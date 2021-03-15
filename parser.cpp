/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "scanner.h"
#include <QString>
#include <string>
#include "qdebug.h"
#include <iostream>
// comandos usados
#include "mkdisk.h"
#include "rmdisk.h"
#include "fdisk.h"
#include "mount.h"
#include "unmount.h"
#include "mkfs.h"
// administracion de usuario
#include "user.h"
#include "mkgrp.h"
#include "rmgrp.h"
#include "mkusr.h"
#include "rmusr.h"
// administracion de archivos
#include "mkfile.h"
#include "mkdir.h"
// reportes
#include "rep.h"
// estructuras
#include "estructuras.h"
// simulacion de perdida del sistema
#include "loss.h"
// otras
#include "file.h"
disco arregloDiscos[26];

//*** para login/logout
string usrname;
string pwd;

// ** Datos de la particion actual montado **
string nombreParticion;
string rutaParticionActual;
bool yaInicioSesion = false;
using namespace std;
extern int yylineno;
extern int columna;
extern char *yytext;
bool mountInicializado = false;

int yyerror(const char* mens)
{
std::cout << mens <<" "<<yytext<< std::endl;
return 0;
}

#line 123 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    p_mkdir = 293,
    p_rep = 294,
    p_pause = 295,
    p_loss = 296,
    punto = 297,
    bracketabre = 298,
    bracketcierra = 299,
    corcheteabre = 300,
    corchetecierra = 301,
    puntocoma = 302,
    potencia = 303,
    coma = 304,
    parentesisabre = 305,
    parentesiscierra = 306,
    llaveabre = 307,
    llavecierra = 308,
    mas = 309,
    menos = 310,
    multiplicacion = 311,
    igual = 312,
    dolar = 313,
    dospuntos = 314,
    entero = 315,
    letra = 316,
    numnegativo = 317,
    cadena = 318,
    identificador = 319,
    caracter = 320,
    ruta = 321,
    rutacualquiera = 322,
    comentario = 323,
    suma = 324,
    multi = 325,
    division = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "parser.y"

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
class mkdir *mkdir_cmd;
class loss *loss_cmd;



#line 271 "parser.cpp"

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



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  319

#define YYUNDEFTOK  2
#define YYMAXUTOK   326


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   182,   182,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   209,   213,   235,   250,   270,   283,   342,   397,
     405,   416,   437,   457,   500,   525,   540,   554,   590,   682,
     683,   738,   771,   813,   839,   866,   893,   927,   979,  1000,
    1012,  1018,  1026,  1048,  1057,  1081,  1119,  1159,  1228,  1308,
    1317
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "psize", "pmkdisk", "prmdisk", "pfdisk",
  "pmount", "punmount", "pmkfs", "p_fs", "p_id", "p_path", "p_name",
  "p_type", "ruta_sin_espacio", "id_particion", "id_particionl", "p_u",
  "p_r", "p_f", "p_fast", "p_delete", "p_full", "p_add", "pmkdir", "p_2fs",
  "p_3fs", "p_login", "p_logout", "p_usr", "p_pwd", "p_grp", "p_mkgrp",
  "p_rmgrp", "p_mkusr", "p_rmusr", "p_mkfile", "p_mkdir", "p_rep",
  "p_pause", "p_loss", "punto", "bracketabre", "bracketcierra",
  "corcheteabre", "corchetecierra", "puntocoma", "potencia", "coma",
  "parentesisabre", "parentesiscierra", "llaveabre", "llavecierra", "mas",
  "menos", "multiplicacion", "igual", "dolar", "dospuntos", "entero",
  "letra", "numnegativo", "cadena", "identificador", "caracter", "ruta",
  "rutacualquiera", "comentario", "suma", "multi", "division", "$accept",
  "INICIO", "LEXPA", "COMENTARIO", "COMANDOMKDISK", "COMANDORMDISK",
  "COMANDOFDISK", "COMANDOMOUNT", "COMANDOUNMOUNT", "COMANDOMKFS",
  "COMANDOLOGIN", "COMANDOLOGOUT", "COMANDOMKGRP", "COMANDORMGRP",
  "COMANDOMKUSR", "COMANDORMUSR", "COMANDOMKFILE", "COMANDOMKDIR",
  "COMANDOREP", "COMANDOPAUSE", "COMANDOLOSS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,   -28,    -2,     4,     7,    10,    11,    12,   -47,    13,
      14,    15,    16,    17,    19,    20,   -47,    21,   -20,    46,
     -47,   -47,     8,   -47,    38,   -47,    25,   -47,    39,   -47,
      41,   -47,    29,   -47,    31,   -47,   -47,    50,   -47,    60,
     -47,    47,   -47,    48,   -47,    76,   -47,    22,   -47,    69,
     -47,   -47,    70,   -47,   -47,   -47,   -47,    26,    27,    28,
      30,    32,    33,    34,    35,    36,    37,    40,    42,    43,
      44,    45,    49,    51,    52,    53,    56,    55,    57,    58,
      67,    24,    -9,    59,    61,    62,    74,    63,    -8,     6,
      80,    64,   -46,   -22,    65,    66,    68,    71,    86,    87,
      88,    72,    78,    79,   -47,   -47,    81,    82,    83,    84,
      85,    89,    90,   -47,   -47,   -47,    91,    92,    93,   -47,
     -47,   -47,    94,   -47,    95,    96,    97,   -47,     1,    98,
     102,     2,    99,     3,   100,   104,   107,   111,   106,   110,
     112,   120,   103,   127,   123,   101,   105,   108,   109,   113,
     114,   115,   116,   117,   118,   119,   121,   122,   124,   125,
     126,   128,   129,   -47,   130,    -7,   131,   132,   133,   139,
     134,   136,   140,   135,   137,   138,   141,   142,   144,   145,
     143,   146,    -6,    -5,   -47,   -47,   149,   152,   154,   156,
     157,   158,   159,   160,   161,   162,   -47,   -47,   163,   164,
     165,   166,   167,   168,   169,   170,   151,   153,   155,   148,
     150,   172,   171,   175,   178,   179,   147,   181,   183,    75,
     182,   -47,   184,   213,   173,   174,   176,   177,   180,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   -47,   194,
     195,    -3,   196,   212,   197,   198,   214,   199,   200,   217,
     202,    18,   219,   220,   203,   204,   205,   211,   -47,   -47,
     215,   -47,   216,   -47,   218,   221,   -47,   222,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   208,   233,   234,   225,   236,
     227,   201,   223,   224,   226,   228,   229,   210,   230,   231,
     232,   237,   209,   -47,   -47,   235,   238,   243,   -47,   245,
     252,   247,   242,   244,   246,   239,   240,   260,   249,   -47,
     250,   265,   259,   251,   253,   248,   254,   -47,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    40,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,    59,     0,    22,     0,
       2,    21,     0,     3,     0,     4,     0,     5,     0,     6,
       0,     7,     0,     8,     0,     9,    10,     0,    11,     0,
      12,     0,    13,     0,    14,     0,    15,     0,    19,     0,
      16,    17,     0,    20,    22,    18,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    29,     0,     0,     0,     0,
       0,     0,     0,    41,    42,    45,     0,     0,     0,    50,
      49,    51,     0,    53,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
       0,    31,     0,    36,     0,     0,    35,     0,    43,    44,
      47,    46,    52,    57,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    33,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   -47,   264,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    19,    20,    21,    23,    25,    27,    29,    31,    33,
      35,    36,    38,    40,    42,    44,    46,    48,    50,    51,
      53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       1,     2,     3,     4,     5,     6,   104,   111,   184,   202,
     204,    57,   257,   145,   149,   152,   150,   117,   118,   146,
      58,   153,   113,   114,     7,     8,    59,    22,    61,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    62,    63,
      68,   119,   120,    69,   268,   269,    56,    64,    54,    65,
      60,    66,    67,    24,   105,   112,   185,   203,   205,    26,
     258,    70,    28,    71,    18,    30,    32,    34,    37,    39,
      41,    43,    45,    72,    47,    49,    52,    73,    74,    75,
      77,    78,   102,    79,    80,    81,    76,    82,   103,    83,
      84,    85,    86,    87,    88,   109,   115,    89,   125,    90,
      91,    92,    93,   126,   127,   148,    94,   237,    95,    96,
      97,    98,    99,   154,   100,   162,   147,   158,   101,   106,
     156,   151,   155,   110,   157,   107,   108,   128,   116,   121,
     122,   124,   123,   129,   130,   164,   131,   132,   133,   134,
     135,   159,   163,   160,   136,   137,   138,   139,   140,   141,
     142,   161,   144,   143,   189,   192,   225,   234,   165,   191,
     198,   227,   166,   224,     0,   167,   168,   226,   228,     0,
     169,   170,   171,   172,   173,   174,   175,     0,   176,   177,
       0,   178,   179,   180,   229,   181,   182,   183,   231,   230,
     232,   233,   235,   188,   236,   186,   187,   239,   190,   193,
     194,   238,   195,   200,   206,   196,   197,   207,   199,   208,
     201,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   240,   260,   281,   263,
     241,   242,   266,   243,   244,   270,   271,   245,   284,   285,
     286,     0,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   282,   283,   303,   259,   302,   287,   304,
       0,   261,   262,   264,   265,   267,   275,   272,   273,   274,
     276,   277,   298,   278,   293,   310,   279,   280,   313,   314,
     288,   289,    55,   290,     0,   291,   292,     0,     0,     0,
     299,     0,     0,   300,   294,   295,   296,   297,   301,   305,
     309,   306,   308,   307,   311,   312,     0,     0,   315,     0,
     316,   317,     0,     0,     0,     0,     0,     0,   318
};

