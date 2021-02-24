#ifndef MOUNT_H
#define MOUNT_H
#include <iostream>
#include <string.h>
#include <string>
#include "estructuras.h"
using namespace std;
class mount
{

private:
    string ruta;
    string nombre;    
    char asignarLetra(int numero);

public:
    mount();
    void montarParticion(string ruta, string nombreParticion);
    disco montarDisco(string ruta,int pos);
    particion_disco montarParticion(string nombreParticion, int pos);


};

#endif // MOUNT_H
