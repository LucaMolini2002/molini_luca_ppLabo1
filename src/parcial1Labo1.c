/*
 ============================================================================
 Name        : parcial1Labo1.c
 Author      : Luca
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"
#include "marca.h"
#include "viaje.h"
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);

	Marca marcas[QTY_MARCAS]={
	{1000,"Boening",0},
	{1001,"Airbus",0},
	{1002,"ATR",0},
	{1003,"Bombardier",0}
	};

	Viaje viajes[QTY_VIAJES]={
	{100,"Salta",1462.5,0},
	{101,"Tucuman",1247.6,0},
	{102,"Neuquen",1139.4,0},
	{103,"Corrientes",670,0},
	{104,"Chubut",1735.8,0}
	};

	Avion aviones[QTY_AVIONES];

	int idAviones=1;
	char auxMatricula[10];
	int auxIndex;
	int opcion;


	if(initAvion(aviones, QTY_AVIONES)==1){
		opcion = menu();
		int contador;
		contador = harcodearAviones(aviones);
		idAviones = idAviones+contador;
	}

	do{
		switch(opcion)
		{
		case 1:
			altaAvion(aviones, QTY_AVIONES, &idAviones, marcas, viajes);
			break;
		case 2:
			mostrarAviones(aviones, QTY_AVIONES, marcas, QTY_MARCAS, viajes, QTY_VIAJES);
			printf("Ingrese matricula del avion a modificar:");
			getString(auxMatricula, 10);
			while(findAvionByMatricula(aviones, QTY_AVIONES, auxMatricula)==-2)
			{
				printf("\nLa matricula ingresada no existe\n");
				printf("Ingrese nuevamente matricula del avion a modificar:\n");
				getString(auxMatricula, 10);
			}
			auxIndex = findAvionByMatricula(aviones, QTY_AVIONES, auxMatricula);
			modificarAvion(aviones, QTY_AVIONES, auxIndex);
			break;
		case 3:
			mostrarAviones(aviones, QTY_AVIONES, marcas, QTY_MARCAS, viajes, QTY_VIAJES);
			printf("Ingrese matricula del avion a eliminar:");
			getString(auxMatricula, 10);
			while(findAvionByMatricula(aviones, QTY_AVIONES, auxMatricula)==-2)
			{
				printf("\nLa matricula ingresada no existe\n");
				printf("Ingrese nuevamente matricula del avion a modificar:\n");
				getString(auxMatricula, 10);
			}
			auxIndex = findAvionByMatricula(aviones, QTY_AVIONES, auxMatricula);
			if(auxIndex>=0 && bajaAvion(aviones, QTY_AVIONES, auxIndex)==1)
				printf("El avion se elimino con exito. \n");
			break;
		case 4:
			if(sortAvionesPorMatriculayMarca(aviones, QTY_AVIONES, marcas, QTY_MARCAS)==0)
			{
				mostrarAviones(aviones, QTY_AVIONES, marcas, QTY_MARCAS, viajes, QTY_VIAJES);
			}
			break;
		case 5:
			mostrarViajes(viajes, QTY_VIAJES);
			break;
		case 6:
			mostrarMarcas(marcas, QTY_MARCAS);
			break;
		case 7:
			mostrarAvionesBoening(aviones, QTY_AVIONES, marcas, QTY_MARCAS, viajes, QTY_VIAJES);
			break;
		case 8:
			mostrarAvionMarcaSelec(aviones, QTY_AVIONES, marcas, QTY_MARCAS, viajes, QTY_VIAJES);
			break;
		case 9:
			mostrarAvionesNeuquen(aviones, QTY_AVIONES, marcas, QTY_MARCAS, viajes, QTY_VIAJES);
			break;
		case 10:

			break;
		case 11:
			informarAsientosModeloSelec(aviones, QTY_AVIONES, marcas, QTY_MARCAS, viajes, QTY_VIAJES);
			break;
		}
		opcion = menu();

	}while(opcion<12);


	return EXIT_SUCCESS;
}


