#include "sistema_udeastay.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include "Funciones.h"
#include "alojamiento.h"
#include "reservacion.h"
#include "alojamiento.h"


SistemaUdeAStay::SistemaUdeAStay() : alojamientos(nullptr), cantidadAlojamientos(50),
    huespedes(nullptr), cantidadHuespedes(50),
    anfitriones(nullptr), cantidadAnfitriones(50) {}

SistemaUdeAStay::~SistemaUdeAStay() {
    delete[] alojamientos;
    delete[] huespedes;
    delete[] anfitriones;
}

void SistemaUdeAStay::menuPrincipal() {
    std::cout << "Bienvenido a UdeAStay\n";
    std::cout << "1. Iniciar sesion\n";
    std::cout << "2. Salir\n";
    int opcion;
    std::cin >> opcion;
    if (opcion == 1) login();
    else std::cout << "Hasta pronto.\n";
}

void SistemaUdeAStay::login() {
    std::string doc;
    std::cout << "Ingrese su numero de documento: ";
    std::cin >> doc;

    // Buscar en huéspedes
    for (int i = 0; i < cantidadHuespedes; i++) {
        if (huespedes[i].getDocumento() == doc) {
            std::cout << "¡Bienvenido, huesped!\n";
            menuHuesped(huespedes[i]);
            return;
        }
        std::cout << huespedes[i].getDocumento();
    }

    // Buscar en anfitriones
    for (int i = 0; i < cantidadAnfitriones; i++) {
        if (anfitriones[i].getDocumento() == doc) {
            std::cout << "¡Bienvenido, anfitrion!\n";
            menuAnfitrion(anfitriones[i]);
            return;
        }
    }

    std::cout << "Usuario no encontrado.\n";
}

void SistemaUdeAStay::menuHuesped(Huesped& h) {
    int opcion = 0;
    do {
        std::cout << "\n--- Menu huesped ---"<<std::endl;
        std::cout <<"Elija una opcion"<<std::endl;
        std::cout <<"1. Reservar alojamiento"<<std::endl;
        std::cout <<"2. Anular reservacion"<<std::endl;
        std::cout <<"3. ver reservaciones"<<std::endl;
        std::cout <<"4. salir"<<std::endl;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            reservarAlojamiento(h);
            break;
        case 2:
            anularReservacion(h);
            break;
        case 3:
            h.mostrarReservaciones();
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (opcion != 4);
}

void SistemaUdeAStay::menuAnfitrion(Anfitrion& a) {
    int opcion;
    do {
        std::cout << "\n--- Menu Anfitrion ---"<<std::endl;
        std::cout << "1. Ver alojamientos"<<std::endl;
        std::cout << "2. Volver"<<std::endl;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            a.mostrarAlojamientos();
            break;
        case 2:
            break;
        default:
            break;
        }
    } while (opcion != 2);
}

void SistemaUdeAStay::anularReservacion(Huesped& h) {
    std::string codReserva;
    std::cout << "Ingrese el codigo de la reservacion que desea anular: ";
    std::cin >> codReserva;

    // Buscar la reservación en las reservas del huésped
    bool encontrada = false;
    for (int i = 0; i < h.getCantidadReservaciones(); i++) {
        if (h.getReservacion(i).getCodigoReservacion() == codReserva) {
            encontrada = true;

            // Eliminar la reservación del huésped
            h.eliminarReservacion(i);

            // Buscar el alojamiento correspondiente y eliminar la reservación allí también
            for (int j = 0; j < cantidadAlojamientos; j++) {
                Alojamiento& a = alojamientos[j];
                if (a.getCodigo() == h.getReservacion(i).getCodigoAlojamiento()) {
                    a.eliminarReservacion(codReserva);
                    break;
                }
            }

            std::cout << "La reservacion ha sido anulada exitosamente.\n";
            break;
        }
    }

    if (!encontrada) {
        std::cout << "No se encontro una reservacion con ese codigo.\n";
    }
}


