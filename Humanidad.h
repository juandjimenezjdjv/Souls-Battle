#include <iostream>
#include <string>
//#include<stdio.h>
//#include<stdlib.h>


using namespace std;

struct Pecado;
struct Humanos;
struct Heaps;
struct ListaDeHeaps;
struct Demonios;
struct Angel;

struct Pecado{
	
	string Nombre, red;
	int cantidad, prioridad;
	
	Pecado(){
	
		Nombre = "";
		red = "";
		cantidad = 0;
		prioridad = 0;
	
	}
	
	Pecado(string _Nombre, string _red,  int _cantidad, int _prioridad){
	
		Nombre = _Nombre;
		red = _red;
		cantidad = _cantidad;
		prioridad = _prioridad;
	
	}
	
	void imprimir(){
		
		cout << "| Nombre : " << Nombre << "| Red : " << red << "| Cantidad : " << cantidad << "| Prioridad : " << prioridad << " |" << endl;
		
	}
	string Consulta(string _Consulta){
		
		//string _Consulta = "";
		_Consulta = "| Nombre : " + Nombre + "| Red : " + red + "| Cantidad : " + to_string(cantidad) + "| Prioridad : " + to_string(prioridad) + " |\n";
		return _Consulta;
	}
	
};

struct Humanos {
	
    string ID, Nombre, Apellido, Pais, Creencia, Profesion, Correo, FechaYHora,FechaYHoraMuerte;
    char Ubicacion;
    int Generacion;
    Pecado *PecadosH[7];
    Humanos *Amigos[100];  
	Angel *AngelSalvador; 

    Humanos() : Ubicacion('\0') {
        ID = "";
        Nombre = "";
        Apellido = "";
        Pais = "";
        Creencia = "";
        Profesion = "";
        FechaYHora = "";
        FechaYHoraMuerte = "";
        Generacion = 0;
 
        for (int i = 0; i < 7; ++i) {
            PecadosH[i] = NULL;   
        }
        for (int i = 0; i < 100; ++i) {
            Amigos[i] = NULL;   
        }
        AngelSalvador = NULL;

    }

    // Constructor con parámetros
    Humanos( string _ID,  string _Nombre,  string _Apellido,  string _Pais,  string _Creencia,  string _Profesion,
            string _FechaYHora,  int _Generacion,
            char _Ubicacion, Pecado *_PecadosH[7]) : Ubicacion(_Ubicacion) {
        ID = _ID;
        Nombre = _Nombre;
        Apellido = _Apellido;
        Pais = _Pais;
        Creencia = _Creencia;
        Profesion = _Profesion;
        FechaYHora = _FechaYHora;
        Generacion = _Generacion;
        FechaYHoraMuerte = "";
        for (int i = 0; i < 7; ++i){
            PecadosH[i] = _PecadosH[i];
        }
        for (int i = 0; i < 100; ++i) {
            Amigos[i] = NULL;   
        }
        AngelSalvador = NULL;
    }
    
    
    void imprimir() {
    	
        cout << "ID: " << ID << "\n"
                << "Nombre: " << Nombre << "\n"
                << "Apellido: " << Apellido << "\n"
                << "Pais: " << Pais << "\n"
                << "Creencia: " << Creencia << "\n"
                << "Profesion: " << Profesion << "\n"
                << "Fecha y Hora: " << FechaYHora << "\n"
                << "Generacion: " << Generacion << "\n"
                << "Ubicacion: " << Ubicacion << "\n";

        // Imprimir Pecados
        for (int i = 0; i < 7; ++i) {
            if (PecadosH[i] != NULL) {
                PecadosH[i]->imprimir();
            }
        }

//        // Imprimir Amigos
        for (int a = 0; a < 100; a++) {
        	
            if (Amigos[a] != NULL) {
                cout << "Amigo " << (a + 1) << ": " << Amigos[a]->Nombre << " " << Amigos[a]->Apellido << " ID : " << Amigos[a] -> ID << "\n";
            }
        }

        cout << endl;
    }
    
	void imprimir2() {
    	
        cout << "ID: " << ID << "\n"
                << "Nombre: " << Nombre << "\n"
                << "Apellido: " << Apellido << "\n"
                << "Pais: " << Pais << "\n";


        // Imprimir Pecados
        for (int i = 0; i < 7; ++i) {
            if (PecadosH[i] != NULL) {
                PecadosH[i]->imprimir();
            }
        }

        cout << endl;
    }
    
    Pecado * BuscarPecado(string Pecado){
    	
    	for (int i = 0; i < 7; i++){
    		if (PecadosH[i] -> Nombre == Pecado){
    			return PecadosH[i];
			}
		}
	}
	
