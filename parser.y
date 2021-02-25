%{
#include "scanner.h"//se importa el header del analisis sintactico
#include <QString>
#include <string>
#include "qdebug.h"
#include <iostream>
#include "obmkdisk.h"
// comandos usados
#include "mkdisk.h"
#include "rmdisk.h"
#include "fdisk.h"
#include "mount.h"
#include "unmount.h"
// estructuras
#include "estructuras.h"
disco arregloDiscos[26];
//int numeros[5];

using namespace std;
extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
bool mountInicializado = false;

int yyerror(const char* mens)
{
std::cout << mens <<" "<<yytext<< std::endl;
return 0;
}
%}
//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%defines "parser.h"
%output "parser.cpp"
%define parse.error verbose
%locations
%union{
//se especifican los tipo de valores para los no terminales y lo terminales
//char TEXT [256];
//QString TEXT;
char TEXT[256];
//class obmkdisk *mdisk;
class mkdisk *mkdisk_cmd;
class rmdisk *rmdisk_cmd;
class fdisk *fdisk_cmd;
class mount *mount_cmd;
class unmount *unmount_cmd;
//class mount *cmd_mount = new mount();
}
//TERMINALES DE TIPO TEXT, SON STRINGS

%token<TEXT> psize;
%token<TEXT> pmkdisk;
%token<TEXT> prmdisk;
%token<TEXT> pfdisk;
%token<TEXT> pmount;
%token<TEXT> punmount;

%token<TEXT> p_id;
%token<TEXT> p_path;
%token<TEXT> p_name;
%token<TEXT> p_type;
%token<TEXT> ruta_sin_espacio;
%token<TEXT> p_u;
%token<TEXT> p_f;
%token<TEXT> p_fast;
%token<TEXT> p_delete;
%token<TEXT> p_full;
%token<TEXT> p_add;
%token<TEXT> pmkdir;


%token<TEXT> punto;
%token<TEXT> bracketabre;
%token<TEXT> bracketcierra;
%token<TEXT> corcheteabre;
%token<TEXT> corchetecierra;
%token<TEXT> puntocoma;
%token<TEXT> potencia;
%token<TEXT> coma;
%token<TEXT> parentesisabre;
%token<TEXT> parentesiscierra;

%token<TEXT> llaveabre;
%token<TEXT> llavecierra;
%token<TEXT> mas;
%token<TEXT> menos;
%token<TEXT> multiplicacion;
%token<TEXT> igual;
%token<TEXT> dolar;
%token<TEXT> dospuntos;
//%token<TEXT> barra;

%token<TEXT> entero;
%token<TEXT> numnegativo;
%token<TEXT> cadena;
%token<TEXT> identificador;
%token<TEXT> caracter;
%token<TEXT> ruta;
%token<TEXT> rutacualquiera;
//%token<TEXT> pdisk;



// Comandos usados
%type<mkdisk_cmd> COMANDOMKDISK;
%type<rmdisk_cmd> COMANDORMDISK;
%type<fdisk_cmd> COMANDOFDISK;
%type<mount_cmd> COMANDOMOUNT;
%type<unmount_cmd> COMANDOUNMOUNT;


%left suma menos
%left multi division
%left potencia
%start INICIO
%%

INICIO : LEXPA { }
;

LEXPA:  pmkdisk COMANDOMKDISK
{
    //$2->mostrarDatos($2);//ejecuto el metodo "mostrardatos" del objeto retornado en COMANDOMKDISK
    //printf("\n ejecutado!!!\n");
}
| prmdisk COMANDORMDISK
{
    //printf("\n >> Ejecutando comando rmdisk");
}
| pfdisk COMANDOFDISK
{
    //printf("\n >> Ejecutando comando fdisk... \n");
}
| pmount COMANDOMOUNT
{
    //printf("\n >> Ejecutando comando mount... \n");
}
| punmount COMANDOUNMOUNT
{


    //printf("\n >> Ejecutando comando unmount... \n");
}
;

COMANDOMKDISK:
// –size=5 –u=m –path="/home/juan/Desktop"
menos psize igual entero menos p_u igual identificador menos p_path igual cadena
    {
        int tam=atoi($4);
        string comilla = "\"";
        string unidad = $8;
        string ruta = $12;
        mkdisk *disco=new mkdisk();
        //cout << ruta << endl;
        disco->setTamanio(tam);
        disco->setUnidad(unidad);

        size_t pos = 0;
        string ruta_final;
        while ((pos = ruta.find(comilla)) != std::string::npos) {
            ruta_final = ruta.substr(0, pos);
            //std::cout << ruta_final << std::endl;
            ruta.erase(0, pos + comilla.length());
        }
        disco->setRuta(ruta_final);
        disco->crearDisco(disco);
        $$=disco;
    }
