#include <iostream>
using namespace std;

int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }

int main() {
    int (*op)(int,int) = suma;

    cout << op(3,4) << endl;

    op = resta;
    cout << op(10,5) << endl;
}