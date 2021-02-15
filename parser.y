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

using namespace std;
extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON

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
    $2->mostrarDatos($2);//ejecuto el metodo "mostrardatos" del objeto retornado en COMANDOMKDISK
    printf("\ejecutado!!!\n");
}
| prmdisk COMANDORMDISK
{
    printf("\n >> Ejecutando comando rmdisk");
}
| pfdisk COMANDOFDISK
{
    printf("\n >> Ejecutando comando fdisk... \n");
}
| pmount COMANDOMOUNT
{
    printf("\n >> Ejecutando comando mount... \n");
}
| punmount COMANDOUNMOUNT
{
    printf("\n >> Ejecutando comando unmount... \n");
}
;

COMANDOMKDISK:
// –size=5 –u=m –path="/home/juan/Desktop"
menos psize igual entero menos p_u igual identificador menos p_path igual cadena
    {
        int tam=atoi($4);
        string comilla = "\"";
        std::string unidad = $8;
        std::string ruta = $12;
        mkdisk *disco=new mkdisk();
        cout << ruta << endl;
        disco->setTamanio(tam);
        disco->setUnidad(unidad);

        size_t pos = 0;
        std::string ruta_final;
        while ((pos = ruta.find(comilla)) != std::string::npos) {
            ruta_final = ruta.substr(0, pos);
            std::cout << ruta_final << std::endl;
            ruta.erase(0, pos + comilla.length());
        }
        cout << ruta_final << endl;
        disco->setRuta(ruta_final);
        //disco->setRuta("/home/juan/Desktop/Prueba.dk");
        disco->crearDisco(disco);
        $$=disco;
    }
// -path=/ruta/archivo -u=K -size=entero
| menos p_path igual ruta_sin_espacio menos p_u igual identificador menos psize igual entero {int tam=atoi($12); mkdisk *disco=new mkdisk(); disco->setTamanio(tam);  $$=disco;}
// -size=entero -path="ruta entre comillas"
| menos psize igual entero menos p_path igual cadena {int tam=atoi($4); mkdisk *disco=new mkdisk(); disco->setTamanio(tam);  $$=disco;}
// -size=entero -path=/ruta/archivo
| menos psize igual entero menos p_path igual ruta_sin_espacio {int tam=atoi($4); mkdisk *disco=new mkdisk(); disco->setTamanio(tam);  $$=disco;}

;


COMANDORMDISK:
menos p_path igual cadena {}
| menos p_path igual ruta_sin_espacio {}
;

COMANDOFDISK:
// fdisk –Size=300 –path=/home/Disco1.disk –name=Particion1
menos psize igual entero menos p_path igual ruta_sin_espacio menos p_name igual identificador {}
;

COMANDOMOUNT:
menos p_path igual ruta_sin_espacio menos p_name igual identificador {}
| menos p_path igual cadena menos p_name igual identificador {}
;

COMANDOUNMOUNT:
 menos p_id igual identificador {}
;
