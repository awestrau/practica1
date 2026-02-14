#include <iostream>
using namespace std;

// aqui se estructura el nodo de la lista con un constructor para facilitar la creación de nuevos nodos
struct Nodo {
    int dato;           // este seria el valor almacenado
    Nodo* siguiente;    // y este el puntero que da al siguiente nodo
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}  // Constructor, nullptr es un puntero nulo que indica el final de la lista
};

// practica1: Estadísticas de nodos de lista
void estadisticasLista(Nodo* head) {
    // este condicional verifica si la lista está vacía
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }
    
    // inicializacion de variables para las estadísticas
    int total = 0, suma = 0;
    int mayor = head->dato;  // Inicializar con el primer valor
    int menor = head->dato;
    Nodo* actual = head;     // Puntero para recorrer la lista
    
    // este while recorre toda la lista
    while (actual != nullptr) {
        total++;                    // Contar nodos
        suma += actual->dato;       // Acumular suma
        if (actual->dato > mayor) mayor = actual->dato;  // Actualizar mayor
        if (actual->dato < menor) menor = actual->dato;  // Actualizar menor
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
    
    // aqui mostramos resultados
    cout << "Total: " << total << endl;
    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << (double)suma / total << endl;
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
}

// ejercicio2: Reemplazo de valor 
bool reemplazarValor(Nodo* head, int buscar, int nuevo) {
    // condicional para verificar si la lista está vacía
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return false;
    }
    
    Nodo* actual = head;  // Puntero para recorrer la lista
    
    // while para buscar el valor en la lista
    while (actual != nullptr) {
        if (actual->dato == buscar) {  // Si encontramos el valor
            actual->dato = nuevo;       // Reemplazarlo
            cout << "Reemplazo exitoso" << endl;
            return true;
        }
        actual = actual->siguiente;  // Avanzar al siguiente
    }
    
    // Si llegamos aquí, el valor no existe
    cout << "Valor no encontrado" << endl;
    return false;
}

//---- aqui puede empezar la funcion para el ejercicio 3 


//-------fin ejercicio 3
// esta funcion es para insertar un nodo al final de la lista funciona para cualquier valor y se puede usar para crear la lista de prueba
void insertar(Nodo*& head, int valor) {
    Nodo* nuevo = new Nodo(valor);  // Crear nuevo nodo
    
    if (head == nullptr) {  // Si la lista está vacía
        head = nuevo;       // El nuevo nodo es el primero
    } else {
        Nodo* temp = head;
        // se va hasta el último nodo
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;  // Agregar al final
    }
}

// Funcion para mostrar la lista
void mostrar(Nodo* head) {
    Nodo* temp = head;
    // while que recorre e imprime cada nodo
    while (temp != nullptr) {
        cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    cout << endl;
}

// Programa principal
int main() {
    Nodo* lista = nullptr;  // Inicializa la lista vacía
    
    // Crea una lista de prueba
    insertar(lista, 5);
    insertar(lista, 12);
    insertar(lista, 8);
    insertar(lista, 3);
    
    // Muestra la lista
    cout << "Lista: ";
    mostrar(lista);
    
    // Prueba de ejercicio 1
    cout << "\nEJERCICIO 1:" << endl;
    estadisticasLista(lista);
    
    // Prueba de ejercicio 2
    cout << "\nEJERCICIO 2:" << endl;
    reemplazarValor(lista, 12, 99);
    mostrar(lista);

    //aqui se pueden agregar pruebas para el ejercicio 3
    
    return 0;
}