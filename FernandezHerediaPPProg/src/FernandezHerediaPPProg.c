/*
 ============================================================================
 Name        : FernandezHerediaPPProg.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMN 4

typedef struct{
	int id;
	char procesador[20];
	char marca[20];
	float precio;

}eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char str[], char caracter);
void ordenarPorMarcayPrecio(eNotebook notebooks[], int tamN);

int main(void) {

	float precio = 200;
	float resul;
	char nombre[20];
	int cantidadCaracter;
	eNotebook listaN[TAMN] = {
			{1000, "AMD ryzen", "HP", 25000},
			{1001, "intel", "Compaq", 40000},
			{1002, "intel", "Compaq", 30000},
			{1003, "intel pentium", "Lenovo", 70000} };

	//Llamada a funciones:
	//1
	resul = aplicarDescuento(precio);
	//2
	strcpy(nombre, "Catalina");
	cantidadCaracter = contarCaracteres(nombre, 'a');
	//3
	ordenarPorMarcayPrecio(listaN, TAMN);

	//Print respuestas:
	//1
	printf("%.2f\n\n", resul );
	//2
	printf("Cantidad caracter %d\n\n", cantidadCaracter);
	//3
	printf("ID       Procesador        Marca      Precio\n\n");
	for(int i = 0; i <TAMN; i++)
	{
		printf("%d    %10s    %10s   $ %.2f\n", listaN[i].id, listaN[i].procesador, listaN[i].marca, listaN[i].precio);
	}



	return EXIT_SUCCESS;
}

float aplicarDescuento(float precio)
{
	float resultado;

	resultado = precio - (precio * 5 / (float)100);

	return resultado;
}

int contarCaracteres(char str[], char caracter)
{
	int contador = 0;

	for(int i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == caracter)
		{
			contador++;
		}
	}

	return contador;
}

void ordenarPorMarcayPrecio(eNotebook notebooks[], int tamN)
{
	eNotebook auxN;
	for(int i = 0; i < tamN-1; i++)
	{
		for(int j = i + 1; j < tamN; j++)
		{
			if(strcmp(notebooks[i].marca, notebooks[j].marca) > 0) //de menor a mayor marca
			{

				auxN = notebooks[i];
				notebooks[i] = notebooks[j];
				notebooks[j] = auxN;
			}
			else if(strcmp(notebooks[i].marca, notebooks[j].marca) == 0 && notebooks[i].precio < notebooks[j].precio) //de menor a mayor precio
			{
				auxN = notebooks[i];
				notebooks[i] = notebooks[j];
				notebooks[j] = auxN;
			}

		}
	}
}


