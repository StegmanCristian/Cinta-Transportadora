/* Cinta transportadora con seleccion por peso
		-funciones de estado */

#include "..\maquina de estado\MY_LIB.h" 

/*codigo de funcion de seteado*/
peso_t f_set(void){
	peso_t setting;
	setting = f_conf("config.conf");
	if(setting.e==-1)
	{
		printf("\nHubo un error en la carga de los datos de configuracion\n");
		printf("\nPara continuar con los valores predeterminados ( p_set1= 5 kg y p_set2= 10 kg) presione '1'\n\nDe lo contrario presione otro numero: ");
		fflush(stdin);
		scanf ("%d",&setting.e);
		if (setting.e==1)
		{
			setting.p_set1=5;
			setting.p_set2=10;
		}
		else
		return setting;
	}//Si f_set carga un -1 en la flag de error entonces la carga fue fallida 
	setting.e=0;
	printf("\nSe cargo la configuracion de seteo:\t ip_set1: %d \t p_set2: %d\n",setting.p_set1,setting.p_set2);
	return setting;
}

/*codigo de funciones de estados*/

estados_t f_espera(peso_t peso){
	estados_t estado = espera;
	printf("\n\tESTADO ACTUAL: ESPERA\n");
	peso.e = f_sensores();
	if(peso.e != 0) return error; //en el caso que no sea '0' directamente pasa al estado de error y se para el funcionamiento hasta que se solucione el problema 
	peso.p = f_pesar();
	if(peso.p==0)return espera;
	system("cls");
	if (peso.p <= peso.p_set1){
		printf("\n PAQUETE LIVIANO");
		estado=izquierda;
	}
	else{
		if(peso.p>peso.p_set1 && peso.p<peso.p_set2){
			printf("\n PAQUETE POCO PESADO");
			estado=recto;
		}
		else{
			printf("\n PAQUETE PESADO");
			estado=derecha;
		}
	}
	return estado;
}

estados_t f_izquierda(peso_t peso)
{
	estados_t estado = izquierda;
	printf("\n\n***Se enciende la cinta en direccion hacia la izquierda***\n");
	peso.e = f_sensores();
	if(peso.e!=0) return error; //en el caso que no sea '0' directamente pasa al estado de error y se para el funcionamiento hasta que se solucione el problema 
	return espera;
}

estados_t f_recto(peso_t peso){
	estados_t estado = recto;
	printf("\n\n***Se enciende la cinta en direccion recta***\n");
	peso.e = f_sensores();
	if(peso.e!=0) return error; //en el caso que no sea '0' directamente pasa al estado de error y se para el funcionamiento hasta que se solucione el problema 
	return espera;
}

estados_t f_derecha(peso_t peso){
	estados_t estado = derecha;
	printf("\n\n***Se enciende la cinta en direccion hacia la derecha***\n");
	peso.e = f_sensores();
	if(peso.e!=0) return error; //en el caso que no sea '0' directamente pasa al estado de error y se para el funcionamiento hasta que se solucione el problema 
	return espera;
}

estados_t f_error(peso_t peso){
	estados_t estado = error;
	printf("\n\tESTADO ACTUAL: ERROR\n");
	bool interruptor=0;//se frena el sistema de manera que se pueda trabajar sobre el problema antes de que la maquina continue fallando
	interruptor = f_llave(interruptor);
	peso.e = f_sensores(); //volvemos a analizar los sensores para verificar que no persista el error 
	if(peso.e!=0) return error;//si el error persiste se vuelve a este estado
	return espera;//solucionado el error se pasa al estado espera
}

