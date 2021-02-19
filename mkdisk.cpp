#include "mkdisk.h"
#include "estructuras.h"
#include <cstdio>

mkdisk::mkdisk() {}

// Getters y setters

void mkdisk::setRuta(string ruta) { this->ruta = ruta; }

string mkdisk::getRuta() { return this->ruta; }

void mkdisk::setTamanio(int tamanio) { this->tamanio = tamanio; }

int mkdisk::getTamanio() { return this->tamanio; }

void mkdisk::setUnidad(string unidad) { this->unidad = unidad; }

string mkdisk::getUnidad() { return this->unidad; }

void mkdisk::setFechaCreacion(string fecha) { this->fecha_creacion = fecha; }

string mkdisk::getFechaCreacion() { return this->fecha_creacion; }

void mkdisk::setAjuste(string ajuste) { this->ajuste = ajuste; }

string mkdisk::getAjuste() { return this->ajuste; }

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
  // cout << disco->getRuta() <<endl;
  archivo = fopen(disco->getRuta().c_str(), "wb");
  // archivo = fopen("Disco1", "wb");
  if (archivo == NULL) {
    cout << errno << endl;
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
  } else if (disco->getUnidad() == "m" || disco->getUnidad() == "M" ||
             disco->getUnidad().empty() == 1) {

    for (int i = 0; i < 1024; i++) {
      buffer[i] = '\0';
      for (int j = 0; j < (disco->getTamanio() * 1024); i++) {
        fwrite(&buffer, 1024, 1, archivo);
      }
      fclose(archivo);
    }
  }
  // **** Etiqueta única para el disco ****

  string fechaPrueba = "15/02/2020 21:38";
  disco->setFechaCreacion(fechaPrueba);

  prueba_mbr.mbr_disk_signature = (rand() % 100);
  strcpy(prueba_mbr.mbr_fecha_creacion, fechaPrueba.c_str());

  if (disco->getAjuste().empty()) {
    strcpy(&prueba_mbr.disk_fit, "F");
  } else {
    strcpy(&prueba_mbr.disk_fit, disco->getAjuste().c_str());
  }

  particion particion_vacia;
  particion_vacia.part_status = '0';
  particion_vacia.part_type = '-';
  particion_vacia.part_start = -1;
  particion_vacia.part_size = -1;
  particion_vacia.part_name[0] = '\0';

  for (int i = 0; i < 4; i++) {
    prueba_mbr.mbr_particions[i] = particion_vacia;
  }

  archivo = fopen(disco->getRuta().c_str(), "rb+");

  if (archivo != NULL) {
    fseek(archivo, 0, SEEK_SET);
    fwrite(&prueba_mbr, sizeof(mbr), 1, archivo);
    fclose(archivo);
    cout << " Disco creado correctanmente. " << endl;
    cout << " Se agrego el mbr de forma correcta. " << endl;

  } else {
    cout << " Error. MBR no creado. " << endl;
  }
}
