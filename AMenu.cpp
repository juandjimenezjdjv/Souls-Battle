//#include "AVL.h"
#include "Humanidad.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

extern int EXISTENCIA = 0;
extern int GENERACION = 0;
int enteros();

void EscogerRedes(Pecado *PecadosArray[7], Pecado *PecadosH[7]);
int Random(int inicio, int final);
void CrearGeneraciones(Humanos *HUMANIDAD[100000],int cantidadHumanos,string Nombres[1000], string Apellidos[30], string Paises[20], string creencias[10], string profesiones[20], int &aa, int &bb);
void LeerNombres(string nombreArchivo, string Nombres[1000]);
void LeerApellidos(string nombreArchivo, string Apellidos[30]);
void LeerProfesiones(string nombreArchivo, string Profesiones[20]); 
void Leercreencias(string nombreArchivo, string Creencias[10]);
void LeerPais(string nombreArchivo, string Paises[20]);
void generarImprimirArbol(Humanos *HUMANIDAD[100000], int exis, int &tamano);

void PublicacionPorReligion(Humanos *HUMANIDAD[100000],string Religion,int EXISTENCIA);
void PublicacionIndividual(Humanos *HUMANIDAD[100000], int ID, string red);
void PublicacionPorFamilia(Humanos *HUMANIDAD[100000], string Apellido,string Pais,int EXISTENCIA, int NRedes);
void PublicacionPorProfesion(Humanos *HUMANIDAD[100000], string Profesion, int EXISTENCIA, int NRedes);
int Condenacion(Demonios *DEMONIOS7[7],Humanos *HUMANIDAD[100000], int EXISTENCIA, string Demonio,string Pecado,int CondenacionID);

void crearArchivoEnCarpeta(const string& nombreCarpeta, const string& nombreArchivo, const string& contenido);
int Salvacion(Humanos *HUMANIDAD[100000],int EXISTENCIA,CieloAngeles *ANGELES3, Demonios *DEMONIOS7[7], string AngelesNombres[10],AVLTree *HashAvl[1000]);

void menu2(Demonios *DEMONIOS7[7]);




