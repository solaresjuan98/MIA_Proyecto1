#include "mkfs.h"
#include "estructuras.h"
#include "math.h"
mkfs::mkfs()
{

}

void mkfs::formatearEXT3(string rutaDisco, string nombreParticion){


    FILE *archivo;
    // abrir el archivo donde se encuentra el "disco"
    archivo = fopen(rutaDisco.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }

    //cout << nombreParticion <<  "\n";
    // Tamanio de la particion
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




    // Valores para aplicar formula
    int n2 = 0;


    // APLICAR FORMULA
    n2 = (tam_particion-sizeof(superBloque))/(4+sizeof(journaling)+sizeof(tablaInodo)+3*64);

    int n = sqrt(n2);
    int numeroEstructuras = n;
    int numeroInodos = n;
    int numeroJournaling = n;
    int numeroBloques = 3*n;
    int bitmapInodos = n;
    int bitmapBloques = 3*n;

    cout << " n: " << n << endl;
    cout << " 3*n: " << 3*n << endl;

    superBloque super_b;
    super_b.s_filesystem_type = 0;
    super_b.s_inodes_count = numeroInodos;
    super_b.s_blocks_count = numeroBloques;
    super_b.s_free_blocks_count = 0;
    super_b.s_mtime[0] = '0';
    super_b.s_umtine[0] = '0';
    super_b.s_mnt_count = 0;
    super_b.s_magic = 0;
    super_b.s_inode_size = sizeof(tablaInodo);
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

    fseek(archivo, inicio_particion, SEEK_SET);

    // escribiendo el superbloque al inicio de la particion
    fwrite(&super_b, sizeof(superBloque), 1, archivo);

    // posicionarme en el lugar donde quiero escribir el journaling
    fseek(archivo, sizeof(superBloque), SEEK_SET);

    // Escribir el journaling
    for(int i = 0; i < numeroJournaling; i++){
        fseek(archivo, sizeof(superBloque)+ i, SEEK_SET);
        fwrite(&journal, sizeof(journal), 1, archivo);
        //cout << "." << endl;
    }

    // posicionarme en el lugar donde quiero escribir el bitmap de inodos
    fseek(archivo, sizeof(superBloque)+numeroJournaling*(sizeof(journaling)), SEEK_SET);

    // Escribir el bitmap de inodos
    char bitCero = '0';
    for(int i = 0; i < bitmapInodos; i++){
        fseek(archivo, sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+i*(sizeof(bitmapInodos)), SEEK_SET);
        fwrite(&bitCero, sizeof(char), 1, archivo);
        //cout << ". \n";
    }


    // posicionarme en el lugar donde quiero escribir el bitmap de bloques
    fseek(archivo, sizeof(superBloque)+numeroJournaling*(sizeof(journaling)+bitmapInodos*sizeof(char)), SEEK_SET);
    for(int i = 0; i < bitmapBloques; i++){
        fseek(archivo, sizeof(superBloque)+numeroJournaling*(sizeof(journaling)+bitmapInodos*sizeof(char))+i*sizeof(bitmapBloques), SEEK_SET);
        fwrite(&bitCero, sizeof(char), 1, archivo);
    }

    // TABLA DE INODOS
    tablaInodo tInodo;
    tInodo.i_uid = 0;
    tInodo.i_gid = 0;
    tInodo.i_size = 0;
    tInodo.i_atime =' ';
    tInodo.i_ctime =' ';
    tInodo.i_mtime = ' ';
    for(int i = 0; i < 15; i++){
        tInodo.i_block[i] = 0;

        if(i == 14){
            tInodo.i_block[i] = -1;
        }
    }
    tInodo.i_type = 0;
    tInodo.i_perm = 0; // Guarda los permisos del archivo / carpeta

    // posicionarme donde quiero empezar a escribir mis inodos
    fseek(archivo, sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char), SEEK_SET);

    // Escribir inodos
    for(int i = 0; i < numeroInodos; i++){
        fseek(archivo, sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char)+i*sizeof(tInodo), SEEK_SET);
        fwrite(&tInodo, sizeof(tablaInodo), 1, archivo);
    }



    // Escribir bloques

    cout << " >> Particion formateada en EXT3. \n";
    fclose(archivo);


}

