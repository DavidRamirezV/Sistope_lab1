/*
Autores:
    -Benjamin Donoso
    -David Ramirez
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#include "funciones.h"

int main(int argc, char **argv){
//int getopt(int argc, char * const argv[],const char *optstring)
    char c;

    //el siguiente ciclo se utiliza para recibir los parametros de entrada usando getopt
    while ((c = getopt(argc, argv, "N:i:o:D")) != -1)
        switch (c)
        {
        case 'N':
            printf("N\n");
            break;
        case 'i':
            printf("i\n");
            break;                         
        case 'o':
            printf("o\n");    
            break;
        case 'D':
            printf("D\n");
            break;

        case '?':
            if (optopt == 'c')
                {
                    fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
                }

            else if (isprint(optopt))
                fprintf(stderr, "Opcion desconocida `-%c'.\n", optopt);

            else
                fprintf(stderr, "Opcion con caracter desconocido `\\x%x'.\n", optopt);
                
            return 1;

        default:
            abort();
    }

}