static const yytype_int8 yycheck[] =
{
       4,     5,     6,     7,     8,     9,    15,    15,    15,    15,
      15,     3,    15,    12,    12,    12,    14,    63,    64,    18,
      12,    18,    16,    17,    28,    29,    18,    55,     3,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    13,    14,
      11,    63,    64,    14,    26,    27,     0,    22,    68,    24,
      12,    12,    11,    55,    63,    63,    63,    63,    63,    55,
      63,    30,    55,    13,    68,    55,    55,    55,    55,    55,
      55,    55,    55,    13,    55,    55,    55,    30,    30,     3,
      11,    11,    15,    57,    57,    57,    64,    57,    64,    57,
      57,    57,    57,    57,    57,    21,    16,    57,    12,    57,
      57,    57,    57,    16,    16,     3,    57,    32,    57,    57,
      57,    55,    57,    13,    57,    12,    18,    11,    60,    60,
      13,    22,    18,    60,    13,    64,    64,    55,    64,    64,
      64,    60,    64,    55,    55,    12,    55,    55,    55,    55,
      55,    31,    15,    31,    55,    55,    55,    55,    55,    55,
      55,    31,    55,    57,    15,    15,     3,    10,    57,    23,
      16,    13,    57,    12,    -1,    57,    57,    12,    18,    -1,
      57,    57,    57,    57,    57,    57,    57,    -1,    57,    57,
      -1,    57,    57,    57,    12,    57,    57,    57,    13,    18,
      12,    12,    11,    60,    11,    64,    64,    13,    64,    64,
      63,    19,    64,    60,    55,    64,    64,    55,    63,    55,
      64,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    13,    15,    20,    15,
      57,    57,    15,    57,    57,    16,    16,    57,    13,     3,
      13,    -1,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    20,    20,     3,    60,    12,    57,    12,
      -1,    64,    64,    64,    64,    63,    55,    64,    64,    64,
      55,    55,    63,    55,    64,    15,    55,    55,    13,    20,
      57,    57,    18,    57,    -1,    57,    57,    -1,    -1,    -1,
      55,    -1,    -1,    55,    64,    64,    64,    60,    55,    57,
      60,    57,    63,    57,    55,    55,    -1,    -1,    57,    -1,
      57,    63,    -1,    -1,    -1,    -1,    -1,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    28,    29,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    68,    73,
      74,    75,    55,    76,    55,    77,    55,    78,    55,    79,
      55,    80,    55,    81,    55,    82,    83,    55,    84,    55,
      85,    55,    86,    55,    87,    55,    88,    55,    89,    55,
      90,    91,    55,    92,    68,    75,     0,     3,    12,    18,
      12,     3,    13,    14,    22,    24,    12,    11,    11,    14,
      30,    13,    13,    30,    30,     3,    64,    11,    11,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    55,    57,
      57,    60,    15,    64,    15,    63,    60,    64,    64,    21,
      60,    15,    63,    16,    17,    16,    64,    63,    64,    63,
      64,    64,    64,    64,    60,    12,    16,    16,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    57,    55,    12,    18,    18,     3,    12,
      14,    22,    12,    18,    13,    18,    13,    13,    11,    31,
      31,    31,    12,    15,    12,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    15,    63,    64,    64,    60,    15,
      64,    23,    15,    64,    63,    64,    64,    64,    16,    63,
      60,    64,    15,    63,    15,    63,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    12,     3,    12,    13,    18,    12,
      18,    13,    12,    12,    10,    11,    11,    32,    19,    13,
      13,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    15,    63,    60,
      15,    64,    64,    15,    64,    64,    15,    63,    26,    27,
      16,    16,    64,    64,    64,    55,    55,    55,    55,    55,
      55,    20,    20,    20,    13,     3,    13,    57,    57,    57,
      57,    57,    57,    64,    64,    64,    64,    60,    63,    55,
      55,    55,    12,     3,    12,    57,    57,    57,    63,    60,
      15,    55,    55,    13,    20,    57,    57,    63,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    76,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    81,    81,    81,    82,    82,    83,    84,
      84,    85,    86,    87,    88,    88,    89,    90,    90,    91,
      92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,    12,    12,     8,     8,    16,    16,     4,
       4,    12,    20,    24,    24,    12,    12,    16,     8,     8,
       0,     4,     4,    12,    12,     4,    12,    12,     0,     4,
       4,     4,    12,     4,    10,     9,     6,    12,    12,     0,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 183 "parser.y"
    {

    }
#line 1753 "parser.cpp"
    break;

  case 3:
#line 188 "parser.y"
                              {}
#line 1759 "parser.cpp"
    break;

  case 4:
#line 189 "parser.y"
                        {}
#line 1765 "parser.cpp"
    break;

  case 5:
#line 190 "parser.y"
                      {}
#line 1771 "parser.cpp"
    break;

  case 6:
#line 191 "parser.y"
                      {}
#line 1777 "parser.cpp"
    break;

  case 7:
#line 192 "parser.y"
                          {}
#line 1783 "parser.cpp"
    break;

  case 8:
#line 193 "parser.y"
                    {}
#line 1789 "parser.cpp"
    break;

  case 9:
#line 194 "parser.y"
                       {}
#line 1795 "parser.cpp"
    break;

  case 10:
#line 195 "parser.y"
                         {}
#line 1801 "parser.cpp"
    break;

  case 11:
#line 196 "parser.y"
                       {}
#line 1807 "parser.cpp"
    break;

  case 12:
#line 197 "parser.y"
                       {}
#line 1813 "parser.cpp"
    break;

  case 13:
#line 198 "parser.y"
                       {}
#line 1819 "parser.cpp"
    break;

  case 14:
#line 199 "parser.y"
                       {}
#line 1825 "parser.cpp"
    break;

  case 15:
#line 200 "parser.y"
                         {}
#line 1831 "parser.cpp"
    break;

  case 16:
#line 201 "parser.y"
                   {}
#line 1837 "parser.cpp"
    break;

  case 17:
#line 202 "parser.y"
                       {}
#line 1843 "parser.cpp"
    break;

  case 18:
#line 203 "parser.y"
                        {}
#line 1849 "parser.cpp"
    break;

  case 19:
#line 204 "parser.y"
                       {}
#line 1855 "parser.cpp"
    break;

  case 20:
#line 205 "parser.y"
                     {}
#line 1861 "parser.cpp"
    break;

  case 21:
#line 206 "parser.y"
             {}
#line 1867 "parser.cpp"
    break;

  case 22:
#line 209 "parser.y"
                       {}
#line 1873 "parser.cpp"
    break;

  case 23:
#line 214 "parser.y"
    {
        int tam=atoi((yyvsp[-8].TEXT));
        string comilla = "\"";
        string unidad = (yyvsp[-4].TEXT);
        string ruta = (yyvsp[0].TEXT);
        mkdisk *disco=new mkdisk();
        //cout << ruta << endl;
        disco->setTamanio(tam);
        disco->setUnidad(unidad);

        size_t pos = 0;
        string ruta_final;
        while ((pos = ruta.find(comilla)) != std::string::npos) {
            ruta_final = ruta.substr(0, pos);
            ruta.erase(0, pos + comilla.length());
        }
        disco->setRuta(ruta_final);
        disco->crearDisco(disco);
        (yyval.mkdisk_cmd)=disco;
    }
#line 1898 "parser.cpp"
    break;

  case 24:
#line 236 "parser.y"
    {
        int tam=atoi((yyvsp[0].TEXT));
        mkdisk *disco=new mkdisk();
        disco->setTamanio(tam);
        string ruta = (yyvsp[-8].TEXT);
        string unidad = (yyvsp[-4].TEXT);

        disco->setTamanio(tam);
        disco->setUnidad(unidad);
        disco->crearDisco(disco);

        (yyval.mkdisk_cmd)=disco;
    }
#line 1916 "parser.cpp"
    break;

  case 25:
#line 251 "parser.y"
    {
        int tam=atoi((yyvsp[-4].TEXT));
        string comilla = "\"";
        mkdisk *disco=new mkdisk();
        string ruta = (yyvsp[0].TEXT);
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
        (yyval.mkdisk_cmd)=disco;
    }
#line 1939 "parser.cpp"
    break;

  case 26:
#line 271 "parser.y"
    {
        int tam=atoi((yyvsp[-4].TEXT));
        string ruta = (yyvsp[0].TEXT);
        mkdisk *disco=new mkdisk();
        disco->setTamanio(tam);
        disco->setRuta(ruta);
        disco->setUnidad("k");
        disco->crearDisco(disco);
        (yyval.mkdisk_cmd)=disco;

    }
#line 1955 "parser.cpp"
    break;

  case 27:
#line 284 "parser.y"
    {
        int tam=atoi((yyvsp[-12].TEXT));
        string unidad = (yyvsp[-8].TEXT);
        string archivo = (yyvsp[-4].TEXT);
        string ajuste = (yyvsp[0].TEXT);

        string delimitador = "/";
        size_t pos = 0;
        string subdir;
        string dir;
        string cmd = "mkdir ";
        string ruta_creacion;
        // Ver si tiene carpetas que la contienen
        while ((pos = archivo.find(delimitador)) != std::string::npos) {
            subdir = archivo.substr(0, pos);

            if(!subdir.empty()){
                cout << " >> Carpeta: " <<subdir << endl;

                if(subdir == "home"){
                    cmd += "/home";
                    ruta_creacion += "/home";
                }else{
                    string aux = "/" + subdir;
                    ruta_creacion += aux;
                    //dir += "/" + subdir;
                    cmd += aux;
                    cout << cmd << endl;

                    /*if(mkdir(cmd.c_str(), 0777) == -1){
                        cout << " >> f \n";
                        //cerr << " >> Error: " << strerror(errno) << endl;
                    }else{
                        cout << " >> Directorio creado \n.";
                    }*/


                    system(cmd.c_str());
                }

            }

            archivo.erase(0, pos + delimitador.length());

        }


        ruta_creacion += "/" + archivo;
        cout << " >> Archivo a crear " << ruta_creacion << endl;
        mkdisk *cmd_mkdisk =new mkdisk();
        cmd_mkdisk->setTamanio(tam);
        cmd_mkdisk->setRuta(ruta_creacion);
        cmd_mkdisk->setUnidad(unidad);
        cmd_mkdisk->setAjuste(ajuste);
        cmd_mkdisk->crearDisco(cmd_mkdisk);
        //$$=disco;
    }
#line 2017 "parser.cpp"
    break;

  case 28:
#line 344 "parser.y"
    {
        int tam=atoi((yyvsp[-8].TEXT));
        string unidad = (yyvsp[-12].TEXT);
        string archivo = (yyvsp[-4].TEXT);
        string ajuste = (yyvsp[0].TEXT);

        string delimitador = "/";
        size_t pos = 0;
        string subdir;
        string dir;
        string cmd = "mkdir ";
        string ruta_creacion;
        // Ver si tiene carpetas que la contienen
        while ((pos = archivo.find(delimitador)) != std::string::npos) {
            subdir = archivo.substr(0, pos);

            if(!subdir.empty()){
                cout << " >> Carpeta: " <<subdir << endl;

                if(subdir == "home"){
                    cmd += "/home";
                    ruta_creacion += "/home";
                }else{
                    string aux = "/" + subdir;
                    ruta_creacion += aux;
                    //dir += "/" + subdir;
                    cmd += aux;
                    cout << cmd << endl;
                    system(cmd.c_str());
                }

            }

            archivo.erase(0, pos + delimitador.length());

        }


        ruta_creacion += "/" + archivo;
        cout << " >> Archivo a crear " << ruta_creacion << endl;
        mkdisk *cmd_mkdisk =new mkdisk();
        cmd_mkdisk->setTamanio(tam);
        cmd_mkdisk->setRuta(ruta_creacion);
        cmd_mkdisk->setUnidad(unidad);
        cmd_mkdisk->setAjuste(ajuste);
        cmd_mkdisk->crearDisco(cmd_mkdisk);
    }
#line 2069 "parser.cpp"
    break;

  case 29:
#line 398 "parser.y"
{
    std::string rutaBorrar = (yyvsp[0].TEXT);
    rmdisk *discoBorrar = new rmdisk();
    discoBorrar->borrarDisco(rutaBorrar);
    (yyval.rmdisk_cmd)=discoBorrar;

}
#line 2081 "parser.cpp"
    break;

  case 30:
#line 406 "parser.y"
{
    std::string rutaBorrar = (yyvsp[0].TEXT);
    rmdisk *discoBorrar = new rmdisk();
    discoBorrar->borrarDisco(rutaBorrar);
    (yyval.rmdisk_cmd)=discoBorrar;
}
#line 2092 "parser.cpp"
    break;

  case 31:
#line 417 "parser.y"
    {
        int tamanio = atoi((yyvsp[-8].TEXT));
        string ruta = (yyvsp[-4].TEXT);
        string nombreDisco = (yyvsp[0].TEXT);

        fdisk *disco = new fdisk();
        disco->setTamanio(tamanio);
        disco->setNombre(nombreDisco);
        disco->setRuta(ruta);
        disco->setUnidad("k");
        disco->setTipo("P");
        disco->setAjuste("W");
        disco->crearParticion(disco);
        disco->mostrarDatosDisco(ruta);
        (yyval.fdisk_cmd) = disco;



    }
#line 2116 "parser.cpp"
    break;

  case 32:
#line 438 "parser.y"
    {
        string tipoParticion = (yyvsp[-16].TEXT);
        string ruta= (yyvsp[-12].TEXT);
        string unidad = (yyvsp[-8].TEXT);
        string nombreParticion = (yyvsp[-4].TEXT);
        int tamanio = atoi((yyvsp[0].TEXT));

        fdisk *disco = new fdisk();
        disco->setTipo(tipoParticion);
        disco->setAjuste("W");
        disco->setRuta(ruta);
        disco->setUnidad(unidad);
        disco->setNombre(nombreParticion);
        disco->setTamanio(tamanio);
        disco->crearParticion(disco);
        disco->mostrarDatosDisco(ruta);
        (yyval.fdisk_cmd) = disco;
    }
#line 2139 "parser.cpp"
    break;

  case 33:
#line 459 "parser.y"
    {
        int tamanio = atoi((yyvsp[-20].TEXT));
        string tipoParticion = (yyvsp[-16].TEXT);
        string unidad = (yyvsp[-12].TEXT);
        string ajusteParticion = (yyvsp[-8].TEXT);
        string r = (yyvsp[-4].TEXT);
        string n = (yyvsp[0].TEXT);
        string comilla = "\"";


        fdisk *disco = new fdisk();
        disco->setTipo(tipoParticion);
        size_t pos = 0;

        // Remover las comillas dobles
        string nombreParticion;
        while ((pos = n.find(comilla)) != std::string::npos) {
            nombreParticion = n.substr(0, pos);
            n.erase(0, pos + comilla.length());
        }

        pos = 0;
        string ruta;
        while ((pos = r.find(comilla)) != std::string::npos) {
            ruta = r.substr(0, pos);
            r.erase(0, pos + comilla.length());
        }

        disco->setRuta(ruta);
        disco->setAjuste(ajusteParticion);
        disco->setUnidad(unidad);
        disco->setNombre(nombreParticion);
        disco->setTamanio(tamanio);
        //cout << disco->getAjuste() <<  "\n";
        disco->crearParticion(disco);
        disco->mostrarDatosDisco(ruta);

        (yyval.fdisk_cmd) = disco;

    }
#line 2184 "parser.cpp"
    break;

  case 34:
#line 504 "parser.y"
    {
        string tipoParticion = (yyvsp[-20].TEXT);
        string unidad = (yyvsp[-16].TEXT);
        string nParticion = (yyvsp[-12].TEXT);
        int tamanio = atoi((yyvsp[-8].TEXT));
        string ruta = (yyvsp[-4].TEXT);
        string ajuste =(yyvsp[0].TEXT);

        fdisk *disco = new fdisk();
        disco->setNombre(nParticion);
        disco->setTamanio(tamanio);
        disco->setTipo(tipoParticion);
        disco->setAjuste(ajuste);
        disco->setRuta(ruta);
        disco->setUnidad(unidad);
        disco->crearParticion(disco);
        disco->mostrarDatosDisco(ruta);


    }
#line 2209 "parser.cpp"
    break;

  case 35:
#line 526 "parser.y"
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
#line 2227 "parser.cpp"
    break;

  case 36:
#line 541 "parser.y"
    {
        string nombreParticion = (yyvsp[-8].TEXT);
        string tipoBorrado = (yyvsp[-4].TEXT);
        string ruta = (yyvsp[0].TEXT);
        fdisk *particion = new fdisk();
        particion->setRuta(ruta);
        particion->setBorrar(tipoBorrado);
        particion->borrarParticion(ruta, particion, nombreParticion);
        particion->mostrarDatosDisco(ruta);
        //$$ = particion;

    }
#line 2244 "parser.cpp"
    break;

  case 37:
#line 555 "parser.y"
    {
        int cantidadAgregar = atoi((yyvsp[-12].TEXT));
        string unidad = (yyvsp[-8].TEXT);
        string ruta = (yyvsp[-4].TEXT);
        string par_nombre = (yyvsp[0].TEXT);

        fdisk *comando_fdisk = new fdisk();
        comando_fdisk->setUnidad(unidad);
        string comilla = "\"";

        size_t pos = 0;
        string ruta_final;
        while ((pos = ruta.find(comilla)) != std::string::npos) {
            ruta_final = ruta.substr(0, pos);
            ruta.erase(0, pos + comilla.length());
        }

        //cout << ruta_final << "\n";
        size_t posaux = 0;
        string nombreParticion;
        while ((posaux = par_nombre.find(comilla)) != std::string::npos) {
            nombreParticion = par_nombre.substr(0, posaux);
            par_nombre.erase(0, posaux + comilla.length());

        }

        //cout << ruta_final << endl;
        comando_fdisk->setRuta(ruta_final);
        comando_fdisk->setNombre(nombreParticion);
        comando_fdisk->extenderParticion(comando_fdisk, cantidadAgregar);

    }
#line 2281 "parser.cpp"
    break;

  case 38:
#line 591 "parser.y"
    {
        string ruta = (yyvsp[-4].TEXT);
        //int i = 0;
        string nombreParticion = (yyvsp[0].TEXT);
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
                    //arregloDiscos[i] = discoaMontar;

                    for (int j = 0; j < 99; j++) {

                        //cout << j << '\n';
                        if (arregloDiscos[i].particiones[j].estado == 0) {

                            //particion particionaMontar;
                            string str(1, discoaMontar.letra);
                            discoaMontar.particiones[j] = comando_mount->montarParticion(nombreParticion, j, str);
                            cout << "*******" << discoaMontar.particiones[j].id << "\n";
                            arregloDiscos[i] = discoaMontar;

                            break;
                        }


                    }

                    break;

                // Si el disco está activo y la ruta es igual
                }else if((arregloDiscos[i].estado == 1) && strcmp(arregloDiscos[i].ruta, ruta.c_str()) == 0){


                    for (int j = 0; j < 99; j++) {

                        // encuentro una particion libre (estado 0)
                        if (arregloDiscos[i].particiones[j].estado == 0) {

                            disco discoaMontar = comando_mount->montarDisco(ruta, i);
                            string str(1, discoaMontar.letra);
                            discoaMontar.particiones[j] = comando_mount->montarParticion(nombreParticion, j, str);
                            arregloDiscos[i] = discoaMontar;
                            //i++;
                            break;
                        }


                    }

                    break;
                }

            }
        }


        //$$ = comando_mount;
    }
