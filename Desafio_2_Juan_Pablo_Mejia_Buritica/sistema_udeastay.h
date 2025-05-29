#ifndef SISTEMA_UDEASTAY_H
#define SISTEMA_UDEASTAY_H

#include "alojamiento.h"
#include "huesped.h"
#include "anfitrion.h"

class SistemaUdeAStay {
private:
    Alojamiento* alojamientos;
    int cantidadAlojamientos;

    Huesped* huespedes;
    int cantidadHuespedes;

    Anfitrion* anfitriones;
    int cantidadAnfitriones;

public:
    SistemaUdeAStay();
    ~SistemaUdeAStay();

    void menuPrincipal();
    void login();

    void menuHuesped(Huesped& h);
    void menuAnfitrion(Anfitrion& a);

    void agregarDatosPrueba(); // Cargar datos iniciales para pruebas

    void reservarAlojamiento(Huesped& h);
    void anularReservacion(Huesped& h);

    void cargarHuespedes();
    void cargarAnfitriones();
    void cargarAlojamientos();
    void cargarReservaciones();

    void cargarDatosDesdeArchivos();

    void guardarHuespedes();
    void guardarAnfitriones();
    void guardarAlojamientos();
    void guardarReservaciones();

    void guardarDatosEnArchivos();
};



#endif
