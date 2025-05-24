#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "anfitrion.h"
#include <string>
class Alojamiento
{
private:
    std::string nombre;
    std::string departamento;
    std::string municipio;
    std::string tipo;
    std::string direccion;
    int codigoIdentificador;
    Anfitrion anfitrion;

public:
    Alojamiento();
};

#endif // ALOJAMIENTO_H
