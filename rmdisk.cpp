#include "rmdisk.h"
#include <string.h>
#include <string>

rmdisk::rmdisk()
{

}

void rmdisk::borrarDisco(string rutaArchivo){

    string cmd;
    cmd = "rm " +rutaArchivo;
    int tam_cmd = cmd.length();
    char comando_borrar[tam_cmd +1];

    strcpy(comando_borrar, cmd.c_str());
    system(comando_borrar);

}