void mkfs::formatearEXT2(string rutaDisco, string nombreParticion){

    FILE *archivo;
    // archivo donde esta el "disco"
    archivo = fopen(rutaDisco.c_str(), "rb+");


    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
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

    int n = 0;
    cout << " >> Formateando " <<tam_particion << "bytes...\n";
    n = (tam_particion - sizeof(superBloque))/(4+sizeof(tablaInodo)+3*64);

    int numeroEstructuras = n;
    int numeroInodos = n;
    int numeroBloques = 3*n;
    int bitmapInodos = n;
    int bitmapBloques = 3*n;

    cout << " n: " << n << endl;
    cout << " 3*n: " << 3*n << endl;

    // Defino el superbloque
    superBloque super_b;
    super_b.s_filesystem_type = 0;
    super_b.s_inodes_count = numeroInodos;
    super_b.s_blocks_count = numeroBloques;
    super_b.s_free_blocks_count = 0;
    super_b.s_mtime[0] = '0';
    super_b.s_umtine[0] = '0';
    super_b.s_mnt_count = 0;
    super_b.s_magic = 0;
    super_b.s_inode_size = sizeof(tablaInodo);
    super_b.s_block_size = 0;
    super_b.s_first_ino = 0;
    super_b.s_first_block = 0;
    super_b.s_bm_inode_start = 0;
    super_b.s_bm_block_start = 0;
    super_b.s_inode_start = 0;
    super_b.s_block_start = 0;

    fseek(archivo, inicio_particion, SEEK_SET);

    // escribiendo el superbloque al inicio de la particion
    fwrite(&super_b, sizeof(superBloque), 1, archivo);

    // posicionarme en el lugar donde quiero escribir el bitmap de inodos
    fseek(archivo, sizeof(superBloque), SEEK_SET);

    // Escribir el bitmap de inodos
    char bitCero = '0';
    for(int i = 0; i < bitmapInodos; i++){
        fseek(archivo, sizeof(superBloque)+i*(sizeof(bitmapInodos)), SEEK_SET);
        fwrite(&bitCero, sizeof(char), 1, archivo);
        //cout << ". \n";
    }


    // posicionarme en el lugar donde quiero escribir el bitmap de bloques
    fseek(archivo, sizeof(superBloque)+bitmapInodos*sizeof(char), SEEK_SET);
    // Escribir el bitmap de bloques
    for(int i = 0; i < bitmapBloques; i++){
        fseek(archivo, sizeof(superBloque)+bitmapInodos*sizeof(char)+i*sizeof(bitmapBloques), SEEK_SET);
        fwrite(&bitCero, sizeof(char), 1, archivo);
    }

    bloque_carpeta bl_carpeta;

    for(int i = 0; i < 4; i++){
        bl_carpeta.b_content[i].b_inodo = 0;
        bl_carpeta.b_content[i].b_name[0] = '0';
    }

    // posicionarme en el lugar donde quiero escribir los bloques
    fseek(archivo, sizeof(superBloque)+bitmapInodos*sizeof(char)+bitmapBloques*sizeof(bitmapBloques) , SEEK_SET);

    for(int i = 0; i < numeroBloques; i++){
        fseek(archivo, sizeof(superBloque)+bitmapInodos*sizeof(char)+bitmapBloques*sizeof(bitmapBloques)+i*64, SEEK_SET);
        fwrite(&bl_carpeta, sizeof(bloque_carpeta), 1, archivo);
    }

    // TABLA DE INODOS
    tablaInodo tInodo;
    tInodo.i_uid = 0;
    tInodo.i_gid = 0;
    tInodo.i_size = 0;
    tInodo.i_atime =' ';
    tInodo.i_ctime =' ';
    tInodo.i_mtime = ' ';
    for(int i = 0; i < 15; i++){
        tInodo.i_block[i] = 0;

        if(i == 14){
            tInodo.i_block[i] = -1;
        }
    }
    tInodo.i_type = 0;
    tInodo.i_perm = 0; // Guarda los permisos del archivo / carpeta

    // posicionarme donde quiero empezar a escribir mis inodos
    fseek(archivo, sizeof(superBloque)+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char), SEEK_SET);

    // Escribir inodos
    for(int i = 0; i < numeroInodos; i++){
        fseek(archivo, sizeof(superBloque)+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char)+i*sizeof(tInodo), SEEK_SET);
        fwrite(&tInodo, sizeof(tablaInodo), 1, archivo);
    }


    cout << " >> Particion formateada en EXT2. \n";
    fclose(archivo);

}
