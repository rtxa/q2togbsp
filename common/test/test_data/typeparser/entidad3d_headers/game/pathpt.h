// pathpt.h -- Genesis Editor standard entity types
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
/*  Copyright (c) 2004 - 2015 Jordi Pérez; All rights reserved.                         */
/*                                                                                      */
/****************************************************************************************/

#ifndef	PATHPT_H
#define	PATHPT_H

#include "Genesis.h"

#pragma warning( disable : 4068 )

// ==========================
// Entidad 'PathPoint'
// ==========================
#pragma GE_Type("PathPt.bmp")
typedef struct PathPoint PathPoint;

#pragma GE_Type("PathPt.bmp")
typedef struct PathPoint {

	#pragma GE_Published

		geVec3d		origin;
		int         PathType;
		int			ActionType;
		float		Time;
		float		Dist;
		float		VelocityScale;
		PathPoint	*Next;
		geWorld_Model *MoveWithModel;
		int         Direction;
		int			ShootTimes;
		PathPoint	*WatchPoint;

	#pragma GE_Private
		geVec3d     Pos;

	#pragma GE_Origin(origin)

	#pragma GE_DefaultValue(PathType, "-1")
	#pragma GE_DefaultValue(ActionType, "-1")
	#pragma GE_DefaultValue(Direction, "1")

	#pragma GE_Documentation(Next, "Enlace al siguiente punto")
	#pragma GE_Documentation(PathType, "Tipo de ruta")
	#pragma GE_Documentation(ActionType, "Tipo de acción")
	#pragma GE_Documentation(Time, "Modificador del tipo de acción. Sólo aplicable a ciertas acciones. 0 por defecto.")
	#pragma GE_Documentation(Dist, "Modificador del tipo de acción. Sólo aplicable a ciertas acciones. 0 por defecto.")
	#pragma GE_Documentation(VelocityScale, "Modificador del tipo de acción. Sólo aplicable a ciertas acciones. 0 por defecto.")
	#pragma GE_Documentation(MoveWithModel,"Enlace a un 'model'. La entidad se moverá con este 'model'.")
	#pragma GE_Documentation(Direction, "Dirección de la acción: 1=Adelante, -1=Inversa, 0=Ambas")
} PathPoint;

#pragma warning( default : 4068 )

geBoolean PathPt_Startup(geWorld *World, geVFile *Fs);
geBoolean	PathPt_Reset(geWorld *World);
geBoolean	PathPt_Frame(geWorld *World, const geXForm3d *ViewPoint, geFloat Time);
geBoolean	PathPt_Shutdown(void);

#endif
