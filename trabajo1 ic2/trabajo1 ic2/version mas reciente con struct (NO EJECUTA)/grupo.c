#include <stdio.h>
#define MAX 50
#include <string.h>
#include 

int *vector;
int a; // almacena n
int vecaux[MAX];
                   
int inicializa_grupo(int n){
	int i;
    a = n;
	vector = (int *)malloc(n * sizeof(int));
	if(a<=MAX){
    	for (i=0;i<a;i++){
        	vector[i] = -1;
    	}
	}
	else{
		printf("Se ha excedido el tamaño permitido por la clase.\n");
		exit(1);
	}
}

void finaliza_grupo(){
	free(vector);
}

int leer_vector(){
	int i;
    for (i=0;i<a;i++){
        if (i == a-1){
			printf("(%d)\n", vector[i]);
		}
		else {
			printf("(%d),", vector[i]);
		}
    }
}

// LAS DE ARRIBA SE QUEDAN IGUALES

int matricula_alumno(lista*){
	int i;
    for (i=0;i<a;i++){
        if (vector[i] == (lista*).dni){
            return -2;
        }
        else if (vector[i] == -1){
			vector[i] = {(lista*).dni, (lista*).nombre};
			vecaux[i] = (lista*);
			vecaux[i].numero_matricula = i;
            return i;
        }
    }
    return -1;
}

char* desmatricula_alumno(int dni){
	int i;
	char str[];
    for (i=0;i<a;i++){
        if (vecaux[i].dni == dni){
			str = vecaux[i].nombre;
			strcat(str," ");
			strcat(str,vecaux[i].apellidos);
			vector[i] = -1;
        	return str; 
        }
    }
    return -3;
}

int testea_asiento(int asiento){
    if (vector[asiento] == -1){
	    printf("El asiento %d está vacio\n", asiento);
		return -1;
    }
    else if (asiento>a){
        printf("El asiento %d no se encuentra en el rango\n", asiento);
		return -2;
    }
    else{
		printf("La persona con DNI: %d esta sentado en el asiento: %d\n", vector[asiento], asiento);
        return vector[asiento];
    }
}

int plazas_libres(){
	int i;
	int counter = 0;
    for (i=0;i<a;i++){
        if (vector[i] == -1){
            counter += 1;
        }
    }
return counter;
}

int plazas_ocupadas(){
	int i;
	int counter = 0;
    for (i=0;i<a;i++){
        if (vector[i] != -1){
            counter += 1;
        }
    }
return counter;
}

