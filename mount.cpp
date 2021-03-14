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

        return 'A';
    case 1:

        return 'B';
    case 2:

        return 'C';
    case 3:

        return 'D';
    case 4:

        return 'E';
    case 5:

        return 'F';
    case 6:

        return 'G';
    case 7:

        return 'H';
    case 8:

        return 'I';
    case 9:

        return 'J';
    case 10:

        return 'K';
    case 11:

        return 'L';
    case 12:

        return 'M';
    case 13:

        return 'N';
    case 14:

        return 'O';
    case 15:

        return 'P';
    case 16:

        return 'Q';
    case 17:

        return 'R';
    case 18:

        return 'S';
    case 19:

        return 'T';
    case 20:

        return 'U';
    case 21:

        return 'V';
    case 22:

        return 'W';
    case 23:

        return 'X';
    case 24:

        return 'Y';
    case 25:

        return 'Z';
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
