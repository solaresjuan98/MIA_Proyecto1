#include "mkdisk.h"
#include <cstdio>
#include "estructuras.h"

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

  mbr prueba_mbr;
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
    //si son megas
  } else if (disco->getUnidad() == "m" || disco->getUnidad().empty() == 1) {
      cout << "no f" <<endl;
    for (int i = 0; i < 1024; i++) {
      buffer[i] = '\0';
      for (int j = 0; j < (disco->getTamanio() * 1024); i++) {
        fwrite(&buffer, 1024, 1, archivo);
      }
      fclose(archivo);
    }

    // **** Etiqueta única para el disco ****
    prueba_mbr.mbr_disk_signature = (rand() %100);

    string fechaPrueba = "15/02/2020 21:38";

    particion particion_vacia;
    particion_vacia.part_status = '0';
    particion_vacia.part_type = '-';
    particion_vacia.part_start = -1;
    particion_vacia.part_size = -1;
    particion_vacia.part_name[0] = '\0';

    for(int i = 0; i < 4; i++){
        prueba_mbr.mbr_particions[i] = particion_vacia;
    }
  }
}