// -path=/ruta/archivo -u=K -size=entero
| menos p_path igual ruta_sin_espacio menos p_u igual identificador menos psize igual entero
    {
        int tam=atoi($12);
        mkdisk *disco=new mkdisk();
        disco->setTamanio(tam);
        string ruta = $4;
        string unidad = $8;

        disco->setTamanio(tam);
        disco->setUnidad(unidad);
        disco->crearDisco(disco);

        $$=disco;
    }
// -size=entero -path="ruta entre comillas"
| menos psize igual entero menos p_path igual cadena
    {
        int tam=atoi($4);
        string comilla = "\"";
        mkdisk *disco=new mkdisk();
        string ruta = $8;
        disco->setTamanio(tam);
        disco->setUnidad("k");
        size_t pos = 0;
        string ruta_final;
        while ((pos = ruta.find(comilla)) != std::string::npos) {
            ruta_final = ruta.substr(0, pos);
            //std::cout << ruta_final << std::endl;
            ruta.erase(0, pos + comilla.length());
        }
        disco->setRuta(ruta_final);
        disco->crearDisco(disco);
        $$=disco;
    }
// -size=entero -path=/ruta/archivo
| menos psize igual entero menos p_path igual ruta_sin_espacio
    {
        int tam=atoi($4);
        string ruta = $8;
        mkdisk *disco=new mkdisk();
        disco->setTamanio(tam);
        disco->setRuta(ruta);
        disco->setUnidad("k");
        disco->crearDisco(disco);
        $$=disco;

    }

;


COMANDORMDISK:
menos p_path igual cadena
{
    std::string rutaBorrar = $4;
    rmdisk *discoBorrar = new rmdisk();
    discoBorrar->borrarDisco(rutaBorrar);
    $$=discoBorrar;

}
| menos p_path igual ruta_sin_espacio
{
    std::string rutaBorrar = $4;
    rmdisk *discoBorrar = new rmdisk();
    discoBorrar->borrarDisco(rutaBorrar);
    $$=discoBorrar;
}
;

COMANDOFDISK:
// –Size=300 –path=/home/Disco1.disk –name=Particion1
menos psize igual entero menos p_path igual ruta_sin_espacio menos p_name igual identificador
    {
        int tamanio = atoi($4);
        string ruta = $8;
        string nombreDisco = $12;

        fdisk *disco = new fdisk();
        disco->setTamanio(tamanio);
        disco->setNombre(nombreDisco);
        disco->setRuta(ruta);
        disco->setUnidad("k");
        disco->setTipo("P");
        disco->setAjuste("W");
        disco->crearParticion(disco);
        disco->mostrarDatosDisco(ruta);
        $$ = disco;



    }
// -type=E –path=/home/Disco1.disk -U=k –name=Particion1 -size=300
| menos p_type igual identificador menos p_path igual ruta_sin_espacio menos p_u igual identificador menos p_name igual identificador menos psize igual entero
    {
        string ruta= $8;
        string tipoAjuste = $4;
        string unidad = $12;
        string nombreParticion = $16;
        int tamanio = atoi($20);

        fdisk *disco = new fdisk();
        disco->setAjuste(tipoAjuste);
        disco->setRuta(ruta);
        disco->setUnidad(unidad);
        disco->setNombre(nombreParticion);
        disco->setTamanio(tamanio);
        disco->crearParticion(disco);
        disco->mostrarDatosDisco(ruta);
        $$ = disco;
    }
// -size=1 -type=L -u=M -f=BF -path="/mis discos/Disco3.disk" -name="Particion3"
| menos psize igual entero menos p_type igual identificador menos p_u igual identificador menos p_f igual identificador
  menos p_path igual cadena menos p_name igual cadena
    {

    }
// -delete=fast -name="Particion1" -path=/home/Disco1.dk
| menos p_delete igual p_fast menos p_name igual cadena menos p_path igual ruta_sin_espacio
    {
        /*
        string nombreParticion = $4;
        string tipoBorrado = $8;
        string ruta = $12;
        fdisk *particion = new fdisk();
        particion->setRuta(ruta);
        particion->setBorrar(tipoBorrado);
        particion->borrarParticion(ruta, particion, nombreParticion);
        particion->mostrarDatosDisco(ruta);
        $$ = particion;
        */
}
// -name=Particion1 -delete=full -path=/home/Disco1.disk
| menos p_name igual identificador menos p_delete igual p_full menos p_path igual ruta_sin_espacio
    {
        string nombreParticion = $4;
        string tipoBorrado = $8;
        string ruta = $12;
        fdisk *particion = new fdisk();
        particion->setRuta(ruta);
        particion->setBorrar(tipoBorrado);
        particion->borrarParticion(ruta, particion, nombreParticion);
        particion->mostrarDatosDisco(ruta);
        $$ = particion;

    }
