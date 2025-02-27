#pragma once
#include "claseCategoria.h"
#include "claseArchivoCategoria.h"

class CategoriaManager{
    public:
    void agregarCategoria();
    void Mostrar(Categoria obj);
    void modificarCategoria();
    void listarCategorias();
    ArchivoCategoria ArchivoCategoria;
    Categoria categoria;
     void bajaFisica();
    void guardarBackup();
    void restaurarArchivo();
    private:
};
