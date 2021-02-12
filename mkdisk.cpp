#include "mkdisk.h"

mkdisk::mkdisk()
{

}


void mkdisk::ejecutarMkdisk(){

    std::cout << "Ejecutando mkdisk..." << std::endl;
}

void mkdisk::mostrarDatos(mkdisk *disco){
    std::cout << " El tamanio del disco es: " << disco->tamanio << std::endl;
}
