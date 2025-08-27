#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// --------- Demo: Puntero simple ---------
void demoPunteroSimple() {
    cout << "\n== Puntero simple ==\n";
    int a = 10;
    int* p = &a;

    cout << "Valor de a: " << a << "\n";
    cout << "Direccion de a (&a): " << static_cast<const void*>(&a) << "\n";
    cout << "Valor de p (direccion): " << static_cast<const void*>(p) << "\n";
    cout << "Contenido apuntado por p (*p): " << *p << "\n";

    // Modificar a traves del puntero
    *p = 42;
    cout << "Luego de *p = 42, a = " << a << "\n";
}

// --------- Demo: Puntero a puntero ---------
void demoDoblePuntero() {
    cout << "\n== Puntero a puntero (doble) ==\n";
    int x = 7;
    int* p = &x;
    int** pp = &p;

    cout << "x = " << x << "\n";
    cout << "p  -> " << static_cast<const void*>(p)  << " (deberia ser &x)\n";
    cout << "pp -> " << static_cast<const void*>(pp) << " (deberia ser &p)\n";
    cout << "*p = " << *p << ", **pp = " << **pp << "\n";

    // Modificar x a traves de **pp
    **pp = 99;
    cout << "Luego de **pp = 99, x = " << x << "\n";
}

// --------- Demo: Punteros y arreglos ---------
void demoPunteroArreglo() {
    cout << "\n== Punteros y arreglos ==\n";
    int arr[5] = {1, 2, 3, 4, 5};

    int* pa = arr; // decae a puntero al primer elemento
    cout << "Direccion arr (arr): " << static_cast<const void*>(arr) << "\n";
    cout << "Direccion primer elem (&arr[0]): " << static_cast<const void*>(&arr[0]) << "\n";
    cout << "pa (puntero a arr[0]): " << static_cast<const void*>(pa) << "\n";

    cout << "Recorriendo con aritmetica de punteros:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "  *(pa + " << i << ") = " << *(pa + i) << "\n";
    }

    // Puntero al arreglo completo (tipo: int (*)[5])
    int (*ptrArrCompleto)[5] = &arr;
    cout << "Puntero al ARREGLO COMPLETO (&arr): " 
         << static_cast<const void*>(ptrArrCompleto) << "\n";
    cout << "(*ptrArrCompleto)[2] = " << (*ptrArrCompleto)[2] << "\n";
}

// --------- Demo: Puntero a funcion ---------
int cuadrado(int x) { return x * x; }
int triple(int x)   { return 3 * x; }

void demoPunteroFuncion() {
    cout << "\n== Puntero a funcion ==\n";
    int (*fptr)(int) = &cuadrado;
    cout << "cuadrado(5) via puntero = " << fptr(5) << "\n";

    fptr = &triple;
    cout << "triple(5) via puntero   = " << fptr(5) << "\n";
}

// --------- Demo: const con punteros ---------
void demoConstConPunteros() {
    cout << "\n== const con punteros ==\n";
    int a = 10;
    int b = 20;

    const int* pDatoConst = &a; 
    cout << "const int* pDatoConst -> *pDatoConst = " << *pDatoConst << "\n";
    pDatoConst = &b; 
    cout << "Ahora pDatoConst -> *pDatoConst = " << *pDatoConst << "\n";

    int* const pConstPuntero = &a;
    *pConstPuntero = 777; 
    cout << "int* const pConstPuntero -> *pConstPuntero = " << *pConstPuntero << "\n";

    const int* const pConstAmbos = &a;
    cout << "const int* const pConstAmbos -> *pConstAmbos = " << *pConstAmbos << "\n";
}

// --------- Demo: memoria dinamica con new/delete ---------
void demoMemoriaDinamica() {
    cout << "\n== Memoria dinamica (new/delete) ==\n";

    int* p = new int(123); 
    cout << "new int(123) -> *p = " << *p 
         << ", direccion: " << static_cast<const void*>(p) << "\n";
    *p = 456;
    cout << "Luego de *p = 456 -> *p = " << *p << "\n";
    delete p; 

    size_t n = 5;
    int* arr = new int[n]{10, 20, 30, 40, 50};
    cout << "Arreglo dinamico:\n";
    for (size_t i = 0; i < n; ++i) {
        cout << "  arr[" << i << "] = " << arr[i] << "\n";
    }
    delete[] arr; 
}

void mostrarMenu() {
    cout << "\n======================\n";
    cout << "  DEMO PUNTEROS C++\n";
    cout << "======================\n";
    cout << "1) Puntero simple\n";
    cout << "2) Puntero a puntero (doble)\n";
    cout << "3) Punteros y arreglos\n";
    cout << "4) Puntero a funcion\n";
    cout << "5) const con punteros\n";
    cout << "6) Memoria dinamica (new/delete)\n";
    cout << "0) Salir\n";
    cout << "Elige una opcion por favor: ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int opcion = -1;
    do {
        mostrarMenu();
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Entrada invalida. Intenta de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1: demoPunteroSimple();     break;
            case 2: demoDoblePuntero();      break;
            case 3: demoPunteroArreglo();    break;
            case 4: demoPunteroFuncion();    break;
            case 5: demoConstConPunteros();  break;
            case 6: demoMemoriaDinamica();   break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    } while (opcion != 0);

    return 0;
}
