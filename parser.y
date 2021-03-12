%{
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
// reportes
#include "rep.h"
// estructuras
#include "estructuras.h"
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

}
//TERMINALES DE TIPO TEXT, SON STRINGS

%token<TEXT> psize;
%token<TEXT> pmkdisk;
%token<TEXT> prmdisk;
%token<TEXT> pfdisk;
%token<TEXT> pmount;
%token<TEXT> punmount;
%token<TEXT> pmkfs;
%token<TEXT> p_fs;


%token<TEXT> p_id;
%token<TEXT> p_path;
%token<TEXT> p_name;
%token<TEXT> p_type;
%token<TEXT> ruta_sin_espacio;
%token<TEXT> id_particion;
%token<TEXT> id_particionl;
%token<TEXT> p_u;
%token<TEXT> p_r;
%token<TEXT> p_f;
%token<TEXT> p_fast;
%token<TEXT> p_delete;
%token<TEXT> p_full;
%token<TEXT> p_add;
%token<TEXT> pmkdir;
%token<TEXT> p_2fs;
%token<TEXT> p_3fs;
%token<TEXT> p_login;
%token<TEXT> p_logout;
%token<TEXT> p_usr;
%token<TEXT> p_pwd;
%token<TEXT> p_grp;
%token<TEXT> p_mkgrp;
%token<TEXT> p_rmgrp;
%token<TEXT> p_mkusr;
%token<TEXT> p_rmusr;
%token<TEXT> p_mkfile;
%token<TEXT> p_rep;

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

%token<TEXT> entero;
%token<TEXT> letra;
%token<TEXT> numnegativo;
%token<TEXT> cadena;
%token<TEXT> identificador;
%token<TEXT> caracter;
%token<TEXT> ruta;
%token<TEXT> rutacualquiera;



// Comandos usados
%type<mkdisk_cmd> COMANDOMKDISK;
%type<rmdisk_cmd> COMANDORMDISK;
%type<fdisk_cmd> COMANDOFDISK;
%type<mount_cmd> COMANDOMOUNT;
%type<unmount_cmd> COMANDOUNMOUNT;
%type<mkfs_cmd> COMANDOMKFS;
%type<usr_login> COMANDOLOGIN;
%type<usr_login> COMANDOLOGOUT;
%type<mkgrp_cmd> COMANDOMKGRP;
%type<rmgrp_cmd> COMANDORMGRP;
%type<mkusr_cmd> COMANDOMKUSR;
%type<rmusr_cmd> COMANDORMUSR;
%type<mkfile_cmd> COMANDOMKFILE;
%type<rep_cmd> COMANDOREP;

%left suma menos
%left multi division
%left potencia
%start INICIO
%%

INICIO : LEXPA
    {

    }
;

LEXPA:  pmkdisk COMANDOMKDISK {}
| prmdisk COMANDORMDISK {}
| pfdisk COMANDOFDISK {}
| pmount COMANDOMOUNT {}
| punmount COMANDOUNMOUNT {}
| pmkfs COMANDOMKFS {}
| p_login COMANDOLOGIN {}
| p_logout COMANDOLOGOUT {}
| p_mkgrp COMANDOMKGRP {}
| p_rmgrp COMANDORMGRP {}
| p_mkusr COMANDOMKUSR {}
| p_rmusr COMANDORMUSR {}
| p_mkfile COMANDOMKFILE {}
| p_rep COMANDOREP {}
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
        string tipoParticion = $4;
        string ruta= $8;
        string unidad = $12;
        string nombreParticion = $16;
        int tamanio = atoi($20);

        fdisk *disco = new fdisk();
        disco->setTipo(tipoParticion);
        disco->setAjuste("W");
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
        int tamanio = atoi($4);
        string tipoParticion = $8;
        string unidad = $12;
        string ajusteParticion = $16;
        string r = $20;
        string n = $24;
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

        $$ = disco;

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
        //$$ = particion;

    }
