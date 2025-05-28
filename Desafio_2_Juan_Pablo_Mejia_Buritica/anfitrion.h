#ifndef ANFITRION_H
#define ANFITRION_H

#include <string>

class Anfitrion {
private:
    std::string documento;
    int antiguedad;
    float puntuacion;
    std::string* codigosAlojamientos;
    int cantidadAlojamientos;

public:
    Anfitrion();
    Anfitrion(const std::string& doc, int ant, float punt);
    ~Anfitrion();

    std::string getDocumento() const;
    int getAntiguedad() const;
    float getPuntuacion() const;

    void agregarAlojamiento(const std::string& codigoAlojamiento);
    void mostrarAlojamientos() const;
    std::string getCodigoAlojamiento(int i) const;
    int getCantidadAlojamientos() const;

};

#endif
