/*
* Desarrolle este sistema con una estructura de tipo arbol
*
* Desarrrolle los metodos de insertar,busqueda,eliminar, llevar el conteo de las piezas

* Determine la cantidad de cajas producidas

* Desarrolle un menu principal para que el operario monitoree las opciones del sistema

* Haga la conexion a la base de datos desde C++ esto se tomara como punto extra en el proyecto
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Cook_Tree.h"
#include "Impregnate_Tree.h"

int main()
{
    menu();
    return 0;
}

bool endsWithZeroOrFive(int n) {
    return (n % 10 == 0) || (n % 10 == 5);
}

//--Las piezas se empacan en cajas de 5 unds.--
void CountBoxes(Cook_Node *cook, Impregnate_Node *impreg) {
    /*Declared Variables*/
    int cook_pieces = cook->cook.length,
    impregnate_pieces = impreg->impreg.length,
    boxes = 0;
    float total_pieces = 0.0,
        single_pieces = 0.0;

    /*Counted units for each box*/
    total_pieces = cook_pieces + impregnate_pieces;
    boxes = (cook_pieces + impregnate_pieces) / 5;

    /*Conditioning for printing boxes and single units*/
    if (boxes != 0 && endsWithZeroOrFive(boxes) == true){
        cout << " " << endl;
        cout << "There is a total of ";
        cout << boxes;
        cout << "boxes" << endl;
        cout << " " << endl;
        cout << "No units without package" << endl;
        cout << " " << endl;
    }
    else {
        boxes = boxes * 5;
        single_pieces = total_pieces - boxes;

        cout << " " << endl;
        cout << "There is a total of ";
        cout << boxes;
        cout << "boxes" << endl;
        cout << " " << endl;
        cout << "There are";
        cout << single_pieces << endl;
        cout << "units without package" << endl;
        cout << " " << endl;
    }
};

void menu() {

};
