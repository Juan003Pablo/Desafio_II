#include "fecha.h"
#include <iostream>
#include <cstdio>

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

Fecha::Fecha() : dia(1), mes(1), anio(2025) {}
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

int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
int Fecha::getAnio() const { return anio; }

void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnio(int a) { anio = a; }

bool Fecha::esAnteriorA(const Fecha& otra) const {
    if (anio < otra.anio) return true;
    if (anio == otra.anio && mes < otra.mes) return true;
    if (anio == otra.anio && mes == otra.mes && dia < otra.dia) return true;
    return false;
}

bool Fecha::esIgualA(const Fecha& otra) const {
    return dia == otra.dia && mes == otra.mes && anio == otra.anio;
}

void Fecha::mostrar() const {
    const std::string meses[] = {
        "", "enero", "febrero", "marzo", "abril", "mayo", "junio",
        "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"
    };

    std::cout << dia << " de " << meses[mes] << " del " << anio << std::endl;
}

void Fecha::toString(char* buffer) const {
    // Formato: "dd/mm/yyyy"
    snprintf(buffer, 11, "%02d/%02d/%04d", dia, mes, anio);
}
