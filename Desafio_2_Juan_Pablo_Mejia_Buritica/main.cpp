#include <iostream>
#include "Funciones.h"
using namespace std;

int main()
{
    int opcion;
    cout << "elija 1 anfitiron, 2 huesped" <<endl;
    cin >> opcion;

    switch (opcion) {
    case 1:
        menu_anfitrion();
        break;
    case 2:
        menu_huesped();
        break;
    default:
        break;
    }

    return 0;
}
