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

/*
 * \brief muestra un viaje
 * \param Viaje* viajes array de viajes
 * \return void
 */
void mostrarViaje (Viaje* viajes){
	if(viajes!=NULL && viajes->isEmpty==0)
	{
		printf("| %d  | %-10s |\n", viajes->idViaje, viajes->descripcion);
	}
}
/*
 * \brief muestra todos los viajes
 * \param Viaje* viajes array de viajes
 * \param int tam longitud del array viajes
 * \return void
 */
void mostrarViajes (Viaje viajes[], int tam){
    printf("---------------------\n");
    printf("| ID   |   Viaje    |\n");
    printf("---------------------\n");
    for(int i=0; i < tam; i++){
        mostrarViaje(&viajes[i]);
    }
    printf("---------------------\n");
}