#line 2377 "parser.cpp"
    break;

  case 39:
#line 682 "parser.y"
                                                             {}
#line 2383 "parser.cpp"
    break;

  case 40:
#line 683 "parser.y"
    {
        disco discoVacio;
        discoVacio.letra = ' ';
        discoVacio.ruta[0] = '\0';
        discoVacio.estado = 0;

        particion_disco part_vacia;
        part_vacia.numero = 0;
        part_vacia.nombre[0] = '\0';
        part_vacia.estado = 0;
        part_vacia.id[0] = '\0';

        if (!mountInicializado) {

            for (int i= 0; i < 26; i++) {
                arregloDiscos[i] = discoVacio;

                for(int j = 0; j < 99; j++){
                    arregloDiscos[i].particiones[j] = part_vacia;
                }
            }

            mountInicializado = true;
            cout << " >> Mount inicializado \n";
        }else {

            cout << " ******* PARTICIONES MONTADAS ******* \n";

            for(int i = 0; i < 26; i++){

                if(arregloDiscos[i].estado != 0){
                    cout << " Letra: " <<arregloDiscos[i].letra << "\n";
                    cout << " Ruta del disco: " <<arregloDiscos[i].ruta << "\n";
                    cout << " \t Particiones montadas : \n";

                    for(int j = 0; j < 99; j++){

                        if(arregloDiscos[i].particiones[j].estado != 0){

                            cout << "\t " << j + 1 <<". Nombre particion: " << arregloDiscos[i].particiones[j].nombre << "\n";
                            cout << "\t  ID particion: " << arregloDiscos[i].particiones[j].id << "\n";
                            cout << "\t  Ruta de la particion: " << arregloDiscos[i].ruta << "\n";
                            fflush(stdin);
                        }
                    }
                }
            }
        }


    }