	int TotalPecados(int _cont){
		
		for (int i = 0; i < 7; i ++){
			_cont += PecadosH[i] -> cantidad;
		}
		return _cont;
	}
	
	
	string Consulta(string _Consulta){
		
		//string _Consulta = "";
		_Consulta ="ID: " + ID + "\n"
                + "Nombre: " + Nombre + "\n"
                + "Apellido: " + Apellido + "\n"
                + "Pais: " + Pais + "\n";

        for (int i = 0; i < 7; ++i) {
            if (PecadosH[i] != NULL) {
                _Consulta = _Consulta + PecadosH[i]->Consulta(_Consulta);
            }
        }

        _Consulta = _Consulta + "\n";
        return _Consulta;
		
	}
    
};


struct Heaps{
	
	string Familia,Pais;
	Humanos *FamiliaActual[10000];
	Heaps *siguiente;
	int ExistenciaFamilia;
	
	Heaps(){
		Familia = "";
		Pais = "";
		ExistenciaFamilia = 0;
		siguiente = NULL;
		for (int i = 0; i < 10000; i ++){
			FamiliaActual[i] = NULL;
		}
	}
	Heaps(string _Familia, string _Pais){
		Familia = _Familia;
		Pais = _Pais;
		ExistenciaFamilia = 0;
		siguiente = NULL;
		for (int i = 0; i < 10000; i ++){
			FamiliaActual[i] = NULL;
		}
	}
	
	void imprimir(){
		
		cout << "| Familia : " << Familia << "  Pais : " << Pais << endl;
		for (int i = 0; i < ExistenciaFamilia; i++){
			if(FamiliaActual[i] != NULL && FamiliaActual[i]-> Ubicacion == 'I')
			FamiliaActual[i]->imprimir2();

		}
		cout << "|-------->"<< endl;
	}
	
	string Consulta(string _Consulta){
		//string _Consulta = "";
		_Consulta = "| Familia : " + Familia + "  Pais : " + Pais + "\n";
		for (int i = 0; i < ExistenciaFamilia; i++){
			if(FamiliaActual[i] != NULL && FamiliaActual[i]-> Ubicacion == 'I')
			_Consulta = _Consulta + FamiliaActual[i]->Consulta(_Consulta);
		}
		_Consulta = _Consulta + "|-------->\n";
		return _Consulta;
	}
	
	int ConteoHumanos(int _cont){
		
		for(int i = 0; i < ExistenciaFamilia; i++){
			if(FamiliaActual[i] != NULL && FamiliaActual[i] -> Ubicacion == 'I'){
				_cont += 1;
			}
		}
		return _cont;
	}
	
	Humanos *MasPecador(Humanos *Pecon){
		
		for(int i = 0; i < ExistenciaFamilia; i++){
			
			if(FamiliaActual[i] -> Ubicacion == 'I' && Pecon -> TotalPecados(0) < FamiliaActual[i] -> TotalPecados(0)){
				
				Pecon = FamiliaActual[i];
			}
			
		}
		return Pecon;
	}
	
};

struct ListaHeaps{
	
	Heaps * primerNodo;
	
	ListaHeaps(){
		primerNodo = NULL;
	}
	
	void InsertarAlInicio(string FamiliaHeap, string PaisHeap){
		
		if (primerNodo != NULL){
			Heaps *FamiliaActual = new Heaps(FamiliaHeap,PaisHeap);
			FamiliaActual -> siguiente = primerNodo;
			primerNodo = FamiliaActual;
		}else{
			primerNodo = new Heaps(FamiliaHeap,PaisHeap);
			
		}
		
	}
	
	void imprimir(){
		
		Heaps * tmp = primerNodo;
		while (tmp != NULL){
			tmp -> imprimir();
			tmp = tmp -> siguiente;
		}
		cout << endl;
	}
	
	string Consulta(string _Consulta){
		//string _Consulta = "";
		Heaps * tmp = primerNodo;
		while (tmp != NULL){
			_Consulta = _Consulta + tmp -> Consulta(_Consulta);
			tmp = tmp -> siguiente;
		}
		_Consulta = _Consulta + "\n";
		return _Consulta;
		//cout << endl;
	}
	
	int Conteo(int _cont){
				
		Heaps * tmp = primerNodo;
		while (tmp != NULL){
			_cont += tmp -> ConteoHumanos(_cont);
			tmp = tmp -> siguiente;
		}
		
		return _cont;
	}
	
