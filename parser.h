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
    p_r = 274,
    p_f = 275,
    p_fast = 276,
    p_delete = 277,
    p_full = 278,
    p_add = 279,
    pmkdir = 280,
    p_2fs = 281,
    p_3fs = 282,
    p_login = 283,
    p_logout = 284,
    p_usr = 285,
    p_pwd = 286,
    p_grp = 287,
    p_mkgrp = 288,
    p_rmgrp = 289,
    p_mkusr = 290,
    p_rmusr = 291,
    p_mkfile = 292,
    p_rep = 293,
    punto = 294,
    bracketabre = 295,
    bracketcierra = 296,
    corcheteabre = 297,
    corchetecierra = 298,
    puntocoma = 299,
    potencia = 300,
    coma = 301,
    parentesisabre = 302,
    parentesiscierra = 303,
    llaveabre = 304,
    llavecierra = 305,
    mas = 306,
    menos = 307,
    multiplicacion = 308,
    igual = 309,
    dolar = 310,
    dospuntos = 311,
    entero = 312,
    letra = 313,
    numnegativo = 314,
    cadena = 315,
    identificador = 316,
    caracter = 317,
    ruta = 318,
    rutacualquiera = 319,
    suma = 320,
    multi = 321,
    division = 322
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 56 "parser.y"

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
class mkfile *mkfile_cmd;
class rep *rep_cmd;


#line 146 "parser.h"

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