#line 2439 "parser.cpp"
    break;

  case 41:
#line 739 "parser.y"
    {
        string id = (yyvsp[0].TEXT);

        unmount *comando_unmount = new unmount();

        particion_disco part_vacia;
        part_vacia.numero = 0;
        part_vacia.nombre[0] = '\0';
        part_vacia.estado = 0;
        part_vacia.id[0] = '\0';

        int num = id[2];
        char letra = id[3];

        cout << letra << "\n";

        for(int i = 0; i <26; i++){

            if(arregloDiscos[i].letra == letra){

                arregloDiscos[i].particiones[num-48] = part_vacia;
                break;
            }
        }


        (yyval.unmount_cmd) = comando_unmount;
        //comando_unmount->desmontarParticion();


    }
#line 2475 "parser.cpp"
    break;

  case 42:
#line 772 "parser.y"
    {
        particion_disco part_vacia;
        part_vacia.numero = 0;
        part_vacia.nombre[0] = '\0';
        part_vacia.estado = 0;
        part_vacia.id[0] = '\0';

        string id = (yyvsp[0].TEXT);
        char num[2];

        for(int i = 2; i < 4;i++){
            num[i-2] = id[i];
        }
        //string n = num;
        char letra = id[4];
        cout << atoi(num) << "\n";
        //cout << letra << "\n";

        for(int i = 0; i <26; i++){

            if(arregloDiscos[i].letra == letra){

                for(int j = 0; j < 99; i++){
                    arregloDiscos[i].particiones[j] = part_vacia;
                    nombreParticion = "";
                    rutaParticionActual = "";
                    break;
                }
            }

        }
    }
