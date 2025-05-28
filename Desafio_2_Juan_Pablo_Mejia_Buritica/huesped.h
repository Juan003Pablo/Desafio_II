#ifndef HUESPED_H
#define HUESPED_H

#include <string>
#include "fecha.h"
#include "reservacion.h"

class Huesped {
private:
    std::string documento;
    int antiguedad;     // en meses
    float puntuacion;   // 0.0 a 5.0
    Reservacion* reservaciones;
    int cantidadReservaciones;

public:
    Huesped();
    Huesped(const std::string& doc, int ant, float punt);

    ~Huesped();

    std::string getDocumento() const;
    int getAntiguedad() const;
    float getPuntuacion() const;
    int getCantidadReservaciones() const;
    Reservacion getReservacion(int index) const;

    void agregarReservacion(const Reservacion& r);
    bool tieneConflictoCon(const Fecha& inicio, int noches) const;

    void mostrarReservaciones() const;
};

#endif
