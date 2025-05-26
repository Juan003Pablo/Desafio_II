#include "reservacion.h"

Reservacion::Reservacion(const Fecha& fecha, int duracion, int codigo, int documento, const std::string metodo, float monto)
    : fechaReservacion(fecha), duracionNoches(duracion), codigoAlojamiento(codigo),
    documentoHuesped(documento), metodoPago(metodo), monto(monto) {}
