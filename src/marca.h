/*
 * marca.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Luk
 */

#ifndef MARCA_H_
#define MARCA_H_

#define QTY_MARCAS 4

typedef struct{
	int id;
	char descripcion[20];
	int isEmpty;
}Marca;

void mostrarMarca (Marca* marcas);
void mostrarMarcas (Marca marcas[], int tam);
int cargarDescMarca(int id, Marca marcas[], int tam, char desc[]);

#endif /* MARCA_H_ */
