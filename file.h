#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <string>
#include <string.h>
#include "user.h"
using namespace std;

class file
{

private:
    string ruta;
    bool tienePadre = false;
public:
    file();

    // getters y setters
    void setRuta(string ruta);
    string getRuta();
    void setTienePadre(bool b);
    bool getTienePadre();
};

#endif // FILE_H
