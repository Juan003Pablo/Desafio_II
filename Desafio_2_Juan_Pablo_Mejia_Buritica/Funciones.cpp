#include "Funciones.h"
#include <cstring>
using namespace std;

char** split(const char* str, char delimitador, int& cantidad) {
    int len = strlen(str);
    int partes = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] == delimitador) partes++;
    }

    char** resultado = new char*[partes];
    cantidad = 0;
    int inicio = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == delimitador || str[i] == '\0') {
            int tamanio = i - inicio;
            resultado[cantidad] = new char[tamanio + 1];
            strncpy(resultado[cantidad], &str[inicio], tamanio);
            resultado[cantidad][tamanio] = '\0';
            cantidad++;
            inicio = i + 1;
        }
    }
    return resultado;

}
/*
Fecha pedirFecha()
{
    int dia, mes, año;
    std::cout << "Introduce la fecha de la reservación (día, mes, año): ";
    std::cin >> dia >> mes >> año;
    return Fecha(dia, mes, año);
}

int pedirEntero(const std::string& mensaje)
{
    int valor;
    std::cout << mensaje;
    std::cin >> valor;
    return valor;
}

std::string pedirMetodoPago()
{
    std::string metodo;
    std::cout << "Introduce el método de pago (ej. tarjeta, efectivo, etc.): ";
    std::cin >> metodo;
    return metodo;
}

float pedirMonto()
{
    float monto;
    std::cout << "Introduce el monto total de la reservación: ";
    std::cin >> monto;
    return monto;
}

Reservacion crearReservacion()
{
    Fecha fecha = pedirFecha();
    int duracion = pedirEntero("Introduce la duración de la reservación en noches: ");
    int codigo = pedirEntero("Introduce el código de alojamiento: ");
    int documento = pedirEntero("Introduce el documento del huésped: ");
    std::string metodoPago = pedirMetodoPago();
    float monto = pedirMonto();

    // Crear el objeto Reservacion con los datos solicitados
    return Reservacion(fecha, duracion, codigo, documento, metodoPago, monto);
}
*/
