#ifndef MKDISK_H
#define MKDISK_H

#include <iostream>
using namespace std;
class mkdisk
{

private:
    // Atributos:
    int tamanio;
    string ruta;

public:

    // Métodos:
    mkdisk();
    void ejecutarMkdisk();
    void mostrarDatos(mkdisk *disco);

    // Getters y setters
    void setTamanio(int tamanio);
    int getTamanio();

    void setRuta(string ruta);
    string getRuta();


};

#endif // MKDISK_H
