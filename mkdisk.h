#ifndef MKDISK_H
#define MKDISK_H

#include <iostream>
class mkdisk
{
public:
    mkdisk();

    int tamanio;

    void ejecutarMkdisk();
    void mostrarDatos(mkdisk *disco);
};

#endif // MKDISK_H