void menu () {
	int id = 0;
	int CondenacionID = 0;
	
	int CondenacionCantidad = 0;
	int ExistenciaInfierno = 0;
	int ExistenciaCielo = 0;
	int CantidadSalvacion = 0;
	
	string ID = "";
	string redtmpp = "";
	string religion = "";
	string profesion = "";
	string Pais = "";
	string Apellido ="";
	string Demonio = "";
	string Pecado = "";
	int NredesF = 0;
	int NredesP = 0;
	int nada = 0;
	int opcion= -1;
	int crearper = 0;
	Humanos *HUMANIDAD[100000];

	
	for(int i = 0; i < 100000; i++){
		
		HUMANIDAD[i] = NULL;
		
	}
	
	string NOMBRES[1000];
	string APELLIDOS[30];
	string PROFESIONES[20];
	string CREENCIAS[10];
	string PAISES[20];
	string NOMBRESANGELES[10] = {"Miguel","Nuriel","Aniel","Rafael","Gabriel","Shamsiel","Raguel","Uriel","Azrael","Sariel"};
	
	AVLTree *HashAvl[1000];
	for(int i = 0; i < 1000; i++){
		HashAvl[i] = NULL;	
	}
	
	Demonios * Lucifer = new Demonios("Lucifer","Soberbia");
	Demonios * Belcebu = new Demonios("Belcebu","Envidia");
	Demonios * Satan = new Demonios("Satan","Ira");
	Demonios * Abadon = new Demonios("Abadon","Pereza");
	Demonios * Mammon = new Demonios("Mammon","Avaricia");
	Demonios * Belfegor = new Demonios("Belfegor","Gula");
	Demonios * Asmodeo = new Demonios("Asmodeo","Lujuria");
		
	Demonios *DEMONIOS7[7] = {Lucifer,Belcebu,Satan,Abadon,Mammon,Belfegor,Asmodeo};

	CieloAngeles *ANGELES3 = new CieloAngeles();
	
	Angel * ELDIOS = new Angel("El Dios",NULL,0,0);
	Angel * Serafin = new Angel("Serafin",NULL,0,0);
	Angel * Querubine = new Angel("Querubine",NULL,0,0);
	Angel * Trono = new Angel("Trono",NULL,0,0);
	ANGELES3 -> Niveles += 1;
	
	ANGELES3 -> ArbolTriaArio[0] = ELDIOS;
	ANGELES3 -> ArbolTriaArio[1] = Serafin;
	ANGELES3 -> ArbolTriaArio[2] = Querubine;
	ANGELES3 -> ArbolTriaArio[3] = Trono;
	
	ANGELES3 -> AngelesExistencia += 4;

	LeerNombres("nombres.txt",NOMBRES);
	LeerApellidos("apellidos.txt",APELLIDOS);
	LeerProfesiones("profesiones.txt",PROFESIONES);
	Leercreencias("creencias.txt",CREENCIAS);
	LeerPais("paises.txt",PAISES);
	
	do{
		cout << "-----BATALLA POR LAS ALMAS----" << endl;
		cout << "\t.:Menu:." << endl;
		cout << "  1. Crear personas" << endl;
		cout << "  2. Imprimir arreglo de humanos" << endl;
		cout << "  3. Imprimir Arbol de vida y datos." << endl;
		cout << "  4. Publicacion individual en Redes" << endl;
		cout << "  5. Publicacion por religion en Redes" << endl;
		cout << "  6. Publicacion por profesion en Redes" << endl;
		cout << "  7. Publicacion por familia en Redes" << endl;
		cout << "  8. **CONDENACION** " << endl;
		cout << "  9. Consultar el infierno" << endl;	
		cout << "  10. ~~ SALVACION ~~" << endl;
		cout << "  11. Mostrar el Cielo " << endl; 
		cout << "  12. Quien tiene mas almas?? " << endl;
		cout << "  13.  Buscar por ID " << endl;
		cout << "  14.  Buscar Familia " << endl;
		cout << "  15. Salir. " << endl;
		cout << "Digite la opcion deseada: ";	

		opcion = enteros();
		if (opcion == -1) {
			cout << "Digite un numero correcto." << endl;
			system("pause");
		}
		
		switch(opcion){
			case 1:
				cout << "Cuantas personas desea crear:";
				crearper = enteros();
				if (crearper > 0)
				CrearGeneraciones(HUMANIDAD,crearper,NOMBRES,APELLIDOS,PAISES,CREENCIAS,PROFESIONES, EXISTENCIA, GENERACION);
				else cout << "Debe crear como minimo una persona." << endl;
				cout<<"\n";
				system("pause");
				break;
				
			case 2:
				for (int i = 0; i < EXISTENCIA; i++) {
					if(HUMANIDAD[i]->Ubicacion =='T'){
						HUMANIDAD[i]->imprimir();
					}
			    }
				cout<<"\n";
				system("pause");
				break;
				
			case 3:
				generarImprimirArbol(HUMANIDAD, EXISTENCIA, nada);
				cout<<"\n";
				system("pause");
				break;

			case 4:
				cout << "Ingrese el ID de la persona que va a publicar en Redes" << endl;
				cin >> id;
				cout << "Ingrese el nombre de la red social en la cual hacer la publicacion" << endl;
				cin >> redtmpp;
				PublicacionIndividual(HUMANIDAD,id,redtmpp);
				cout << "Esta publicacion hizo pecar a las siguientes personas : "<< endl;
				
				for (int i = 0; i < 100; i++){
					if (HUMANIDAD[id] -> Amigos[i] != NULL){
						HUMANIDAD[id] -> Amigos[i] -> imprimir2();
					}else{
						break;
					}	
				}
				
				cout<<"\n";
				system("pause");
				break;

			case 5:
				cout << "Ingrese la religion de las personas que van a publicar " << endl; 
				cin >> religion;
				PublicacionPorReligion(HUMANIDAD,religion,EXISTENCIA);
				cout<<"\n";
				system("pause");
				break;
				
			case 6:
				cout << "Ingrese la Profesion de las personas que van a publicar " << endl;
				cin >> profesion;
				cout << "Ingrese en la cantidad de redes que va a publicar(1-7)"<< endl;
				cin >> NredesP;
				PublicacionPorProfesion(HUMANIDAD,profesion,EXISTENCIA,NredesP);
				cout<<"\n";
				system("pause");
				break;
				
			case 7:
				
				cout << "Ingrese el Pais de la familia" << endl;
				cin >> Pais;
				cout << "Ingrese el apellido de la familia"<< endl;
				cin >> Apellido;
				cout << "Ingrese en la cantidad de redes que van a publicar(1-7)"<< endl;
				cin >> NredesF;
				PublicacionPorFamilia(HUMANIDAD,Apellido,Pais,EXISTENCIA,NredesF);
				cout<<"\n";
				system("pause");
				break;
				
			case 8:
				
				cout << "Ingrese el nombre del demonio" << endl;
				cin >> Demonio;
				cout << "Ingrese el Pecado del demonio"<< endl;
				cin >> Pecado;
				CondenacionCantidad = Condenacion(DEMONIOS7,HUMANIDAD,EXISTENCIA,Demonio,Pecado,CondenacionID);
				//EXISTENCIA = EXISTENCIA - CondenacionCantidad;
				ExistenciaInfierno += CondenacionCantidad;
				CondenacionCantidad = 0;
				CondenacionID += 1;
				cout<<"\n";
				system("pause");
				break;
				
			case 9:
				menu2(DEMONIOS7);
				break;
			
			case 10:
				
				CantidadSalvacion = Salvacion(HUMANIDAD,EXISTENCIA,ANGELES3,DEMONIOS7,NOMBRESANGELES,HashAvl);
				ExistenciaInfierno -= CantidadSalvacion;
				ExistenciaCielo += CantidadSalvacion;
				cout << "Se realizo correctamente la salvacion de " << CantidadSalvacion << endl; 
				CantidadSalvacion = 0;
				cout<<"\n";
				system("pause");
				break;
			
			case 11:
				
				ANGELES3 -> imprimir();

				cout<<"\n";
				system("pause");
				break;	
				
			case 12: 
			
			if(ExistenciaCielo > ExistenciaInfierno){
				cout << "El cielo tiene mas almas por lo tanto, de momento gana el cielo...\n\n";
			}else if(ExistenciaInfierno > ExistenciaCielo){
				cout << "El infierno tiene mas almas por lo tanto, de momento gana el infierno...\n\n";
			}
			
				cout<<"\n";
				system("pause");
				break;
			
			case 13:
				cout << "Ingrese el ID de la persona a buscar " << endl;
				cin >> ID;
			
				for(int i = 0; i < EXISTENCIA; i++){
					if(HUMANIDAD[i] != NULL && HUMANIDAD[i] -> ID == ID) {
						HUMANIDAD[i] -> imprimir();
						break;	
					}
					
				}
				
				cout<<"\n";
				system("pause");
				break;
				
			case 14:
				
				cout << "Ingrese el Pais de la familia a buscar " << endl;
				cin >> Pais;
				cout << "Ingrese el Apellido de la familia a buscar " << endl;
				cin >> Apellido;
				
				for(int i = 0; i < EXISTENCIA; i++){
					if(HUMANIDAD[i] != NULL && (HUMANIDAD[i] -> Pais == Pais && HUMANIDAD[i] -> Apellido == Apellido)) {
						HUMANIDAD[i] -> imprimir();
						break;	
					}
					
				}
				
				cout<<"\n";
				system("pause");
				break;
		}
		system("cls");
	}while(opcion != 15);
}


