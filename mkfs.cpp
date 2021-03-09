#include "mkfs.h"
#include "estructuras.h"
#include "math.h"
mkfs::mkfs()
{

}


void mkfs::formatearEXT3(string rutaDisco, string nombreParticion, string tipoFormateo){


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
    int n = 0;
    cout << " >> Formateando " << tam_particion << " bytes...\n";
    // APLICAR FORMULA
    n = (tam_particion-sizeof(superBloque))/
            (4+sizeof(journaling)+sizeof(tablaInodo)+3*64);

    cout << " n: " << n << endl;
    cout << " 3n: " << 3*n <<  endl;

    fseek(archivo, inicio_particion, SEEK_SET);
    if(tipoFormateo == "full"){

        char bytenulo = '0';
        // llenar de ceros la sección
        for(int i = 0; i < tam_particion; i++){

            fwrite(&bytenulo, sizeof(bytenulo), 1, archivo);
            fseek(archivo, inicio_particion + i, SEEK_SET);
        }
    }

    int numeroEstructuras = n;
    int numeroInodos = n;
    int numeroJournaling = n;
    int numeroBloques = 3*n;
    int bitmapInodos = n;
    int bitmapBloques = 3*n;


    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char fechaActual[16];
    strftime(fechaActual,16,"%d/%m/%y %H:%M:%S",tlocal);

    superBloque super_b;
    super_b.s_filesystem_type = 3;
    super_b.s_inodes_count = numeroInodos;
    super_b.s_blocks_count = numeroBloques;
    super_b.s_free_blocks_count = 3*n;
    super_b.s_free_inodes_count = numeroInodos;
    strcpy(super_b.s_mtime, fechaActual);
    strcpy(super_b.s_umtine, "");
    super_b.s_umtine[0] = '0';
    super_b.s_mnt_count = 1;
    super_b.s_magic = 0xEF53;
    super_b.s_inode_size = sizeof(tablaInodo);
    super_b.s_block_size = sizeof(bloque_archivo);
    super_b.s_first_ino = 2;
    super_b.s_first_block = 2;
    super_b.s_bm_inode_start = inicio_particion + sizeof(superBloque) + n*sizeof(journaling);
    super_b.s_bm_block_start = super_b.s_bm_inode_start + n;
    super_b.s_inode_start = super_b.s_block_start + 3*n;
    super_b.s_block_start = super_b.s_bm_inode_start+n*sizeof(tablaInodo);

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
    cout << " 1. " << inicio_particion + sizeof(superBloque) << "\n";
    fseek(archivo, inicio_particion +sizeof(superBloque), SEEK_SET);

    // Escribir el journaling
    for(int i = 0; i < numeroJournaling; i++){
        fseek(archivo,inicio_particion + sizeof(superBloque)+ i, SEEK_SET);
        fwrite(&journal, sizeof(journal), 1, archivo);

    }

    // Escribir el journal de la carpeta
    journaling journalCarpeta;
    strcpy(journalCarpeta.tipo_op, "mkfs");
    strcpy(journalCarpeta.fecha_op, fechaActual);
    strcpy(journalCarpeta.path, "/");
    journalCarpeta.id_propietario = '1';
    strcpy(journalCarpeta.contenido, "-");
    journalCarpeta.tipo = '0';

    long inicio_journaling = inicio_particion + sizeof(superBloque);
    fseek(archivo, inicio_journaling, SEEK_SET);
    fwrite(&journalCarpeta, sizeof(journaling), 1, archivo);

    // Escribir el journal del archivo
    journaling journalArchivo;
    strcpy(journalArchivo.tipo_op, "mkfs");
    strcpy(journalArchivo.fecha_op, fechaActual);
    strcpy(journalArchivo.path, "/users.txt");
    journalArchivo.id_propietario = '1';
    strcpy(journalArchivo.contenido, "1,G,root\n1,U,root,root,123\n");
    journalArchivo.tipo = '1';

    fseek(archivo, inicio_journaling + sizeof(journaling), SEEK_SET);
    fwrite(&journalArchivo, sizeof(journaling), 1, archivo);

    // posicionarme en el lugar donde quiero escribir el bitmap de inodos
    cout << " 2. " <<inicio_particion + sizeof(superBloque)+numeroJournaling*(sizeof(journaling)) << "\n";


    char inodos[n];
    char bloques[3*n];

    // lleno los inodos
    for(int i = 0; i < n; i++ ){
        inodos[i] = '0';
    }

    inodos[0] = '1';
    inodos[1] = '1';
    fseek(archivo, inicio_particion + sizeof(superBloque)+numeroJournaling*(sizeof(journaling)), SEEK_SET);
    fwrite(&inodos, sizeof(inodos), 1, archivo);


    for(int i = 0; i < 3*n; i++){
        bloques[i] = '0';
    }

    bloques[0] = '1';
    bloques[1] = '2';

    cout << " 3. " << inicio_particion + sizeof(superBloque)+numeroJournaling*sizeof(journaling)+bitmapInodos*sizeof(char) << "\n";
    fseek(archivo, inicio_particion + sizeof(superBloque)+numeroJournaling*sizeof(journaling)+bitmapInodos*sizeof(char), SEEK_SET);
    fwrite(&bloques, sizeof(bloques), 1, archivo);

    /*
    // Escribir el bitmap de inodos
    char bitCero = '0';
    for(int i = 0; i < bitmapInodos; i++){
        //cout << sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+i*(sizeof(bitmapInodos)) << endl;
        fseek(archivo, inicio_particion + sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+i*(sizeof(bitmapInodos)), SEEK_SET);
        fwrite(&bitCero, sizeof(char), 1, archivo);
        //cout << ". \n";
    }


    // posicionarme en el lugar donde quiero escribir el bitmap de bloques
    cout << " 3. " << inicio_particion + sizeof(superBloque)+numeroJournaling*sizeof(journaling)+bitmapInodos*sizeof(char) << "\n";
    fseek(archivo, inicio_particion + sizeof(superBloque)+numeroJournaling*(sizeof(journaling)+bitmapInodos*sizeof(char)), SEEK_SET);
    for(int i = 0; i < bitmapBloques; i++){
        //cout << sizeof(superBloque)+numeroJournaling*(sizeof(journaling)+bitmapInodos*sizeof(char))+i*sizeof(bitmapBloques) << endl;
        fseek(archivo, inicio_particion + sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+bitmapInodos*sizeof(char)+i*sizeof(bitmapBloques), SEEK_SET);
        fwrite(&bitCero, sizeof(char), 1, archivo);
    }*/

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);

    // TABLA DE INODOS
    tablaInodo tInodo;
    tInodo.i_uid = 1;
    tInodo.i_gid = 1;
    tInodo.i_size = 0;
    strcpy(tInodo.i_ctime, fechaActual);
    strcpy(tInodo.i_atime, fechaActual);
    strcpy(tInodo.i_mtime, fechaActual);
    for(int i = 0; i < 15; i++){
        tInodo.i_block[i] = 0;
        if(i == 14){
            tInodo.i_block[i] = -1;
        }
    }
    tInodo.i_type = '0';
    tInodo.i_perm = 664; // Guarda los permisos del archivo / carpeta
    tInodo.i_block[0] = 0;
    /*
    // agregando los inodos a
    for(int i = 0; i < numeroInodos; i++){
        arregloInodos[i] = tInodo;
    }
    */

    // posicionarme donde quiero empezar a escribir mis inodos
    cout << " 4. " << inicio_particion+ sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+bitmapInodos*sizeof(char) + bitmapBloques* sizeof(char) << "\n";
    fseek(archivo, sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+bitmapInodos*sizeof(char)+ sizeof(char), SEEK_SET);

    // Escribir inodos
    for(int i = 0; i < numeroInodos; i++){
        //cout << sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char)+i*sizeof(tInodo) << endl;
        fseek(archivo, inicio_particion + sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char)+i*sizeof(tablaInodo), SEEK_SET);
        fwrite(&tInodo, sizeof(tablaInodo), 1, archivo);
    }

    // posicioname donde quiero empezar a escribir los bloques
    cout << " 5. " << inicio_particion + sizeof(superBloque) + numeroJournaling*sizeof(journaling) +bitmapInodos*sizeof(char)+bitmapBloques*sizeof(char) + numeroInodos * sizeof(tablaInodo) << "\n";
    fseek(archivo, sizeof(superBloque)+bitmapInodos*sizeof(char)+bitmapBloques*sizeof(bitmapBloques) , SEEK_SET);

    // ARREGLO DE BLOQUES

    bloque_carpeta bl_carpeta;
    content bl_content;
    bl_content.b_name[0] = '-';
    bl_content.b_inodo = 0;

    for(int i = 0; i < 4; i++){
        bl_carpeta.b_content[i] = bl_content;
    }
    /*
    // Escribir bloques
    for(int i = 0; i < numeroBloques; i++){
        //cout << sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char)+i*sizeof(tInodo)+i*64 << endl;
        fseek(archivo, inicio_particion + sizeof(superBloque)+numeroJournaling*(sizeof(journaling))+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char)+i*sizeof(tInodo)+i*64, SEEK_SET);
        fwrite(&bl_carpeta, sizeof(bloque_carpeta), 1, archivo);

    }*/


    // ESTRUCTURA DE LOS ARCHIVOS QUE VAN EN LA RAIZ
    bloque_carpeta bloque_root;
    string nombre_archivo = "users.txt";
    string un_punto = ".";
    string dos_puntos = "..";
    string dir_raiz = "/";
    // primera posicion
    bloque_root.b_content[0].b_inodo = 0;
    strcpy(bloque_root.b_content[0].b_name, un_punto.c_str());
    // segunda posicion
    bloque_root.b_content[1].b_inodo = 0;
    strcpy(bloque_root.b_content[1].b_name, dos_puntos.c_str());
    // tercera posicion
    bloque_root.b_content[2].b_inodo = 1;
    strcpy(bloque_root.b_content[2].b_name, nombre_archivo.c_str());
    // cuarta posicion
    bloque_root.b_content[3].b_inodo = -1;
    strcpy(bloque_root.b_content[3].b_name, dir_raiz.c_str());

    fseek(archivo, sb_aux.s_inode_start, SEEK_SET);
    fwrite(&tInodo, sizeof(tablaInodo), 1, archivo);
    super_b.s_free_inodes_count--;
    fseek(archivo, sb_aux.s_block_start, SEEK_SET);
    fwrite(&bloque_root, 64,1, archivo);
    sb_aux.s_free_blocks_count--;


    //
    string contenido = "1,G,root\n1,U,root,root,123\n";
    tablaInodo archivo_usuarios;// inodo del archivo de usuarios
    archivo_usuarios.i_gid = 1;
    archivo_usuarios.i_uid = 1;
    archivo_usuarios.i_size = sizeof(contenido);
    strcpy(archivo_usuarios.i_atime, fechaActual);
    strcpy(archivo_usuarios.i_ctime, fechaActual);
    strcpy(archivo_usuarios.i_mtime, fechaActual);

    for(int i = 0; i < 15; i++){
        archivo_usuarios.i_block[i] = -1;
    }

    archivo_usuarios.i_perm = 664;
    archivo_usuarios.i_block[0] = 1;
    archivo_usuarios.i_type = '1';


    bloque_archivo bl_archivo;
    strcpy(bl_archivo.b_content, contenido.c_str());

    fseek(archivo, sb_aux.s_bm_inode_start+sizeof(tablaInodo), SEEK_SET);
    fwrite(&archivo_usuarios,sizeof(tablaInodo),1, archivo);
    sb_aux.s_free_inodes_count--;
    fseek(archivo, sb_aux.s_block_start + 64, SEEK_SET);
    fwrite(&bl_archivo, 64, 1, archivo);
    sb_aux.s_free_blocks_count--;

    /* codigo anterior
    // escribir el archivo users.txt en la raiz
    long pos_users_txt = inicio_particion + numeroJournaling*(sizeof(journaling)) + sizeof(superBloque)+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char)+numeroInodos*sizeof(tablaInodo);
    fseek(archivo, pos_users_txt, SEEK_SET);
    fwrite(&bloque_root, sizeof(bloque_carpeta), 1, archivo);


    bloque_archivo b_archivo;

    strcpy(b_archivo.b_content, contenido.c_str());
    fseek(archivo, pos_users_txt + sizeof(bloque_root), SEEK_SET);
    fwrite(&b_archivo, sizeof(bloque_archivo), 1, archivo);
    */
    cout << " >> Particion formateada en EXT3. \n";
    fclose(archivo);


}

