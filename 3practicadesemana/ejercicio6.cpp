#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

// Función para ordenar los caracteres de la palabra
void ordenarString(string &s) {
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int cantidad;
    string p1, p2;

    // 1. Preguntamos cuántos pares de palabras tiene la lista
    cout << "Ingrese la cantidad de pares a verificar: ";
    cin >> cantidad;

    // 2. El ciclo se repetirá exactamente esa cantidad de veces
    for (int i = 0; i < cantidad; i++) {
        cin >> p1 >> p2;

        // Verificamos longitud primero por eficiencia
        if (p1.length() != p2.length()) {
            cout << 0 << endl;
        } else {
            ordenarString(p1);
            ordenarString(p2);

            if (p1 == p2) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}