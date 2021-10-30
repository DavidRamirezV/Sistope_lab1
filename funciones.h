#ifndef funciones_h_
#define funciones_h_
#include "estructuras.h"

//Entradas: int n el cual es el numero de celdas, float Energy es la posicion
//float maximum es la energia maxima de la celda.
//Funcionamiento: muestra un print con el arreglo de celdas de manera ordenada.
//Salidas: -
void extern niceprint(int N, float *Energy, float Maximum);

//Entradas: char nombre, el cual especifica el nombre del archivo a leerArchivo
//Particula ** lista es el arreglo en donde se guardaran las particulas con su estructura
//int cantidad, es la cantidad de particulas que se encuentran en el archivo
//Funcionamiento: lee el archivo linea por linea y obtiene su contenido, ademas lo guarda 
//en un arreglo de estrutuca de particulas
//Salidas: retorna un 0 o un 1 dependiendo si el archivo es correcto o esta bien escrito
int leerArchivo(char *nombre , Particula **lista, int * cantidad);

//Entradas: int N el cual es el numero de la celda, int i el cual la posicion de 
//en la celda de particulas, int j representa la posicion de impacto de la particu
//la en la celda, float Ep es el valor de energia con el cual la particula impacta 
//la celda
//Funcionamiento: a traves de n, i, j, Ep calcula la energia en la posicion de la
//celda otorgandole enrgia si esta es mayor a la energia minima
//Salidas: devuelve la energia que sera entregada a la celda si esta no es superior
//a la energia minima esta retornara 0
float Energia(int N, int i , int j , float Ep );

//Entradas: int nC cantidad de celdas, int nP cantidad de particulas, Particula * listaP 
//es una lista de particulas, float * listaC es la lista de las celdas con energia
//Funcionamiento: Acumula la energia de las particulas en la lista de celdas, dependiendo de 
//la ubicacion y energia de la particula 
//Salidas: retorna la posicion de la celda con mayor energia
int AcumulacionEnergia(int nC, int nP, Particula * listaP, float * listaC);

//Entradas: char * nombre string que indica el nombre del archivo de salida, float * celdas
//lista con las celdas de energia, int n es la cantidad de celdas, pos es la celda con la
//posicion maxima y float max es la fuerza maxima en la posicion pos
//Funcionamiento: crea un archivo de salida con los datos de celdas y sus energias
//Salidas: retorna un entero para saber si se creo o no el archivo sin problemas
int escribirArchivo( char * nombre , float * celdas , int n,int pos, float max);
#endif // funciones_h_