#line 2512 "parser.cpp"
    break;

  case 43:
#line 814 "parser.y"
    {
        string ruta;
        string tipoFormateo = (yyvsp[-8].TEXT);
        char nombreParticion[16];
        string id = (yyvsp[-4].TEXT);

        mkfs *cmd_mkfs = new mkfs();

        for(int i = 0; i < 26; i++){

            for(int j = 0; j < 99; j++){

                if(arregloDiscos[i].particiones[j].id == id){
                    ruta = arregloDiscos[i].ruta;
                    strcpy(nombreParticion, arregloDiscos[i].particiones[j].nombre);
                    cmd_mkfs->formatearEXT2(ruta, nombreParticion, tipoFormateo);
                    break;
                }

            }
        }


    }
#line 2541 "parser.cpp"
    break;

  case 44:
#line 840 "parser.y"
    {
        string ruta;
        string tipoFormateo = (yyvsp[-8].TEXT);
        char nombreParticion[16];
        string id = (yyvsp[-4].TEXT);

        mkfs *cmd_mkfs = new mkfs();

        for(int i = 0; i < 26; i++){

            for(int j = 0; j < 99; j++){

                // encuentra el id de la partición a la que se tiene que formatear
                if(arregloDiscos[i].particiones[j].id == id){
                    ruta = arregloDiscos[i].ruta;
                    strcpy(nombreParticion, arregloDiscos[i].particiones[j].nombre);
                    cmd_mkfs->formatearEXT3(ruta, nombreParticion, tipoFormateo);
                    break;
                }

            }

        }

    }
