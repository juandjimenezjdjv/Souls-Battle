#include <iostream>
#include <cmath>
#include "Humanidad.h"
#include <vector>
#include "ArbolHumanos.h"
#include <list>

using namespace std;
string* listaArbol(Humanos *HUMANIDAD[100000], int exis, int &tamano);
int operacion_personalizada(int numero);
int * distribuir_datos(int potencia, int tamano_lista);


void generarImprimirArbol(Humanos *HUMANIDAD[100000], int exis, int &tamano){
	if (exis > 0 && exis >299){
//		cout << "AAAAAAAAAAAAaa" << endl;
		string* resultado = listaArbol(HUMANIDAD, exis, tamano);
		if (tamano+1 >299){
			int cantNodos = operacion_personalizada(tamano);
			
			int* posiciones = distribuir_datos(cantNodos, tamano);
			cout << "\nEl arbol consta de " << (log2(cantNodos+1)) << " nivel(es), del 0 al " << (log2(cantNodos+1)-1) << "." << endl;
			cout << "El arbol consta de " << cantNodos << " nodo(s)." << endl;
			cout << "La cantidad de humanos en la tierra es: " << tamano+1 << endl;
			string* datosTemp = new string[cantNodos];
		    
		    int j = 0;
		    for (int i = 0; i < tamano; i++) {
		    	if (posiciones[j]==i){
		    		datosTemp[j] = resultado[i];
		    		j++;
				}
		    }
		    
		    for (int i = 0; i < cantNodos; i++) {
		        resultado[i] = datosTemp[i];
		    }
		    delete[] datosTemp;
		    Nodo* hola = construir_ABB(resultado, 0, cantNodos-1);
		    cout << "\nArbol (Inorden): " << endl;
			imprimir_inorden(hola);
			cout << "\nArbol (Preorden): " << endl;
			imprimir_preorden(hola);
			cout << "\n\nNodos del ultimo nivel: " << endl;
			std::list<string> hojas;
			obtenerHojas(hola, hojas);
			for (string valor : hojas){
				std::cout << valor << " ";
			}
			cout << "\n\nDatos del ultimo nivel: " << endl;
			for (const std::string& hoja : hojas){
				for (int i = 0; i < exis; i++){
					if (hoja==HUMANIDAD[i]->ID){
						HUMANIDAD[i]->imprimir();
					}
				}
			}
		}
		
	}else {
		cout << "Hay menos de 299 humanos en la tierra por lo que no\nhay suficientes datos para sacar el 1% para hacer el arbol." << endl;
	}
	
}


int operacion_personalizada(int numero) {//define la cantidad de nodos del arbol
    numero = numero * 0.01;
    int resultado = pow(2, ceil(log2(numero)));
    return resultado-1;
}

int * distribuir_datos(int potencia, int tamano_lista) {
    int paso = tamano_lista / potencia;
    int* posis = new int[tamano_lista];
    for (int i = paso / 2, j = 0; i < tamano_lista; i += paso, j++) {
        posis[j] = i;
    }
    return posis;
}

string* listaArbol(Humanos *HUMANIDAD[100000], int exis, int &tamano){
	string* listaPosiciones = new string[exis];
	int cont=0;
	for (int i = 0; i < exis; i++){
		if (HUMANIDAD[i]->Ubicacion == 'T'){
			listaPosiciones[cont] = HUMANIDAD[i]->ID;
			cont++;
		}
	}
	string* listafinal = new string[cont-1];
	for (int j = 0; j < cont-1; j++){
		listafinal[j] = listaPosiciones[j];
	}
	
	tamano = cont-1;
	delete[] listaPosiciones;
	return listafinal;
}







