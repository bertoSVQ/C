#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCAR 128
#define MAXPELICULAS 20

typedef struct{
    char titulo[MAXCAR];
    char director[MAXCAR];
    int year;
}Pelicula;

int menu();
void verListado(Pelicula pelis[MAXPELICULAS], int numElem);
int addPelicula(Pelicula pelis[MAXPELICULAS], int numElem);
void editarPelicula(Pelicula pelis[MAXPELICULAS], int numElem, int indice);
int borrarPelicula(Pelicula pelis[MAXPELICULAS], int numElem, int indice);

void main()
{
    int opcion = 0, numElem = 0, indice;
    Pelicula pelis[MAXPELICULAS];
    while(opcion != 5){
        opcion = menu();
        if(opcion == 1){
            verListado(pelis, numElem);
        }
        else if(opcion == 2){
            numElem = addPelicula(pelis,numElem);
        }
        else if(opcion == 3){
            printf("Inserte el indice de la pelicula a editar: ");
            scanf("%d",&indice);
            scanf("%*c");
            editarPelicula(pelis,numElem,indice);
        }
        else if(opcion == 4){
            printf("Inserte el indice de la pelicula a borrar: ");
            scanf("%d", &indice);
            numElem = borrarPelicula(pelis,numElem,indice);
        }
        else
            puts("Inserta una opcion correcta.");
    }
}

int menu(){
    int opcion;
    puts("+---------------------------+");
    puts("|            MENU           |");
    puts("+---------------------------+");
    puts("  1. Ver lista de peliculas");
    puts("  2. Añadir una pelicula");
    puts("  3. Editar datos pelicula");
    puts("  4. Borrar pelicula");
    puts("  5. Salir");
    puts("-----------------------------");
    printf("Introduzca una opcion: ");
    scanf("%d",&opcion);
    scanf("%*c");
    return opcion;
}

void verListado(Pelicula pelis[MAXPELICULAS], int numElem){
    int i;
    for(i=0;i<numElem;i++){
        printf("Pelicula %d:\n",i);
        printf("\tTitulo: %s\n",pelis[i].titulo);
        printf("\tDirector: %s\n",pelis[i].director);
        printf("\tYear: %d\n",pelis[i].year);
        puts("");
        if( !( i+1 % 5 )){
            puts("Presiona una tecla para continuar...");
            getchar();
        }
    }
}

int addPelicula(Pelicula pelis[MAXPELICULAS], int numElem){
    int numElemUp;
    printf("Inserte el Titulo: ");
    gets(pelis[numElem].titulo);
    if(strcmp(pelis[numElem].titulo,"")){
        printf("Inserte el Director: ");
        gets(pelis[numElem].director);
        printf("Inserte el year: ");
        scanf("%d",&pelis[numElem].year);
        numElemUp = numElem+1;
    }
    else{
        fprintf(stderr, "Operacion Abortada.\n");
        numElemUp = numElem;
    }
    return numElemUp;
}

void editarPelicula(Pelicula pelis[MAXPELICULAS], int numElem, int indice){
    char auxTitulo[MAXCAR], auxDirector[MAXCAR], auxYear[MAXCAR];
    int year;
    printf("Pelicula %d:\n", indice);
    printf("\tTitulo: %s\n", pelis[indice].titulo);
    printf("\tDirector: %s\n", pelis[indice].director);
    printf("\tYear: %d\n", pelis[indice].year);
    puts("");
    printf("Nuevo Titulo: ");
    gets(auxTitulo);
    printf("Nuevo Director: ");
    gets(auxDirector);
    printf("Nuevo year: ");
    gets(auxYear);
    year = atoi(auxYear);
    if(strcmp(auxTitulo, "") && strcmp(auxDirector, "") && year != 0){
        strcpy(pelis[indice].titulo, auxTitulo);
        strcpy(pelis[indice].director, auxDirector);
        pelis[indice].year = year;
    }
    else{
        fprintf(stderr, "Operacion Abortada.\n");
    }
}

int borrarPelicula(Pelicula pelis[MAXPELICULAS], int numElem, int indice){
    int i;
    for(i=indice;i<numElem-1;i++){
        pelis[i] = pelis[i+1];
    }
    return numElem-1;
}
