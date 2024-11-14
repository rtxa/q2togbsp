/******************************************************************************/
/*  e_env_spout.h                                                             */
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
/*  Traducci�n y adaptaci�n para Entidad 3D: Jordi P�rez                      */
/*                                                                            */
/*  Copyright (c) 2005; All rights reserved.                                  */
/*                                                                            */
/*                        http://www.entidad-3d.com                           */
/******************************************************************************/

#ifndef E_env_spout_H
#define E_env_spout_H

#include <Windows.H>
#include "AAAStaticEntity.h"

#pragma warning( disable : 4068 )

#ifdef __cplusplus
extern "C" {
#endif


#pragma GE_Type("env_spout.bmp")
typedef struct Fx_Surtidor
{
#pragma	GE_Private
	int		EffectList;
	int		EffectCount;
	float		PauseTime;
	geBoolean 	PauseState;
#pragma GE_Published
	geVec3d		Position;
	geVec3d		Angles;
	float		ParticleCreateRate;
	float		MinScale;
	float		MaxScale;
	float		MinSpeed;
	float		MaxSpeed;
	float		MinUnitLife;
	float		MaxUnitLife;
	int		SourceVariance;
	int		DestVariance;
        GE_RGBA		ColorMin;
        GE_RGBA		ColorMax;
	geVec3d		Gravity;
	char		*BmpName;
	char		*AlphaName;
	char		*TriggerName;
	float		MinPauseTime;
	float		MaxPauseTime;
	float		TotalLife;
	StaticEntityProxy *Entity;
	char		*BoneName;
	geBoolean 	ShowAlways;
	float		Transparencia;
	geBoolean 	Activo;
	geWorld_Model *	Model;

#pragma GE_Origin(Position)
#pragma GE_Angles(Angles)
#pragma GE_DefaultValue( Angles, "-90 0 0" )
#pragma GE_DefaultValue( ParticleCreateRate, "0.1" )
#pragma GE_DefaultValue( MinScale, "1.0" )
#pragma GE_DefaultValue( MaxScale, "1.0" )
#pragma GE_DefaultValue( MinSpeed, "10.0" )
#pragma GE_DefaultValue( MaxSpeed, "30.0" )
#pragma GE_DefaultValue( MinUnitLife, "3.0" )
#pragma GE_DefaultValue( MaxUnitLife, "6.0" )
#pragma GE_DefaultValue( SourceVariance, "0" )
#pragma GE_DefaultValue( DestVariance, "1" )
#pragma GE_DefaultValue( ColorMin, "255.0 255.0 255.0" )
#pragma GE_DefaultValue( ColorMax, "255.0 255.0 255.0" )
#pragma GE_DefaultValue( Gravity, "0.0 0.0 0.0" )
#pragma GE_DefaultValue( TotalLife, "0.0" )
#pragma GE_DefaultValue( TriggerName, "" )
#pragma GE_DefaultValue( MinPauseTime, "0.0" )
#pragma GE_DefaultValue( MaxPauseTime, "0.0" )
#pragma GE_DefaultValue( BoneName, "EFFECT_BONE01" )
#pragma GE_DefaultValue( BmpName, "lvsfuego.bmp" )
#pragma GE_DefaultValue( AlphaName, "A_lvsmoke.bmp" )
#pragma GE_DefaultValue( ShowAlways, "False" )
#pragma GE_DefaultValue( Transparencia, "255.0" )

#pragma GE_Documentation( Entity, "<sin funci�n> Entidad 'StaticEntityProxy' asociada" )
#pragma GE_Documentation( Position, "Posici�n del efecto" )
#pragma GE_Documentation( Angles, "Direcci�n de emisi�n de las part�culas" )
#pragma GE_Documentation( ParticleCreateRate, "Cada cuantos segundos se genera una nueva part�cula" )
#pragma GE_Documentation( MinScale, "Tama�o m�nimo de las part�culas" )
#pragma GE_Documentation( MaxScale, "Tama�o m�ximo de las part�culas" )
#pragma GE_Documentation( MinSpeed, "Velocidad m�nima de las part�culas" )
#pragma GE_Documentation( MaxSpeed, "Velocidad m�xima de las part�culas" )
#pragma GE_Documentation( MinUnitLife, "Vida m�nima de cada part�cula" )
#pragma GE_Documentation( MaxUnitLife, "Vida m�xima de cada part�cula" )
#pragma GE_Documentation( SourceVariance, "Nivel de variaci�n de la fuente de emisi�n de part�culas" )
#pragma GE_Documentation( DestVariance, "Nivel de variaci�n del destino de las part�culas" )
#pragma GE_Documentation( ColorMin, "M�nimo valor de color RGB para cada part�cula" )
#pragma GE_Documentation( ColorMax, "M�ximo valor de color RGB para cada part�cula" )
#pragma GE_Documentation( Gravity, "Vector de gravedad para aplicar a cada part�cula" )
#pragma GE_Documentation( BmpName, "Nombre de imagen .BMP que representa la part�cula" )
#pragma GE_Documentation( AlphaName, "Nombre de imagen .BMP (Alpha) que representa la part�cula" )
#pragma GE_Documentation( TotalLife, "Tiempo que dura el efecto. 0=indefinido" )
#pragma GE_Documentation( TriggerName, "<sin funci�n> Fichero de comandos .INI" )
#pragma GE_Documentation( MinPauseTime, "<sin funci�n> Tiempo m�nimo para pausas aleatorias del efecto (segundos)" )
#pragma GE_Documentation( MaxPauseTime, "<sin funci�n> Tiempo m�ximo para pausas aleatorias del efecto (segundos)" )
#pragma GE_Documentation( BoneName, "<sin funci�n> Hueso del esqueleto del 'actor' al que enganchar efecto" )
#pragma GE_Documentation( ShowAlways, "Mostrar aunque el origen no est� a la vista. True=Si False=No" )
#pragma GE_Documentation( Transparencia, "Nivel de transparencia. De 0 a 255" )

#pragma GE_DefaultValue( Activo, "True" )
#pragma GE_Documentation( Activo, "� Efecto activo ?. True=Si False=No" )

#pragma GE_Documentation(Model, "Modelo asociado al efecto. (Opcional)")

} Fx_Surtidor;

geBoolean Spout_Create(geEngine *Engine, Eff_Manager *EM);
void Spout_Destroy(Eff_Manager *EM);
void Spout_Tick(Eff_Manager *EM);



#ifdef __cplusplus
}
#endif

#endif
