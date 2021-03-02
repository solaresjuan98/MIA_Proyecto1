#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include "time.h"
#include<iostream>
// extended boot record
typedef struct {
    char part_status;
    char part_fit;
    int part_start;
    int part_size;
    int part_next;
    char part_name[16];
} ebr;

typedef struct {
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_size;
    char part_name[16];

} particion;

// master boot record
typedef struct {
    int mbr_tamanio;
    char mbr_fecha_creacion[16];
    int mbr_disk_signature;
    char disk_fit;
    particion mbr_particions[4];
} mbr;

/*
    PARA COMANDO MOUNT
*/

typedef struct {
    //char id[5];
    std::string id;
    int numero;
    char nombre[16];
    int estado;
} particion_disco;

typedef struct  {
    char letra;
    char ruta[100];
    int estado;
    particion_disco particiones[99];
}disco;

// **********

// JOURNALING
typedef struct {
    char tipo_op[10];
    char tipo;
    char path[100];
    char fecha_op[25];
    int tamanio;
} journaling;

// SUPERBLOQUE
typedef struct {
    int s_filesystem_type;
    int s_inodes_count;
    int s_blocks_count;
    int s_free_blocks_count;
    int s_free_inodes_count;
    char s_mtime[16];
    char s_umtine[16];
    int s_mnt_count;
    int s_magic;
    int s_inode_size;
    int s_block_size;
    int s_first_ino;
    int s_first_block;
    int s_bm_inode_start;
    int s_bm_block_start;
    int s_inode_start;
    int s_block_start;
}superBloque;

typedef struct {
    int i_uid;
    int i_gid;
    int i_size;
    int i_atime;
    int i_ctime;
    int i_mtime;
    int i_block[15];
    int i_type;
    int i_perm;
}tablaInodo;



#endif // ESTRUCTURAS_H
