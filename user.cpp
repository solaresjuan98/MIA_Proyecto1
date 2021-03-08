#include "user.h"

user::user()
{

}

void user::setNombreUsuario(string nombreUsuario) { this->nombreUsuario = nombreUsuario; }

void user::setContrasenia(string contrasenia) { this->contrasenia = contrasenia; }

void user::setGrupo(string grupo) { this->grupo = grupo; }

string user::getNombreUsuario() { return this->nombreUsuario; }

string user::getContrasenia() { return this->contrasenia; }

string user::getGrupo() { return this->grupo; }
