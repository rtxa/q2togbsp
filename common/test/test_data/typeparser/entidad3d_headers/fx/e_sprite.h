/******************************************************************************/
/*  e_sprite.h                                                                */
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
/*  Copyright (c) 2005; All rights reserved.                                  */
/*                                                                            */
/*                        http://www.entidad-3d.com                           */
/******************************************************************************/

#pragma warning( disable : 4068 )

#ifndef E_SPRITE_H
#define E_SPRITE_H

#include "genesis.h"
//#include "env.h"

#include "EffManager.h"
#include "AAAStaticEntity.h"

#ifdef __cplusplus
extern "C" {
#endif


#pragma GE_Type("env_sprite.bmp")
typedef struct Fx_Sprite
{
#pragma	GE_Private
	int 	*EffectList;
	int	EffectCount;
	geXForm3d	*Xf;
	float		*Speed;
	geVec3d		BasePos;
	geBitmap	*Bitmap;

#pragma GE_Published
	geVec3d		Position;
        GE_RGBA		Color;
	float		Scale;
	int		ParticleCount;
	float		Radius;
	float		RadiusY;
	float		Height;
	float		XSlant;
	float		ZSlant;
	float		MinSpeed;
	float		MaxSpeed;
	char		*BmpName;
	char		*AlphaName;
	char		*TriggerName;
	StaticEntityProxy *Entity;
	char		*BoneName;
	float		Rotation;
	float		ScaleRate;
	float		AlphaRate;
	float		Transparencia;
	geBoolean	ShowAlways;
	float		RadioMov;
	geBoolean 	Activo;
	//geWorld_Model *	Model;

#pragma GE_Origin( Position )
#pragma GE_DefaultValue( Color, "255.0 255.0 255.0" )
#pragma GE_DefaultValue( Scale, "1.0" )
#pragma GE_DefaultValue( ParticleCount, "10" )
#pragma GE_DefaultValue( Radius, "100" )
#pragma GE_DefaultValue( Height, "100" )
#pragma GE_DefaultValue( XSlant, "0.65" )
#pragma GE_DefaultValue( ZSlant, "0.65" )
#pragma GE_DefaultValue( MinSpeed, "5" )
#pragma GE_DefaultValue( MaxSpeed, "10" )
#pragma GE_DefaultValue( TriggerName, "" )
#pragma GE_DefaultValue( BoneName, "EFFECT_BONE01" )
#pragma GE_DefaultValue( BmpName, "trans.bmp" )
#pragma GE_DefaultValue( AlphaName, "a_trans.bmp" )
	
#pragma GE_Documentation( Entity, "<sin función> Entidad 'StaticEntityProxy' asociada" )
#pragma GE_Documentation( Position, "Posición del efecto" )
#pragma GE_Documentation( Color, "Color de la partícula" )
#pragma GE_Documentation( Scale, "Tamaño de la partícula" )
#pragma GE_Documentation( ParticleCount, "Partículas a usar" )
#pragma GE_Documentation( Radius, "Radio horizontal de colocación de las partículas" )
#pragma GE_Documentation( Height, "<sin función> Altura de la partícula" )
#pragma GE_Documentation( XSlant, "<sin función> Inclinación ascendente en eje X" )
#pragma GE_Documentation( ZSlant, "<sin función> Inclinación ascendente en eje Z" )
#pragma GE_Documentation( MinSpeed, "Mínima velocidad de cada partícula" )
#pragma GE_Documentation( MaxSpeed, "Máxima velocidad de cada partícula" )
#pragma GE_Documentation( BmpName, "Nombre de imagen .BMP que representa la partícula" )
#pragma GE_Documentation( AlphaName, "Nombre de imagen .BMP (Alpha) que representa la partícula" )
#pragma GE_Documentation( TriggerName, "<sin función> Fichero de comandos .INI" )
#pragma GE_Documentation( BoneName, "<sin función> Hueso del esqueleto del 'actor' al que enganchar efecto" )
	
#pragma GE_DefaultValue( Rotation, "0.0" )
#pragma GE_Documentation( Rotation, "Velocidad de rotación (entre -3.14 y 3.14)" )

#pragma GE_DefaultValue( ScaleRate, "0.0" )
#pragma GE_Documentation( ScaleRate, "Velocidad de reducción de las partículas (entre 0 y Scale)" )

#pragma GE_DefaultValue( AlphaRate, "0.0" )
#pragma GE_Documentation( AlphaRate, "Velocidad de difuminación de las partículas (entre 0 y 255)" )

#pragma GE_DefaultValue( RadiusY, "0.0" )
#pragma GE_Documentation( RadiusY, "Radio vertical de colocación de las partículas" )

#pragma GE_DefaultValue( Transparencia, "255.0" )
#pragma GE_Documentation( Transparencia, "Nivel de transparencia. De 0 a 255" )

#pragma GE_DefaultValue( ShowAlways, "False" )
#pragma GE_Documentation( ShowAlways, "Mostrar aunque el origen no esté a la vista. True=Si False=No" )

#pragma GE_DefaultValue( RadioMov, "100.0" )
#pragma GE_Documentation( RadioMov, "Radio de acción de las partículas" )

#pragma GE_DefaultValue( Activo, "True" )
#pragma GE_Documentation( Activo, "¿ Efecto activo ?. True=Si False=No" )

//#pragma GE_Documentation(Model, "Modelo asociado al efecto. (Opcional)")

} Fx_Sprite;

// Definitions
geBoolean Sprite_Create(geEngine *Engine, Eff_Manager *EM);
Sprite_Destroy(Eff_Manager *EM);
void Sprite_Tick(Eff_Manager *EM);


#ifdef __cplusplus
}
#endif

#endif
