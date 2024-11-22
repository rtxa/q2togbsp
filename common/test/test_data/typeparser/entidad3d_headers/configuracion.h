/****************************************************************************************/
/*  File: configuracion.h                                                               */
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
/*  Autor: Jordi Pérez                                                                  */
/*                                                                                      */
/*  Copyright (c) 2004 - 2016 Jordi Pérez; All rights reserved.                         */
/*                                                                                      */
/****************************************************************************************/

#ifndef CONFIGURACION_H
#define CONFIGURACION_H
#ifdef __cplusplus
extern "C" {
#endif

#pragma warning( disable : 4068 )

// ==========================
// Entidad 'Configuracion'
// ==========================
// Entidad para datos generales de configuración
#pragma GE_Type("Item.ico")
typedef struct  Configuracion
{
#pragma GE_Private
	geVec3d		Origin;
#pragma GE_Published

	//geBoolean   Ver_puntuacion;
	//#pragma GE_DefaultValue(Ver_puntuacion, "False")
	//#pragma GE_Documentation(Ver_puntuacion, "Ver en pantalla puntuación y record. True=Si False=No")

	int	VolumenMusicaFondo;
	#pragma GE_DefaultValue(VolumenMusicaFondo, "90")
	#pragma GE_Documentation(VolumenMusicaFondo, "Volumen de la música de fondo. Entre 0 y 100")

	geBoolean   Utilizar_joystick;
	#pragma GE_DefaultValue(Utilizar_joystick, "False")
	#pragma GE_Documentation(Utilizar_joystick, "¿ Utilización del Joystick o Gamepad durante el juego ?. True=Si False=No")

	geBoolean   Camara_inicial_1;
	#pragma GE_DefaultValue(Camara_inicial_1, "True")
	#pragma GE_Documentation(Camara_inicial_1, "Cámara inicial en primera persona. False=No True=Si")

	geBoolean   Camara_inicial_3;
	#pragma GE_DefaultValue(Camara_inicial_3, "False")
	#pragma GE_Documentation(Camara_inicial_3, "Cámara inicial en tercera persona. False=No True=Si")

	geBoolean   Camara_inicial_RPG;
	#pragma GE_DefaultValue(Camara_inicial_RPG, "False")
	#pragma GE_Documentation(Camara_inicial_RPG, "Cámara inicial tipo RPG. False=No True=Si")

	geBoolean   Permite_camara_1;
	#pragma GE_DefaultValue(Permite_camara_1, "True")
	#pragma GE_Documentation(Permite_camara_1, "Permite cambio a cámara en primera persona. False=No True=Si")

	geBoolean   Permite_camara_3;
	#pragma GE_DefaultValue(Permite_camara_3, "True")
	#pragma GE_Documentation(Permite_camara_3, "Permite cambio a cámara en tercera persona. False=No True=Si")

	geBoolean   Permite_camara_RPG;
	#pragma GE_DefaultValue(Permite_camara_RPG, "True")
	#pragma GE_Documentation(Permite_camara_RPG, "Permite cambio a cámara tipo RPG. False=No True=Si")

	geBoolean   Permite_camara_PLAT;
	#pragma GE_DefaultValue(Permite_camara_PLAT, "True")
	#pragma GE_Documentation(Permite_camara_PLAT, "Permite cambio a cámara tipo Plataformas. False=No True=Si")

	geBoolean   Camara_inicial_PLAT;
	#pragma GE_DefaultValue(Camara_inicial_PLAT, "False")
	#pragma GE_Documentation(Camara_inicial_PLAT, "Cámara inicial tipo Plataformas. False=No True=Si")

	int	Camara_PLAT_alt;
	#pragma GE_DefaultValue(Camara_PLAT_alt, "250")
	#pragma GE_Documentation(Camara_PLAT_alt, "Altura de la cámara tipo Plataformas. Entre 10 y 1000")

	int	Camara_PLAT_dist;
	#pragma GE_DefaultValue(Camara_PLAT_dist, "400")
	#pragma GE_Documentation(Camara_PLAT_dist, "Distancia de la cámara tipo Plataformas. Entre 10 y 1000")

	geBoolean   Ver_Sombras;
	#pragma GE_DefaultValue(Ver_Sombras, "True")
	#pragma GE_Documentation(Ver_Sombras, "Ver sombras de objetos y personajes. True=Si False=No")

	int	Camara_RPG_alt;
	#pragma GE_DefaultValue(Camara_RPG_alt, "300")
	#pragma GE_Documentation(Camara_RPG_alt, "Altura de la cámara tipo RPG. Entre 10 y 1000")

	int	Camara_RPG_dist;
	#pragma GE_DefaultValue(Camara_RPG_dist, "300")
	#pragma GE_Documentation(Camara_RPG_dist, "Distancia de la cámara tipo RPG. Entre 10 y 1000")

	float	Camara_RPG_angulo;
	#pragma GE_DefaultValue(Camara_RPG_angulo, "45")
	#pragma GE_Documentation(Camara_RPG_angulo, "Ángulo de inclinación de la cámara tipo RPG. Entre 0 y 90 grados")

	int	Camara_3PER_alt;
	#pragma GE_DefaultValue(Camara_3PER_alt, "55")
	#pragma GE_Documentation(Camara_3PER_alt, "Altura de la cámara en tercera persona. Entre 1 y 1000")

	int	Camara_3PER_dist;
	#pragma GE_DefaultValue(Camara_3PER_dist, "300")
	#pragma GE_Documentation(Camara_3PER_dist, "Distancia de la cámara en tercera persona. Entre 10 y 1000")

	float	Camara_3PER_angulo;
	#pragma GE_DefaultValue(Camara_3PER_angulo, "180")
	#pragma GE_Documentation(Camara_3PER_angulo, "Ángulo de acercamiento de la cámara en tercera persona. Entre 10 y 360 grados")

	int	Lava_salud;
	#pragma GE_DefaultValue(Lava_salud, "20")
	#pragma GE_Documentation(Lava_salud, "Cantidad de salud que resta la lava al tocarla (de 0 a 255)")

	char *FicheroComandos;
	#pragma GE_DefaultValue(FicheroComandos, "")
	#pragma GE_Documentation(FicheroComandos, "Fichero de comandos a procesar al comienzo.")

	char *FicheroAcciones;
	#pragma GE_DefaultValue(FicheroAcciones, "")
	#pragma GE_Documentation(FicheroAcciones, "Fichero de comandos a procesar al usar acciones.")

	char *FicheroComandosMorir;
	#pragma GE_DefaultValue(FicheroComandosMorir, "")
	#pragma GE_Documentation(FicheroComandosMorir, "Fichero de comandos a procesar al morir jugador.")

	char *FicheroComandosFinal;
	#pragma GE_DefaultValue(FicheroComandosFinal, "")
	#pragma GE_Documentation(FicheroComandosFinal, "Fichero de comandos a procesar al finalizar partida.")

	char *FicheroComandosSalud;
	#pragma GE_DefaultValue(FicheroComandosSalud, "")
	#pragma GE_Documentation(FicheroComandosSalud, "Fichero de comandos a procesar al sufrir daño el jugador.")

	char *FicheroComandosRespawn;
	#pragma GE_DefaultValue(FicheroComandosRespawn, "")
	#pragma GE_Documentation(FicheroComandosRespawn, "Fichero de comandos a procesar al re-aparecer el jugador.")

	char *FicheroComandosRatonIzq;
	#pragma GE_DefaultValue(FicheroComandosRatonIzq, "")
	#pragma GE_Documentation(FicheroComandosRatonIzq, "Fichero de comandos a procesar al pulsar el botón izquierdo del ratón.")

	geBoolean   UsarFicherosEnc;
	#pragma GE_DefaultValue(UsarFicherosEnc, "False")
	#pragma GE_Documentation(UsarFicherosEnc, "¿ Usar ficheros encriptados '.enc' ?. True=Si False=No")

	int	SombrasDinMax;
	#pragma GE_DefaultValue(SombrasDinMax, "1")
	#pragma GE_Documentation(SombrasDinMax, "Número máximo de sombras dinámicas por objeto o personaje. (0 a 3)")

	geBoolean   Ver_zona_ItemObjects;
	#pragma GE_DefaultValue(Ver_zona_ItemObjects, "False")
	#pragma GE_Documentation(Ver_zona_ItemObjects, "¿ Ver zona influencia de ItemObjects ? True=Si False=No")

	geBoolean	Fx_Bobbing_camara_1;
	#pragma GE_DefaultValue(Fx_Bobbing_camara_1, "False")
	#pragma GE_Documentation(Fx_Bobbing_camara_1, "Efecto 'Bobbing' en cámara primera persona. True=Si False=No")

	geBoolean	Ocultar_ACTs;
	#pragma GE_DefaultValue(Ocultar_ACTs, "False")
	#pragma GE_Documentation(Ocultar_ACTs, "Ocultar todos los modelos 3D .ACT del nivel. True=Si False=No")

	geBoolean	Camara_colisiona_winclip;
	#pragma GE_DefaultValue(Camara_colisiona_winclip, "True")
	#pragma GE_Documentation(Camara_colisiona_winclip, "La cámara colisiona con bloques 'Window' y 'Clip'. True=Si False=No")

	char *Personajes_validos;
	#pragma GE_DefaultValue(Personajes_validos, "")
	#pragma GE_Documentation(Personajes_validos, "Personajes válidos para juego online. 1 a 15 y separar por comas ,")

	geBoolean	Ajustar_armas_juego;
	#pragma GE_DefaultValue(Ajustar_armas_juego, "False")
	#pragma GE_Documentation(Ajustar_armas_juego, "Permite ajustar parámetros de armas dinámicamente en tiempo de juego")

	geBoolean	Camara_3PER_alt_SI_salto;
	#pragma GE_DefaultValue(Camara_3PER_alt_SI_salto, "True")
	#pragma GE_Documentation(Camara_3PER_alt_SI_salto, "'False' -> al saltar, no aplicar 'Camara_3PER_alt'. 'True' -> si aplicar")

	char *Moneda_tipo;
	#pragma GE_DefaultValue(Moneda_tipo, "dolares")
	#pragma GE_Documentation(Moneda_tipo, "Nombre de la moneda para comprar y vender")

#pragma GE_Origin(Origin)
}   Configuracion;



// ==========================
// Entidad 'ConfigSonidosEne'
// ==========================
// Entidad para datos de sonidos WAV para los enemigos y enemigas
#pragma GE_Type("Item.ico")
typedef struct  ConfigSonidosEne
{
#pragma GE_Private
	geVec3d		Origin;
#pragma GE_Published

	int Num_enemigo;
	#pragma GE_DefaultValue(Num_enemigo, "1")
	#pragma GE_Documentation(Num_enemigo, "Número de enemigo a configurar. De 1 a 8.")

	geBoolean   Config_activa;
	#pragma GE_DefaultValue(Config_activa, "True")
	#pragma GE_Documentation(Config_activa, "¿ Activar esta configuración para este enemigo ? True=Si False=No")

	char *EnemigoMuere_a;
	#pragma GE_DefaultValue(EnemigoMuere_a, "muerto1a.wav")
	#pragma GE_Documentation(EnemigoMuere_a, "Nombre de un fichero .WAV para muerte del enemigo.")

	char *EnemigoMuere_b;
	#pragma GE_DefaultValue(EnemigoMuere_b, "muerto1b.wav")
	#pragma GE_Documentation(EnemigoMuere_b, "Nombre de un fichero .WAV para muerte del enemigo.")

	char *EnemigoMuere_c;
	#pragma GE_DefaultValue(EnemigoMuere_c, "muerto1c.wav")
	#pragma GE_Documentation(EnemigoMuere_c, "Nombre de un fichero .WAV para muerte del enemigo.")

	char *EnemigaMuere_a;
	#pragma GE_DefaultValue(EnemigaMuere_a, "muerto1a_f.wav")
	#pragma GE_Documentation(EnemigaMuere_a, "Nombre de un fichero .WAV para muerte de la enemiga.")

	char *EnemigaMuere_b;
	#pragma GE_DefaultValue(EnemigaMuere_b, "muerto1b_f.wav")
	#pragma GE_Documentation(EnemigaMuere_b, "Nombre de un fichero .WAV para muerte de la enemiga.")

	char *EnemigaMuere_c;
	#pragma GE_DefaultValue(EnemigaMuere_c, "muerto1c_f.wav")
	#pragma GE_Documentation(EnemigaMuere_c, "Nombre de un fichero .WAV para muerte de la enemiga.")

	char *EnemigoDolor_a;
	#pragma GE_DefaultValue(EnemigoDolor_a, "daño1a.wav")
	#pragma GE_Documentation(EnemigoDolor_a, "Nombre de un fichero .WAV para daño del enemigo.")

	char *EnemigoDolor_b;
	#pragma GE_DefaultValue(EnemigoDolor_b, "daño1b.wav")
	#pragma GE_Documentation(EnemigoDolor_b, "Nombre de un fichero .WAV para daño del enemigo.")

	char *EnemigoDolor_c;
	#pragma GE_DefaultValue(EnemigoDolor_c, "daño1c.wav")
	#pragma GE_Documentation(EnemigoDolor_c, "Nombre de un fichero .WAV para daño del enemigo.")

	char *EnemigaDolor_a;
	#pragma GE_DefaultValue(EnemigaDolor_a, "daño1a_f.wav")
	#pragma GE_Documentation(EnemigaDolor_a, "Nombre de un fichero .WAV para daño de la enemiga.")

	char *EnemigaDolor_b;
	#pragma GE_DefaultValue(EnemigaDolor_b, "daño1b_f.wav")
	#pragma GE_Documentation(EnemigaDolor_b, "Nombre de un fichero .WAV para daño de la enemiga.")

	char *EnemigaDolor_c;
	#pragma GE_DefaultValue(EnemigaDolor_c, "daño1c_f.wav")
	#pragma GE_Documentation(EnemigaDolor_c, "Nombre de un fichero .WAV para daño de la enemiga.")

	char *EnemigoEmite_a;
	#pragma GE_DefaultValue(EnemigoEmite_a, "emite_ene1a.wav")
	#pragma GE_Documentation(EnemigoEmite_a, "Fichero de sonido .WAV que emite el enemigo.")

	char *EnemigoEmite_b;
	#pragma GE_DefaultValue(EnemigoEmite_b, "emite_ene1b.wav")
	#pragma GE_Documentation(EnemigoEmite_b, "Fichero de sonido .WAV que emite el enemigo.")
	
	char *EnemigaEmite_a;
	#pragma GE_DefaultValue(EnemigaEmite_a, "emite_ene1a_f.wav")
	#pragma GE_Documentation(EnemigaEmite_a, "Fichero de sonido .WAV que emite la enemiga.")

	char *EnemigaEmite_b;
	#pragma GE_DefaultValue(EnemigaEmite_b, "emite_ene1b_f.wav")
	#pragma GE_Documentation(EnemigaEmite_b, "Fichero de sonido .WAV que emite la enemiga.")
	
#pragma GE_Origin(Origin)
}   ConfigSonidosEne;



// ==========================
// Entidad 'ConfigSonidosJug'
// ==========================
// Entidad para datos de sonidos WAV del jugador o de la jugadora
#pragma GE_Type("Item.ico")
typedef struct  ConfigSonidosJug
{
#pragma GE_Private
	geVec3d		Origin;
#pragma GE_Published

	char *SonidoDolor1;
	#pragma GE_DefaultValue(SonidoDolor1, "dolor1.wav")
	#pragma GE_Documentation(SonidoDolor1, "Fichero de sonido .WAV para daño del jugador")

	char *SonidoDolor2;
	#pragma GE_DefaultValue(SonidoDolor2, "dolor2.wav")
	#pragma GE_Documentation(SonidoDolor2, "Fichero de sonido .WAV para daño del jugador")

	char *SonidoDolor3;
	#pragma GE_DefaultValue(SonidoDolor3, "dolor3.wav")
	#pragma GE_Documentation(SonidoDolor3, "Fichero de sonido .WAV para daño del jugador")

	char *SonidoDolor4;
	#pragma GE_DefaultValue(SonidoDolor4, "dolor4.wav")
	#pragma GE_Documentation(SonidoDolor4, "Fichero de sonido .WAV para daño del jugador")

	char *SonidoDolor5;
	#pragma GE_DefaultValue(SonidoDolor5, "dolor5.wav")
	#pragma GE_Documentation(SonidoDolor5, "Fichero de sonido .WAV para daño del jugador")

	char *SonidoDolor1_F;
	#pragma GE_DefaultValue(SonidoDolor1_F, "dolor1_f.wav")
	#pragma GE_Documentation(SonidoDolor1_F, "Fichero de sonido .WAV para daño de la jugadora")

	char *SonidoDolor2_F;
	#pragma GE_DefaultValue(SonidoDolor2_F, "dolor2_f.wav")
	#pragma GE_Documentation(SonidoDolor2_F, "Fichero de sonido .WAV para daño de la jugadora")

	char *SonidoDolor3_F;
	#pragma GE_DefaultValue(SonidoDolor3_F, "dolor3_f.wav")
	#pragma GE_Documentation(SonidoDolor3_F, "Fichero de sonido .WAV para daño de la jugadora")

	char *SonidoDolor4_F;
	#pragma GE_DefaultValue(SonidoDolor4_F, "dolor4_f.wav")
	#pragma GE_Documentation(SonidoDolor4_F, "Fichero de sonido .WAV para daño de la jugadora")

	char *SonidoDolor5_F;
	#pragma GE_DefaultValue(SonidoDolor5_F, "dolor5_f.wav")
	#pragma GE_Documentation(SonidoDolor5_F, "Fichero de sonido .WAV para daño de la jugadora")

	char *SonidoMuerte1;
	#pragma GE_DefaultValue(SonidoMuerte1, "muerte1.wav")
	#pragma GE_Documentation(SonidoMuerte1, "Fichero de sonido .WAV para muerte del jugador")

	char *SonidoMuerte2;
	#pragma GE_DefaultValue(SonidoMuerte2, "muerte2.wav")
	#pragma GE_Documentation(SonidoMuerte2, "Fichero de sonido .WAV para muerte del jugador")

	char *SonidoMuerte3;
	#pragma GE_DefaultValue(SonidoMuerte3, "muerte3.wav")
	#pragma GE_Documentation(SonidoMuerte3, "Fichero de sonido .WAV para muerte del jugador")

	char *SonidoMuerte4;
	#pragma GE_DefaultValue(SonidoMuerte4, "muerte4.wav")
	#pragma GE_Documentation(SonidoMuerte4, "Fichero de sonido .WAV para muerte del jugador")

	char *SonidoMuerte1_F;
	#pragma GE_DefaultValue(SonidoMuerte1_F, "muerte1_f.wav")
	#pragma GE_Documentation(SonidoMuerte1_F, "Fichero de sonido .WAV para muerte de la jugadora")

	char *SonidoMuerte2_F;
	#pragma GE_DefaultValue(SonidoMuerte2_F, "muerte2_f.wav")
	#pragma GE_Documentation(SonidoMuerte2_F, "Fichero de sonido .WAV para muerte de la jugadora")

	char *SonidoMuerte3_F;
	#pragma GE_DefaultValue(SonidoMuerte3_F, "muerte3_f.wav")
	#pragma GE_Documentation(SonidoMuerte3_F, "Fichero de sonido .WAV para muerte de la jugadora")

	char *SonidoMuerte4_F;
	#pragma GE_DefaultValue(SonidoMuerte4_F, "muerte4_f.wav")
	#pragma GE_Documentation(SonidoMuerte4_F, "Fichero de sonido .WAV para muerte de la jugadora")

	char *SonidoSalto;
	#pragma GE_DefaultValue(SonidoSalto, "saltar.wav")
	#pragma GE_Documentation(SonidoSalto, "Fichero de sonido .WAV para salto del jugador")

	char *SonidoSalto_F;
	#pragma GE_DefaultValue(SonidoSalto_F, "saltar_f.wav")
	#pragma GE_Documentation(SonidoSalto_F, "Fichero de sonido .WAV para salto de la jugadora")

	char *CogerSalud;
	#pragma GE_DefaultValue(CogerSalud, "coger_vida.wav")
	#pragma GE_Documentation(CogerSalud, "Fichero de sonido .WAV para aumento de salud del jugador")

	char *CogerSalud_F;
	#pragma GE_DefaultValue(CogerSalud_F, "coger_vida_f.wav")
	#pragma GE_Documentation(CogerSalud_F, "Fichero de sonido .WAV para aumento de salud de la jugadora")

#pragma GE_Origin(Origin)
}   ConfigSonidosJug;



// ==========================
// Entidad 'Fx_Niebla'
// ==========================
// Entidad para aplicar niebla en el horizonte
#pragma GE_Type("Item.ico")
typedef struct  Fx_Niebla
{
#pragma GE_Private
	geVec3d		Origin;
#pragma GE_Published

	geBoolean   Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Niebla activa ?. True=Si False=No")

	float	DistIncioNiebla;
	#pragma GE_DefaultValue(DistIncioNiebla, "200.0")
	#pragma GE_Documentation(DistIncioNiebla, "Distancia del comienzo de la niebla. Entre 1 y 5000")

	float	DistFinalNiebla;
	#pragma GE_DefaultValue(DistFinalNiebla, "1300.0")
	#pragma GE_Documentation(DistFinalNiebla, "Distancia del final de la niebla. Entre 1 y 5000")

    GE_RGBA	Color;
	#pragma GE_DefaultValue(Color, "255.0 255.0 255.0")
	#pragma GE_Documentation(Color, "Color de la niebla")

	geBoolean   RenderTrasNiebla;
	#pragma GE_DefaultValue(RenderTrasNiebla, "False")
	#pragma GE_Documentation(RenderTrasNiebla, "¿ Calcular geometría detrás de la niebla ?. True=Si False=No")

#pragma GE_Origin(Origin)
}   Fx_Niebla;



// ==========================
// Entidad 'ConfigEnemigos'
// ==========================
// Entidad para configurar datos generales de los enemigos
#pragma GE_Type("Item.ico")
typedef struct  ConfigEnemigos
{
#pragma GE_Private
	geVec3d		Origin;
#pragma GE_Published
	int		Brillo_enemigo_1;
	#pragma GE_DefaultValue(Brillo_enemigo_1, "200")
	#pragma GE_Documentation(Brillo_enemigo_1, "Nivel de brillo del enemigo 1. (De 0 a 255)")

	int		Brillo_enemigo_2;
	#pragma GE_DefaultValue(Brillo_enemigo_2, "200")
	#pragma GE_Documentation(Brillo_enemigo_2, "Nivel de brillo del enemigo 2. (De 0 a 255)")

	int		Brillo_enemigo_3;
	#pragma GE_DefaultValue(Brillo_enemigo_3, "200")
	#pragma GE_Documentation(Brillo_enemigo_3, "Nivel de brillo del enemigo 3. (De 0 a 255)")

	int		Brillo_enemigo_4;
	#pragma GE_DefaultValue(Brillo_enemigo_4, "200")
	#pragma GE_Documentation(Brillo_enemigo_4, "Nivel de brillo del enemigo 4. (De 0 a 255)")

	int		Brillo_enemigo_5;
	#pragma GE_DefaultValue(Brillo_enemigo_5, "200")
	#pragma GE_Documentation(Brillo_enemigo_5, "Nivel de brillo del enemigo 5. (De 0 a 255)")

	int		Brillo_enemigo_6;
	#pragma GE_DefaultValue(Brillo_enemigo_6, "200")
	#pragma GE_Documentation(Brillo_enemigo_6, "Nivel de brillo del enemigo 6. (De 0 a 255)")

	int		Brillo_enemigo_7;
	#pragma GE_DefaultValue(Brillo_enemigo_7, "200")
	#pragma GE_Documentation(Brillo_enemigo_7, "Nivel de brillo del enemigo 7. (De 0 a 255)")

	int		Brillo_enemigo_8;
	#pragma GE_DefaultValue(Brillo_enemigo_8, "200")
	#pragma GE_Documentation(Brillo_enemigo_8, "Nivel de brillo del enemigo 8. (De 0 a 255)")

	geBoolean   Sangre_charco_1;
	#pragma GE_DefaultValue(Sangre_charco_1, "True")
	#pragma GE_Documentation(Sangre_charco_1, "Ver charco de sangre al morir enemigo 1. True=Si False=No")

	geBoolean   Sangre_charco_2;
	#pragma GE_DefaultValue(Sangre_charco_2, "True")
	#pragma GE_Documentation(Sangre_charco_2, "Ver charco de sangre al morir enemigo 2. True=Si False=No")

	geBoolean   Sangre_charco_3;
	#pragma GE_DefaultValue(Sangre_charco_3, "True")
	#pragma GE_Documentation(Sangre_charco_3, "Ver charco de sangre al morir enemigo 3. True=Si False=No")

	geBoolean   Sangre_charco_4;
	#pragma GE_DefaultValue(Sangre_charco_4, "True")
	#pragma GE_Documentation(Sangre_charco_4, "Ver charco de sangre al morir enemigo 4. True=Si False=No")

	geBoolean   Sangre_charco_5;
	#pragma GE_DefaultValue(Sangre_charco_5, "True")
	#pragma GE_Documentation(Sangre_charco_5, "Ver charco de sangre al morir enemigo 5. True=Si False=No")

	geBoolean   Sangre_charco_6;
	#pragma GE_DefaultValue(Sangre_charco_6, "True")
	#pragma GE_Documentation(Sangre_charco_6, "Ver charco de sangre al morir enemigo 6. True=Si False=No")

	geBoolean   Sangre_charco_7;
	#pragma GE_DefaultValue(Sangre_charco_7, "True")
	#pragma GE_Documentation(Sangre_charco_7, "Ver charco de sangre al morir enemigo 7. True=Si False=No")

	geBoolean   Sangre_charco_8;
	#pragma GE_DefaultValue(Sangre_charco_8, "True")
	#pragma GE_Documentation(Sangre_charco_8, "Ver charco de sangre al morir enemigo 8. True=Si False=No")

	int	Transparencia_1;
	#pragma GE_DefaultValue( Transparencia_1, "255" )
	#pragma GE_Documentation( Transparencia_1, "Nivel de transparencia para enemigo 1 (De 0 a 255)" )

	int	Transparencia_2;
	#pragma GE_DefaultValue( Transparencia_2, "255" )
	#pragma GE_Documentation( Transparencia_2, "Nivel de transparencia para enemigo 2 (De 0 a 255)" )

	int	Transparencia_3;
	#pragma GE_DefaultValue( Transparencia_3, "255" )
	#pragma GE_Documentation( Transparencia_3, "Nivel de transparencia para enemigo 3 (De 0 a 255)" )

	int	Transparencia_4;
	#pragma GE_DefaultValue( Transparencia_4, "255" )
	#pragma GE_Documentation( Transparencia_4, "Nivel de transparencia para enemigo 4 (De 0 a 255)" )

	int	Transparencia_5;
	#pragma GE_DefaultValue( Transparencia_5, "255" )
	#pragma GE_Documentation( Transparencia_5, "Nivel de transparencia para enemigo 5 (De 0 a 255)" )

	int	Transparencia_6;
	#pragma GE_DefaultValue( Transparencia_6, "255" )
	#pragma GE_Documentation( Transparencia_6, "Nivel de transparencia para enemigo 6 (De 0 a 255)" )

	int	Transparencia_7;
	#pragma GE_DefaultValue( Transparencia_7, "255" )
	#pragma GE_Documentation( Transparencia_7, "Nivel de transparencia para enemigo 7 (De 0 a 255)" )

	int	Transparencia_8;
	#pragma GE_DefaultValue( Transparencia_8, "255" )
	#pragma GE_Documentation( Transparencia_8, "Nivel de transparencia para enemigo 8 (De 0 a 255)" )

	int Sombra_1;
	#pragma GE_DefaultValue(Sombra_1, "1")
	#pragma GE_Documentation(Sombra_1, "Tipo de sombra para enemigo 1. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	int Sombra_2;
	#pragma GE_DefaultValue(Sombra_2, "1")
	#pragma GE_Documentation(Sombra_2, "Tipo de sombra para enemigo 2. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	int Sombra_3;
	#pragma GE_DefaultValue(Sombra_3, "1")
	#pragma GE_Documentation(Sombra_3, "Tipo de sombra para enemigo 3. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	int Sombra_4;
	#pragma GE_DefaultValue(Sombra_4, "1")
	#pragma GE_Documentation(Sombra_4, "Tipo de sombra para enemigo 4. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	int Sombra_5;
	#pragma GE_DefaultValue(Sombra_5, "1")
	#pragma GE_Documentation(Sombra_5, "Tipo de sombra para enemigo 5. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	int Sombra_6;
	#pragma GE_DefaultValue(Sombra_6, "1")
	#pragma GE_Documentation(Sombra_6, "Tipo de sombra para enemigo 6. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	int Sombra_7;
	#pragma GE_DefaultValue(Sombra_7, "1")
	#pragma GE_Documentation(Sombra_7, "Tipo de sombra para enemigo 7. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	int Sombra_8;
	#pragma GE_DefaultValue(Sombra_8, "1")
	#pragma GE_Documentation(Sombra_8, "Tipo de sombra para enemigo 8. (0=Sin sombra, 1=Círculo, 2=Dinámica)")

	int	Render_distancia_max_1;
	#pragma GE_DefaultValue(Render_distancia_max_1, "0")
	#pragma GE_Documentation(Render_distancia_max_1, "Distancia máxima para calcular 'render' de enemigo 1 (0 sin distancia)")

	int	Render_distancia_max_2;
	#pragma GE_DefaultValue(Render_distancia_max_2, "0")
	#pragma GE_Documentation(Render_distancia_max_2, "Distancia máxima para calcular 'render' de enemigo 2 (0 sin distancia)")

	int	Render_distancia_max_3;
	#pragma GE_DefaultValue(Render_distancia_max_3, "0")
	#pragma GE_Documentation(Render_distancia_max_3, "Distancia máxima para calcular 'render' de enemigo 3 (0 sin distancia)")

	int	Render_distancia_max_4;
	#pragma GE_DefaultValue(Render_distancia_max_4, "0")
	#pragma GE_Documentation(Render_distancia_max_4, "Distancia máxima para calcular 'render' de enemigo 4 (0 sin distancia)")

	int	Render_distancia_max_5;
	#pragma GE_DefaultValue(Render_distancia_max_5, "0")
	#pragma GE_Documentation(Render_distancia_max_5, "Distancia máxima para calcular 'render' de enemigo 5 (0 sin distancia)")

	int	Render_distancia_max_6;
	#pragma GE_DefaultValue(Render_distancia_max_6, "0")
	#pragma GE_Documentation(Render_distancia_max_6, "Distancia máxima para calcular 'render' de enemigo 6 (0 sin distancia)")

	int	Render_distancia_max_7;
	#pragma GE_DefaultValue(Render_distancia_max_7, "0")
	#pragma GE_Documentation(Render_distancia_max_7, "Distancia máxima para calcular 'render' de enemigo 7 (0 sin distancia)")

	int	Render_distancia_max_8;
	#pragma GE_DefaultValue(Render_distancia_max_8, "0")
	#pragma GE_Documentation(Render_distancia_max_8, "Distancia máxima para calcular 'render' de enemigo 8 (0 sin distancia)")

#pragma GE_Origin(Origin)
}   ConfigEnemigos;



// ==========================
// Entidad 'Marcador'
// ==========================
// Entidad para indicadores del marcador HUD del jugador
#pragma GE_Type("Item.ico")
typedef struct  Marcador
{
#pragma GE_Private
	
#pragma GE_Published

	geVec3d		Origin;

	geBoolean   Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Configuración activa ?. True=Si False=No")

	geVec3d		Vidas_XY;
	#pragma GE_DefaultValue(Vidas_XY, "10 -65 1")
	#pragma GE_Documentation(Vidas_XY, "Posición indicador de las vidas del jugador")

	geVec3d		Salud_XY;
	#pragma GE_DefaultValue(Salud_XY, "10 -36 1")
	#pragma GE_Documentation(Salud_XY, "Posición indicador de salud del jugador")

	geVec3d		Armadura_XY;
	#pragma GE_DefaultValue(Armadura_XY, "200 -36 1")
	#pragma GE_Documentation(Armadura_XY, "Posición indicador de la armadura del jugador")

	geVec3d		Armas_XY;
	#pragma GE_DefaultValue(Armas_XY, "390 -54 1")
	#pragma GE_Documentation(Armas_XY, "Posición indicador de armas del jugador")

	geVec3d		Puntuacion_XY;
	#pragma GE_DefaultValue(Puntuacion_XY, "-460 4 0")
	#pragma GE_Documentation(Puntuacion_XY, "Posición indicador de puntuacion del jugador")

	geVec3d		Record_XY;
	#pragma GE_DefaultValue(Record_XY, "10 4 0")
	#pragma GE_Documentation(Record_XY, "Posición indicador de récord del jugador")

	geVec3d		Inventario_XY;
	#pragma GE_DefaultValue(Inventario_XY, "-223 -235 1")
	#pragma GE_Documentation(Inventario_XY, "Posición indicador del inventario del jugador")

	geVec3d		Acciones_XY;
	#pragma GE_DefaultValue(Acciones_XY, "-397 -245 0")
	#pragma GE_Documentation(Acciones_XY, "Posición de la lista de acciones")

	geVec3d		Dinero_XY;
	#pragma GE_DefaultValue(Dinero_XY, "10 40 0")
	#pragma GE_Documentation(Dinero_XY, "Posición del indicador de dinero del jugador")

	geVec3d		InventarioDesc_XY;
	#pragma GE_DefaultValue(InventarioDesc_XY, "-300 -440 1")
	#pragma GE_Documentation(InventarioDesc_XY, "Posición indicador descripción de objetos del inventario")

	geVec3d		PanelObjeto_XY;
	#pragma GE_DefaultValue(PanelObjeto_XY, "10 -320 0")
	#pragma GE_Documentation(PanelObjeto_XY, "Posición del panel de objeto 'ItemObject'")

	geVec3d		VidasNum_XY;
	#pragma GE_DefaultValue(VidasNum_XY, "10 75 0")
	#pragma GE_Documentation(VidasNum_XY, "Posición del contador numérico de vidas del jugador")

	geVec3d		BanderaLleva_XY;
	#pragma GE_DefaultValue(BanderaLleva_XY, "-128 100 0")
	#pragma GE_Documentation(BanderaLleva_XY, "Posición del indicador de llevar la bandera")

	geVec3d		PanelFrags_XY;
	#pragma GE_DefaultValue(PanelFrags_XY, "10 -352 0")
	#pragma GE_Documentation(PanelFrags_XY, "Posición del panel indicador de Frags de los jugadores")

	geBoolean	Sangre_salud;
	#pragma GE_DefaultValue(Sangre_salud, "False")
	#pragma GE_Documentation(Sangre_salud, "Ver sangre en pantalla al perder salud. True=Si False=No")

	geVec3d		PanelChat_XY;
	#pragma GE_DefaultValue(PanelChat_XY, "320 -180 0")
	#pragma GE_Documentation(PanelChat_XY, "Posición de la ventana de chat en juegos online")

	geVec3d		Radar_XY;
	#pragma GE_DefaultValue(Radar_XY, "-220 20 0")
	#pragma GE_Documentation(Radar_XY, "Posición del radar del jugador")

	geVec3d		ConsolaSup_XY;
	#pragma GE_DefaultValue(ConsolaSup_XY, "120 16 1")
	#pragma GE_Documentation(ConsolaSup_XY, "Posición de la consola superior")

	geVec3d		Tecla_Accion_XY;
	#pragma GE_DefaultValue(Tecla_Accion_XY, "-470 -140 1")
	#pragma GE_Documentation(Tecla_Accion_XY, "Posición indicador de tecla 'Acción'")

	geVec3d		Barra_Salud_XY;
	#pragma GE_DefaultValue(Barra_Salud_XY, "90 -132 0")
	#pragma GE_Documentation(Barra_Salud_XY, "Posición de la barra de salud del jugador")
	
	geVec3d		Barra_Escudo_XY;
	#pragma GE_DefaultValue(Barra_Escudo_XY, "90 -90 0")
	#pragma GE_Documentation(Barra_Escudo_XY, "Posición de la barra de escudo del jugador")

#pragma GE_Origin(Origin)
}   Marcador;



// ==========================
// Entidad 'AccionMenu'
// ==========================
// Entidad para definir nuevas acciones o modificar las que hay por defecto
#pragma GE_Type("Item.ico")
typedef struct  AccionMenu
{
#pragma GE_Private
	geVec3d		Origin;
#pragma GE_Published

	geBoolean   Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Entidad activa ? True=Si False=No")

	int	Num_accion;
	#pragma GE_DefaultValue( Num_accion, "1" )
	#pragma GE_Documentation( Num_accion, "Número de acción (entre 1 y 8)" )

	char *Verbo;
	#pragma GE_DefaultValue(Verbo, "Leer")
	#pragma GE_Documentation(Verbo, "Texto que define la acción")

#pragma GE_Origin(Origin)
}   AccionMenu;



// ==========================
// Entidad 'MarcadorBarra'
// ==========================
// Entidad para configurar las barras indicadoras del HUD
#pragma GE_Type("Item.ico")
typedef struct  MarcadorBarra
{
#pragma GE_Private
	geVec3d		Origin;
#pragma GE_Published

	geBoolean   Activada;
	#pragma GE_DefaultValue(Activada, "True")
	#pragma GE_Documentation(Activada, "¿ Activada al dar comienzo el nivel ?. True=Si False=No")

	geBoolean   Visible;
	#pragma GE_DefaultValue(Visible, "True")
	#pragma GE_Documentation(Visible, "¿ Barra visible al dar comienzo el nivel ?. True=Si False=No")

	geBoolean   Tipo_barra;
	#pragma GE_DefaultValue(Tipo_barra, "True")
	#pragma GE_Documentation(Tipo_barra, "Tipo de barra. True=Horizontal False=Vertical")

	int	Num_barra;
	#pragma GE_DefaultValue( Num_barra, "1" )
	#pragma GE_Documentation( Num_barra, "Número de barra (entre 1 y 10)" )

	geVec3d	Posicion_XY;
	#pragma GE_DefaultValue(Posicion_XY, "10 80 1")
	#pragma GE_Documentation(Posicion_XY, "Posición de la barra en pantalla. (Sólo X Y)")

	int		X_llena;
	#pragma GE_DefaultValue(X_llena, "163")
	#pragma GE_Documentation(X_llena, "Coordenada X de la barra horizontal llena.")
	
	int		X_vacia;
	#pragma GE_DefaultValue(X_vacia, "4")
	#pragma GE_Documentation(X_vacia, "Coordenada X de la barra horizontal vacía.")

	int		Y_llena;
	#pragma GE_DefaultValue(Y_llena, "4")
	#pragma GE_Documentation(Y_llena, "Coordenada Y de la barra vertical llena")
	
	int		Y_vacia;
	#pragma GE_DefaultValue(Y_vacia, "163")
	#pragma GE_Documentation(Y_vacia, "Coordenada Y de la barra vertical vacía.")

	int		Valor;
	#pragma GE_DefaultValue(Valor, "1")
	#pragma GE_Documentation(Valor, "Valor inicial de la barra. (mínimo 1)")

	geBoolean  Llenar_Vaciar;
	#pragma GE_DefaultValue(Llenar_Vaciar, "True")
	#pragma GE_Documentation(Llenar_Vaciar, "¿ Llenar o vaciar con el paso del tiempo ?. True=Llenar False=Vaciar")

	geBoolean  Tiempo;
	#pragma GE_DefaultValue(Tiempo, "True")
	#pragma GE_Documentation(Tiempo, "¿ Llenar/vaciar con el paso del tiempo ?. True=Si False=No")

	float	Retardo;
	#pragma GE_DefaultValue(Retardo, "0.5")
	#pragma GE_Documentation(Retardo, "Velocidad de llenado/vaciado. (En segundos)")

	char *Comandos_Llena;
	#pragma GE_DefaultValue(Comandos_Llena, "")
	#pragma GE_Documentation(Comandos_Llena, "Nombre del fichero de comandos a lanzar cuando se llene la barra.")

	char *Comandos_Vacia;
	#pragma GE_DefaultValue(Comandos_Vacia, "")
	#pragma GE_Documentation(Comandos_Vacia, "Nombre del fichero de comandos a lanzar cuando se vacie la barra.")

#pragma GE_Origin(Origin)
}   MarcadorBarra;



// ==========================
// Entidad 'EquipoOnline'
// ==========================
// Entidad para definir posición de inicio de jugadores online de un mismo equipo, entre otros parámetros
#pragma GE_Type("Item.ico")
typedef struct  EquipoOnline
{
#pragma GE_Published
    geVec3d	Origin;
	#pragma GE_Documentation(Origin, "Posición X Y Z")

	geBoolean Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Entidad activa ? True=Si False=No")

	char *Equipo;
	#pragma GE_DefaultValue(Equipo, "A" )
	#pragma GE_Documentation(Equipo, "Letra de equipo online (entre A y H)")

	geVec3d	Reaparicion_Pos_2;
	#pragma GE_DefaultValue(Reaparicion_Pos_2, "0 0 0")
	#pragma GE_Documentation(Reaparicion_Pos_2, "Posición 2 de reaparición de jugadores")

	geVec3d	Reaparicion_Pos_3;
	#pragma GE_DefaultValue(Reaparicion_Pos_3, "0 0 0")
	#pragma GE_Documentation(Reaparicion_Pos_3, "Posición 3 de reaparición de jugadores")

	geBoolean Reaparicion_azar;
	#pragma GE_DefaultValue(Reaparicion_azar, "False")
	#pragma GE_Documentation(Reaparicion_azar, "Posición al azar de reaparición de jugadores. True=Si False=No")

#pragma GE_Origin(Origin)
}   EquipoOnline;



// ==========================
// Entidad 'ConfigPersonaje'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ConfigPersonaje
{
#pragma GE_Private
	geVec3d		Origin;
#pragma GE_Published

	geBoolean   Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Entidad activa ? True=Si False=No")

	geBoolean   PersonajeOnline;
	#pragma GE_DefaultValue(PersonajeOnline, "False")
	#pragma GE_Documentation(PersonajeOnline, "True=Configura personaje online. False=Configura personaje offline")

	int		Num_personaje;
	#pragma GE_DefaultValue(Num_personaje, "1")
	#pragma GE_Documentation(Num_personaje, "Número de personaje a configurar")

	geBoolean   Masculino;
	#pragma GE_DefaultValue(Masculino, "True")
	#pragma GE_Documentation(Masculino, "True=Personaje masculino. False=Personaje femenino")

	float Ancho_bloqueo;
	#pragma GE_DefaultValue(Ancho_bloqueo, "30")
	#pragma GE_Documentation(Ancho_bloqueo, "Ancho de la caja de bloqueo (de pie)")

	float Alto_bloqueo;
	#pragma GE_DefaultValue(Alto_bloqueo, "195")
	#pragma GE_Documentation(Alto_bloqueo, "Alto de la caja de bloqueo (de pie)")

	float Ancho_bloqueo2;
	#pragma GE_DefaultValue(Ancho_bloqueo2, "45")
	#pragma GE_Documentation(Ancho_bloqueo2, "Ancho de la caja de bloqueo (agachado)")

	float Alto_bloqueo2;
	#pragma GE_DefaultValue(Alto_bloqueo2, "110")
	#pragma GE_Documentation(Alto_bloqueo2, "Alto de la caja de bloqueo (agachado)")

	int	Brillo;
	#pragma GE_DefaultValue(Brillo, "200")
	#pragma GE_Documentation(Brillo, "Nivel de brillo que se aplicará a este personaje. Entre 0 y 255")

	float Orientacion;
	#pragma GE_DefaultValue(Orientacion, "0")
	#pragma GE_Documentation(Orientacion, "Reorienta la vista del jugador al comenzar la partida (de 0 a 360 grados)")

	geBoolean   Agacharse_solido;
	#pragma GE_DefaultValue(Agacharse_solido, "True")
	#pragma GE_Documentation(Agacharse_solido, "True=Permite al jugador agacharse cerca de bloques 'solid'")

	int Sombra;
	#pragma GE_DefaultValue(Sombra, "1")
	#pragma GE_Documentation(Sombra, "Tipo de sombra para este personaje (0=Sin sombra, 1=Círculo, 2=Dinámica)")

#pragma GE_Origin(Origin)
}   ConfigPersonaje;




// ==========================
// Entidad 'ConfigRadar'
// ==========================
#pragma GE_Type("Item.ico")
typedef struct  ConfigRadar
{
#pragma GE_Private
	geVec3d		Origin;
#pragma GE_Published

	geBoolean   Activa;
	#pragma GE_DefaultValue(Activa, "True")
	#pragma GE_Documentation(Activa, "¿ Entidad activa ? True=Si False=No")

	int		Ancho;
	#pragma GE_DefaultValue(Ancho, "200")
	#pragma GE_Documentation(Ancho, "Tamaño del radar (en pixeles)")

	float Alcance;
	#pragma GE_DefaultValue(Alcance, "3000")
	#pragma GE_Documentation(Alcance, "Alcance del radar (en centímetros)")

    GE_RGBA	Color;
	#pragma GE_DefaultValue(Color, "255 255 255")
	#pragma GE_Documentation(Color, "Color del radar")

	float Transparencia_radar;
	#pragma GE_DefaultValue(Transparencia_radar, "250")
	#pragma GE_Documentation(Transparencia_radar, "Nivel de transparencia del radar (De 0 a 255)")

	float Transparencia_elementos;
	#pragma GE_DefaultValue(Transparencia_elementos, "200")
	#pragma GE_Documentation(Transparencia_elementos, "Nivel de transparencia de los elementos del radar (De 0 a 255)")

	geBoolean   Elem_bot_reduc;
	#pragma GE_DefaultValue(Elem_bot_reduc, "True")
	#pragma GE_Documentation(Elem_bot_reduc, "Tamaño reducido para elementos Bots. True=Si False=No")

	geBoolean   Elem_jug_reduc;
	#pragma GE_DefaultValue(Elem_jug_reduc, "True")
	#pragma GE_Documentation(Elem_jug_reduc, "Tamaño reducido para elementos Jugadores. True=Si False=No")

	geBoolean   Elem_com_reduc;
	#pragma GE_DefaultValue(Elem_com_reduc, "True")
	#pragma GE_Documentation(Elem_com_reduc, "Tamaño reducido para elementos Command. True=Si False=No")

	geBoolean   Elem_obj_reduc;
	#pragma GE_DefaultValue(Elem_obj_reduc, "True")
	#pragma GE_Documentation(Elem_obj_reduc, "Tamaño reducido para elementos ItemObject. True=Si False=No")

#pragma GE_Origin(Origin)
}   ConfigRadar;



// ==========================
// Declaración de funciones
// ==========================
geBoolean Recoge_Configuracion(geWorld *World);
geBoolean Recoge_DeathMatchStart(geWorld *World);
geBoolean Recoge_ConfigSonidosEne(geWorld *World);
geBoolean Recoge_ConfigSonidosJug(geWorld *World);
geBoolean Recoge_ItemHealth(geWorld *World);
geBoolean Recoge_ItemVida(geWorld *World);
#ifdef CODIGO_NAVWEB
geBoolean Recoge_ItemColision(geWorld *World);
#endif
geBoolean Recoge_Objetivo(geWorld *World);
geBoolean Recoge_ConfigPersonaje(geWorld *World);
geBoolean Recoge_ItemArmor(geWorld *World);
geBoolean Recoge_Fx_Niebla(geEngine *Engine, geWorld *World);
geBoolean Recoge_TeclaComandos(geWorld *World);
geBoolean Recoge_ConfigEnemigos(geWorld *World);
geBoolean Recoge_Marcador(geWorld *World);
geBoolean Recoge_AccionMenu(geWorld *World);
geBoolean Recoge_MarcadorBarra(geWorld *World, int ancho_resolucion, int alto_resolucion);
geBoolean Recoge_VolarJugador(geWorld *World, int ancho_resolucion, int alto_resolucion);
geBoolean Inicializa_barras_sistema(geWorld *World, int ancho_resolucion, int alto_resolucion);
geBoolean Recoge_EquipoOnline(geWorld *World);
geBoolean Recoge_ConfigRadar(geWorld *World);

#ifdef __cplusplus
}
#endif

#endif
