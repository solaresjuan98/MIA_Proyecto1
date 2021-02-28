#ifndef MKFS_H
#define MKFS_H

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class mkfs
{
public:
    mkfs();

    // métodos de formateo
    void formatearEXT3(string rutaDisco, char nombreParticion[16]);
    void formatearEXT2(string rutaDisco, char nombreParticion[16]);
};

#endif // MKFS_H
