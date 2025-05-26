#include "huesped.h"

Huesped::Huesped(int doc, float punt, int ant, const Reservacion& reserv)
    : documento(doc), puntuacion(punt), antiguedad(ant), reservaciones(reserv) {}
