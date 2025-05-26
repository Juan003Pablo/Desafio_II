#ifndef ANFITRION_H
#define ANFITRION_H

#include <string>
class Anfitrion
{
private:
    int documento;
    int antiguedad;
    float puntuacion;
    std::string* codigosAlojamientos;
    int cantidadAlojamientos;

public:
    Anfitrion();
};

#endif // ANFITRION_H
