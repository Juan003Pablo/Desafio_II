#ifndef FECHA_H
#define FECHA_H

class Fecha
{
private:
    int dia;
    int mes;
    int anio;

    bool esBisiesto() const;

    int obtenerDiasDelMes() const;

    void sumarDias(int sumaDias);
public:
    Fecha(int dia, int mes, int anio);

    // Método para mostrar la fecha en formato dd/mm/aaaa
    void mostrarFecha() const;

    // Método para calcular el día final de una reserva
    Fecha calcularFin(int noches) const;

    // Método para verificar si dos reservas se superponen
    bool entraEnConflicto(const Fecha& inicioReserva, int duracionReserva) const;
};

#endif // FECHA_H
