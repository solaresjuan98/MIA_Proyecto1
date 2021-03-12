#ifndef REP_H
#define REP_H
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class rep
{
public:
    rep();

    // REPORTE DE MBR
    void repmbr(string rutaParticion, string nombreParticion, string rutaDestino);
    // REPORTE DE SUBERBLOQUE
    void sb(string rutaParticion, string nombreParticion, string rutaDestino);
    // REPORTE DE DISCO
    void disk(string rutaParticion, string rutaDestino);
};

#endif // REP_H
