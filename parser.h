/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    psize = 258,
    pmkdisk = 259,
    prmdisk = 260,
    pfdisk = 261,
    pmount = 262,
    punmount = 263,
    pmkfs = 264,
    p_fs = 265,
    p_id = 266,
    p_path = 267,
    p_name = 268,
    p_type = 269,
    ruta_sin_espacio = 270,
    id_particion = 271,
    id_particionl = 272,
    p_u = 273,
    p_f = 274,
    p_fast = 275,
    p_delete = 276,
    p_full = 277,
    p_add = 278,
    pmkdir = 279,
    p_2fs = 280,
    p_3fs = 281,
    p_login = 282,
    p_logout = 283,
    p_usr = 284,
    p_pwd = 285,
    p_grp = 286,
    p_mkgrp = 287,
    p_rmgrp = 288,
    p_mkusr = 289,
    p_rmusr = 290,
    punto = 291,
    bracketabre = 292,
    bracketcierra = 293,
    corcheteabre = 294,
    corchetecierra = 295,
    puntocoma = 296,
    potencia = 297,
    coma = 298,
    parentesisabre = 299,
    parentesiscierra = 300,
    llaveabre = 301,
    llavecierra = 302,
    mas = 303,
    menos = 304,
    multiplicacion = 305,
    igual = 306,
    dolar = 307,
    dospuntos = 308,
    entero = 309,
    letra = 310,
    numnegativo = 311,
    cadena = 312,
    identificador = 313,
    caracter = 314,
    ruta = 315,
    rutacualquiera = 316,
    suma = 317,
    multi = 318,
    division = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "parser.y"

//se especifican los tipo de valores para los no terminales y lo terminales
//char TEXT [256];
//QString TEXT;
char TEXT[256];
class mkdisk *mkdisk_cmd;
class rmdisk *rmdisk_cmd;
class fdisk *fdisk_cmd;
class mount *mount_cmd;
class unmount *unmount_cmd;
class mkfs *mkfs_cmd;
class user *usr_login;
class mkgrp *mkgrp_cmd;
class rmgrp *rmgrp_cmd;
class mkusr *mkusr_cmd;
class rmusr *rmusr_cmd;


#line 141 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
