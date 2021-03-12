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
                porcentaje = (mbr_.mbr_particions[i].part_size/tamanioArchivo)*100;
                //cout << porcentaje << endl;
                reporte <<  " Primaria \\n "
                        << (mbr_.mbr_particions[i].part_size/tamanioArchivo)*100 << " % | ";
            }
            // Estoy graficando una particion extendida
            else if(mbr_.mbr_particions[i].part_type == 'E'){
                reporte << " { extendidas } | { 1 | 2 | 3 } |";
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
