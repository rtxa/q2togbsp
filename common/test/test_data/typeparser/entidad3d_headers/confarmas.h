/****************************************************************************************/
/*  File: confarmas.h                                                                   */
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

#ifndef CONFARMAS_H
#define CONFARMAS_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Genesis.h"

#pragma warning( disable : 4068 )



// ==========================
// Entidad 'ConfigArmaUno'
// ==========================
// Configuración del arma número 1 (Blaster)
#pragma GE_Type("Item.ico")
typedef struct  ConfigArmaUno
{
#pragma GE_Published
	#pragma GE_Private
	geVec3d		Origin;
	#pragma GE_Published

	float	Velocidad;
	#pragma GE_DefaultValue(Velocidad, "5600")
	#pragma GE_Documentation(Velocidad, "Velocidad del proyectil. (De 600 a 50000)")

	char *Arma_ACT;
	#pragma GE_DefaultValue(Arma_ACT, "blaster.act")
	#pragma GE_Documentation(Arma_ACT, "Nombre del fichero .ACT que representa la arma.")

	char *Sonido_Disp_WAV;
	#pragma GE_DefaultValue(Sonido_Disp_WAV, "blaster_disp.wav")
	#pragma GE_Documentation(Sonido_Disp_WAV, "Nombre del fichero de sonido .WAV del disparo.")

	char *Sonido_Impa_WAV;
	#pragma GE_DefaultValue(Sonido_Impa_WAV, "blaster_exp.wav")
	#pragma GE_Documentation(Sonido_Impa_WAV, "Nombre del fichero de sonido .WAV del impacto del proyectil.")

	geVec3d	Orientacion_1;
	#pragma GE_DefaultValue(Orientacion_1, "180 -90 -180")
	#pragma GE_Documentation(Orientacion_1, "Orientación del arma en primera persona.")

	geVec3d	Orientacion_3;
	#pragma GE_DefaultValue(Orientacion_3, "90 -15 5")
	#pragma GE_Documentation(Orientacion_3, "Orientación del arma en tercera persona.")

	float	Orient_Punto_Mira;
	#pragma GE_DefaultValue(Orient_Punto_Mira, "5")
	#pragma GE_Documentation(Orient_Punto_Mira, "Orientación hacia el punto de mira en primera persona")

	geVec3d	Posicion_arma_1;
	#pragma GE_DefaultValue(Posicion_arma_1, "0 0 0")
	#pragma GE_Documentation(Posicion_arma_1, "Posición del arma en primera persona.")

	geVec3d	Posicion_arma_3;
	#pragma GE_DefaultValue(Posicion_arma_3, "0 -10 -33")
	#pragma GE_Documentation(Posicion_arma_3, "Posición del arma en tercera persona.")

	geVec3d	Posicion_disparo_1;
	#pragma GE_DefaultValue(Posicion_disparo_1, "40 -10 -8")
	#pragma GE_Documentation(Posicion_disparo_1, "Posición salida del disparo en primera persona.")

	geVec3d	Posicion_disparo_3;
	#pragma GE_DefaultValue(Posicion_disparo_3, "100 10 -20")
	#pragma GE_Documentation(Posicion_disparo_3, "Posición salida del disparo en tercera persona.")

	geVec3d	Posicion_fogonazo_1;
	#pragma GE_DefaultValue(Posicion_fogonazo_1, "40 -10 -8")
	#pragma GE_Documentation(Posicion_fogonazo_1, "Posición del fogonazo del disparo en primera persona.")

	geVec3d	Posicion_fogonazo_3;
	#pragma GE_DefaultValue(Posicion_fogonazo_3, "100 10 -20")
	#pragma GE_Documentation(Posicion_fogonazo_3, "Posición del fogonazo del disparo en tercera persona.")

	float	Escala_1;
	#pragma GE_DefaultValue(Escala_1, "15")
	#pragma GE_Documentation(Escala_1, "Escala del arma en primera persona.")

	float	Escala_3;
	#pragma GE_DefaultValue(Escala_3, "85")
	#pragma GE_Documentation(Escala_3, "Escala del arma en tercera persona.")

	float	Escala_fogonazo_1;
	#pragma GE_DefaultValue(Escala_fogonazo_1, "0")
	#pragma GE_Documentation(Escala_fogonazo_1, "Tamaño del fogonazo en primera persona.")

	float	Escala_fogonazo_3;
	#pragma GE_DefaultValue(Escala_fogonazo_3, "0")
	#pragma GE_Documentation(Escala_fogonazo_3, "Tamaño del fogonazo en tercera persona.")

	char *Fogonazo_BMP;
	#pragma GE_DefaultValue(Fogonazo_BMP, "fogonazo01.bmp")
	#pragma GE_Documentation(Fogonazo_BMP, "Nombre del fichero .BMP que representa el fogonazo.")

	char *Fogonazo_aBMP;
	#pragma GE_DefaultValue(Fogonazo_aBMP, "a_fogonazo01.bmp")
	#pragma GE_Documentation(Fogonazo_aBMP, "Nombre del fichero .BMP (con canal Alpha) para el fogonazo.")

	GE_RGBA	Luz_color;
	#pragma GE_DefaultValue(Luz_color, "255 55 15")
	#pragma GE_Documentation(Luz_color, "Color de la luz que acompaña al proyectil.")

	float	Luz_escala;
	#pragma GE_DefaultValue(Luz_escala, "320")
	#pragma GE_Documentation(Luz_escala, "Tamaño de la luz que acompaña al proyectil.")

	geBoolean	Particulas;
	#pragma GE_DefaultValue(Particulas, "True")
	#pragma GE_Documentation(Particulas, "Partículas acompañan al proyectil. False=No True=Si")

	geBoolean	Humo;
	#pragma GE_DefaultValue(Humo, "False")
	#pragma GE_Documentation(Humo, "Humo acompaña al proyectil. False=No True=Si")

	float	Escala_proyectil;
	#pragma GE_DefaultValue(Escala_proyectil, "2.5")
	#pragma GE_Documentation(Escala_proyectil, "Tamaño del proyectil.")

	char *Proyectil_BMP;
	#pragma GE_DefaultValue(Proyectil_BMP, "Spot_red.bmp")
	#pragma GE_Documentation(Proyectil_BMP, "Nombre del fichero .BMP que representa el proyectil.")

	char *Proyectil_aBMP;
	#pragma GE_DefaultValue(Proyectil_aBMP, "A_spot.bmp")
	#pragma GE_Documentation(Proyectil_aBMP, "Nombre del fichero .BMP (con canal Alpha) que representa el proyectil.")

	char *Particulas_BMP;
	#pragma GE_DefaultValue(Particulas_BMP, "Parti")
	#pragma GE_Documentation(Particulas_BMP, "Nombre de la secuencia de ficheros .BMP que representan las partículas.")

	geBoolean	Config_activa;
	#pragma GE_DefaultValue(Config_activa, "True")
	#pragma GE_Documentation(Config_activa, "Activar esta configuración para esta arma. False=No True=Si")

	float	Cadencia;
	#pragma GE_DefaultValue(Cadencia, "5")
	#pragma GE_Documentation(Cadencia, "Disparos por segundo (del 1 al 10). A más valor, más disparos.")

	float	Salud_resta;
	#pragma GE_DefaultValue(Salud_resta, "15")
	#pragma GE_Documentation(Salud_resta, "Salud que resta a jugador o enemigos por impacto directo (de 0 a 255)")

	float	Salud_resta_critica;
	#pragma GE_DefaultValue(Salud_resta_critica, "255")
	#pragma GE_Documentation(Salud_resta_critica, "Salud que resta al enemigo por impacto en zona crítica (de 0 a 255)")

	geBoolean	Primera_persona;
	#pragma GE_DefaultValue(Primera_persona, "False")
	#pragma GE_Documentation(Primera_persona, "¿ Arma sólo para vista en primera persona ?. False=No True=Si")

	char *AnimDisparo;
	#pragma GE_DefaultValue(AnimDisparo, "sin_animacion")
	#pragma GE_Documentation(AnimDisparo, "Nombre de la animación del disparo o ataque en primera persona ('Shoot')")

	float AnimDispVel;
	#pragma GE_DefaultValue(AnimDispVel, "1")
	#pragma GE_Documentation(AnimDispVel, "Velocidad de la animación del disparo. 0.5=lenta 1=normal 2=rápida, etc.")

	char *AnimNDisparo;
	#pragma GE_DefaultValue(AnimNDisparo, "sin_animacion")
	#pragma GE_Documentation(AnimNDisparo, "Nombre de la animación sin disparar en primera persona ('Idle'")

	float AnimNDispVel;
	#pragma GE_DefaultValue(AnimNDispVel, "1")
	#pragma GE_Documentation(AnimNDispVel, "Velocidad de la animación sin disparar. 0.5=lenta 1=normal 2=rápida, etc.")

	float	Municion_resta;
	#pragma GE_DefaultValue(Municion_resta, "1")
	#pragma GE_Documentation(Municion_resta, "Cantidad de munición a restar en cada disparo.")

	float	Municion_cargador;
	#pragma GE_DefaultValue(Municion_cargador, "20")
	#pragma GE_Documentation(Municion_cargador, "Cantidad de munición en cada cargador.")

	float	Municion_inicial;
	#pragma GE_DefaultValue(Municion_inicial, "40")
	#pragma GE_Documentation(Municion_inicial, "Cantidad de munición inicial en el arma.")

	GE_RGBA	Luz_fogonazo;
	#pragma GE_DefaultValue(Luz_fogonazo, "213 219 38")
	#pragma GE_Documentation(Luz_fogonazo, "Color de la luz del fogonazo.")

	float	Bot_punteria_movil;
	#pragma GE_DefaultValue(Bot_punteria_movil, "1.6")
	#pragma GE_Documentation(Bot_punteria_movil, "Puntería de Bot sobre objetivo móvil (de -20.0 a 20.0)")

	float	Posicion_disparo_1_alt_online;
	#pragma GE_DefaultValue(Posicion_disparo_1_alt_online, "65")
	#pragma GE_Documentation(Posicion_disparo_1_alt_online, "Ajuste de la altura establecida en 'Posicion_disparo_1' (Online)")

	float	Posicion_mira_3_alt;
	#pragma GE_DefaultValue(Posicion_mira_3_alt, "40")
	#pragma GE_Documentation(Posicion_mira_3_alt, "Altura del punto de mira en tercera persona (Online Cli)")

	float	Posicion_mira_3_ang;
	#pragma GE_DefaultValue(Posicion_mira_3_ang, "20")
	#pragma GE_Documentation(Posicion_mira_3_ang, "Ajuste 'Posicion_mira_3_alt' según ángulo de la cámara (Online Cli)")

#pragma GE_Origin(Origin)
}   ConfigArmaUno;



