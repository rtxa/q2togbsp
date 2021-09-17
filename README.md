# q2togbsp

Convert a Quake 1/2 .map to Genesis3D .map format. The generated file will later be used in the Genesis3D BSP Compiler (CSG, VIS and Light) to finally build the level and be playable.

The Genesis3D .map format is just like the Quake .map format but written in a non-readable way (binary) and with some extra attributes.

## Commands:

- `<input>` : File path to the Quake 1/2 .map
- `<output>` : File path where the .map GBSP binary map format will output.
