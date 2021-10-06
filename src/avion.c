/*
 * avion.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Luk
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"
#include "marca.h"
#include "viaje.h"
#include "utn.h"

static void getDescripcionMarca(Marca arrayMarca[], int tamMarca, int buscar, char* descMarca);
static void getDescripcionViaje(Viaje arrayViaje[], int tamViaje, int buscar, char* descViaje);

/* * \brief  Indica si un avion esta vacio o ocupado.
 *  \param Avion* array
 *  \param len int longitud del array
 *  \return int Return (-1) si hay error (longitud invalida o puntero NULL) - (0) si esta bien
 */
int initAvion(Avion* array, int len){
	int retorno=-1;
	if(array!=NULL && len>0)
	{
		retorno=1;
		for(int i=0;i<len;i++)
		{
			array[i].isEmpty=1;
		}
	}
	return retorno;
}

/*
 * *\brief harcodea avion
 *  \param avion
 *  \return void
 */
int harcodearAviones(Avion* array){
	int contador=0;

	Avion empleados[] =
	{
	};

	for(int i=0;i<5;i++){
		array[i]=empleados[i];
		contador++;
	}
	return contador;
}
/*
 *  \brief da de alta un acion
 *  \param eEmpleados* array
 *  \param int len longitud del array
 *  \param int* id puntero al id del empleado
 *  \return -1 si hay error y 0 si esta bien
 */
int altaAvion(Avion* array, int len,int* id){
	int retorno=-1;
	Avion buffer;
	int auxIndexAvion;

	auxIndexAvion = getEmptyIndex(array, len);
	if(auxIndexAvion>=0)
	{
		if(array!=NULL && len>0 && auxIndexAvion<len && auxIndexAvion>=0 && array[auxIndexAvion].isEmpty==1)
		{
			printf("Ingrese matricula:");
			getString(buffer.matricula, 10);
			printf("Ingrese Fecha dd/mm/aaa: ");
			getString(buffer.fecha, 15);
			utn_getNumero(&buffer.modelo,  "Ingrese modelo: (año de fabricacion)", "Error, ingrese nuevamente el modelo", 1900, 2022, 2);
 			utn_getNumero(&buffer.idMarca, "Ingrese el numero correspondiente a su marca: 1000- Boening\n1001- Airbus\n1002- ATR\n1003- Bombardier", "Error, ingrese nuevamente la marca", 1000, 1003, 2);
			utn_getNumero(&buffer.idViaje, "Ingrese el numero correspondiente a su viaje: \n100-Salta\n101-Tucuman\n102-Neuquen\n103-Corrientes\n104-Chubut", "Error, vuelva a intentarlo", 100, 104, 2);
			utn_getNumero(&buffer.cantAsientos, "Ingrese la cantidad de asientos del avion","Error, ingrese una cantidad valida", 1, 5000, 2);

			retorno=0;
			buffer.idAvion= *id;
			buffer.isEmpty=0;
			array[auxIndexAvion]=buffer;
			(*id)++;
			printf("Los datos se cargaron con exito.\n");
		}
	}
	else
	{
		printf("No hay mas espacios disponibles.\n");
	}
	return retorno;
}
/*
 *  \brief busca un avion por id
 *  \param Avion* list
 *  \param int len longitud del array
 *  \param int id legajo del avion
 *  \return -1 si hay error o i, con el id del avion buscado
 */
int findAvionByMatricula(Avion* list, int len, char* matricula)
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			if(strcmp(list[i].matricula,matricula)==0)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/*
 *  \brief busca un avion vacio
 *  \param Avion* list
 *  \param int len longitud del array
 *  \return -1 si hay error o i, con el id del avion buscado
 */
