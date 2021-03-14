#include "loss.h"
#include "estructuras.h"
loss::loss()
{

}


void loss::simularPerdida(string nombreParticion, string ruta){


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

    /*
        Para el comando loss:
        Llenar con el caracter '\0' los espacios delimitados por:

            * Bloque de bitmap de árbol virtual de directorio
            * Bloque de bitmap de Bloques
            * Inodos
            * Bloque de datos

    */


    char nulo = '\0';

    // Posicionarme en el donde empieza el bitmap de inodos
    fseek(archivo, sb_aux.s_bm_inode_start, SEEK_SET);

    for(int i = 0; i < sb_aux.s_inodes_count; i++){
        fseek(archivo, sb_aux.s_bm_inode_start + i*sizeof(tablaInodo), SEEK_SET);
        fwrite(&nulo, sizeof(char), 1, archivo);
    }


    // Posicionarme en donde empieza el bitmap de bloques
    fseek(archivo, sb_aux.s_bm_block_start, SEEK_SET);

    for(int i = 0; i < sb_aux.s_blocks_count; i++){
        fseek(archivo, sb_aux.s_bm_block_start + (i*64), SEEK_SET);
        fwrite(&nulo, sizeof(char), 1, archivo);
    }


    // Posicionamre en donde empiezan los inodos
    fseek(archivo, sb_aux.s_inode_start, SEEK_SET);

    for(int i = 0; i < sb_aux.s_inodes_count; i++){
        fseek(archivo, sb_aux.s_inode_start + i*sizeof(tablaInodo), SEEK_SET);
        fwrite(&nulo, sizeof(char), 1, archivo);

    }


    // Posicionarme en el bloque de datos
    fseek(archivo, sb_aux.s_block_start, SEEK_SET);

    for(int i = 0; i < sb_aux.s_blocks_count; i++){
        fseek(archivo, sb_aux.s_block_start + i*64, SEEK_SET);
        fwrite(&nulo, sizeof(char), 1, archivo);

    }


    cout << " >> Simulacion de perdida realizada. \n";

    fclose(archivo);

}