#line 2571 "parser.cpp"
    break;

  case 45:
#line 867 "parser.y"
    {
        string ruta;
        char nombreParticion[16];
        string id = (yyvsp[0].TEXT);

        mkfs *cmd_mkfs = new mkfs();

        for(int i = 0; i < 26; i++){

            for(int j = 0; j < 99; j++){

                if(arregloDiscos[i].particiones[j].id == id){
                    ruta = arregloDiscos[i].ruta;
                    strcpy(nombreParticion, arregloDiscos[i].particiones[j].nombre);
                    cmd_mkfs->formatearEXT2(ruta, nombreParticion, "full");
                    break;
                }

            }
        }
    }
#line 2597 "parser.cpp"
    break;

  case 46:
#line 894 "parser.y"
{
    string usr = (yyvsp[-8].TEXT);
    int pass = atoi((yyvsp[-4].TEXT));
    string id = (yyvsp[0].TEXT);

    // Iniciando sesión como usuario root
    if(usr == "root" && pass == 123 && yaInicioSesion == false){

        // procedo a buscar mi particion montada
        for(int i = 0; i < 26; i++){

            for(int j = 0; j < 99; j++){
                if(strcmp(arregloDiscos[i].particiones[j].id, id.c_str())== 0){

                    cout << " >> Particion encontrada. \n";
                    nombreParticion = arregloDiscos[i].particiones[j].nombre;
                    rutaParticionActual = arregloDiscos[i].ruta;
                    break;
                }
            }
        }

        yaInicioSesion = true;
        usrname = usr;
        cout << " >> Has iniciado sesión. \n";

    }else{
        cout << " Error al iniciar sesion. \n";
    }


}
#line 2634 "parser.cpp"
    break;

  case 47:
#line 928 "parser.y"
    {
        string u_ = (yyvsp[-8].TEXT);
        string p_ = (yyvsp[-4].TEXT);
        string id = (yyvsp[0].TEXT);
        string rutaParticion;

        string comilla = "\"";
        size_t pos = 0;
        // Remover las comillas dobles
        string nombreUsuario;
        while ((pos = u_.find(comilla)) != std::string::npos) {
            nombreUsuario = u_.substr(0, pos);
            u_.erase(0, pos + comilla.length());
        }

        pos = 0;
        string contrasenia;
        while ((pos = p_.find(comilla)) != std::string::npos) {
            contrasenia = p_.substr(0, pos);
            p_.erase(0, pos + comilla.length());
        }

        /*
            Buscar si la particion está montada o no
            si no está montada, tiene que tirar error y no dejar iniciar sesion
            tambien si el usuario ingresa los datos incorrectos debe de lanzar error

            Si encuentro la particion (y su archivo)
            leer el archivo y validar los datos de inicio de sesion

        */

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 99; j++){

                if(arregloDiscos[i].particiones[j].id == id){

                    cout << " >> Particion encontrada \n";
                    // * poner metodo que valide mis datos en la particion *
                    break;
                }
            }
        }

        //cout << nombreUsuario <<  "\n";
        //cout << contrasenia << "\n";
    }
