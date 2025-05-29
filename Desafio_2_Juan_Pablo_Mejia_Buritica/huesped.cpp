#include "huesped.h"
#include "reservacion.h"
#include <iostream>

Huesped::Huesped() : antiguedad(0), puntuacion(0.0f), reservaciones(nullptr), cantidadReservaciones(0) {}

Huesped::Huesped(const std::string& doc, int ant, float punt)
    : documento(doc), antiguedad(ant), puntuacion(punt), reservaciones(nullptr), cantidadReservaciones(0) {}

Huesped::~Huesped() {
    delete[] reservaciones;
}

std::string Huesped::getDocumento() const { return documento; }
int Huesped::getAntiguedad() const { return antiguedad; }
float Huesped::getPuntuacion() const { return puntuacion; }

void Huesped::agregarReservacion(const Reservacion& r) {
    Reservacion* nuevo = new Reservacion[cantidadReservaciones + 1];
    for (int i = 0; i < cantidadReservaciones; i++) {
        nuevo[i] = reservaciones[i];
    }
    nuevo[cantidadReservaciones] = r;
    delete[] reservaciones;
    reservaciones = nuevo;
    cantidadReservaciones++;
}

bool Huesped::tieneConflictoCon(const Fecha& inicio, int noches) const {
    Fecha fin = Fecha(inicio.getDia() + noches, inicio.getMes(), inicio.getAnio()); // simplificado

    for (int i = 0; i < cantidadReservaciones; i++) {
        Fecha entrada = reservaciones[i].getFechaEntrada();
        Fecha salida = reservaciones[i].calcularFechaFin();

        if (!(fin.esAnteriorA(entrada) || inicio.esAnteriorA(salida))) {
            return true; // hay cruce de fechas
        }
    }
    return false;
}

void Huesped::mostrarReservaciones() const {
    std::cout << "Reservas del huesped " << documento << ":\n";
    for (int i = 0; i < cantidadReservaciones; i++) {
        reservaciones[i].mostrarResumen();
        std::cout << "-------------------------\n";
    }
}

void Huesped::eliminarReservacion(int index) {
    if (index < 0 || index >= cantidadReservaciones) return;

    Reservacion* nuevo = new Reservacion[cantidadReservaciones - 1];

    for (int i = 0, j = 0; i < cantidadReservaciones; i++) {
        if (i != index) {
            nuevo[j++] = reservaciones[i];
        }
    }

    delete[] reservaciones;
    reservaciones = nuevo;
    cantidadReservaciones--;
}


int Huesped::getCantidadReservaciones() const {
    return cantidadReservaciones;
}

Reservacion Huesped::getReservacion(int index) const {
    if (index >= 0 && index < cantidadReservaciones) {
        return reservaciones[index];
    }
    return Reservacion();  // Devuelve objeto vacío si el índice es inválido
}
