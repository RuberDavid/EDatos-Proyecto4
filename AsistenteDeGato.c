#define BUILDING 0 //TODO: quitar este y los #if

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
#include <string.h>

#include "bintree.h"

#define NUM_OF_MOVES 9


//arreglo global 
char Movimientos[]="ABCDEFGHI";

typedef struct _Info
{
	char* moves;
	double probOfWin;
} Info;

/*****************************************************************************
 *
 *	Inicializa un Info
 *	ADVERTENCIA: no aloja memoria para el miembro moves
 *
 *****************************************************************************/
void info_init( Info* myinfo, char* mystring, double myfloat );


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
 *	Función para borrar datos de nodos del tipo Info
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
#if BUILDING
	fillMoves( &arbolDJuego );


#endif
	bintree_destroy( &arbolDJuego );
}

void info_init( Info* myinfo, char* mystring, double myfloat )
{

	myinfo->moves= mystring;
	myinfo->probOfWin= myfloat;

	return;
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
	Info inforoot;
	char* mystring;


	if( (inforoot = (Info*)malloc( sizeof(Info) ) ) == NULL )
	{
		fprintf(stderr,"error al alojar memoria");
		return;
	}
	if( (mystring = (Info*)malloc( sizeof(char)*2 ) ) == NULL )
	{
		fprintf(stderr,"error al alojar memoria");
		return;
	}


	info_init( inforoot, mystring , 0.0 ); 

	//insertar el primer movimiento en  la raiz
	bintree_ins_left( tree, NULL, inforoot ); 

	node= bintree_root(tree);

	right_eq_replaceLastMv( node );
	left_eq_concatNextMv( node );
	
	return;

}
/*****************************************************************************
 *
 * 	Inserta en el nodo derecho un nodo con otra posible jugada actual
 * 	(remplaza la anterior)
 * 	y se llama a si misma y a left_eq_concatNextMv en sus hijos
 *
 *****************************************************************************/

void right_eq_replaceLastMv( BinTree *sometree, BinTreeNode *someNode)
{
	bool not_moved( char move, char* done , size_t len );//TODO

	Info *infonode;//TODO  inicializar y pasar
	char* other=NULL;
	char last[NUM_OF_MOVES];
	char next='0';
	size_t len;

	if( (infonode = (Info*)malloc( sizeof(Info) ) ) == NULL )
	{
		fprintf(stderr,"error al alojar memoria");
		return;
	}
	
	//copia la cadena del nodo pasado para facilitar el manejo
	strcpy( last, bintree_moves( someNode ) );
	len=strlen( last );
	if( (other = (char*)malloc( sizeof(char)*(len) ) == NULL ))
	{
		fprintf(stderr,"error al alojar memoria");
		return;
	}

	//encuéntra el siguiente movimiento posible
	for(size_t i=0; i<NUM_OF_MOVES ; i++)
	{
		//Busca en el arreglo global de jugadas
		//si ya se ha hecho la i-esima jugada
		//si no, se seleccióna como la que hay que remplazar
		//y se sale del for
		if( not_moved( Movimientos[i], last, len) )
		{
			next=Movimientos[i];
			break;
		}
	}

	
	if( next != '0' )
	{
		last[len]=next;
		strcpy(other, last );
		bintree_ins_right( 

	bintree_ins_right(
	
}
/*****************************************************************************
 *
 * 	Inserta en el nodo izquierdo un nodo con la siguiente posible jugada
 * 	(del otro jugador)
 * 	y se llama a si misma y a left_eq_concatNextMv en sus hijos
 *
 *****************************************************************************/

void left_eq_concatNextMv(  BinTree *sometree, BinTreeNode *someNode)
{

}

