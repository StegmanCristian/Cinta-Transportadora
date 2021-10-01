/* Cinta transportadora con seleccion por peso
		-Libreria */
		
#ifndef MY_LIB
#define MY_LIB

// Se incluyen todas las librerias que se vayan a utilizar en el programa y por las funciones que este emplee
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Definimos un tipo de dato que contenga los estados posibles
typedef enum{
	espera=0,
	izquierda=1,
	recto=2,
	derecha=3,
	error=4
	}estados_t;

// Definimos tipo de dato que va a manejar la maquina durante todo el proceso de transiciones
typedef struct {
	int p;  //peso leido
	char e; //flag de error en la medicion de peso
	int p_set1; //valor inferior de peso para cosas "poco pesadas"
	int p_set2; //limite superior de peso para cosas "poco pesadas"
}peso_t;


// Se incluyen los prototipos de las funciones 

peso_t f_set(void); //funcion de seteado 

//funciones de estados
estados_t f_espera(peso_t);
estados_t f_izquierda(peso_t);
estados_t f_recto(peso_t);
estados_t f_derecha(peso_t);
estados_t f_error(peso_t);

//funciones secundarias y de simulación funcionamiento 
char *getkey(char *);
peso_t f_conf (char *); //lee y obtiene informacion del archivo de configuracion
char f_sensores (void); //simula detector de errores
int f_pesar (void); //simula sensor de peso
bool f_llave(bool); //simula interruptor de error

#include "../Codigo/f_estado.cpp"
#include "../Codigo/f_funcionamiento.cpp"

#endif
