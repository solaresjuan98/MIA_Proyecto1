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
    int fin_particion;
    std::cout << disco->getRuta() << "\n";
    archivo = fopen(disco->getRuta().c_str(), "rb+");


    if(archivo == NULL) {
        std::cout << " >> Archivo no encontrado<\n";
        return;
    }

    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_tmp, sizeof(mbr), 1, archivo);

    // Tamaño total del archivo (en bytes)
    fseek(archivo, 0L, SEEK_END);
    long int res = ftell(archivo);
    std::cout << res << "\n";

    if(disco->getUnidad() == "k" || disco->getUnidad().empty() == true) {
        tamanio_parcicion = disco->getTamanio() * 1024;
    } else if (disco->getUnidad() == "mb") {
        tamanio_parcicion = disco->getTamanio() * 1024 * 1024;
    } else if (disco->getUnidad() == "b") {
        tamanio_parcicion = disco->getTamanio();
    }

    for(int i = 0; i < 4; i++){

        // me ubico en una particion inactiva
        if(mbr_tmp.mbr_particions[i].part_status == '0'){
            std::cout << " Aqui tengo que crear la particion. \n";

            if(disco->getAjuste() == "B"){
                mbr_tmp.mbr_particions[i].part_fit = 'B';
            }else if (disco->getAjuste() == "F") {
                mbr_tmp.mbr_particions[i].part_fit = 'F';
            }else if (disco->getAjuste() == "W") {
                mbr_tmp.mbr_particions[i].part_fit = 'W';

                /*
                    int inicioParticion = calcularAjusteW();
                    USAR RANGOS PARA LOS AJUSTES
                */
            }

            strcpy(mbr_tmp.mbr_particions[i].part_name, disco->getNombre().c_str());

            mbr_tmp.mbr_particions[i].part_size = tamanio_parcicion;
            //mbr_tmp.mbr_particions[i].part_start = sizeof(mbr);// CAMBIAR ESTE VALOR POR EL CALCULO DE LOS AJUSTES



            if(i == 0){
                 mbr_tmp.mbr_particions[i].part_start = sizeof(mbr);
            }
            else if(i >= 1){
                mbr_tmp.mbr_particions[i].part_start = mbr_tmp.mbr_particions[i-1].part_start+mbr_tmp.mbr_particions[i-1].part_size;
            }

            fin_particion = tamanio_parcicion + sizeof(mbr);
            std::cout << " >> La particion va de " << sizeof(mbr) << " a " << fin_particion;
            mbr_tmp.mbr_particions[i].part_status ='1';

            if(disco->getTipo() == "P" || disco->getTipo().empty() == true){
                // creaando una particion primaria
                mbr_tmp.mbr_particions[i].part_type = 'P';

            } else if (disco->getTipo() == "E") {
                // creando una parcicion extendida
                std::cout << " >> Creando una particion extendida... \n";
                mbr_tmp.mbr_particions[i].part_type = 'E';

                ebr ebr_aux;
                ebr_aux.part_fit = '-';
                ebr_aux.part_name[i] = '\0';
                ebr_aux.part_next = -1;
                ebr_aux.part_size = -1;
                ebr_aux.part_status = '0';


                fseek(archivo, mbr_tmp.mbr_particions[i].part_start, SEEK_SET);
                fwrite(&ebr_aux, sizeof(ebr_aux),1, archivo);

            }

            break;
        }
    }


    fseek(archivo, 0, SEEK_SET);
    fwrite(&mbr_tmp,sizeof(mbr_tmp), 1, archivo);
    fclose(archivo);


}

