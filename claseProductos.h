#pragma once

class Producto{
private:
    int codigo;
    char nombre[30];
    float precio;
    int stock;
    int categoria;
    bool estado;
public:
    void cargarCadena(char *pal, int tam);
    void Cargar();
    int getCodigo();
    const char* getNombre();
    int getStock();
    int getCategoria();
    float getPrecio();
    bool getEstado();
    void setCodigo(int num);
    void setPrecio(float p);
    void setNombre(const char *n);
    void setStock(int s);
    void setCategoria(int cat);
    void setEstado(bool e);
};
