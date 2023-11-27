#include <iostream>
#include <fstream>
#include <string>
//#include <filesystem>  // Asegúrate de usar un compilador que admita C++17 para std::filesystem

using namespace std;

void crearArchivoEnCarpeta(const string& nombreCarpeta, const string& nombreArchivo, const string& contenido){
    // Combinar la carpeta y el nombre del archivo para obtener la ruta completa
    string rutaCompleta = nombreCarpeta + "/" + nombreArchivo;

    // Crear el archivo en la carpeta especificada
    ofstream archivo(rutaCompleta);

    // Verificar si se pudo abrir correctamente el archivo
    if (archivo.is_open()) {
        // Escribir el contenido en el archivo
        archivo << contenido;

        // Cerrar el archivo después de escribir
        archivo.close();

        //cout << "Archivo creado exitosamente en: " << rutaCompleta << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}


