#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ESTA LIBRERÍA ES OPCIONAL Y AQUI ES MERAMENTE INFORMATIVA YA QUE NO LA VAMOS A EMPLEAR AL MENOS DE MOMENTO 
#include<time.h>//PONEMOS AL FINAL DEL CODIGO SYSTEM(PAUSE); Y HASTA QUE NO PULSEMOS ENTER EL PROGRAMA NO FINALIZA



//DESCRIPCIÓN DEL PROGRAMA Y SU FUNCIONAMIENTO GENERAL


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
int NumeroCliente=0;//SERÁ UN CONTADOR QUE SE GENERARÁ DE FORMA AUTOMATICA CADA VEZ QUE SE REGISTRE COMO USUARIO, POSTERIORMENTE LO EMPLEAREEMOS PARA SABER SI AL VOLVER A INTRODUCIRLO PASA ALGO O NO Y COSAS ASI
//int TotalPlazas=0; YA USADAS AL CREAR EL FICHERO PARKING COMO TAL
//int PlazasElectricas=0;
char preg_tipo_vehiculo[20]="";
int tiempo=0;
double precioTarifa=0;
double TotalPago=0;
char seleccionTarifa[20]="";//AUN POR DEFINIR
//VARIABLES FICHERO ADMINISTRADOR
char PreguntaAdmin[20]="";
char Opcion_admin[20]="";



void main()
{
	printf("\n ------------------- APLICACI%cN PARA LA GESTI%cN DE UN PARKING -------------------\n\n ",224,224);
	printf("\tRecordatorio\n");
	printf("\t _________________________________________________________\n");
	printf("\t|                                                         |");
	printf("\n\t| PARA ACCEDER COMO ADMINISTRADOR SE REQUIERE CONTRASE%cA  |\n",165);
	printf("\t|_________________________________________________________|\n");
	printf("\n -----------------------------------------------------------------\n");
	printf("\n\n\t #Seleccione una de las siguientes opciones: \n\n\t  -USUARIO ---------------- (PULSE 1) \n\t  -ADMINISTRADOR ---------- (PULSE 2)\n\t  -SALIR ------------------ (TECLEE 'SALIR') \n\n\t      *Introduzca una opci%cn: ",162,162);
	scanf("%s",PREGUNTA);
	fflush(stdout);

	

	while(strcmp(PREGUNTA,"SALIR")!=0 || strcmp(PREGUNTA,"salir")!=0)
	{
		
		if(strcmp(PREGUNTA,"1")==0)//SI ES USUARIO
		{
			printf("\n\n   -----------------------------------------------------------------\n");
			printf("\t *Ha accedido al sistema como USUARIO.*");
			printf("\n   -----------------------------------------------------------------\n\n");
			
			USUARIO();//lLAMAMOS AL VOID USUARIO
		}
		else if(strcmp(PREGUNTA,"2")==0)
		{
			printf("   -----------------------------------------------------------------\n");
			printf("\t *Ha accedido al sistema como ADMINISTRADOR.*");
			printf("\n   -----------------------------------------------------------------\n\n");
			printf("\tIntroduzca la contrase%ca: ",164);
			scanf("%s",&CONTRASENA);
			fflush(stdout);
			while(strcmp(CONTRASENA,"ADMIN")!=0 || strcmp(CONTRASENA,"admin")!=0)
			{
				if(strcmp(CONTRASENA,"ADMIN")==0)//SI ES ADMINISTRADOR
				{
					ADMINISTRADOR();//LLAMAMAOS AL VOID ADMINISTRADOR
				}
				else
				{
					printf("\tCONTRASE%cA INCORRECTA\n",165);
					
				}
				printf("\tIntroduzca la contrase%ca: ",164);
				scanf("%s",&CONTRASENA);
				fflush(stdout);
			}
		}
		else if((strcmp(PREGUNTA,"*")==0))
		{		
			printf("\n\tAcceder al fichero (TECLEE ESCRIBIR O LEER): ");
			scanf("%s",&pregunta);
			fflush(stdout);
			if (strcmp(pregunta,"ESCRIBIR")==0|| strcmp(pregunta,"escribir")==0)
			{
				ESCRIBIR();
			}
			else if(strcmp(pregunta,"LEER")==0|| strcmp(pregunta,"leer")==0)
			{
				LEER();
			}
	
		}
		else if(strcmp(PREGUNTA,"SALIR")==0|| strcmp(PREGUNTA,"salir")==0)
		{
			printf("\n\n.:%cHasta pronto!:.",173);
			return 0;
		}
		else
		{
			printf("\n   -----------------------------------------------------------------\n");	
			printf("\t%cUps! No se reconoce la opci%cn introducida...",173,162);
			printf("\n   -----------------------------------------------------------------\n\n");
		}
		
			printf("\n\t #Seleccione una de las siguientes opciones: \n\n\t  -USUARIO ---------------- (PULSE 1) \n\t  -ADMINISTRADOR ---------- (PULSE 2)\n\t  -SALIR ------------------ (TECLEE 'SALIR') \n\n\t      *Introduzca una opci%cn: ",162,162);
			scanf("%s",&PREGUNTA);
			fflush(stdout);
	}//FIN WHILE PREGUNTA
	
}

