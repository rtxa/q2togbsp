// File: ModelCtl.h -- Genesis Editor standard entity types
//
// Copyright  1999, WildTangent, Inc.
//

/****************************************************************************************/
/*  Descripci�n:                                                                        */
/*                                                                                      */
/*  Definici�n de clases de entidades.                                                  */
/*  Este fichero .h lo utiliza World Editor para crear las entidades que usa el         */
/*  programa Entidad 3D.                                                                */
/*                                                                                      */
/*  No modificar el contenido de este fichero .h para un correcto funcionamiento        */
/*  de Entidad 3D y World Editor.                                                       */
/*                                                                                      */
/*  Modificaciones para Entidad 3D:                                                     */
/*                                                                                      */
/*  Autor: Jordi P�rez                                                                  */
/*                                                                                      */
/*  Copyright (c) 2004 - 2017 Jordi P�rez; All rights reserved.                         */
/*                                                                                      */
/****************************************************************************************/

#ifndef	MODELCTL_H
#define	MODELCTL_H

#include	"genesis.h"

#pragma warning( disable : 4068 )

// ==========================
// Entidad 'ModelController'
// ==========================
#pragma GE_Type("modelctl.bmp")
typedef struct	ModelController
{
#pragma	GE_Private
	geFloat			LastTime;
	
#pragma GE_Published
	geWorld_Model *	Model;
	#pragma GE_Documentation(Model, "Selecciona un 'model' con animaci�n que ser� el bloque a mover")

	geBoolean   En_movimiento;
	#pragma GE_DefaultValue(En_movimiento, "True")
	#pragma GE_Documentation(En_movimiento, "� Bloque en movimiento al dar comienzo el nivel ? True=Si False=No")

	int Num_bloque;	
	#pragma GE_DefaultValue(Num_bloque, "1")
	#pragma GE_Documentation(Num_bloque, "N�mero de bloque (entre 1 y 255)")

	geVec3d Origin;
	#pragma GE_Origin(Origin)

}	ModelController;


#pragma warning( default : 4068 )

geBoolean	ModelCtl_Init(void);
geBoolean	ModelCtl_Reset(geWorld *World);
geBoolean	ModelCtl_Frame(geWorld *World, const geXForm3d *ViewPoint, geFloat Time);
geBoolean	ModelCtl_Shutdown(void);

#endif

