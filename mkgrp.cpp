#include "mkgrp.h"
#include "estructuras.h"
mkgrp::mkgrp()
{

}


void mkgrp::crearGrupo(string nombreParticion, string ruta, string nombreGrupo){

    // Fecha actual
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char fechaActual[16];
    strftime(fechaActual,16,"%d/%m/%y %H:%M:%S",tlocal);


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


    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);
    cout << " >> "<<sb_aux.s_filesystem_type << "\n";

    // DECLARAR EL INODO PADRE DEL BLOQUE DEL ARCHIVO USERS.TXT
    tablaInodo inodoUserstxt;
    // BUSCAR EN QUE PARTE TENGO EL INODO DEL ARCHIVO USERS.TXT
    fseek(archivo, sb_aux.s_bm_inode_start+sizeof(tablaInodo), SEEK_SET);
    fread(&inodoUserstxt, sizeof(tablaInodo), 1, archivo);
    /*
    prueba de que si lee el inodo y sus bloques
    for(int i = 0; i < 15; i++){
        cout << inodoUserstxt.i_block[i] << "\n";
    }
    */

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

    int espaciosUsados = 0;

    for(int i = 0; i < 64; i++){
       char c = bloque_arch.b_content[i];

        if(isalpha(c)){
            espaciosUsados++;
        }else if(isdigit(c)){
            espaciosUsados++;
        }else if(c == ','){
            espaciosUsados++;
        }else if(c == '\n'){
            espaciosUsados++;
        }

    }

    if(espaciosUsados >= 64){
        cout << " El bloque está lleno \n";
        /*
            Crear otro bloque y pasar el contenido sobrante al bloque
        */

        // Buscar el inodo del archivo
        fseek(archivo, sb_aux.s_bm_inode_start+sizeof(tablaInodo), SEEK_SET);
        fread(&inodoUserstxt, sizeof(tablaInodo), 1, archivo);

        for(int i = 0; i < 15; i++){

            // encuentro un bloque inactivo
            if(inodoUserstxt.i_block[i] == -1){
                cout << inodoUserstxt.i_block[i] << "\n";
                inodoUserstxt.i_block[i] = 1;// pasarlo a estado activo

                bloque_archivo bloque_nuevo;
                strcpy(bloque_nuevo.b_content, str_grupo.c_str());
                // escribiendo los cambios en el inodos
                fwrite(&inodoUserstxt, 64, 1, archivo);
                fseek(archivo, sb_aux.s_block_start + (64 *(i+1)), SEEK_SET);
                fwrite(&bloque_nuevo, 64, 1, archivo);

                //
                sb_aux.s_free_blocks_count--;
                fseek(archivo, inicio_particion, SEEK_SET);
                fwrite(&sb_aux, sizeof(superBloque), 1, archivo);
                cout << sb_aux.s_free_blocks_count << endl;

                // modificar el bitmap de inodos
                //fseek(archivo, );
                break;
            }
        }
    }else{
        //cout << " El bloque aun no esta lleno \n";
        // guardar los cambios
        fseek(archivo, sb_aux.s_block_start + 64, SEEK_SET);
        fwrite(&bloque_arch, 64, 1, archivo);

        // modificar el bitmap de inodos
        fseek(archivo, sb_aux.s_bm_block_start, SEEK_SET);
        int fin_bloques = sb_aux.s_bm_block_start + sb_aux.s_blocks_count;
        char bl_actual;
        for(int i = sb_aux.s_block_start; i < fin_bloques; i++){
            // aqui me quede :(
            //fread(,);
        }

        // Escribir en el journaling el cambio que hice
        // validar si la particion está formateada en EXT3 para escribir en el journaling
        /*if(sb_aux.s_filesystem_type == 3){
            journaling journal_usuario;
            strcpy(journal_usuario.tipo_op, "mkgrp");
            strcpy(journal_usuario.fecha_op, fechaActual);
            strcpy(journal_usuario.path, "/users.txt");
            journal_usuario.id_propietario = '1';
            strcpy(journal_usuario.contenido, str_grupo.c_str());
            journal_usuario.tipo = '1';

            fseek(archivo, inicio_particion + sizeof(superBloque), SEEK_SET);


        }*/

    }



    // cerrar el archivo
    fclose(archivo);


}