// ==========================
// Entidad 'ConfigArmaDos'
// ==========================
// Configuración del arma número 2 (Lanza-granadas)
#pragma GE_Type("Item.ico")
typedef struct  ConfigArmaDos
{
#pragma GE_Published
	#pragma GE_Private
	geVec3d		Origin;
	#pragma GE_Published

	float	Velocidad;
	#pragma GE_DefaultValue(Velocidad, "1100")
	#pragma GE_Documentation(Velocidad, "Velocidad del proyectil. (De 100 a 10000)")

	char *Arma_ACT;
	#pragma GE_DefaultValue(Arma_ACT, "glaunch.act")
	#pragma GE_Documentation(Arma_ACT, "Nombre del fichero .ACT que representa la arma.")

	char *Proyectil_ACT;
	#pragma GE_DefaultValue(Proyectil_ACT, "grenade.act")
	#pragma GE_Documentation(Proyectil_ACT, "Nombre del fichero .ACT que representa el proyectil.")

	char *Sonido_Disp_WAV;
	#pragma GE_DefaultValue(Sonido_Disp_WAV, "granada_disp.wav")
	#pragma GE_Documentation(Sonido_Disp_WAV, "Nombre del fichero de sonido .WAV del disparo.")

	char *Sonido_Impa_WAV;
	#pragma GE_DefaultValue(Sonido_Impa_WAV, "granada_exp.wav")
	#pragma GE_Documentation(Sonido_Impa_WAV, "Nombre del fichero de sonido .WAV del impacto del proyectil.")

	geVec3d	Orientacion_1;
	#pragma GE_DefaultValue(Orientacion_1, "0 0 0")
	#pragma GE_Documentation(Orientacion_1, "Orientación del arma en primera persona.")

	geVec3d	Orientacion_3;
	#pragma GE_DefaultValue(Orientacion_3, "90 -15 -85")
	#pragma GE_Documentation(Orientacion_3, "Orientación del arma en tercera persona.")

	float	Orient_Punto_Mira;
	#pragma GE_DefaultValue(Orient_Punto_Mira, "5")
	#pragma GE_Documentation(Orient_Punto_Mira, "Orientación hacia el punto de mira en primera persona")

	geVec3d	Posicion_arma_1;
	#pragma GE_DefaultValue(Posicion_arma_1, "0 0 0")
	#pragma GE_Documentation(Posicion_arma_1, "Posición del arma en primera persona.")

	geVec3d	Posicion_arma_3;
	#pragma GE_DefaultValue(Posicion_arma_3, "30 -10 0")
	#pragma GE_Documentation(Posicion_arma_3, "Posición del arma en tercera persona.")

	geVec3d	Posicion_disparo_1;
	#pragma GE_DefaultValue(Posicion_disparo_1, "32 -15 -10")
	#pragma GE_Documentation(Posicion_disparo_1, "Posición salida del disparo en primera persona.")

	geVec3d	Posicion_disparo_3;
	#pragma GE_DefaultValue(Posicion_disparo_3, "80 10 -22")
	#pragma GE_Documentation(Posicion_disparo_3, "Posición salida del disparo en tercera persona.")

	float	Escala_1;
	#pragma GE_DefaultValue(Escala_1, "15")
	#pragma GE_Documentation(Escala_1, "Escala del arma en primera persona.")

	float	Escala_3;
	#pragma GE_DefaultValue(Escala_3, "85")
	#pragma GE_Documentation(Escala_3, "Escala del arma en tercera persona.")

	GE_RGBA	Luz_color;
	#pragma GE_DefaultValue(Luz_color, "255 55 15")
	#pragma GE_Documentation(Luz_color, "Color de la luz que acompaña al proyectil.")

	float	Luz_escala;
	#pragma GE_DefaultValue(Luz_escala, "320")
	#pragma GE_Documentation(Luz_escala, "Tamaño de la luz que acompaña al proyectil.")

	geBoolean	Particulas;
	#pragma GE_DefaultValue(Particulas, "False")
	#pragma GE_Documentation(Particulas, "Partículas acompañan al proyectil. False=No True=Si")

	geBoolean	Humo;
	#pragma GE_DefaultValue(Humo, "True")
	#pragma GE_Documentation(Humo, "Humo acompaña al proyectil. False=No True=Si")

	float	Escala_proyectil;
	#pragma GE_DefaultValue(Escala_proyectil, "2.5")
	#pragma GE_Documentation(Escala_proyectil, "Tamaño del proyectil.")

	char *Particulas_BMP;
	#pragma GE_DefaultValue(Particulas_BMP, "Parti")
	#pragma GE_Documentation(Particulas_BMP, "Nombre de la secuencia de ficheros .BMP que representan las partículas.")

	geBoolean	Config_activa;
	#pragma GE_DefaultValue(Config_activa, "True")
	#pragma GE_Documentation(Config_activa, "Activar esta configuración para esta arma. False=No True=Si")

	float	Cadencia;
	#pragma GE_DefaultValue(Cadencia, "5")
	#pragma GE_Documentation(Cadencia, "Disparos por segundo (del 1 al 10). A más valor, más disparos.")

	float	Salud_resta;
	#pragma GE_DefaultValue(Salud_resta, "15")
	#pragma GE_Documentation(Salud_resta, "Salud que resta a jugador o enemigos por impacto directo (de 0 a 255)")

	float	Salud_resta_critica;
	#pragma GE_DefaultValue(Salud_resta_critica, "255")
	#pragma GE_Documentation(Salud_resta_critica, "Salud que resta al enemigo por impacto en zona crítica (de 0 a 255)")

	geBoolean	Primera_persona;
	#pragma GE_DefaultValue(Primera_persona, "False")
	#pragma GE_Documentation(Primera_persona, "¿ Arma sólo para vista en primera persona ?. False=No True=Si")

	float	Temporizador;
	#pragma GE_DefaultValue(Temporizador, "3.5")
	#pragma GE_Documentation(Temporizador, "Tiempo en segundos para la explosión de la granada.")

	char *AnimDisparo;
	#pragma GE_DefaultValue(AnimDisparo, "sin_animacion")
	#pragma GE_Documentation(AnimDisparo, "Nombre de la animación del disparo o ataque en primera persona ('Shoot')")

	float AnimDispVel;
	#pragma GE_DefaultValue(AnimDispVel, "1")
	#pragma GE_Documentation(AnimDispVel, "Velocidad de la animación del disparo. 0.5=lenta 1=normal 2=rápida, etc.")

	char *AnimNDisparo;
	#pragma GE_DefaultValue(AnimNDisparo, "sin_animacion")
	#pragma GE_Documentation(AnimNDisparo, "Nombre de la animación sin disparar en primera persona ('Idle'")

	float AnimNDispVel;
	#pragma GE_DefaultValue(AnimNDispVel, "1")
	#pragma GE_Documentation(AnimNDispVel, "Velocidad de la animación sin disparar. 0.5=lenta 1=normal 2=rápida, etc.")

	float	Municion_resta;
	#pragma GE_DefaultValue(Municion_resta, "1")
	#pragma GE_Documentation(Municion_resta, "Cantidad de munición a restar en cada disparo.")

	float	Municion_cargador;
	#pragma GE_DefaultValue(Municion_cargador, "10")
	#pragma GE_Documentation(Municion_cargador, "Cantidad de munición en cada cargador.")

	float	Municion_inicial;
	#pragma GE_DefaultValue(Municion_inicial, "10")
	#pragma GE_Documentation(Municion_inicial, "Cantidad de munición inicial en el arma.")

	float	Posicion_disparo_1_alt_online;
	#pragma GE_DefaultValue(Posicion_disparo_1_alt_online, "75")
	#pragma GE_Documentation(Posicion_disparo_1_alt_online, "Ajuste de la altura establecida en 'Posicion_disparo_1' (Online)")

	float	Posicion_mira_3_alt;
	#pragma GE_DefaultValue(Posicion_mira_3_alt, "40")
	#pragma GE_Documentation(Posicion_mira_3_alt, "Altura del punto de mira en tercera persona (Online Cli)")

	float	Posicion_mira_3_ang;
	#pragma GE_DefaultValue(Posicion_mira_3_ang, "20")
	#pragma GE_Documentation(Posicion_mira_3_ang, "Ajuste 'Posicion_mira_3_alt' según ángulo de la cámara (Online Cli)")

#pragma GE_Origin(Origin)
}   ConfigArmaDos;



