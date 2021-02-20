#include "fdisk.h"
#include "estructuras.h"
fdisk::fdisk()
{

}


// Getters y setters
void fdisk::setAjuste(string ajuste) { this->ajuste = ajuste; }

string fdisk::getAjuste() { return this->ajuste; }

void fdisk::setBorrar(string borrar) { this->borrar = borrar; }

string fdisk::getBorrar() { return this->borrar; }

void fdisk::setRuta(string ruta) { this->ruta = ruta; }

string fdisk::getRuta() { return this->ruta; }

void fdisk::setTamanio(int tamanio) { this->tamanio = tamanio; }

int fdisk::getTamanio() { return this->tamanio; }

void fdisk::setUnidad(string unidad) { this->unidad = unidad; }

string fdisk::getUnidad() { return this->unidad; }

void fdisk::setNombre(string nombre) { this->nombre = nombre; }

string fdisk::getNombre() { return this->nombre; }

void fdisk::setTipo(string tipo) { this->tipo = tipo; }

string fdisk::getTipo() { return this->tipo; }

// Crear particion
void fdisk::crearParticion(fdisk *disco){

    FILE *archivo;
    mbr mbr_tmp;
    int tamanio_parcicion;
    std::cout << disco->getRuta() << "\n";
    archivo = fopen(disco->getRuta().c_str(), "rb+");

    if(archivo == NULL) {
        std::cout << " >> Archivo no encontrado<\n";
        return;
    }

    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_tmp, sizeof(mbr), 1, archivo);


    if(disco->getUnidad() == "k" || disco->getUnidad().empty() == true) {
        tamanio_parcicion = disco->getTamanio() * 1024;
    } else if (disco->getUnidad() == "mb") {
        tamanio_parcicion = disco->getTamanio() * 1024 * 1024;
    } else if (disco->getUnidad() == "b") {
        tamanio_parcicion = disco->getTamanio();
    }

    // Tipos de ajustes

    if(disco->getAjuste() == "B"){
        mbr_tmp.mbr_particions[0].part_fit = 'B';
    }else if (disco->getAjuste() == "F") {
        mbr_tmp.mbr_particions[0].part_fit = 'F';
    }else if (disco->getAjuste() == "W") {
        mbr_tmp.mbr_particions[0].part_fit = 'W';
    }

    strcpy(mbr_tmp.mbr_particions[0].part_name, disco->getNombre().c_str());

    mbr_tmp.mbr_particions[0].part_size = tamanio_parcicion;
    mbr_tmp.mbr_particions[0].part_start = sizeof(mbr);
    mbr_tmp.mbr_particions[0].part_status ='1';

    if(disco->getTipo() == "P" || disco->getTipo().empty() == true){
        mbr_tmp.mbr_particions[0].part_type = 'P';
    } else if (disco->getTipo() == "E") {
        mbr_tmp.mbr_particions[0].part_type = 'E';

        ebr ebr_aux;
        ebr_aux.part_fit = '-';
        ebr_aux.part_name[0] = '\0';
        ebr_aux.part_next = -1;
        ebr_aux.part_size = -1;
        ebr_aux.part_status = '0';

        fseek(archivo, mbr_tmp.mbr_particions[0].part_start, SEEK_SET);
        fwrite(&ebr_aux, sizeof(ebr_aux),1, archivo);

    } /*else if (disco->getTipo() == "L"){
        mbr_tmp.mbr_particions[0].part_type = 'L';
    }*/


    fseek(archivo, 0, SEEK_SET);
    fwrite(&mbr_tmp,sizeof(mbr_tmp), 1, archivo);
    fclose(archivo);

}

// Mostrar datos del disco (y sus particiones)
void fdisk::mostrarDatosDisco(string ruta){
    FILE *archivo;

    archivo = fopen(ruta.c_str(), "rb+");

    if(archivo == NULL){
        std::cout << " >> Archivo no encontrado. \n";
    }

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);
    fclose(archivo);


    std::cout << "\n **** Datos **** \n";

    std::cout << " Nombre mbr: " << mbr_.mbr_disk_signature <<std::endl;
    std::cout << " Tamanio del mbr: " << mbr_.mbr_tamanio << std::endl;

    for(int i = 0; i < 4; i++){
        std::cout << " Estado mbr: " << mbr_.mbr_particions[i].part_status <<std::endl;
        std::cout << " Tipo de particion: " << mbr_.mbr_particions[i].part_type <<std::endl;
        std::cout << " Ajuste de particion: " << mbr_.mbr_particions[i].part_fit <<std::endl;
        std::cout << " Inicio de particion: " << mbr_.mbr_particions[i].part_start <<std::endl;
        std::cout << " Tamanio de particion: " << mbr_.mbr_particions[i].part_size <<std::endl;
        std::cout << " Nombre de particion: " << mbr_.mbr_particions[i].part_name <<std::endl;
    }



}

//Borrar particion
void fdisk::borrarParticion(string ruta, fdisk *disco, string nombreParticion) {

    FILE *archivo;
    archivo = fopen(ruta.c_str(), "rb+");
    std::cout << disco->getBorrar() << std::endl;
    if(archivo == NULL){
        std::cout << " << Disco no encontrado \n";
    }

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);
    fclose(archivo);

    if(disco->getBorrar() == "fast"){ // borrar en modo "fast"

        for(int i = 0; i < 4; i++){
            if(mbr_.mbr_particions[i].part_name == nombreParticion.c_str()){
                //cout << " << Aqui tengo que borrar \n";
            }
        }
    }else if(disco->getBorrar() =="full"){ // borrar en modo "full"
        cout << " >> Borrando en modo \"full\" \n";
        for(int i = 0; i < 4; i++){
            if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
                //cout << " << Aqui tengo que borrar \n";
               mbr_.mbr_particions[i].part_status = 0; // Se pone en estado inactivo
               mbr_.mbr_particions[i].part_name[i] = '\0';
               mbr_.mbr_particions[i].part_type = '-';
               mbr_.mbr_particions[i].part_size = 0;
               mbr_.mbr_particions[i].part_start = -1;
               mbr_.mbr_particions[i].part_fit = '-';

               break;

            }
        }
    }else {
        std::cout << " >> Modo de borrado incorrecto. \n";
    }
}
