// Genvs.h -- Genesis Editor standard entity types
//
// Copyright  1999, WildTangent, Inc.
//
/****************************************************************************************/
/*  File: Genvs.h                                                                       */
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

#ifndef GENVS_H
#define GENVS_H

#include "Quatern.h"
#include "GenVSI.h"

#include "PhysicsObject.h"
#include "PhysicsJoint.h"
#include "PhysicsSystem.h"

#include "botact.h"

#pragma warning( disable : 4068 )
#ifdef __cplusplus
extern "C" {
#endif

//SURF_METAL 	 0x00000400 	1024  	Metal floor
//SURF_DIRT 	 0x00000800 	2048  	Dirt, sand, rock
//SURF_VENT 	 0x00001000 	4096  	Ventillation duct
//SURF_GRATE 	 0x00002000 	8192  	Metal grating
//SURF_TILE 	 0x00004000 	16384  	Floor tiles
//SURF_GRASS 	 0x00008000 	32768  	Grass
//SURF_SNOW 	 0x00010000 	65536  	Snow
//SURF_CARPET 	 0x00020000 	131072 	Carpet
//SURF_FORCE 	 0x00040000 	262144 	Force field


// ============================================
// Enumeración de contenidos de bloques 'brush'
// ============================================
#pragma GE_BrushContents
typedef enum
{
	Water = 0x00010000,
	Lava = 0x00020000,
	Ladder = 0x00040000,
	Agua_baja = 0x00080000,
	Metal = 0x00100000,
	Madera = 0x00200000,
	Hierba = 0x00400000,
	Pavimento = 0x00800000,
	Tierra = 0x01000000,
	Nieve = 0x02000000,
	Nieve_baja = 0x04000000
	/*
	type4 = 0x00080000,
	type5 = 0x00100000,
	type6 = 0x00200000,
	type7 = 0x00400000,
	type8 = 0x00800000,
	type9 = 0x01000000,
	type10 = 0x02000000,
	type11 = 0x04000000,
	type12 = 0x08000000,
	type13 = 0x10000000,
	type14 = 0x20000000,
	type15 = 0x40000000,
	type16 = 0x80000000
	*/
} UserContentsEnum;


// ==========================
// Entidad 'PlayerStart'
// ==========================
#pragma GE_Type("Player.ico")
typedef struct	PlayerStart
{
#pragma GE_Published
    geVec3d     Origin;
#pragma GE_Origin(Origin)
}	PlayerStart;


// ==========================
// Entidad 'DeathMatchStart'
// ==========================
#pragma GE_Type("Player.ico")
typedef struct DeathMatchStart
{
#pragma GE_Published
    geVec3d     Origin;
	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

	char *Anim_agachado_Idle;
	#pragma GE_DefaultValue(Anim_agachado_Idle, "")
	#pragma GE_Documentation(Anim_agachado_Idle, "Nombre animación del personaje parado agachado. Normalmente 'Idle_agachado'")

	char *Anim_agachado_Walk;
	#pragma GE_DefaultValue(Anim_agachado_Walk, "")
	#pragma GE_Documentation(Anim_agachado_Walk, "Nombre animación del personaje caminando agachado. Normalmente 'Walk_agachado'")

	char *Anim_salto;
	#pragma GE_DefaultValue(Anim_salto, "")
	#pragma GE_Documentation(Anim_salto, "Nombre de animación para el salto del personaje. Normalmente 'JumpLand'")

	char *Anim_escalar;
	#pragma GE_DefaultValue(Anim_escalar, "")
	#pragma GE_Documentation(Anim_escalar, "Nombre de animación del personaje escalando. Normalmente 'Escalar'")

	char *Anim_nadar;
	#pragma GE_DefaultValue(Anim_nadar, "")
	#pragma GE_Documentation(Anim_nadar, "Nombre de animación del personaje nadando. Normalmente 'Swim'")

	geBoolean   Avance_direccion;
	#pragma GE_DefaultValue(Avance_direccion, "False")
	#pragma GE_Documentation(Avance_direccion, "Avance del jugador según las teclas de dirección. False=No True=Si")

	int	Vidas;
	#pragma GE_DefaultValue(Vidas, "4")
	#pragma GE_Documentation(Vidas, "Número de vidas iniciales del jugador")

	geBoolean   Jugador_masculino;
	#pragma GE_DefaultValue(Jugador_masculino, "True")
	#pragma GE_Documentation(Jugador_masculino, "Género del personaje del jugador. True=Masculino False=Femenino")

	int	Salto_jugador;
	#pragma GE_DefaultValue(Salto_jugador, "510")
	#pragma GE_Documentation(Salto_jugador, "Altura a la que saltará el jugador. Entre 0 y 5000. 0 no salta")

	int	Brillo_jugador;
	#pragma GE_DefaultValue(Brillo_jugador, "200")
	#pragma GE_Documentation(Brillo_jugador, "Nivel de brillo que se aplicará al jugador. Entre 0 y 255")

	geBoolean   Movimiento_lateral;
	#pragma GE_DefaultValue(Movimiento_lateral, "True")
	#pragma GE_Documentation(Movimiento_lateral, "Permitir movimiento lateral al jugador. True=Si False=No")

	geVec3d		Colision_player1p;
	#pragma GE_DefaultValue(Colision_player1p, "0 0 0")
	#pragma GE_Documentation(Colision_player1p, "Corrección de colisión jugador (+). De 0 a 2000.")

	geVec3d		Colision_player1n;
	#pragma GE_DefaultValue(Colision_player1n, "0 0 0")
	#pragma GE_Documentation(Colision_player1n, "Corrección de colisión jugador (-). De 0 a -2000.")

	geVec3d		Colision_player2p;
	#pragma GE_DefaultValue(Colision_player2p, "0 0 0")
	#pragma GE_Documentation(Colision_player2p, "Corrección de colisión jugador (+). De 0 a 2000.")

	geVec3d		Colision_player2n;
	#pragma GE_DefaultValue(Colision_player2n, "0 0 0")
	#pragma GE_Documentation(Colision_player2n, "Corrección de colisión jugador (-). De 0 a -2000.")

	geBoolean   Sonido_pasos;
	#pragma GE_DefaultValue(Sonido_pasos, "True")
	#pragma GE_Documentation(Sonido_pasos, "¿ Sonido de pasos al correr el jugador ?. False=No True=Si")

	geBoolean   Pierde_armas;
	#pragma GE_DefaultValue(Pierde_armas, "False")
	#pragma GE_Documentation(Pierde_armas, "El jugador pierde sus armas al morir. True=Si False=No")

	geBoolean   Ver_arma;
	#pragma GE_DefaultValue(Ver_arma, "False")
	#pragma GE_Documentation(Ver_arma, "¿ Ver arma en primera persona ?. False=No True=Si")

	geBoolean   Usar_Blaster;
	#pragma GE_DefaultValue(Usar_Blaster, "True")
	#pragma GE_Documentation(Usar_Blaster, "¿ Permitir usar el arma Blaster ?. False=No True=Si")

	geBoolean   Sangre_charco;
	#pragma GE_DefaultValue(Sangre_charco, "True")
	#pragma GE_Documentation(Sangre_charco, "Ver charco de sangre al morir jugador. True=Si False=No")

	geBoolean   Inventario_3D;
	#pragma GE_DefaultValue(Inventario_3D, "False")
	#pragma GE_Documentation(Inventario_3D, "Inventario de objetos presenta objeto seleccionado en 3D. True=Si False=No")

	int	Dinero;
	#pragma GE_DefaultValue(Dinero, "0")
	#pragma GE_Documentation(Dinero, "Cantidad de dinero inicial para el jugador")

	geBoolean   QuitaSaludCaidas;
	#pragma GE_DefaultValue(QuitaSaludCaidas, "False")
	#pragma GE_Documentation(QuitaSaludCaidas, "Quita salud al jugador en las caidas. True=Si False=No")

	float	Velocidad;
	#pragma GE_DefaultValue(Velocidad, "4000")
	#pragma GE_Documentation(Velocidad, "Velocidad del jugador corriendo.")

	int	Sombra;
	#pragma GE_DefaultValue(Sombra, "1")
	#pragma GE_Documentation(Sombra, "Tipo de sombra del jugador. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	geBoolean Sangre;
	#pragma GE_DefaultValue(Sangre, "True")
	#pragma GE_Documentation(Sangre, "Aparece sangre en el jugador por impactos de armas 1 y 4. True=Si False=No")

	geBoolean Bloqueo_ver;
	#pragma GE_DefaultValue(Bloqueo_ver, "False")
	#pragma GE_Documentation(Bloqueo_ver, "¿ Ver zona de bloqueo del jugador ?. True=Si False=No")

	geBoolean Tiene_arma_2;
	#pragma GE_DefaultValue(Tiene_arma_2, "False")
	#pragma GE_Documentation(Tiene_arma_2, "Jugador tiene arma 2 al comenzar. True=Si False=No")

	geBoolean Tiene_arma_3;
	#pragma GE_DefaultValue(Tiene_arma_3, "False")
	#pragma GE_Documentation(Tiene_arma_3, "Jugador tiene arma 3 al comenzar. True=Si False=No")

	geBoolean Tiene_arma_4;
	#pragma GE_DefaultValue(Tiene_arma_4, "False")
	#pragma GE_Documentation(Tiene_arma_4, "Jugador tiene arma 4 al comenzar. True=Si False=No")

	geBoolean Se_hunde_en_agua;
	#pragma GE_DefaultValue(Se_hunde_en_agua, "True")
	#pragma GE_Documentation(Se_hunde_en_agua, "El jugador se hunde en el agua. True=Si False=No")

	int	Salud_jugador;
	#pragma GE_DefaultValue(Salud_jugador, "100")
	#pragma GE_Documentation(Salud_jugador, "Nivel de salud del jugador por cada vida. (de 1 a 100)")

	float Respawn_tiempo;
	#pragma GE_DefaultValue(Respawn_tiempo, "0")
	#pragma GE_Documentation(Respawn_tiempo, "Tiempo en reaparecer el jugador (de 0 a 99 segundos)")

	geBoolean Online_indicador_sobre_cabeza;
	#pragma GE_DefaultValue(Online_indicador_sobre_cabeza, "True")
	#pragma GE_Documentation(Online_indicador_sobre_cabeza, "En modo online muestra indicador sobre la cabeza del jugador propio. True=Si False=No")

	geBoolean Recuperar_salud;
	#pragma GE_DefaultValue(Recuperar_salud, "False")
	#pragma GE_Documentation(Recuperar_salud, "El jugador recupera automáticamente algo de salud. True=Si False=No")

#pragma GE_Origin(Origin)
}   DeathMatchStart;



// MissleTurret
//#pragma GE_Type("Player.ico")
typedef struct	AttackerTurret
{
//#pragma GE_Published
    geVec3d     Origin;
//#pragma GE_Origin(Origin)
}	AttackerTurret;


// ==========================
// Entidad 'PhysicsObject'
// ==========================
typedef struct PhysicsObject PhysicsObject;
#pragma GE_Type("Model.ico")
typedef struct	PhysicsObject
{
#pragma GE_Published
  geWorld_Model		*Model;
  geVec3d					Origin;
	float						mass;
	int							isAffectedByGravity;
	int							respondsToForces;
	float						linearDamping;
	float						angularDamping;
	PhysicsObject				*Next;
	float						physicsScale;
	float						tiempoAvance;
	float						tiempoRetroceso;
	geBoolean					levantarObjeto;
	geBoolean					ascensorObjeto;
	geBoolean					Bloqueo_ver;
	float						Bloqueo_escala;
	geVec3d						Colision_MAX_objeto;
	geVec3d						Colision_MIN_objeto;
	geWorld_Model				*ColisionModel;
	char						*ColisionCommandsFile;
	geBoolean					Flota;
	geBoolean					Enemigos_lo_mueven;
	geBoolean					GravedadPorImpacto;

#pragma GE_Documentation(Model, "'Model' al que le afectarán todos estos parámetros")

#pragma GE_Documentation(Origin, "Posición de esta entidad. Colocar en el interior del objeto")

#pragma GE_DefaultValue(mass, "10.0")
#pragma GE_Documentation(mass, "Peso del objeto")

#pragma GE_DefaultValue(isAffectedByGravity, "1")
#pragma GE_Documentation(isAffectedByGravity, "¿ Le afecta la gravedad ? 0=No, 1=Si")

#pragma GE_DefaultValue(respondsToForces, "1")
#pragma GE_Documentation(respondsToForces, "¿ Responde a fuerzas externas ? 0=No, 1=Si")

#pragma GE_DefaultValue(linearDamping, "0.0005")
#pragma GE_Documentation(linearDamping, "Velocidad de avance o caida (5 no se mueve)")

#pragma GE_DefaultValue(angularDamping, "5")
#pragma GE_Documentation(angularDamping, "Velocidad de rotación (0.0005 rota)")

#pragma GE_DefaultValue(physicsScale, "0.01")
#pragma GE_Documentation(physicsScale, "Escala de las fuerzas < no se usa >")

#pragma GE_Documentation(Next, "Siguiente 'PhysicsObject' para aplicarle fuerza")

#pragma GE_DefaultValue(tiempoAvance, "1")
#pragma GE_Documentation(tiempoAvance, "Tiempo sin tener en cuenta la gravedad al empujar el objeto")

#pragma GE_DefaultValue(tiempoRetroceso, "4")
#pragma GE_Documentation(tiempoRetroceso, "Tiempo sin tener en cuenta la gravedad al tirar del objeto")

#pragma GE_DefaultValue(levantarObjeto, "True")
#pragma GE_Documentation(levantarObjeto, "¿ El jugador puede levantar el objeto ? True=Si False=No")

#pragma GE_DefaultValue(ascensorObjeto, "False")
#pragma GE_Documentation(ascensorObjeto, "¿ Objeto ascensor controlado por el jugador ? True=Si False=No")

#pragma GE_DefaultValue(Bloqueo_ver, "False")
#pragma GE_Documentation(Bloqueo_ver, "¿ Ver zona de bloqueo del 'model' ? True=Si False=No")

#pragma GE_DefaultValue(Bloqueo_escala, "0")
#pragma GE_Documentation(Bloqueo_escala, "Permite ajustar el tamaño de la zona de bloqueo (0.5 Mitad  2.0 Doble")

#pragma GE_DefaultValue(Colision_MAX_objeto, "0 0 0")
#pragma GE_Documentation(Colision_MAX_objeto, "Corrección de colisión objeto (+). De 0 a 2000.")

#pragma GE_DefaultValue(Colision_MIN_objeto, "0 0 0")
#pragma GE_Documentation(Colision_MIN_objeto, "Corrección de colisión objeto (-). De 0 a 2000.")

#pragma GE_Documentation(ColisionModel, "'Model' de colisión para lanzar comandos de 'ColisionCommandsFile'")

#pragma GE_DefaultValue(ColisionCommandsFile, "")
#pragma GE_Documentation(ColisionCommandsFile, "Fichero de comandos para colisión con 'ColisionModel' (sin extensión .INI)")

#pragma GE_DefaultValue(Flota, "False")
#pragma GE_Documentation(Flota, "¿ Flota en líquidos ? True=Si False=No")

#pragma GE_DefaultValue(Enemigos_lo_mueven, "True")
#pragma GE_Documentation(Enemigos_lo_mueven, "¿ Lo pueden mover los Bots o sus disparos ? True=Si False=No")

#pragma GE_DefaultValue(GravedadPorImpacto, "False")
#pragma GE_Documentation(GravedadPorImpacto, "¿ Aplicar gravedad si recibe un disparo del jugador ? True=Si False=No")

#pragma GE_Private
	gePhysicsObject *			stateInfo;
	geBoolean colisionando;
	int	isAffectedByGravityCopy;
	float timeNoGravity;
	geVec3d	PosActual;
	geVec3d	Mins;
	geVec3d	Maxs;
	float NextThinkTime;
#pragma GE_Origin(Origin)
}	PhysicsObject;

typedef struct PhysicsJoint PhysicsJoint;


// ==========================
// Entidad 'PhysicsJoint'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  PhysicsJoint
{
#pragma GE_Published
    geVec3d					Origin;
		PhysicsObject *	physicsObject1;
		PhysicsObject *	physicsObject2;
		PhysicsJoint			* Next;
		float						assemblyRate;
		int jointType;
		float physicsScale;
#pragma GE_DefaultValue(assemblyRate, "0.03")
#pragma GE_DefaultValue(physicsScale, "0.01")

#pragma GE_Private
		gePhysicsJoint *			jointData;
#pragma GE_Origin(Origin)
}   PhysicsJoint;



// ==========================
// Entidad 'PhysicalSystem'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct PhysicalSystem
{
#pragma GE_Published
	geVec3d						Origin;
	PhysicsObject		*	physicsObjectListHeadPtr;
	PhysicsJoint				*	jointListHeadPtr;

	#pragma GE_Documentation(physicsObjectListHeadPtr, "Entidad 'PhysicsObject' asociada a esta entidad")

#pragma GE_Private
//		AnyStruct			*	physsysData;
		gePhysicsSystem	*				physsysData;
#pragma GE_Origin(Origin)
} PhysicalSystem;



typedef enum
{
	FALLOFF_NONE = 0,
	FALLOFF_ONE_OVER_D,
	FALLOFF_ONE_OVER_DSQUARED
};


// ==========================
// Entidad 'ForceField'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct ForceField
{
#pragma GE_Published
	geVec3d						Origin;
	float							radius;
	float							strength;
	int								falloffType;
	int								affectsPlayers;
	int								affectsPhysicsObjects;

#pragma GE_DefaultValue(radius, "50.0")
#pragma GE_DefaultValue(falloffType, "1")
#pragma GE_DefaultValue(affectsPlayers, "1")
#pragma GE_DefaultValue(affectsPhysicsObjects, "1")

#pragma GE_Origin(Origin)
} ForceField;


// ==========================
// Entidad 'Door'
// ==========================
#pragma GE_Type("Model.ico")
typedef struct  Door
{
#pragma GE_Published
    geWorld_Model   *Model;

	geBoolean   Ciclico;
	#pragma GE_DefaultValue(Ciclico, "False")
	#pragma GE_Documentation(Ciclico, "La puerta se abre y se cierra sin parar. True=Si False=No")

	geBoolean   Boton_accion;
	#pragma GE_DefaultValue(Boton_accion, "False")
	#pragma GE_Documentation(Boton_accion, "¿ Activación si botón acción pulsado ? True=Si False=No")

    geVec3d			Origin;
	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

	char *CommandsFile;
	#pragma GE_DefaultValue(CommandsFile, "")
	#pragma GE_Documentation(CommandsFile, "Fichero de comandos para contacto (sin extensión .INI)")

	char *CommandsFile2;
	#pragma GE_DefaultValue(CommandsFile2, "")
	#pragma GE_Documentation(CommandsFile2, "Fichero de comandos para impacto (sin extensión .INI)")

	char *CommandsFileE;
	#pragma GE_DefaultValue(CommandsFileE, "")
	#pragma GE_Documentation(CommandsFileE, "Fichero de comandos para Bots (sin extensión .INI)")

	geBoolean   AbrirPorImpacto;
	#pragma GE_DefaultValue(AbrirPorImpacto, "False")
	#pragma GE_Documentation(AbrirPorImpacto, "Abrir puerta por impacto de armas 1 o 3. True=Si False=No")

	geBoolean   EnemigoAbre;
	#pragma GE_DefaultValue(EnemigoAbre, "False")
	#pragma GE_Documentation(EnemigoAbre, "Bots abren esta puerta. True=Si False=No")

	geBoolean   En_movimiento;
	#pragma GE_DefaultValue(En_movimiento, "False")
	#pragma GE_Documentation(En_movimiento, "¿ En movimiento desde el comienzo del nivel ? True=Si False=No")

	geBoolean   JugadorAbre;
	#pragma GE_DefaultValue(JugadorAbre, "True")
	#pragma GE_Documentation(JugadorAbre, "Jugador abre esta puerta. True=Si False=No")

	geBoolean   Evento_con_movimiento;
	#pragma GE_DefaultValue(Evento_con_movimiento, "False")
	#pragma GE_Documentation(Evento_con_movimiento, "Procesar eventos aunque la puerta esté en movimiento. True=Si False=No")

	geBoolean   Sonidos_puerta;
	#pragma GE_DefaultValue(Sonidos_puerta, "True")
	#pragma GE_Documentation(Sonidos_puerta, "Reproduce sonidos por defecto de la puerta. True=Si False=No")

	geBoolean Boton_Accion_indicador;
	#pragma GE_DefaultValue(Boton_Accion_indicador, "True")
	#pragma GE_Documentation(Boton_Accion_indicador, "Mostrar indicador de tecla 'Acción'.'Boton_accion' debe estar a 'True'")

	geBoolean Repetir_comandos_zona;
	#pragma GE_DefaultValue(Repetir_comandos_zona, "True")
	#pragma GE_Documentation(Repetir_comandos_zona, "Procesar 'CommandsFile' mientras el jugador siga en la zona de influencia")

#pragma GE_Private

	char		*Ptr;

#pragma GE_Origin(Origin)
}   Door;



// ==========================
// Entidad 'TextPrompt'
// ==========================
#pragma GE_Type("Model.ico")
typedef struct TextPrompt
{
	#pragma GE_Published
	geWorld_Model *Model;
	char *TextInput;
	char *TextInput1;
	char *TextInput2;
	geVec3d Origin;
#pragma GE_Origin(Origin)
} TextPrompt;



// ==========================
// Entidad 'Explosión'
// ==========================
#pragma GE_Type("Model.ico")
typedef struct Explosion
{
	#pragma GE_Published
	geVec3d Origin;

	int Num_explosion;	
	#pragma GE_DefaultValue(Num_explosion, "1")
	#pragma GE_Documentation(Num_explosion, "Número de explosión (entre 1 y 255)")
		
	float Dimension;
	#pragma GE_DefaultValue(Dimension, "20")
	#pragma GE_Documentation(Dimension, "Tamaño de la explosión")

	float Velocidad;
	#pragma GE_DefaultValue(Velocidad, "10")
	#pragma GE_Documentation(Velocidad, "A menos valor, explosión más lenta")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
} Explosion;



// ==========================
// Entidad 'Animacion'
// ==========================
#pragma GE_Type("Model.ico")
typedef struct Animacion
{
	#pragma GE_Published

	geVec3d Origin;

	geBoolean   Ciclica;
	#pragma GE_DefaultValue(Ciclica, "True")
	#pragma GE_Documentation(Ciclica, "¿ La animación se repite continuamente ? True=Si False=No")

	char *Sonido;
	#pragma GE_DefaultValue(Sonido, "animacion")
	#pragma GE_Documentation(Sonido, "Nombre de fichero .WAV a interpretar (sin indicar extensión .WAV)")

	float   Transparencia;
	#pragma GE_DefaultValue(Transparencia, "255")
	#pragma GE_Documentation(Transparencia, "Nivel de transparencia (de 0 a 255). 255 sin transparencia")

	geBoolean   Activa;
	#pragma GE_DefaultValue(Activa, "False")
	#pragma GE_Documentation(Activa, "¿ Animación activa al iniciar el nivel ? True=Si False=No")

	char *Nombre;
	#pragma GE_DefaultValue(Nombre, "chica")
	#pragma GE_Documentation(Nombre, "Nombre de la secuencia de .BMPs de la animación.")

	int Cuadro_inicial;	
	#pragma GE_DefaultValue(Cuadro_inicial, "1")
	#pragma GE_Documentation(Cuadro_inicial, "Fotograma inicial de la animación.")

	int Cuadro_final;	
	#pragma GE_DefaultValue(Cuadro_final, "8")
	#pragma GE_Documentation(Cuadro_final, "Fotograma final de la animación.")

	int Num_animacion;	
	#pragma GE_DefaultValue(Num_animacion, "1")
	#pragma GE_Documentation(Num_animacion, "Número de animación (entre 1 y 255)")
		
	float Dimension;
	#pragma GE_DefaultValue(Dimension, "3")
	#pragma GE_Documentation(Dimension, "Tamaño de la animación")

	float Velocidad;
	#pragma GE_DefaultValue(Velocidad, "8")
	#pragma GE_Documentation(Velocidad, "A menos valor, animación más lenta")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
} Animacion;



// ==========================
// Entidad 'Command'
// ==========================
#pragma GE_Type("Model.ico")
typedef struct Command
{
#pragma GE_Private

	char		*Ptr;

#pragma GE_Published
	geVec3d Origin;

	char *CommandsFile;
	#pragma GE_DefaultValue(CommandsFile, "")
	#pragma GE_Documentation(CommandsFile, "Fichero de comandos (sin extensión .INI)")

	geBoolean   Boton_accion;
	#pragma GE_DefaultValue(Boton_accion, "False")
	#pragma GE_Documentation(Boton_accion, "¿ Activación si botón acción pulsado ? True=Si False=No")
	
	geBoolean   Visible;
	#pragma GE_DefaultValue(Visible, "False")
	#pragma GE_Documentation(Visible, "Mostrar una esfera como referencia de la posición. True=Si False=No")
	
	geVec3d Zona_influencia;
	#pragma GE_DefaultValue(Zona_influencia, "20 20 20")
	#pragma GE_Documentation(Zona_influencia, "Zona de influencia de esta entidad (Y es en vertical)")

	geBoolean	Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Entidad activa al iniciar el juego ? True=Si False=No")

	geBoolean	Reaparece;
	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparece ? True=Si False=No")

	float Tiempo_reaparicion;
	#pragma GE_DefaultValue(Tiempo_reaparicion, "3")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer (en segundos)")

	int Ver_en_radar;
	#pragma GE_DefaultValue(Ver_en_radar, "0")
	#pragma GE_Documentation(Ver_en_radar, "La posición se muestra en el radar. 0=No, 1=Si en rango, 2=Si en borde")

	int Icono_en_radar;
	#pragma GE_DefaultValue(Icono_en_radar, "1")
	#pragma GE_Documentation(Icono_en_radar, "Tipo de símbolo que se muestra en el radar (1 a 4)")

	geBoolean Boton_Accion_indicador;
	#pragma GE_DefaultValue(Boton_Accion_indicador, "True")
	#pragma GE_Documentation(Boton_Accion_indicador, "Mostrar indicador de tecla 'Acción'.'Boton_accion' debe estar a 'True'")

	geBoolean Repetir_comandos_zona;
	#pragma GE_DefaultValue(Repetir_comandos_zona, "True")
	#pragma GE_Documentation(Repetir_comandos_zona, "Procesar 'CommandsFile' mientras el jugador siga en la zona de influencia")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
} Command;




// ==========================
// Entidad 'CommandModel'
// ==========================
#pragma GE_Type("Model.ico")
typedef struct CommandModel
{
#pragma GE_Published
	geWorld_Model *Model;
	
	geBoolean   Boton_accion;
	#pragma GE_DefaultValue(Boton_accion, "False")
	#pragma GE_Documentation(Boton_accion, "¿ Activación si botón acción pulsado ? True=Si False=No")
	
	geVec3d Origin;
	
	char *CommandsFile;
	#pragma GE_DefaultValue(CommandsFile, "")
	#pragma GE_Documentation(CommandsFile, "Fichero de comandos (sin extensión .INI) para contacto")
	
	char *CommandsFile2;
	#pragma GE_DefaultValue(CommandsFile2, "")
	#pragma GE_Documentation(CommandsFile2, "Fichero de comandos (sin extensión .INI) para impacto")

	geBoolean Boton_Accion_indicador;
	#pragma GE_DefaultValue(Boton_Accion_indicador, "True")
	#pragma GE_Documentation(Boton_Accion_indicador, "Mostrar indicador de tecla 'Acción'.'Boton_accion' debe estar a 'True'")

	geBoolean Repetir_comandos_zona;
	#pragma GE_DefaultValue(Repetir_comandos_zona, "True")
	#pragma GE_Documentation(Repetir_comandos_zona, "Procesar 'CommandsFile' mientras el jugador siga en la zona de influencia")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")
#pragma GE_Origin(Origin)
} CommandModel;



// ==========================
// Entidad 'ItemObject'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemObject
{
#pragma GE_Private

	char		*Ptr;

#pragma GE_Published
	char *ActorFile;
	char *ObjectName;
	char *ObjectGroup;
	float	Scale; // Vector de escalado
	geVec3d	Orientation; // Vector para orientación
    geVec3d	Origin;
	geBoolean   Respawn;
	geBoolean   Rotate;
	geBoolean   Catch;
	int			Brillo;
	char *CommandsFile;
	geBoolean   Inventario_objeto;
	float Tiempo_reaparicion;
	int			Usos;
	char *Descrip1;
	char *Descrip2;
	char *Descrip3;
	char *Descrip4;
	char *Descrip5_inv;
	char *Descrip6_inv;
	char *Descrip7_inv;
	char *Descrip8_inv;
	int	Precio_venta;
	int	Precio_compra;
	geBoolean   PanelObjeto;
	geBoolean   Boton_accion;
	float   Transparencia;
	int Sombra;
    geVec3d	Zona_influencia;
	geBoolean Fisica_objeto;
	int Ver_en_radar;
	int	Render_distancia_max;
	int	Numero_objeto;
	geBoolean Respawn_Origin;
	geBoolean Boton_Accion_indicador;
	geBoolean Repetir_comandos_zona;

	#pragma GE_DefaultValue(Boton_accion, "False")
	#pragma GE_Documentation(Boton_accion, "¿ Activación si botón Acción pulsado ? True=Si False=No")

	#pragma GE_DefaultValue(PanelObjeto, "True")
	#pragma GE_Documentation(PanelObjeto, "¿ Presenta datos del objeto al tocarlo ? True=Si False=No")

	#pragma GE_DefaultValue(Precio_venta, "0")
	#pragma GE_Documentation(Precio_venta, "Precio al venderlo el jugador (0 gratuito)")

	#pragma GE_DefaultValue(Precio_compra, "0")
	#pragma GE_Documentation(Precio_compra, "Precio al comprarlo el jugador (0 gratuito)")

	#pragma GE_DefaultValue(Descrip1, "")
	#pragma GE_Documentation(Descrip1, "Descripción del objeto, línea 1 (28 carac.)")

	#pragma GE_DefaultValue(Descrip2, "")
	#pragma GE_Documentation(Descrip2, "Descripción del objeto, línea 2 (28 carac.)")

	#pragma GE_DefaultValue(Descrip3, "")
	#pragma GE_Documentation(Descrip3, "Descripción del objeto, línea 3 (28 carac.)")

	#pragma GE_DefaultValue(Descrip4, "")
	#pragma GE_Documentation(Descrip4, "Descripción del objeto, línea 4 (28 carac.)")

	#pragma GE_DefaultValue(Descrip5_inv, "")
	#pragma GE_Documentation(Descrip5_inv, "Descripción del objeto en inventario, línea 5 (28 carac.)")

	#pragma GE_DefaultValue(Descrip6_inv, "")
	#pragma GE_Documentation(Descrip6_inv, "Descripción del objeto en inventario, línea 6 (28 carac.)")

	#pragma GE_DefaultValue(Descrip7_inv, "")
	#pragma GE_Documentation(Descrip7_inv, "Descripción del objeto en inventario, línea 7 (28 carac.)")

	#pragma GE_DefaultValue(Descrip8_inv, "")
	#pragma GE_Documentation(Descrip8_inv, "Descripción del objeto en inventario, línea 8 (28 carac.)")

	#pragma GE_DefaultValue(Usos, "1")
	#pragma GE_Documentation(Usos, "Número inicial de usos. (de 1 a 99)")

	#pragma GE_DefaultValue(Brillo, "190")
	#pragma GE_Documentation(Brillo, "Nivel de brillo. (de 0 a 255)")

	#pragma GE_DefaultValue(Catch, "True")
	#pragma GE_Documentation(Catch, "¿ Objeto recogible por el jugador ? True=Si False=No")

	#pragma GE_DefaultValue(Rotate, "True")
	#pragma GE_Documentation(Rotate, "¿ Objeto girando ? True=Si False=No")

	#pragma GE_DefaultValue(Respawn, "False")
	#pragma GE_Documentation(Respawn, "¿ Objeto reaparece después de ser recogido ? True=Si False=No")

	#pragma GE_DefaultValue(ActorFile, "caja.act")
	#pragma GE_Documentation(ActorFile, "Nombre del fichero .ACT del objeto")

	#pragma GE_DefaultValue(ObjectName, "")
	#pragma GE_Documentation(ObjectName, "Nombre completo del objeto")

	#pragma GE_DefaultValue(ObjectGroup, "")
	#pragma GE_Documentation(ObjectGroup, "Grupo al que pertenece el objeto ('Luz' si produce luz)")

	#pragma GE_DefaultValue(Scale, "1")
	#pragma GE_Documentation(Scale, "Tamaño (1=Sin variar  2=El doble  0.5=La mitad)")

	#pragma GE_DefaultValue(Orientation, "0 0 0")
	#pragma GE_Documentation(Orientation, "Orientación")

	#pragma GE_DefaultValue(CommandsFile, "")
	#pragma GE_Documentation(CommandsFile, "Fichero de comandos (sin extensión .INI)")

	#pragma GE_DefaultValue(Inventario_objeto, "True")
	#pragma GE_Documentation(Inventario_objeto, "¿ Al recogerlo se añade al inventario de objetos ? True=Si False=No")

	#pragma GE_DefaultValue(Tiempo_reaparicion, "60")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer después de recogido (en segundos)")

	#pragma GE_DefaultValue(Transparencia, "255")
	#pragma GE_Documentation(Transparencia, "Nivel de transparencia (de 0 a 255). 255 sin transparencia")

	#pragma GE_DefaultValue(Sombra, "1")
	#pragma GE_Documentation(Sombra, "Tipo de sombra. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	#pragma GE_DefaultValue(Zona_influencia, "20 20 20")
	#pragma GE_Documentation(Zona_influencia, "Caja que define la zona de influencia de este objeto")

	#pragma GE_DefaultValue(Fisica_objeto, "False")
	#pragma GE_Documentation(Fisica_objeto, "Aplicar física a este objeto. True=Si False=No")

	#pragma GE_DefaultValue(Ver_en_radar, "1")
	#pragma GE_Documentation(Ver_en_radar, "Objeto se muestra en el radar. 0=No, 1=Si en rango, 2=Si en borde")

	#pragma GE_DefaultValue(Render_distancia_max, "0")
	#pragma GE_Documentation(Render_distancia_max, "Distancia máxima para calcular 'render' (0 sin distancia)")

	#pragma GE_DefaultValue(Numero_objeto, "1")
	#pragma GE_Documentation(Numero_objeto, "Número de objeto (de 1 a 50)")

	#pragma GE_DefaultValue(Respawn_Origin, "False")
	#pragma GE_Documentation(Respawn_Origin, "¿ Objeto reaparece en posición Origin ? True=Si False=No")

	#pragma GE_DefaultValue(Boton_Accion_indicador, "True")
	#pragma GE_Documentation(Boton_Accion_indicador, "Mostrar indicador de tecla 'Acción'.'Boton_accion' debe estar a 'True'")

	#pragma GE_DefaultValue(Repetir_comandos_zona, "True")
	#pragma GE_Documentation(Repetir_comandos_zona, "Procesar 'CommandsFile' mientras el jugador siga en la zona de influencia")

#pragma GE_Origin(Origin)
}   ItemObject;



// ==========================
// Entidad 'MovingPlat'
// ==========================
#pragma GE_Type("Model.ico")
typedef struct  MovingPlat
{
#pragma GE_Published
    geWorld_Model	*Model;
	geBoolean   Ciclico;
	#pragma GE_DefaultValue(Ciclico, "False")
	#pragma GE_Documentation(Ciclico, "La plataforma se mueve sin parar. True=Si False=No")

	geBoolean   Boton_accion;
	#pragma GE_DefaultValue(Boton_accion, "False")
	#pragma GE_Documentation(Boton_accion, "¿ Activación si botón acción pulsado ? True=Si False=No")

    geVec3d			Origin;

	char *CommandsFile;
	#pragma GE_DefaultValue(CommandsFile, "")
	#pragma GE_Documentation(CommandsFile, "Fichero de comandos para contacto (sin extensión .INI)")

	char *CommandsFile2;
	#pragma GE_DefaultValue(CommandsFile2, "")
	#pragma GE_Documentation(CommandsFile2, "Fichero de comandos para impacto (sin extensión .INI)")

	char *CommandsFileE;
	#pragma GE_DefaultValue(CommandsFileE, "")
	#pragma GE_Documentation(CommandsFileE, "Fichero de comandos para Bots (sin extensión .INI)")

	geBoolean   MoverPorImpacto;
	#pragma GE_DefaultValue(MoverPorImpacto, "False")
	#pragma GE_Documentation(MoverPorImpacto, "Mover plataforma por impacto de armas 1 o 3. True=Si False=No")

	geBoolean   EnemigoMueve;
	#pragma GE_DefaultValue(EnemigoMueve, "False")
	#pragma GE_Documentation(EnemigoMueve, "Bots mueven esta plataforma. True=Si False=No")

	geBoolean   En_movimiento;
	#pragma GE_DefaultValue(En_movimiento, "False")
	#pragma GE_Documentation(En_movimiento, "¿ En movimiento desde el comienzo del nivel ? True=Si False=No")

	geBoolean   JugadorMueve;
	#pragma GE_DefaultValue(JugadorMueve, "True")
	#pragma GE_Documentation(JugadorMueve, "Jugador mueve esta plataforma. True=Si False=No")

	geBoolean   Evento_con_movimiento;
	#pragma GE_DefaultValue(Evento_con_movimiento, "False")
	#pragma GE_Documentation(Evento_con_movimiento, "Procesar eventos aunque la plataforma esté en movimiento. True=Si False=No")

	geBoolean   Sonidos_plataforma;
	#pragma GE_DefaultValue(Sonidos_plataforma, "True")
	#pragma GE_Documentation(Sonidos_plataforma, "Reproduce sonidos por defecto de la plataforma. True=Si False=No")

	geBoolean Boton_Accion_indicador;
	#pragma GE_DefaultValue(Boton_Accion_indicador, "True")
	#pragma GE_Documentation(Boton_Accion_indicador, "Mostrar indicador de tecla 'Acción'.'Boton_accion' debe estar a 'True'")

	geBoolean Repetir_comandos_zona;
	#pragma GE_DefaultValue(Repetir_comandos_zona, "True")
	#pragma GE_Documentation(Repetir_comandos_zona, "Procesar 'CommandsFile' mientras el jugador siga en la zona de influencia")

#pragma GE_Private

	char		*Ptr;

#pragma GE_Origin(Origin)
}   MovingPlat;



// ==================================
// Entidad 'ChangeLevel' (OBSOLETA)
// ==================================
#pragma GE_Type("Player.ico")
typedef struct ChangeLevel
{
#pragma GE_Private
    geVec3d			Origin;
#pragma GE_Published
    geWorld_Model	*Model;
	char			*LevelName;
	char			*CommandsFile;

	#pragma GE_Documentation(Model, "Nombre del 'model' que activa cargar el nuevo nivel")
	#pragma GE_DefaultValue(LevelName, "")	
	#pragma GE_Documentation(LevelName, "Nombre del nuevo nivel a cargar (sin extensión .BSP)")
	#pragma GE_DefaultValue(CommandsFile, "")
	#pragma GE_Documentation(CommandsFile, "Fichero de comandos al iniciar el nivel (sin extensión .INI)")
#pragma GE_Origin(Origin)
} ChangeLevel;



// ==========================
// Entidad 'ItemHealth'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemHealth
{
#pragma GE_Published
    geVec3d			Origin;
	geBoolean   Reaparece;
	geFloat		Incremento;
	int Num_ACT;
	int	Transparencia;
	int Brillo;
	float	Scale; // Vector de escalado
	int Sombra;
	float Tiempo_reaparicion;

	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparece después de ser recogido ? True=Si False=No")

	#pragma GE_DefaultValue(Incremento, "25")
	#pragma GE_Documentation(Incremento, "Incremento de salud al recoger el objeto (de 1 a 100)")

	#pragma GE_DefaultValue(Num_ACT, "1")
	#pragma GE_Documentation(Num_ACT, "Determina el modelo 3D que representa la salud (de 1 a 3)")

	#pragma GE_DefaultValue(Scale, "1")
	#pragma GE_Documentation(Scale, "Tamaño (1=Sin variar  2=El doble  0.5=La mitad)")

	#pragma GE_DefaultValue(Transparencia, "255")
	#pragma GE_Documentation(Transparencia, "Nivel de transparencia (de 0 a 255, 255=Opaco 128=Semitransparente)")

	#pragma GE_DefaultValue(Brillo, "190")
	#pragma GE_Documentation(Brillo, "Nivel de brillo (de 0 a 255)")

	#pragma GE_DefaultValue(Sombra, "1")
	#pragma GE_Documentation(Sombra, "Tipo de sombra. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	#pragma GE_DefaultValue(Tiempo_reaparicion, "60")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer después de recogido (en segundos)")

#pragma GE_Origin(Origin)
}   ItemHealth;



// ==========================
// Entidad 'ItemArmor'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct ItemArmor
{
#pragma GE_Published
    geVec3d     Origin;
	geBoolean   Reaparece;
	geFloat		Incremento;
	int	Transparencia;
	int Brillo;
	float	Scale;
	int Sombra;
	float Tiempo_reaparicion;

	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparición transcurridos unos segundos ? True=Si False=No")

	#pragma GE_DefaultValue(Incremento, "100")
	#pragma GE_Documentation(Incremento, "Incremento de escudo al recoger el objeto (de 1 a 100)")

	#pragma GE_DefaultValue(Scale, "1")
	#pragma GE_Documentation(Scale, "Tamaño (1=Sin variar  2=El doble  0.5=La mitad)")

	#pragma GE_DefaultValue(Transparencia, "255")
	#pragma GE_Documentation(Transparencia, "Nivel de transparencia (de 0 a 255, 255=Opaco 128=Semitransparente)")

	#pragma GE_DefaultValue(Brillo, "190")
	#pragma GE_Documentation(Brillo, "Nivel de brillo (de 0 a 255)")

	#pragma GE_DefaultValue(Sombra, "1")
	#pragma GE_Documentation(Sombra, "Tipo de sombra. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	#pragma GE_DefaultValue(Tiempo_reaparicion, "60")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer después de recogido (en segundos)")

#pragma GE_Origin(Origin)
} ItemArmor;



// ==========================
// Entidad 'ItemRocket'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemRocket
{
#pragma GE_Published
    geVec3d			Origin;
	geBoolean   Reaparece;
	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparición transcurridos unos segundos ? True=Si False=No")
	#pragma GE_Documentation(Origin, "Posición (X Y Z)")
#pragma GE_Origin(Origin)
} ItemRocket;



// ==========================
// Entidad 'ItemRocketAmmo'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemRocketAmmo
{
#pragma GE_Published
    geVec3d			Origin;
	geBoolean   Reaparece;
	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparición transcurridos unos segundos ? True=Si False=No")

	float Tiempo_reaparicion;
	#pragma GE_DefaultValue(Tiempo_reaparicion, "60")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer después de recogido (en segundos)")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
} ItemRocketAmmo;



// ==========================
// Entidad 'ItemGrenade'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemGrenade
{
#pragma GE_Published
    geVec3d			Origin;
	geBoolean   Reaparece;
	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparición transcurridos unos segundos ? True=Si False=No")
	#pragma GE_Documentation(Origin, "Posición (X Y Z)")
#pragma GE_Origin(Origin)
}   ItemGrenade;



// ==========================
// Entidad 'ItemGrenadeAmmo'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemGrenadeAmmo
{
#pragma GE_Published
    geVec3d			Origin;
	geBoolean   Reaparece;
	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparición transcurridos unos segundos ? True=Si False=No")

	float Tiempo_reaparicion;
	#pragma GE_DefaultValue(Tiempo_reaparicion, "60")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer después de recogido (en segundos)")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")
#pragma GE_Origin(Origin)
}   ItemGrenadeAmmo;



// ==========================
// Entidad 'ItemBlasterAmmo'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemBlasterAmmo
{
#pragma GE_Published
    geVec3d			Origin;
	geBoolean   Reaparece;
	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparición transcurridos unos segundos ? True=Si False=No")

	float Tiempo_reaparicion;
	#pragma GE_DefaultValue(Tiempo_reaparicion, "60")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer después de recogido (en segundos)")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")
#pragma GE_Origin(Origin)
}   ItemBlasterAmmo;



// ==========================
// Entidad 'ItemShredder'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemShredder
{
#pragma GE_Published
    geVec3d			Origin;
	geBoolean   Reaparece;
	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparición transcurridos unos segundos ? True=Si False=No")
	#pragma GE_Documentation(Origin, "Posición (X Y Z)")
#pragma GE_Origin(Origin)
}   ItemShredder;



// ==========================
// Entidad 'ItemShredderAmmo'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemShredderAmmo
{
#pragma GE_Published
    geVec3d			Origin;
	geBoolean   Reaparece;
	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparición transcurridos unos segundos ? True=Si False=No")

	float Tiempo_reaparicion;
	#pragma GE_DefaultValue(Tiempo_reaparicion, "60")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer después de recogido (en segundos)")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")
#pragma GE_Origin(Origin)
}   ItemShredderAmmo;



// ==========================
// Entidad 'FogLight'
// ==========================
#pragma GE_Type("FogLight.ico")
typedef struct FogLight
{
#pragma GE_Published
	geVec3d		Origin;
	GE_RGBA		Color;
	float		Brightness;
	float		Radius;
#pragma GE_Origin(Origin)
} FogLight;



// ==========================
// Entidad 'ItemVida'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemVida
{
#pragma GE_Published
    geVec3d			Origin;
	int	Transparencia;
	int Brillo;
	float	Scale; // Vector de escalado
	int Sombra;
	float Tiempo_reaparicion;
	geBoolean   Reaparece;

	#pragma GE_DefaultValue(Scale, "1")
	#pragma GE_Documentation(Scale, "Tamaño (1=Sin variar  2=El doble  0.5=La mitad)")

	#pragma GE_DefaultValue(Transparencia, "255")
	#pragma GE_Documentation(Transparencia, "Nivel de transparencia (de 0 a 255, 255=Opaco 128=Semitransparente)")

	#pragma GE_DefaultValue(Brillo, "190")
	#pragma GE_Documentation(Brillo, "Nivel de brillo (de 0 a 255)")

	#pragma GE_DefaultValue(Sombra, "1")
	#pragma GE_Documentation(Sombra, "Tipo de sombra. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	#pragma GE_DefaultValue(Tiempo_reaparicion, "300")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer después de recogido (en segundos)")

	#pragma GE_DefaultValue(Reaparece, "False")
	#pragma GE_Documentation(Reaparece, "¿ Reaparece después de ser recogido ? True=Si False=No")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
}   ItemVida;



// ==========================
// Entidad 'CamaraFija'
// ==========================
#pragma GE_Type("Model.ico")
typedef struct CamaraFija
{
	#pragma GE_Published
	geVec3d Origin;

	geBoolean   Activa;
	#pragma GE_DefaultValue(Activa, "False")
	#pragma GE_Documentation(Activa, "¿ Cámara activa al iniciar el juego ? True=Si False=No")

	int Num_camara;
	#pragma GE_DefaultValue(Num_camara, "1")
	#pragma GE_Documentation(Num_camara, "Número de cámara (entre 1 y 64)")
		
	float Tiempo;
	#pragma GE_DefaultValue(Tiempo, "0")
	#pragma GE_Documentation(Tiempo, "Tiempo, en segundos, que estará activa (0 indefinido)")

	geVec3d Angulo;
	#pragma GE_DefaultValue(Angulo, "0 0 0")
	#pragma GE_Documentation(Angulo, "Ángulo de inclinación")

	geBoolean   Apunta_al_jugador;
	#pragma GE_DefaultValue(Apunta_al_jugador, "False")
	#pragma GE_Documentation(Apunta_al_jugador, "¿ Apunta al jugador ? True=Si False=No")

	geWorld_Model *	Model;
	#pragma GE_Documentation(Model, "Modelo asociado a la cámara. (Opcional)")

	Posicion *	Apuntar;
	#pragma GE_Documentation(Apuntar, "Posición hacia donde apunta la cámara. (Opcional)")
	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
} CamaraFija;



// ==========================
// Entidad 'Objetivo'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  Objetivo
{
#pragma GE_Private
    geVec3d			Origin;
#pragma GE_Published
	char *Descripcion;
	#pragma GE_DefaultValue(Descripcion, "Descripción de un objetivo de la misión")
	#pragma GE_Documentation(Descripcion, "Descripción de un objetivo de la misión (50 carac. max.)")

	geBoolean En_panel;
	#pragma GE_DefaultValue(En_panel, "True")
	#pragma GE_Documentation(En_panel, "En el panel de objetivos al comenzar el juego. False=No True=Si")

	int Num_objetivo;	
	#pragma GE_DefaultValue(Num_objetivo, "1")
	#pragma GE_Documentation(Num_objetivo, "Número de objetivo (de 1 a 10)")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
}   Objetivo;



// ==========================
// Entidad 'SunLight'
// Esta estructura ha de ser la misma que haya definida en 'puppet.h' de Genesis3D
// ==========================
#pragma GE_Type("corona.bmp")
typedef struct tagSunLight
{
#pragma GE_Private
	geVec3d	origin;
#pragma GE_Published
	GE_RGBA	color;
	int	light;
	geVec3d	angles;
	int style;

#pragma GE_Origin(origin)

#pragma GE_DefaultValue(color, "251 244 174")
#pragma GE_Documentation(color, "Color de la luz del Sol")

#pragma GE_DefaultValue(light, "2400")
#pragma GE_Documentation(light, "Alcance de la luz del Sol")

#pragma GE_Angles(angles)
#pragma GE_DefaultValue(angles, "0 0 -45")
#pragma GE_Documentation(angles, "Ángulo de incidencia de la luz del Sol")

#pragma GE_DefaultValue(style, "0")
#pragma GE_Documentation(style, "Parpadeo de la luz (0, 1, 2 o 3)")

#pragma GE_Documentation(origin, "Posición (X Y Z)")

} SunLight ;



// ==========================
// Entidad 'TeclaComandos'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  TeclaComandos
{
#pragma GE_Private
    geVec3d			Origin;
#pragma GE_Published
	char *FicheroComandos;
	#pragma GE_DefaultValue(FicheroComandos, "tecla_comandos.ini")
	#pragma GE_Documentation(FicheroComandos, "Nombre del fichero de comandos a lanzar al pulsar la tecla.")

	geBoolean Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Tecla activa al dar comienzo el juego ?. False=No True=Si")

	char *Tecla;
	#pragma GE_DefaultValue(Tecla, "U")
	#pragma GE_Documentation(Tecla, "Tecla que lanzará el fichero de comandos.")

	float Retardo;
	#pragma GE_DefaultValue(Retardo, "0.5")
	#pragma GE_Documentation(Retardo, "Tiempo, en segundos, en permitir volver a usar la tecla.")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
}   TeclaComandos;



// ==========================
// Entidad 'Fx_ArmaEnergia'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  Fx_ArmaEnergia
{
#pragma GE_Private
    geVec3d			Origin;
#pragma GE_Published

	geBoolean Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Arma activa ?. False=No True=Si")

	int Num_ArmaEnergia;
	#pragma GE_DefaultValue(Num_ArmaEnergia, "1")
	#pragma GE_Documentation(Num_ArmaEnergia, "Número de arma de energía (de 1 a 20).")

	char *NombreBMP;
	#pragma GE_DefaultValue(NombreBMP, "espiral")
	#pragma GE_Documentation(NombreBMP, "Nombre de la secuencia .BMPs de la animación (sin extension .BMP)")

	char *NombreBMPa;
	#pragma GE_DefaultValue(NombreBMPa, "espiral")
	#pragma GE_Documentation(NombreBMPa, "Nombre de la secuencia .BMPs (canal Alpha) de la animación (sin extension .BMP)")

	char *NombreWAV;
	#pragma GE_DefaultValue(NombreWAV, "arma_energia.wav")
	#pragma GE_Documentation(NombreWAV, "Nombre de fichero .WAV a interpretar")

	float Retardo;
	#pragma GE_DefaultValue(Retardo, "0.05")
	#pragma GE_Documentation(Retardo, "Tiempo (en segundos) entre cada imagen BMP")

	float Escala;
	#pragma GE_DefaultValue(Escala, "5")
	#pragma GE_Documentation(Escala, "Tamaño del efecto.")

	int Quita_salud;
	#pragma GE_DefaultValue(Quita_salud, "50")
	#pragma GE_Documentation(Quita_salud, "Cantidad de salud a restar a los Bots.")

	float Altura;
	#pragma GE_DefaultValue(Altura, "140")
	#pragma GE_Documentation(Altura, "Altura del efecto.")

	float   Transparencia;
	#pragma GE_DefaultValue(Transparencia, "130")
	#pragma GE_Documentation(Transparencia, "Nivel de transparencia (de 0 a 255). 255 sin transparencia")

	GE_RGBA	Color;
	#pragma GE_DefaultValue(Color, "255.0 255.0 255.0")
	#pragma GE_Documentation(Color, "Color del efecto")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
}   Fx_ArmaEnergia;



// ==========================
// Entidad 'VolarJugador'
// ==========================
#pragma GE_Type("Player.ico")
typedef struct  VolarJugador
{
#pragma GE_Private
    geVec3d			Origin;
#pragma GE_Published
	geBoolean   Descuenta_energia;
	#pragma GE_DefaultValue(Descuenta_energia, "True")
	#pragma GE_Documentation(Descuenta_energia, "¿ Descuenta energía al volar ?. True=Si False=No")

	geBoolean   Inicio_volando;
	#pragma GE_DefaultValue(Inicio_volando, "False")
	#pragma GE_Documentation(Inicio_volando, "¿ Iniciar el nivel volando ?. True=Si False=No")

	geBoolean   Pemitir_OnOff;
	#pragma GE_DefaultValue(Pemitir_OnOff, "True")
	#pragma GE_Documentation(Pemitir_OnOff, "¿ Permitir al jugador activar/desactivar volar ?. True=Si False=No")

	geBoolean   Sonido_volar;
	#pragma GE_DefaultValue(Sonido_volar, "True")
	#pragma GE_Documentation(Sonido_volar, "¿ Sonido de propulsión al volar el jugador ?. False=No True=Si")

	geBoolean   Sonido_volando;
	#pragma GE_DefaultValue(Sonido_volando, "True")
	#pragma GE_Documentation(Sonido_volando, "¿ Sonido mientras vuela el jugador ?. False=No True=Si")

	geVec3d	Posicion_XY;
	#pragma GE_DefaultValue(Posicion_XY, "15 -220 1")
	#pragma GE_Documentation(Posicion_XY, "Posición de la barra de energía en pantalla. (Sólo X Y)")

	float	Retardo;
	#pragma GE_DefaultValue(Retardo, "0.5")
	#pragma GE_Documentation(Retardo, "Velocidad de vaciado de la energía. (En segundos)")

	int	Energia;
	#pragma GE_DefaultValue(Energia, "100")
	#pragma GE_Documentation(Energia, "Energia inicial de la barra de energía (de 0 a 100 )")

	char *Comandos_Vacia;
	#pragma GE_DefaultValue(Comandos_Vacia, "")
	#pragma GE_Documentation(Comandos_Vacia, "Nombre del fichero de comandos a lanzar cuando se acabe la energía")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
}   VolarJugador;



// ==========================
// Entidad 'Teletransporte'
// ==========================
#pragma GE_Type("Model.ico")
typedef struct Teletransporte
{
#pragma GE_Private

	char		*Ptr;

#pragma GE_Published
	geVec3d Origin;

	char *CommandsFile;
	#pragma GE_DefaultValue(CommandsFile, "")
	#pragma GE_Documentation(CommandsFile, "Fichero de comandos de Jugador (sin extensión .INI)")

	char *CommandsFileBot;
	#pragma GE_DefaultValue(CommandsFileBot, "")
	#pragma GE_Documentation(CommandsFileBot, "Fichero de comandos de Bot (sin extensión .INI)")

	geBoolean   Boton_accion;
	#pragma GE_DefaultValue(Boton_accion, "False")
	#pragma GE_Documentation(Boton_accion, "¿ Activación si botón/tecla acción pulsada ? True=Si False=No")
	
	geBoolean   Visible;
	#pragma GE_DefaultValue(Visible, "True")
	#pragma GE_Documentation(Visible, "Mostrar una plataforma como referencia de la posición. True=Si False=No")
	
	geVec3d Zona_influencia;
	#pragma GE_DefaultValue(Zona_influencia, "40 20 40")
	#pragma GE_Documentation(Zona_influencia, "Zona de influencia de esta entidad (Y es en vertical)")

	geBoolean	Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Entidad activa al iniciar el juego ? True=Si False=No")

	geBoolean	Reaparece;
	#pragma GE_DefaultValue(Reaparece, "True")
	#pragma GE_Documentation(Reaparece, "¿ Reaparece ? True=Si False=No")

	float Tiempo_reaparicion;
	#pragma GE_DefaultValue(Tiempo_reaparicion, "0.2")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer (en segundos)")

	geVec3d Posicion_destino;
	#pragma GE_DefaultValue(Posicion_destino, "0 0 0")
	#pragma GE_Documentation(Posicion_destino, "Posición destino del Jugador o Bot (X Y Z)")

	geBoolean Destino_absoluto;
	#pragma GE_DefaultValue(Destino_absoluto, "True")
	#pragma GE_Documentation(Destino_absoluto, "Posición destino absoluta o relativa a la posición actual del juegador. True=Absoluta False=Relativa")

	geBoolean VisualFx;
	#pragma GE_DefaultValue(VisualFx, "True")
	#pragma GE_Documentation(VisualFx, "Mostrar efecto visual y sonoro al teletransportar. True=Si False=No")

	geBoolean Usar_por_Jugador;
	#pragma GE_DefaultValue(Usar_por_Jugador, "True")
	#pragma GE_Documentation(Usar_por_Jugador, "Los Jugadores pueden usar el teletransporte. True=Si False=No")

	geBoolean Usar_por_Bot;
	#pragma GE_DefaultValue(Usar_por_Bot, "False")
	#pragma GE_Documentation(Usar_por_Bot, "Los Bots pueden usar el teletransporte. True=Si False=No")

	geBoolean Ver_zona_influencia;
	#pragma GE_DefaultValue(Ver_zona_influencia, "False")
	#pragma GE_Documentation(Ver_zona_influencia, "Ver zona de influencia de esta entidad. True=Si False=No")

	geBoolean Boton_Accion_indicador;
	#pragma GE_DefaultValue(Boton_Accion_indicador, "True")
	#pragma GE_Documentation(Boton_Accion_indicador, "Mostrar indicador de tecla 'Acción'.'Boton_accion' debe estar a 'True'")

	geBoolean Repetir_comandos_zona;
	#pragma GE_DefaultValue(Repetir_comandos_zona, "True")
	#pragma GE_Documentation(Repetir_comandos_zona, "Procesar 'CommandsFile' mientras el jugador siga en la zona de influencia")

	#pragma GE_Documentation(Origin, "Posición entidad (X Y Z)")

#pragma GE_Origin(Origin)
} Teletransporte;



// ==========================
// Entidad 'ItemColision' (Deshabilitada)
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ItemColision
{
#pragma GE_Private
    geVec3d			Origin;
#pragma GE_Published
	int	Transparencia;
	int Brillo;
	float	Scale;
	int Sombra;
	float Tiempo_reaparicion;
	geBoolean   Reaparece;

	#pragma GE_DefaultValue(Scale, "1")
	#pragma GE_Documentation(Scale, "Tamaño (1=Sin variar  2=El doble  0.5=La mitad)")

	#pragma GE_DefaultValue(Transparencia, "255")
	#pragma GE_Documentation(Transparencia, "Nivel de transparencia (de 0 a 255, 255=Opaco 128=Semitransparente)")

	#pragma GE_DefaultValue(Brillo, "190")
	#pragma GE_Documentation(Brillo, "Nivel de brillo (de 0 a 255)")

	#pragma GE_DefaultValue(Sombra, "1")
	#pragma GE_Documentation(Sombra, "Tipo de sombra. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	#pragma GE_DefaultValue(Tiempo_reaparicion, "300")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo en reaparecer después de recogido (en segundos)")

	#pragma GE_DefaultValue(Reaparece, "False")
	#pragma GE_Documentation(Reaparece, "¿ Reaparece después de ser recogido ? True=Si False=No")

	#pragma GE_Documentation(Origin, "Posición (X Y Z)")

#pragma GE_Origin(Origin)
}   ItemColision;




#ifdef __cplusplus
}
#endif

#pragma warning( default : 4068 )

#endif
