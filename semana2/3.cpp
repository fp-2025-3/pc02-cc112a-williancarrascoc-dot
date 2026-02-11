#include <iostream>
using namespace std;

int* crearEntero(int& x) {
    x = 42;
    return &x; //NO DEVOLVER DIRECCIONES DE VARIABLES LOCALES
}

int main() {
    int xx = 10;
    int* p= crearEntero(xx);
    cout << *p << endl;
}