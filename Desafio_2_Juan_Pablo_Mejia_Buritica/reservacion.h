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
    Reservacion();
};

#endif // RESERVACION_H
