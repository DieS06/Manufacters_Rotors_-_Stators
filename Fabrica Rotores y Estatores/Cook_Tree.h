/*Si la temperatura a la pieza se mayor a 30.8 
la pieza estara mala, de lo contrario esta buena.*/

#ifndef COOK_TREE_H_INCLUDED
#define COOK_TREE_H_INCLUDED

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct Cook_Node {
	Cook cook;
	Cook_Node* right;
	Cook_Node* left;
}Cook_Node;

typedef struct Cook {
	int length;
	/*Tree variable temperature*/
	float temperature;
	float humidity;
	float pressure;
	enum class partType {
		Type_A,
		Type_B
	};
}Cook;

Cook_Node* cook_tree = nullptr;

/*CREATE COOK NODE*/
Cook_Node* Create_Cook_Node(Cook cook) {
	Cook_Node* newCook = new Cook_Node();
	newCook->cook = cook;
	newCook->right = NULL;
	newCook->left = NULL;

	return newCook;
}

/*INSERT COOK NODE*/
void insert_Cook_Node(Cook_Node*& tree, Cook cook) {
	float root;
	if (tree == NULL) {

		Cook_Node* newCook = Create_Cook_Node(cook);
		tree = newCook;
	}
	else {

		root = tree->cook.temperature;
		if (root < 30.8) {

			insert_Cook_Node(tree->left, cook);
		}
		else {
			insert_Cook_Node(tree->right, cook);
		}
	}
}

/*SEARCH COOK NODE*/
bool search_Cook_Node();

/*DELETE COOK NODE*/
void destroy_Cook_Node(Cook_Node *cook);

#endif //COOK_TREE_H_INCLUDED