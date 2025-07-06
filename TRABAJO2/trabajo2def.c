#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <unistd.h>

// ESTA ES LA VERSION TEMPRANA DEL SPLITTER DE ENRIQUE Y FABIO               
/*
char *splitter(char *line){
	char *token[50]; //un valor grande por si hay alguna función larga
	int i = 0;
	token[i] = strtok(line, " ");
	if (token == NULL){
		printf("Se ha producido un error");
		exit(-1);
	}
	while(token[i] != NULL){
		i++;
		token[i] = strtok(NULL, " ");
	}
	return token;
}
*/


void main(){
	pid_t pid;
	char *buffer;
	size_t bufsize = 32;
	size_t characters;
	struct tms time_start, time_end;
	struct rusage usage;
	clock_t start_clock, end_clock;	
	
	while (1){ 


inicio:

		buffer = (char *)malloc(bufsize * sizeof(char));
		
		printf("-----------------------------------------------\n");
    	printf("Escribe órdenes: ");
    	characters = getline(&buffer,&bufsize,stdin);
    	printf("%zu caracteres han sido leídos.\n",characters);
    	//printf("You typed: '%s'\n",buffer);
	
		//printf("Instrucciones a ejecutar: ");
		//printf("%s", buffer);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
	int i; // para recorrer la cadena
	int counter = 0; // para navegar el vector aux
	int idef = 0; // para navegar el vector result
	
	char aux = (char)malloc(20*sizeof(char)); // crea un vector con espacio para (20) chars
	char *result[10];

	for (i=0;i<characters;i++){
	 	if (buffer[i] != ' ' || buffer[i] != "\n"){
			*(aux+counter) = buffer[i];
			counter++;
		}
		else{
			result[idef] = aux;
			
			counter = 0;
			free(aux);
			aux = (char*)malloc(20*sizeof(char)); // crea un vector con espacio para (counter) chars
			idef++;
		}
			
	}

	
	int tam = sizeof(result) / sizeof(char*);
	for (i=0;i<tam;i++){
		printf("%s\n", result[i]);
	}

// el problema que nos daba esta version es que al hacer free, nos cargabamos el puntero.

	
*/

		
		// segmento splitter
		char *result[10];

		const char s[3] = " \n";
	   	char *token;
	   
	   	/* primer elemento */
	   	token = strtok(buffer, s);
	   
	   	/* recopila los elementos restantes */
		int i = 0;
		int a = 0;
	   	while( token != NULL ) {
			result[a] = token;
			a++;
	    
	      token = strtok(NULL, s);
	   }
	
		result[a] = NULL;
	//a++;

	
	// ESTE ES UN SEGMENTO PARA LEER EL VECTOR (HECHO POR AYOZE)
    // int tam = sizeof(hola) / sizeof(char*);
	printf("-----------------------------------------------\n");
	printf("Contenido del vector resultado: ");
	int amper = 0;
    for (i=0;i<a;i++){
		if (strcmp(result[i], "&") == 0){
			result[i] = NULL;
			amper = 1;
		}
		if (i==a-1){
			printf("(%s)\n", result[i]);
		}
		else{
        	printf("(%s),", result[i]);
		}

	}








/*		
		buffer = (char *)malloc(bufsize * sizeof(char));
			
		printf("Type something: ");
		characters = getline(&buffer,&bufsize,stdin);
		printf("%zu characters were read.\n",characters);

		
		char *token[50]; //un valor grande por si hay alguna función larga
		char s[3] = " \n";
		int i = 0;
		token[i] = strtok(buffer, s);
		if (token == NULL){															// ESTO SI LO PODEMOS BORRAR
			printf("Se ha producido un error");
			exit(-1);
		}
		while(token[i] != NULL){
			i++;	
			token[i] = strtok(NULL, " ");
		}
		
		
		int tam = sizeof(token) / sizeof(char*);
		for (i=0;i<tam;i++){
			printf("%s, ", token[i]);
    		}
*/
		if (strcmp(result[0],"cd")==0){
			if (result[1] != NULL){ //Comprueba que tiene un argumento
				if (chdir(result[1]) != 0){ //si no existe el directorio devuelve error
					perror("Error de cd");			
			} 
				
			}
			else{
				printf("Uso: cd	<directorio>\n");		
			}
		}

		if (strcmp(result[0],"exit")==0){
			printf("-----------------------------------------------\n");
			printf("Ejecución terminada. (Se ha introducido exit)\n");
			break;	
		}
		 /*if (strcmp(result[0],"cd")==0){
			if (result[1] != NULL){ //Comprueba que tiene un argumento
				if (chdir(result[1]) != 0){ //si no existe el directorio devuelve error
					perror("Error de cd");			
			} 
				
			}
			else{
				printf("Uso: cd	<directorio>\n");		
			}
		} */

		else{
			start_clock = times(&time_start);
			//printf("Start_clock = %d\n", start_clock);
			pid = fork(); 
			if (pid == 0){	
				printf("-----------------------------------------------\n");
				printf("Pid del proceso padre: %d, pid del proceso hijo: %d\n", getppid(), getpid());
				printf("-----------------------------------------------\n");
				execvp(result[0], result);	
			}
			else{
				if (amper){
					goto inicio;
					}
				wait(0); 
				end_clock = times(&time_end);
				//printf("End_clock = %d\n", end_clock);

			long tiempo_usuario = (time_end.tms_cutime - time_start.tms_cutime);
			long tiempo_sistema = (time_end.tms_cstime - time_start.tms_cstime);
			long tiempo_total = tiempo_usuario + tiempo_sistema;

				printf("Tiempo de uso de la CPU del proceso hijo: %ld\n", tiempo_total);
			}
		}
	}

}


