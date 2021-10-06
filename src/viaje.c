/*
 * viaje.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Luk
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaje.h"

void mostrarViaje (Viaje* viajes){
	if(viajes!=NULL && viajes->isEmpty==0)
	{
		printf("  %d      %10s\n", viajes->idViaje, viajes->descripcion);
	}
}

void mostrarViajes (Viaje viajes[], int tam){
    printf(" Id         Marca\n\n");
    for(int i=0; i < tam; i++){
        mostrarViaje(&viajes[i]);
    }
    printf("\n");
}
