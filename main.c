#include <stdio.h>
#include <stdlib.h>
#define TAM 250
#define MAXCAR 100

typedef char Cadena[MAXCAR];

typedef struct{
    Cadena cadena;
    double numero;
}Entrada;

typedef Entrada TablaEntrada[TAM];

typedef struct{
    double media;
}Salida;

int menuPricipal();
int leerDatos(TablaEntrada tabla1);
int mostrarInformacion(TablaEntrada tabla1, int numElem);
int submenuOperaciones(TablaEntrada tabla1, int numElem);
Salida mediaNumero(TablaEntrada tabla1, int numElem);


void main()
{
    int opcion = 0, numElem = 0;
    TablaEntrada tabla1;
    while( opcion != 5 ){
        opcion = menuPricipal();

        if(opcion == 1){
            numElem = leerDatos(tabla1);
            printf("Se han leido %d datos.\n",numElem);
        }

        else if(opcion == 2){
            mostrarInformacion(tabla1,numElem);
        }

        else if(opcion == 3){
            submenuOperaciones(tabla1, numElem);
        }

        else if(opcion == 4){
            //
        }

        else if(opcion == 5)
            puts("Adios.");
        else
            puts("Inserta una opcion correcta");
    }
}

int menuPricipal(){
    int opcion = 0;
    puts("Menu Principal.-");
    puts("");
    puts("    1. Cargar datos");
    puts("    2. Mostrar informacion");
    puts("    3. Operaciones");
    puts("    4. Guardar resultados");
    puts("    5. Salir");
    printf("Inserte una opcion: ");
    scanf("%d",&opcion);
    scanf("%*c");
    return opcion;
}

int leerDatos(TablaEntrada tabla1){
    char nombreFichero[MAXCAR];
    printf("Inserte un nombre de fichero: ");
    scanf("%s",nombreFichero);
    FILE *f;
    int i = 1;
    f = fopen(nombreFichero,"r");
    if(f == NULL)
        fprintf(stderr,"Error opening file.\n");
    else{
        fscanf(f, "%s%lf", tabla1[0].cadena, &tabla1[0].numero);
        while( !feof(f) && i < TAM ){
            fscanf(f, "%s%lf", tabla1[i].cadena, &tabla1[i].numero);
            i++;
        }
        fclose(f);
    }
    return i-1;
}

int mostrarInformacion(TablaEntrada tabla1, int numElem){
    int i, elementos = 0;
    if(numElem == 0){
        puts("No se ha leido ningun elemento.");
    }
    else{
        printf("Cadena        Numero\n");
        printf("------        ------\n");
        for( i = 0; i < numElem; i++ ){
            printf("%-14s %.2f\n",tabla1[i].cadena,tabla1[i].numero);
        }
        elementos = numElem;
    }
    return elementos;
}

int submenuOperaciones(TablaEntrada tabla1, int numElem){
    int opcion, realizaOperacion = 0;
    puts("Submenu de Operaciones.-");
    puts("    1. Calcular promedio del campo real");
    puts("    2. Volver al menu principal");
    printf("Insert option: ");
    scanf("%d",&opcion);
    scanf("%*c");
    if( opcion == 1){
        realizaOperacion = 1;
        //mediaNumero(tabla1, numElem);
    }
    else{
        realizaOperacion = 0;
    }
    return realizaOperacion;
}

Salida mediaNumero(TablaEntrada tabla1, int numElem){
    int i;
    Salida salida1;
    double aux;
    for( i = 0; i < numElem; i++ ){
        aux += tabla1[i].numero;
    }
    salida1.media = aux/numElem;
    return salida1;
}

void guardarResultados(Cadena cadena1){
    FILE *f;
    f = fopen(cadena1,"w");
    if(f == NULL)
        fprintf(stderr,"Error in file.\n");
    else{
        //
        fclose(f);
    }
}
