#pragma once
class Compra{
private:
    int codigo;
    char nombre[20];
    float importe;
    int cantidad;
    bool estado;
public:
    void cargarCadena(char *pal, int tam);
    void Cargar();
    int getCodigo();
    const char* getNombre();
    int getCantidad();
    float getImporte();
    bool getEstado();
    void setCodigo(int num);
    void setImporte(float i);
    void setNombre(const char *n);
    void setCantidad(int c);
    void setEstado(bool e);
};
