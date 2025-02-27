#pragma once
#include <cstring>
class Categoria{
private:
    int idCategoria;
    char nombreProducto[30];
    bool estado;
public:
    void cargarCadena(char *pal, int tam);
    void Cargar();
    void Mostrar(Categoria obj);
    const char *getNombreProducto();
    int getIdCategoria();
    bool getEstado();
    void setNombreProducto(const char *nom);
    void setIdCategoria(int idCat);
    void setEstado(bool e);
};
