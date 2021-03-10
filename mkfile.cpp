#include "mkfile.h"
#include "estructuras.h"

mkfile::mkfile()
{

}


void mkfile::crearArchivo(string nombreParticion, string ruta, user *usuario, file *archivo_nuevo){

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
            cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);
    cout << " >> Inodo  "<< sb_aux.s_inodes_count << "\n";
    cout << " >> Bloque "<< sb_aux.s_blocks_count << "\n";
    cout << " >> Inodos libres "<< sb_aux.s_free_inodes_count << "\n";
    cout << " >> Bloques libres "<< sb_aux.s_free_blocks_count << "\n";

    // Declaro mis inodos y bloques usados
    int inodos_usados = sb_aux.s_inodes_count - sb_aux.s_free_inodes_count;
    int bloques_usados = sb_aux.s_blocks_count - sb_aux.s_free_blocks_count;

    cout <<" >> "<< sb_aux.s_inode_start << endl;

    tablaInodo inodo_aux;
    bloque_carpeta bl_carpeta_aux;
    // intentar recorrer un inodo
    for(int i = 0; i < inodos_usados; i++){

        fseek(archivo, sb_aux.s_inode_start + i*(sizeof(tablaInodo)), SEEK_SET);
        fread(&inodo_aux, sizeof(tablaInodo), 1, archivo);
        cout << inodo_aux.i_gid << "\n";

        for(int j = 0; j <15; j++){
            if(inodo_aux.i_block[j] != -1){
                cout << inodo_aux.i_block[j] << "\n";


            }
        }


    }

    fclose(archivo);

}
