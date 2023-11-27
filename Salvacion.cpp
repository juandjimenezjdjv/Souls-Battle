#include "Humanidad.h"
//#include "AVL.h"

using namespace std;
int enteros2(string entero);


int Random(int inicio, int final);

int Salvacion(Humanos *HUMANIDAD[100000],int EXISTENCIA,CieloAngeles *ANGELES3, Demonios *DEMONIOS7[7], string AngelesNombres[10],AVLTree *HashAvl[1000]){
	
	int NuevosA = 1;
	int HumanosEnInfierno = 0;

	
	
	Pecado *L = new Pecado("Lujuria","Tinder",0,0);
	Pecado *G = new Pecado("Gula","iFood",0,0);
	Pecado *A = new Pecado("Avaricia","Linkedln",0,0);
	Pecado *P = new Pecado("Pereza","Netflix",0,0);
	Pecado *I = new Pecado("Ira","Twitter",0,0);
	Pecado *E = new Pecado("Envidia","Facebook",0,0);
	Pecado *S = new Pecado("Soberbia","Instagram",0,0);
	Pecado * PecadosEnCero[7] = {L,G,A,P,I,E,S};
	
	for(int i = 0; i <= ANGELES3->Niveles; i++){
		
		NuevosA *= 3; 
		
	}
	
	for(int i = 0; i < 7; i++){
		
		HumanosEnInfierno += DEMONIOS7[i] -> TotalHumanos(0);
		
	}
	
	
	string NombresVersion[NuevosA];
	int ExNombres = 0;
	
	Angel *ArrayNuevosA[NuevosA];
	int ArrayEx = 0;
		
	for (int i = 0; i < NuevosA; i++){
		NombresVersion[i] = "";
	}
	
	
	for(int i = 0; i < NuevosA; i++){
		ArrayNuevosA[i] = new Angel();
	}
	
	if(HumanosEnInfierno >= NuevosA){
		
		for (int i = 0; i < NuevosA; i++){
			
			string _Nombre = AngelesNombres[Random(0,9)];
			int Version = 0;
			NombresVersion[ExNombres] = _Nombre;
			for(int j = 0; j < ExNombres; j++){
				if(NombresVersion[j] == _Nombre){	
					Version += 1;
				}
			}
			ExNombres += 1;
			int Generacion = ANGELES3 -> Niveles;
			//AQUI BUSCAR AL HUMANO PARA PODER CREAR EL OBJETO Y LUEGO METERLO AL ARREGLO DE ANGELES3 Y AUMENTARELCONTADOR DE ANGELES
			
			Humanos *Pecador = new Humanos("Null","Null","Null","Null","Null","Null","Null",0,'I',PecadosEnCero);
			
			for(int j = 0; j < 7; j++){
				
				if(Pecador -> TotalPecados(0) < DEMONIOS7[j] -> MasPecador(Pecador) -> TotalPecados(0)){
					Pecador = DEMONIOS7[j] -> MasPecador(Pecador);
				}
				
			}
			
			
			Angel *AngelActual = new Angel(_Nombre,Pecador,Generacion,Version);
			Pecador -> Ubicacion = 'C';
			Pecador -> AngelSalvador = AngelActual;
			
			ANGELES3 -> ArbolTriaArio[ANGELES3 -> AngelesExistencia] = AngelActual;
			ANGELES3 -> AngelesExistencia = ANGELES3 -> AngelesExistencia + 1;
			
			int _ID_ = enteros2(Pecador -> ID);
			int idx = _ID_ % 1000;
			//cout << idx << endl;
//			TreeNode *node = new TreeNode(Pecador);
//			HashAvl[idx] -> insert(HashAvl[idx] -> root, node);
			
			
		}
		ANGELES3 -> Niveles = ANGELES3 -> Niveles + 1;

		return NuevosA;
	}else{
		cout << "No hay suficientes humanos en el infierno para salvar\n";
		return 0;
	}
	
	//SI TODO SALE BIEN "SUMARLE" UN NIVEL MAS AL ARBOL DE ANGELES
	//Agregarle a los humanos el puntero para el angel
	// Crear el arreglo de angeles e insertar todos los nuevos angeles
	//Luego crear el Hashhhh
	return 0;
}