// Mostrar datos del disco (y sus particiones)
void fdisk::mostrarDatosDisco(string ruta){
    FILE *archivo;
    //int espacioLibre;

    // Tamaño total del archivo (en bytes)
    archivo = fopen(ruta.c_str(), "rb+");
    fseek(archivo, 0L, SEEK_END);
    long int tamanioArchivo = ftell(archivo);
    std::cout << tamanioArchivo << "\n";
    int particionesInactivas = 0;
    archivo = fopen(ruta.c_str(), "rb+");

    if(archivo == NULL){
        std::cout << " >> Archivo no encontrado. \n";
    }

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);
    //fclose(archivo);

    std::cout << "\n **** Datos **** \n";

    std::cout << " Mbr signature: " << mbr_.mbr_disk_signature <<std::endl;
    std::cout << " Tamanio del mbr: " << mbr_.mbr_tamanio << "\n\n";
    //std::cout << " Fecha "
    for(int i = 0; i < 4; i++){
        std::cout << " Estado de particion: " << mbr_.mbr_particions[i].part_status <<std::endl;
        std::cout << " Tipo de particion: " << mbr_.mbr_particions[i].part_type <<std::endl;
        std::cout << " Ajuste de particion: " << mbr_.mbr_particions[i].part_fit <<std::endl;
        std::cout << " Inicio de particion: " << mbr_.mbr_particions[i].part_start <<std::endl;
        std::cout << " Tamanio de particion: " << mbr_.mbr_particions[i].part_size <<std::endl;
        std::cout << " Nombre de particion: " << mbr_.mbr_particions[i].part_name <<std::endl;
        std::cout << "\n\n";


        // Estoy en una partición inactiva (no tomo en cuenta el tamaño, ni inicio porque no tienen)
        if(mbr_.mbr_particions[i].part_status == '0'){
            particionesInactivas++;
            //std::cout << " Hay un rango vacío en [" << mbr_.mbr_particions[i-1].part_start + mbr_.mbr_particions[i-1].part_size<< ",";
                      //<< mbr_.mbr_particions[i+1].part_start << std::endl;
            if(i == 3){ // la ultima particion está sin ocupar
                std::cout << mbr_.mbr_particions[i-1].part_start + mbr_.mbr_particions[i-1].part_size <<"] "<<std::endl;
            }else{
                std::cout << mbr_.mbr_particions[i+1].part_start <<"] "<< std::endl;
            }
        }
    }

    // Si no hay particiones activas (dentro del mbr)
    if(particionesInactivas == 4){
        std::cout << " >> (No hay particiones). Hay espacio libre en el rango ["<<sizeof(mbr) << "," <<tamanioArchivo<<"]\n";
    }






}

//Borrar particion
void fdisk::borrarParticion(string ruta, fdisk *disco, string nombreParticion) {

    FILE *archivo;
    archivo = fopen(ruta.c_str(), "rb+");

    if(archivo == NULL){
        std::cout << " >> Disco no encontrado \n";
    }

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    // Particion vacia
    particion particion_vacia;
    particion_vacia.part_status = '0';
    particion_vacia.part_type = '-';
    particion_vacia.part_start = -1;
    particion_vacia.part_size = -1;
    particion_vacia.part_name[0] = '\0';

    if(disco->getBorrar() == "fast"){ // borrar en modo "fast"

        for(int i = 0; i < 4; i++){
            if(mbr_.mbr_particions[i].part_name == nombreParticion.c_str()){
                //cout << " << Aqui tengo que borrar \n";
            }
        }
    }else if(disco->getBorrar() =="full"){ // borrar en modo "full"
        cout << " >> Borrando en modo full \n";
        for(int i = 0; i < 4; i++){

            if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
               //cout << " >> Borrando... \n";
               mbr_.mbr_particions[i] = particion_vacia;
               std::cout << " Estado de particion: " << mbr_.mbr_particions[i].part_status <<std::endl;
               std::cout << " Tipo de particion: " << mbr_.mbr_particions[i].part_type <<std::endl;
               std::cout << " Ajuste de particion: " << mbr_.mbr_particions[i].part_fit <<std::endl;
               std::cout << " Inicio de particion: " << mbr_.mbr_particions[i].part_start <<std::endl;
               std::cout << " Tamanio de particion: " << mbr_.mbr_particions[i].part_size <<std::endl;
               std::cout << " Nombre de particion: " << mbr_.mbr_particions[i].part_name <<std::endl;
               std::cout << "\n\n";

               fseek(archivo, 0, SEEK_SET);
               fwrite(&mbr_, sizeof(mbr), 1, archivo);
            }
        }
    }else {
        std::cout << " >> Modo de borrado incorrecto. \n";
    }

    //fwrite(&mbr_, mbr_.mbr_particions[i], 1, archivo);
    fclose(archivo);

}
