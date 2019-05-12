//
// Created by charles on 4/15/18.
//

#ifndef PROJECT3_RESERVA_H
#define PROJECT3_RESERVA_H

class Reserva
{
public:
    Reserva() {idMaterial = 0; idCliente = 0;}
    Reserva(int idM, int idC, Fecha f);

    Fecha calculaFechaFinReserva(int cantDias);

    void setIdMaterial(int idMaterial) {this->idMaterial = idMaterial;}
    void setIdCliente(int idCliente) {this->idCliente = idCliente;}
    void setFechaReservacion(Fecha f) {fechaReservacion = f;}

    int getIdMaterial() {return idMaterial;}
    int getIdCliente() {return idCliente;}
    Fecha getFechaReservacion() {return fechaReservacion;}

private:
    int idMaterial;
    int idCliente;
    Fecha fechaReservacion;
};

Reserva::Reserva(int idM, int idC, Fecha f)
{
    idMaterial = idM;
    idCliente = idC;
    fechaReservacion = f;
}

Fecha Reserva::calculaFechaFinReserva(int cantDias)
{
    return fechaReservacion + cantDias;
}


#endif //PROJECT3_RESERVA_H
