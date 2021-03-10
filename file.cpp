#include "file.h"

file::file()
{

}

void file::setRuta(string ruta) { this->ruta = ruta; }

void file::setTienePadre(bool b) { this->tienePadre = b; }

string file::getRuta() { return this->ruta; }

bool file::getTienePadre() { return this->tienePadre; }
