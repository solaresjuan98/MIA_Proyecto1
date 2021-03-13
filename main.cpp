#include <QCoreApplication>

#include "iostream"

#include <QString>

#include <parser.h>  // Nuestro parser

#include <scanner.h>  // Nuestro scanner

#include <QTextStream>

#include <fstream>

using namespace std;
extern int yyparse(); //
//static QList<discosmontados> discosenmemoria;
int p;
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;

string partirComando(string cmd);
void ejecutarComando(QString comando);

int main() {
  // exec -path=/home/juan/Desktop/discos.txt
  QTextStream qtin(stdin);
  QString line;

  while (line != "salir") {
    cout << "\n *** Ingresa un comando ***" << endl;
    line = qtin.readLine();
    if (line != "salir") {
        // hacerle split al comando
        string comando = line.toUtf8().constData();
        string ruta = partirComando(comando);

        string entrada;
        std::ifstream archivo(ruta);
        /*
            LEYENDO ARCHIVO DE ENTRADA
        */
        if (archivo.is_open()) {
              while (getline(archivo, entrada)) {
                cout << entrada << "\n";
                QString linea = QString::fromLocal8Bit(entrada.c_str());
                // Ejecutar comando
                ejecutarComando(linea);
              }
        } else {
          cout << " >> El archivo no se pudo leer. \n";
        }

    }

  }

  //return 0;
}

string partirComando(string cmd) {
  string igual = "=";
  size_t pos = 0;
  // Remover las comillas dobles
  string ruta;
  while ((pos = cmd.find(igual)) != std::string::npos) {
    ruta = cmd.substr(0, pos);
    cmd.erase(0, pos + igual.length());
  }

  return cmd;
}

void ejecutarComando(QString comando) {
  if (comando.isEmpty() == false) {
    YY_BUFFER_STATE buffer = yy_scan_string(comando.toUtf8().constData());

    linea = 0;
    columna = 0;
    yylineno = 0;

    if (yyparse() == 0)
    {


    } else {
      cout << " >> Comando erroneo " << endl;

    }

  }
}

