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
    char id[4];
    //std::string id;
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


//disco discosmontados[26];

/*
class estructuras
{
public:
    estructuras();


};
*/
#endif // ESTRUCTURAS_H