void SistemaUdeAStay::reservarAlojamiento(Huesped& h) {
    std::string municipio;
    int dia, mes, anio, noches;
    float precioMax = -1;
    float puntMin = -1;
    char usarFiltros;

    std::cout << "Ingrese municipio destino: " <<std::endl;
    std::cin >> municipio;

    std::cout << "Ingrese la fecha de entrada, primero dia, luego mes y por ultimo anio: "<<std::endl;
    std::cin >> dia >> mes >> anio;

    std::cout << "Numero de noches: ";
    std::cin >> noches;

    Fecha inicio(dia, mes, anio);

    std::cout << "Desea aplicar filtros? (s/n): ";
    std::cin >> usarFiltros;

    if (usarFiltros == 's' || usarFiltros == 'S') {
        std::cout << "Precio maximo por noche: ";
        std::cin >> precioMax;
        std::cout << "Puntuacion minima del anfitrion: ";
        std::cin >> puntMin;
    }

    // Mostrar alojamientos disponibles
    int seleccion = -1;
    int contador = 0;
    for (int i = 0; i < cantidadAlojamientos; i++) {
        Alojamiento& a = alojamientos[i];
        if (a.getMunicipio() == municipio &&
            a.estaDisponible(inicio, noches) &&
            (precioMax < 0 || a.getPrecioPorNoche() <= precioMax)) {

            // Buscar anfitrión del alojamiento
            float puntuacionAnfitrion = 0.0;
            for (int j = 0; j < cantidadAnfitriones; j++) {
                if (anfitriones[j].getDocumento() == a.getCodigo()) {
                    puntuacionAnfitrion = anfitriones[j].getPuntuacion();
                    break;
                }
            }

            if (puntMin < 0 || puntuacionAnfitrion >= puntMin) {
                std::cout << "Opcion " << contador + 1 << ":\n";
                a.mostrarResumen();
                contador++;
            }
        }
    }

    if (contador == 0) {
        std::cout << "No hay alojamientos disponibles con esos criterios.\n";
        return;
    }

    std::cout << "Seleccione la opcion (1 - " << contador << "): ";
    std::cin >> seleccion;

    if (seleccion < 1 || seleccion > contador) {
        std::cout << "Seleccion invalida.\n";
        return;
    }

    // Suponemos que la selección corresponde a índice directo (simple)
    Alojamiento& alojElegido = alojamientos[seleccion - 1];

    if (h.tieneConflictoCon(inicio, noches)) {
        std::cout << "Ya tienes una reserva en esas fechas."<<std::endl;
        return;
    }

    std::string codReserva = "R" + std::to_string(rand() % 10000);
    std::string metodo;
    float monto = alojElegido.getPrecioPorNoche() * noches;
    std::string nota;

    std::cout << "Metodo de pago (PSE/TCredito): ";
    std::cin >> metodo;

    std::cout << "Deseas dejar una anotacion? (max 1000 caracteres):\n";
    std::cin.ignore();
    std::getline(std::cin, nota);

    Fecha hoy(1, 1, 2025);

    Reservacion nueva(codReserva, inicio, noches,
                      alojElegido.getCodigo(), h.getDocumento(),
                      metodo, hoy, monto, nota);

    alojElegido.agregarReservacion(nueva);
    h.agregarReservacion(nueva);

    std::cout << "\nReserva confirmada:\n";
    nueva.mostrarResumen();
}


void SistemaUdeAStay::cargarHuespedes() {
    std::ifstream archivo("huespedes.txt");
    char linea[256];
    int contador = 0;
    Huesped* temporales = new Huesped[100]; // máximo 100 huéspedes para prueba

    while (archivo.getline(linea, 256)) {
        if (strstr(linea, "documento")) continue;

        int n;
        char** partes = split(linea, ';', n);
        if (n >= 3) {
            int antiguedad = atoi(partes[1]);
            float puntuacion = atof(partes[2]);
            temporales[contador++] = Huesped(partes[0], antiguedad, puntuacion);
        }

        for (int i = 0; i < n; i++) delete[] partes[i];
        delete[] partes;
    }

    cantidadHuespedes = contador;
    huespedes = new Huesped[cantidadHuespedes];
    for (int i = 0; i < cantidadHuespedes; i++) {
        huespedes[i] = temporales[i];
    }

    delete[] temporales;
}

