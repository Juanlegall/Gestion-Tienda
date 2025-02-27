#pragma once
class Detalle{
private:
    int codigo;
    int codigoVenta;
    int codigoProducto;
    float precioU;
    int cantidad;
    bool estado;
public:
    void Cargar();
    int getCodigo();
    int getCodigoVenta();
    int getCodigoProducto();
    int getCantidad();
    float getPrecioU();
    bool getEstado();
    void setCodigo(int num);
    void setPrecioU(float p);
    void setCodigoVenta(int v);
    void setCodigoProducto(int p);
    void setCantidad(int c);
    void setEstado(bool e);
};
