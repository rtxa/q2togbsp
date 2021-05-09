#include "GBSPWriter.h"
#include "Vector3f.h"
#include <iostream>

bool GBSPWriter::writeGBSPFile(const std::string filename, const GenesisMap& gMap) {
	m_genesisMap.open(filename, std::ios::out | std::ios::binary);

	if (!m_genesisMap.is_open()) {
		std::cout << "Failed to write file" << '\n';
		return false;
	}

	writeFileHeader(gMap);

	for (auto itr = gMap.beginEnt(); itr != gMap.endEnt(); itr++) {
		writeEntity(*itr);
	}

	writeTypeDefs();

	return true;
}

bool GBSPWriter::writeFileHeader(const GenesisMap& gMap) {
	FileHeader fileH;
	std::string tag = "NCBF";

	fileH.version = 1;
	tag.copy(fileH.tag, 4);

	fileH.numEntities = gMap.getNumEntities() + 2; // worldspawn + normal entities + entity typedefs;

	m_genesisMap.write(reinterpret_cast<const char*>(&fileH), sizeof(FileHeader));

	return true;
}

bool GBSPWriter::writeFace(GenesisFace face) {
	FaceHeader faceH;

	faceH.flags = face.getFlags();
	faceH.mipMapBias = face.getMipMapBias();
	faceH.lightIntensity = static_cast<float>(face.getLightIntensity());
	faceH.alpha = face.getAlpha();
	faceH.reflectivityScale = face.getReflectivityScale();

	memcpy(faceH.textureName, face.getTextureName().c_str(), sizeof(faceH.textureName));
	
	faceH.uVecX = face.getVecU().x;
	faceH.uVecY = face.getVecU().y;
	faceH.uVecZ = face.getVecU().z;

	faceH.xScale = face.getScaleX();
	faceH.xOffset = face.getOffsetX();

	faceH.vVecX = face.getVecV().x;
	faceH.vVecY = face.getVecV().y;
	faceH.vVecZ = face.getVecV().z;

	faceH.yScale = face.getScaleY();
	faceH.yOffset = face.getOffsetY();

	faceH.normalX = face.getNormal().x;
	faceH.normalY = face.getNormal().y;
	faceH.normalZ = face.getNormal().z;

	faceH.distance = face.getDistance();

	m_genesisMap.write(reinterpret_cast<const char*>(&faceH), sizeof(FaceHeader));

	return true;
}

bool GBSPWriter::writeKeyValue(std::string key, std::string value) {
	writeString(key);
	writeString(value);
	
	return true;
}

bool GBSPWriter::writeEntity(GenesisEntity gEnt) {
	writeInt(gEnt.getNumBrushes());
	if (gEnt.getNumBrushes() > 0) {
		for (auto itr = gEnt.begin(); itr != gEnt.end(); itr++) {
			writeBrush(*itr);
		}
	}

	writeInt(gEnt.getFlags());
	writeInt(gEnt.getNumKeys());

	for (auto itr = gEnt.beginKeyValues(); itr != gEnt.endKeyValues(); itr++) {
		writeKeyValue(itr->first, itr->second);
	}

	return true;
}

bool GBSPWriter::writeBrush(GenesisBrush brush) {
	BrushHeader brushH;
	brushH.flags = brush.getFlags();
	brushH.numFaces = brush.getNumFaces();

	m_genesisMap.write(reinterpret_cast<const char*>(&brushH), sizeof(BrushHeader));

	for (auto itr = brush.begin(); itr < brush.end(); itr++) {
		writeFace(*itr);
	}

	return true;
}

void GBSPWriter::writeTypeDefs() {
	// No brushes attached to this entity
	int numBrushes = 0;
	int entFlags = 0; // no motion for this entity
	int numFields = 4; // numfields = classname + name + origin

	writeInt(numBrushes);
	writeInt(entFlags);
	writeInt(numFields);

	// Keyvalues
	writeKeyValue("classname", "%typedef%");
	writeKeyValue("%typename%", "DeathMatchStart");
	writeKeyValue("Origin", "point");
	writeKeyValue("%defaultvalue%", "");

	// No brushes attached to this entity
	numBrushes = 0;
	entFlags = 0; // no motion for this entity
	numFields = 10; // numfields = classname + name + origin

	writeInt(numBrushes);
	writeInt(entFlags);
	writeInt(numFields);

	// Keyvalues
	writeKeyValue("classname", "%typedef%");
	writeKeyValue("%typename%", "light");
	writeKeyValue("light", "int");
	writeKeyValue("%defaultvalue%", "");
	writeKeyValue("color", "color");
	writeKeyValue("%defaultvalue%", "");
	writeKeyValue("style", "int");
	writeKeyValue("%defaultvalue%", "");
	writeKeyValue("Origin", "point");
	writeKeyValue("%defaultvalue%", "");	
}

void GBSPWriter::writeInt(int value) {
	m_genesisMap.write(reinterpret_cast<const char*>(&value), sizeof(std::int32_t));
}

void GBSPWriter::writeString(std::string str) {
	int length = str.length();
	m_genesisMap.write(reinterpret_cast<const char*>(&length), sizeof(std::int32_t));
	m_genesisMap.write(reinterpret_cast<const char*>(str.c_str()), str.length());
}