	Humanos * MasPecador(Humanos *Pecon){
		
		Heaps * tmp = primerNodo;
		while(tmp != NULL){
			
			if (Pecon -> TotalPecados(0) < tmp -> MasPecador(Pecon) -> TotalPecados(0)){
				Pecon = tmp -> MasPecador(Pecon);
			}
			tmp = tmp -> siguiente;
		}
		
		return Pecon;
	}
	
};


struct Demonios {
	
    string Nombre;
    string Pecado;
	ListaHeaps *ListaDeHeaps;
	int _TotalHumanos;
	
	Demonios(){
		Nombre = "";
		Pecado = "";
		ListaDeHeaps = new ListaHeaps();
		_TotalHumanos = 0;
	}
    Demonios(string _Nombre,string _Pecado){
    	
    	Nombre = _Nombre;
		Pecado = _Pecado;
		ListaDeHeaps = new ListaHeaps();
		_TotalHumanos = 0;
    	
	}
    
    void imprimir(){
    	
    	cout << "Demonio : " << Nombre << " Aqui se ve la lista de familias : \n" ;
    	ListaDeHeaps -> imprimir();
	}
	
	string Consulta(string _Consulta){
		//string _Consulta = "";
		_Consulta = "Demonio : " + Nombre + " Aqui se ve la lista de familias : \n\n\n";
		_Consulta = _Consulta + ListaDeHeaps -> Consulta(_Consulta);
		return _Consulta;
	}
	
	int TotalHumanos(int _cont){
		
		_cont = ListaDeHeaps -> Conteo(_cont);
		return _cont;
		
	}
    
    Humanos * MasPecador(Humanos *Pecon){
    	
    	if(Pecon -> TotalPecados(0) < ListaDeHeaps -> MasPecador(Pecon) -> TotalPecados(0)){
    		//cout << "Si se encontro uno mas peconnn\n";
    		Pecon = ListaDeHeaps -> MasPecador(Pecon);
		}
		
    	return Pecon;
	}
    
};


struct TreeNode {
    Humanos * humano;
    TreeNode * left;
    TreeNode * right;

    TreeNode() {
        humano = NULL;
        left = NULL;
        right = NULL;
    }
    TreeNode(Humanos * human) {
        humano = human;
        left = NULL;
        right = NULL;
    }
};

struct AVLTree{
	
	TreeNode * root;
	AVLTree(){
		root = NULL;
	}
	
	int height(TreeNode * r);
	int getBalanceFactor(TreeNode * n);
	TreeNode * rightRotate(TreeNode * y);
	TreeNode * leftRotate(TreeNode * x);
	TreeNode * insert(TreeNode * r, TreeNode * new_node);
	void print2D(TreeNode * r, int space);
	void printInorder(TreeNode * r);
	void printLevelOrderBFS(TreeNode *r);
	void printGivenLevel(TreeNode * r, int level);
	
	
};

struct Angel{
			
	string Nombre;
	int Generacion,Version;
	Humanos *HumanoSalvado;
	
	Angel(){
		Nombre = "";
		HumanoSalvado = NULL;
		Generacion = 0;
		Version = 0;
	}
		
	Angel(string _Nombre,Humanos* _HumanoSalvado, int _Generacion, int _Version){
		
		Nombre = _Nombre;
		HumanoSalvado = _HumanoSalvado;
		Generacion = _Generacion;
		Version = _Version;
		
	}
	
	void imprimir(){
		
		cout << "Angel : " << Nombre << " De la generacion # " << Generacion << " Version : "<< Version << "	Salvo al Humano :\n" ;
		if(HumanoSalvado != NULL)
		HumanoSalvado->imprimir2();
		
	}
	
	
};


struct CieloAngeles{
	
	int Niveles,AngelesExistencia;
	Angel *ArbolTriaArio[100000];
	
	CieloAngeles(){
		
		Niveles = 0;
		AngelesExistencia = 0;
		for(int i = 0; i < 100000; i++){
			ArbolTriaArio[i] = new Angel();
		}
		
	}
	
	void imprimir(){
		
		cout << "Aqui se muestra el arbol3ario con "<< Niveles << " niveles : \n";
		
		for(int i = 0; i < AngelesExistencia; i++){
			if (ArbolTriaArio[i] != NULL){
				ArbolTriaArio[i] -> imprimir();
			}
		}
		
	}
	
};


/*

		AVLSS
		SSS

*/