void ESCRIBIR()
{
	PARKING=fopen("F_PARKING.txt","a");
	printf("\n   -----------------------------------------------------------------\n");
	printf("\t *Ha accedido al sistema como PROGRAMADOR.*");
	printf("\n   -----------------------------------------------------------------\n\n");
	printf("\n\n\tIntroducir datos en el fichero PARKING (TECLEE 'SI' o 'NO'): ");
	scanf("%s",&pregunta);
	fflush(stdout);
	
	while(strcmp(pregunta,"SI")==0|| strcmp(pregunta,"si")==0)
		{
			printf("\nIntroduzca el numero de PLAZAS TOTALES del parking: ");
			scanf("%i",&PlazasNormales);
			fflush(stdin);
			
			printf("\nIntroduzca el NUMERO DE PLAZAS para COCHES ELECTRICOS del parking: ");
			scanf("%i",&PlazasElectricas);
			fflush(stdin);
			
			printf("\nIntroduzca el numero de PLANTAS que tiene el parking: ");
			scanf("%i",&Plantas);
			fflush(stdin);
			
			//PODRÍA HACERSE CON UN FOR Y ALAMCENAR LOS DATOS, PERO MEJOR ASÍ YA QUE PODEMOS ACCEDER A LA TARIFA ESPECIFICA EN FUNCION DEL TIEMPO ESCOGIDO
			printf("\nIntroduzca la tarifa correspondiente a los tiempos de estancia (De 0 a 30 minutos): ");
			scanf("%lf",&Tarifa1);
			fflush(stdout);
			printf("\nIntroduzca la tarifa correspondiente a los tiempos de estancia (De 31 a 90 minutos): ");
			scanf("%lf",&Tarifa2);
			fflush(stdout);
			printf("\nIntroduzca la tarifa correspondiente a los tiempos de estancia ( De 91 a 660 minutos): ");
			scanf("%lf",&Tarifa3);
			fflush(stdout);
			printf("\nIntroduzca la tarifa correspondiente a los tiempos de estancia (De 661 minutos hasta un máximo de 24 horas): ");
			scanf("%lf",&Tarifa4);
			fflush(stdout);
				
			printf("\nDesea introducir mas datos? (PULSE SI O NO): ");
			scanf("%s",&pregunta);
			fflush(stdout);
		}
		
		fprintf(PARKING,"%i %i %i %lf %lf %lf %lf\n",PlazasNormales,PlazasElectricas,Plantas,Tarifa1,Tarifa2,Tarifa3,Tarifa4);
		printf("\nSe ha escrito correctamente en el fichero");
	fclose(PARKING);
	
}

void LEER()
{

//LEEMOS EL FICHERO
	PARKING=fopen("F_PARKING.txt","r");
	printf("\nVISUALIZAR DATOS DEL FICHERO PARKING\n");
	printf("Visualizar el fichero (TECLEE 'SI' O 'NO')\n");
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
		
		printf("\n\tTeclee 'SI'para visualizar las tarifas. (Pulse 'NO' para omitir este paso.)\n");
		printf("\tIntroduzca una opci%cn: ",162);
		scanf("%s",&PreguntaVisualizar);
		fflush(stdout);
		
		printf("\nLas tarifas quedan de la siguiente forma: \n");
		printf("\t TIEMPO DE ESTANCIA            \t TARIFA (euros / minuto)\n\n");
		
		while(!feof(PARKING))
		{
			printf("\t De 0 a 30 minutos ----------------- %.2lf",Tarifa1);
			printf("\n\n\t De 31 a 90 minutos ---------------- %.2lf",Tarifa2);
			printf("\n\n\t De 91 a 660 minutos --------------- %.2lf",Tarifa3);
			printf("\n\n\t De 661 minutos hasta \n\t un m%cximo de 24 horas ------------- %.2lf\n\n",160,Tarifa4);
			
			
			TotalPlazas=PlazasNormales+PlazasElectricas;
			printf("\n\tEl numero TOTAL DE PLAZAS es: %i",TotalPlazas);
			printf("\n\tEl numero de PLAZAS PARA VEHICULO ELECTRICO es: %i",PlazasElectricas);
			printf("\n\tEl numero de PLANTAS es: %i",Plantas);
			
			fscanf(PARKING,"%i %i %i %lf %lf %lf %lf",&PlazasNormales,&PlazasElectricas,&Plantas,&Tarifa1,&Tarifa2,&Tarifa3,&Tarifa4);
		}
			printf("\n\tPulse cualquier tecla para Salir:\n");
			scanf("%s",&PreguntaVisualizar);
			fflush(stdout);
	}
	fclose(PARKING);
}

