/*
Autores:
    -Benjamin Donoso
    -David Ramirez
*/

//importacion de librerias necesarias para el funcionamiento del programa
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "funciones.h"

//main el cual recibe un argumento y doble puntero de char para el uso de getotp
int main(int argc, char **argv){
 
  time_t start_t2, end_t2;
  double diff_t2;
  time(&start_t2);
  //variables globales necesarias para el uso de las funciones y datos entregados
  //por compilacion
  char *nombreArchivo = NULL;
  char *nombreSalida = NULL;
  int nceldas;
  char c;
	int flag = 0;
  //delimitador de grafica de niceprint
	int Maximum = 5000;


  
  //el siguiente ciclo se utiliza para recibir los parametros de entrada usando getopt
  while ((c = getopt(argc, argv, "N:i:o:D")) != -1)
      switch (c){
      //N es el numero de celdas que contendra el arreglo de energia de particulas
      case 'N':
          sscanf(optarg,"%d", &nceldas);
          break;
      //i es el nombre del archivo de entrada
      case 'i':
          nombreArchivo= optarg;
          break;   
      //o es el nombre del archivo de salida                      
      case 'o':
          nombreSalida= optarg;
          break;
      //D es una bandera que permite el uso de niceprint
      case 'D':
          flag = 1;
          break;
          
      //protocolo de correcion si es que se entrega una opcion invalida
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
      //cancelacion del programa si no se especifica ningun uso o el protocolo
      //no fue capaz de evitar un error
      default:
          abort();
  }

//Si el numero de celdas es menor a 1, debera finalizar el programa
  if (nceldas < 1){
    printf("El numero de celdas N tiene que ser mayor o igual a 1\n");
    return 0;
  }

  int n, pos, error;
  Particula * listaP;
  //se lee el archivo y se extrae su contenido y el numero de particulas
  error=leerArchivo(nombreArchivo, &listaP, &n);

//si el archivo no existe (o no se pudo abrir) el programa termina.
  if (error == 1){
    return 0;
  }
  
  //crear arreglo de tamaño nceldas 
  float * celdas =(float*)malloc(sizeof(float)*(nceldas));

  // se inicializa cada valor del arreglo con un 0
  int iterador = 0;
  while(iterador < nceldas){
    celdas[iterador] = 0;
    iterador++;
  }

  //se acumula la energia y se obtiene la posicion de la celda con la mayor energia
  pos = AcumulacionEnergia(nceldas, n,  listaP, celdas);

  //se procede a escribir el archivo
  error=escribirArchivo( nombreSalida , celdas , nceldas, pos, celdas[pos] );
  //si no se pudo crear el archivo se saldra del programa
  if (error == 1){
    free(listaP);
    free(celdas);
    return 0;
  }

  //se usa la condicion de flag dada por -D la cual delimita el uso del niceprint
  if(flag == 1){
    printf("\n   %d  %f\n",pos,celdas[pos]);
    niceprint(nceldas,celdas,Maximum);
    printf("\n");
  }


  // se liberan los arreglos para optimizar el uso de memoria y evitar errores
  free(listaP);
  free(celdas);
  
  time(&end_t2);
  //Diferencia
  diff_t2 = difftime(end_t2, start_t2);

  printf("\nTiempo de ejecucion: %f segundos\n\n",diff_t2);

}
