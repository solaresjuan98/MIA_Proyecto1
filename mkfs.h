#ifndef MKFS_H
#define MKFS_H

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class mkfs
{

private:
    string tipoFormateo;// puede ser de tipo fast o full
public:
    mkfs();

    // métodos de formateo
    void formatearEXT3(string rutaDisco, string nombreParticion, string tipoFormateo);
    void formatearEXT2(string rutaDisco, string nombreParticion, string tipoFormateo);

};

#endif // MKFS_H
