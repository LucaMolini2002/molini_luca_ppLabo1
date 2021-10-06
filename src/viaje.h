/*
 * viaje.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Luk
 */

#ifndef VIAJE_H_
#define VIAJE_H_

#define QTY_VIAJES 5

typedef struct{
	int idViaje;
	char descripcion[25];
	float kms;
	int isEmpty;
}Viaje;

void mostrarViaje (Viaje* viajes);
void mostrarViajes (Viaje viajes[], int tam);

#endif /* VIAJE_H_ */
