#include "mkgrp.h"
#include "estructuras.h"
mkgrp::mkgrp()
{

}


void mkgrp::crearGrupo(string nombreParticion, string ruta){

    FILE *archivo;

    if(archivo == NULL){
        cout << " >> El archivo no existe. \n";
    }

    archivo = fopen(ruta.c_str(), "rb+");

    int tam_particion = 0;
    int inicio_particion = 0;

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    for(int i = 0; i < 4; i++){
        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
            cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }



    // BUSCAR EN QUE LUGAR TENGO ESCRITO EL USERS.TXT

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);

    cout << sb_aux.s_block_start << "\n";
    cout << sb_aux.s_mtime <<  "\n";

}


