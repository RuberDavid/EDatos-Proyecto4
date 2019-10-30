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
 * 	Funciónes con argumento puntero a nodo y que funciónan como interfaz
 * 	para las jugadas miembro y la probabilidad de ganar de cada nodo
 *
 *****************************************************************************/
#define bintree_moves(node) ( ((node)->data)->moves )
#define bintree_probOfWin(node) ( ((node)->data)->probOfWin )

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
void fillMoves( BinTree *tree);

/*****************************************************************************
 *	
 * 	Calcula recursivamente la probabilidad de éxito de cada jugada dado un
 *	nodo
 *
 *****************************************************************************/
double fillPrblty( BinTreeNode *node );

// TODO: esta declaración va adentro de fillPrblty
double evalMove( BinTreeNode *node );


/*****************************************************************************
 *
 * ------------------------------MAIN-----------------------------------------
 *
 *****************************************************************************/


int main()
{
	BinTree arbolDJuego;

	bintree_init( &arbolDJuego, destroy );
	
	fillMoves( &arbolDJuego );



	bintree_destroy( &arbolDJuego );
}


void destroy(void* data)
{	
	free( data->moves );
	free( data );
}

void fillMoves( BinTree *tree)
{
	/*****************************************************************************
	 *
	 * 	funciónes recursivas para llenar el árbol con todas las jugadas
	 *
	 *****************************************************************************/

	void right_eq_replaceLastMv( BinTree *sometree, BinTreeNode *someNode);
	void left_eq_concatNextMv(   BinTree *sometree, BinTreeNode *someNode);

	BinTreeNode *node;
	char * fstMv; //first Move

	if( (fstMv = (char*)malloc( sizeof(char) + 1 ) ) == NULL )
	{
		fprintf(stderr,"error al alojar memoria");
		return;
	}

	//insertar el primer movimiento en  la raiz
	bintree_ins_left( tree, NULL, fstMv );

	node= bintree_root(tree);

	right_eq_replaceLastMv( node );
	left_eq_concatNextMv( node );
	
	return;

}
/*****************************************************************************
 *
 * 	Inserta en el nodo derecho un nodo otra posible jugada actual
 * 	y se llama a si misma y a left_eq_concatNextMv en sus hijos
 *
 *****************************************************************************/

void right_eq_replaceLastMv( BinTree *sometree, BinTreeNode *someNode)
{
	char* othermove;
	size_t len;
	len=strlen( bintree_moves( someNode ) );
	if( (othermove = (char*)malloc( len*sizeof(char) ) ) == NULL )//SPECIFY width
	{
		fprintf(stderr,"error al alojar memoria");
		return;
	}


	bintree_ins_right(
	
}
/*****************************************************************************
 *
 * 	Inserta en el nodo izquierdo un nodo con la siguiente posible jugada
 * 	(del otro jugador y se llama a si misma y a left_eq_concatNextMv en
 * 	sus hijos
 *
 *****************************************************************************/

void left_eq_concatNextMv(  BinTree *sometree, BinTreeNode *someNode)
{

}

