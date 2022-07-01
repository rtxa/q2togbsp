set(COMMON_SOURCE_FILES
    src/converter/QuakeToGenesis.cpp
    src/math/Vector3f.cpp
    src/parser/QuakeParser.cpp
    src/structures/GenesisBrush.cpp
    src/structures/GenesisEntity.cpp
    src/structures/GenesisFace.cpp
    src/structures/GenesisMap.cpp
    src/structures/QuakeBrush.cpp
    src/structures/QuakeEntity.cpp
    src/structures/QuakeFace.cpp
    src/structures/QuakeMap.cpp
    src/utils/StringTokenizer.cpp
    src/writer/GBSPWriter.cpp
)

add_library(common OBJECT ${COMMON_SOURCE_FILES})

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(common PUBLIC fmt::fmt)
