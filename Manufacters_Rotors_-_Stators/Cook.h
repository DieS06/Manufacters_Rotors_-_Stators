/*
* Variables:
* temperatura
* humedad
* presi�n
* tipo de pieza{ tipo A, tipo B}
* 
* Condiciones:
* Si la temperatura es mayor de 30.8, la pieza esta da�ada, de lo contrario esta lista para exportar.
* 
* Constantes:
* da�o: 30.8
* 
* --Las piezas se empacan en cajas de 5 unds.--
* 
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
	Nodo* treeCook = nullptr;

	/*INSERT*/

	/*SEARCH*/

	/*DELETE*/

	/*COUNT*/
};



#endif // COOK_H_INCLUDED