void USUARIO()
{
	PARKING=fopen("F_PARKING.txt","r");
		
	printf("\n\tAcceder al Sistema (TECLEE 'SI' O 'NO')\n");
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
			printf("\t ************************************************************ \n ");
			printf("\tEn dichas cifras se incluye el 21%c de IVA.\n",'%');			 
			TotalPlazas=PlazasNormales+PlazasElectricas;
			printf("\n\tEl n%cmero TOTAL DE PLAZAS es: %i",163,TotalPlazas);
			printf("\n\tEl n%cmero de PLAZAS PARA VEHICULO ELECTRICO es: %i",163,PlazasElectricas);
			printf("\n\tEl n%cmero de PLANTAS es: %i",163,Plantas);
			
			fscanf(PARKING,"%i %i %i %lf %lf %lf %lf",&PlazasNormales,&PlazasElectricas,&Plantas,&Tarifa1,&Tarifa2,&Tarifa3,&Tarifa4);
		}//FIN WHILE LECTURA PARKING
		
			//A PARTIR DE AQUÍ ALMACENAMOS LOS DATOS DEL USUARIO EN UN FICHERO DISTINTO, DONDE GRABAREMOS TAMBIEN LA FECHA HORA Y DEMÁS DATOS
			usuario=fopen("F_USUARIO.txt","a");
			
			
			/*ASIGNAMOS LA FECHA Y HORA ACTUALES Y CON %s , output IMPRIMIMOS DICHOS DATOS*/
				time_t tiempo = time(0);
			    struct tm *tlocal = localtime(&tiempo);
			    char output[128];
			    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    		/*ASIGNAMOS LA FECHA Y HORA ACTUALES Y CON %s , output IMPRIMIMOS DICHOS DATOS*/
				NumeroCliente++;
				printf("\n\tSe le ha asignado el siguiente n%cmero: 000%i\n",163,NumeroCliente);
				fscanf(usuario,"%i %s %i %lf %s %lf ",NumeroCliente,preg_tipo_vehiculo,tiempo,precioTarifa,output,TotalPago);
			
			
			printf("\tEs usuario de un veh%cculo el%cctrico? ------ (Pulse 'SI'o 'NO'): ",161,130);
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
			
			printf("\n\tIntroduzca el tiempo (en minutos): ");
			scanf("%i",&tiempo);
			fflush(stdout);
			
				if (tiempo>0 && tiempo<=30)
				{
					precioTarifa=Tarifa1;
					TotalPago=tiempo*Tarifa1;
				}
				else if (tiempo>=31 && tiempo<=90)
				{
					precioTarifa=Tarifa2;
					TotalPago=tiempo*Tarifa2;
				}
				else if (tiempo>=91 && tiempo<=660)
				{
					precioTarifa=Tarifa3;
					TotalPago=tiempo*Tarifa3;
				}
				else if (tiempo>=661 && tiempo<=1440)
				{
					precioTarifa=Tarifa4;
					TotalPago=tiempo*Tarifa4;
				}
			
			printf("\n\t RECUERDE RECOGER SU TICKET: ");
			printf("\n\t ---------------------------------- ");
			printf("\n\t|------------------               |");
			printf("\n\t| Fecha y hora de expedici%cn:     |\n\t| %s               |\n",162,output);
			printf("        |------------------               |");
			printf("\n\t| C%cdigo: 000%i                    |",162,NumeroCliente);
			printf("\n\t| Veh%cculo el%cctrico: %s          |",161,130,preg_tipo_vehiculo);
			printf("\n\t| Tiempo: %i minutos               |",tiempo);
			printf("\n\t| Precio: %.2lf EUR/min            |",precioTarifa);
			printf("\n\t| ------------------              |\n");
			printf("        | Total a pagar: %.2lf euros  |\n",TotalPago);
			printf("\n\t ---------------------------------- ");
			/*ESCRIBIMOS EN EL FICHERO usuario*/
			fprintf(usuario,"000%i %s %i %.2lf %s %.2lf \n",NumeroCliente,preg_tipo_vehiculo,tiempo,precioTarifa,output,TotalPago);//PARA ESCRIBIR UN DOUBLE EN UN FICHERO PODEMOS MARCARLE LA DIMENSION PERO AL LEER SOLO PODEMOS LEER LF NO,.2LF O COSAS ASI 
			
			fclose(usuario);
			
			printf("\n\n\tPulse cualquier tecla para Salir: ");
			scanf("%s",&PreguntaVisualizar);
			fflush(stdout);
			printf("\n -----------------------------------------------------------------\n");
	}//FIN WHILE PreguntaVisualizar
	fclose(PARKING);
	//return;
}

