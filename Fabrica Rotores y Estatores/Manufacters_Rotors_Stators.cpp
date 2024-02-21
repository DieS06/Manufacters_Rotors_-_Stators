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

using namespace std;

Impregnate::Impregnate() {};
Impregnate::Impregnate(float resistance, float magneticField, float voltage, Impregnate::partType type) { };
Cook::Cook() {};
Cook::Cook(float tempreature, float humidity, float pressure, Cook::partType type) { };

Impregnate_Node* impregnate_tree = nullptr;
Cook_Node* cook_tree = nullptr;

bool endsWithZeroOrFive(int n) {
    return (n % 10 == 0) || (n % 10 == 5);
}

//--Las piezas se empacan en cajas de 5 unds.--
void CountBoxes(Cook_Node* cook_tree, Impregnate_Node* impregnate_tree) {
    /*Declared Variables*/
    int cook_pieces = cook_tree->length,
        impregnate_pieces = impregnate_tree->length,
        boxes = 0;
    float total_pieces = 0.0, single_pieces = 0.0;

    /*Counted units for each box*/
    total_pieces = cook_pieces + impregnate_pieces;
    boxes = (cook_pieces + impregnate_pieces) / 5;

    /*Conditioning for printing boxes and single units*/
    if (boxes != 0 && endsWithZeroOrFive(boxes) == true) {
        cout << " " << endl;
        cout << "There is a total of ";
        cout << boxes;
        cout << " boxes." << endl;
        cout << " " << endl;
        cout << "No units without package " << endl;
        cout << " " << endl;
    }
    else {
        boxes = boxes * 5;
        single_pieces = total_pieces - boxes;
        cout << " " << endl;
        cout << "There is a total of ";
        cout << boxes;
        cout << " boxes." << endl;
        cout << " " << endl;
        cout << "There are ";
        cout << single_pieces;
        cout << " units without package" << endl;
        cout << " " << endl;
    }
};

