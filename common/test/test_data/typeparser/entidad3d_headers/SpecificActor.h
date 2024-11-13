/****************************************************************************************/
/*  File: SpecificActor.h                                                               */
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
/*  Copyright (C) 2004 - 2016 Jordi Pérez; All rights reserved.                         */
/*                                                                                      */
/****************************************************************************************/

#ifndef	SPECIFICACTOR_H
#define SPECIFICACTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Genesis.h"
#include "Genvsi.h"

#pragma warning( disable : 4068 )

// ==========================
// Entidad 'SpecificActor'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct SpecificActor
{
#pragma GE_Private
	geFloat	lastTime;	// Temporización animación
	geActor	*pActor; // Puntero 'Actor'
	geActor_Def *pActorDef; // 'ActorDef'
	geFloat startTime;	// Temporización animación
	geVec3d	Rotation; // Rotación
	char *MotionUna; // Nombre de animación (una sola animación no cíclica)
	char *MotionCic; // Nombre de animación (una animación cíclica)
	#pragma GE_DefaultValue(MotionUna, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX")
	#pragma GE_DefaultValue(MotionCic, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX")
	geFloat TiempoVisible;
	#pragma GE_DefaultValue(TiempoVisible, "0.0")
	geFloat TiempoInvisible;
	#pragma GE_DefaultValue(TiempoInvisible, "0.0")
	char *BoneNameUnir;
	#pragma GE_DefaultValue(BoneNameUnir, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX")
	int	EstadoBoneUnir;
	#pragma GE_DefaultValue(EstadoBoneUnir, "0")
	geBoolean UnionJugadorLocal;
	#pragma GE_DefaultValue(UnionJugadorLocal, "0")

#pragma GE_Published
	char *CommandsFile;
	char *CommandsFile2;

	geBoolean   Boton_accion;
	#pragma GE_DefaultValue(Boton_accion, "False")
	#pragma GE_Documentation(Boton_accion, "¿ Activación si botón acción pulsado ? True=Si False=No")

	geVec3d	Origin; // Posición
	geVec3d	scale; // Escala
	geVec3d	Orientation; // Orientación
	char	*ActorFile; // Ruta y fichero del .ACT
	char	*Motion; // Nombre de la animación
	float	ASpeed; // Velocidad de la animación
	float	RSpeed; // Velocidad de la rotación
	geBoolean	RotateX; // Rotación en eje X
	geBoolean	RotateY; // Rotación en eje Y
	geBoolean	RotateZ; // Rotación en eje Z
	geBoolean	Visible; // 'Actor' visible actor
	geBoolean	Bloqueo_ver; // Ver bloqueo azul del actor (True/False)
	float Bloqueo_X; // Variación X de la zona de bloqueo
	float Bloqueo_Y; // Variación Y de la zona de bloqueo
	float Bloqueo_Z; // Variación Z de la zona de bloqueo
	int	Brillo;
	geBoolean	Bloqueo; // Colisión del jugador con este SpecificActor (True/False)
	geBoolean	Bloqueo_Bots; // Colisión de los Bots con este SpecificActor (True/False)
	geBoolean	Bloqueo_Proyectiles; // Colisión de proyectiles de las armas con este SpecificActor (True/False)
	int Transparencia;
	geBoolean	RenderSiNoVisible;
	int	Sombra;
	geBoolean	Resaltar;
	geVec3d		Zona_influencia;
	geBoolean	Render_tras_solido;
	int	Render_distancia_max;
	int	Luces_Dina_Max;
	int	Luces_Stat_Max;
	geBoolean Colorear;
	GE_RGBA	Color;
	geBoolean Boton_Accion_indicador;
	geBoolean Repetir_comandos_zona;
	geBoolean AllowRotation;
	geBoolean AllowOrbiting;
	geWorld_Model	*Model;

	#pragma GE_Origin(Origin)
	#pragma GE_DefaultValue(scale, "2.7 2.7 2.7")
	#pragma GE_DefaultValue(Orientation, "0 0 0")
	#pragma GE_DefaultValue(Rotation, "0 0 0")
	#pragma GE_DefaultValue(ActorFile, "armor.ACT")
	#pragma GE_DefaultValue(Motion, "Idle")
	#pragma GE_DefaultValue(ASpeed, "1")
	#pragma GE_DefaultValue(RSpeed, "1")
	#pragma GE_DefaultValue(RotateX, "False")
	#pragma GE_DefaultValue(RotateY, "False")
	#pragma GE_DefaultValue(RotateZ, "False")
	#pragma GE_DefaultValue(CommandsFile, "")
	#pragma GE_DefaultValue(CommandsFile2, "")
	#pragma GE_DefaultValue(Visible, "True")
	#pragma GE_DefaultValue(Bloqueo_ver, "False")
	#pragma GE_DefaultValue(Bloqueo_X, "0")
	#pragma GE_DefaultValue(Bloqueo_Y, "0")
	#pragma GE_DefaultValue(Bloqueo_Z, "0")
	#pragma GE_DefaultValue(Brillo, "200")
	#pragma GE_DefaultValue(Bloqueo, "True")
	#pragma GE_DefaultValue(Bloqueo_Bots, "True")
	#pragma GE_DefaultValue(Bloqueo_Proyectiles, "True")
	#pragma GE_DefaultValue(Transparencia, "255")
	#pragma GE_DefaultValue(RenderSiNoVisible, "False")
	#pragma GE_DefaultValue(Sombra, "0")
	#pragma GE_DefaultValue(Resaltar, "False")
	#pragma GE_DefaultValue(Zona_influencia, "45 45 45")
	#pragma GE_DefaultValue(Render_tras_solido, "True")
	#pragma GE_DefaultValue(Render_distancia_max, "0")
	#pragma GE_DefaultValue(Luces_Dina_Max, "3")
	#pragma GE_DefaultValue(Luces_Stat_Max, "3")
	#pragma GE_DefaultValue(Colorear, "False")
	#pragma GE_DefaultValue(Color, "255.0 255.0 255.0")
	#pragma GE_DefaultValue(Boton_Accion_indicador, "True")
	#pragma GE_DefaultValue(Repetir_comandos_zona, "True")
	#pragma GE_DefaultValue(AllowRotation, "True")
	#pragma GE_DefaultValue(AllowOrbiting, "True")

	#pragma GE_Documentation(CommandsFile, "Fichero de comandos si colisiona jugador (sin extensión .INI)")
	#pragma GE_Documentation(CommandsFile2, "Fichero de comandos si impacta proyectil")
	#pragma GE_Documentation(Origin, "Posición (X Y Z)")
	#pragma GE_Documentation(scale, "Escala")
	#pragma GE_Documentation(Orientation, "Orientación")
	#pragma GE_Documentation(ActorFile, "Nombre del fichero .ACT del modelo 3D a visualizar.")
	#pragma GE_Documentation(Motion, "Nombre de animación. Dejar en blanco para ninguna.")
	#pragma GE_Documentation(ASpeed, "Velocidad de la animación. 0.5 = lenta, 1 = normal, 2 = rápida, etc.")
	#pragma GE_Documentation(RSpeed, "Velocidad de la rotación. 0.5 = lenta, 1 = normal, 2 = rápida, etc.")
	#pragma GE_Documentation(RotateX, "¿ Rotación de X del modelo 3D ? True=Si False=No")
	#pragma GE_Documentation(RotateY, "¿ Rotación de Y del modelo 3D ? True=Si False=No")
	#pragma GE_Documentation(RotateZ, "¿ Rotación de Z del modelo 3D ? True=Si False=No")
	#pragma GE_Documentation(Visible, "¿ Visible ?. True=Si False=No")
	#pragma GE_Documentation(Bloqueo_ver, "¿ Ver zona de bloqueo del modelo 3D ? True=Si False=No")
	#pragma GE_Documentation(Bloqueo_X, "Variación en X del bloqueo del modelo 3D (0 sin variación)")
	#pragma GE_Documentation(Bloqueo_Y, "Variación en Y del bloqueo del modelo 3D (0 sin variación)")
	#pragma GE_Documentation(Bloqueo_Z, "Variación en Z del bloqueo del modelo 3D (0 sin variación)")
	#pragma GE_Documentation(Brillo, "Nivel de brillo. (de 0 a 255)")
	#pragma GE_Documentation(Bloqueo, "¿ Detectar colisión con jugador ? True=Si False=No")
	#pragma GE_Documentation(Bloqueo_Bots, "¿ Detectar colisión con Bots ? True=Si False=No")
	#pragma GE_Documentation(Bloqueo_Proyectiles, "¿ Detectar colisión con proyectiles de armas ? True=Si False=No")
	#pragma GE_Documentation(Transparencia, "Nivel de transparencia (de 0 a 255, 255=Opaco 128=Semitransparente)")
	#pragma GE_Documentation(RenderSiNoVisible, "¿ Calcular 'render' si está detrás del jugador ? True=Si False=No")
	#pragma GE_Documentation(Sombra, "Tipo de sombra. (0=Sin sombra, 1=Círculo, 2=Dinámica)")
	#pragma GE_Documentation(Resaltar, "Resaltar con variación de brillo. True=Si False=No")
	#pragma GE_Documentation(Zona_influencia, "Zona de influencia de esta entidad (Y es en vertical)")
	#pragma GE_Documentation(Render_tras_solido, "¿ Calcular 'render' si está detrás de bloque sólido ? True=Si False=No")
	#pragma GE_Documentation(Render_distancia_max, "Distancia máxima para calcular 'render' (0 sin distancia)")
	#pragma GE_Documentation(Luces_Dina_Max, "Luces dinámicas que afectan al modelo 3D. (de 0 a 9)")
	#pragma GE_Documentation(Luces_Stat_Max, "Luces estáticas que afectan al modelo 3D. (de 0 a 9)")
	#pragma GE_Documentation(Colorear, "Usar el valor de 'Color' para colorear el modelo 3D. True=Si False=No")
	#pragma GE_Documentation(Color, "Color del modelo 3D.'Colorear' debe estar a 'True'")
	#pragma GE_Documentation(Boton_Accion_indicador, "Mostrar indicador de tecla 'Acción'.'Boton_accion' debe estar a 'True'")
	#pragma GE_Documentation(Repetir_comandos_zona, "Procesar 'CommandsFile' mientras el jugador siga en la zona de influencia")
	#pragma GE_Documentation(AllowRotation, "¿ Rotación del .ACT según la rotación del modelo asociado ? True=Si False=No")
	#pragma GE_Documentation(AllowOrbiting, "¿ Orbitación del .ACT según la rotación del modelo asociado ? True=Si False=No")
	#pragma GE_Documentation(Model, "Modelo asociado al .ACT (Opcional)")

} SpecificActor;

// Declaración de funciones
geBoolean SpecificActor_Spawn(geWorld *World, geBitmap *Bitmap);
geBoolean SpecificActor_Render(geWorld *World, GenVSI *VSI, int ancho_resolucion, int alto_resolucion, float Time);
geBoolean Free_SpecificActor(geWorld *World);

#ifdef	__cplusplus
}
#endif

#endif