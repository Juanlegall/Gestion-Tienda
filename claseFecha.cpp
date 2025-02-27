#include "claseFecha.h"
#include <iostream>
#include <ctime>

void Fecha::cargarFecha() {
    time_t ahora = time(nullptr);
    tm* fechaActual = localtime(&ahora);

    dia = fechaActual->tm_mday;
    mes = fechaActual->tm_mon + 1;
    anio = fechaActual->tm_year + 1900;
}

void Fecha::mostrarFecha() {
    std::cout << dia << "/" << mes << "/" << anio << std::endl;
}

int Fecha::getDia() {
    return dia;
}

int Fecha::getMes() {
    return mes;
}

int Fecha::getAnio() {
    return anio;
}

void Fecha::setDia(int d) {
    if (d >= 1 && d <= 31) {
        dia = d;
    }
}

void Fecha::setMes(int m) {
    if (m >= 1 && m <= 12) {
        mes = m;
    }
}

void Fecha::setAnio(int a) {
    if (a >= 0) {
        anio = a;
    }
}
