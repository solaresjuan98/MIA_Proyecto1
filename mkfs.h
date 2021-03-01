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
    void formatearEXT3(string rutaDisco, string nombreParticion);
    void formatearEXT2(string rutaDisco, string nombreParticion);
};

#endif // MKFS_H
