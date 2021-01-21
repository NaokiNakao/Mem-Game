#include <stdio.h>
#include <stdlib.h>
#include <conio.c>
#include <time.h>

/* Directivas de preprocesador */

#define TRUE    1
#define FALSE   0

#define ROW          4
#define COL          4
#define FIG          8
#define MAXASIGFIG   2
#define INI_X       10
#define INI_Y        5
#define ESP          4

#define CT  YELLOW
#define CF  BLUE

/* Prototipos de funci�n */

void generateMatrix(int [][COL], int []);
void showMatrix(int [][COL], int, int);

int main()
{
   srand(time(NULL));

   int figures[FIG] = {1, 2, 3, 4, 5, 6, 15, 18};
   int table[ROW][COL];

   generateMatrix(table, figures);
   showMatrix(table, INI_X, INI_Y);

   /*for ( int indfil = 0; indfil < FILA; indfil ++ )
   {
      for ( int indcol = 0; indcol < COLUMN; indcol ++ )
         printf("%1d ",pantalla[indfil][indcol]);
      printf("\n");
   }*/

   return 0;
}

/*
   Funci�n    : generateTable
   Argumentos : int matrix[][COL], pantalla que contendr�a las figuras a parear.
                int figures[], arreglo que contiene las figuras a colocar en la pantalla.
   Objetivo   : Asignar aleatoriamente un par de figuras en la pantalla.
   Retorno    : ---
*/
void generateMatrix(int matrix[][COL], int figures[])
{
   int row, col, count;

   for (int index = 0; index < FIG; index++)
   {
      count = 0;
      do{
         do{
            row = rand() % ROW;
            col = rand() % COL;
         }while (matrix[row][col] == 0);
         matrix[row][col] = figures[index];
         count++;
      }while (count != MAXASIGFIG);
   }

   return;
}

/*
   Funci�n    : showMatrix
   Argumentos : int matrix[][COL] : contiene las figuras que se mostrar�n en pantalla.
                int x : posici�n inicial en "x".
                int y : posici�n inicial en "y".
   Objetivo   : mostrar las figuras del juego en una posici�n espec�fica.
   Retorno    : ---
*/
void showMatrix(int matrix[][COL], int x, int y)
{
   int i, j, pos_x = x, pos_y = y;

   for (i = 0; i < ROW; i++)
   {
      for (j = 0; j < COL; j++)
      {
         gotoxy(pos_x, pos_y);
         printf("%c", matrix[i][j]);
         pos_x += ESP;
      }
      pos_x = x;
      pos_y++;
   }

   return;
}
































