#include "mkusr.h"
#include "estructuras.h"
#include "user.h"
mkusr::mkusr()
{

}

void mkusr::crearUsuario(string nombreParticion, string rutaParticion, user *usuario){

    // Fecha actual
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char fechaActual[16];
    strftime(fechaActual,16,"%d/%m/%y %H:%M:%S",tlocal);

    FILE *archivo;

    archivo = fopen(rutaParticion.c_str(), "rb+");

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

    // BUSCAR EN QUE LUGAR TENGO ESCRITO EL USERS.TXT

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);

    // DECLARAR EL INODO PADRE DEL BLOQUE DEL ARCHIVO USERS.TXT
    tablaInodo inodoUserstxt;
    // BUSCAR EN QUE PARTE TENGO EL INODO DEL ARCHIVO USERS.TXT
    fseek(archivo, sb_aux.s_bm_inode_start+sizeof(tablaInodo), SEEK_SET);
    fread(&inodoUserstxt, sizeof(tablaInodo), 1, archivo);


    bloque_carpeta bloque_root;

    // LEO EL BLOQUE EN DONDE ESTÁ EL BLOQUE ROOT
    fseek(archivo, sb_aux.s_block_start, SEEK_SET);
    fread(&bloque_root, sizeof(bloque_carpeta), 1, archivo);

    bloque_archivo bloque_arch;
    fseek(archivo, sb_aux.s_block_start + 64, SEEK_SET);
    fread(&bloque_arch, sizeof(bloque_archivo), 1, archivo);
    cout << bloque_arch.b_content <<  "\n";


    int numero_usuario = 0;// cantidad de usuarios que hay en el archivo users.txt
    for(int i = 0; i < 64;i++){

        if(bloque_arch.b_content[i] == 'U' || bloque_arch.b_content[i] == 'u'){
            numero_usuario++;
        }
    }

    string str_usuario = to_string(numero_usuario + 1) + ",U," + usuario->getGrupo() +
            ","+usuario->getNombreUsuario()+","+usuario->getContrasenia()+"\n";
    strcat(bloque_arch.b_content, str_usuario.c_str());

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

    // Se lleno el bloque
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


                // Crear un nuevo bloque de archivo para meter el resto del contenido
                bloque_archivo bloque_nuevo;
                strcpy(bloque_nuevo.b_content, str_usuario.c_str());
                // escribiendo los cambios en el inodos
                fwrite(&inodoUserstxt, 64, 1, archivo);
                fseek(archivo, sb_aux.s_block_start + (64 *(i+1)), SEEK_SET);
                fwrite(&bloque_nuevo, 64, 1, archivo);

                //
                sb_aux.s_free_blocks_count--;
                fseek(archivo, inicio_particion, SEEK_SET);
                fwrite(&sb_aux, sizeof(superBloque), 1, archivo);
                cout << sb_aux.s_free_blocks_count << endl;
                break;
            }
        }


    }else{

        // guardar los cambios
        fseek(archivo, sb_aux.s_block_start + 64, SEEK_SET);
        fwrite(&bloque_arch, 64, 1, archivo);
    }


    fclose(archivo);

}


