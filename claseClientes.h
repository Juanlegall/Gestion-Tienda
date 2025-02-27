#pragma once
#include <cstdlib>
#include <cstring>

class Clientes{
private:
    int DNI;
    char nombreCompleto[30];
    char email[30];
    char direccion[30];
    int telefono;
    bool estado;
public:
    void cargarCadena(char *pal, int tam);
    void Cargar();
    const char* getNombreCompleto();
    const char* getEmail();
    const char* getDireccion();
    int getTelefono();
    int getDni();
    bool getEstado();
    void setNombreCompleto(const char *nom);
    void setEmail(const char *correo);
    void setDireccion(const char *direc);
    void setTelefono(int tel);
    void setDni(int identificacion);
    void setEstado(bool e);

};
