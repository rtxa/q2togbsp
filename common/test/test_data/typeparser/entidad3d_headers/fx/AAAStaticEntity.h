/******************************************************************************/
/*  StaticEntity.h                                                            */
/*                                                                            */
/*  Author: David Wulff                                                       */
/*  Description: Effect manager header (No implementado)                      */
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
/*  Copyright (c) 2005 - 2015; All rights reserved.                           */
/*                                                                            */
/*                        http://www.entidad-3d.com                           */
/******************************************************************************/

#pragma warning( disable : 4068 )

#ifndef SE_H
#define SE_H


#ifdef __cplusplus
extern "C" {
#endif

// ==========================
//	Static Entity proxy
// ==========================
#pragma GE_Type("Model.ico")
typedef struct _StaticEntityProxy
{
#pragma GE_Private
	geSound_Def *theSound;			// Handle of audio effect
	geSound *SoundHandle;				// For later modification of sound
	geActor *Actor;							// Actor for this entity
	geActor_Def *ActorDef;			// Actor def.
	int RunningTime;						// Timer for this static actor
	geBoolean bAnimated;				// Animation active flag
	geVec3d LastBBoxMin;				// Last bounding-box min. point
	geVec3d LastBBoxMax;				// Last bounding-box max. point
	int GravityTime;						// Used in gravity computations
	float TimeInAir;						// Time spent in the air, for gravity
	geBoolean bCollisionTest;		// Collision test enable/disable
	geBoolean bPlayingCollisionAnimation;	// TRUE if playing collision animation
	geBoolean bFollower;				// TRUE if entity is bound to a motion path
#pragma GE_Published
	geVec3d Origin;
	char *szSoundFile;
	float fRadius;							// Audio audible radius
	char *szActorFile;
	char *szEntityName;
	char *szDefaultAction;			// Default animation to play
	char *szImpactAction;				// Animation to play when collided with
	geBoolean bCanPush;					// Static entity can be pushed around
	int InitialAlpha;						// Transparency of actor
	geBoolean SubjectToGravity;	// TRUE if entity subject to gravity
	geFloat ScaleFactor;				// Factor to scale model by
	geBoolean FaceDestination;	// TRUE if entity rotated to face destination
	geVec3d ActorRotation;			// Rotation needed to properly orient actor
#pragma GE_Origin(Origin)
#pragma GE_DefaultValue(szSoundFile, "audio/st_entity.wav")
#pragma GE_DefaultValue(fRadius, "200.0")
#pragma GE_DefaultValue(szEntityName, "")
#pragma GE_DefaultValue(szActorFile, "actors/static.act")
#pragma GE_DefaultValue(szDefaultAction, "")
#pragma GE_DefaultValue(szImpactAction, "")
#pragma GE_DefaultValue(bCanPush, "False")
#pragma GE_DefaultValue(InitialAlpha, "255")
#pragma GE_DefaultValue(SubjectToGravity, "False")
#pragma GE_DefaultValue(ScaleFactor, "1.0")
#pragma GE_DefaultValue(FaceDestination, "False")
#pragma GE_DefaultValue(ActorRotation, "-89.55 3.14159268359 0.0")
#pragma GE_Documentation(szSoundFile, "Sonido para colisión y activación")
#pragma GE_Documentation(fRadius, "Rango audible del sonido")
#pragma GE_Documentation(szActorFile, "Fichero .ACT a cargar para este 'proxy'")
#pragma GE_Documentation(szEntityName, "Entidad asociada")
#pragma GE_Documentation(szDefaultAction, "Animación por defecto")
#pragma GE_Documentation(szImpactAction, "Animación al colisionar")
#pragma GE_Documentation(bCanPush, "True si el jugador puede empujar el 'actor'")
#pragma GE_Documentation(InitialAlpha,"Transparencia del 'actor', de 0 a 255")
#pragma GE_Documentation(SubjectToGravity, "True si al 'actor' le afecta la gravedad")
#pragma GE_Documentation(ScaleFactor, "Tamaño del 'actor'")
#pragma GE_Documentation(FaceDestination, "True si el 'actor' gira para encarar")
#pragma GE_Documentation(ActorRotation, "Rotación necesaria para la correcta orientación")
} StaticEntityProxy;


// ==========================
//	Particle System proxy
// ==========================
#pragma GE_Type("Model.ico")
typedef struct _ParticleSystemProxy
{
#pragma GE_Private
	geSound_Def *theSound;			// Handle of audio effect
	geSound *SoundHandle;				// For later modification of sound
	int psHandle;								// Particle system handle
	int pmHandle;								// Particle map handle
	geBoolean bFollower;				// TRUE if entity is bound to a motion path
#pragma GE_Published
	geVec3d Origin;
	int nStyle;									// Particle system style
	char *szSoundFile;					// Audio effect for particle system
	float fRadius;							// Audio audible radius
	char *szTexture;						// Texture for particles
	GE_RGBA clrColor;						// Color for particles
	int BirthRate;							// Over-ride default system birth rate
	int MaxParticleCount;				// Over-ride default max particle count
	int ParticleLifespan;				// Over-ride default particle lifespan
	char *szEntityName;					// Name for this particle system
#pragma GE_Origin(Origin)
#pragma GE_DefaultValue(nStyle, "2")
#pragma GE_DefaultValue(szSoundFile, "audio/psystem.wav")
#pragma GE_DefaultValue(fRadius, "200.0")
#pragma GE_DefaultValue(szTexture, "bitmaps/flare.bmp")
#pragma GE_DefaultValue(clrColor, "255 255 255")
#pragma GE_DefaultValue(BirthRate, "50")
#pragma GE_DefaultValue(MaxParticleCount, "10")
#pragma GE_DefaultValue(ParticleLifespan, "2000")
#pragma GE_DefaultValue(szEntityName, "")
#pragma GE_Documentation(nStyle, "Estilo del sistema de partículas")
#pragma GE_Documentation(szSoundFile, "Sonido en bucle")
#pragma GE_Documentation(fRadius, "Rango audible del sonido")
#pragma GE_Documentation(szTexture, "Textura a usar para las partículas")
#pragma GE_Documentation(clrColor, "Color de las partículas")
#pragma GE_Documentation(BirthRate, "Frecuencia de creación de las partículas")
#pragma GE_Documentation(MaxParticleCount, "Número máximo de partículas")
#pragma GE_Documentation(ParticleLifespan, "Ciclo de vida de las partículas")
#pragma GE_Documentation(szEntityName, "Entidad asociada")
} ParticleSystemProxy;


#ifdef __cplusplus
}
#endif

#endif

