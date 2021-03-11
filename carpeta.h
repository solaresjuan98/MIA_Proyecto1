#ifndef CARPETA_H
#define CARPETA_H
#include <iostream>
#include <string>
#include <string.h>
#include "user.h"
using namespace std;

class carpeta
{
private:
    string nombreCarpeta;

public:
    carpeta();

    // Getters y setters
    void setNombreCarpeta(string nombreCarpeta);
    string getNombreCarpeta();
};

#endif // CARPETA_H
