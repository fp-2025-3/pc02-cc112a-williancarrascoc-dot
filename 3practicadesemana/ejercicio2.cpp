#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

// Función para identificar el inicio de cada palabra
int separar_palabras(char* frase, char* palabras[]) {
    int contador = 0;
    char* p = frase;
    bool enPalabra = false;

    while (*p != '\0') {
        if (*p != ' ') {
            if (!enPalabra) {
                palabras[contador] = p; // Guardamos la dirección del inicio
                contador++;
                enPalabra = true;
            }
        } else {
            enPalabra = false;
        }
        p++;
    }
    return contador;
}

// Función para comparar dos palabras carácter por carácter hasta encontrar un espacio o fin de cadena
int comparar(const char* a, const char* b) {
    int i = 0;
    while (a[i] != ' ' && a[i] != '\0' && b[i] != ' ' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
        i++;
    }

    // Manejo de longitudes diferentes: simulamos fin de cadena si hay un espacio
    char charA = (a[i] == ' ' || a[i] == '\0') ? '\0' : a[i];
    char charB = (b[i] == ' ' || b[i] == '\0') ? '\0' : b[i];

    return charA - charB;
}

// Función de ordenamiento (Bubble Sort) intercambiando solo los punteros
void ordenar(char* palabras[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparar(palabras[j], palabras[j + 1]) > 0) {
                // Intercambio de direcciones de memoria
                char* temp = palabras[j];
                palabras[j] = palabras[j + 1];
                palabras[j + 1] = temp;
            }
        }
    }
}

// Función para imprimir leyendo desde el puntero hasta encontrar el límite de la palabra
void imprimir(char* palabras[], int n) {
    for (int i = 0; i < n; i++) {
        char* p = palabras[i];
        while (*p != ' ' && *p != '\0') {
            cout << *p;
            p++;
        }
        cout << endl;
    }
}

int main() {
    char frase[200] = "aprender punteros exige mucha logica y practica";
    char* palabras[50];

    // 1. Identificar palabras
    int n = separar_palabras(frase, palabras);

    // 2. Ordenar alfabéticamente
    ordenar(palabras, n);

    // 3. Imprimir resultado
    imprimir(palabras, n);

    return 0;
}