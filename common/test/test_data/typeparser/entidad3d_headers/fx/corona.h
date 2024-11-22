// File: corona.h -- Genesis Editor standard entity types
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

#ifndef	CORONA_H
#define	CORONA_H

#include	"genesis.h"

#pragma warning( disable : 4068 )

#ifdef __cplusplus
extern "C" {
#endif

// ==========================
// Entidad 'Corona'
// ==========================
#pragma GE_Type("corona.bmp")
typedef struct	Corona
{
	#pragma	GE_Private
		geFloat			LastTime;
		geFloat			LastVisibleTime;
		geFloat			LastVisibleRadius;
	
	#pragma GE_Published
	    geVec3d			origin;
		int				FadeOut;
		geFloat			FadeTime;
	    int				MinRadius;
	    int				MaxRadius;
		int				MaxVisibleDistance;
		int				MaxRadiusDistance;
		int				MinRadiusDistance;
		int				AllowRotation;
		geWorld_Model	*Model;
	    GE_RGBA			Color;
		geBoolean		Visible;
		int				Num_corona;
		float			Transparencia;
		int				Tipo_corona;


		#pragma GE_Origin(origin)
		#pragma GE_DefaultValue(FadeOut, "1")
		#pragma GE_DefaultValue(FadeTime, "0.15")
		#pragma GE_DefaultValue(MinRadius, "10")
		#pragma GE_DefaultValue(MaxRadius, "10")
		#pragma GE_DefaultValue(MaxVisibleDistance, "2000")
		#pragma GE_DefaultValue(MaxRadiusDistance, "1000")
		#pragma GE_DefaultValue(MinRadiusDistance, "100")
		#pragma GE_DefaultValue(AllowRotation, "1")
		#pragma GE_DefaultValue(Color, "255 255 255")
		#pragma GE_DefaultValue(Visible, "True")
		#pragma GE_DefaultValue(Num_corona, "1")
		#pragma GE_DefaultValue(Transparencia, "128")
		#pragma GE_DefaultValue(Tipo_corona, "1")


		#pragma GE_Documentation(FadeOut, "Nivel de desvanecimiento. (Valores 0 o 1)")
		#pragma GE_Documentation(FadeTime, "Tiempo en segundos para desvanecerse")
		#pragma GE_Documentation(MinRadius, "Mínimo radio de la corona")
		#pragma GE_Documentation(MaxRadius, "Máximo radio de la corona")
		#pragma GE_Documentation(MaxVisibleDistance, "Distancia máxima a la que es visible la corona")
		#pragma GE_Documentation(MaxRadiusDistance, "Por encima de esta distancia, la corona se verá al tamaño 'MaxRadius'")
		#pragma GE_Documentation(MinRadiusDistance, "Por debajo de esta distancia, la corona se verá al tamaño 'MinRadius'")
		#pragma GE_Documentation(AllowRotation, "¿ Rotación de la corona según la rotación del modelo asociado ?. (0=No  1=Si)")
		#pragma GE_Documentation(Model, "Modelo asociado a la corona. (Opcional)")
		#pragma GE_Documentation(Color, "Color de la corona")
		#pragma GE_Documentation(Visible, "¿ Corona visible ?. True=Si False=No")
		#pragma GE_Documentation(origin, "Posición (X Y Z)")
		#pragma GE_Documentation(Num_corona, "Número de corona. (de 1 a 255)")
		#pragma GE_Documentation(Transparencia, "Nivel de transparencia (de 0 a 255). 255 sin transparencia")
		#pragma GE_Documentation(Tipo_corona, "Tipo de corona. (de 1 a 10)")

}	Corona;

geBoolean Corona_Init(geEngine *Engine, geWorld *World, geVFile *MainFS);
geBoolean Corona_Shutdown(void);
geBoolean Corona_Frame(geWorld *World, const geXForm3d *XForm, geFloat DeltaTime);

#ifdef __cplusplus
}
#endif

#pragma warning( default : 4068 )

#endif
