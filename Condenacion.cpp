#include "Humanidad.h"

using namespace std;

string obtenerFechaYHora(); 
int Condenacion(Demonios *DEMONIOS7[7],Humanos *HUMANIDAD[100000], int EXISTENCIA, string Demonio,string Pecado,int CondenacionID);
void heapSort(Humanos* arr[], int size, string pecado);
void heapify(Humanos* arr[], int size, int root, string pecado);
void swap(Humanos*& a, Humanos*& b);
void crearArchivoEnCarpeta(const string& nombreCarpeta, const string& nombreArchivo, const string& contenido);

void swap(Humanos*& a, Humanos*& b) {
    Humanos* temp = a;
    a = b;
    b = temp;
}

// Función para realizar el heapify ascendente en el subárbol con raíz en el índice 'root'
void heapify(Humanos* arr[], int size, int root, string pecado) {
    int min = root; // Inicializar el índice más pequeño como la raíz
    int left = 2 * root + 1; // Índice del hijo izquierdo
    int right = 2 * root + 2; // Índice del hijo derecho

    // Comparar con el hijo izquierdo
    if (left < size && arr[left]->BuscarPecado(pecado)->cantidad < arr[min]->BuscarPecado(pecado)->cantidad)
        min = left;

    // Comparar con el hijo derecho
    if (right < size && arr[right]->BuscarPecado(pecado)->cantidad < arr[min]->BuscarPecado(pecado)->cantidad)
        min = right;

    // Si el índice más pequeño no es la raíz, intercambiar y hacer heapify en el subárbol afectado
    if (min != root) {
        swap(arr[root], arr[min]);
        heapify(arr, size, min, pecado);
    }
}

// Función principal para realizar el heapsort
void heapSort(Humanos* arr[], int size, string pecado) {
    // Construir un min heap cambiando la dirección de la comparación
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i, pecado);
    }

    // Extraer elementos uno por uno desde el heap en orden ascendente
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, pecado);
    }
}


int Condenacion(Demonios *DEMONIOS7[7],Humanos *HUMANIDAD[100000], int EXISTENCIA, string Demonio,string Pecado,int CondenacionID){
	
	string BitacoraCondenacion = "";
	string NombreArchivo = "";
	int CincoPorciento = EXISTENCIA * 0.05;
	int contador = 0;
	Humanos *Muertes[CincoPorciento];
	for(int i = 0; i < CincoPorciento; i++){
		Muertes[i] = NULL;
	}
	
	for (int i = 0; i < EXISTENCIA; i++){
		
		if (HUMANIDAD[i]-> Ubicacion == 'T'){
			
			if (Muertes[contador] == NULL){//CAMBIARRR LA UBICACION DE LOS HUMANOS HASTA AHORA MAS ABAJOOOO
			
				Muertes[contador] = HUMANIDAD[i];
				contador++;
				
			}else{
				//cout << "ENTRA : " << i << endl;
				for (int j = 0; j < contador;j++){
					//cout << Muertes[j]->BuscarPecado(Pecado) -> cantidad << "MAYOR A " << HUMANIDAD[i]->BuscarPecado(Pecado) -> cantidad << endl;
					int CantidadEnMuertes = Muertes[j] -> BuscarPecado(Pecado)-> cantidad;
					int CantidadEnHumanidad = HUMANIDAD[i] -> BuscarPecado(Pecado)-> cantidad;
				
					if ( CantidadEnMuertes < CantidadEnHumanidad ){

						Muertes[j] = HUMANIDAD[i];
						break;
					}
				}
			}
		
		if(contador > CincoPorciento){
				contador = 0;	
			
		}
	}
}
 
	
	
	for (int i = 0; i < CincoPorciento; i++) {
	    if (Muertes[i] != NULL) {
	        Muertes[i]->FechaYHoraMuerte = obtenerFechaYHora();
	        Muertes[i]->Ubicacion = 'I';
	    }
	}

	
	BitacoraCondenacion = BitacoraCondenacion + "El demonio " + Demonio + " tomo "  + to_string(CincoPorciento) + " almas, aca está la informacion detallada: \n";
	
	for(int d = 0; d < CincoPorciento; d++) {
		int prueba = Muertes[d] -> BuscarPecado(Pecado)-> cantidad;		
	    BitacoraCondenacion = BitacoraCondenacion + Muertes[d]->FechaYHora + "  " + "ID :" + Muertes[d]->ID + " " + Muertes[d]->Nombre + " Pais : " + Muertes[d]->Pais + "\n";
	    BitacoraCondenacion = BitacoraCondenacion + "Murio : " + Muertes[d]->FechaYHoraMuerte  + " Condenado por " + to_string(prueba) + " pecados de la " + Pecado + " por el demonio " + Demonio + "\n\n";
	
	}


//	cout << "Aqui esta muertes sin ordenar\n";
//	for(int k = 0; k < CincoPorciento; k++){
//		Muertes[k] -> imprimir2();
//	}
//	heapSort(Muertes,CincoPorciento,Pecado);
//	cout << "\nAqui esta muertes ordenado\n";
//	for(int k = 0; k < CincoPorciento; k++){
//		Muertes[k] -> imprimir2();
//	}
	
	Demonios *DemonioActual = new Demonios();
	for (int i = 0; i < 7; i++){
		if(DEMONIOS7[i] -> Nombre == Demonio){
			DemonioActual = DEMONIOS7[i];
		}
	}
 	
	for (int i = 0; i < CincoPorciento; i++){
		
		Heaps * tmp = DemonioActual -> ListaDeHeaps -> primerNodo;
		
		bool bandera = false;
		while(tmp != NULL){
			
			if(tmp -> Familia == Muertes[i] -> Apellido && tmp -> Pais == Muertes[i] -> Pais ){
				tmp -> FamiliaActual[tmp -> ExistenciaFamilia] = Muertes[i];
				tmp -> ExistenciaFamilia = tmp -> ExistenciaFamilia + 1;
				bandera = true;
				heapSort(tmp->FamiliaActual,tmp -> ExistenciaFamilia,Pecado);
				break;
			}
			
			tmp = tmp -> siguiente;
		}
		if(bandera == false){
			
			DemonioActual -> ListaDeHeaps -> InsertarAlInicio(Muertes[i] -> Apellido,Muertes[i]->Pais);
			Heaps * tmp2 = DemonioActual -> ListaDeHeaps -> primerNodo;
			tmp2 -> FamiliaActual[tmp2 -> ExistenciaFamilia] = Muertes[i];
			tmp2 -> ExistenciaFamilia = tmp2 -> ExistenciaFamilia + 1;
			heapSort(tmp2->FamiliaActual,tmp2 -> ExistenciaFamilia,Pecado);
			
		}
		
	}
	
	NombreArchivo = "BitacoraCondenacion_" + to_string(CondenacionID);
	crearArchivoEnCarpeta("BitacoraCondenacion",NombreArchivo,BitacoraCondenacion);

	return CincoPorciento;
}
 

