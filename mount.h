#ifndef MOUNT_H
#define MOUNT_H
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class mount
{

private:
    string ruta;
    string nombre;

public:
    mount();
    void montarParticion(string ruta);

    // Getters y setters
    void setRuta(string ruta);
    string getRuta();
    void setNombre(string nombre);
    string getNombre();
};

#endif // MOUNT_H
