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
int altaAvion(Avion* array, int len, int* id, Marca* aMarca, Viaje* aViaje);
int findAvionByMatricula(Avion* list, int len, char* matricula);
int getEmptyIndex(Avion* array,int len);
int bajaAvion(Avion* array, int len, int id);
int modificarAvion(Avion* array,int len, int index);
void mostrarAvion(Avion aAviones, char* descMarca, char* descViaje);
int mostrarAviones(Avion aAviones[], int len, Marca aMarca[], int lenMarca, Viaje aViaje[], int lenViaje);
int sortAvionesPorMatriculayMarca(Avion* list, int len, Marca* aMarca, int lenMarca);

//informes
void mostrarMatriculayMarca(Avion avion, char* descMarca);
void mostrarAvionesBoening(Avion* aAviones, int lenAviones, Marca* aMarcas, int lenMarcas, Viaje* aViajes, int lenViajes);
void mostrarAvionMarcaSelec(Avion* aAviones, int lenAviones, Marca* aMarcas, int lenMarcas, Viaje* aViajes, int lenViajes);
void mostrarAvionesNeuquen(Avion* aAviones, int lenAviones, Marca* aMarcas, int lenMarcas, Viaje* aViajes, int lenViajes);
void informarAsientosModeloSelec(Avion* aAviones, int lenAviones, Marca* aMarcas, int lenMarcas, Viaje* aViajes, int lenViajes);

#endif /* AVION_H_ */
