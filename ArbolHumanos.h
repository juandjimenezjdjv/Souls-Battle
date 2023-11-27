#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct Nodo {
    string valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(string v) : valor(v), izquierda(NULL), derecha(NULL) {} 
};

	Nodo* construir_ABB(string arr[], int inicio, int fin) {
	    if (inicio > fin) {
	        return NULL;
	    }
	    int medio = (inicio + fin) / 2;
	    Nodo* nodo = new Nodo(arr[medio]);
	
	    nodo->izquierda = construir_ABB(arr, inicio, medio - 1);
	    nodo->derecha = construir_ABB(arr, medio + 1, fin);
	
	    return nodo;
	}
	
	
	void imprimir_inorden(Nodo* nodo) {
		
	    if (nodo == NULL) {
	        return;
	    }
	    imprimir_inorden(nodo->izquierda);
	    std::cout << nodo->valor << " ";
	    imprimir_inorden(nodo->derecha);
	}
	
	void imprimir_preorden(Nodo* nodo) {
	    if (nodo != NULL) {
	        cout << nodo->valor << " ";
	        imprimir_preorden(nodo->izquierda);
	        imprimir_preorden(nodo->derecha);
	    }
	}
	
	void obtenerHojas(Nodo* nodo, std::list<string>& hojas) {
	    if (nodo == NULL) {
	        return;
	    }
	    if (nodo->izquierda == NULL && nodo->derecha == NULL) {
	        hojas.push_back(nodo->valor);
	    } else {
	        obtenerHojas(nodo->izquierda, hojas);
	        obtenerHojas(nodo->derecha, hojas);
	    }
	}

