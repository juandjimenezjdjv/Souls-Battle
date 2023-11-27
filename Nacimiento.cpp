#include "Humanidad.h"
#include <iostream>
#include <ctime>    
#include <cstdlib>
#include <algorithm>
//#include <chrono>
//#include <thread>


using namespace std;

string obtenerFechaYHora();
int Random(int inicio, int final);
void CrearAmigos(int cantidad, Humanos *Amigostmp[100], int limite, Humanos *HUMANIDAD[100000],string Pais, string profesion,string creencia,string Apellido,string ID);
void EscogerRedes(Pecado *PecadosH[7]);
void Nacimiento(Humanos *HUMANIDAD[100000], int Existencia, string Nombres[1000], string Apellidos[30], string Paises[20], string creencias[10], string profesiones[20], int Generacion);
void CrearGeneraciones(Humanos *HUMANIDAD[100000],int cantidadHumanos,string Nombres[1000], string Apellidos[30], string Paises[20], string creencias[10], string profesiones[20], int aa, int bb);
void quickSort(Pecado* arr[], int low, int high);
void swap(Pecado* a, Pecado* b);
int partition(Pecado* arr[], int low, int high);

void CrearGeneraciones(Humanos *HUMANIDAD[100000],int cantidadHumanos,string Nombres[1000], string Apellidos[30], string Paises[20], string creencias[10], string profesiones[20], int &aa, int &bb){
	
//	int EXISTENCIA = 0;
//	int GENERACION = 0;
	
	int Existencia = aa;
	int GeneracionActual = bb;
	int LimiteAmigos = aa; //ESTA VARIABLE INDICA CUANTOS HUMANOS HABIAN ANTES DE MANDAR A LLAMAR AL ALGORITMO, PRA TENER UN INDICE DE A CUAL RANGO DE HUMANOS HAY QUE CREARLES AMIGOS
	
	cout << "\n" << endl;
	for (int G = 0; G < cantidadHumanos ; G++){
		
//		std::this_thread::sleep_for(std::chrono::milliseconds(1));
//		cout << "\n" << endl;
		
		Nacimiento(HUMANIDAD,Existencia,Nombres,Apellidos,Paises,creencias,profesiones,GeneracionActual);
		
		Existencia += 1;		
		aa += 1;
	}


	GeneracionActual += 1;
	bb += 1;

	for(int A = 0; A < cantidadHumanos; A++){
		
		Humanos *AmigosTMP[100];
		int cantidadAmigos = Random(0,100);
		for (int i = 0; i < 100; i++){
			AmigosTMP[i] =NULL;
		}
		
		string Pais = HUMANIDAD[LimiteAmigos]->Pais;
		string Profesion = HUMANIDAD[LimiteAmigos]->Profesion;
		string creencia = HUMANIDAD[LimiteAmigos]->Creencia;
		string Apellido = HUMANIDAD[LimiteAmigos]->Apellido;
		
		CrearAmigos(cantidadAmigos,AmigosTMP,Existencia,HUMANIDAD,Pais,Profesion,creencia,Apellido,HUMANIDAD[LimiteAmigos] -> ID);
		
		for (int i = 0; i < cantidadAmigos; i++){
			HUMANIDAD[LimiteAmigos] -> Amigos[i] = AmigosTMP[i];
		}
//		HUMANIDAD[LimiteAmigos] -> imprimir();
		LimiteAmigos += 1;
	}
	
//	aa = Existencia;
//	bb = GeneracionActual;
	
}




void Nacimiento(Humanos *HUMANIDAD[100000], int Existencia, string Nombres[1000], string Apellidos[30], string Paises[20], string creencias[10], string profesiones[20], int Generacion){

	string ID = to_string(Existencia);
	string Nombre = Nombres[Random(0,999)];
	string Apellido = Apellidos[Random(0,5)];//Son 30, Cambielossssss
	string Pais = Paises[Random(0,5)];//son 20 cambielos
	string creencia = creencias[Random(0,9)];//Fijese cuantos son y cambieloss
	string profesion = profesiones[Random(0,9)];//son 20 cambielos
	string FechaYHora = obtenerFechaYHora();
	char Ubicacion = 'T';
	
	Pecado *PecadosTMP[7];
	for(int i = 0; i < 7; i++) {
    	PecadosTMP[i] = new Pecado();
	}
	EscogerRedes(PecadosTMP);
	 
	Humanos *HumanoActual = new Humanos(ID,Nombre,Apellido,Pais,creencia,profesion,FechaYHora,Generacion,Ubicacion,PecadosTMP);
	HUMANIDAD[Existencia] = HumanoActual;
	//HUMANIDAD[Existencia] -> imprimir();
 
}


void CrearAmigos(int cantidad, Humanos *Amigostmp[100], int limite, Humanos *HUMANIDAD[100000],string Pais, string profesion,string creencia,string Apellido,string ID){
	
	int VecesN = 0, idx = 0;

	
	while(VecesN <= cantidad){
		
		if (idx >= limite){
			break;
		}else if((HUMANIDAD[idx]->Pais == Pais && (HUMANIDAD[idx]->Apellido == Apellido || HUMANIDAD[idx]->Creencia == creencia || HUMANIDAD[idx]->Profesion == profesion)) && HUMANIDAD[idx]->ID != ID){
			
			Amigostmp[VecesN] = HUMANIDAD[idx];
			VecesN++;	
		}
		idx++;	
	}
	
}
	static std::random_device rd;
    static std::mt19937 g(rd());

void EscogerRedes(Pecado *PecadosH[7]) {
	
	Pecado *L = new Pecado("Lujuria","Tinder",0,0);
	Pecado *G = new Pecado("Gula","iFood",0,0);
	Pecado *A = new Pecado("Avaricia","Linkedln",0,0);
	Pecado *P = new Pecado("Pereza","Netflix",0,0);
	Pecado *I = new Pecado("Ira","Twitter",0,0);
	Pecado *E = new Pecado("Envidia","Facebook",0,0);
	Pecado *S = new Pecado("Soberbia","Instagram",0,0);

	Pecado * Pecados[7] = {L,G,A,P,I,E,S};
	for(int i = 0; i < 7; i++) {
    	PecadosH[i] = Pecados[i];
	}
    // Mezclar las prioridades
    int prioridades[7] = {1, 2, 3, 4, 5, 6, 7};
    std::shuffle(prioridades, prioridades + 7, g);

    for (int i = 0; i < 7; ++i) {
        PecadosH[i]->prioridad = prioridades[i];
    }
    
    quickSort(PecadosH, 0, 6);
}

int Random(int inicio, int final) {
    static std::random_device rd; // Se mantiene el mismo generador
    static std::mt19937 gen(rd()); // Se mantiene el mismo generador
    std::uniform_int_distribution<int> distribution(inicio, final);

    return distribution(gen);
}

void swap(Pecado* a, Pecado* b) {
    Pecado temp = *a;
    *a = *b;
    *b = temp;
}

// Funci?n para dividir el arreglo y encontrar el pivote
int partition(Pecado* arr[], int low, int high) {
    int pivot = arr[high]->prioridad;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j]->prioridad < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Funci?n principal de QuickSort
void quickSort(Pecado* arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

