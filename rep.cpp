#include "rep.h"
#include "estructuras.h"
#include <fstream>
rep::rep()
{

}

void rep::repmbr(string rutaParticion, string nombreParticion, string rutaDestino){

    FILE *archivo;

    archivo = fopen(rutaParticion.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }

    int inicio_particion = 0;

    mbr mbr_;

    // Escribir el reporte del mbr
    ofstream reporte;

    reporte.open("/home/juan/Desktop/mbr.txt", ios::out);

    if(reporte.fail()){
        cout << " >> No se pudo abrir \n";
    }

    reporte << "digraph G {\n"
            << "node [shape=plaintext] \n"
            << "nodo [ \n"
            << " label =< \n"
            << "<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">"
            << "<tr> <td bgcolor=\"#30A6BB\">Nombre</td> <td bgcolor=\"#30A6BB\"> Valor </td> </tr>";

    // Empiezo a leer el mbr
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    // Datos del mbr
    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> mbr_tamanio </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << mbr_.mbr_tamanio << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> mbr_fecha_creacion </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << mbr_.mbr_fecha_creacion << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> mbr_disk_signature </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << mbr_.mbr_disk_signature << " </td> \n";
    reporte << "</tr>";


    // Particiones del mbr
    for(int i = 0; i < 4; i++){

        if(mbr_.mbr_particions[i].part_status == '1'){
            reporte << "<tr>\n";
            reporte << "<td bgcolor=\"#89D8E7\"> Estado de particion: </td>";
            reporte << "<td bgcolor=\"#C7F6FF\">" << mbr_.mbr_particions[i].part_status << " </td> \n";
            reporte << "</tr>";

            reporte << "<tr>\n";
            reporte << "<td bgcolor=\"#89D8E7\"> Tipo de particion: </td>";
            reporte << "<td bgcolor=\"#C7F6FF\">" << mbr_.mbr_particions[i].part_type << " </td> \n";
            reporte << "</tr>";

            reporte << "<tr>\n";
            reporte << "<td bgcolor=\"#89D8E7\"> Tipo de ajuste: </td>";
            reporte << "<td bgcolor=\"#C7F6FF\">" << mbr_.mbr_particions[i].part_fit<< " </td> \n";
            reporte << "</tr>";

            reporte << "<tr>\n";
            reporte << "<td bgcolor=\"#89D8E7\"> Inicio de particion: </td>";
            reporte << "<td bgcolor=\"#C7F6FF\">" << mbr_.mbr_particions[i].part_start << " </td> \n";
            reporte << "</tr>";

            reporte << "<tr>\n";
            reporte << "<td bgcolor=\"#89D8E7\"> Tamaño de particion: </td>";
            reporte << "<td bgcolor=\"#C7F6FF\">" << mbr_.mbr_particions[i].part_size << " </td> \n";
            reporte << "</tr>";

            reporte << "<tr>\n";
            reporte << "<td bgcolor=\"#89D8E7\"> Nombre de particion: </td>";
            reporte << "<td bgcolor=\"#C7F6FF\">" << mbr_.mbr_particions[i].part_name << " </td> \n";
            reporte << "</tr>";
        }

    }

    reporte << "</table>\n";
    reporte << ">\n";
    reporte << "];\n";
    reporte << "}";

    reporte.close();
    fclose(archivo);
    string comando = "dot -Tpng /home/juan/Desktop/mbr.txt -o " + rutaDestino;
    system(comando.c_str());


}

