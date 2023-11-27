//#include "Humanidad.h"
//#include<stdio.h>
//#include<stdlib.h>
//
//
////ARROZZ
//
//// Cambio de nombre de la estructura
//struct AVL
//{
//    int llave;
//    struct AVL *izq;
//    struct AVL *derecha;
//    int alturaA;
//    //void procesarNodo(struct AVL *nodo,Humanos *HUMANIDAD[100000],int EXISTENCIA);
//    
//    
//    
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
//    AVL->alturaA = 1 + max(altura(AVL->izq), altura(AVL->derecha));
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
//    void procesarNodo(struct AVL *nodo, Humanos *HUMANIDAD[100000], int EXISTENCIA)
//{
//    if (nodo != NULL)
//    {
//        // Accede al arreglo de objetos en el índice correspondiente al valor del nodo
//        int indice = nodo->llave;
//
//        // Verifica que el índice esté en el rango del arreglo
//        if (indice >= 0 && indice < EXISTENCIA)
//        {
//            // Accede al objeto en el arreglo
//            struct Humanos *HumanoActual = HUMANIDAD[indice];
//			HumanoActual -> imprimir2();
//            // Realiza la operación que necesites con el objeto (por ejemplo, imprímelo)
//            // Por ejemplo:
//            // printf("Valor del objeto en el índice %d: %d\n", indice, objetoActual.valor);
//        }
//
//        // Procesa los subárboles izquierdo y derecho
//        procesarNodo(nodo->izq,HUMANIDAD,EXISTENCIA);
//        procesarNodo(nodo->derecha,HUMANIDAD,EXISTENCIA);
//        //return indice;
//    }
//    
//}
//
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
//    return N->alturaA;
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
//    y->alturaA = max(altura(y->izq), altura(y->derecha)) + 1;
//    x->alturaA = max(altura(x->izq), altura(x->derecha)) + 1;
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
//    x->alturaA = max(altura(x->izq), altura(x->derecha)) + 1;
//    y->alturaA = max(altura(y->izq), altura(y->derecha)) + 1;
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
//    nuevoAVL->alturaA = 1; // nuevoAVL es agregado como hoja
//    return nuevoAVL;
//}
//
//// Cambio de nombre de la función
//
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
//
//
//
//    
//};

