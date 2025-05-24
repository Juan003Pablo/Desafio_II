#ifndef HUESPED_H
#define HUESPED_H

#include "reservacion.h"
class Huesped
{
private:
    int documento;
    float puntuacion;
    int antiguedad;
    Reservacion reservaciones;
public:
    Huesped();
};

#endif // HUESPED_H
