%option case-insensitive
%option yylineno

%{
#include <iostream>
#include <QString>
#include "parser.h"

#include <string>
#include <QList>

    int yylex();
    void yyerror(const char *s);
    int linea = 0;
    int columna = 1;
    int anterior = 0;


%}

%option noyywrap
%option nounput

entero [0-9]+
letra [a-zA-ZÑñáéíóúÁÉÍÓÚ]+


identificador {letra}({letra}|{entero}|"_")*
caracter "\'"("\\")?({letra}|{entero})"\'"
cadena [\"][^\"\n]*[\"\n]
ruta_sin_espacio ("/"({letra}|{entero}|"_"|"-"|".")*)+
id_particion {entero}{entero}{entero}{letra}
id_particionl {entero}{entero}{entero}{entero}{letra}
%x COM


%%
"MKDISK" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return pmkdisk;}
"RMDISK" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return prmdisk;}
"FDISK" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return pfdisk;}
"MOUNT" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return pmount;}
"UNMOUNT" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return punmount;}
"MKFS" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return pmkfs;}
"SIZE" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return psize;}
"PATH" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_path;}
"U" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_u;}
"F" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_f;}
"NAME" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_name;}
"TYPE" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_type;}
"DELETE" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_delete;}
"FAST" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_fast;}
"FULL" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_full;}
"ADD" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_add;}
"ID" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_id;}
"FS" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_fs;}
"2FS" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_2fs;}
"3FS" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_3fs;}
"LOGIN" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_login;}
"USR" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_usr;}
"PWD" {columna=columna+ anterior;  anterior = strlen(yytext); strcpy(yylval.TEXT, yytext);return p_pwd;}

{entero} {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return entero;}
{cadena} {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return cadena;}
{identificador} {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return identificador;}
{ruta_sin_espacio} {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return ruta_sin_espacio;}
{caracter} {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return caracter;}
{id_particionl} {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return id_particionl;}
{id_particion} {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return id_particion;}


"." {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return punto;}
"<" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return bracketabre;}
">" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return bracketcierra;}
"[" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return corcheteabre;}
"]" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return corchetecierra;}
";" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return puntocoma;}
"^" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return potencia;}
"," {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return coma;}
"(" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return parentesisabre;}
")" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return parentesiscierra;}
"{" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return llaveabre;}
"}" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return llavecierra;}
"+" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return mas;}
"-" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return menos;}
"*" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return multiplicacion;}
"=" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return igual;}
"$" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return dolar;}
":" {columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);return dospuntos;}

"\n" {linea++; columna=0; anterior=0;}
[[:blank:]] { columna++; }



.   {
std::cout<<"Error Lexico: "<<linea<<"\n";
}
