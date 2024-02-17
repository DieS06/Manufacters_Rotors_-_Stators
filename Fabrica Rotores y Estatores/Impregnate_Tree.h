/*Si la resistencia de la pieza se mayor a 5 ohms, la pieza estara mala, de lo contrario esta buena.*/

#ifndef IMPREGNATE_TREE_H_INCLUDED
#define IMPREGNATE_TREE_H_INCLUDED

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
enum class partType {
	MQ2,
	TERMOCUPLA,
	LASER
};

typedef struct Impregnate_Node {
	Impregnate impregnate;
	Impregnate_Node* right;
	Impregnate_Node* left;
}Impregnate_Node;

typedef struct Impregnate {
	int length;
	/*Tree variable Voltage*/
	float magneticfield;
	float voltage;
	float resistance;
	enum class partType {
		MQ2,
		TERMOCUPLA,
		LASER
	};
}Impregnate;

Impregnate_Node* impregnate_tree = nullptr;

/*CREATE IMPREGNATE NODE*/
Impregnate_Node* Create_Impregnate_Node(Impregnate impregnate) {
	Impregnate_Node* newImpregnate = new Impregnate_Node();
	newImpregnate->impregnate = impregnate;
	newImpregnate->right = NULL;
	newImpregnate->left = NULL;

	return newImpregnate;
}

/*INSERT COOK NODE*/
void insert_Impregnate_Node(Impregnate_Node*& tree, Impregnate impregnate) {
	float root;

	Impregnate Nodo1;
	Nodo1.length = 0;  // Establecemos la longitud en 0
	Nodo1.magneticfield = 0.0f;  // Establecemos el campo magnético en 0.0
	Nodo1.voltage = 0.0f;  // Establecemos el voltaje en 0.0
	Nodo1.resistance = 5.0f;  // Establecemos la resistencia en 0.0


	Impregnate_Node* newImpregnate = Create_Impregnate_Node(Nodo1);
	tree = newImpregnate;


		root = tree->impregnate.resistance;
		if (root < impregnate.resistance) {

			insert_Impregnate_Node(tree->left, impregnate);
		}
		else {
			insert_Impregnate_Node(tree->right, impregnate);
		}
	}


/*SEARCH COOK NODE*/
bool Search_Node_Tree(Impregnate_Node* tree, float magneticF, float volt, float ohm ) { //Impregnate::partType type
	if (tree == NULL) {
		return false;
	}
	else if (magneticF == tree->impregnate.magneticfield && volt == tree->impregnate.voltage && ohm == tree->impregnate.resistance) { //Si el nodo es igual al nodo que se busca
		return true;
	}
	else if (ohm < tree->impregnate.resistance) {
		return Search_Node_Tree(tree->left, magneticF, volt, ohm);
	}
	else {
		return Search_Node_Tree(tree->right, magneticF, volt, ohm);
	}

}

/*DELETE COOK NODE*/
void destroy_Impregnate_Node(Impregnate_Node*& tree,Impregnate* impregnate, float magneticF, float volt, float ohm) {

	bool nodoElimated = Search_Node_Tree(tree, magneticF, volt, ohm);

	if (nodoElimated) {
	
		free (impregnate);

	}


}

#endif //COOK_TREE_H_INCLUDED