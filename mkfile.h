#ifndef MKFILE_H
#define MKFILE_H
#include <iostream>
#include <string>
#include <string.h>
#include "user.h"
#include "file.h"
using namespace std;
class mkfile
{
public:
    mkfile();

    // crear nuevo archivo
    void crearArchivo(string nombreParticion, string ruta, user *usuario, file *archivo_nuevo);
};

#endif // MKFILE_H
