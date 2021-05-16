#include <iostream>

#include "QuakeToGenesis.h"
#include "StringTokenizer.h"

bool QuakeToGenesis::convertTo(QuakeMap qMap, GenesisMap& gMap) {
	GenesisEntity gEnt;
	GenesisBrush gBrush;
	GenesisFace gFace;
	QuakeBrush qBrush;

	for (const auto& ent : qMap) {
		entToGenesis(ent, gEnt);
		if (gEnt.getNumKeys() != 0) {
			gMap.insertEntity(gEnt);
		}
		gEnt = GenesisEntity();
	}

	return true;
}

bool QuakeToGenesis::faceToGenesis(QuakeFace qFace, GenesisFace& gFace) {
	Vector3f points[3];
	
	for (int i = 0; i < 3; i++) {
		// switch coordinates Y and Z and make negative Z
		points[i].x = qFace.getPlane(i).x;
		points[i].y = qFace.getPlane(i).z;
		points[i].z = qFace.getPlane(i).y;
		points[i].z = -points[i].z;
	}

	Vector3f normal;
	float distance;
	
	// TODO check if process was done successfully in planeToNormalForm and worldTextureVecsToUV
	planeToNormalForm(points, normal, distance);

	Vector3f uVec, vVec;
	worldTextureVecsToUV(normal, qFace.getRotation(), uVec, vVec);

	gFace.setTextureName(qFace.getTextureName());
	gFace.setNormal(normal);
	gFace.setDistance(distance);
	gFace.setVecU(uVec);
	gFace.setVecV(vVec);

	// make axis Y of scale and offset negative
	gFace.setScaleX(qFace.getScaleX());
	gFace.setScaleY(-qFace.getScaleY());
	gFace.setOffsetX(qFace.getOffsetX());
	gFace.setOffsetY(-qFace.getOffsetY());

	gFace.setFlags(qFace.getSurfaceFlags());


	gFace.setLightIntensity(qFace.getLightIntensity());
	// TODO add light map scale in GenesisFace.h
	// also this conversion of light map scale is bugged...

	// const float scaleX = gFace.getScaleX() / 0.2f;
	// const float scaleY = gFace.getScaleY() / 0.2f;

	// uVec = uVec * scaleX; // divided by light map scale
	// vVec = vVec * scaleY; // divided by light map scale

	// gFace.setVecU(uVec);
	// gFace.setVecV(vVec);
	// gFace.setScaleX(scaleX);
	// gFace.setScaleY(scaleY);

	return true;
}

bool QuakeToGenesis::planeToNormalForm(const Vector3f points[3], Vector3f& normal, float& distance) {
	const int NumPoints = 3; // 3 points per plane (genesis uses 4 points in his .3dt format)
	
	Vector3f v1, v2;
	
	int i;
	for (i = 0; i < NumPoints; i++) {
		v1 = points[i] - points[(i + 1) % NumPoints];
		v2 = points[(i + 2) % NumPoints] - points[(i + 1) % NumPoints];
		normal = v1.crossProduct(v2);
		if (!normal.epsilonEquals(Vector3f(0.0f, 0.0f, 0.0f), Vector3f::CompareEpsilon)) {
			break;
		}
	}

	// Error: Face with no normal!
	if (i >= NumPoints) {
		return false;
	}

	normal.normalize();
	distance = points[1].dotProduct(normal);

	return true;
}

void QuakeToGenesis::worldTextureVecsToUV(Vector3f normal, float rotation, Vector3f& uVec, Vector3f& vVec) {
	const float Pi = 3.141592741f;
	
	float ang, sinv, cosv;

	// degrees to radians
	ang = (rotation * Pi) / 180.0f;

	sinv = static_cast<float>(sin(ang));
	cosv = static_cast<float>(cos(ang));

	int whichAxis = 0;
	if (fabs(normal.y) > fabs(normal.x)) {
		if (fabs(normal.z) > fabs(normal.y)) {
			whichAxis = 2;
		} else {
			whichAxis = 1;
		}
	} else if (fabs(normal.z) > fabs(normal.x)) {
		whichAxis = 2;
	}

	switch (whichAxis) {
		case 0:
			uVec = Vector3f(0.0f, sinv, cosv);
			vVec = Vector3f(0.0f, -cosv, sinv);
			break;
		case 1:
			uVec = Vector3f(cosv, 0.0f, sinv);
			vVec = Vector3f(-sinv, 0.0f, cosv);
			break;
		case 2:
			uVec = Vector3f(cosv, sinv, 0.0f);
			vVec = Vector3f(sinv, -cosv, 0.0f);
			break;
	}
}

bool QuakeToGenesis::entToGenesis(QuakeEntity qEnt, GenesisEntity& gEnt) {
	// insert brushes to genesis entity
	for (const auto &brush : qEnt) {
		// TODO create function brushToGenesis
		GenesisBrush gBrush;
		int contentFlags = 0;
		for (const auto &face : brush) {
			GenesisFace gFace;
			faceToGenesis(face, gFace);
			gBrush.insertFace(gFace);
			//  only use the one from the first face
			contentFlags = face.getContentFlags();
		}
		if (contentFlags == 0) {
			contentFlags = GenesisBrush::BrushContentFlags::Solid;
		}
		gBrush.setFlags(contentFlags);
		
		gEnt.insertBrush(gBrush);
	}

	// insert keyvalues to genesis entity
	// TODO compare insensitive case using c.str() and stricmp
	for (auto itr = qEnt.beginKeyValues(); itr != qEnt.endKeyValues(); itr++) {
		// Every entity has a name assigned (light1, light2, etc...)
		// Generate those names automatically
		if (itr->first == "classname" && itr->second != "worldspawn") {
			gEnt.insertKeyValue("%name%", getNameForEntity(itr->second));
		} else if (itr->first == "origin") { 
			float x = 0.0f, y = 0.0f, z = 0.0f;
			if (convertOriginToGenesis(itr->second, x, y, z)) {
				gEnt.insertKeyValue(itr->first, std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z));
				continue;
			} else {
				std::cout << "Error converting origin to Genesis\n";
			}
		}
		gEnt.insertKeyValue(itr->first, itr->second);
	}

	return false;
}

std::string QuakeToGenesis::getNameForEntity(std::string classname) {
			// Every entity has a name assigned (light1, light2, etc...)
			// Generate those names automatically
			if (m_numEntsByClass.count(classname) == 0) {
				m_numEntsByClass.insert({classname, 0});
			}
			int num = m_numEntsByClass.at(classname);
			m_numEntsByClass.at(classname) = ++num;
			return classname + std::to_string(num);
}

bool QuakeToGenesis::convertOriginToGenesis(std::string origin, float& x, float& y, float& z) {
	StringTokenizer st = StringTokenizer(origin);

	if (st.countTokens() < 3) {
		return false;
	}

	x = st.nextTokenFloat();
	z = st.nextTokenFloat();
	y = st.nextTokenFloat();
	z = -z;

	return true;
}