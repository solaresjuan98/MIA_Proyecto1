#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class user
{
private:
    string nombreUsuario;
    string contrasenia;
    string grupo;

public:
    user();

    // getters y setters
    void setNombreUsuario(string nombreUsuario);
    void setContrasenia(string contrasenia);
    void setGrupo(string grupo);
    string getNombreUsuario();
    string getContrasenia();
    string getGrupo();

};

#endif // USER_H
