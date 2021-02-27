#ifndef FDISK_H
#define FDISK_H
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class fdisk
{
private:
    int tamanio;
    string nombre;
    string unidad;
    string ruta;
    string tipo;
    string ajuste;
    string borrar;

public:

    // Metodos
    fdisk();
    void crearParticion(fdisk *disco);
    void mostrarDatosDisco(string ruta);
    void borrarParticion(string ruta, fdisk *disco, string nombreParticion);
    void extenderParticion(fdisk *disco, int cantidad);

    // Getters y setters
    void setTamanio(int tamanio);
    int getTamanio();
    void setNombre(string nombre);
    string getNombre();
    void setUnidad(string unidad);
    string getUnidad();
    void setRuta(string ruta);
    string getRuta();
    void setTipo(string tipo);
    string getTipo();
    void setAjuste(string ajuste);
    string getAjuste();
    void setBorrar(string borrar);
    string getBorrar();

};

#endif // FDISK_H
