#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "reservacion.h"
#include <string>
class Alojamiento
{
private:
    std::string codigo;
    std::string nombre;
    std::string tipo; // "Casa" o "Apartamento"
    std::string direccion;
    std::string municipio;
    std::string departamento;
    float precioPorNoche;

    std::string* amenidades;
    int cantidadAmenidades;

    std::string documentoAnfitrion;

    Reservacion* reservaciones;
    int cantidadReservaciones;

public:
    Alojamiento();
    Alojamiento(const std::string& cod, const std::string& nom, const std::string& tipo,
                const std::string& dir, const std::string& mun, const std::string& depto,
                float precio, std::string* amenidades, int cantAmen, const std::string& docAnfitrion);
    Alojamiento(const Alojamiento& otro);
    Alojamiento& operator=(const Alojamiento& otro);
    ~Alojamiento();

    std::string getCodigo() const;
    float getPrecioPorNoche() const;
    std::string getMunicipio() const;
    std::string getDepartamento() const;
    std::string getTipo() const;
    std::string getNombre() const;
    std::string getDocAnfitrion() const;
    std::string getDireccion() const;
    float getPrecio() const;
    int getCantidadAmenidades() const;
    std::string getAmenidad(int index) const;
    std::string getDocumentoAnfitrion() const;

     void mostrarResumen() const;
     void agregarReservacion(const Reservacion& r);
     bool estaDisponible(const Fecha& inicio, int noches) const;
};

#endif // ALOJAMIENTO_H
