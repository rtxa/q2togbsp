/****************************************************************************************/
/*  Copyright (c) 1999 WildTangent, Inc.; All rights reserved.                          */
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
/*  Copyright (c) 2004 - 2015 Jordi Pérez; All rights reserved.                         */
/*                                                                                      */
/****************************************************************************************/

#ifndef	BOTACTOR_H
#define	BOTACTOR_H

#include	"genesis.h"

#pragma warning( disable : 4068 )


// ==========================
// Entidad 'Posicion'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  Posicion
{
#pragma GE_Published
    geVec3d			Origin;
	#pragma GE_Documentation(Origin, "Posición X Y Z")

	int Num_posicion;
	#pragma GE_DefaultValue(Num_posicion, "1")
	#pragma GE_Documentation(Num_posicion, "Número de posición. (Entre 1 y 255)")

#pragma GE_Origin(Origin)
}   Posicion;



// ==========================
// Entidad 'BotActorStart'
// ==========================
#pragma GE_Type("BotActor.bmp")
typedef struct BotActorStart BotActorStart;

#pragma GE_Type("BotActor.bmp")
typedef struct BotActorStart {
#pragma GE_Published

	geVec3d		origin;
	geBoolean   Respawn;
	geBoolean	Retreat;
	geBoolean   IgnoreTurrets;
	int			SkillLevel;
	int			EnemyNumber;
	geBoolean   WeaponShredder;
	geBoolean   WeaponGrenades;
	geBoolean   WeaponRockets;
	geBoolean   WeaponBlaster;
	int			WeaponShredderA;
	int			WeaponGrenadesA;
	int			WeaponRocketsA;
	int			WeaponBlasterA;
	int			HealthLevel;
	char		*CommandsFile;
	geBoolean   Static_Bot;
	geBoolean   Se_detiene;
	float		Tiempo_reaparicion;
	float		Velocidad;
	int			Quita_salud;
	geBoolean   Dispara;
	geBoolean	Inicio_parado;
	float		Tiempo_corriendo;
	geBoolean	Cobarde;
	geBoolean	Abalanzarse;
	geBoolean   Masculino;
	geBoolean	Sangre;
	float		Tiempo_sonido;
	geBoolean	Indiferente;
	geBoolean	Buscar;
	float		DistanciaMin;
	int			BuscarPorc;
	int			CobardePorc;
	int			IndiferentePorc;
	geBoolean	AnimacionTipo;
	geBoolean	Bloqueo;
	char		*Comandos_colision;
	float		Scale;
    Posicion *	Destino1;
    Posicion *	Destino2;
    Posicion *	Destino3;
    Posicion *	Destino4;
    Posicion *	Destino5;
	int			Inmune;
	geBoolean   Mov_lateral_azar;
	geBoolean   Dispara1_parado;
	geBoolean   Dispara2_parado;
	geBoolean   Dispara3_parado;
	geBoolean   Dispara4_parado;
	float		Distancia1_disparar;
	float		Distancia2_disparar;
	float		Distancia3_disparar;
	float		Distancia4_disparar;
	int			InmuneEnergia;
	geBoolean	ExplosionMorir;
	float		Min_zona_critica;
	float		Max_zona_critica;
	char		*Comandos_impacto;
	geBoolean	Pierde_salud;
	float		Salto_Morir;
	geBoolean	InmuneLava;
	float		Tiempo_Recuperarse;
	char		*Anim_nadar;
	geBoolean	Se_hunde_en_agua;
	float		Altura_subir_bloque;
	float		Altura_bajar_bloque;
	int			Nivel_armadura;
	int			Vidas;
	geBoolean	Buscar_salud;
	geBoolean	Buscar_municion;
	geBoolean	Recargar_armas;
	geBoolean	HUD_salud;
	int			Ver_en_radar;
	geBoolean	Colision_con_jugador;
	float		Distancia_colision_jugador;
	geBoolean	Esquivar_balas;
	geBoolean	Mov_recta_jugador;
	int			Equipo_aliado;

	#pragma GE_Documentation(origin, "Posición X Y Z")

	#pragma GE_DefaultValue(CommandsFile, "")
	#pragma GE_Documentation(CommandsFile, "Fichero .INI de comandos para procesar cuando muere el Bot")

	#pragma GE_DefaultValue(SkillLevel, "5")
	#pragma GE_Documentation(SkillLevel, "Nivel de dificultad. De 1 a 10. El 1 es el más difícil.")

	#pragma GE_DefaultValue(Respawn, "False")
	#pragma GE_Documentation(Respawn, "Reaparición del Bot después de muerto. True=Si False=No")

	#pragma GE_DefaultValue(Retreat, "False")
	#pragma GE_Documentation(Retreat, "<sin función>")

	#pragma GE_DefaultValue(IgnoreTurrets, "True")
	#pragma GE_Documentation(IgnoreTurrets, "<sin función>")

	#pragma GE_DefaultValue(EnemyNumber, "0")
	#pragma GE_Documentation(EnemyNumber, "Número de Bot a mostrar. De 0 a 8. 0=Al azar entre 1 y 6, 1 a 8=Bot específico.")

	#pragma GE_DefaultValue(WeaponBlaster, "True")
	#pragma GE_Documentation(WeaponBlaster, "Arma 1 (Blaster) en el inventario.")

	#pragma GE_DefaultValue(WeaponBlasterA, "255")
	#pragma GE_Documentation(WeaponBlasterA, "Cantidad de munición inicial para el Blaster.")

	#pragma GE_DefaultValue(WeaponShredder, "False")
	#pragma GE_Documentation(WeaponShredder, "Arma 4 (Fusil) en el inventario.")

	#pragma GE_DefaultValue(WeaponShredderA, "50")
	#pragma GE_Documentation(WeaponShredderA, "Cantidad de munición inicial para el Fusil.")

	#pragma GE_DefaultValue(WeaponGrenades, "False")
	#pragma GE_Documentation(WeaponGrenades, "Arma 2 (Lanza-granadas) en el inventario.")

	#pragma GE_DefaultValue(WeaponGrenadesA, "20")
	#pragma GE_Documentation(WeaponGrenadesA, "Cantidad de munición inicial para el Lanza-granadas.")

	#pragma GE_DefaultValue(WeaponRockets, "False")
	#pragma GE_Documentation(WeaponRockets, "Arma 3 (Lanza-cohetes) en el inventario.")

	#pragma GE_DefaultValue(WeaponRocketsA, "15")
	#pragma GE_Documentation(WeaponRocketsA, "Cantidad de munición inicial para el Lanza-cohetes.")

	#pragma GE_DefaultValue(HealthLevel, "50")
	#pragma GE_Documentation(HealthLevel, "Salud inicial. De 1 a 100.")

	#pragma GE_DefaultValue(Static_Bot, "False")
	#pragma GE_Documentation(Static_Bot, "Bot estático. (False=No True=Si)")

	#pragma GE_DefaultValue(Se_detiene, "False")
	#pragma GE_Documentation(Se_detiene, "El Bot, en ocasiones, se detiene. (False=No True=Si)")

	#pragma GE_DefaultValue(Tiempo_reaparicion, "120")
	#pragma GE_Documentation(Tiempo_reaparicion, "Tiempo (en segundos) en reaparecer después de muerto.")

	#pragma GE_DefaultValue(Velocidad, "3700")
	#pragma GE_Documentation(Velocidad, "Velocidad del Bot. Mayor valor es mayor velocidad.")

	#pragma GE_DefaultValue(Quita_salud, "5")
	#pragma GE_Documentation(Quita_salud, "Salud a restar al jugador si colisiona con este Bot.")

	#pragma GE_DefaultValue(Dispara, "True")
	#pragma GE_Documentation(Dispara, "Bot dispara. True=Si False=No")

	#pragma GE_DefaultValue(Inicio_parado, "True")
	#pragma GE_Documentation(Inicio_parado, "Al comenzar, Bot parado si no ve al jugador. True=Si False=No")

	#pragma GE_DefaultValue(Tiempo_corriendo, "20")
	#pragma GE_Documentation(Tiempo_corriendo, "Tiempo (en segundos) corriendo cuando no ve al jugador.")

	#pragma GE_DefaultValue(Cobarde, "False")
	#pragma GE_Documentation(Cobarde, "El Bot huye del jugador y no dispara. True=Si False=No")

	#pragma GE_DefaultValue(CobardePorc, "0")
	#pragma GE_Documentation(CobardePorc, "Porcentaje de tiempo cobarde (0 - 100)(0 no usar porcentaje)")

	#pragma GE_DefaultValue(Abalanzarse, "False")
	#pragma GE_Documentation(Abalanzarse, "Se abalanza hacia el jugador. True=Si False=No")

	#pragma GE_DefaultValue(Masculino, "True")
	#pragma GE_Documentation(Masculino, "¿ El Bot es del sexo masculino ?. True=Masculino  False=Femenino")

	#pragma GE_DefaultValue(Sangre, "True")
	#pragma GE_Documentation(Sangre, "Aparece sangre en impactos por armas 1 y 4. True=Si False=No")

	#pragma GE_DefaultValue(Tiempo_sonido, "0")
	#pragma GE_Documentation(Tiempo_sonido, "Intérvalo de tiempo para interpretar el sonido de este Bot.")

	#pragma GE_DefaultValue(Indiferente, "False")
	#pragma GE_Documentation(Indiferente, "Se mantiene próximo al jugador dando vueltas. True=Si False=No")

	#pragma GE_DefaultValue(IndiferentePorc, "0")
	#pragma GE_Documentation(IndiferentePorc, "Porcentaje de tiempo indiferente (0 - 100)(0 no usar porcentaje)")

	#pragma GE_DefaultValue(Buscar, "True")
	#pragma GE_Documentation(Buscar, "Busca al jugador esquivando obstáculos. True=Si False=No")

	#pragma GE_DefaultValue(BuscarPorc, "0")
	#pragma GE_Documentation(BuscarPorc, "Porcentaje de tiempo buscando al jugador (0 - 100)(0 no usar porcentaje)")

	#pragma GE_DefaultValue(DistanciaMin, "400")
	#pragma GE_Documentation(DistanciaMin, "Distancia mínima entre Bot y jugador. (entre 50 y 5000)")

	#pragma GE_DefaultValue(AnimacionTipo, "False")
	#pragma GE_Documentation(AnimacionTipo, "Animación al desplazarse. (False=Correr(Run) True=Andar(Walk))")

	#pragma GE_DefaultValue(Bloqueo, "True")
	#pragma GE_Documentation(Bloqueo, "¿ Impide avanzar al jugador si hay colisión ? True=Si False=No")

	#pragma GE_DefaultValue(Comandos_colision, "")
	#pragma GE_Documentation(Comandos_colision, "Fichero .INI de comandos para procesar al colisionar con el jugador.")

	#pragma GE_DefaultValue(Scale, "2.7")
	#pragma GE_Documentation(Scale, "Tamaño (2.7=Normal  5.4=El doble  1.3=La mitad)")

	#pragma GE_Documentation(Destino1, "Destino 1 de la ruta")
	#pragma GE_Documentation(Destino2, "Destino 2 de la ruta")
	#pragma GE_Documentation(Destino3, "Destino 3 de la ruta")
	#pragma GE_Documentation(Destino4, "Destino 4 de la ruta")
	#pragma GE_Documentation(Destino5, "Destino 5 de la ruta")

	#pragma GE_DefaultValue(Inmune, "0")
	#pragma GE_Documentation(Inmune, "Inmunidad. 0=No inmune. 1 a 4 inmune a ese nivel de arma.")

	#pragma GE_DefaultValue(Mov_lateral_azar, "False")
	#pragma GE_Documentation(Mov_lateral_azar, "Movimientos laterales aleatorios. True=Si False=No")

	#pragma GE_DefaultValue(Dispara1_parado, "False")
	#pragma GE_Documentation(Dispara1_parado, "Siempre dispara el arma 1 parado. True=Si False=No")

	#pragma GE_DefaultValue(Dispara2_parado, "False")
	#pragma GE_Documentation(Dispara2_parado, "Siempre dispara el arma 2 parado. True=Si False=No")

	#pragma GE_DefaultValue(Dispara3_parado, "False")
	#pragma GE_Documentation(Dispara3_parado, "Siempre dispara el arma 3 parado. True=Si False=No")

	#pragma GE_DefaultValue(Dispara4_parado, "False")
	#pragma GE_Documentation(Dispara4_parado, "Siempre dispara o ataca con el arma 4 parado. True=Si False=No")

	#pragma GE_DefaultValue(Distancia1_disparar, "5000")
	#pragma GE_Documentation(Distancia1_disparar, "Distancia mínima hasta el jugador para usar arma 1 (50 a 10000)")

	#pragma GE_DefaultValue(Distancia2_disparar, "1000")
	#pragma GE_Documentation(Distancia2_disparar, "Distancia mínima hasta el jugador para usar arma 2 (50 a 10000)")

	#pragma GE_DefaultValue(Distancia3_disparar, "3000")
	#pragma GE_Documentation(Distancia3_disparar, "Distancia mínima hasta el jugador para usar arma 3 (50 a 10000)")

	#pragma GE_DefaultValue(Distancia4_disparar, "10000")
	#pragma GE_Documentation(Distancia4_disparar, "Distancia mínima hasta el jugador para usar arma 4 (50 a 10000)")

	#pragma GE_DefaultValue(InmuneEnergia, "0")
	#pragma GE_Documentation(InmuneEnergia, "Inmunidad a armas de energía. -1=A todas, 0=A ninguna, Arma 1 a 20 que le daña")

	#pragma GE_DefaultValue(ExplosionMorir, "False")
	#pragma GE_Documentation(ExplosionMorir, "Explosión del Bot al morir. True=Si False=No")

	#pragma GE_DefaultValue(Min_zona_critica, "0")
	#pragma GE_Documentation(Min_zona_critica, "Inicio, en %, de la zona crítica mínima del Bot (de 0 a 100) 0 sin zona ")

	#pragma GE_DefaultValue(Max_zona_critica, "0")
	#pragma GE_Documentation(Max_zona_critica, "Inicio, en %, de la zona crítica máxima del Bot (de 0 a 100) 0 sin zona")

	#pragma GE_DefaultValue(Comandos_impacto, "")
	#pragma GE_Documentation(Comandos_impacto, "Fichero .INI de comandos para procesar al recibir impacto.")

	#pragma GE_DefaultValue(Pierde_salud, "True")
	#pragma GE_Documentation(Pierde_salud, "Pierde salud cuando sufre daño. True=Si False=No")

	#pragma GE_DefaultValue(Salto_Morir, "0")
	#pragma GE_Documentation(Salto_Morir, "Altura del salto al morir (de 0 a 2000)")

	#pragma GE_DefaultValue(InmuneLava, "False")
	#pragma GE_Documentation(InmuneLava, "Inmunidad a los bloques de lava. True=Si False=No")

	#pragma GE_DefaultValue(Tiempo_Recuperarse, "0")
	#pragma GE_Documentation(Tiempo_Recuperarse, "Tiempo en recuperarse parado después de recibir un disparo (en segundos) 0 no se para")

	#pragma GE_DefaultValue(Anim_nadar, "")
	#pragma GE_Documentation(Anim_nadar, "Nombre de animación del Bot nadando. Normalmente 'Swim'")

	#pragma GE_DefaultValue(Se_hunde_en_agua, "True")
	#pragma GE_Documentation(Se_hunde_en_agua, "Bot se hunde en el agua. True=Si False=No")

	#pragma GE_DefaultValue(Altura_subir_bloque, "48")
	#pragma GE_Documentation(Altura_subir_bloque, "Altura máxima del bloque que puede subir.")

	#pragma GE_DefaultValue(Altura_bajar_bloque, "100")
	#pragma GE_Documentation(Altura_bajar_bloque, "Altura máxima del bloque que puede bajar.")

	#pragma GE_DefaultValue(Nivel_armadura, "0")
	#pragma GE_Documentation(Nivel_armadura, "Armadura inicial. De 0 a 100.")

	#pragma GE_DefaultValue(Vidas, "0")
	#pragma GE_Documentation(Vidas, "Número de vidas de este Bot (0 = Infinitas)")

	#pragma GE_DefaultValue(Buscar_salud, "False")
	#pragma GE_Documentation(Buscar_salud, "Busca items de salud y armadura. True=Si False=No")

	#pragma GE_DefaultValue(Buscar_municion, "False")
	#pragma GE_Documentation(Buscar_municion, "Busca items de munición. True=Si False=No")

	#pragma GE_DefaultValue(Recargar_armas, "True")
	#pragma GE_Documentation(Recargar_armas, "Recargar armas al reaparecer después de morir. True=Si False=No")

	#pragma GE_DefaultValue(HUD_salud, "False")
	#pragma GE_Documentation(HUD_salud, "Mostrar indicador de salud del Bot. True=Si False=No")

	#pragma GE_DefaultValue(Ver_en_radar, "1")
	#pragma GE_Documentation(Ver_en_radar, "Bot se muestra en el radar. 0=No, 1=Si en rango, 2=Si en borde")

	#pragma GE_DefaultValue(Colision_con_jugador, "False")
	#pragma GE_Documentation(Colision_con_jugador, "¿ Detectar colisión con jugador ? True=Si False=No")

	#pragma GE_DefaultValue(Distancia_colision_jugador, "75")
	#pragma GE_Documentation(Distancia_colision_jugador, "Distancia para considerarse colisión con jugador")

	#pragma GE_DefaultValue(Esquivar_balas, "False")
	#pragma GE_Documentation(Esquivar_balas, "Bot intenta esquivar las balas del jugador. True=Si False=No")

	#pragma GE_DefaultValue(Mov_recta_jugador, "True")
	#pragma GE_Documentation(Mov_recta_jugador, "Bot intenta dirigirse en línea recta hacia el jugador. True=Si False=No")

	#pragma GE_DefaultValue(Equipo_aliado, "0")
	#pragma GE_Documentation(Equipo_aliado, "Bot ignora jugadores de este equipo online (0 a 8)")

#pragma GE_Private

	char		*Ptr;

#pragma GE_Origin(origin)
} BotActorStart;



// ==========================
// Entidad 'BlockActor'
// ==========================
#pragma GE_Type("BlockActor.bmp")
typedef struct BlockActor BlockActor;

#pragma GE_Type("BlockActor.bmp")
typedef struct BlockActor {
#pragma GE_Published

geVec3d		Origin;
geWorld_Model *Model;

#pragma GE_Documentation(Model, "Blocking Model - Actors will not move into this model.")

#pragma GE_Origin(Origin)
} BlockActor;

#pragma warning( default : 4068 )

#endif