#line 2686 "parser.cpp"
    break;

  case 48:
#line 979 "parser.y"
{
   if(yaInicioSesion){

        cout << " >> Has cerrado la sesion. \n";
        usrname = "";
        yaInicioSesion = false;

    }else{

        cout << " >> No tienes ninguna sesion iniciada. \n";

    }



}
#line 2707 "parser.cpp"
    break;

  case 49:
#line 1001 "parser.y"
    {
        string nombreGrupo  = (yyvsp[0].TEXT);
        mkgrp *cmd_mkgrp = new mkgrp();

        if(yaInicioSesion && usrname == "root"){
            cmd_mkgrp->crearGrupo(nombreParticion, rutaParticionActual, nombreGrupo);
        }else{
            cout << " >> Comando no permitido.\n";
        }
    }
#line 2722 "parser.cpp"
    break;

  case 50:
#line 1012 "parser.y"
                             {}
#line 2728 "parser.cpp"
    break;

  case 51:
#line 1019 "parser.y"
    {

    }
#line 2736 "parser.cpp"
    break;

  case 52:
#line 1027 "parser.y"
    {

        string usr = (yyvsp[-8].TEXT);
        string pass = (yyvsp[-4].TEXT);
        string grp = (yyvsp[0].TEXT);
        mkusr *cmd_mkusr = new mkusr();
        user *usuario = new user();
        usuario->setNombreUsuario(usr);
        usuario->setContrasenia(pass);
        usuario->setGrupo(grp);
        if(yaInicioSesion && usrname == "root"){
            cmd_mkusr->crearUsuario(nombreParticion, rutaParticionActual, usuario);
        }else{
            cout << " >> Comando no permitido \n";
        }

    }
#line 2758 "parser.cpp"
    break;

  case 53:
#line 1049 "parser.y"
    {

    }
#line 2766 "parser.cpp"
    break;

  case 54:
#line 1058 "parser.y"
    {

        string ruta = (yyvsp[-2].TEXT);
        int tamanio = atoi((yyvsp[-6].TEXT));

        if(yaInicioSesion){

            user *usuario = new user();
            usuario->setNombreUsuario(usrname);
            usuario->setGrupo("1");

            file *archivo_crear = new file();
            archivo_crear->setRuta(ruta);
            archivo_crear->setTienePadre(false);
            mkfile *cmd_mkfile = new mkfile();
            cmd_mkfile->crearArchivo(nombreParticion, rutaParticionActual, usuario, archivo_crear);

        }else{
            cout << " >> Debes iniciar sesion para ejecutar este comando \n";
        }

    }
#line 2793 "parser.cpp"
    break;

  case 55:
#line 1082 "parser.y"
    {
        string ruta = (yyvsp[-1].TEXT);
        int tamanio = atoi((yyvsp[-5].TEXT));

        if(yaInicioSesion){

            user *usuario = new user();
            usuario->setNombreUsuario(usrname);
            usuario->setGrupo("1");

            string comilla = "\"";
            size_t pos = 0;
            string r_;
            // Remover las comillas dobles
            string ruta;
            while ((pos = ruta.find(comilla)) != std::string::npos) {
                r_ = ruta.substr(0, pos);
                ruta.erase(0, pos + comilla.length());
            }

            cout << r_ << endl;

            file *archivo_crear = new file();
            archivo_crear->setRuta(r_);
            archivo_crear->setTienePadre(false);
            mkfile *cmd_mkfile = new mkfile();
            cmd_mkfile->crearArchivo(nombreParticion, rutaParticionActual, usuario, archivo_crear);

        }else{
            cout << " >> Debes iniciar sesion para ejecutar este comando \n";
        }
    }
#line 2830 "parser.cpp"
    break;

  case 56:
#line 1120 "parser.y"
    {
        string ruta = (yyvsp[0].TEXT);
        if(yaInicioSesion){

            user *usuario = new user();
            usuario->setNombreUsuario(usrname);
            usuario->setGrupo("1");

            // separar cada uno de los subdirectorios

            string delimitador = "/";
            size_t pos = 0;
            string subdir;

            // Ver si tiene carpetas que la contienen
            while ((pos = ruta.find(delimitador)) != std::string::npos) {
                subdir = ruta.substr(0, pos);

                if(!subdir.empty()){
                    cout << " >> Carpeta: " <<subdir << endl;
                    carpeta *nueva_carpeta = new carpeta();
                    nueva_carpeta->setNombreCarpeta(subdir);
                    cout << " Ruta particion -- " << rutaParticionActual << endl;
                    // Crear nueva carpeta con un mkdir
                    mkdir *cmd_mkdir = new mkdir();
                    cmd_mkdir->crearCarpeta(nombreParticion, rutaParticionActual, usuario, nueva_carpeta);
                }

                ruta.erase(0, pos + delimitador.length());
            }
            //mkdir_cmd->crearCarpeta(nombreParticion, rutaParticionActual, usuario,);
        }else{
            cout << " >> Inicia sesion para ejecutar este comando. \n";
        }
    }
#line 2870 "parser.cpp"
    break;

  case 57:
