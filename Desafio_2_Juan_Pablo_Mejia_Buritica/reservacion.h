#ifndef RESERVACION_H
#define RESERVACION_H
#include <string>
#include "fecha.h"

class Reservacion {
private:
    std::string codigoReservacion;
    Fecha fechaEntrada;
    int duracionNoches;
    std::string codigoAlojamiento;
    std::string documentoHuesped;
    std::string metodoPago; // "PSE" o "TCredito"
    Fecha fechaPago;
    float monto;
    std::string anotaciones;

public:
    Reservacion();
    Reservacion(const std::string& codRes, const Fecha& entrada, int noches,
                const std::string& codAloj, const std::string& docHuesp,
                const std::string& metodoPago, const Fecha& pago, float monto,
                const std::string& anotaciones);

    // Getters
    std::string getCodigoReservacion() const;
    Fecha getFechaEntrada() const;
    int getDuracionNoches() const;
    std::string getCodigoAlojamiento() const;
    std::string getDocumentoHuesped() const;
    std::string getMetodoPago() const;
    Fecha getFechaPago() const;
    float getMonto() const;
    std::string getAnotaciones() const;
    int getNoches() const;

    // Utilidades
    Fecha calcularFechaFin() const;
    void mostrarResumen() const;
};

#endif
