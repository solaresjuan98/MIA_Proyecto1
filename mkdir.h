#ifndef MKDIR_H
#define MKDIR_H
#include <iostream>
#include <string>
#include <string.h>
#include "user.h"
#include "carpeta.h"

using namespace std;

class mkdir
{

private:
    void buscarCarpeta(string nombreParticion, string ruta, string nombre_carpeta);

public:
    mkdir();

    void crearCarpeta(string nombreParticion, string ruta, user *usuario, carpeta *carpeta_nueva);
};

#endif // MKDIR_H
