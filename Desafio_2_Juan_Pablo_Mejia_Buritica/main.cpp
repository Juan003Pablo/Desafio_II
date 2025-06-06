#include <iostream>
#include "sistema_udeastay.h"

int main() {
    SistemaUdeAStay sistema;

    // Cargar datos desde archivos
    sistema.cargarDatosDesdeArchivos();

    // Menú principal
    bool salir = false;
    while (!salir) {
        std::cout << "\n====== Bienvenido a UdeAStay ======\n";
        std::cout << "1. Iniciar sesion"<<std::endl;
        std::cout << "2. Salir"<<std::endl;
        std::cout << "Seleccione una opcion: ";
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            sistema.login();
            break;
        case 2:
            std::cout << "Gracias por usar UdeAStay."<<std::endl;;
            salir = true;
            break;
        default:
            std::cout << "Opcion invalida. Intente nuevamente."<<std::endl;
        }
    }

    // Guardar datos antes de salir
    sistema.guardarDatosEnArchivos();

    return 0;
}
