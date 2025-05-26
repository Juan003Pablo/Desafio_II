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
    Huesped(int doc, float punt, int ant, const Reservacion& reserv);
};

#endif // HUESPED_H