//struct AVL
//{
//    int llave;
//    struct AVL *izq;
//    struct AVL *derecha;
//    int altura;
//
//
//// Cambio de nombre de la función
//int max(int a, int b)
//{
//    return (a > b) ? a : b;
//}
//
//// Cambio de nombre de la función
//int altura(struct AVL *N)
//{
//    if (N == NULL)
//        return 0;
//
//    return N->altura;
//}
//
//
//int obtenerbalance(struct AVL *N)
//
//{
//	if (N == NULL)
//
//		return 0;
//
//	return altura(N->izq) - altura(N->derecha);
//
//}
//
//// Cambio de nombre de la función
//struct AVL *RotarDerecha(struct AVL *y)
//{
//    struct AVL *x = y->izq;
//    struct AVL *T2 = x->derecha;
//
//    // hace rotación
//    x->derecha = y;
//    y->izq = T2;
//
//    // actualiza alturas
//    y->altura = max(altura(y->izq), altura(y->derecha)) + 1;
//    x->altura = max(altura(x->izq), altura(x->derecha)) + 1;
//
//    // retorna nueva raíz
//    return x;
//}
//
//// Cambio de nombre de la función
//struct AVL *RotarIzquierda(struct AVL *x)
//{
//    struct AVL *y = x->derecha;
//    struct AVL *T2 = y->izq;
//
//    // hace rotación
//    y->izq = x;
//    x->derecha = T2;
//
//    // actualiza alturas
//    x->altura = max(altura(x->izq), altura(x->derecha)) + 1;
//    y->altura = max(altura(y->izq), altura(y->derecha)) + 1;
//
//    // retorna nueva raíz
//    return y;
//}
//
//// Cambio de nombre de la función
//struct AVL* nuevoAVL(int llave)
//{
//    struct AVL* nuevoAVL = (struct AVL*)malloc(sizeof(struct AVL));
//    nuevoAVL->llave = llave;
//    nuevoAVL->izq = NULL;
//    nuevoAVL->derecha = NULL;
//    nuevoAVL->altura = 1; // nuevoAVL es agregado como hoja
//    return nuevoAVL;
//}
//
//// Cambio de nombre de la función
//struct AVL* insertarAVL(struct AVL* AVL, int llave)
//{
//    // 1. Inserción normal
//    if (AVL == NULL)
//        return nuevoAVL(llave);
//
//    if (llave < AVL->llave)
//        AVL->izq = insertarAVL(AVL->izq, llave);
//    else if (llave > AVL->llave)
//        AVL->derecha = insertarAVL(AVL->derecha, llave);
//    else // No se permiten llaves iguales
//        return AVL;
//
//    // 2. Actualiza altura
//    AVL->altura = 1 + max(altura(AVL->izq), altura(AVL->derecha));
//
//    // 3. Verifica si el árbol se desequilibra
//    int balance = obtenerbalance(AVL);
//
//    // 4 casos para un árbol desequilibrado
//
//    // izq izq
//    if (balance > 1 && llave < AVL->izq->llave)
//        return RotarDerecha(AVL);
//
//    // derecha derecha
//    if (balance < -1 && llave > AVL->derecha->llave)
//        return RotarIzquierda(AVL);
//
//    // izq derecha
//    if (balance > 1 && llave > AVL->izq->llave)
//    {
//        AVL->izq = RotarIzquierda(AVL->izq);
//        return RotarDerecha(AVL);
//    }
//
//    // derecha izq
//    if (balance < -1 && llave < AVL->derecha->llave)
//    {
//        AVL->derecha = RotarDerecha(AVL->derecha);
//        return RotarIzquierda(AVL);
//    }
//
//    return AVL;
//}
//
//// Cambio de nombre de la función
//void preOrder(struct AVL *root)
//{
//    if (root != NULL)
//    {
//        printf("%d ", root->llave);
//        preOrder(root->izq);
//        preOrder(root->derecha);
//    }
//}
//
//// Resto del código...
//// Cambio de nombre de la función
//int procesarNodo(struct AVL *nodo)
//{
//    if (nodo != NULL)
//    {
//        // Accede al arreglo de objetos en el índice correspondiente al valor del nodo
//        int indice = nodo->llave;
//
////        // Verifica que el índice esté en el rango del arreglo
////        if (indice >= 0 && indice < EXISTENCIA)
////        {
////            // Accede al objeto en el arreglo
////            struct Humanos *HumanoActual = HUMANIDAD[indice];
////				HumanoActual -> imprimir2();
////            // Realiza la operación que necesites con el objeto (por ejemplo, imprímelo)
////            // Por ejemplo:
////            // printf("Valor del objeto en el índice %d: %d\n", indice, objetoActual.valor);
////        }
//
//        // Procesa los subárboles izquierdo y derecho
//        procesarNodo(nodo->izq);
//        procesarNodo(nodo->derecha);
//        return indice;
//    }
//    
//}
//};
