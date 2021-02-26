#ifndef UNMOUNT_H
#define UNMOUNT_H
#include "estructuras.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class unmount
{
public:
    unmount();

    particion_disco desmontarParticion(string id);
};

#endif // UNMOUNT_H