void menu() {
    int opt, option, count = 0;
    int counter = 0;
    float temp = 0.0, hum = 0.0, press = 0.0;
    float magn = 0.0, volt = 0.0, resist= 0.0;

    bool foundImpregnate = false, foundCook = false;

    do {
        cout << "\t.........MAIN_MENU.........\n";
        cout << "\t......... Processes.........\n";
        cout << "1. Insert Nodes\n";
        cout << "2. Search Nodes\n";
        cout << "3. Delete Nodes\n";
        cout << "4. Show Trees\n";
        cout << "\t..............................\n";
        cout << "5. Count Boxes Report\n";
        cout << "0. Exit\n";
        cout << "OPTION: ";
        cin >> opt;

        switch (opt) {
            case 1:
                do {
                    cout << "\t......... Insert Node.........\n";
                    cout << "1. Insert Cook Node\n";
                    cout << "2. Insert Impregnate Node\n";
                    cout << "0. Exit\n";
                    cout << "OPTION: ";
                    cin >> option;

                    switch (option) {
                    case 1:
                        cout << "\n";
                        cout << "Insert the temperature of the part:\n";
                        cin >> temp;
                        cout << "Insert the humidity of the part:\n";
                        cin >> hum;
                        cout << "Insert the pression of the part:\n";
                        cin >> press;
                        cout << "Insert the number for the type of part:\n";
                        cout << "0: Type_A\n";
                        cout << "1 : Type_B\n";
                        cin >> counter;

                        if (counter == 0) {
                            Cook one_cook(temp, hum, press, Cook::partType::Type_A);
                            Insert_Cook_Node(cook_tree, one_cook);
                        }
                        else if (counter == 1) {
                            Cook one_cook(temp, hum, press, Cook::partType::Type_B);
                            Insert_Cook_Node(cook_tree, one_cook);
                        }
                        else {
                            cout << "Incorrect value inserted!\n";
                            cout << "Please, insert 0 for Type_A or 1 for Type_B." << endl;
                        }
                        cout << "\n";
                        system("pause");
                        break;

                    case 2:
                        cout << "\n";
                        cout << "Insert the resistance of the part:\n";
                        cin >> resist;
                        cout << "Insert the manetic field of the part:\n";
                        cin >> magn;
                        cout << "Insert the voltage of the part:\n";
                        cin >> volt;
                        cout << "Insert the number for the type of part:\n";
                        cout << "0 : MQ2\n";
                        cout << "1 : Termocupla\n";
                        cout << "2 : Laser\n";
                        cin >> counter;

                        if (counter == 0) {
                            Impregnate new_impregnate (resist, magn, volt, Impregnate::partType::MQ2);
                            Insert_Impregnate_Node(impregnate_tree, new_impregnate);
                        }
                        else if (counter == 1) {
                            Impregnate new_impregnate (resist, magn, volt, Impregnate::partType::TERMOCUPLA);
                            Insert_Impregnate_Node(impregnate_tree, new_impregnate);
                        }
                        else if (counter == 2) {
                            Impregnate new_impregnate (resist, magn, volt, Impregnate::partType::LASER);
                            Insert_Impregnate_Node(impregnate_tree, new_impregnate);
                        }
                        else {
                            cout << "Incorrect value inserted!\n";
                            cout << "Please, insert 0 for MQ2 or 1 for Termocupla or 2 for Laser." << endl;
                        }
                        cout << "\n";
                        system("pause");
                        break;
                    }                     
                } while (option != 0);
                break;
                /*End of Insert Node*/
            case 2:
                do {
                    cout << "\t......... Search Node.........\n";
                    cout << "1. Search Cook Node\n";
                    cout << "2. Search Impregnate Node\n";
                    cout << "0. Exit\n";
                    cout << "OPTION: ";
                    cin >> option;

                    switch (option) {
                    case 1:
                        cout << "Searching Cook Node..." << endl;
                        cout << "Enter the temperature to search for:\n";
                        cin >> temp;

                        foundCook = Search_Cook_Node(cook_tree, temp);

                        if (foundCook) {
                            cout << "Cook Node with temperature " << temp << " found." << endl;
                        }
                        else {
                            cout << "Cook Node with temperature " << temp << " not found." << endl;
                        }
                        break;

                    case 2:
                        cout << "Searching Impregnate Node..." << endl;
                        cout << "Enter the resistance to search for:\n";
                        cin >> resist;

                        foundImpregnate = Search_Impregnate_Node(impregnate_tree, resist); // No se utilizan magneticF y volt, por lo que se pasan como 0

                        if (foundImpregnate) {
                            cout << "Impregnate Node with resistance " << resist << " found." << endl;
                        }
                        else {
                            cout << "Impregnate Node with resistance " << resist << " not found." << endl;
                        }
                        break;
                        }
                    system("pause");          
                } while (option != 0);
                break;
                /*End of Search Node*/
            case 3:
                do {
                    cout << "\t......... Delete Node.........\n";
                    cout << "1. Delete Cook Node\n";
                    cout << "2. Delete Impregnate Node\n";
                    cout << "0. Exit\n";
                    cout << "OPTION: ";
                    cin >> option;

                    switch (option) {
                    case 1:
                        cout << "Deleting Cook Node..." << endl;
                        cout << "Enter the temperature to delete:\n";
                        cin >> temp;
                        //Destroy_Cook_Node(cook_tree, );
                        break;

                    case 2:
                        cout << "Deleting Impregnate Node..." << endl;
                        cout << "Enter the resistance to delete:\n";
                        cin >> resist;
                        //Destroy_Cook_Node(impregnate_tree, );
                        break;
                    }
                } while (option != 0);
                break;
                /*End of Delete Node*/
            case 4:
                do {
                    cout << "\t......... Show Tree.........\n";
                    cout << "1. Show Cook Tree\n";
                    cout << "2. Show Impregnate Tree\n";
                    cout << "0. Exit\n";
                    cout << "OPTION: ";
                    cin >> option;

                    switch (option) {
                    case 1:
                        cout << "Cook Tree..." << endl;
                        Show_Cook_Tree(cook_tree, count);
                        system("pause");
                        break;

                    case 2:
                        cout << "Impregnate Tree..." << endl;
                        Show_Impregnate_Tree(impregnate_tree, count);
                        system("pause");
                        break;
                    }
                } while (option != 0);
                break;
                /*End of Show Tree*/

            case 5:
                cout << "\t......... Number of Boxes | Report.........\n";
                CountBoxes(cook_tree, impregnate_tree);
                break;
                /*End of Count Boxes*/

            default:
                cout << "\nInvalid option. Please try again.\n";
                break;
        }
        // Clean prompt
        cout << endl;
        system("pause");
        system("cls");
    } while (opt != 0);
};

int main()
{
    menu();
    return 0;
}




