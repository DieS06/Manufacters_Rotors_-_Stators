#pragma once
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node {

	int data;
	Node* right;
	Node* left;
};

Node* tree = nullptr;

Node* Create_Node(int n) {

	//Sintax of C++
	Node* newNode = new Node();
	newNode->data = n;
	newNode->right = nullptr;
	newNode->left = nullptr;

	return newNode;
};

void insert_Node(Node*& tree, int n) {

	int root;

	//Condition to prove if the tree is empty.
	if (tree == nullptr) {
		//If it is empty, create a new node and insert it to the tree.
		Node* newNode = Create_Node(n);
		tree = newNode;
	}
	else {
		//Condition for the entry side of data in the tree,
		root = tree->data;
		if (n < root) {
			//If it is minor than the root, it goes left,
			insert_Node(tree->left, n);
		}
		//If it is mayor, it goes right.
		else {
			insert_Node(tree->right, n);
		}
	}
};

void show_Tree(Node*& tree, int cont) {
	if (tree == nullptr) {
		return;
	}
	else {
		show_Tree(tree->right, cont + 1);
		for (int i = 0; i < cont; i++) {
			std::cout << "  ";
		}
		cout << tree->data << endl;
		show_Tree(tree->left, cont + 1);
	}
};

bool Search_Node_Tree(Node* tree, int n) {
	if (tree == NULL) {
		return false;
	}
	else if (tree->data == n) {
		return true;
	}
	else if (n < tree->data) {
		return Search_Node_Tree(tree->left, n);
	}
	else {
		return Search_Node_Tree(tree->right, n);
	}
}

#endif //TREE_H_INCLUDED