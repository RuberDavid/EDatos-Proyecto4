/*****************************************************************************
 *
 *  Header para librería para el uso de árboles 
 *
 *  Atención, se deve de crear una función para destruir
 *  los datos asignados a los nodos
 *
 *****************************************************************************/
#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>

/*****************************************************************************
 *
 *	Estructura de un nodo
 *	que apunta a varios nodos
 *
 *****************************************************************************/
typedef struct _BinTreeNode
{
	void* data;

	struct _BinTreeNode* right;
	struct _BinTreeNode* left;

} BinTreeNode;

/*****************************************************************************
 *
 * 	Estructura de árbol
 *
 *****************************************************************************/

typedef struct _BinTree
{
	size_t size;

	//función definida por el usuario para destruir datos
	void (*destroy)(void* data);

	BinTreeNode* root;
}

/*****************************************************************************
 *
 * 	Interfaz de funciones
 *
 * 	NOTA: los macros con parametro se usan para mantener un estilo 
 * 		consistente con la interfaz del árbol.
 *
 *****************************************************************************/

/*****************************************************************************
 *
 * Inicializa arbol binario
 *
 *****************************************************************************/
void bintree_init(BinTree *tree, void (*destroy)(void *data));

/*****************************************************************************
 * 
 * Vacía un arbol
 *
 *****************************************************************************/
void bintree_destroy(BinTree *tree);

/*****************************************************************************
 * 
 * Inserta un nodo como el izquierdo de uno dado
 *
 *****************************************************************************/
int bintree_ins_left(BinTree *tree, BiTreeNode *node, const void *data);

/*****************************************************************************
 *
 * Inserta un nodo como el derecho de uno dado
 *
 *****************************************************************************/
int bintree_ins_right(BinTree *tree, BiTreeNode *node, const void *data);

/*****************************************************************************
 *
 * Borra nodo izquierdo
 *
 *****************************************************************************/
void bintree_rem_left(BinTree *tree, BiTreeNode *node);

/*****************************************************************************
 *
 * Borra nodo derecho
 *
 *****************************************************************************/
void bintree_rem_right(BinTree *tree, BiTreeNode *node);

/*****************************************************************************
 *
 * Obten tamaño del árbol
 *
 *****************************************************************************/
#define bintree_size(tree) ((tree)->size)

/*****************************************************************************
 *
 * Obten apuntador a raiz
 *
 *****************************************************************************/
#define bintree_root(tree) ((tree)->root)

/*****************************************************************************
 *
 * Determina si un nodo es nulo
 *
 *****************************************************************************/
#define bintree_is_eob(node) ((node) == NULL)

/*****************************************************************************
 *
 * Determina si un nodo es hoja
 *
 *****************************************************************************/
#define bintree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)

/*****************************************************************************
 *
 * Accede a los datos de un nodo
 *
 *****************************************************************************/
#define bintree_data(node) ((node)->data)

/*****************************************************************************
 *
 * Accede al hijo izquierdo
 *
 *****************************************************************************/
#define bintree_left(node) ((node)->left)

/*****************************************************************************
 *
 * Accede al hijo derecho
 *
 *****************************************************************************/
#define bintree_right(node) ((node)->right)

#endif



	


