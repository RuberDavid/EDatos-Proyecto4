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
 *						A
 *
 *
 *				AB					B
 *
 *
 *		ABC			AC		BC					C
 *
 *				
 *				ACB		 BCA     	BA			CA
 *								
 *							BAC			CAB		CB
 *											
 *											CBA
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

	void right_eq_replaceLastMv( BinTree *someTree, BinTreeNode *someNode);
	void left_eq_concatNextMv(   BinTree *someTree, BinTreeNode *someNode);//TODO

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

	right_eq_replaceLastMv( tree,  node );//estas dos son recursivas, así que crea e inicializa todo el árbol de juego
	left_eq_concatNextMv(   tree,  node );
	
	return;

}
/*****************************************************************************
 *
 * 	Inserta en el nodo derecho un nodo con otra posible jugada actual
 * 	(remplaza la anterior)
 * 	y se llama a si misma y a left_eq_concatNextMv en sus hijos
 *
 *****************************************************************************/

void right_eq_replaceLastMv( BinTree *someTree, BinTreeNode *someNode)
{

	Info *infonode;//TODO  inicializar y pasar
	char* other=NULL;//esta se la meto a mi nodo
	char aux[NUM_OF_MOVES];//con esta manipulo mi cadena
	char next='0';
	size_t len;

	//Aloja memoria para miembro para los DATOS del nodo
	if( (infonode = (Info*)malloc( sizeof(Info) ) ) == NULL )
	{
		fprintf(stderr,"error al alojar memoria para un info");
		return;
	}
	//NOTA: no se necesita alojar memoria pal nodo por que esto lo hace la
	//	función bintree_ins_rigt y la otra similar a esa

	//copia la cadena del nodo pasado para facilitar el manejo
	strcpy( aux, bintree_moves( someNode ) );

	//como el miebro moves del nodo a insertar debe de ser de la misma longitúd, 
	//se obtiene primero esta
	len=strlen( aux );
	


	//De el complemento de jugadas totales y las hechas hasta este punto
	//seleccióna la primera de estas en el orden que está en el arreglo global
	//si no, se ha terminado esta ramificación
	for(size_t i=0; i<NUM_OF_MOVES ; i++)
	{
		if( strchr( aux , Movimientos[i] ) != NULL )
		{
			next=Movimientos[i];
			//Remplaza el último mokvimento
			//Aloja memoria para la CADENA  mienbro moves de infonode
			if( (other = (char*)malloc( sizeof(char)*(len) ) == NULL ))
			{
				fprintf(stderr,"error al alojar memoria para una cadena");
				return;
			}

			strcpy( other, aux );
			other[len]=next;
			info_init( infonode, other, 0.0 );
			if( bintree_ins_rigt( tree, someNode, infonode ) != -1)
				fprintf(stderr, "Error al crear hijo izquierdo");

			//llama a las funciónes de llenado del árbol en ambos hijos
			//del nuevo nodo( que es el derecho del evaluado en la función
			//de arriba
			right_eq_replaceLastMv( bintree_right( someNode ) );
			left_eq_concatNextMv( bintree_left( someNode ) );
			break;
		}else
		{

			return;
		}
	}

}

/*****************************************************************************
 *
 * 	Inserta en el nodo izquierdo un nodo con la siguiente posible jugada
 * 	(del otro jugador)
 * 	y se llama a si misma y a left_eq_concatNextMv en sus hijos
 *
 *****************************************************************************/

void left_eq_concatNextMv(  BinTree *someTree, BinTreeNode *someNode)
{

}


