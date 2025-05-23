#include "fecha.h"
#include <iostream>

bool Fecha::esBisiesto() const {
    return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}

int Fecha::obtenerDiasDelMes() const {
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && esBisiesto()) {
        return 29;
    }

    return diasPorMes[mes - 1];
}

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

void Fecha::sumarDias(int sumaDias) {
    dia += sumaDias;  // Incrementamos los días

    // Mientras el día supere el número de días del mes actual ajustamos la fecha
    while (dia > obtenerDiasDelMes()) {
        dia -= obtenerDiasDelMes();  // Restamos los días del mes actual
        mes++;

        if (mes > 12) {
            mes = 1;
            anio++;
        }
    }
}

void Fecha::mostrarFecha() const {
    std::cout << "Fecha: " << dia << "/" << mes << "/" << anio << std::endl;
}

Fecha Fecha::calcularFin(int noches) const {
    Fecha fin = *this;
    fin.sumarDias(noches);
    return fin;
}

// Método para verificar si dos fechas se superponen
bool Fecha::entraEnConflicto(const Fecha& inicioReserva, int duracionReserva) const {
    Fecha finReserva = inicioReserva.calcularFin(duracionReserva);

    // Compara los rangos de fechas
    if ((this->anio > finReserva.anio) ||
        (this->anio == finReserva.anio && this->mes > finReserva.mes) ||
        (this->anio == finReserva.anio && this->mes == finReserva.mes && this->dia > finReserva.dia)) {
        return false;
    }

    return true;
}
