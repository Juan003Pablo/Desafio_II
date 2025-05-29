#include "alojamiento.h"
#include "reservacion.h"
#include <iostream>

Alojamiento::Alojamiento() : precioPorNoche(0.0f), amenidades(nullptr),
    cantidadAmenidades(0), reservaciones(nullptr), cantidadReservaciones(0) {}

Alojamiento::Alojamiento(const std::string& cod, const std::string& nom, const std::string& tipo,
                         const std::string& dir, const std::string& mun, const std::string& depto,
                         float precio, std::string* amen, int cantAmen, const std::string& docAnfitrion)
    : codigo(cod), nombre(nom), tipo(tipo), direccion(dir), municipio(mun),
    departamento(depto), precioPorNoche(precio), cantidadAmenidades(cantAmen),
    documentoAnfitrion(docAnfitrion), cantidadReservaciones(0)
{
    amenidades = new std::string[cantAmen];
    for (int i = 0; i < cantAmen; i++) {
        amenidades[i] = amen[i];
    }
    reservaciones = nullptr;
}

Alojamiento::Alojamiento(const Alojamiento& otro) {
    codigo = otro.codigo;
    nombre = otro.nombre;
    tipo = otro.tipo;
    direccion = otro.direccion;
    municipio = otro.municipio;
    departamento = otro.departamento;
    precioPorNoche = otro.precioPorNoche;
    documentoAnfitrion = otro.documentoAnfitrion;
    cantidadAmenidades = otro.cantidadAmenidades;

    amenidades = new std::string[cantidadAmenidades];
    for (int i = 0; i < cantidadAmenidades; i++) {
        amenidades[i] = otro.amenidades[i];
    }
}

Alojamiento& Alojamiento::operator=(const Alojamiento& otro) {
    if (this != &otro) {
        delete[] amenidades;

        codigo = otro.codigo;
        nombre = otro.nombre;
        tipo = otro.tipo;
        direccion = otro.direccion;
        municipio = otro.municipio;
        departamento = otro.departamento;
        precioPorNoche = otro.precioPorNoche;
        documentoAnfitrion = otro.documentoAnfitrion;
        cantidadAmenidades = otro.cantidadAmenidades;

        amenidades = new std::string[cantidadAmenidades];
        for (int i = 0; i < cantidadAmenidades; i++) {
            amenidades[i] = otro.amenidades[i];
        }
    }
    return *this;
}

Alojamiento::~Alojamiento() {
    delete[] amenidades;
    delete[] reservaciones;
}

std::string Alojamiento::getCodigo() const { return codigo; }
float Alojamiento::getPrecioPorNoche() const { return precioPorNoche; }
std::string Alojamiento::getMunicipio() const { return municipio; }
std::string Alojamiento::getDepartamento() const { return departamento; }
std::string Alojamiento::getTipo() const { return tipo; }
std::string Alojamiento::getNombre() const { return nombre; }
std::string Alojamiento::getDocAnfitrion() const {return documentoAnfitrion;}
std::string Alojamiento::getDireccion() const { return direccion;}
float Alojamiento::getPrecio() const { return precioPorNoche;}
int Alojamiento::getCantidadAmenidades() const {return cantidadAmenidades;}
std::string Alojamiento::getAmenidad(int index) const {
    if (index >= 0 && index < cantidadAmenidades) {return amenidades[index];}
    return "";
}
std::string Alojamiento::getDocumentoAnfitrion() const {return documentoAnfitrion;}


void Alojamiento::mostrarResumen() const {
    std::cout << "Alojamiento: " << nombre << " (" << tipo << ") - " << direccion << "\n";
    std::cout << "Municipio: " << municipio << ", Departamento: " << departamento << "\n";
    std::cout << "Precio por noche: $" << precioPorNoche << " COP\n";
    std::cout << "Amenidades: ";
    for (int i = 0; i < cantidadAmenidades; i++) {
        std::cout << amenidades[i];
        if (i != cantidadAmenidades - 1) std::cout << ", ";
    }
    std::cout << "\n\n";
}

void Alojamiento::agregarReservacion(const Reservacion& r) {
    // Verificar si la nueva reserva está disponible
    if (!estaDisponible(r.getFechaEntrada(), r.getNoches())) {
        std::cout << "La reserva entra en conflicto con una reserva existente y no se agregará.\n";
        return;  // No se agrega la reserva si hay conflicto
    }

    // Si no hay conflicto, agregar la reserva normalmente
    Reservacion* nuevo = new Reservacion[cantidadReservaciones + 1];
    for (int i = 0; i < cantidadReservaciones; i++) {
        nuevo[i] = reservaciones[i];
    }
    nuevo[cantidadReservaciones] = r;
    delete[] reservaciones;
    reservaciones = nuevo;
    cantidadReservaciones++;
}


bool Alojamiento::estaDisponible(const Fecha& inicio, int noches) const {
    Fecha fin = inicio;
    fin = Fecha(inicio.getDia() + noches, inicio.getMes(), inicio.getAnio()); // simplificado

    for (int i = 0; i < cantidadReservaciones; i++) {
        Fecha entrada = reservaciones[i].getFechaEntrada();
        Fecha salida = reservaciones[i].calcularFechaFin();

        if (!(fin.esAnteriorA(entrada) || inicio.esAnteriorA(salida))) {
            return false; // Hay cruce de fechas
        }
    }
    return true;
}
