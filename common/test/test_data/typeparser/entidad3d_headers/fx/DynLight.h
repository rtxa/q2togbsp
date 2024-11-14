// File: DynLight.h -- Genesis Editor standard entity types
//
// Copyright  1999, WildTangent, Inc.
//
/****************************************************************************************/
/*  Descripci�n:                                                                        */
/*                                                                                      */
/*  Definici�n de clases de entidades.                                                  */
/*  Este fichero .h lo utiliza World Editor para crear las entidades que usa el         */
/*  programa Entidad 3D.                                                                */
/*                                                                                      */
/*  No modificar el contenido de este fichero .h para un correcto funcionamiento        */
/*  de Entidad 3D y World Editor.                                                       */
/*                                                                                      */
/*  Modificaciones para Entidad 3D:                                                     */
/*                                                                                      */
/*  Autor: Jordi P�rez                                                                  */
/*                                                                                      */
/*  Copyright (c) 2004 - 2016 Jordi P�rez; All rights reserved.                         */
/*                                                                                      */
/****************************************************************************************/

#ifndef	DYNLIGHT_H
#define	DYNLIGHT_H

#include "genesis.h"

#pragma warning( disable : 4068 )

// ==========================
// Entidad 'DynamicLight'
// ==========================
#pragma GE_Type("dynlight.bmp")

typedef struct	DynamicLight
{
#pragma	GE_Private
	geFloat			LastTime;
	geFloat			IntervalWidth;
	int				NumFunctionValues;
	geLight			*DynLight;
	
#pragma GE_Published
    geVec3d			origin;
    int				MinRadius;
    int				MaxRadius;
	int				InterpolateValues;
	int				AllowRotation;
    char			*RadiusFunction;
    geFloat			RadiusSpeed;
	geWorld_Model	*Model;
    GE_RGBA			Color;
	geBoolean		Visible;
	int				Num_luz;
	geVec3d			Orientacion;
	geFloat			Arc;
	geBoolean		SombraNivel;

#pragma GE_Origin(origin)
#pragma GE_DefaultValue(MinRadius, "450")
#pragma GE_DefaultValue(MaxRadius, "550")
#pragma GE_DefaultValue(Color, "40.0 40.0 153.0")
#pragma GE_DefaultValue(RadiusFunction, "azaz")
#pragma GE_DefaultValue(RadiusSpeed, "2.0")
#pragma GE_DefaultValue(InterpolateValues, "1")
#pragma GE_DefaultValue(AllowRotation, "1")
#pragma GE_DefaultValue(Visible, "True")
#pragma GE_DefaultValue(Num_luz, "1")
#pragma GE_DefaultValue(SombraNivel, "True")

#pragma GE_Documentation(origin, "Posici�n (X Y Z)")
#pragma GE_Documentation(MinRadius, "Alcance m�nimo de la luz")
#pragma GE_Documentation(MaxRadius, "Alcance m�ximo de la luz")
#pragma GE_Documentation(InterpolateValues, "Tipo de variaci�n de la luz. Valores 0, 1, 2, 3 o 4")
#pragma GE_Documentation(AllowRotation, "� Rotaci�n de la luz seg�n la rotaci�n del modelo asociado ?. 0=No  1=Si")
#pragma GE_Documentation(RadiusFunction, "Secuencia de letras de la 'a' a la 'z' para fijar intensidad variable de la luz. (a = M�nimo  z = M�ximo)")
#pragma GE_Documentation(RadiusSpeed, "Velocidad de variaci�n de los valores de 'RadiusFunction'. (En segundos)")
#pragma GE_Documentation(Model, "Modelo asociado a la luz. (Opcional)")
#pragma GE_Documentation(Color, "Color de la luz")
#pragma GE_Documentation(Visible, "� Luz visible ? True=Si False=No")
#pragma GE_Documentation(Num_luz, "N�mero de luz. (de 1 a 255)")
#pragma GE_Documentation(SombraNivel, "Produce sombras por la arquitectura del nivel. True=Si False=No")

#pragma GE_Angles(Orientacion)
#pragma GE_DefaultValue(Orientacion, "0 0 0")
#pragma GE_Documentation(Orientacion, "Orientaci�n de la luz de foco")

#pragma GE_Arc(Arc)
#pragma GE_DefaultValue(Arc, "0")
#pragma GE_Documentation(Arc, "Apertura del foco de luz")

} DynamicLight;


// Declaraci�n de funciones
geBoolean	DynLight_Init(geEngine *Engine, geWorld *World, geVFile *Context);
geBoolean	DynLight_Frame(geWorld *World, const geXForm3d *ViewPoint, geFloat Time);

#pragma warning( default : 4068 )

#endif

