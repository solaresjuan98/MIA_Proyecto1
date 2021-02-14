#include "mkdisk.h"

mkdisk::mkdisk()
{

}


void mkdisk::ejecutarMkdisk(){

    std::cout << "Ejecutando mkdisk..." << std::endl;
}

void mkdisk::mostrarDatos(mkdisk *disco){
    std::cout << " El tamanio del disco es: " << disco->getTamanio() << std::endl;
}


void mkdisk::setRuta(string ruta){
    this->ruta = ruta;
}

string mkdisk::getRuta(){
    return this->ruta;
}


void mkdisk::setTamanio(int tamanio){
    this->tamanio = tamanio;
}

int mkdisk::getTamanio(){
    return this->tamanio;
}
