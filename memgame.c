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

#define DTC   LIGHTGRAY
#define DBC   BLACK
#define CT    YELLOW
#define CB    BLUE

/* Prototipos de función */

void generateMatrix(int [][COL], int []);
void showMatrix(int [][COL], int, int);
void setColor(int, int);
void defaultColor();

int main()
{
   srand(time(NULL));

   int figures[FIG] = {1, 2, 3, 4, 5, 6, 15, 18}, *p_figures;
   p_figures = (int*)malloc(FIG*sizeof(int));

   int table[ROW][COL];

   generateMatrix(table, figures);
   free(p_figures);
   showMatrix(table, INI_X, INI_Y);

   return 0;
}

/*
   Función    : generateTable
   Argumentos : int matrix[][COL], pantalla que contendría las figuras a parear.
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
   Función    : showMatrix
   Argumentos : int matrix[][COL] : contiene las figuras que se mostrarán en pantalla.
                int x : posición inicial en "x".
                int y : posición inicial en "y".
   Objetivo   : mostrar las figuras del juego en una posición específica.
   Retorno    : ---
*/
void showMatrix(int matrix[][COL], int x, int y)
{
   int i, j, pos_x, pos_y;

   pos_x = x;
   pos_y = y;

   setColor(CT, CB);

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

   defaultColor();

   return;
}

/*
   Función    : setColor
   Argumentos : int ct : color del texto.
                int cb : color del fondo.
   Objetivo   : cambiar el color del texto y fondo.
   Retorno    : ---
*/
void setColor(int ct, int cb)
{
   textcolor(ct);
   textbackground(cb);
   return;
}

/*
   Función    :
   Argumentos : ---
   Objetivo   : establecer el los colores por defecto de la consola (fondo negro, texto gris)
   Retorno    : ---
*/
void defaultColor()
{
   setColor(DTC, DBC);
   return;
}
































