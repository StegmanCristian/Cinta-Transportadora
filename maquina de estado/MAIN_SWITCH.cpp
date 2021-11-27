/* Main de Maquina de estados Stegman Cristian 
	- Cinta transportadora con seleccion por peso*/

#include "..\maquina de estado\MY_LIB.h" 

int main()
{
	peso_t peso;
	estados_t estado=espera;
	peso= f_set();
	if (peso.e==-1) return 0;
	while(1){
		switch (estado){
			case espera:
				estado= f_espera(peso);
				break;
			case izquierda:
				estado= f_izquierda(peso);
				break;
			case recto:
				estado= f_recto(peso);
				break;
			case derecha:
				estado= f_derecha(peso);
				break;
			case error:
				estado= f_error(peso);
				break;
		}
	}
	return 0;
}

