#pragma once

#include <iostream>

#include <vector>
#include <fstream>

#include "GenesisMap.h"
//#include "GenesisEntity.h"
//#include "GenesisBrush.h"


class GBSPWriter {

#pragma pack(1)
	struct FileHeader {
		std::int32_t	version;
		char			tag[4];
		std::int32_t	numEntities;
		std::int32_t	numBrushes;
	};

	struct BrushHeader {
		std::int32_t	flags;
		std::int32_t	numFaces;
	};

	struct FaceHeader {
		std::int32_t	flags;
		float			mipMapBias;
		float			alpha;					// Alpha for brush (0-255)
		float			lightIntensity;			// face light
		float			reflectivityScale;
		char			textureName[32];
		float			uVecX, uVecY, uVecZ;
		float			xScale, xOffset;
		float			vVecX, vVecY, vVecZ;
		float			yScale, yOffset;
		float			normalX, normalY, normalZ;
		float			distance;
	};
#pragma pack()

	enum class Result {
		RESULT_SUCCED,
		RESULT_FAIL,
		RESULT_EOF
	};

public:
	bool writeGBSPFile(const std::string filename, const GenesisMap& gMap);
private:
	std::fstream m_genesisMap;

	Result writeFileHeader(const GenesisMap& gMap);
	//void writeWorldSpawn(const GenesisEntity& gEnt)
	void writeMapAtribbutes(const GenesisMap& gMap);
	Result writeBrush(GenesisBrush brush); // perhaps inside goes WriteFaces();
	Result writeFace(GenesisFace face);
	Result writeKeyValue(std::string key, std::string value);
	Result writeEntity(GenesisEntity gEnt);

	// hardcoded
	void writeTypeDefs();

	// Methods to write basic types in binary
	void writeInt(int value);
	void writeString(std::string str);
	//void writeBlock();
	
};