#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#include "estructuras.h"


//Funcion la cual lee el archivo con datos para el mapa
int leerArchivo(char * nombre , Particula **lista, int * cantidad){
  int n;
  Particula * listaP = NULL;
  //se abre el archivo en modo lectura
	FILE *archivo =fopen(nombre , "r");
	//Se comprueba que el archivo no sea nulo
	if(archivo == NULL){
		printf("El archivo de entrada no existente o esta corrompido\n");
		return 1;
 	}
   
 	//Si el archivo no es nulo, se tienen datos, se obtienen y se añaden a la lista.
	else{
    fscanf(archivo , "%d" , &n);
    listaP =(Particula*)malloc(sizeof(Particula)*(n));
    for(int i = 0; i < n; i++){
      int posicionParticula;
      int energiaParticula;
      fscanf(archivo , "%d %d " ,&posicionParticula ,&energiaParticula);
      listaP[i].posicion = posicionParticula;
      listaP[i].energia = energiaParticula;
    }
    //se entrega la lista de particulas a main
    *lista = listaP;
	}

  fclose(archivo);  
  //se entrega el numero de particulas a main
  *cantidad = n;
  return 0;

}
//aplicacion de la ecuacion de energia
 float Energia(int N, int i , int j , float Ep ){
    float E= 0;
    float MIN_ENERGY = 0;
    MIN_ENERGY = pow(10,-3) / N;
    E =  (pow(10,3) * Ep)/(N*(sqrt(abs(j-i)+1)));
    if(E >= MIN_ENERGY){
      return E;
    }
    
    return 0;
    
    
}

int escribirArchivo( char * nombre , float * celdas , int n,int pos, float max){
  //se abre el archivo en modo escritura
  FILE *archivo =fopen(nombre , "wt");
  //Se comprueba que el archivo no sea nulo
  if(archivo == NULL){
    printf("No se ha podido abrir el fichero\n");
    return 1;
  }
  //Si el archivo no es nulo, se escribe la energia de las celdas
  else{
    fprintf(archivo, "%d %f\n", pos, max);
    for(int i = 0; i < n ; i++){
      fprintf(archivo, "%d %f\n", i, celdas[i]);
    }
  }
  return 0;
}

//funcion la cual le da la energia a las celdas
int AcumulacionEnergia(int nC, int nP, Particula * listaP, float * listaC){
float max = 0;
int pos = 0;
//doble ciclo que recorre las celdas y particulas y le asigna la energia celda por celda
	for(int i = 0 ; i < nC; i++){
		for(int j = 0 ; j < nP; j++){
      //Acumular energia
			listaC[i] = listaC[i]  + Energia(nC,i,listaP[j].posicion, listaP[j].energia );

    // si la energia maxima actual es menor a listaC[i], entonces se reemplaza
     if (listaC[i]>max){
			 max = listaC[i];
			 pos = i; 
		 } 
    }
	}
  return pos;
  
}