// ==========================
// Entidad 'ConfigArmaTres'
// ==========================
// Configuración del arma número 3 (Lanza-cohetes)
#pragma GE_Type("Item.ico")
typedef struct  ConfigArmaTres
{
#pragma GE_Published
	#pragma GE_Private
	geVec3d		Origin;
	#pragma GE_Published

	float	Velocidad;
	#pragma GE_DefaultValue(Velocidad, "3600")
	#pragma GE_Documentation(Velocidad, "Velocidad del proyectil. (De 600 a 50000)")

	char *Arma_ACT;
	#pragma GE_DefaultValue(Arma_ACT, "rlaunch.act")
	#pragma GE_Documentation(Arma_ACT, "Nombre del fichero .ACT que representa el arma.")

	char *Proyectil_ACT;
	#pragma GE_DefaultValue(Proyectil_ACT, "rocket.act")
	#pragma GE_Documentation(Proyectil_ACT, "Nombre del fichero .ACT que representa el proyectil.")

	char *Sonido_Disp_WAV;
	#pragma GE_DefaultValue(Sonido_Disp_WAV, "misil_disp.wav")
	#pragma GE_Documentation(Sonido_Disp_WAV, "Nombre del fichero de sonido .WAV del disparo.")

	char *Sonido_Impa_WAV;
	#pragma GE_DefaultValue(Sonido_Impa_WAV, "misil_exp.wav")
	#pragma GE_Documentation(Sonido_Impa_WAV, "Nombre del fichero de sonido .WAV del impacto del proyectil.")

	geVec3d	Orientacion_1;
	#pragma GE_DefaultValue(Orientacion_1, "0 90 0")
	#pragma GE_Documentation(Orientacion_1, "Orientación del arma en primera persona.")

	geVec3d	Orientacion_3;
	#pragma GE_DefaultValue(Orientacion_3, "90 -15 5")
	#pragma GE_Documentation(Orientacion_3, "Orientación del arma en tercera persona.")

	float	Orient_Punto_Mira;
	#pragma GE_DefaultValue(Orient_Punto_Mira, "5")
	#pragma GE_Documentation(Orient_Punto_Mira, "Orientación hacia el punto de mira en primera persona")

	geVec3d	Posicion_arma_1;
	#pragma GE_DefaultValue(Posicion_arma_1, "0 0 0")
	#pragma GE_Documentation(Posicion_arma_1, "Posición del arma en primera persona.")

	geVec3d	Posicion_arma_3;
	#pragma GE_DefaultValue(Posicion_arma_3, "-5 -5 5")
	#pragma GE_Documentation(Posicion_arma_3, "Posición del arma en tercera persona.")

	geVec3d	Posicion_disparo_1;
	#pragma GE_DefaultValue(Posicion_disparo_1, "110 -10 -10")
	#pragma GE_Documentation(Posicion_disparo_1, "Posición salida del disparo en primera persona.")

	geVec3d	Posicion_disparo_3;
	#pragma GE_DefaultValue(Posicion_disparo_3, "90 15 -25")
	#pragma GE_Documentation(Posicion_disparo_3, "Posición salida del disparo en tercera persona.")

	float	Escala_1;
	#pragma GE_DefaultValue(Escala_1, "15")
	#pragma GE_Documentation(Escala_1, "Escala del arma en primera persona.")

	float	Escala_3;
	#pragma GE_DefaultValue(Escala_3, "85")
	#pragma GE_Documentation(Escala_3, "Escala del arma en tercera persona.")

	GE_RGBA	Luz_color;
	#pragma GE_DefaultValue(Luz_color, "255 55 15")
	#pragma GE_Documentation(Luz_color, "Color de la luz que acompaña al proyectil.")

	float	Luz_escala;
	#pragma GE_DefaultValue(Luz_escala, "320")
	#pragma GE_Documentation(Luz_escala, "Tamaño de la luz que acompaña al proyectil.")

	geBoolean	Particulas;
	#pragma GE_DefaultValue(Particulas, "False")
	#pragma GE_Documentation(Particulas, "Partículas acompañan al proyectil. False=No True=Si")

	geBoolean	Humo;
	#pragma GE_DefaultValue(Humo, "True")
	#pragma GE_Documentation(Humo, "Humo acompaña al proyectil. False=No True=Si")

	float	Escala_proyectil;
	#pragma GE_DefaultValue(Escala_proyectil, "1")
	#pragma GE_Documentation(Escala_proyectil, "Tamaño del proyectil.")

	char *Particulas_BMP;
	#pragma GE_DefaultValue(Particulas_BMP, "Parti")
	#pragma GE_Documentation(Particulas_BMP, "Nombre de la secuencia de ficheros .BMP que representan las partículas.")

	geBoolean	Config_activa;
	#pragma GE_DefaultValue(Config_activa, "True")
	#pragma GE_Documentation(Config_activa, "Activar esta configuración para esta arma. False=No True=Si")

	float	Cadencia;
	#pragma GE_DefaultValue(Cadencia, "2")
	#pragma GE_Documentation(Cadencia, "Disparos por segundo (del 1 al 10). A más valor, más disparos.")

	float	Salud_resta;
	#pragma GE_DefaultValue(Salud_resta, "35")
	#pragma GE_Documentation(Salud_resta, "Salud que resta a jugador o enemigos por impacto directo (de 0 a 255)")

	float	Salud_resta_critica;
	#pragma GE_DefaultValue(Salud_resta_critica, "255")
	#pragma GE_Documentation(Salud_resta_critica, "Salud que resta al enemigo por impacto en zona crítica (de 0 a 255)")

	geBoolean	Primera_persona;
	#pragma GE_DefaultValue(Primera_persona, "False")
	#pragma GE_Documentation(Primera_persona, "¿ Arma sólo para vista en primera persona ?. False=No True=Si")

	char *AnimDisparo;
	#pragma GE_DefaultValue(AnimDisparo, "sin_animacion")
	#pragma GE_Documentation(AnimDisparo, "Nombre de la animación del disparo o ataque en primera persona ('Shoot')")

	float AnimDispVel;
	#pragma GE_DefaultValue(AnimDispVel, "1")
	#pragma GE_Documentation(AnimDispVel, "Velocidad de la animación del disparo. 0.5=lenta 1=normal 2=rápida, etc.")

	char *AnimNDisparo;
	#pragma GE_DefaultValue(AnimNDisparo, "sin_animacion")
	#pragma GE_Documentation(AnimNDisparo, "Nombre de la animación sin disparar en primera persona ('Idle'")

	float AnimNDispVel;
	#pragma GE_DefaultValue(AnimNDispVel, "1")
	#pragma GE_Documentation(AnimNDispVel, "Velocidad de la animación sin disparar. 0.5=lenta 1=normal 2=rápida, etc.")

	float	Municion_resta;
	#pragma GE_DefaultValue(Municion_resta, "1")
	#pragma GE_Documentation(Municion_resta, "Cantidad de munición a restar en cada disparo.")

	float	Municion_cargador;
	#pragma GE_DefaultValue(Municion_cargador, "10")
	#pragma GE_Documentation(Municion_cargador, "Cantidad de munición en cada cargador.")

	float	Municion_inicial;
	#pragma GE_DefaultValue(Municion_inicial, "10")
	#pragma GE_Documentation(Municion_inicial, "Cantidad de munición inicial en el arma.")

	float	Bot_punteria_movil;
	#pragma GE_DefaultValue(Bot_punteria_movil, "1.2")
	#pragma GE_Documentation(Bot_punteria_movil, "Puntería de Bot sobre objetivo móvil (de -20.0 a 20.0)")

	float	Posicion_disparo_1_alt_online;
	#pragma GE_DefaultValue(Posicion_disparo_1_alt_online, "75")
	#pragma GE_Documentation(Posicion_disparo_1_alt_online, "Ajuste de la altura establecida en 'Posicion_disparo_1' (Online)")

	float	Posicion_mira_3_alt;
	#pragma GE_DefaultValue(Posicion_mira_3_alt, "40")
	#pragma GE_Documentation(Posicion_mira_3_alt, "Altura del punto de mira en tercera persona (Online Cli)")

	float	Posicion_mira_3_ang;
	#pragma GE_DefaultValue(Posicion_mira_3_ang, "20")
	#pragma GE_Documentation(Posicion_mira_3_ang, "Ajuste 'Posicion_mira_3_alt' según ángulo de la cámara (Online Cli)")

#pragma GE_Origin(Origin)
}   ConfigArmaTres;



