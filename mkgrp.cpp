#include "mkgrp.h"
#include "estructuras.h"
mkgrp::mkgrp()
{

}


void mkgrp::crearGrupo(string nombreParticion, string ruta, string nombreGrupo){

    FILE *archivo;

    archivo = fopen(ruta.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El archivo no existe. \n";
    }


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

    bloque_carpeta bloque_root;

    // LEO EL BLOQUE EN DONDE ESTÁ EL BLOQUE ROOT
    fseek(archivo, sb_aux.s_block_start, SEEK_SET);
    fread(&bloque_root, sizeof(bloque_carpeta), 1, archivo);

    bloque_archivo bloque_arch;
    fseek(archivo, sb_aux.s_block_start + 64, SEEK_SET);
    fread(&bloque_arch, sizeof(bloque_archivo), 1, archivo);
    cout << bloque_arch.b_content <<  "\n";

    int numero_grupo = 0;// cantidad de grupos que hay en el archivo users.txt
    for(int i = 0; i < 64;i++){

        if(bloque_arch.b_content[i] == 'G' || bloque_arch.b_content[i] == 'g'){
            numero_grupo++;
        }
    }

    string str_grupo = to_string(numero_grupo + 1) + ",G," + nombreGrupo +"\n";
    strcat(bloque_arch.b_content, str_grupo.c_str());

    // guardar los cambios
    fseek(archivo, sb_aux.s_block_start + 64, SEEK_SET);
    fwrite(&bloque_arch, 64, 1, archivo);

    fclose(archivo);


}


