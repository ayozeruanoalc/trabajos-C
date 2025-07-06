
#include <stdio.h>
#include "grupo.h"
#include <errno.h>

int* n;
int aux;
int matricula(int dni){
    if (plazas_libres() >= 1){
        aux = matricula_alumno(dni);
        if (aux == -2){
            printf("El alumno con DNI %d ya está matriculado\n", dni);
        }
        else{
            printf("Se ha matriculado el alumno con DNI %d en el asiento/posición %d\n", dni, aux);
        }
    }
    else {
		aux = matricula_alumno(dni);
		if (aux == -2){
            printf("El alumno con DNI %d ya está matriculado\n", dni);
        }
        else{
        	printf("No hay plazas libres en el grupo\n");
    	}
	}
}
int desmatricula(int dni){
    if (plazas_ocupadas() >= 1){
          aux = desmatricula_alumno(dni);
          if (aux != -3){
            printf("El alumno con DNI %d y posición %d ha sido desmatriculado del grupo\n", dni, aux);
        }
        else{
            printf("No se ha encontrado el DNI solicitado en la lista\n");
        }
    }
    else{
        printf("No hay alumnos matriculados en el grupo\n");
    }
}
int matricula_multiple(int npersonas, int* lista_dni){
	int i;
    if (plazas_libres() >= npersonas){
        for (i=0;i<npersonas;i++){
			//printf("he mandado %d de %d\n", *(lista_dni+i), i);
			matricula_alumno(*(lista_dni+i));
		}
    }
    else{
        printf("No hay plazas libres para todas las personas\n");
    }
}

int main(){

   	printf("Introduzca el tamaño de la lista a crear: ");
    scanf("%d", &n);

if (n<=0 || n>50){
	printf("Código de error: %d\n", errno);
	perror("Error en el input, el número debe estar comprendido entre 1 y 50\n");
	
}

else{

    inicializa_grupo(n);
    leer_vector();

	printf("\n(Se intenta desmatricular cuando no hay nadie matriculado)\n");
    desmatricula(38808158);

    printf("\n(Se procede a hacer una matricula multiple)\n");
    int npersonas = 3;
    int lista[3] = {38808158, 17598594, 51489657};
    int* lista_dni;
	lista_dni = lista;		
    matricula_multiple(npersonas, lista_dni);
	leer_vector(); 


	printf("\n(Se procede a hacer otra matricula multiple)\n");
    npersonas = 5;
    int lista3[5] = {99808158, 99598594, 99489657, 99857465, 35248697};
    lista_dni = lista3;
    matricula_multiple(npersonas, lista_dni);
	leer_vector(); 
 

	printf("\n(Se mete un matriculado nuevo(solo uno))\n");
	matricula(59317174);
	leer_vector();

	printf("\n(Se intenta matricular a alguien ya matriculado)\n");
	matricula(59317174);
	leer_vector();

	printf("\n(Se desmatricula el primero)\n");
    desmatricula(38808158);
	leer_vector();

	printf("\n(Se intenta desmatricular a alguien no matriculado)\n");
    desmatricula(38808158);
	leer_vector();


    printf("\n(Se procede a hacer una matricula multiple, que sobrepase el límite)\n");
    npersonas = 8;
    int lista2[8] = {38805658, 17863894, 54615168, 58394884, 65847219, 63514298, 98426571, 36951753};
    lista_dni = lista2;
    matricula_multiple(npersonas, lista_dni); 
	leer_vector();

/*
	printf("\n(Se matricula a uno solo para luego comprobar que ocurre si esta todo ocupado)\n");
	matricula(38808158);
	leer_vector();
*/
	printf("\n");
/*
	printf("\n(Ahora se matricula a uno nuevo para ver si da ese error)\n");
	matricula(12356847);
	leer_vector();
*/
//Este caso se cumple en casos concretos

    testea_asiento(11);
    testea_asiento(28);
    testea_asiento(1);
    printf("\n");

finaliza_grupo();
/*
Mirar porque cuando liberamos el vector y luego lo leemos no nos sale vacío
y nos devuelve algo raro.
*/
leer_vector();
printf("\n");

printf("Ahora creamos otro grupo: ");
scanf("%d", &n);

if (n<=0 || n>50){
	printf("Código de error: %d\n", errno);
	perror("Error en el input, el número debe estar comprendido entre 1 y 50\n");
	
}

else{
inicializa_grupo(n);
leer_vector();

}
}
} 


