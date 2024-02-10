#pragma once
#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Nodo {

	int data;
	Nodo* der;
	Nodo* izq;

};

Nodo* arbol = nullptr;

Nodo* Create_Node(int n) {

	//Sintaxis de C++
	Nodo* nuevo = new Nodo();
	nuevo->data = n;
	nuevo->der = nullptr;
	nuevo->izq = nullptr;

	return nuevo;
};

void insert_Node(Nodo*& arbol, int n) {

	int root;

	//Condicion para comprobar si el árbol esta vacio
	if (arbol == nullptr) {
		//Si esta vacio, crea un nuevo nodo y lo inserta en el árbol
		Nodo* nuevo = Create_Node(n);
		arbol = nuevo;
	}
	else {
		//Condicionar de que lado entra el dato, 
		root = arbol->data;
		if (n < root) {
			//si es menor que la raiz izquierda,
			insert_Node(arbol->izq, n);
		}
		//si es mayor, derecha.
		else {
			insert_Node(arbol->der, n);
		}
	}
};
void show_Tree(Nodo*& arbol, int cont) {
	if (arbol == nullptr) {
		return;
	}
	else {
		show_Tree(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++) {
			std::cout << "  ";
		}
		cout << arbol->data << endl;
		show_Tree(arbol->izq, cont + 1);
	}
};
bool Search_Node_Tree(Nodo* arbol, int n) {
	if (arbol == NULL) {
		return false;
	}
	else if (arbol->data == n) {
		return true;
	}
	else if (n < arbol->data) {
		return Search_Node_Tree(arbol->izq, n);
	}
	else {
		return Search_Node_Tree(arbol->der, n);
	}
}

#endif //ARBOL_H_INCLUDED