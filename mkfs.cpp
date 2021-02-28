#include "mkfs.h"
#include "estructuras.h"
mkfs::mkfs()
{

}

void mkfs::formatearEXT3(string rutaDisco, char nombreParticion[16]){

    FILE *archivo;
    archivo = fopen(rutaDisco.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }


    mbr mbr_;

    superBloque super_b;
    super_b.s_filesystem_type = 0;
    super_b.s_inodes_count = 0;
    super_b.s_blocks_count = 0;
    super_b.s_free_blocks_count = 0;
    super_b.s_mtime = 0;
    super_b.s_umtine = 0;
    super_b.s_mnt_count = 0;
    super_b.s_magic = 0;
    super_b.s_inode_size = 0;
    super_b.s_block_size = 0;
    super_b.s_first_ino = 0;
    super_b.s_first_block = 0;
    super_b.s_bm_inode_start = 0;
    super_b.s_bm_block_start = 0;
    super_b.s_inode_start = 0;
    super_b.s_block_start = 0;

    journaling journal;
    journal.fecha_op[0] ='\0';
    journal.path[0] = '\0';
    journal.tipo = -1;
    journal.tamanio = 0;
    journal.tipo_op[0] = '\0';

    fseek(archivo, 0, SEEK_SET);


    for(int i = 0; i < 4; i++){

        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion) == 0){
            // Escribiendo el superbloque
            fseek(archivo, mbr_.mbr_particions[i].part_start, SEEK_SET);
            fwrite(&super_b, sizeof(superBloque), 1, archivo);

            // Escribiendo el journaling
            fseek(archivo, mbr_.mbr_particions[i].part_start + sizeof(superBloque), SEEK_SET);
            fwrite(&journal, sizeof(journaling), 1, archivo);
            break;
        }

    }

    cout << " >> Particion formateada. \n";
    fclose(archivo);


}

void mkfs::formatearEXT2(string rutaDisco, char nombreParticion[16]){

    FILE *archivo;
    archivo = fopen(rutaDisco.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    /*
    for(int i = 0; i < 4; i++){

        if(mbr_.mbr_particions[i].)

    }
    */

}
