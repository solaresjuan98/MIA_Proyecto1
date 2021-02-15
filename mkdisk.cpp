#include "mkdisk.h"
#include <cstdio>
mkdisk::mkdisk() {}

// Getters y setters

void mkdisk::setRuta(string ruta) { this->ruta = ruta; }

string mkdisk::getRuta() { return this->ruta; }

void mkdisk::setTamanio(int tamanio) { this->tamanio = tamanio; }

int mkdisk::getTamanio() { return this->tamanio; }

void mkdisk::setUnidad(string unidad) { this->unidad = unidad; }

string mkdisk::getUnidad() { return this->unidad; }

// ********************

void mkdisk::ejecutarMkdisk() {

  std::cout << "Ejecutando mkdisk..." << std::endl;
}

void mkdisk::mostrarDatos(mkdisk *disco) {
  std::cout << " El tamanio del disco es: " << disco->getTamanio() << std::endl;
}

void mkdisk::crearDisco(mkdisk *disco) {

  FILE *archivo;
  //cout << disco->getRuta() <<endl;
  archivo = fopen(disco->getRuta().c_str(), "wb");
    //archivo = fopen("Disco1", "wb");
  if (archivo == NULL) {
    cout << errno <<endl;
    exit(1);
  }

  // simulando un kilobyte
  char buffer[1024];

  if (disco->getUnidad() == "k" || disco->getUnidad() == "K") {

    for (int i = 0; i < 1024; i++) {
      buffer[i] = '\0';
    }

    for (int i = 0; i < disco->getTamanio(); i++) {
      fwrite(&buffer, 1024, 1, archivo);
    }

    fclose(archivo);
  } else if (disco->getUnidad() == "m" || disco->getUnidad().empty() == 1) {
      cout << "no f" <<endl;
    for (int i = 0; i < 1024; i++) {
      buffer[i] = '\0';
      for (int j = 0; j < (disco->getTamanio() * 1024); i++) {
        fwrite(&buffer, 1024, 1, archivo);
      }
      fclose(archivo);
    }
  }
}