#line 1160 "parser.y"
    {
        string id = (yyvsp[-8].TEXT);
        string rutaDestinoReporte = (yyvsp[-4].TEXT);// ruta fisica en donde se guardar al reporte
        string tipoReporte = (yyvsp[0].TEXT);
        string nombreParticionReporte; // id de la particion que usaré para el reporte
        string rutaParticionReporte; // ruta ubicada en el disco
        if(yaInicioSesion){


            for(int i = 0; i < 26; i++){

                for(int j = 0; j <99;j++){
                    if(strcmp(arregloDiscos[i].particiones[j].id, id.c_str())== -1){
                        cout << " :) \n";
                        nombreParticionReporte = arregloDiscos[i].particiones[j].nombre;
                        rutaParticionReporte = arregloDiscos[i].ruta;
                        break;
                    }
                }
            }



            rep *reporte = new rep();

            if(tipoReporte == "sb"){
                reporte->sb(rutaParticionReporte, nombreParticionReporte, rutaDestinoReporte);
                cout << " >> Generando reporte de superbloque... \n";
            }
            else if(tipoReporte == "mbr"){
                reporte->repmbr(rutaParticionReporte, nombreParticionReporte, rutaDestinoReporte);
                cout << " >> Generando reporte de mbr... \n";
            }
            else if(tipoReporte == "disk"){
                reporte->disk(rutaParticionReporte, rutaDestinoReporte);
                cout << " >> Generando reporte de disco... \n";
            }
            else if(tipoReporte == "bm_inode"){
                reporte->bm_inode(rutaParticionReporte, nombreParticionReporte, rutaDestinoReporte);
                cout << " >> Generando reporte de bitmap de inodos... \n";
            }
            else if(tipoReporte == "bm_block"){
                reporte->bm_inode(rutaParticionReporte, nombreParticionReporte, rutaDestinoReporte);
                cout << " >> Generando reporte de bitmap de bloques... \n";
            }
            else if(tipoReporte == "journaling"){
                reporte->rep_journaling(rutaParticionReporte, nombreParticionReporte, rutaDestinoReporte);
                cout << " >> Generando reporte de journaling... \n";
            }
            else if(tipoReporte == "inode"){
                reporte->rep_inodos(rutaParticionReporte, nombreParticionReporte, rutaDestinoReporte);
                cout << " >> Generando reporte de inodos... \n";
            }
            else if(tipoReporte == "block"){
                reporte->rep_bloques(rutaParticionReporte, nombreParticionReporte, rutaDestinoReporte);
                cout << " >> Generando reporte de bloques... \n";
            }
            else{
                cout << " >> Tipo de reporte incorrecto. \n";
            }


        }else{
            cout << " >> Inicia sesion para generar reportes. \n";
        }

    }
#line 2942 "parser.cpp"
    break;

  case 58:
#line 1229 "parser.y"
    {
        string id = (yyvsp[-8].TEXT);
        string rutaDestinoReporte = (yyvsp[-4].TEXT);// ruta fisica en donde se guardar al reporte
        string tipoReporte = (yyvsp[0].TEXT);
        string nombreParticionReporte; // id de la particion que usaré para el reporte
        string rutaParticionReporte; // ruta ubicada en el disco

        string comilla = "\"";
        size_t pos = 0;
        // Remover las comillas dobles
        string ruta;
        while ((pos = rutaDestinoReporte.find(comilla)) != std::string::npos) {
            ruta = rutaDestinoReporte.substr(0, pos);
            rutaDestinoReporte.erase(0, pos + comilla.length());
        }

        //cout << ruta << "\n";
        cout << " >> Id: " << id << "\n";

            for(int i = 0; i < 26; i++){

                for(int j = 0; j <99;j++){

                    if(strcmp(arregloDiscos[i].particiones[j].id, id.c_str())== -1){
                        ruta = arregloDiscos[i].ruta;
                        nombreParticionReporte = arregloDiscos[i].particiones[j].nombre;
                        rutaParticionReporte = arregloDiscos[i].ruta;
                        cout << " >> Particion encontrada \n";
                        break;
                    }
                }
            }


            cout << " >> " << ruta << "\n";
            rep *reporte = new rep();

            if(tipoReporte == "sb"){
                reporte->sb(rutaParticionReporte, nombreParticionReporte, ruta);
                cout << " >> Generando reporte de superbloque... \n";
            }
            else if(tipoReporte == "mbr"){
                reporte->repmbr(rutaParticionReporte, nombreParticionReporte, ruta);
                cout << " >> Generando reporte de mbr... \n";
            }
            else if(tipoReporte == "disk"){
                reporte->disk(rutaParticionReporte, ruta);
                cout << " >> Generando reporte de disco... \n";
            }
            else if(tipoReporte == "bm_inode"){
                reporte->bm_inode(rutaParticionReporte, nombreParticionReporte, ruta);
                cout << " >> Generando reporte de bitmap de inodos... \n";
            }
            else if(tipoReporte == "bm_block"){
                reporte->bm_inode(rutaParticionReporte, nombreParticionReporte, ruta);
                cout << " >> Generando reporte de bitmap de bloques... \n";
            }
            else if(tipoReporte == "journaling"){
                reporte->rep_journaling(rutaParticionReporte, nombreParticionReporte, ruta);
                cout << " >> Generando reporte de journaling... \n";
            }
            else if(tipoReporte == "inode"){
                reporte->rep_inodos(rutaParticionReporte, nombreParticionReporte, ruta);
                cout << " >> Generando reporte de inodos... \n";
            }
            else if(tipoReporte == "block"){
                reporte->rep_bloques(rutaParticionReporte, nombreParticionReporte, ruta);
                cout << " >> Generando reporte de bloques... \n";
            }
            else{
                cout << " >> Tipo de reporte incorrecto. \n";
            }



    }
#line 3023 "parser.cpp"
    break;

  case 59:
#line 1308 "parser.y"
              {

    cout << " >> Presiona cualquier tecla para continuar... \n";
    cin.get();

}
#line 3034 "parser.cpp"
    break;

  case 60:
#line 1318 "parser.y"
    {
        string id = (yyvsp[0].TEXT);

        for(int i = 0; i < 26; i++){

            for(int j = 0; j <99;j++){
                if(strcmp(arregloDiscos[i].particiones[j].id, id.c_str())== -1){

                    cout << " >> Particion encontrada \n";

                    loss *cmd_loss = new loss();
                    cmd_loss->simularPerdida(arregloDiscos[i].particiones[j].nombre, arregloDiscos[i].ruta);

                    break;
                }
            }
        }
    }
#line 3057 "parser.cpp"
    break;


#line 3061 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
