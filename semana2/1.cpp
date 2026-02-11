#include <iostream>
using namespace std;

int main() {
    int x=5;
    int* p; // El puntero tiene que apuntar por algo es un puntero

    p=&x;
    *p = 10;

    cout << *p << endl;
    cout << p <<endl;
    cout << x <<endl;
    cout << &x <<endl;
}