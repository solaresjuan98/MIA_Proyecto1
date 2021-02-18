#ifndef MKDISK_H
#define MKDISK_H

#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class mkdisk
{

private:
    // Atributos:
    int tamanio;
    string ruta;
    string unidad;
    string fecha_creacion;
    string ajuste;

public:

    /**
     ** Métodos:
     * */
    mkdisk();
    void ejecutarMkdisk();
    void mostrarDatos(mkdisk *disco);
    void crearDisco(mkdisk *disco);


    // Getters
    int getTamanio();
    string getRuta();
    string getUnidad();
    string getFechaCreacion();
    string getAjuste();

    // Setters
    void setTamanio(int tamanio);
    void setRuta(string ruta);
    void setUnidad(string unidad);
    void setFechaCreacion(string fecha);
    void setAjuste(string ajuste);

};

#endif // MKDISK_H
