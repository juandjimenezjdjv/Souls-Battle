#include "Humanidad.h"

using namespace std;

void PublicacionPorReligion(Humanos *HUMANIDAD[100000],string Religion,int EXISTENCIA);
void PublicacionIndividual(Humanos *HUMANIDAD[100000], int ID, string red);
void PublicacionPorFamilia(Humanos *HUMANIDAD[100000], string Apellido,string Pais,int EXISTENCIA, int NRedes);
void PublicacionPorProfesion(Humanos *HUMANIDAD[100000], string Profesion, int EXISTENCIA, int NRedes);


void PublicacionIndividual(Humanos *HUMANIDAD[100000], int ID, string red){
	
	Humanos *HumanoActual = HUMANIDAD[ID];
	
	for(int i = 0; i < 100; i++){
		
		if (HumanoActual -> Amigos[i] != NULL){
			Humanos *Victima = HumanoActual -> Amigos[i];
			for(int j = 0; j < 7; j++){
				if(Victima -> PecadosH[j] -> red == red){
					Victima -> PecadosH[j] -> cantidad = Victima -> PecadosH[j] -> cantidad + Victima -> PecadosH[j] -> prioridad;
				}
			}
		}else{
			break;
		}
		
		
	}
	
	
}


void PublicacionPorReligion(Humanos *HUMANIDAD[100000],string Religion,int EXISTENCIA){
	
	for (int i = 0; i < EXISTENCIA; i++){
		
		if (HUMANIDAD[i] -> Creencia == Religion){
			string red = HUMANIDAD[i] -> PecadosH[0] -> red;
			PublicacionIndividual(HUMANIDAD,i,red);
		}
	}
	
}

void PublicacionPorProfesion(Humanos *HUMANIDAD[100000], string Profesion, int EXISTENCIA, int NRedes){
	
	
	for (int i = 0; i < EXISTENCIA; i++){
		
		if (HUMANIDAD[i] -> Profesion == Profesion){
			
			for(int j = 0; j < NRedes; j++){
				
				string red = HUMANIDAD[i] -> PecadosH[j] -> red;
				PublicacionIndividual(HUMANIDAD,i,red);
			
			}
			
		}
	}
	
}

void PublicacionPorFamilia(Humanos *HUMANIDAD[100000], string Apellido,string Pais,int EXISTENCIA, int NRedes){
	
	
	for (int i = 0; i < EXISTENCIA; i++){
		
		if (HUMANIDAD[i] -> Apellido == Apellido && HUMANIDAD[i] -> Pais == Pais){
			
			for(int j = 0; j < NRedes; j++){
				
				string red = HUMANIDAD[i] -> PecadosH[j] -> red;
				PublicacionIndividual(HUMANIDAD,i,red);
			
			}
			
		}
	}
	
}



