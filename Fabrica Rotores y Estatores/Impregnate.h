/*
* Condiciones:
* Si la temperatura es mayor de 30.8, la pieza esta dañada, de lo contrario esta lista para exportar.
*
* Constantes:
* daño: 30.8
*/
#ifndef IMPREGNATE_H
#define IMPREGNATE_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Impregnate {

private:
	float magneticfield;
	float voltage;
	float resistance;

public:
	enum class partType {
		MQW,
		TERMOCUPLA,
		LASER
	};

	//Constructors
	Impregnate();
	Impregnate(float magneticfield, float voltage, float resistance, enum partType);

	// Destructor
	~Impregnate();


	
	/*INSERT*/

	/*SEARCH*/

	/*DELETE*/

	/*COUNT*/

};
#endif // IMPREGNATE_H_INCLUDED