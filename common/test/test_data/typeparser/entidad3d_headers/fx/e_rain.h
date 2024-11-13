/******************************************************************************/
/*  File: e_rain.h                                                            */
/*                                                                            */
/*  Author: David Wulff                                                       */
/*  Description: Env header file                                              */
/*                                                                            */
/*  Copyright (c) 1999, 2000, Battleaxe Studios; All rights reserved.         */
/*           ______  __   __  ___      __  __  __  __  __  _____    __        */
/*          / ____/ / /  / / / _ \    / / / / / / / / / / / ___ \  / /        */
/*         / /___  / /  / / / /_\ \  / / / / / / / / / / / /__/ / / /         */
/*        /___  / / /  / / / ___  / / / / / / / / / / / /  __  / / /          */
/*       ____/ / / /__/ / / /  / /  \ \/ / / /  \ \/ / / /  / / / /___        */
/*      /_____/ /______/ /_/  /_/    \__/ /_/    \__/ /_/  /_/ /_____/        */
/*                                                                            */
/*                              www.bttlxe.co.uk                              */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*  Traducción y adaptación para Entidad 3D: Jordi Pérez                      */
/*                                                                            */
/*  Copyright (C) 2005 - 2016; All rights reserved.                           */
/*                                                                            */
/*                        http://www.entidad-3d.com                           */
/******************************************************************************/

#pragma warning( disable : 4068 )

#ifndef E_RAIN_H
#define E_RAIN_H

#include "genesis.h"
//#include "env.h"

#include "EffManager.h"
#include "AAAStaticEntity.h"

#ifdef __cplusplus
extern "C" {
#endif

// ==========================
// Entidad 'Fx_Lluvia'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct Fx_Lluvia
{
#pragma GE_Private
	int 	*EffectList;
	int		EffectCount;
#pragma GE_Published
	geVec3d		Position;
	StaticEntityProxy *Entity;
	geVec3d		Gravity;
	float		Radius;
	float		Severity;
	float		DropLife;
	GE_RGBA		ColorMin;
	GE_RGBA		ColorMax;
	char		*BmpName;
	char		*AlphaName;
	char		*TriggerName;
	char		*BoneName;
	float		Transparencia;
	float		MinScale;
	float		MaxScale;
	geBoolean 	Activo;

	#pragma GE_Documentation( Entity, "<sin función> Entidad 'StaticEntityProxy' asociada" )
	#pragma GE_Origin( Position )
	#pragma GE_DefaultValue( Gravity, "0.0 -60.0 0.0" )
	#pragma GE_DefaultValue( Radius, "200.0" )
	#pragma GE_DefaultValue( Severity, "0.5" )
	#pragma GE_DefaultValue( DropLife, "6.0" )
	#pragma GE_DefaultValue( ColorMin, "255.0 255.0 255.0" )
	#pragma GE_DefaultValue( ColorMax, "255.0 255.0 255.0" )
	#pragma GE_DefaultValue( TriggerName, "" )
	#pragma GE_DefaultValue( BmpName, "rain.bmp" )
	#pragma GE_DefaultValue( AlphaName, "a_rain.bmp" )

	#pragma GE_Documentation( Position, "Posición del efecto" )
	#pragma GE_Documentation( Gravity, "Vector de gravedad para aplicar a cada gota" )
	#pragma GE_Documentation( Radius, "Radio de acción de la lluvia" )
	#pragma GE_Documentation( Severity, "Intensidad de la lluvia, 0.0 poca, 1.0 mucha" )
	#pragma GE_Documentation( DropLife, "Vida de cada gota (segundos)" )
	#pragma GE_Documentation( ColorMin, "Mínimo valor de color RGB para cada gota" )
	#pragma GE_Documentation( ColorMax, "Máximo valor de color RGB para cada gota" )
	#pragma GE_Documentation( BmpName, "Nombre de imagen .BMP que representa la gota" )
	#pragma GE_Documentation( AlphaName, "Nombre de imagen .BMP (Alpha) que representa la gota" )
	#pragma GE_Documentation( BoneName, "<sin función> Hueso del esqueleto del 'actor' al que enganchar efecto" )
	#pragma GE_Documentation( TriggerName, "<sin función> Fichero de comandos .INI" )

	#pragma GE_DefaultValue( Transparencia, "255.0" )
	#pragma GE_Documentation( Transparencia, "Nivel de transparencia. De 0 a 255" )

	#pragma GE_DefaultValue( MinScale, "0.5" )
	#pragma GE_Documentation( MinScale, "Tamaño mínimo de las gotas" )

	#pragma GE_DefaultValue( MaxScale, "1.5" )
	#pragma GE_Documentation( MaxScale, "Tamaño máximo de las gotas" )

	#pragma GE_DefaultValue( Activo, "True" )
	#pragma GE_Documentation( Activo, "¿ Efecto activo ?. True=Si False=No" )

} Fx_Lluvia;


// Definitions
geBoolean Rain_Create(geEngine *Engine, Eff_Manager *EM);


#ifdef __cplusplus
}
#endif

#endif
