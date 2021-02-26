#include <QCoreApplication>
#include "iostream"
#include <QString>
#include <parser.h>  // Nuestro parser
#include <scanner.h>  // Nuestro scanner
#include <QTextStream>
#include "mkdisk.h"
using namespace std;
extern int yyparse(); //
//static QList<discosmontados> discosenmemoria;
int p;
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;
int main()
{

    QTextStream qtin(stdin);
    QString line;

    while(line!="salir"){    //esto me sirve para seguir leyendo siempre los comandos sin salirme
        cout << "\n *** Ingresa un comando ***"<<endl;
        line = qtin.readLine();
        if(line!="salir"){
            if(line.isEmpty()==false){
                YY_BUFFER_STATE buffer = yy_scan_string(line.toUtf8().constData());

                linea = 0;
                columna = 0;
                yylineno = 0;

                if(yyparse()==0) // Si nos da un número negativo, es error.
                {
                    //printf("\n\Comando ejecutado correctamente\n\n");

                }else {
                    cout << " >> Comando erroneo " <<endl;
                    //printf("\n\nhay errores\n\n");
                }

            }
        }

    }

    //return 0;
}
