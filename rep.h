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
    // REPORTE DE BITMAP DE INODOS
    void bm_inode(string rutaParticion, string nombreParticion, string rutaDestino);
    // REPORTE DE BITMAP DE BLOQUES
    void bm_block(string rutaParticion, string nombreParticion, string rutaDestino);
    // REPORTE DE JOURNALING
    void rep_journaling(string rutaParticion, string nombreParticion, string rutaDestino);

};

#endif // REP_H
