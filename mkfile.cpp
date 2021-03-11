#include "mkfile.h"
#include "estructuras.h"
#include "carpeta.h"
#include "mkdir.h"
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


    cout << " >> Ruta de archivo a crear: " << archivo_nuevo->getRuta() << "\n";

    string str = archivo_nuevo->getRuta();
    string delimitador = "/";
    size_t pos = 0;
    string subdir;

    // Ver si tiene carpetas que la contienen
    while ((pos = str.find(delimitador)) != std::string::npos) {
        subdir = str.substr(0, pos);

        if(!subdir.empty()){
            //cout << " >> Carpeta: " <<subdir << endl;
            carpeta *nueva_carpeta = new carpeta();
            nueva_carpeta->setNombreCarpeta(subdir);

            // Crear nueva carpeta con un mkdir
            mkdir *cmd_mkdir = new mkdir();
            cmd_mkdir->crearCarpeta(nombreParticion, ruta, usuario, nueva_carpeta);
        }

        str.erase(0, pos + delimitador.length());
    }

    cout << " >> Archivo a crear " << str << endl;
    // intentar recorrer un inodo
    for(int i = 0; i < inodos_usados; i++){

        fseek(archivo, sb_aux.s_inode_start + i*(sizeof(tablaInodo)), SEEK_SET);
        fread(&inodo_aux, sizeof(tablaInodo), 1, archivo);
        cout << inodo_aux.i_gid << "\n";

    }


    // intentar recorrer un bloque
    bloque_archivo bl_archivo_aux;
    for(int i = 0; i < bloques_usados; i++){
        fseek(archivo, sb_aux.s_block_start + i*64, SEEK_SET);
        fread(&bl_archivo_aux, 64, 1, archivo);

        cout << bl_archivo_aux.b_content << "\n";

    }

    fclose(archivo);

}
