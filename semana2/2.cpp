#include <iostream>
using namespace std;

int* crearEntero() {
    int* x = new int(42); // stack |   heap   guardo la direccion de 42 y tmb guardo memoria para ello 
    return x;
}

int main() {
    int* p = crearEntero();
    cout << *p << endl;
}