int getEmptyIndex(Avion* array,int len)
{
	int retorno=0;
	int i;
	if(array!=NULL && len>0)
	{
		retorno=0;
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/*
 *  \brief da de baja un avion
 *  \param Avion* list
 *  \param int len longitud del array
 *  \param int id legajo del avion
 *  \return -1 si hay error o 0 si salio bien
 */
int bajaAvion(Avion* array, int len, int id)
{
	int retorno=-1;
	char charOpcion;
	Avion buffer;
	if(array[id].isEmpty==1){
		printf("No hay ningun avion con este id.");
	}
	if(array!=NULL&&len>0&&id<len&&id>=0&&array[id].isEmpty==0)
	{
		printf("Esta seguro de que quiere dar de baja al avion? s/n");
		fflush(stdin);
		scanf("%c", &charOpcion);
		if(charOpcion == 's')
		{
			retorno=0;
			buffer.isEmpty=1;
			array[id] = buffer;
			printf("\nEl avion se elimino con exito.");
		}
		else if(charOpcion == 'n')
		{
			printf("\nSe cancelo la baja de avion. ");
		}
	}
	return retorno;
}
/*
 *  \brief modifica un avion
 *  \param Avion* list
 *  \param int len longitud del array
 *  \param int indice indice del array avion
 *  \return -1 si hay error o 0 si salio bien
 */
int modificarAvion(Avion* array,int len, int index)
{
	int retorno=0;
	char charOpcion;
	int opcion;
	Avion buffer;
	if(array[index].isEmpty==1)
	{
		printf("El avion no existe.");
	}
	else
	{
		if(array!=NULL && len>0 && index<len && index>=0 )
		{
			printf("Esta seguro de que quiere de modificar el avion? s/n");
			fflush(stdin);
			scanf("%c", &charOpcion);
			if(charOpcion == 's')
			{
				utn_getNumero(&opcion, "Que desea cambiar?", "Error, elija una opcion valida", 1, 2, 2);
				switch(opcion){
				case 1:
					utn_getNumero(&buffer.modelo, "Ingrese modelo: (año de fabricacion)", "Error, ingrese nuevamente el modelo", 1900, 2022, 2);
					break;
				case 2:
					utn_getNumero(&buffer.idViaje, "Ingrese la cantidad de asientos del avion","Error, ingrese una cantidad valida", 1, 5000, 2);
					break;
				}

				retorno=1;
				buffer.idAvion=array[index].idAvion;
				buffer.isEmpty=0;
				array[index]=buffer;
				printf("El avion se modifico con exito! ");
			}
			else if(charOpcion == 'n')
			{
				printf("\nSe cancelo la modificacion del avion.");
			}
			else
			{
				printf("Error, ingrese una opcion valida. ");
			}
		}

	}
	return retorno;
}
/*
 *  \brief muestra un avion
 *  \param char* descMarca
 *  \param char* descViaje
 *  \return 0 si hay error o 1 si salio bien
 */
int mostrarAvion(Avion* aAviones, char* descMarca, char* descViaje){

	int retorno=0;
	if(aAviones != NULL && aAviones->isEmpty == 0)
	{
		retorno=1;
		printf("\n %d  %s %s %s  %s  %d  %d \n",
				aAviones->idAvion,
				aAviones->matricula,
				aAviones->fecha,
				descViaje,
				descMarca,
				aAviones->modelo,
				aAviones->cantAsientos);
	}

	return retorno;
}


/*
 *  \brief muestra todos los aviones
 *  \param Avion* aAviones
 *  \param int len
 *  \param Marca* aMarca
 *  \param int lenMarca
 *  \param Viaje* aViaje
 *  \param int lenViaje
 *  \return 0 si hay error o 1 si salio bien
 */
int mostrarAviones(Avion aAviones[], int len, Marca aMarca[], int lenMarca, Viaje aViaje[], int lenViaje)
{
	int retorno=-1;
	int i;
	char descripcionMarca[20];
	char descripcionVaje[25];

	if(aAviones != NULL && len > 0 )
	{
		printf("\nID  Matricula  Fecha  Viaje  Marca  Modelo CantidadDeAsientos");
		retorno=0;
		for(i=0;i<len;i++)
		{
			getDescripcionMarca(aMarca, lenMarca, aAviones[i].idMarca, descripcionMarca);
			getDescripcionViaje(aViaje, lenViaje, aAviones[i].idViaje, descripcionVaje);
			mostrarAvion(&aAviones[i], descripcionMarca, descripcionVaje);
		}
	}
	return retorno;
}

/*
 *  \brief Obtiene una desripcion segun el id
 *  \param Marca* arrayMarca[]
 *  \param int tamMarca longitud del array
 *  \param int buscar id a buscar
 *  \param char* descDepto donde se guardara la descripcion obtenida
 *  \return void
 */
static void getDescripcionMarca(Marca arrayMarca[], int tamMarca, int buscar, char* descMarca){
	int i;
	for(i=0; i<tamMarca; i++)
	{
		if(arrayMarca[i].id == buscar && arrayMarca->isEmpty == 0)
		{
			strcpy(descMarca,arrayMarca[i].descripcion);
		}
	}
}
/*
 *  \brief Obtiene una desripcion segun el id
 *  \param Viaje* arrayViaje[]
 *  \param int tamViaje longitud del array
 *  \param int buscar id a buscar
 *  \param char* descDepto donde se guardara la descripcion obtenida
 *  \return void
 */
static void getDescripcionViaje(Viaje arrayViaje[], int tamViaje, int buscar, char* descViaje){
	int i;
	for(i=0; i<tamViaje; i++)
	{
		if(arrayViaje[i].idViaje == buscar && arrayViaje->isEmpty == 0)
		{
			strcpy(descViaje,arrayViaje[i].descripcion);
		}
	}
}
/*
 *  \brief ordena los empleados por matricula y marca
 *  \param Avion* list
 *  \param int len longitud del array
 *  \param Marca* aMarca[]
 *  \param lenDepto longitud del array depto
 *  \return -1 si hay error o 0 si salio bien
 */
int sortAvionesPorMatricula(Avion* list, int len, Marca* aMarca)
{
	int retorno=-1;
	int flagSwap;
	int i;
	Avion bufferEntidad;
	if(list!=NULL && len>0)
	{
		retorno=0;
		do{
			flagSwap=0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(list[i].matricula,list[i+1].matricula,51)>0)
				{
					flagSwap=1;
					bufferEntidad=list[i];
					list[i]=list[i+1];
					list[i+1]=bufferEntidad;
				}
				else if(strncmp(list[i].matricula,list[i+1].matricula,51)==0)
				{
					if(strncmp(aMarca[i].descripcion,aMarca[i+1].descripcion,51)>0)
					{
						flagSwap=1;
						bufferEntidad=list[i];
						list[i]=list[i+1];
						list[i+1]=bufferEntidad;
					}
				}
			}
			len--;
		}while(flagSwap);
		printf("Aviones ordenados con exito!");
	}
	return retorno;
}