// -add=1 -u=M -path="/home/juan/Desktop/Disco.dk" -name="Particion 4"
| menos p_add igual entero menos p_u igual identificador menos p_path igual cadena menos p_name igual cadena
    {
        int cantidadAgregar = atoi($4);
        string unidad = $8;
        string ruta = $12;
        string par_nombre = $16;

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


        comando_fdisk->setRuta(ruta_final);
        comando_fdisk->setNombre(nombreParticion);
        comando_fdisk->extenderParticion(comando_fdisk, cantidadAgregar);

    }
;

COMANDOMOUNT:
menos p_path igual ruta_sin_espacio menos p_name igual identificador
    {
        string ruta = $4;
        //int i = 0;
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
                    //arregloDiscos[i] = discoaMontar;

                    for (int j = 0; j < 99; j++) {

                        //cout << j << '\n';
                        if (arregloDiscos[i].particiones[j].estado == 0) {

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
| menos p_path igual cadena menos p_name igual identificador {}
|   {
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
                            fflush(stdin);
                        }
                    }
                }
            }
        }


    }
;

COMANDOUNMOUNT:
// unmount -id=960A
 menos p_id igual id_particion
    {
        string id = $4;

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


        $$ = comando_unmount;
        //comando_unmount->desmontarParticion();


    }
 // unmount -id=9699A
