#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ESTA LIBRERÍA ES OPCIONAL Y AQUI ES MERAMENTE INFORMATIVA YA QUE NO LA VAMOS A EMPLEAR AL MENOS DE MOMENTO 
#include<time.h>//PONEMOS AL FINAL DEL CODIGO SYSTEM(PAUSE); Y HASTA QUE NO PULSEMOS ENTER EL PROGRAMA NO FINALIZA

/*APLICACIÓN QUE REALIZARÁ LA GESTIÓN DE UN PARKING
DOS OPCIONES INICIALES:
-USUARIO
-ADMINISTRADOR (CON CONTRASEÑA, SERÁ 'ADMIN')
*/

/*PUNTERO AL FICHERO PARKING*/
FILE*PARKING;
FILE*usuario;
//VARIABLES GLOBALES
char PREGUNTA[20]="";//LA EMPLEAREMOS PARA ENTRAR,SALIR E INTERACTUAR CON EL MENU DE OPCIONES Y LOS DISTINTOS WHILE
char CONTRASENA[20]="";//SOLICITAMOS UNA CONTRASEÑA Y LA ALMACENAMOS AQUI, EN ESTA VARIABLE
char pregunta[20]="";//PARA ENTRAR O SALIR DEL WHILE A LA HORA DE LEER O ESCRIBIR EL FICHERO

	//VARIABLES FICHERO PARKING (LO CREARÁ UN MENUÚ OCULTO QUE SOLO SE PUEDE ACCEDER INTRODUCIENDO * DEL SISTEMA)
//char pregunta[20]="";//PARA ENTRAR O SALIR DEL WHILE A LA HORA DE LEER O ESCRIBIR EL FICHERO
int TotalPlazas=0;//HACE REFERENCIA AL TOTAL DE PLAZAS
int PlazasElectricas=0;//HACE REFERENCIA A LAS PLAZAS ELECTRICAS
int PlazasNormales=0;
int Plantas=0;//NUMERO DE NIVELES O PLANTAS DEL PARKING QUE LO USAREMOS PARA HACER CALCULOS Y DEMÁS
double Tarifa1;
double Tarifa2;
double Tarifa3;
double Tarifa4;
char PreguntaVisualizar[20]="";


//VARIABLES FICHERO USUARIO
int NumeroCliente=0001;//SERÁ UN CONTADOR QUE SE GENERARÁ DE FORMA AUTOMATICA CADA VEZ QUE SE REGISTRE COMO USUARIO, POSTERIORMENTE LO EMPLEAREEMOS PARA SABER SI AL VOLVER A INTRODUCIRLO PASA ALGO O NO Y COSAS ASI
//int TotalPlazas=0; YA USADAS AL CREAR EL FICHERO PARKING COMO TAL
//int PlazasElectricas=0;
char preg_tipo_vehiculo[20]="";

void USUARIO()
{
	
	printf("\n\n\tBienvenido al sistema, se ha registrado como USUARIO.");
	
	PARKING=fopen("F_PARKING.txt","r");
		
	printf("\n\tVisualizar el fichero (TECLEE 'SI' O 'NO')\n");
	printf("\tIntroduzca una opci%cn: ",162);
	scanf("%s",&PreguntaVisualizar);
	fflush(stdout);
	
	while(strcmp(PreguntaVisualizar,"SI")==0||strcmp(PreguntaVisualizar,"si")==0 )
	{											
		if (PARKING==NULL)// COMPROBAMOS SI EL ARCHIVO EXISTE
		{	  
			printf("Archivo no encontrado\n");
			return; 
			//SE ACABA EL PROGRAMA SI EL ARCHIVO NO EXISTE
		}
		//LEEMOS EL FICHERO
		fscanf(PARKING,"%i %i %i %lf %lf %lf %lf",&PlazasNormales,&PlazasElectricas,&Plantas,&Tarifa1,&Tarifa2,&Tarifa3,&Tarifa4);
		
		printf("\n\tTeclee 'SI'para visualizar las tarifas.\n\t (Pulse 'NO' para omitir este paso.)\n");
		printf("\tIntroduzca una opci%cn: ",162);
		scanf("%s",&PreguntaVisualizar);
		fflush(stdout);
		
		printf("\n\tLas tarifas quedan de la siguiente forma: \n\n");
		
		printf("\t   TIEMPO DE ESTANCIA           \tTARIFA (euros / minuto) ");
		
		
		while(!feof(PARKING))
		{		
			printf("\n\n\t ************************************************************ ");
			printf("\t\n\t|    De 0 a 30 minutos ---------------------- %.2lf           |\t",Tarifa1);
			printf("\t\n\t|    De 31 a 90 minutos --------------------- %.2lf           |\t",Tarifa2);
			printf("\t\n\t|    De 91 a 660 minutos -------------------- %.2lf           |\t",Tarifa3);
			printf("\t\n\t|    De 661 minutos hasta                                    |\n\t|    un m%cximo de 24 horas ----------------- %.2lf           |\t\n",160,Tarifa4);
			printf("\t ************************************************************ \n\n ");
						 
			TotalPlazas=PlazasNormales+PlazasElectricas;
			printf("\n\tEl numero TOTAL DE PLAZAS es: %i",TotalPlazas);
			printf("\n\tEl numero de PLAZAS PARA VEHICULO ELECTRICO es: %i",PlazasElectricas);
			printf("\n\tEl numero de PLANTAS es: %i",Plantas);
			
			fscanf(PARKING,"%i %i %i %lf %lf %lf %lf",&PlazasNormales,&PlazasElectricas,&Plantas,&Tarifa1,&Tarifa2,&Tarifa3,&Tarifa4);
		}
			//A PARTIR DE AQUÍ ALMACENAMOS LOS DATOS DEL USUARIO EN UN FICHERO DISTINTO, DONDE GRABAREMOS TAMBIEN LA FECHA HORA Y DEMÁS DATOS
			usuario=fopen("F_USUARIO.txt","a");
			NumeroCliente++;
			
			fscanf(PARKING,"%i %i %i %lf %lf %lf %lf",&PlazasNormales,&PlazasElectricas,&Plantas,&Tarifa1,&Tarifa2,&Tarifa3,&Tarifa4);
		
			printf("\tSe le ha asignado el siguiente n%cmero: %i \n",NumeroCliente);
			printf("\tEs usuario de un vehículo eléctrico? ------ (Pulse 'SI'o 'NO'): ");
			scanf("%s",&preg_tipo_vehiculo);
			fflush(stdout);
				if(strcmp(preg_tipo_vehiculo,"SI")==0||strcmp(preg_tipo_vehiculo,"si")==0 )
				{
					PlazasElectricas--;
					TotalPlazas--;
				}
				else if(strcmp(preg_tipo_vehiculo,"NO")==0||strcmp(preg_tipo_vehiculo,"no")==0 )
				{
					TotalPlazas--;
					PlazasNormales--;
				}
			
			fclose(usuario);
			
			
			printf("\n\tPulse cualquier tecla para Salir:\n");
			scanf("%s",&PreguntaVisualizar);
			fflush(stdout);
	}
	fclose(PARKING);
	//return 0;
}
