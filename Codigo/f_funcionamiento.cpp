/* Cinta transportadora con seleccion por peso
		-funciones funcionamiento */

#include "..\Codigo\My_Lib.h" 

char *getkey(char *key)
{
	char i=0;
	while (*(key+i)!=' ')
	{
		i++;
	}
	*(key+i)=0;
	return key+i+1;
}

peso_t f_conf (char *filename)
{
	FILE *conf;
	char cadena[40], *key, *val;
	char variables[2][20] = {"p_set1", "p_set2"};
	peso_t config;
	char i, flag1=0,flag2=0;
	enum set
	{
		p_set1=0,
		p_set2=1
	} ;
	if ((conf=fopen(filename, "rt")) == NULL)
	{
		printf("\n***Error: Archivo de configuracion no encontrado***\n");
		config.e = -1;
		return config;
	}
	fgets(cadena,40,conf);
	do
	{
		key=cadena;
		if ((*key)!='#'&& strlen(key)>=0)
		{
			val=getkey(key);
			for(i=0;i<2;i++)
			{
				if(!strcmp(key,variables[i]))
				{
					switch(i)
					{
						case p_set1:
							config.p_set1 = atoi(val);
							flag1 = 1;
							break;
						case p_set2:
							config.p_set2 = atoi(val);
							flag2 =1;
							break;
					}
				}
			}
		}
		fgets(cadena,40,conf);
	} while (!feof(conf));
	if(flag1 && flag2)
	{
		return config;
	}
	else
	{
		printf("\n***Error: No se cargaron adecuadamente los valores de configuracion***\n");
		config.e=-1;
		return config;
	}
}

// Detectora de errores
char f_sensores (void)
{
	int e;
	printf("\n\t***simulacion de error***\n\tSeleccione uno de los posibles casos");
	printf("\n\t\t(0):Sin error");
	printf("\n\t\t(1):Problema con el selector");
	printf("\n\t\t(2):Cinta atascada");
	printf("\n\t\t(3):Problema en el sensor");
	printf("\n\n\t caso: ");
	fflush(stdin);
	scanf("%d",&e);
	system("cls");
	switch (e)
	{
		case 0:
			printf("\n\t El sistema funciona con normalidad ->\t No se detectaron errores\n");
			break;
		case 1:
			printf ("\n\t Se detecto un problema con el selector\n");
			printf ("\n\t***REVISAR Y REPARAR***\n");
			break;
		case 2:
			printf ("\n\t La cinta se encuentra atascada\n");
			printf ("\n\t***REVISAR Y REPARAR***\n");
			break;
		default:
			printf ("\n\t Se detecto un problema con el sensor de peso\n");
			printf ("\n\t***REVISAR Y REPARAR***\n");
	}
	
	return e;
}

bool f_llave(bool llave){
	printf("\n\tEn caso de haber revisado y reparado el problema presione '1'\n");//el '1' simula accionar llave
	fflush(stdin);
	scanf("%d",&llave);//evalua si la llave esta o no accionada 
	return llave;
}

int f_pesar (void){
	int p;
	printf("\nPeso medido:");
	fflush(stdin);
	scanf("%d",&p);
	return p;
}