| menos p_id igual id_particionl
    {
        particion_disco part_vacia;
        part_vacia.numero = 0;
        part_vacia.nombre[0] = '\0';
        part_vacia.estado = 0;
        part_vacia.id[0] = '\0';

        string id = $4;
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

;

COMANDOMKFS:
 /*
    fast para 2fs y 3fs
    full para 2fs y 3fs
 */
// mkfs -type=fast -id=581A -fs=2fs
menos p_type igual p_fast  menos p_id igual id_particion menos p_fs igual p_2fs
    {
        string ruta;
        char nombreParticion[16];
        string id = $8;

        mkfs *cmd_mkfs = new mkfs();

        for(int i = 0; i < 26; i++){

            for(int j = 0; j < 99; j++){

                if(arregloDiscos[i].particiones[j].id == id){
                    ruta = arregloDiscos[i].ruta;
                    strcpy(nombreParticion, arregloDiscos[i].particiones[j].nombre);
                    cmd_mkfs->formatearEXT2(ruta, nombreParticion, "fast");
                    break;
                }

            }
        }


    }
// mkfs -type=fast -id=581A -fs=3fs
| menos p_type igual p_fast  menos p_id igual id_particion menos p_fs igual p_3fs
    {
        string ruta;
        char nombreParticion[16];
        string id = $8;

        mkfs *cmd_mkfs = new mkfs();

        for(int i = 0; i < 26; i++){

            for(int j = 0; j < 99; j++){

                // encuentra el id de la partición a la que se tiene que formatear
                if(arregloDiscos[i].particiones[j].id == id){
                    ruta = arregloDiscos[i].ruta;
                    strcpy(nombreParticion, arregloDiscos[i].particiones[j].nombre);
                    cmd_mkfs->formatearEXT3(ruta, nombreParticion, "fast");
                    break;
                }

            }

        }

    }
// mkfs -type=full -id=581A -fs=3fs
| menos p_type igual p_full  menos p_id igual id_particion menos p_fs igual p_2fs
    {

    }
// mkfs -type=full -id=581A -fs=3fs
| menos p_type igual p_full  menos p_id igual id_particion menos p_fs igual p_3fs
    {
    }
// mkfs -id=582A (No manda parametros, así que será el EXT2)
| menos p_id igual id_particion
    {
        string ruta;
        char nombreParticion[16];
        string id = $4;

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
;


COMANDOLOGIN:
// -usr=root -pwd=123 -id=582A (iniciando sesion como usuario root)
menos p_usr igual identificador menos p_pwd igual entero menos p_id igual id_particion
{
    string usr = $4;
    int pass = atoi($8);
    string id = $12;

    // Iniciando sesión como usuario root
    if(usr == "root" && pass == 123){

        // procedo a buscar mi particion montada
        for(int i = 0; i < 26; i++){

            for(int j = 0; j < 99; j++){
                if(arregloDiscos[i].particiones[j].id == id){

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
        cout << " Datos incorrectos";
    }


}
// -usr="mi usuario" -pwd="contraseña" -id=582A
| menos p_usr igual cadena menos p_pwd igual cadena menos p_id igual id_particion
    {
        string u_ = $4;
        string p_ = $8;
        string id = $12;
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
;

COMANDOLOGOUT:
//
{
   if(yaInicioSesion){

        cout << " >> Has cerrado la sesion. \n";
        usrname = "";
        yaInicioSesion = false;

    }else{

        cout << " >> No tienes ninguna sesion iniciada. \n";

    }



}
;


COMANDOMKGRP:
 // mkgrp -name=usuarios
 menos p_name igual identificador
    {
        string nombreGrupo  = $4;
        mkgrp *cmd_mkgrp = new mkgrp();

        if(yaInicioSesion && usrname == "root"){
            cmd_mkgrp->crearGrupo(nombreParticion, rutaParticionActual, nombreGrupo);
        }else{
            cout << " >> Comando no permitido.\n";
        }
    }
 // mkgrp -name="grupo 1"
 | menos p_name igual cadena {}
;


COMANDORMGRP:
// rmgrp -name=usuarios
menos p_name igual identificador
    {

    }
;

COMANDOMKUSR:
// mkusr -usr=user1 -pwd=pass -grp=usuarios
menos p_usr igual identificador menos p_pwd igual identificador menos p_grp igual identificador
    {

        string usr = $4;
        string pass = $8;
        string grp = $12;
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
;

COMANDORMUSR:
// rmusr -usr=user1
menos p_usr igual identificador
    {

    }
;


COMANDOMKFILE:
// -SIZE=15 -PatH=/home/user/docs/a.txt –r
menos psize igual entero  menos p_path igual ruta_sin_espacio menos p_r
    {

        string ruta = $8;
        int tamanio = atoi($4);

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
//
;


COMANDOREP:
// –id=561A -Path=/home/user/reports/reporte1.jpg -name=mbr
menos p_id igual id_particion menos p_path igual ruta_sin_espacio menos p_name igual identificador
    {
        string id = $4;
        string rutaDestinoReporte = $8;// ruta fisica en donde se guardar al reporte
        string tipoReporte = $12;
        string nombreParticionReporte; // id de la particion que usaré para el reporte
        string rutaParticionReporte; // ruta ubicada en el disco
        if(yaInicioSesion){


            for(int i = 0; i < 26; i++){

                for(int j = 0; j <99;j++){
                    if(arregloDiscos[i].particiones[j].id == id){
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
            }else if(tipoReporte == "mbr"){
                reporte->repmbr(rutaParticionReporte, nombreParticionReporte, rutaDestinoReporte);
                cout << " >> Generando reporte de mbr... \n";
            }else if(tipoReporte == "disk"){
                reporte->disk(rutaParticionActual, rutaDestinoReporte);
                cout << " >> Generando reporte de disco... \n";
            }
            else{
                cout << " >> Tipo de reporte incorrecto. \n";
            }

            /*
            switch(tipoReporte) {
            case "mbr":
                reporte->sb(rutaParticionReporte, nombreParticionReporte);
                break;
            case "disk":
                break;
            case "inode":
                break;
            case "journaling":
                break;
            case "block":
                break;
            case "bm_inode":
                break;
            case "bm_block":
                break;
            case "tree":
                break;
            case "sb":
                break;
            case "file":
                break;
            case "ls":
                break;
            default:
                cout << " >> Tipo de reporte incorrecto. \n";
                break;
            }
            */

        }else{
            cout << " >> Inicia sesion para generar reportes. \n";
        }

    }

;
