#include <iostream>
using namespace std;

// Estructura de un nodo de la lista
struct Nodo {
    int dato;           // Valor almacenado
    Nodo* siguiente;    // Puntero al siguiente nodo
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}  // Constructor
};

// EJERCICIO 1: Estadísticas de la lista
void estadisticasLista(Nodo* head) {
    // Verificar si la lista está vacía
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }
    
    // Variables para las estadísticas
    int total = 0, suma = 0;
    int mayor = head->dato;  // Inicializar con el primer valor
    int menor = head->dato;
    Nodo* actual = head;     // Puntero para recorrer la lista
    
    // Recorrer toda la lista
    while (actual != nullptr) {
        total++;                    // Contar nodos
        suma += actual->dato;       // Acumular suma
        if (actual->dato > mayor) mayor = actual->dato;  // Actualizar mayor
        if (actual->dato < menor) menor = actual->dato;  // Actualizar menor
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
    
    // Mostrar resultados
    cout << "Total: " << total << endl;
    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << (double)suma / total << endl;
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
}

// EJERCICIO 2: Reemplazar un valor en la lista
bool reemplazarValor(Nodo* head, int buscar, int nuevo) {
    // Verificar si la lista está vacía
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return false;
    }
    
    Nodo* actual = head;  // Puntero para recorrer
    
    // Buscar el valor en la lista
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

// Función auxiliar: Insertar un nodo al final
void insertar(Nodo*& head, int valor) {
    Nodo* nuevo = new Nodo(valor);  // Crear nuevo nodo
    
    if (head == nullptr) {  // Si la lista está vacía
        head = nuevo;       // El nuevo nodo es el primero
    } else {
        Nodo* temp = head;
        // Ir hasta el último nodo
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;  // Agregar al final
    }
}

// Función auxiliar: Mostrar la lista
void mostrar(Nodo* head) {
    Nodo* temp = head;
    // Recorrer e imprimir cada nodo
    while (temp != nullptr) {
        cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    cout << endl;
}

// Programa principal
int main() {
    Nodo* lista = nullptr;  // Inicializar lista vacía
    
    // Crear una lista de prueba
    insertar(lista, 5);
    insertar(lista, 12);
    insertar(lista, 8);
    insertar(lista, 3);
    
    // Mostrar la lista
    cout << "Lista: ";
    mostrar(lista);
    
    // Probar ejercicio 1
    cout << "\nEJERCICIO 1:" << endl;
    estadisticasLista(lista);
    
    // Probar ejercicio 2
    cout << "\nEJERCICIO 2:" << endl;
    reemplazarValor(lista, 12, 99);
    mostrar(lista);
    
    return 0;
}