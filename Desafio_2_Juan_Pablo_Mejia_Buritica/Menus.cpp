#include <iostream>

using namespace std;

void menu_anfitrion()
{
    cout <<endl;
    cout <<"Bienvenido usuario anfitrion"<<endl;

    int opcion;
    while (true) {
    cout <<"Elija una opcion"<<endl;
    cout <<"1. Anular reservacion"<<endl;
    cout <<"2. Consurtal reservaciones"<<endl;
    cout <<"3. Actualizar historico"<<endl;
    cout <<"0. Salir"<<endl;
    cin >> opcion;

    switch (opcion) {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    default:
        return;
    }
    }
}

void menu_huesped()
{
    cout <<endl;
    cout <<"Bienvenido usuario huesped"<<endl;

    int opcion;
    while (true) {
        cout <<"Elija una opcion"<<endl;
        cout <<"1. Reservar alojamiento"<<endl;
        cout <<"2. Anular reservacion"<<endl;
        cout <<"0. Salir"<<endl;
        cin >> opcion;

        switch (opcion) {
        case 1:

            break;
        case 2:

            break;
        default:
            return;
        }
    }
}
