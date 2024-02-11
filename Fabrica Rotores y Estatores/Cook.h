/*
* Condiciones:
* Si la temperatura es mayor de 30.8, la pieza esta dañada, de lo contrario esta lista para exportar.
* 
* Constantes:
* daño: 30.8
*/
#ifndef COOK_H
#define COOK_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Arbol.h"

using namespace std;

class Cook {

private:
	float temperature;
	float humidity;
	float pressure;

public:
	enum class partType {
		 Type_A,
		 Type_B
	};

	//Constructors
	Cook();
	Cook(float temperature, float humidity, float pressure, enum partType);
	
	// Destructor
	~Cook();

	//Create the tree structure for Cook class. 
	Node* treeCook = nullptr;

	/*INSERT*/

	/*SEARCH*/

	/*DELETE*/

	/*COUNT*/

};
#endif // COOK_H_INCLUDED

