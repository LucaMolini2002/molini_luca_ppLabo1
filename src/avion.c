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
 *  \return int contador retorna cantidad de aviones, para asi saber el  ultimo id usado
 */
int harcodearAviones(Avion* array){
	int contador=0;

	Avion aviones[] =
	{
			{1,"ASD123","01/01/2002",101,1001,2002,500,0},
			{2,"QWE234","02/01/2002",102,1002,2007,700,0},
			{3,"FJK438","03/01/2002",104,1001,2002,900,0},
			{4,"HGJ432","04/01/2002",100,1003,2005,200,0},
			{5,"NFI912","05/01/2002",103,1000,1999,300,0},
			{6,"ELR594","06/01/2002",103,1000,2002,500,0},
			{7,"KOW239","07/01/2002",101,1002,2000,700,0},
			{8,"POP232","08/01/2002",100,1002,2004,900,0},
			{9,"KKJ013","09/01/2002",103,1003,2011,200,0},
		   {10,"LDS423","10/01/2002",101,1000,2003,600,0}


			/*{1,"a","01/01/2002",101,1001,2002,500,0},
			{2,"a","02/01/2002",102,1002,2007,700,0},
			{3,"a","03/01/2002",104,1001,2002,900,0},
			{4,"a","04/01/2002",100,1003,2005,200,0},
			{5,"a","05/01/2002",103,1000,1999,300,0},
			{6,"a","06/01/2002",103,1000,2002,500,0},
			{7,"a","07/01/2002",101,1002,2000,700,0},
			{8,"a","08/01/2002",100,1002,2004,900,0},
			{9,"a","09/01/2002",103,1003,2011,200,0},
			{10,"a","10/01/2002",101,1000,1996,300,0},
			*/
	};

	for(int i=0;i<10;i++){
		array[i]=aviones[i];
		contador++;
	}
	return contador;
}
/*
 *  \brief da de alta un avion
 *  \param Avion array  array de aviones
 *  \param int len longitud del array
 *  \param int* id en el que se guardara el id del avion ingresado
 *  \return -1 si hay error y 0 si esta bien
 */
int altaAvion(Avion* array, int len, int* id, Marca* aMarca, Viaje* aViaje){
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
			printf("Ingrese Fecha dd/mm/aaaa: ");
			getString(buffer.fecha, 15);
			utn_getNumero(&buffer.modelo, "Ingrese modelo: (año de fabricacion)", "Error, ingrese nuevamente el modelo\n", 1900, 2022, 2);
			mostrarMarcas(aMarca, 4);
 			utn_getNumero(&buffer.idMarca,"Ingrese el ID correspondiente a su marca:\n", "Error, vuelva a intentarlo\n", 1000, 1003, 2);
			mostrarViajes(aViaje, 5);
 			utn_getNumero(&buffer.idViaje,"Ingrese el Id correspondiente a su viaje:\n", "Error, vuelva a intentarlo\n", 100, 104, 2);
			utn_getNumero(&buffer.cantAsientos,"Ingrese la cantidad de asientos del avion","Error, ingrese una cantidad valida\n", 1, 5000, 2);

			retorno=0;
			buffer.idAvion= *id;
			buffer.isEmpty=0;
			array[auxIndexAvion]=buffer;
			(*id)++;
			printf("Los datos se cargaron con exito.\n");
		}
		else
		{
			printf("\nNo hay mas espacios disponibles.\n");
		}
	}

	return retorno;
}
/*
 *  \brief busca un avion por id
 *  \param Avion* list array avion
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
			else
			{
				retorno=-2;
			}
		}
	}
	return retorno;
}
/*
 *  \brief busca un avion vacio
 *  \param Avion* list array de avion
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
 *  \param Avion* list array avion
 *  \param int len longitud del array
 *  \param int id legajo del avion a dar de baja
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
 *  \param Avion* list array de aviones
 *  \param int len longitud del array aviones
 *  \param int indice indice del array avion a modificar
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
				utn_getNumero(&opcion, "Elija una opcion: \n"
									   "1- Cambiar modelo \n"
									   "2- Cambiar cantidad de asientos \n"
									   "3- Cambiar modelo y cantidad de asientos \n", "Error, elija una opcion valida", 1, 3, 2);
				switch(opcion){
				case 1:
					utn_getNumero(&buffer.modelo, "Ingrese modelo: (año de fabricacion)", "Error, ingrese nuevamente el modelo\n", 1900, 2022, 2);
					array[index].modelo=buffer.modelo;
					break;
				case 2:
					utn_getNumero(&buffer.cantAsientos, "Ingrese la cantidad de asientos del avion","Error, ingrese una cantidad valida\n", 1, 5000, 2);
					array[index].cantAsientos=buffer.cantAsientos;
					break;
				case 3:
					utn_getNumero(&buffer.modelo, "Ingrese modelo: (año de fabricacion)", "Error, ingrese nuevamente el modelo\n", 1900, 2022, 2);
					array[index].modelo=buffer.modelo;
					utn_getNumero(&buffer.cantAsientos, "Ingrese la cantidad de asientos del avion","Error, ingrese una cantidad valida\n", 1, 5000, 2);
					array[index].cantAsientos=buffer.cantAsientos;
					break;
				}

				retorno=1;

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
 *  \param Avion aAviones
 *  \param char* descMarca
 *  \param char* descViaje
 *  \return -1 si hay error o 0 si salio bien
 */
