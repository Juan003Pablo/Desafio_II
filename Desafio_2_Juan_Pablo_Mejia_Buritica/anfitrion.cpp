#include "anfitrion.h"
#include <iostream>

Anfitrion::Anfitrion() : antiguedad(0), puntuacion(0.0f), codigosAlojamientos(nullptr), cantidadAlojamientos(0) {}

Anfitrion::Anfitrion(const std::string& doc, int ant, float punt)
    : documento(doc), antiguedad(ant), puntuacion(punt), codigosAlojamientos(nullptr), cantidadAlojamientos(0) {}

Anfitrion::~Anfitrion() {
    delete[] codigosAlojamientos;
}

std::string Anfitrion::getDocumento() const { return documento; }
int Anfitrion::getAntiguedad() const { return antiguedad; }
float Anfitrion::getPuntuacion() const { return puntuacion; }


void Anfitrion::mostrarAlojamientos() const {
    std::cout << "Alojamientos del anfitrión " << documento << ":\n";
    for (int i = 0; i < cantidadAlojamientos; i++) {
        std::cout << "- " << codigosAlojamientos[i] << "\n";
    }
}

std::string Anfitrion::getCodigoAlojamiento(int i) const {
    if (i >= 0 && i < cantidadAlojamientos)
        return codigosAlojamientos[i];
    return "";
}

int Anfitrion::getCantidadAlojamientos() const {
    return cantidadAlojamientos;
}