void rep::sb(string rutaParticion, string nombreParticion, string rutaDestino){

    FILE *archivo;

    archivo = fopen(rutaParticion.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }

    int inicio_particion = 0;

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    for(int i = 0; i < 4; i++){
        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
            //cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            //tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);

    // Escribir el reporte del superbloque
    ofstream reporte;

    reporte.open("/home/juan/Desktop/superbloque.txt", ios::out);

    if(reporte.fail()){
        cout << " >> No se pudo abrir \n";
    }

    reporte << "digraph G {\n"
            << "node [shape=plaintext] \n"
            << "nodo [ \n"
            << " label =< \n"
            << "<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">"
            << "<tr> <td bgcolor=\"#30A6BB\">Nombre</td> <td bgcolor=\"#30A6BB\"> Valor </td> </tr>";

    // Empiezo a leer el superbloque
    fread(&sb_aux, sizeof(superBloque), 1, archivo);

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_inodes_count </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_inodes_count << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_blocks_count </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_blocks_count << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_free_blocks_count </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_free_blocks_count << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_free_inodes_count </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_free_inodes_count << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_mtime </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_mtime << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_umtime </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_umtine << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_mnt_count </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_mnt_count << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_magic </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_magic << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_inode_size </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_inode_size << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_block_size </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_block_size << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_first_ino </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_first_ino << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_first_blo </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_first_block << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_bm_inode_start </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_bm_inode_start << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_bm_block_start </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_bm_block_start << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_inode_start </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_inode_start << " </td> \n";
    reporte << "</tr>";

    reporte << "<tr>\n";
    reporte << "<td bgcolor=\"#89D8E7\"> s_block_start </td>";
    reporte << "<td bgcolor=\"#C7F6FF\">" << sb_aux.s_block_start << " </td> \n";
    reporte << "</tr>";

    reporte << "</table>\n";
    reporte << ">\n";
    reporte << "];\n";
    reporte << "}";


    reporte.close();
    fclose(archivo);
    string comando = "dot -Tpng /home/juan/Desktop/superbloque.txt -o " + rutaDestino;
    system(comando.c_str());


}

void rep::disk(string rutaParticion, string rutaDestino){


    FILE *archivo;

    archivo = fopen(rutaParticion.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }

    //int inicio_particion = 0;

    mbr mbr_;


    /*
        Modelo de codigo
        digraph disk {
          concentrate=True;
          rankdir=TB;
          node [shape=record];
          nodo[label="mbr|libre xd|  { extendidas | {1|2|3|4}  } | Primaria | Primaria"];
        }

    */
    int porcentaje = 0;
    fseek(archivo, 0L, SEEK_END);
    int tamanioArchivo = ftell(archivo);
    // Escribir el reporte del disco
    ofstream reporte;

    reporte.open("/home/juan/Desktop/disk.txt", ios::out);

    if(reporte.fail()){
        cout << " >> No se pudo abrir \n";
    }

    reporte << " digraph disk { \n"
            << " concentrate=True; \n"
            << " rankdir=TB; \n"
            << " node [shape=record];\n"
            << " nodo [label=\" ";

    // Leyendo el mbr
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    reporte << " mbr \\n "
            << sizeof(mbr) << " bytes | ";

    // Leyendo las particiones

    for(int i = 0; i < 4; i++){

        if(mbr_.mbr_particions[i].part_status == '1'){

            // Estoy graficando una primaria
            if(mbr_.mbr_particions[i].part_type == 'P'){
                //porcentaje = (mbr_.mbr_particions[i].part_size/tamanioArchivo)*100;
                //cout << porcentaje << endl;
                reporte <<  " Primaria \\n "
                        << mbr_.mbr_particions[i].part_size << " bytes | ";
            }
            // Estoy graficando una particion extendida
            else if(mbr_.mbr_particions[i].part_type == 'E'){
                reporte << " { extendidas  | { 1 | 2 | 3 } } |";
            }

        }else{
            reporte << " Libre |";
        }

    }

    reporte << " \" ]; \n";
    reporte << " } \n";

    reporte.close();
    fclose(archivo);
    string comando = "dot -Tpng /home/juan/Desktop/disk.txt -o " + rutaDestino;
    system(comando.c_str());


}

void rep::bm_inode(string rutaParticion, string nombreParticion, string rutaDestino){

    FILE *archivo;

    archivo = fopen(rutaParticion.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }

    int inicio_particion = 0;

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    for(int i = 0; i < 4; i++){
        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
            //cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            //tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);

    // Escribir el reporte del bitmap de inodos
    ofstream reporte;

    reporte.open(rutaDestino, ios::out);

    if(reporte.fail()){
        cout << " >> No se pudo abrir \n";
    }

    // Empiezo a leer el superbloque
    fread(&sb_aux, sizeof(superBloque), 1, archivo);

    fseek(archivo, sb_aux.s_bm_inode_start, SEEK_SET);

    // Escribo el bitmap de inodos en el txt
    char bitchar[sb_aux.s_inodes_count];

    for(int i = 0; i < sb_aux.s_inodes_count; i++){

        fseek(archivo, sb_aux.s_bm_inode_start + i*sizeof(char), SEEK_SET);
        reporte << "  " << bitchar[i] << "  |  ";

        //cout << "  " <<bitchar[i] << "  |  ";
        if(i%20 == 0){
            reporte << "  +  \n";
            //cout << "  +  \n";
        }
    }

    reporte.close();
    fclose(archivo);



}

void rep::bm_block(string rutaParticion, string nombreParticion, string rutaDestino){

    FILE *archivo;

    archivo = fopen(rutaParticion.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }

    int inicio_particion = 0;

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    for(int i = 0; i < 4; i++){
        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
            //cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            //tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);

    // Escribir el reporte del bitmap de inodos
    ofstream reporte;

    reporte.open(rutaDestino, ios::out);

    if(reporte.fail()){
        cout << " >> No se pudo abrir \n";
    }

    // Empiezo a leer el superbloque
    fread(&sb_aux, sizeof(superBloque), 1, archivo);

    fseek(archivo, sb_aux.s_bm_block_start, SEEK_SET);

    // Escribo el bitmap de inodos en el txt
    char bitchar[sb_aux.s_blocks_count];

    for(int i = 0; i < sb_aux.s_blocks_count; i++){

        fseek(archivo, sb_aux.s_bm_block_start + i*sizeof(char), SEEK_SET);
        reporte << "  " << bitchar[i] << "  |  ";

        //cout << "  " <<bitchar[i] << "  |  ";
        if(i%20 == 0){
            reporte << "  +  \n";
            //cout << "  +  \n";
        }
    }

    reporte.close();
    fclose(archivo);


}

void rep::rep_journaling(string rutaParticion, string nombreParticion, string rutaDestino){

    FILE *archivo;

    archivo = fopen(rutaParticion.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }

    int inicio_particion = 0;

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    for(int i = 0; i < 4; i++){
        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
            //cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            //tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);
    int num_journaling = sb_aux.s_inodes_count;

    // Escribir el reporte del superbloque
    ofstream reporte;

    reporte.open("/home/juan/Desktop/journaling.txt", ios::out);

    if(reporte.fail()){
        cout << " >> No se pudo abrir \n";
    }

    int inicio_journaling = inicio_particion + sizeof(superBloque);

    //fseek(archivo, inicio_journaling + sizeof(journaling), SEEK_SET);
    //fwrite(&journalArchivo, sizeof(journaling), 1, archivo);
    /*

            digraph G {
            node [shape=plaintext]
            nodo [
             label =<
                <table border="0" cellborder="1" cellspacing="0">
                    <tr>
                        <td bgcolor="#30A6BB">No. </td> <td bgcolor="#30A6BB"> Tipo operacion </td>
                        <td bgcolor="#30A6BB">Fecha operación </td> <td bgcolor="#30A6BB"> path </td>
                        <td bgcolor="#30A6BB">Tamanio </td> <td bgcolor="#30A6BB"> Id propiertario </td>
                        <td bgcolor="#30A6BB">Contenido </td> <td bgcolor="#30A6BB"> Tipo </td>
                    </tr>
                    <tr>
                        <td bgcolor="#C7F6FF">No. </td> <td bgcolor="#C7F6FF"> Tipo </td>
                        <td bgcolor="#C7F6FF">Fecha operación </td> <td bgcolor="#C7F6FF"> path </td>
                        <td bgcolor="#C7F6FF">Tamanio </td> <td bgcolor="#C7F6FF"> Id propiertario </td>
                        <td bgcolor="#C7F6FF">Tamanio </td> <td bgcolor="#C7F6FF"> Id propiertario </td>
                    </tr>

                </table>


            >

            ];

            nodo1 [
             label =<
                <table border="0" cellborder="1" cellspacing="0">
                    <tr>
                        <td bgcolor="#30A6BB">No. </td> <td bgcolor="#30A6BB"> Tipo operacion </td>
                        <td bgcolor="#30A6BB">Fecha operación </td> <td bgcolor="#30A6BB"> path </td>
                        <td bgcolor="#30A6BB">Tamanio </td> <td bgcolor="#30A6BB"> Id propiertario </td>
                        <td bgcolor="#30A6BB">Contenido </td> <td bgcolor="#30A6BB"> Tipo </td>
                    </tr>
                    <tr>
                       <td bgcolor="#C7F6FF">No. </td> <td bgcolor="#C7F6FF"> Tipo </td>
                        <td bgcolor="#C7F6FF">Fecha operación </td> <td bgcolor="#C7F6FF"> path </td>
                        <td bgcolor="#C7F6FF">Tamanio </td> <td bgcolor="#C7F6FF"> Id propiertario </td>
                        <td bgcolor="#C7F6FF">Tamanio </td> <td bgcolor="#C7F6FF"> Id propiertario </td>
                    </tr>

                </table>


            >

            ];

            nodo->nodo1 [style=invis]
            }
    */

    journaling journaling_aux;
    fseek(archivo, inicio_journaling + sizeof(journaling), SEEK_SET);
    fread(&journaling_aux, sizeof(journaling), 1, archivo);

    reporte << "digraph Journaling { \n"
            << "node [shape=plaintext] \n";

    for(int i = 0; i < sb_aux.s_inodes_count; i++){

        fseek(archivo, inicio_journaling + sizeof(journaling)*i, SEEK_SET);

        if(journaling_aux.estado == 1){
            fread(&journaling_aux, sizeof(journaling), 1 , archivo);
            cout << " Esta activo \n";

            reporte << "nodo"<< i <<"[\n";
            reporte << "\t label =< \n"
                    << "\t\t <table border=\"0\" cellborder=\"1\" cellspacing=\"0\"> \n"
                    << "\t\t\t <tr> \n"
                    << "\t\t\t\t <td bgcolor=\"#30A6BB\">No. </td> <td bgcolor=\"#30A6BB\"> Tipo operacion </td> \n"
                    << "\t\t\t\t <td bgcolor=\"#30A6BB\">Fecha operacion </td> <td bgcolor=\"#30A6BB\"> path </td> \n"
                    << "\t\t\t\t <td bgcolor=\"#30A6BB\">Tamanio </td> <td bgcolor=\"#30A6BB\"> Id propiertario </td> \n"
                    << "\t\t\t\t <td bgcolor=\"#30A6BB\">Contenido </td> <td bgcolor=\"#30A6BB\"> Tipo </td> \n"
                    << "\t\t\t </tr> \n";

            reporte << "\t\t\t <tr> \n"
                    << "\t\t\t\t <td bgcolor=\"#C7F6FF\"> " << i + 1 << "</td> <td bgcolor=\"#C7F6FF\"> " << journaling_aux.tipo <<" </td> \n"
                    << "\t\t\t\t <td bgcolor=\"#C7F6FF\"> " << journaling_aux.fecha_op << "</td> <td bgcolor=\"#C7F6FF\">" << journaling_aux.path <<" </td> \n"
                    << "\t\t\t\t <td bgcolor=\"#C7F6FF\"> " << journaling_aux.tamanio << "</td> <td bgcolor=\"#C7F6FF\">" << journaling_aux.id_propietario <<" </td> \n"
                    << "\t\t\t\t <td bgcolor=\"#C7F6FF\"> " << journaling_aux.contenido << "</td> <td bgcolor=\"#C7F6FF\">" << journaling_aux.tipo_op <<" </td> \n"
                    << "\t\t\t </tr> \n"
                    << "\t\t </table> \n"
                    << "\t > \n"
                    << "]; \n";

            // enlazando invisiblemente las tablas
            reporte << "nodo" << i << "->nodo" << i+1 << "[style=invis]\n";

        }
    }

    reporte << "}\n";

    reporte.close();
    fclose(archivo);
    string comando = "dot -Tpng /home/juan/Desktop/journaling.txt -o " + rutaDestino;
    system(comando.c_str());
    //fwrite(&journalArchivo, sizeof(journaling), 1, archivo);


}

void rep::rep_inodos(string rutaParticion, string nombreParticion, string rutaDestino){

    FILE *archivo;

    archivo = fopen(rutaParticion.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }

    int inicio_particion = 0;

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    for(int i = 0; i < 4; i++){
        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
            //cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            //tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);
    int inicio_inodos = sb_aux.s_inode_start;

    // Escribir el reporte del superbloque
    ofstream reporte;

    reporte.open("/home/juan/Desktop/inode.txt", ios::out);

    if(reporte.fail()){
        cout << " >> No se pudo abrir \n";
    }


    tablaInodo inodo_aux;
    int inodos_ocupados = sb_aux.s_inodes_count - sb_aux.s_free_inodes_count;

    reporte << "digraph Inode {\n"
            << "node [shape=plaintext] \n";




    for(int i = 0; i < inodos_ocupados; i++){
        fseek(archivo, inicio_inodos, SEEK_SET);
        fread(&inodo_aux, sizeof(tablaInodo), 1, archivo);
        reporte << "nodo"<< i <<" [\n"
                << "label =< \n";

        reporte << "<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">"
                << "<tr> <td bgcolor=\"#30A6BB\">Nombre</td> <td bgcolor=\"#30A6BB\"> Valor </td> </tr>";

        reporte << "<tr>\n";
        reporte << "<td bgcolor=\"#89D8E7\"> i_uid </td>";
        reporte << "<td bgcolor=\"#C7F6FF\">" << inodo_aux.i_uid << " </td> \n";
        reporte << "</tr>";

        reporte << "<tr>\n";
        reporte << "<td bgcolor=\"#89D8E7\"> i_gid </td>";
        reporte << "<td bgcolor=\"#C7F6FF\">" << inodo_aux.i_gid << " </td> \n";
        reporte << "</tr>";

        reporte << "<tr>\n";
        reporte << "<td bgcolor=\"#89D8E7\"> i_atime </td>";
        reporte << "<td bgcolor=\"#C7F6FF\">" << inodo_aux.i_atime << " </td> \n";
        reporte << "</tr>";


        for(int j = 0; j < 15; j++){

            if(inodo_aux.i_block[j] != -1){
                reporte << "<tr>\n";
                reporte << "<td bgcolor=\"#89D8E7\"> i_block_" << j << " </td>";
                reporte << "<td bgcolor=\"#C7F6FF\">" << inodo_aux.i_block[j] << " </td> \n";
                reporte << "</tr>";
            }
        }

        reporte << "<tr>\n";
        reporte << "<td bgcolor=\"#89D8E7\"> i_perm </td>";
        reporte << "<td bgcolor=\"#C7F6FF\">" << inodo_aux.i_perm << " </td> \n";
        reporte << "</tr>";

        reporte << "<tr>\n";
        reporte << "<td bgcolor=\"#89D8E7\"> i_type </td>";
        reporte << "<td bgcolor=\"#C7F6FF\">" << inodo_aux.i_type << " </td> \n";
        reporte << "</tr>";

        reporte << "</table>\n";
        reporte << ">\n";
        reporte << "];\n";

    }

    reporte << "}";

    reporte.close();
    fclose(archivo);
    string comando = "dot -Tpng /home/juan/Desktop/inode.txt -o " + rutaDestino;
    system(comando.c_str());

}

void rep::rep_bloques(string rutaParticion, string nombreParticion, string rutaDestino){
    FILE *archivo;

    archivo = fopen(rutaParticion.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> El disco no existe. \n";
    }


    int inicio_particion = 0;

    mbr mbr_;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_, sizeof(mbr), 1, archivo);

    for(int i = 0; i < 4; i++){
        if(strcmp(mbr_.mbr_particions[i].part_name, nombreParticion.c_str()) == 0){
            //cout << " >> Size: " << mbr_.mbr_particions[i].part_size << " \n";
            inicio_particion = mbr_.mbr_particions[i].part_start;
            //tam_particion = mbr_.mbr_particions[i].part_size;
            break;
        }

    }

    // superbloque auxiliar
    superBloque sb_aux;
    fseek(archivo, inicio_particion, SEEK_SET);
    fread(&sb_aux, sizeof(superBloque), 1, archivo);
    int inicio_bloques = sb_aux.s_block_start;
    int bloques_usados = sb_aux.s_blocks_count - sb_aux.s_free_blocks_count;

    ofstream reporte;

    reporte.open("/home/juan/Desktop/blocks.txt", ios::out);

    if(reporte.fail()){
        cout << " >> No se pudo abrir \n";
    }

    reporte << "digraph Journaling { \n"
            << "node [shape=plaintext] \n";

    bloque_carpeta bl_carpeta_aux;

    for(int i = 0; i < bloques_usados; i++){

        fseek(archivo, inicio_bloques + i*64, SEEK_SET);
        fread(&bl_carpeta_aux, 64, 1, archivo);
        reporte << "nodo"<< i <<"[\n";

        reporte << "\t label =< \n"
                << "\t\t <table border=\"0\" cellborder=\"1\" cellspacing=\"0\"> \n"
                << "\t\t\t <tr> \n"
                << "\t\t\t\t <td bgcolor=\"#30A6BB\">No. Bloque </td> <td bgcolor=\"#30A6BB\"> "<< i <<"  </td> \n"
                << "\t\t\t </tr> \n";

        reporte << "\t\t\t <tr> \n"
                << "\t\t\t\t <td bgcolor=\"#C7F6FF\"> b_name </td> <td bgcolor=\"#C7F6FF\"> b_inodo </td> \n"
                << "\t\t\t </tr> \n";

        for(int j = 0; j < 4; j++){
            reporte << "\t\t\t <tr> \n"
                    << "\t\t\t\t <td bgcolor=\"#C7F6FF\"> "<< bl_carpeta_aux.b_content[j].b_inodo << " </td> <td bgcolor=\"#C7F6FF\"> "<< bl_carpeta_aux.b_content[j].b_name <<" </td> \n"
                    << "\t\t\t </tr> \n";
        }

        reporte << "\t\t </table> \n"
                << "\t > \n"
                << "]; \n";

    }

    bloque_archivo bl_archivo_aux;

    for(int i = 0; i < bloques_usados; i++){

        fseek(archivo, inicio_bloques + i*64, SEEK_SET);
        fread(&bl_archivo_aux, 64, 1, archivo);
        reporte << "nodoaux"<< i <<"[\n";

        reporte << "\t label =< \n"
                << "\t\t <table border=\"0\" cellborder=\"1\" cellspacing=\"0\"> \n"
                << "\t\t\t <tr> \n"
                << "\t\t\t\t <td bgcolor=\"#30A6BB\">No. Bloque </td> <td bgcolor=\"#30A6BB\"> "<< i <<"  </td> \n"
                << "\t\t\t </tr> \n";

        reporte << "\t\t\t <tr> \n"
                << "\t\t\t\t <td bgcolor=\"#C7F6FF\"> content </td> <td bgcolor=\"#C7F6FF\"> " << bl_archivo_aux.b_content <<" </td> \n"
                << "\t\t\t </tr> \n";


        reporte << "\t\t </table> \n"
                << "\t > \n"
                << "]; \n";

    }



    reporte << "}\n";

    reporte.close();
    fclose(archivo);
    string comando = "dot -Tpng /home/juan/Desktop/blocks.txt -o " + rutaDestino;
    system(comando.c_str());


}
