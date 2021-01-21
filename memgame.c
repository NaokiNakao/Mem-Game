#include <stdio.h>
#include <stdlib.h>
#include <conio.c>
#include <time.h>

#define FILA   4
#define COLUMN 4
#define CANFIG 8
#define MAXASIGFIG 2

#define CT  YELLOW
#define CF  BLUE


void genpantalla(int [][COLUMN],int []);
void putpantallaxy(int [][COLUMN],int,int);

int main()
{
   srand(time(NULL));
   int figuras[CANFIG] = {1,2,3,4,5,6,15,18};

   //int pantalla[FILA][COLUMN], indfig = 0;

   /*for ( int indfil = 0; indfil < FILA; indfil ++ )
   {
      for ( int indcol = 0; indcol < COLUMN; indcol ++ )
         printf("%1d ",pantalla[indfil][indcol]);
      printf("\n");
   }*/

   return 0;

}

/*
   Función: genpantalla
   Argumentos: int pantalla[][COLUMN], pantalla que contendría
               las figuras a parear.
               int figuras[], arreglo que contiene las figuras
               a colocar en la pantalla.
   Objetivo: Asignar aleatoriamente un par de figuras en la pantalla.
   Retorno: ningún valor.
*/
void genpantalla(int pantalla[][COLUMN],int figuras[])
{
   int fila,columna, cont;
   for ( int ind = 0; ind < CANFIG; ind ++  )
   {
      cont = 0;
      do{
         do{
            fila = rand() % FILA;
            columna = rand() % COLUMN;
         }while ( pantalla[fila][columna] == 0 );
         pantalla[fila][columna] = figuras[ind];
         cont++;
      }while ( cont != MAXASIGFIG );
   }
}
































