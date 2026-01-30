#include <iostream>
#include <cctype>
#include <cstdlib>
#include<cstring>
using namespace std;
// Función para identificar el inicio de cada palabra
int separar_palabras(char* frase, char* palabras[]) {
    int contador = 0;
    char* p = frase;

    while (*p != '\0') {
        if (*p != ' ') {
            palabras[contador++] = p;
            while (*p != ' ' && *p != '\0') {
                p++;
            }
            if (*p == ' ') {
                *p = '\0';   
            }
        }
        p++;
    }
    return contador;
}

// Función de ordenamiento (Bubble Sort) intercambiando solo los punteros
void ordenar(char* palabras[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(palabras[j], palabras[j + 1]) > 0) {
                // Intercambio de direcciones de memoria
                swap(palabras[j],palabras[j+1]);
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