void ADMINISTRADOR() // QUE TENGA OPCIONES DE EDICION EN CUANTO A LOS CAMPOS Y DEMAS TERMINOS QUE APARECEN EN EL SISTEMA, SIEMPRE DESDE EL PROPIO SISTEMA
{
	printf("\n\tModificar los datos del Sistema (TECLEE SI O NO)");
	printf("\n\t*Introduzca una opci%cn: ",162);
	scanf("%s",&PreguntaAdmin);
	fflush(stdin);
	
	while(strcmp(PreguntaAdmin,"SI")==0||strcmp(PreguntaAdmin,"si")==0 )
	{
		
		printf("\n\n\t #Seleccione una de las siguientes opciones:");
		printf("\n\t\t-Modificar el numero de Plazas del Parking ---------------- (PULSE 1)" );
		printf("\n\t\t-Modificar el numero de Plazas electricas ---------- (PULSE 2)");
		printf("\n\t-SALIR ------------------ (TECLEE 'SALIR') \n\n\t      *Introduzca una opci%cn: ",162,162);
		scanf("%s",Opcion_admin);
		fflush(stdout);
	
		if(strcmp(Opcion_admin,"1")==0)//SI ES USUARIO
		{
			printf("\n\n   -----------------------------------------------------------------\n");
			printf("\t *Modificar el numero de plazas del Parking.*");
			printf("\n   -----------------------------------------------------------------\n\n");
			
			printf("\n\n************FICHERO EN PROCESO INTERNO, DISCULPE LAS MOLESTIAS***************\n\n");
			/*IR AL FICHERO PARKING EN EL QUE ALMACENAMOS LAS PLAZAS Y MODIFICARLAS CON LOS PARAMETROS AQUÍ INTRODUCIDOS*/
		}
		else if(strcmp(Opcion_admin,"2")==0)
		{
			printf("\n\n   -----------------------------------------------------------------\n");
			printf("\t *Modificar el numero de Plazas electricas.*");
			printf("\n   -----------------------------------------------------------------\n\n");
			
			printf("\n\n************FICHERO EN PROCESO INTERNO, DISCULPE LAS MOLESTIAS***************\n\n");
			/*IR AL FICHERO PARKING EN EL QUE ALMACENAMOS LAS PLAZAS Y MODIFICARLAS CON LOS PARAMETROS AQUÍ INTRODUCIDOS*/
		}
		
		else if(strcmp(PREGUNTA,"SALIR")==0|| strcmp(PREGUNTA,"salir")==0)
		{
			printf("\n\n.:%cHasta pronto!:.",173);
			return 0;
		}
		else
		{
			printf("\n   -----------------------------------------------------------------\n");	
			printf("\t%cUps! No se reconoce la opci%cn introducida...",173,162);
			printf("\n   -----------------------------------------------------------------\n\n");
			
			printf("\n\n\t #Seleccione una de las siguientes opciones:");
			printf("\n\n\t\t-Modificar el numero de Plazas del Parking ---------------- (PULSE 1)" );
			printf("\n\t\t-Modificar el numero de Plazas electricas ---------- (PULSE 2)");
			printf("\n\t\t-SALIR ------------------ (TECLEE 'SALIR') \n\n\t      *Introduzca una opci%cn: ",162);
			scanf("%s",Opcion_admin);
			fflush(stdout);
				
		}
		

		printf("Salir del Sistema (TECLEE SI O NO)");
		printf("*Introduzca una opci%cn: ",162);
		scanf("%s",&PreguntaAdmin);
		fflush(stdin);
	}
	printf("Desea volver al menu principal?");
	
	
	return;
}

