#ifndef MY_LIB
#define MY_LIB

// Se incluyen todas las librerias que se vayan a utilizar en el programa y por las funciones que este emplee
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos un tipo de dato que contenga los estados posibles
typedef enum{espera,izquierda,recto,derecha,error}estados_t;

// Definimos tipo de dato que va a manejar la maquina durante todo el proceso de transiciones
typedef struct {
	int p;
	char e;
	int p_set1;
	int p_set2;
}peso_t;


// Se incluyen los prototipos de las funciones 

peso_t f_set(void); //funcion de seteado 

//funciones de estados
estados_t f_espera(peso_t);
estados_t f_izquierda(peso_t);
estados_t f_recto(peso_t);
estados_t f_derecha(peso_t);
estados_t f_error(peso_t);



#endif
