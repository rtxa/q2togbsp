/****************************************************************************************/
/*  File: LuzJugador.h                                                                  */
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
/*  Modificaciones para Entidad 3D:                                                     */
/*                                                                                      */
/*  Autor: Jordi Pérez                                                                  */
/*                                                                                      */
/*  Copyright (C) 2004 - 2017 Jordi Pérez; All rights reserved.                         */
/*                                                                                      */
/****************************************************************************************/

#ifndef	LUZJUGADOR_H
#define	LUZJUGADOR_H

#include "genesis.h"

#pragma warning( disable : 4068 )

// ==========================
// Entidad 'LuzJugador'
// ==========================
#pragma GE_Type("dynlight.bmp")

typedef struct	LuzJugador
{
#pragma	GE_Private
	geFloat			LastTime;
	geFloat			IntervalWidth;
	int				NumFunctionValues;
	geLight *		DynLight;
	
#pragma GE_Published
    geVec3d			origin;
    int				MinRadius;
    int				MaxRadius;
	int				InterpolateValues;
	int				AllowRotation;
    char *			RadiusFunction;
    geFloat			RadiusSpeed;
    GE_RGBA			Color;
	geFloat			Arc;

#pragma GE_Origin(origin)
#pragma GE_DefaultValue(MinRadius, "500")
#pragma GE_DefaultValue(MaxRadius, "700")
#pragma GE_DefaultValue(Color, "247.0 207.0 72.0")
#pragma GE_DefaultValue(RadiusFunction, "nqntmrmtuvpo")
#pragma GE_DefaultValue(RadiusSpeed, "6.0")
#pragma GE_DefaultValue(InterpolateValues, "1")
#pragma GE_DefaultValue(AllowRotation, "1")

#pragma GE_Documentation(MinRadius, "Alcance mínimo de la luz")
#pragma GE_Documentation(MaxRadius, "Alcance máximo de la luz")
#pragma GE_Documentation(InterpolateValues, "Tipo de variación de la luz. Valores 0, 1, 2, 3 o 4")
#pragma GE_Documentation(AllowRotation, "¿ Rotación de la luz según la rotación del modelo asociado ?. 0=No 1=Si")
#pragma GE_Documentation(RadiusFunction, "Secuencia de letras de la 'a' a la 'z' para fijar intensidad variable de la luz. a=Mínimo z=Máximo")
#pragma GE_Documentation(RadiusSpeed, "Velocidad de variación de los valores de 'RadiusFunction'. En segundos")
#pragma GE_Documentation(Color, "Color de la luz")

#pragma GE_Arc(Arc)
#pragma GE_DefaultValue(Arc, "0")
#pragma GE_Documentation(Arc, "Apertura del foco de la luz. 0=Antorcha  55=Linterna")

} LuzJugador;

geBoolean	LuzJugador_Init(geEngine *Engine, geWorld *World, geVFile *Context);
geBoolean	LuzJugador_Frame(geWorld *World, const geXForm3d *ViewPoint, geFloat Time);

#pragma warning( default : 4068 )

#endif