void menu2(Demonios *DEMONIOS7[7]) {


	int opcion= -1;
	
	string Consulta0 = "";
	string Consulta1 = "";
	string Consulta2 = "";
	string Consulta3 = "";
	string Consulta4 = "";
	string Consulta5 = "";
	string Consulta6 = "";
	

	do{

		cout << "\t.:Consultas del INFIERNO :." << endl;
		cout << "  1. == LUCIFER ==" << endl;
		cout << "  2. .: BELCEBU :. " << endl;
		cout << "  3. ~~ SATAN ~~ " << endl;
		cout << "  4. ++ ABADON ++ " << endl;
		cout << "  5. {[ MAMMON ]} " << endl;
		cout << "  6. ** BELFEGOR ** " << endl;
		cout << "  7. $$ ASMODEO $$ " << endl;
		cout << "  8. --------------------------- " << endl;
		cout << "  9. ----------------------------" << endl;	
		cout << "  13. Salir. " << endl;
		cout << "Digite la opcion deseada: ";	
		
		opcion = enteros();
		if (opcion == -1) {
			cout << "Digite un numero correcto." << endl;
			system("pause");
		}
		
		switch(opcion){
			case 1:
				//DEMONIOS7[0] -> imprimir();
				cout << "\nSe creo en la carpeta InfiernoInfo el archivo con nombre LUCIFER con la informacion del demonio\n";
				Consulta0 = DEMONIOS7[0] -> Consulta(Consulta0);
				crearArchivoEnCarpeta("InfiernoInfo","LUCIFER",Consulta0);
				//Consulta0 = "";
				cout<<"\n";
				system("pause");
				break;
				
			case 2:
				//DEMONIOS7[1] -> imprimir();
				cout << "\nSe creo en la carpeta InfiernoInfo el archivo con nombre BELCEBU con la informacion del demonio\n";
				Consulta1 = DEMONIOS7[1] -> Consulta(Consulta1);
				crearArchivoEnCarpeta("InfiernoInfo","BELCEBU",Consulta1);
				cout<<"\n";
				system("pause");
				break;
				
			case 3:
				
				cout << "\nSe creo en la carpeta InfiernoInfo el archivo con nombre SATAN con la informacion del demonio\n";
				Consulta2 = DEMONIOS7[2] -> Consulta(Consulta2);
				crearArchivoEnCarpeta("InfiernoInfo","SATAN",Consulta2);
				cout<<"\n";
				system("pause");
				break;

			case 4:
				cout << "\nSe creo en la carpeta InfiernoInfo el archivo con nombre ABADON con la informacion del demonio\n";
				Consulta3 = DEMONIOS7[3] -> Consulta(Consulta3);
				crearArchivoEnCarpeta("InfiernoInfo","ABADON",Consulta3);
				cout<<"\n";
				system("pause");
				break;
				
			case 5:
				
				cout << "\nSe creo en la carpeta InfiernoInfo el archivo con nombre MAMMON con la informacion del demonio\n";
				Consulta4 = DEMONIOS7[4] -> Consulta(Consulta4);
				crearArchivoEnCarpeta("InfiernoInfo","MAMMON",Consulta4);
				cout<<"\n";
				system("pause");
				break;
				
			case 6:
				
				cout << "\nSe creo en la carpeta InfiernoInfo el archivo con nombre BELFEGOR con la informacion del demonio\n";
				Consulta5 = DEMONIOS7[5] -> Consulta(Consulta5);
				crearArchivoEnCarpeta("InfiernoInfo","BELFEGOR",Consulta5);
				cout<<"\n";
				system("pause");
				break;
				
			case 7:
 				cout << "\nSe creo en la carpeta InfiernoInfo el archivo con nombre ASMODEO con la informacion del demonio\n";
				Consulta6 = DEMONIOS7[6] -> Consulta(Consulta6);
				crearArchivoEnCarpeta("InfiernoInfo","ASMODEO",Consulta6);
				cout<<"\n";
				system("pause");
				break;
				
			case 8:
				
				cout<<"\n";
				system("pause");
				break;
				
			case 9:
				
				cout<<"\n";
				system("pause");
				break;
			
			
		}
		system("cls");
	}while(opcion != 13);
}



