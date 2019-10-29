/*****************************************************************************
 *
 *****************************************************************************/
/*****************************************************************************
 *	Diseño del tablero:
 *
 *		 A | B | C
 *		___|___|___
 *		 D | E | F
 *		___|___|___
 *		 G | H | I
 *		   |   |
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"


//arreglo global 
char tablero[]="ABCDEFGHI";

typedef struct _info
{
	char* moves;
	double probOfWin;
} info;

/*****************************************************************************
 *	
 *	Función para borrar datos de nodos del tipo info
 *
 *****************************************************************************/
void destroy(void* data);

/*****************************************************************************
 *	
 *	LLena árbol con jugadas
 *
 *****************************************************************************/
void fillMvs( BinTree *tree);

/*****************************************************************************
 *	
 * 	Calcula recursivamente la probabilidad de éxito de cada jugada dado un
 *	nodo
 *
 *****************************************************************************/
double fillPrblty( BinTreeNode *tree);

double eval( ) //TODO HERE




int main()
{
	BinTree arbolDJuego;

	bintree_init( &arbolDJuego, destroy );




}


void destroy(void* data)
{	
	free( data->moves );
	free( data );
}

