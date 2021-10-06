/*
 * marca.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Luk
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

void mostrarMarca (Marca* marcas){
	if(marcas!=NULL && marcas->isEmpty==0)
	{
		printf("  %d      %10s\n", marcas->id, marcas->descripcion);
	}
}

void mostrarMarcas (Marca marcas[], int tam){
    printf(" Id         Marca\n\n");
    for(int i=0; i < tam; i++){
        mostrarMarca(&marcas[i]);
    }
    printf("\n");
}