void mostrarAvion(Avion aAviones, char* descMarca, char* descViaje){

	printf("|  %-5d |  %-9s| %s | %-10s |  %-10s |    %-9d|       %d          |\n",
			aAviones.idAvion,
			aAviones.matricula,
			aAviones.fecha,
			descViaje,
			descMarca,
			aAviones.modelo,
			aAviones.cantAsientos);
}

/*
 *  \brief muestra todos los aviones
 *  \param Avion* aAviones array de tipo avion
 *  \param int len longitud del array aviones
 *  \param Marca* aMarca array de tipo marca
 *  \param int lenMarca longitud del array marca
 *  \param Viaje* aViaje array de tipo viaje
 *  \param int lenViaje longitud del array viaje
 *  \return -1 si hay error o 0 si salio bien
 */
int mostrarAviones(Avion aAviones[], int len, Marca aMarca[], int lenMarca, Viaje aViaje[], int lenViaje)
{
	int retorno=-1;
	int i;
	char descripcionMarca[20];
	char descripcionVaje[25];

	if(aAviones != NULL && len > 0 )
	{
		printf("\n-------------------------------------------------------------------------------------------------\n");

		printf("|  ID    | Matricula |   Fecha    |  Viaje     |   Marca     |   Modelo    | CantidadDeAsientos |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		retorno=0;
		for(i=0;i<len;i++)
		{
			getDescripcionMarca(aMarca, lenMarca, aAviones[i].idMarca, descripcionMarca);
			getDescripcionViaje(aViaje, lenViaje, aAviones[i].idViaje, descripcionVaje);
			mostrarAvion(aAviones[i], descripcionMarca, descripcionVaje);
		}
		printf("-------------------------------------------------------------------------------------------------\n");
	}
	return retorno;
}

/*
 *  \brief Obtiene una descripcion segun el id
 *  \param Marca* arrayMarca[] array del tipo marca
 *  \param int tamMarca longitud del array
 *  \param int buscar id a buscar
 *  \param char* descMarca donde se guardara la descripcion obtenida
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
 *  \brief Obtiene una descripcion segun el id
 *  \param Viaje* arrayViaje[] array de la escructura viaje
 *  \param int tamViaje longitud del array
 *  \param int buscar id a buscar id a buscar
 *  \param char* descViaje donde se guardara la descripcion obtenida
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
 *  \brief ordena los aviones por matricula y marca
 *  \param Avion* list array de aviones
 *  \param int len longitud del array avion
 *  \param Marca* aMarca[] array de marca
 *  \param int lenMarca longitud del array marca
 *  \return -1 si hay error o 0 si salio bien
 */
int sortAvionesPorMatriculayMarca(Avion* list, int len, Marca* aMarca, int lenMarca)
{
	int retorno=-1;
	int flagSwap;
	int i;
	char descripcionMarca[20];
	char descripcionMarcaSiguiente[20];
	Avion bufferEntidad;
	if(list!=NULL && len>0 )
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
				if(strncmp(list[i].matricula,list[i+1].matricula,21)>0)
				{
					flagSwap=1;
					bufferEntidad=list[i];
					list[i]=list[i+1];
					list[i+1]=bufferEntidad;
				}
				if(strncmp(list[i].matricula,list[i+1].matricula,21)==0)
				{
					getDescripcionMarca(aMarca, lenMarca, list[i].idMarca, descripcionMarca);
					getDescripcionMarca(aMarca, lenMarca, list[i+1].idMarca, descripcionMarcaSiguiente);
					if(strncmp(descripcionMarca,descripcionMarcaSiguiente,41)>0)
					{
						flagSwap=1;
						bufferEntidad=list[i];
						list[i]=list[i+1];
						list[i+1]=bufferEntidad;
					}
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

void mostrarAvionesBoening(Avion* aAviones, int lenAviones, Marca* aMarcas, int lenMarcas, Viaje* aViajes, int lenViajes){

	char descMarca[20];
	char descViaje[20];
	if(aAviones!=NULL && lenAviones>=0)
	{
		printf("\n-------------------------------------------------------------------------------------------------\n");

		printf("|  ID    | Matricula |   Fecha    |  Viaje     |   Marca     |   Modelo    | CantidadDeAsientos |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<lenAviones;i++)
		{
			if(aAviones[i].idMarca == 1000 && aAviones[i].isEmpty == 0)
			{
		    	getDescripcionMarca(aMarcas, lenMarcas, aAviones[i].idMarca, descMarca);
		    	getDescripcionViaje(aViajes, lenViajes, aAviones[i].idViaje, descViaje);
				mostrarAvion(aAviones[i], descMarca, descViaje);
			}
		}
		printf("-------------------------------------------------------------------------------------------------\n");
	}
}

void mostrarAvionMarcaSelec(Avion* aAviones, int lenAviones, Marca* aMarcas, int lenMarcas, Viaje* aViajes, int lenViajes){

    int idMarca;
	char descMarca[20];
	char descViaje[20];
    printf("*** Avion de una marca ***\n\n");

    mostrarMarcas(aMarcas,lenMarcas);
    utn_getNumero(&idMarca, "Seleccione una ID:", "Error, ID invalida", 1000, 1003, 3);

	printf("\n-------------------------------------------------------------------------------------------------\n");

	printf("|  ID    | Matricula |   Fecha    |  Viaje     |   Marca     |   Modelo    | CantidadDeAsientos |\n");
	printf("-------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < lenAviones; i++)
    {
        if(aAviones[i].idMarca == idMarca && aAviones[i].isEmpty == 0){
        	getDescripcionMarca(aMarcas, lenMarcas, aAviones[i].idMarca, descMarca);
        	getDescripcionViaje(aViajes, lenViajes, aAviones[i].idViaje, descViaje);
        	mostrarAvion(aAviones[i], descMarca, descViaje);
        }
    }
    printf("-------------------------------------------------------------------------------------------------\n");
}

void mostrarMatriculayMarca(Avion avion, char* descMarca){
	printf("| %s    | %s    |",avion.matricula,descMarca);
}

void mostrarAvionesNeuquen(Avion* aAviones, int lenAviones, Marca* aMarcas, int lenMarcas, Viaje* aViajes, int lenViajes){

	char descMarca[20];
	if(aAviones!=NULL && lenAviones>=0)
	{
		printf("-----------------------\n");

		printf("| Matricula | Marcas |\n");
		printf("-----------------------\n");
		for(int i=0;i<lenAviones;i++)
		{
			if(aAviones[i].idViaje == 102 && aAviones[i].isEmpty == 0)
			{
		    	getDescripcionMarca(aMarcas, lenMarcas, aAviones[i].idMarca, descMarca);
				mostrarMatriculayMarca(aAviones[i], descMarca);
			}
		}
		printf("\n-----------------------\n");
	}
}

void informarKmsMarcaATR(Avion* aAviones, int lenAviones, Marca* aMarcas, int lenMarcas, Viaje* aViajes, int lenViajes){
	//int acumKm=0;
	if(aAviones!=NULL && lenAviones>=0)
	{
		for(int i=0;i<lenAviones;i++)
		{
			if(aAviones[i].idMarca == 1002 && aAviones[i].isEmpty == 0)
			{
				//acumKm = acumKm + aAviones->
			}
		}
	}
}

void informarAsientosModeloSelec(Avion* aAviones, int lenAviones, Marca* aMarcas, int lenMarcas, Viaje* aViajes, int lenViajes){

    int modelo;
	int acumAsientos;

    mostrarAviones(aAviones, lenAviones, aMarcas, lenMarcas, aViajes, lenViajes);
    utn_getNumero(&modelo, "Ingrese un modelo:", "Error, modelo invalida", 1900, 2022, 3);

    for(int i = 0; i < lenAviones; i++)
    {
        if(aAviones[i].modelo == modelo && aAviones[i].isEmpty == 0){
        	acumAsientos = acumAsientos + aAviones[i].cantAsientos;
        }
    }
    printf("La marca seleccionada tiene un total de %d asientos.",acumAsientos);
}

