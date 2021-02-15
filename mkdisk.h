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

    // Setters
    void setTamanio(int tamanio);
    void setRuta(string ruta);
    void setUnidad(string unidad);

};

#endif // MKDISK_H
