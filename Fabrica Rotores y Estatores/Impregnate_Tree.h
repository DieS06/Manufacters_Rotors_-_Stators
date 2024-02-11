/*Si la resistencia es mayor a 5ohm esta dañada, de lo 
contrario esta bien.*/

#ifndef IMPREGNATE_TREE_H_INCLUDED
#define IMPREGNATE_TREE_H_INCLUDED

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct Impregnate_Node {
	Impregnate impreg;
	Impregnate_Node* right;
	Impregnate_Node* left;
}Impregnate_Node;

typedef struct Impregnate {
	int length;
	/*Tree variable resistance*/
	float resistance;
	float voltage;
	float magneticField;
	enum class sensorType {
		MQ2,
		Termocupla,
		laser
	};
}Impregnate;

Impregnate_Node* impreg_tree = nullptr;

/*CREATE COOK NODE*/
Impregnate_Node* Create_Cook_Node(Impregnate* impreg);
/*INSERT COOK NODE*/
void insert_Cook_Node(Impregnate_Node*& impreg_tree);
/*SEARCH COOK NODE*/
bool search_Cook_Node();
/*DELETE COOK NODE*/
void destroy_Cook_Node(Impregnate_Node* impreg);

/*COUNT COOK NODE*/

#endif //IMPREGNATE_TREE_H_INCLUDED