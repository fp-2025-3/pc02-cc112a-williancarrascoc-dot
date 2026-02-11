#include <iostream>
#include <cstring>  // strlen
using namespace std;
// Función que cuenta cuántas cadenas tienen longitud mayor al promedio
int contar(const char* cad[], int n) {
    float suma = 0;
    // 1. Calcular suma de longitudes
    for (int i = 0; i < n; i++) {
        suma += strlen(cad[i]);
    }
    // 2. Calcular promedio
    float promedio = suma / n;
    // 3. Contar cadenas mayores al promedio
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (strlen(cad[i]) > promedio) {
            contador++;
        }
    }
    return contador;
}
int main() {
    const char* cad[] = {
        "el gato",
        "es",
        "el mejor animal"
    };
    int n = sizeof(cad) / sizeof(cad[0]);
    cout << "Cadenas con longitud mayor al promedio: "<< contar(cad, n) << endl;
    return 0;
}