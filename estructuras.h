#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include "time.h"

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



class estructuras
{
public:
    estructuras();


};

#endif // ESTRUCTURAS_H
