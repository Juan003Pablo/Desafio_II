#include "reservacion.h"
#include "fecha.h"
#include <iostream>

Reservacion::Reservacion() : duracionNoches(1), monto(0.0) {}

Reservacion::Reservacion(const std::string& codRes, const Fecha& entrada, int noches,
                         const std::string& codAloj, const std::string& docHuesp,
                         const std::string& metodoPago, const Fecha& pago, float monto,
                         const std::string& anotaciones)
    : codigoReservacion(codRes), fechaEntrada(entrada), duracionNoches(noches),
    codigoAlojamiento(codAloj), documentoHuesped(docHuesp), metodoPago(metodoPago),
    fechaPago(pago), monto(monto), anotaciones(anotaciones) {}

std::string Reservacion::getCodigoReservacion() const { return codigoReservacion; }
Fecha Reservacion::getFechaEntrada() const { return fechaEntrada; }
int Reservacion::getDuracionNoches() const { return duracionNoches; }
std::string Reservacion::getCodigoAlojamiento() const { return codigoAlojamiento; }
std::string Reservacion::getDocumentoHuesped() const { return documentoHuesped; }
std::string Reservacion::getMetodoPago() const { return metodoPago; }
Fecha Reservacion::getFechaPago() const { return fechaPago; }
float Reservacion::getMonto() const { return monto; }
std::string Reservacion::getAnotaciones() const { return anotaciones; }
int Reservacion::getNoches() const {
    return duracionNoches;
}


// Simplemente suma noches sin validar fin de mes/año
Fecha Reservacion::calcularFechaFin() const {
    int diaFin = fechaEntrada.getDia() + duracionNoches;
    int mes = fechaEntrada.getMes();
    int anio = fechaEntrada.getAnio();
    // Para hacerlo bien, se debería ajustar días según el mes
    return Fecha(diaFin, mes, anio);
}

void Reservacion::mostrarResumen() const {
    std::cout << "Reserva " << codigoReservacion << ": "
              << "Huesped " << documentoHuesped << ", "
              << "Alojamiento " << codigoAlojamiento << "\nEntrada: ";
    fechaEntrada.mostrar();
    std::cout << "Duracion: " << duracionNoches << " noche(s)\n"
              << "Monto: $" << monto << " COP\n"
              << "Metodo de pago: " << metodoPago << "\n"
              << "Anotaciones: " << anotaciones << "\n";
}
