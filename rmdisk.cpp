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

    cout << " >> ¿Seguro que deseas eliminar el disco? [s/n] \n";

    string confirmacion;
    cin.get();
    cin >> confirmacion;

    if(confirmacion == "s" || confirmacion == "S"){
        cout << " >> Borrando disco... \n";
        strcpy(comando_borrar, cmd.c_str());
        system(comando_borrar);
        cout << " >> Disco borrado. \n";
    }else{
        cout << " >> Operacion abortada. \n";
    }


}
