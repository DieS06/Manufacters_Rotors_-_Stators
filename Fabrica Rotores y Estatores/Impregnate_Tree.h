#ifndef IMPREGNATE_TREE_H_INCLUDED
#define IMPREGNATE_TREE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

struct Impregnate {
	/*Tree variable Voltage*/
	float magneticfield;
	float voltage;
	float resistance;
	enum class partType {
		MQ2,
		TERMOCUPLA,
		LASER
	};

	/*Constructor*/
	Impregnate();
	Impregnate(float resistance, float magneticfield, float voltage, partType type);
};

typedef struct Impregnate_Node {
	int length;
	Impregnate impregnate;
	Impregnate_Node* right = nullptr;
	Impregnate_Node* left = nullptr;
}Impregnate_Node;

//Impregnate_Node* impregnate_tree = nullptr;

/*CREATE IMPREGNATE NODE*/
Impregnate_Node* Create_Impregnate_Node(Impregnate impregnate) {
	Impregnate_Node* newImpregnate = new Impregnate_Node();
	newImpregnate->impregnate = impregnate;
	newImpregnate->right = NULL;
	newImpregnate->left = NULL;

	return newImpregnate;
}

/*INSERT IMPREGNATE NODE*/
void Insert_Impregnate_Node(Impregnate_Node*& impregnate_tree, Impregnate impregnate) {
float root;
	if (impregnate_tree == NULL) {
		//Impregnate Nodo1;
		//Nodo1.magneticfield = 0.0f;  // Establecemos el campo magnético en 0.0
		//Nodo1.voltage = 0.0f;  // Establecemos el voltaje en 0.0
		//Nodo1.resistance = 0.0f;  // Establecemos la resistencia en 0.0

		Impregnate_Node* newImpregnate = Create_Impregnate_Node(impregnate);
		impregnate_tree = newImpregnate;
	}else {
		root = impregnate_tree->impregnate.resistance;
		if (root < 5.0f) {

			Insert_Impregnate_Node(impregnate_tree->left, impregnate);
			impregnate_tree->length++;
		}
		else {
			Insert_Impregnate_Node(impregnate_tree->right, impregnate);
		}
	}
}

/*SEARCH IMPREGNATE NODE*/
bool Search_Impregnate_Node(Impregnate_Node* root, float ohm)
	{
		if (root == NULL) {
			return false;
		}
		else if (ohm == root->impregnate.resistance) { //Si el nodo es igual al nodo que se busca
			return true;
		}
		else if (ohm < root->impregnate.resistance) {
			return Search_Impregnate_Node(root->left, ohm);
		}
		else {
			return Search_Impregnate_Node(root->right, ohm);
		}
	}

/*DELETE IMPREGNATE NODE*/
void Destroy_Impregnate_Node(Impregnate_Node*& impregnate_tree, Impregnate* impregnate) {
	float ohm = impregnate->resistance;
	bool eliminateNode = Search_Impregnate_Node(impregnate_tree, ohm);

	if (eliminateNode == true) {
		Destroy_Impregnate_Node(impregnate_tree->left, impregnate);
		Destroy_Impregnate_Node(impregnate_tree->right, impregnate);
		delete impregnate;
	}
	else {
		cout << "The specified node doesn't exist." << endl;
	}
}

/*SHOW TREE*/
void Show_Impregnate_Tree(Impregnate_Node*& impregnate_tree, int cont) {
	if (impregnate_tree == nullptr) {
		return;
	}
	else {
		Show_Impregnate_Tree(impregnate_tree->right, cont + 1);
		for (int i = 0; i < cont; i++) {
			std::cout << "  ";
		}
		cout << impregnate_tree->impregnate.resistance << endl;
		Show_Impregnate_Tree(impregnate_tree->left, cont + 1);
	}
};

#endif //IMPREGNATE_TREE_H_INCLUDED