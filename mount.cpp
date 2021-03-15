#include "mount.h"
#include "estructuras.h"


mount::mount()
{

}

/*
void mount::montarParticion(string ruta, string nombreParticion){

    int prefijo_id = 96;
    //cout << discos_montados.length()
    // Leer el archivo para leerlo

    FILE *archivo_disco;
    archivo_disco = fopen(ruta.c_str(), "rb+");

    if(archivo_disco == NULL){
        cout << " >> El disco no existe. \n";
    }

    cout << " >> Montando disco... \n";

    disco disco_;
    disco_.letra = 'A'; // Cambiar por una funcion que detecte letra
    strcpy(disco_.ruta, ruta.c_str());
    disco_.estado = 0;

    mbr mbr_busqueda;
    particion_disco particionBuscada;
    //particion particion_disco;
    fseek(archivo_disco, 0, SEEK_SET);
    fread(&mbr_busqueda, sizeof(mbr), 1, archivo_disco);


    for(int i = 0; i<4; i++){

        if(strcmp(mbr_busqueda.mbr_particions[i].part_name, nombreParticion.c_str())){

            strcpy(particionBuscada.nombre, mbr_busqueda.mbr_particions[i].part_name);
            particionBuscada.estado = mbr_busqueda.mbr_particions[i].part_status;
            particionBuscada.numero = 1;
            disco_.particiones[0] = particionBuscada;
        }

    }

    fclose(archivo_disco);
}
*/
disco mount::montarDisco(string ruta, int pos){

    FILE *archivo;
    archivo = fopen(ruta.c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> Archivo no encontrado. \n";
    }

    disco disco_;
    disco_.letra = asignarLetra(pos);
    strcpy(disco_.ruta, ruta.c_str());
    disco_.estado = 1;


    return disco_;

}

char mount::asignarLetra(int numero){

    switch (numero) {
    case 0:

        return 'a';
    case 1:

        return 'b';
    case 2:

        return 'c';
    case 3:

        return 'd';
    case 4:

        return 'e';
    case 5:

        return 'f';
    case 6:

        return 'g';
    case 7:

        return 'h';
    case 8:

        return 'i';
    case 9:

        return 'j';
    case 10:

        return 'j';
    case 11:

        return 'l';
    case 12:

        return 'm';
    case 13:

        return 'n';
    case 14:

        return 'o';
    case 15:

        return 'p';
    case 16:

        return 'q';
    case 17:

        return 'r';
    case 18:

        return 's';
    case 19:

        return 't';
    case 20:

        return 'u';
    case 21:

        return 'v';
    case 22:

        return 'w';
    case 23:

        return 'x';
    case 24:

        return 'y';
    case 25:

        return 'z';
    default:
        break;
    }

}

particion_disco mount::montarParticion(string nombreParticion, int pos, string letra) {

    string num = "96";

    num.append(to_string(pos));//961
    string str;
    str.append(letra);
    //str.append(letra);
    cout << letra << " --- \n";
    string l = letra;

    string id_ = num + letra;

    cout << " ---> " <<  id_  << "\n";

    char id[id_.length()];

    for(int i = 0; i< sizeof(id);i++){
        id[i] = id_[i];
    }

    particion_disco part;

    strcpy(part.id, id_.c_str());
    //part.id = id_;
    part.numero = pos;
    part.estado = 1;
    strcpy(part.nombre, nombreParticion.c_str());


    return part;
}
