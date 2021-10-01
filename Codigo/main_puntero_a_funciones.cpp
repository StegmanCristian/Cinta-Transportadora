/* Main de Maquina de estados Stegman Cristian con puntero a funciones 
	- Cinta transportadora con seleccion por peso*/

#include "..\Codigo\My_Lib.h" 


int main()
{
	peso_t peso;
	estados_t estado=espera;
	estados_t (*pfe[])(peso_t)={f_espera,f_izquierda,f_recto,f_derecha,f_error};
	peso= f_set();
	if (peso.e==-1) return 0;
	while(1)estado= (*pfe[estado])(peso);
	return 0;
}

