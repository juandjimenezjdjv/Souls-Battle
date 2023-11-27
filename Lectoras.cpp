#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int enteros2(string entero);
void LeerNombres(string nombreArchivo, string Nombres[1000]);
void LeerApellidos(string nombreArchivo, string Apellidos[30]);
void LeerProfesiones(string nombreArchivo, string Profesiones[20]); 
void Leercreencias(string nombreArchivo, string Creencias[10]);
void LeerPais(string nombreArchivo, string Paises[20]);


void LeerNombres(string nombreArchivo, string Nombres[1000]) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        int contador = 0;

        while (getline(archivo, linea) && contador < 1000) {
            Nombres[contador] = linea;
            contador++;
        }

        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
}



void LeerApellidos(string nombreArchivo, string Apellidos[30]) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        int contador = 0;

        while (getline(archivo, linea) && contador < 30) {
            Apellidos[contador] = linea;
            contador++;
        }

        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
}


void LeerPais(string nombreArchivo, string Paises[20]) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        int contador = 0;

        while (getline(archivo, linea) && contador < 20) {
            Paises[contador] = linea;
            contador++;
        }

        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
}


void Leercreencias(string nombreArchivo, string Creencias[10]) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        int contador = 0;

        while (getline(archivo, linea) && contador < 10) {
            Creencias[contador] = linea;
            contador++;
        }

        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
}

void LeerProfesiones(string nombreArchivo, string Profesiones[20]) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        int contador = 0;

        while (getline(archivo, linea) && contador < 20) {
            Profesiones[contador] = linea;
            contador++;
        }

        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
}
