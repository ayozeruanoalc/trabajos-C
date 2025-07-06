
#include <stdio.h>
#include "grupo.h"
#include <string.h>

int* n;
int aux;
struct new {
	int dni;
	char nombre[10];
	char apellidos[20];
	int numero_matricula;
		};

int matricula(int dni, char* nom, char* apellido, int numero_matricula){
    	struct new nuevo[1] = {dni, nom, apellido, numero_matricula};

	struct new* lista;
	lista = nuevo;
	
if (plazas_libres() >= 1){
	
        aux = matricula_alumno(lista);
        if (aux == -2){
            printf("El alumno con DNI %d ya está matriculado\n", dni);
        }
        else{
            printf("Se ha matriculado el alumno con DNI %d en el asiento/posición %d\n", dni, aux);
        }
    }
    else {
		aux = matricula_alumno(lista);
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

int matricula_multiple(int npersonas, struct new* lista){
	int i;
    if (plazas_libres() >= npersonas){
        for (i=0;i<npersonas;i++){
			//printf("he mandado %d de %d\n", *(lista_dni+i), i);
			matricula_alumno(*(lista+i)); // pensamos que un error puede estar en que ahí se navegan structs SOLOS, y matricula alumno pide un puntero a struct
		}
    }
    else{
        printf("No hay plazas libres para todas las personas\n");
    }
}

int main(){

   	printf("Introduzca el tamaño de la lista a crear: ");
    scanf("%d", &n);

if (n<0){
printf("%d", errno);
perror("Error en el input: El número debe ser positivo");
}

else if (n>50){
printf("%d", errno);
perror("Error en el input: El número debe ser menor de 50");
}

else{






    inicializa_grupo(n);
    leer_vector();

	printf("\n(Se intenta desmatricular cuando no hay nadie matriculado)\n");
    desmatricula(38808158);

    printf("\n(Se procede a hacer una matricula multiple)\n");
    int npersonas = 3;
    struct new lista[3] = {{38808158, "Ayoze", "Ruano Alcántara",},{59874632, "Nesta", "Arteaga Cabrera",},{45179111, "Enrique", "Reina Hernández",}};
    struct new* lista_dni;
	lista_dni = lista;		
    matricula_multiple(npersonas, lista_dni);
	leer_vector(); 


	printf("\n(Se procede a hacer otra matricula multiple)\n");
    npersonas = 2;
    struct new lista3[2] = {{66666666, "Cristina", "Gonzçalez López",},{55555555, "Manuel", "Delacruz Quintana",}};
    lista_dni = lista3;
    matricula_multiple(npersonas, lista_dni);
	leer_vector(); 
 

	printf("\n(Se mete un matriculado nuevo(solo uno))\n");
	matricula(59317174, "Isidro", "Velázquez Duarte", 0);
	leer_vector();

	printf("\n(Se intenta matricular a alguien ya matriculado)\n");
	matricula(59317174, "Isidro", "Velázquez Duarte", 0);
	leer_vector();

	printf("\n(Se desmatricula el primero)\n");
    desmatricula(38808158);
	leer_vector();

	printf("\n(Se intenta desmatricular a alguien no matriculado)\n");
    desmatricula(38808158);
	leer_vector();

/*
    printf("\n(Se procede a hacer una matricula multiple, que sobrepase el límite)\n");
    npersonas = 8;
    int lista2[8] = {38805658, 17863894, 54615168, 58394884, 65847219, 63514298, 98426571, 36951753};
    lista_dni = lista2;
    matricula_multiple(npersonas, lista_dni); 
	leer_vector();
*/
/*
	printf("\n(Se matricula a uno solo para luego comprobar que ocurre si esta todo ocupado)\n");
	matricula(38808158);
	leer_vector();
	printf("\n");
*/
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
inicializa_grupo(n);
leer_vector();

}
} 


