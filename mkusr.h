#ifndef MKUSR_H
#define MKUSR_H
#include <iostream>
#include "user.h"
#include <string>
#include <string.h>
using namespace std;

class mkusr
{
public:
    mkusr();

    void crearUsuario(string nombreParticion, string rutaParticion, user *usuario);
};

#endif // MKUSR_H
