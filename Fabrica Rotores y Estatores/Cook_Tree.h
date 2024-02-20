#ifndef COOK_TREE_H_INCLUDED
#define COOK_TREE_H_INCLUDED

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Cook {
	/*Tree variable temperature*/
    float temperature;
    float humidity;
    float pressure;
	enum class partType {
		Type_A,
		Type_B
	};

	/*Constructor*/
	Cook();
	Cook(float temperature, float humidity, float pressure, partType type);
};

typedef struct Cook_Node {
    int length;
    Cook cook;
	Cook_Node* right = nullptr;
	Cook_Node* left = nullptr;
}Cook_Node;

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
void Insert_Cook_Node(Cook_Node*& tree, Cook cook) {
    float root;
    if (tree == NULL) {
        Cook_Node* newCook = Create_Cook_Node(cook);
        tree = newCook;
    }
    else {
        root = tree->cook.temperature;
        if (root < 30.8) {

            Insert_Cook_Node(tree->left, cook);
            tree->length++;
        }
        else {
            Insert_Cook_Node(tree->right, cook);
        }
    }
}

/*SEARCH COOK NODE*/
bool Search_Cook_Node(Cook_Node* root, float targetTemperature) {
    if (root == nullptr) {
        return false;
    }
    if (root->cook.temperature == targetTemperature) {
        return true;
    }
    if (targetTemperature < root->cook.temperature) {
        return Search_Cook_Node(root->left, targetTemperature);
    }
    else {
        return Search_Cook_Node(root->right, targetTemperature);
    }
}

/*DELETE COOK NODE*/
void Destroy_Cook_Node(Cook_Node* cook) {
    if (cook != nullptr) {
        Destroy_Cook_Node(cook->left);
        Destroy_Cook_Node(cook->right);
        delete cook;
    }
}

/*SHOW TREE*/
void Show_Cook_Tree(Cook_Node*& cook_tree, int cont) {
    if (cook_tree == nullptr) {
        return;
    }
    else {
        Show_Cook_Tree(cook_tree->right, cont + 1);
        for (int i = 0; i < cont; i++) {
            std::cout << "  ";
        }
        cout << cook_tree->cook.temperature << endl;
        Show_Cook_Tree(cook_tree->left, cont + 1);
    }
};

#endif //COOK_TREE_H_INCLUDED