void SistemaUdeAStay::cargarAnfitriones() {

    std::ifstream archivoA("anfitriones.txt");
    if (!archivoA) {
        std::cerr << " Error: no se pudo abrir anfitriones.txt\n";
        return;
    }

    char lineaA[256];
    int contA = 0;
    Anfitrion* tempA = new Anfitrion[100];  // máx 100 anfitriones

    while (archivoA.getline(lineaA, 256)) {
        if (strstr(lineaA, "documento")) continue;  // saltar cabecera

        int np;
        char** partes = split(lineaA, ';', np);
        if (np >= 4) {
            int antiguedad = atoi(partes[1]);
            float puntuacion = atof(partes[2]);

            // Crear anfitrión directamente en el arreglo
            tempA[contA] = Anfitrion(partes[0], antiguedad, puntuacion);

            // Separar alojamientos
            int na;
            char** aloj = split(partes[3], ',', na);
            for (int j = 0; j < na; j++) {
                tempA[contA].agregarAlojamiento(aloj[j]);  // copiar string
                delete[] aloj[j];  // liberar string individual
            }
            delete[] aloj;  // liberar arreglo de punteros

            contA++;
        }

        // Liberar memoria del split principal
        for (int i = 0; i < np; i++) delete[] partes[i];
        delete[] partes;
    }

    cantidadAnfitriones = contA;
    anfitriones = new Anfitrion[cantidadAnfitriones];
    for (int i = 0; i < cantidadAnfitriones; i++) {
        anfitriones[i] = tempA[i];
    }
    delete[] tempA;
}


void SistemaUdeAStay::cargarAlojamientos() {
    std::ifstream archivoAl("alojamientos.txt");
    char lineaAl[512];
    int contAl = 0;
    Alojamiento* tempAl = new Alojamiento[100];

    while (archivoAl.getline(lineaAl, 512)) {
        if (strstr(lineaAl, "codigo")) continue;

        int np;
        char** partes = split(lineaAl, ';', np);
        if (np >= 9) {
            float precio = atof(partes[6]);

            // dividir amenidades
            int na;
            char** amens = split(partes[7], ',', na);

            std::string* amenidades = new std::string[na];
            for (int i = 0; i < na; i++) {
                amenidades[i] = std::string(amens[i]);  // Convertir char* a std::string
            }

            // construir alojamiento
            tempAl[contAl++] = Alojamiento(partes[0], partes[1], partes[2], partes[3], partes[4], partes[5], precio, amenidades, na, partes[8]);

            for (int j = 0; j < na; j++) {
                delete[] amens[j]; // Liberar cada parte
            }
            delete[] amens; // Liberar el arreglo de punteros a amenidades

            // Liberar el arreglo de std::string de amenidades
            delete[] amenidades;
        }

        for (int i = 0; i < np; i++) delete[] partes[i];
        delete[] partes;
    }

    cantidadAlojamientos = contAl;
    alojamientos = new Alojamiento[cantidadAlojamientos];
    for (int i = 0; i < cantidadAlojamientos; i++) {
        alojamientos[i] = tempAl[i];
    }
    delete[] tempAl;

}

