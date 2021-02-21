#include "mount.h"
#include "estructuras.h"

disco discos_montados[26];

mount::mount()
{

}


void mount::setNombre(string nombre) { this->nombre = nombre; }

string mount::getNombre() { return this->nombre; }

void mount::setRuta(string ruta) { this->ruta = ruta; }

string mount::getRuta() { return this->ruta;  }

void mount::montarParticion(string ruta){

    int prefijo_id = 96;
    // Leer el archivo para leerlo

    FILE *archivo_disco;
    archivo_disco = fopen(ruta.c_str(), "rb+");

    if(archivo_disco == NULL){
        std::cout << " >> El disco no existe. \n";
    }

    mbr mbr_busqueda;
    fseek(archivo_disco, 0, SEEK_SET);
    fclose(archivo_disco);
}