void mkfs::formatearEXT2(string rutaDisco, string nombreParticion, string tipoFormateo){
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

    //int numeroEstructuras = n;
    int numeroInodos = n;
    int numeroBloques = 3*n;
    int bitmapInodos = n;
    int bitmapBloques = 3*n;

    cout << " n: " << n << endl;
    cout << " 3*n: " << 3*n << endl;

    if(tipoFormateo == "full"){
        char nulo = '0';

        for(int i = 0; i < tam_particion; i++){
            fwrite(&nulo, sizeof(nulo), 1, archivo);
            fseek(archivo, inicio_particion + i, SEEK_SET);
        }

    }

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char fechaActual[16];
    strftime(fechaActual,16,"%d/%m/%y %H:%M:%S",tlocal);

    // Defino el superbloque
    superBloque super_b;
    super_b.s_filesystem_type = 2;
    super_b.s_inodes_count = numeroInodos;
    super_b.s_blocks_count = numeroBloques;
    super_b.s_free_blocks_count = 0;
    strcpy(super_b.s_mtime, fechaActual);
    strcpy(super_b.s_umtine, "");
    super_b.s_mnt_count = 0;
    super_b.s_magic = 0xEF53;
    super_b.s_inode_size = sizeof(tablaInodo);
    super_b.s_block_size = sizeof(bloque_archivo);
    super_b.s_first_ino = 2;
    super_b.s_first_block = 2;
    super_b.s_bm_inode_start = inicio_particion +sizeof(superBloque);
    super_b.s_bm_block_start = super_b.s_bm_inode_start + n;
    super_b.s_inode_start = super_b.s_block_start+3*n;
    super_b.s_block_start = super_b.s_bm_inode_start+n*sizeof(tablaInodo);

    fseek(archivo, inicio_particion, SEEK_SET);

    // escribiendo el superbloque al inicio de la particion
    fwrite(&super_b, sizeof(superBloque), 1, archivo);

    // posicionarme en el lugar donde quiero escribir el bitmap de inodos
    cout << " 1. " << inicio_particion + sizeof(superBloque) << "\n";
    fseek(archivo, inicio_particion + sizeof(superBloque), SEEK_SET);

    char inodos[n];
    char bloques[3*n];

    for(int i = 0; i< n; i++ ){
        inodos[i] = '0';
    }

    inodos[0] = '1';
    inodos[1] = '1';
    fseek(archivo,inicio_particion + sizeof(superBloque), SEEK_SET);
    fwrite(&inodos, sizeof(inodos), 1, archivo);

    for(int i = 0; i < 3*n; i++){
        bloques[i] = '0';
    }

    bloques[0] = '1';
    bloques[1] = '2';

    fseek(archivo, inicio_particion + sizeof(superBloque) + numeroBloques*sizeof(inodos), SEEK_SET);
    fwrite(&bloques, sizeof(bloques), 1, archivo);

    /*
    // Escribir el bitmap de inodos
    char bitCero = '0';
    for(int i = 0; i < bitmapInodos; i++){
        fseek(archivo, inicio_particion + sizeof(superBloque)+i*(sizeof(bitmapInodos)), SEEK_SET);
        fwrite(&bitCero, sizeof(char), 1, archivo);
        //cout << ". \n";
    }


    // posicionarme en el lugar donde quiero escribir el bitmap de bloques
    cout << " 2. " <<inicio_particion + sizeof(superBloque)+bitmapInodos*sizeof(char) << "\n";
    fseek(archivo, sizeof(superBloque)+bitmapInodos*sizeof(char), SEEK_SET);
    // Escribir el bitmap de bloques
    for(int i = 0; i < bitmapBloques; i++){
        fseek(archivo, inicio_particion + sizeof(superBloque)+bitmapInodos*sizeof(char)+i*sizeof(bitmapBloques), SEEK_SET);
        fwrite(&bitCero, sizeof(char), 1, archivo);
    }
    */

    bloque_carpeta bl_carpeta;

    for(int i = 0; i < 4; i++){
        bl_carpeta.b_content[i].b_inodo = 0;
        bl_carpeta.b_content[i].b_name[0] = '0';
    }

    // posicionarme en el lugar donde quiero escribir los bloques
    cout << " 3. " <<inicio_particion + sizeof(superBloque)+bitmapInodos*sizeof(char) +bitmapBloques*sizeof(char) << "\n";
    fseek(archivo, inicio_particion + sizeof(superBloque)+bitmapInodos*sizeof(char)+bitmapBloques*sizeof(bitmapBloques) , SEEK_SET);

    for(int i = 0; i < numeroBloques; i++){
        fseek(archivo, inicio_particion + sizeof(superBloque)+bitmapInodos*sizeof(char)+bitmapBloques*sizeof(char)+i*sizeof(bloque_carpeta), SEEK_SET);
        fwrite(&bl_carpeta, sizeof(bloque_carpeta), 1, archivo);
    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);

    // TABLA DE INODOS
    tablaInodo tInodo;
    tInodo.i_uid = 1;
    tInodo.i_gid = 1;
    tInodo.i_size = 0;
    strcpy(tInodo.i_ctime, fechaActual);
    strcpy(tInodo.i_atime, fechaActual);
    strcpy(tInodo.i_mtime, fechaActual);
    for(int i = 0; i < 15; i++){
        tInodo.i_block[i] = 0;

        if(i == 14){
            tInodo.i_block[i] = -1;
        }
    }
    tInodo.i_type = '0';
    tInodo.i_perm = 664; // Guarda los permisos del archivo / carpeta

    // posicionarme donde quiero empezar a escribir mis inodos
    /*cout << " 4. " <<inicio_particion + sizeof(superBloque)+bitmapInodos*sizeof(char) +bitmapBloques*sizeof(char)+numeroBloques*sizeof(char) << "\n";
    fseek(archivo, inicio_particion + sizeof(superBloque)+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char), SEEK_SET);

    // Escribir inodos
    for(int i = 0; i < numeroInodos; i++){
        fseek(archivo, inicio_particion + sizeof(superBloque)+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char)+i*sizeof(tablaInodo), SEEK_SET);
        fwrite(&tInodo, sizeof(tablaInodo), 1, archivo);
    }*/



    bloque_carpeta bloque_root;
    string nombre_archivo = "users.txt";
    string un_punto = ".";
    string dos_puntos = "..";
    string dir_raiz = "/";
    // primera posicion
    bloque_root.b_content[0].b_inodo = 0;
    strcpy(bloque_root.b_content[0].b_name, un_punto.c_str());
    // segunda posicion
    bloque_root.b_content[1].b_inodo = 0;
    strcpy(bloque_root.b_content[1].b_name, dos_puntos.c_str());
    // tercera posicion
    bloque_root.b_content[2].b_inodo = 1;
    strcpy(bloque_root.b_content[2].b_name, nombre_archivo.c_str());
    // cuarta posicion
    bloque_root.b_content[3].b_inodo = -1;
    strcpy(bloque_root.b_content[3].b_name, dir_raiz.c_str());

    fseek(archivo, sb_aux.s_inode_start, SEEK_SET);
    fwrite(&tInodo, sizeof(tablaInodo), 1, archivo);
    super_b.s_free_inodes_count--;
    fseek(archivo, sb_aux.s_block_start, SEEK_SET);
    fwrite(&bloque_root, 64, 1, archivo);
    sb_aux.s_free_blocks_count--;

    string contenido = "1,G,root\n1,U,root,root,123\n";
    tablaInodo archivo_usuarios;
    archivo_usuarios.i_gid = 1;
    archivo_usuarios.i_uid = 1;
    archivo_usuarios.i_size = sizeof(contenido);
    strcpy(archivo_usuarios.i_atime, fechaActual);
    strcpy(archivo_usuarios.i_ctime, fechaActual);
    strcpy(archivo_usuarios.i_mtime, fechaActual);

    for(int i = 0; i < 15; i++){
        archivo_usuarios.i_block[i] = -1;
    }

    archivo_usuarios.i_perm = 664;
    archivo_usuarios.i_block[0] = 1;
    archivo_usuarios.i_type = '1';

    bloque_archivo bl_archivo;
    strcpy(bl_archivo.b_content, contenido.c_str());

    fseek(archivo, sb_aux.s_bm_inode_start+sizeof(tablaInodo), SEEK_SET);
    fwrite(&archivo_usuarios,sizeof(tablaInodo),1, archivo);
    sb_aux.s_free_inodes_count--;
    fseek(archivo, sb_aux.s_block_start + 64, SEEK_SET);
    fwrite(&bl_archivo, 64, 1, archivo);
    sb_aux.s_free_blocks_count--;


    //cout << ftell(archivo) << "\n";
    /*
     * codigo anterior
    // Escribir el archivo users.txt en la raíz
    long pos_users_txt = inicio_particion + sizeof(superBloque)+bitmapInodos*sizeof(char)+ bitmapBloques*sizeof(char)+numeroInodos*sizeof(tablaInodo);
    fseek(archivo, pos_users_txt, SEEK_SET);
    fwrite(&bloque_root, sizeof(bloque_carpeta), 1, archivo);

    string contenido = "1,G,root\n1,U,root,root,123\n";
    bloque_archivo cont_archivo;
    strcpy(cont_archivo.b_content, contenido.c_str());

    fseek(archivo, pos_users_txt + sizeof(bloque_root), SEEK_SET);
    fwrite(&cont_archivo, sizeof(bloque_archivo), 1, archivo);

    */
    cout << " >> Particion formateada en EXT2. \n";

    fclose(archivo);

}