// ==========================
// Entidad 'ConfigArmaCuatro'
// ==========================
// Configuración del arma número 4 (Fusil)
#pragma GE_Type("Item.ico")
typedef struct  ConfigArmaCuatro
{
#pragma GE_Published
	#pragma GE_Private
	geVec3d		Origin;
	#pragma GE_Published

	char *Arma_ACT;
	#pragma GE_DefaultValue(Arma_ACT, "shredder.act")
	#pragma GE_Documentation(Arma_ACT, "Nombre del fichero .ACT que representa la arma.")

	char *Sonido_Disp_WAV;
	#pragma GE_DefaultValue(Sonido_Disp_WAV, "desfibradora_disp.wav")
	#pragma GE_Documentation(Sonido_Disp_WAV, "Nombre del fichero de sonido .WAV del disparo.")

	geVec3d	Orientacion_1;
	#pragma GE_DefaultValue(Orientacion_1, "0 0 0")
	#pragma GE_Documentation(Orientacion_1, "Orientación del arma en primera persona.")

	geVec3d	Orientacion_3;
	#pragma GE_DefaultValue(Orientacion_3, "-10 -110 -90")
	#pragma GE_Documentation(Orientacion_3, "Orientación del arma en tercera persona.")

	float	Orient_Punto_Mira;
	#pragma GE_DefaultValue(Orient_Punto_Mira, "5")
	#pragma GE_Documentation(Orient_Punto_Mira, "Orientación hacia el punto de mira en primera persona")

	geVec3d	Posicion_arma_1;
	#pragma GE_DefaultValue(Posicion_arma_1, "0 3 0")
	#pragma GE_Documentation(Posicion_arma_1, "Posición del arma en primera persona.")

	geVec3d	Posicion_arma_3;
	#pragma GE_DefaultValue(Posicion_arma_3, "35 5 0")
	#pragma GE_Documentation(Posicion_arma_3, "Posición del arma en tercera persona.")

	geVec3d	Posicion_disparo_1;
	#pragma GE_DefaultValue(Posicion_disparo_1, "16 0 1.5")
	#pragma GE_Documentation(Posicion_disparo_1, "Posición salida del disparo en primera persona.")

	geVec3d	Posicion_disparo_3;
	#pragma GE_DefaultValue(Posicion_disparo_3, "40 55 -20")
	#pragma GE_Documentation(Posicion_disparo_3, "Posición salida del disparo en tercera persona.")

	geVec3d	Posicion_fogonazo_1;
	#pragma GE_DefaultValue(Posicion_fogonazo_1, "16 0 1.5")
	#pragma GE_Documentation(Posicion_fogonazo_1, "Posición del fogonazo del disparo en primera persona.")

	geVec3d	Posicion_fogonazo_3;
	#pragma GE_DefaultValue(Posicion_fogonazo_3, "40 55 -20")
	#pragma GE_Documentation(Posicion_fogonazo_3, "Posición del fogonazo del disparo en tercera persona.")

	float	Escala_1;
	#pragma GE_DefaultValue(Escala_1, "15")
	#pragma GE_Documentation(Escala_1, "Escala del arma en primera persona.")

	float	Escala_3;
	#pragma GE_DefaultValue(Escala_3, "80")
	#pragma GE_Documentation(Escala_3, "Escala del arma en tercera persona.")

	float	Escala_fogonazo_1;
	#pragma GE_DefaultValue(Escala_fogonazo_1, "0.4")
	#pragma GE_Documentation(Escala_fogonazo_1, "Tamaño del fogonazo en primera persona.")

	float	Escala_fogonazo_3;
	#pragma GE_DefaultValue(Escala_fogonazo_3, "0.8")
	#pragma GE_Documentation(Escala_fogonazo_3, "Tamaño del fogonazo en tercera persona.")

	char *Fogonazo_BMP;
	#pragma GE_DefaultValue(Fogonazo_BMP, "explode3_01.bmp")
	#pragma GE_Documentation(Fogonazo_BMP, "Nombre del fichero .BMP que representa el fogonazo.")

	char *Fogonazo_aBMP;
	#pragma GE_DefaultValue(Fogonazo_aBMP, "a_explode3_01.bmp")
	#pragma GE_Documentation(Fogonazo_aBMP, "Nombre del fichero .BMP (con canal Alpha) para el fogonazo.")

	geBoolean	Config_activa;
	#pragma GE_DefaultValue(Config_activa, "True")
	#pragma GE_Documentation(Config_activa, "Activar esta configuración para esta arma. False=No True=Si")

	float	Cadencia;
	#pragma GE_DefaultValue(Cadencia, "10")
	#pragma GE_Documentation(Cadencia, "Disparos por segundo (del 1 al 10). A más valor, más disparos.")

	float	Salud_resta;
	#pragma GE_DefaultValue(Salud_resta, "25")
	#pragma GE_Documentation(Salud_resta, "Salud que resta a jugador o enemigos por impacto directo (de 0 a 255)")

	float	Salud_resta_critica;
	#pragma GE_DefaultValue(Salud_resta_critica, "255")
	#pragma GE_Documentation(Salud_resta_critica, "Salud que resta al enemigo por impacto en zona crítica (de 0 a 255)")

	geBoolean	Primera_persona;
	#pragma GE_DefaultValue(Primera_persona, "False")
	#pragma GE_Documentation(Primera_persona, "¿ Arma sólo para vista en primera persona ?. False=No True=Si")

	float	Alcance;
	#pragma GE_DefaultValue(Alcance, "10000")
	#pragma GE_Documentation(Alcance, "Alcance del disparo (de 1 a 10000)")

	char *AnimDisparo;
	#pragma GE_DefaultValue(AnimDisparo, "sin_animacion")
	#pragma GE_Documentation(AnimDisparo, "Nombre de la animación del disparo o ataque en primera persona ('Shoot')")

	float AnimDispVel;
	#pragma GE_DefaultValue(AnimDispVel, "1")
	#pragma GE_Documentation(AnimDispVel, "Velocidad de la animación del disparo. 0.5=lenta 1=normal 2=rápida, etc.")

	char *AnimNDisparo;
	#pragma GE_DefaultValue(AnimNDisparo, "sin_animacion")
	#pragma GE_Documentation(AnimNDisparo, "Nombre de la animación sin disparar en primera persona ('Idle'")

	float AnimNDispVel;
	#pragma GE_DefaultValue(AnimNDispVel, "1")
	#pragma GE_Documentation(AnimNDispVel, "Velocidad de la animación sin disparar. 0.5=lenta 1=normal 2=rápida, etc.")

	geBoolean ArmaDeMano;
	#pragma GE_DefaultValue(ArmaDeMano, "False")
	#pragma GE_Documentation(ArmaDeMano, "¿ Es una arma cuerpo a cuerpo tipo palo, cuchillo, espada, ..? False=No True=Si")

	float	Municion_resta;
	#pragma GE_DefaultValue(Municion_resta, "1")
	#pragma GE_Documentation(Municion_resta, "Cantidad de munición a restar en cada disparo.")

	float	Municion_cargador;
	#pragma GE_DefaultValue(Municion_cargador, "50")
	#pragma GE_Documentation(Municion_cargador, "Cantidad de munición en cada cargador.")

	float	Municion_inicial;
	#pragma GE_DefaultValue(Municion_inicial, "50")
	#pragma GE_Documentation(Municion_inicial, "Cantidad de munición inicial en el arma.")

	GE_RGBA	Luz_fogonazo;
	#pragma GE_DefaultValue(Luz_fogonazo, "213 219 38")
	#pragma GE_Documentation(Luz_fogonazo, "Color de la luz del fogonazo.")

	float	Posicion_mira_3_alt;
	#pragma GE_DefaultValue(Posicion_mira_3_alt, "40")
	#pragma GE_Documentation(Posicion_mira_3_alt, "Altura del punto de mira en tercera persona.")

	float	Posicion_mira_3_ang;
	#pragma GE_DefaultValue(Posicion_mira_3_ang, "20")
	#pragma GE_Documentation(Posicion_mira_3_ang, "Ajuste 'Posicion_mira_3_alt' según ángulo de la cámara.")

#pragma GE_Origin(Origin)
}   ConfigArmaCuatro;


geBoolean Recoge_ConfigArma1(geWorld *World);
geBoolean Recoge_ConfigArma2(geWorld *World);
geBoolean Recoge_ConfigArma3(geWorld *World);
geBoolean Recoge_ConfigArma4(geWorld *World);


#ifdef __cplusplus
}
#endif

#endif
