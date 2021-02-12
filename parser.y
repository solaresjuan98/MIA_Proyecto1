%{
#include "scanner.h"//se importa el header del analisis sintactico
#include <QString>
#include <string>
#include "qdebug.h"
#include <iostream>
#include "obmkdisk.h"
//
#include "mkdisk.h"
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

}
//TERMINALES DE TIPO TEXT, SON STRINGS

%token<TEXT> psize;
%token<TEXT> pmkdisk;
%token<TEXT> p_path;
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




%type<mkdisk_cmd> COMANDOMKDISK; // lista de instrucciones

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
printf("\nHello!!!\n");
}


;

COMANDOMKDISK:
//menos psize igual entero {int tam=atoi($4); obmkdisk *disco=new obmkdisk(); disco->size=tam;  $$=disco;}
menos psize igual entero menos p_u igual identificador menos p_path igual cadena {int tam=atoi($4); mkdisk *disco=new mkdisk(); disco->tamanio=tam;  $$=disco;}

;