// -add=1 -u=M -path="/home/mis discos/Disco4.dk" -name="Particion 4"
| menos p_add igual entero menos p_u igual identificador menos p_path igual cadena menos p_name igual cadena
    {

    }
// -add=1 -u=M -path="/home/juan/Desktop/Disco.dk" -name="Particion 4"
| menos p_add entero menos p_u igual identificador menos p_path igual cadena menos p_name igual cadena
    {

    }
;

COMANDOMOUNT:
menos p_path igual ruta_sin_espacio menos p_name igual identificador
    {
        string ruta = $4;
        int i = 0;
        string nombreParticion = $8;
        mount *comando_mount = new mount();

        disco discoVacio;
        discoVacio.letra = ' ';
        discoVacio.ruta[0] = '\0';
        discoVacio.estado = 0;

        particion_disco part_vacia;
        part_vacia.numero = 0;
        part_vacia.nombre[0] = '\0';
        part_vacia.estado = 0;
        part_vacia.id[0] = '\0';

        // Inicializando el arreglo de particiones por primera vez
        if (!mountInicializado) {


            for (int i= 0; i < 26; i++) {
                arregloDiscos[i] = discoVacio;

                for(int j = 0; j < 99; j++){
                    arregloDiscos[i].particiones[j] = part_vacia;
                }
            }

            mountInicializado = true;
        }
        else {
            /* "i" representa a cada uno de los discos montados (representados por letras)
             * validar si la ruta existe, etc etc
             *
             * */
            for (int i = 0; i < 26; i++) { // Recorriendo todas las posiciones del disco

                // encuentro el primer disco inactivo (o libre)
                if (arregloDiscos[i].estado == 0) {
                    disco discoaMontar = comando_mount->montarDisco(ruta, i);
                    for (int j = 0; j < 99; j++) {

                        //cout << j << '\n';
                        if (arregloDiscos[i].particiones[j].estado == 0) {
                            cout << " Insertando en disco " << i << "\n";
                            cout << " Insertando en particion " << j  << "\n";
                            //particion particionaMontar;
                            string str(1, discoaMontar.letra);
                            discoaMontar.particiones[j] = comando_mount->montarParticion(nombreParticion, j, str);
                            arregloDiscos[i] = discoaMontar;
                            break;
                        }


                    }

                    break;

                // Si el disco está activo y la ruta es igual
                }else if((arregloDiscos[i].estado == 1) && strcmp(arregloDiscos[i].ruta, ruta.c_str()) == 0){
                    disco discoaMontar = comando_mount->montarDisco(ruta, i);
                    for (int j = 0; j < 99; j++) {
                        //cout << " - i " <<i << '\n';
                        //cout << " - j " <<j << '\n';
                        // encuentro una particion libre (estado 0)
                        if (arregloDiscos[i].particiones[j].estado == 0) {
                            cout << " Insertando en disco " << i << "\n";
                            cout << " Insertando en particion " << j  << "\n";
                            string str(1, discoaMontar.letra);
                            discoaMontar.particiones[j] = comando_mount->montarParticion(nombreParticion, j, str);
                            arregloDiscos[i] = discoaMontar;
                            break;
                        }


                    }

                    break;
                }

            }
        }



        for(int i = 0; i < 26; i++){

            if(arregloDiscos[i].estado != 0){
                cout << " Letra: " <<arregloDiscos[i].letra << "\n";
                cout << " Ruta del disco: " <<arregloDiscos[i].ruta << "\n";
                cout << " \t Particiones montadas : \n";

                for(int j = 0; j < 99; j++){

                    if(arregloDiscos[i].particiones[j].estado != 0){

                        cout << "\t " << j + 1 <<". Nombre particion: " << arregloDiscos[i].particiones[j].nombre << "\n";
                        cout << "\t  ID particion: " << arregloDiscos[i].particiones[j].id << "\n";
                        fflush(stdin);
                    }
                }
            }
        }

        //$$ = comando_mount;
    }
| menos p_path igual cadena menos p_name igual identificador {}
;

COMANDOUNMOUNT:
 menos p_id igual identificador {}
;
