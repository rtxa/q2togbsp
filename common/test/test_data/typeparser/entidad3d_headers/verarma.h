/****************************************************************************************/
/*  File: verarma.h                                                                     */
/*                                                                                      */
/*  Descripción:                                                                        */
/*                                                                                      */
/*  Definición de clases de entidades.                                                  */
/*  Este fichero .h lo utiliza World Editor para crear las entidades que usa el         */
/*  programa Entidad 3D.                                                                */
/*                                                                                      */
/*  No modificar el contenido de este fichero .h para un correcto funcionamiento        */
/*  de Entidad 3D y World Editor.                                                       */
/*                                                                                      */
/*  Autor: Jordi Pérez                                                                  */
/*                                                                                      */
/*  Copyright (C) 2005 - 2017 Jordi Pérez; All rights reserved.                         */
/*                                                                                      */
/****************************************************************************************/

#ifndef VWEAP_H
#define VWEAP_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Genesis.h"

#pragma warning( disable : 4068 )

// ==========================
// Entidad 'VerArma'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct VerArma {
#pragma GE_Private
	geFloat lastTime; // Control última animación
	geActor *Weapon1; // Puntero al 'Actor' del arma 1
	geActor *Weapon2; // Puntero al 'Actor' del arma 2
	geActor *Weapon3; // Puntero al 'Actor' del arma 3
	geActor *Weapon4; // Puntero al 'Actor' del arma 4
	geActor_Def *pActorDef1; // 'Actor' Definition arma 1
	geActor_Def *pActorDef2; // 'Actor' Definition arma 2
	geActor_Def *pActorDef3; // 'Actor' Definition arma 3
	geActor_Def *pActorDef4; // 'Actor' Definition arma 4
	//geFloat startTime; // Control primera animación (no utilizado)
	//geVec3d Rotation; // Vector de rotación (no utilizado)
#pragma GE_Published
	geVec3d Origin; // Posición de la entidad
	geVec3d scale; // Escala
	geVec3d Orientation; // Vector de orientación
	//geBoolean RenderEnEspejos; // Reflejo en espejos (no utilizado)
	geBoolean Ocultar_sombra_1P;

	#pragma GE_Origin(Origin)

	#pragma GE_DefaultValue(scale, "1 1 1")
	#pragma GE_DefaultValue(Orientation, "-90 0 0")
	//#pragma GE_DefaultValue(RenderEnEspejos, "True")
	#pragma GE_DefaultValue(Ocultar_sombra_1P, "False")

	#pragma GE_Documentation(scale, "< sin uso >")
	#pragma GE_Documentation(Orientation, "< sin uso >")
	//#pragma GE_Documentation(RenderEnEspejos, "Armas en espejos. True=si False=no")
	#pragma GE_Documentation(Ocultar_sombra_1P, "Ocultar sombra en primera persona. True=si False=no")

} VerArma;

// Declaración de funciones
geBoolean VWeap_Spawn(geWorld *World, geVFile *MainFS);
geBoolean VWeap_Render(geWorld *World, geBoolean Show, uint16 Weapon, float Time);

#ifdef __cplusplus
}
#endif

#endif
