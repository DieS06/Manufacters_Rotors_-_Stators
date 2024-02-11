/*
* Condiciones:
* Si la resistencia es mayor a 5ohm esta dañada, de lo contrario esta bien.
* 
*/

#ifndef IMPREGNATE_H_INCLUDED
#define IMPREGNATE_H_INCLUDED

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Impregnate {

private:
	float resistance;
	float voltage;
	float magneticField;

public:
	enum class sensorType {
		MQ2,
		Termocupla,
		laser
	};

	//Constructors
	Impregnate();
	Impregnate(float resistance, float voltage, float magneticField, enum sensorType);

	// Destructor
	~Impregnate();

	/*INSERT*/

	/*SEARCH*/

	/*DELETE*/

	/*COUNT*/

};
#endif //IMPREGNATE_H_INCLUDED