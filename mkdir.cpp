#include "mkdir.h"
#include "estructuras.h"

mkdir::mkdir()
{

}


void mkdir::crearCarpeta(string nombreParticion, string ruta, user *usuario, carpeta *carpeta_nueva){

    FILE *archivo;

    archivo = fopen(ruta.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El archivo no se ha encontrado. \n";
    }

    int tam_particion = 0;
    int inicio_particion = 0;

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    for(int i = 0; i < 4; i++){
        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
            //cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);

    // Declaro mis inodos y bloques usados
    int inodos_usados = sb_aux.s_inodes_count - sb_aux.s_free_inodes_count;
    int bloques_usados = sb_aux.s_blocks_count - sb_aux.s_free_blocks_count;

    bloque_carpeta bl_carpeta_aux;
    int bloque_actual = 0;
    int num_carpetas = 0;
    bool bloqueLleno = false;

    tablaInodo inodo_raiz;
    fseek(archivo, sb_aux.s_inode_start, SEEK_SET);
    fread(&inodo_raiz, sizeof(tablaInodo), 1, archivo);

    for(int i = 0; i < 15; i++){

        // Si el registro tiene bloques
        if(inodo_raiz.i_block[i] != -1){
            // buscar bloque
            buscarCarpeta(nombreParticion, ruta, carpeta_nueva->getNombreCarpeta());
        }
    }


    //fseek(archivo, sb_aux.s_block_start, SEEK_SET);

    /*
        Mi punto de partida para realizar este algoritmo es el inodo inicial
    */

    /*
    // VER SI YA EXISTE EL BLOQUE DE CARPETA
    for(int i = 0; i < bloques_usados; i++){

        //  cout << " >> Bloque actual que estoy leyendo "
        fseek(archivo, sb_aux.s_block_start + (i*64), SEEK_SET);
        fread(&bl_carpeta_aux, 64, 1, archivo);

        for(int j = 0; j < 4; j++){

            cout << " >> " << bl_carpeta_aux.b_content[j].b_inodo << "\n"; // apuntador al siguiente inodo
            cout << " >> " << bl_carpeta_aux.b_content[j].b_name << "\n";

            // Ya existe la carpeta en el bloque
            if(strcmp(bl_carpeta_aux.b_content[j].b_name, carpeta_nueva->getNombreCarpeta().c_str()) == 0){
                // crear un nuevo inodo

            }

            if(bl_carpeta_aux.b_content[j].b_inodo == -1){
                num_carpetas++;
            }

            if(num_carpetas == 4){
                bloqueLleno = true;
            }
        }
    }

    // Si el bloque está lleno, creo el inodo dependiendo de donde esté
    if(bloqueLleno){

    }
    */

}

void mkdir::buscarCarpeta(string nombreParticion, string ruta, string nombre_carpeta){

    FILE *archivo;

    archivo = fopen(ruta.c_str(), "rb+");

    int tam_particion = 0;
    int inicio_particion = 0;

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    for(int i = 0; i < 4; i++){
        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
            //cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);

    // Declaro mis bloques usados
    int bloques_usados = sb_aux.s_blocks_count - sb_aux.s_free_blocks_count;

    bloque_carpeta bl_carpeta_aux;

    fseek(archivo, sb_aux.s_block_start, SEEK_SET);
    for(int i = 0; i < bloques_usados; i++){
        fseek(archivo, sb_aux.s_block_start + (i*64), SEEK_SET);
        fread(&bl_carpeta_aux, 64, 1, archivo);
        for(int j = 0; j < 4; j++){
            if(strcmp(bl_carpeta_aux.b_content[j].b_name, nombre_carpeta.c_str()) == 0){
                cout << " La carpeta ya existe \n";
            }
        }
    }

    fclose(archivo);
}
