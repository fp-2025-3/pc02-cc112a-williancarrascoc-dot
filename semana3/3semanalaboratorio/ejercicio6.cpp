#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// Función para ordenar los caracteres de la palabra
void ordenarString(char* s) {
    int n = strlen(s);
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
    char p1[100], p2[100];

    // 1. Preguntamos cuántos pares de palabras tiene la lista
    cout << "Ingrese la cantidad de pares a verificar: ";
    cin >> cantidad;
    cin.ignore();

    // 2. El ciclo se repetirá exactamente esa cantidad de veces
    for (int i = 0; i < cantidad; i++) {
        cin.getline(p1,100);
        cin.getline(p2,100);

        // Verificamos longitud primero por eficiencia
        if (strlen(p1) != strlen(p2)) {
            cout << 0 << endl;
        } else {
            ordenarString(p1);
            ordenarString(p2);

            if (strcmp(p1,p2)==0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}