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


/*
 * \brief muestra una marca
 * \param Marca* marcas array de marca
 * \return void
 */
void mostrarMarca(Marca* marcas){
	if(marcas!=NULL && marcas->isEmpty==0)
	{
		printf("|%d  |  %-10s |\n", marcas->id, marcas->descripcion);
	}
}
/*
 * \brief muestra todas las marcas
 * \param Marca marcas[] array de marca
 * \param int tam longitud del array marca
 * \return void
 */
void mostrarMarcas (Marca marcas[], int tam){
    printf("----------------------\n");
    printf("| ID   |    Marca    |\n");
    printf("----------------------\n");
    for(int i=0; i < tam; i++){
    	mostrarMarca(&marcas[i]);
    }
    printf("----------------------\n");
}