void SistemaUdeAStay::cargarReservaciones() {
    std::ifstream archivoR("reservaciones.txt");
    char lineaR[512];

    while (archivoR.getline(lineaR, 512)) {
        if (strstr(lineaR, "codigo")) continue;

        int np;
        char** partes = split(lineaR, ';', np);
        if (np >= 9) {
            // Fecha entrada
            int d1, m1, a1;
            sscanf(partes[1], "%d/%d/%d", &d1, &m1, &a1);
            Fecha entrada(d1, m1, a1);

            // Fecha pago
            int d2, m2, a2;
            sscanf(partes[6], "%d/%d/%d", &d2, &m2, &a2);
            Fecha pago(d2, m2, a2);

            int noches = atoi(partes[2]);
            float monto = atof(partes[7]);

            Reservacion r(partes[0], entrada, noches, partes[3], partes[4], partes[5], pago, monto, partes[8]);

            // Asociar a huésped
            for (int i = 0; i < cantidadHuespedes; i++) {
                if (strcmp(huespedes[i].getDocumento().c_str(), partes[4]) == 0) {
                    huespedes[i].agregarReservacion(r);
                    break;
                }
            }

            // Asociar a alojamiento
            for (int i = 0; i < cantidadAlojamientos; i++) {
                if (strcmp(alojamientos[i].getCodigo().c_str(), partes[3]) == 0) {
                    alojamientos[i].agregarReservacion(r);
                    break;
                }
            }
        }

        for (int i = 0; i < np; i++) delete[] partes[i];
        delete[] partes;
    }
}

void SistemaUdeAStay::cargarDatosDesdeArchivos() {
    if (alojamientos == nullptr) {
        alojamientos = new Alojamiento[100];
        cantidadAlojamientos = 100;
    }

    if (huespedes == nullptr) {
        huespedes = new Huesped[100];
        cantidadHuespedes = 100;
    }

    if (anfitriones == nullptr) {
        anfitriones = new Anfitrion[100];
        cantidadAnfitriones = 100;
    }

    cargarHuespedes();
    cargarAnfitriones();
    cargarAlojamientos();
    cargarReservaciones();
}

void SistemaUdeAStay::guardarAlojamientos() {
    std::ofstream archivoAl("alojamientos.txt");
    archivoAl << "codigo;nombre;tipo;direccion;municipio;departamento;precio;amen1,amen2,...;documentoAnfitrion\n";  // Cabecera

    for (int i = 0; i < cantidadAlojamientos; i++) {
        archivoAl << alojamientos[i].getCodigo() << ";"
                  << alojamientos[i].getNombre() << ";"
                  << alojamientos[i].getTipo() << ";"
                  << alojamientos[i].getDireccion() << ";"
                  << alojamientos[i].getMunicipio() << ";"
                  << alojamientos[i].getDepartamento() << ";"
                  << alojamientos[i].getPrecio() << ";";

        // Guardar amenidades
        for (int j = 0; j < alojamientos[i].getCantidadAmenidades(); j++) {
            archivoAl << alojamientos[i].getAmenidad(j) << (j < alojamientos[i].getCantidadAmenidades() - 1 ? "," : "");
        }

        archivoAl << ";" << alojamientos[i].getDocumentoAnfitrion() << "\n";
    }

    archivoAl.close();
}

void SistemaUdeAStay::guardarReservaciones() {
    std::ofstream archivoR("reservaciones.txt");
    archivoR << "codigoRes;dd/mm/yyyy;noches;codAloj;docHuesped;metodo;dd/mm/yyyy;monto;anotacion\n";  // Cabecera

    for (int i = 0; i < cantidadHuespedes; i++) {
        for (int j = 0; j < huespedes[i].getCantidadReservaciones(); j++) {
            Reservacion r = huespedes[i].getReservacion(j);

            char fechaEntrada[11]; // buffer para la fecha
            r.getFechaEntrada().toString(fechaEntrada);

            char fechaPago[11]; // buffer para la fecha de pago
            r.getFechaPago().toString(fechaPago);

            archivoR << r.getCodigoReservacion() << ";"
                     << fechaEntrada << ";"
                     << r.getNoches() << ";"
                     << r.getCodigoAlojamiento() << ";"
                     << r.getDocumentoHuesped() << ";"
                     << r.getMetodoPago() << ";"
                     << fechaPago << ";"
                     << r.getMonto() << ";"
                     << r.getAnotaciones() << "\n";
        }
    }

    archivoR.close();
}

void SistemaUdeAStay::guardarDatosEnArchivos() {
    guardarAlojamientos();
    guardarReservaciones();
}

