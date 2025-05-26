#ifndef RESERVACION_H
#define RESERVACION_H
#include "fecha.h"
#include <string>

class Reservacion
{
private:
    Fecha fechaReservacion;
    int duracionNoches;
    int codigoAlojamiento;
    int documentoHuesped;
    std::string metodoPago;
    float monto;

public:
    Reservacion(const Fecha &fecha, int duracion, int codigo, int documento, const std::string metodo, float monto);
};

#endif // RESERVACION_H
