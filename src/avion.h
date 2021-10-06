/*
 * avion.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Luk
 */

#ifndef AVION_H_
#define AVION_H_

#define QTY_AVIONES 10

typedef struct{
	int idAvion;
	char matricula[10];
	char fecha[15];
	int idViaje;
	int idMarca;
	int modelo;
	int cantAsientos;
	int isEmpty;
}Avion;

#include "Marca.h"
#include "Viaje.h"

int harcodearAviones(Avion* array);

int initAvion(Avion* array, int len);
int altaAvion(Avion* array, int len,int* id);
int findAvionByMatricula(Avion* list, int len, char* matricula);
int getEmptyIndex(Avion* array,int len);
int bajaAvion(Avion* array, int len, int id);
int modificarAvion(Avion* array,int len, int index);
int mostrarAvion(Avion* aAviones, char* descMarca, char* descViaje);
int mostrarAviones(Avion aAviones[], int len, Marca aMarca[], int lenMarca, Viaje aViaje[], int lenViaje);
int sortAvionesPorMatricula(Avion* list, int len, Marca* aMarca);

#endif /* AVION_H_ */
