/*
* Variables:
* tipo de sensor { MQ2, termocupla, laser}
* campo m�gnetico
* voltaje
* resistencia de la pieza
* 
* Condiciones:
* Si la resistencia es mayor a 5ohm esta da�ada, de lo contrario esta bien.
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
};

#endif //IMPREGNATE_H_INCLUDED