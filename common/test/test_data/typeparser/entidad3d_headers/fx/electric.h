// File: electric.h -- Genesis Editor standard entity types
//
// Copyright  1999, WildTangent, Inc.
//
/****************************************************************************************/
/*  Descripción:                                                                        */
/*                                                                                      */
/*  Definición de clases de entidades.                                                  */
/*  Este fichero .h lo utiliza World Editor para crear las entidades que usa el         */
/*  programa Entidad 3D.                                                                */
/*                                                                                      */
/*  No modificar el contenido de este fichero .h para un correcto funcionamiento        */
/*  de Entidad 3D y World Editor.                                                       */
/*                                                                                      */
/*  Modificaciones para Entidad 3D:                                                     */
/*                                                                                      */
/*  Autor: Jordi Pérez                                                                  */
/*                                                                                      */
/*  Copyright (c) 2004 - 2016 Jordi Pérez; All rights reserved.                         */
/*                                                                                      */
/****************************************************************************************/

#ifndef	ELECTRIC_H
#define ELECTRIC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Genesis.h"

#pragma warning( disable : 4068 )

// ==========================
// Entidad 'ElectricBoltTerminus'
// ==========================
#pragma GE_Type("terminus.bmp")
typedef struct	ElectricBoltTerminus
{
#pragma GE_Published
    geVec3d			origin;

#pragma GE_Origin(origin)
}	ElectricBoltTerminus;

typedef struct Electric_BoltEffect Electric_BoltEffect;

// ==========================
// Entidad 'ElectricBolt'
// ==========================
#pragma GE_Type("bolt.bmp")
typedef struct	ElectricBolt
{
#pragma	GE_Private
	geFloat					LastTime;
	geFloat					LastBoltTime;
	Electric_BoltEffect		*Bolt;
	geSound					*LoopingSound;
	geSound_Def				*LoopingSoundDef;

#pragma GE_Published
	int Num_sonido3d;	
	#pragma GE_DefaultValue(Num_sonido3d, "0")
	#pragma GE_Documentation(Num_sonido3d, "Número de sonido 3D (entre 1 y 255). (Poner 0 si no es sonido 3D)")

	geBoolean   Activado;
	#pragma GE_DefaultValue(Activado, "True")
	#pragma GE_Documentation(Activado, "¿ Sonido 3D activado al dar comienzo el nivel ? True=Si False=No")

	geBoolean   Ciclico;
	#pragma GE_DefaultValue(Ciclico, "True")
	#pragma GE_Documentation(Ciclico, "¿ Sonido 3D se interpreta cíclicamente ? True=Si False=No")

    geVec3d					origin;
    int						Width;
    int						NumPoints;
    int						Intermittent;
    geFloat					MinFrequency;
    geFloat					MaxFrequency;
    geFloat					Wildness;
    ElectricBoltTerminus	*Terminus;
    int						DominantColor;
    GE_RGBA					Color;
	char					*Fichero_sonido_wav;
	#pragma GE_DefaultValue(Fichero_sonido_wav, "")
	#pragma GE_Documentation(Fichero_sonido_wav, "Nombre del fichero en formato .WAV para el sonido 3D")

	#pragma GE_Origin(origin)
	#pragma GE_DefaultValue(Width, "8")
	#pragma GE_DefaultValue(NumPoints, "64")
	#pragma GE_DefaultValue(Intermittent, "1")
	#pragma GE_DefaultValue(MinFrequency, "4.0")
	#pragma GE_DefaultValue(MaxFrequency, "1.0")
	#pragma GE_DefaultValue(Wildness, "0.5")
	#pragma GE_DefaultValue(DominantColor, "2")
	#pragma GE_DefaultValue(Color, "160.0 160.0 255.0")

	#pragma GE_Documentation(Width, "Ancho del rayo. (0 para sonido 3D)")
	#pragma GE_Documentation(NumPoints, "Puntos de control del rayo (32, 64, 128")
	#pragma GE_Documentation(Intermittent, "Rayo intermitente. 0=No o 1=Si.(0 para sonido 3D)")
	#pragma GE_Documentation(MinFrequency, "Tiempo mínimo entre descargas del rayo")
	#pragma GE_Documentation(MaxFrequency, "Tiempo máximo entre descargas del rayo")
	#pragma GE_Documentation(Wildness, "Grado de intensidad del rayo. 0 a 1.(0 para sonido 3D)")
	#pragma GE_Documentation(Terminus, "Seleccionar el otro extremo del rayo")
	#pragma GE_Documentation(DominantColor, "Color dominante del rayo. 0=Rojo, 1=Verde, 2=Azul")
	#pragma GE_Documentation(Color, "Color base del rayo")

}	ElectricBolt;
#pragma warning( default : 4068 )

geBoolean	Electric_Init(geEngine *Engine, geWorld *World, geVFile *MainFS, geSound_System *SoundSystem);
geBoolean	Electric_Reset(geWorld *World);
geBoolean	Electric_Frame(geWorld *World, const geXForm3d *ViewPoint, geFloat Time);
geBoolean	Electric_Shutdown(void);

#ifdef	__cplusplus
}
#endif

#endif

