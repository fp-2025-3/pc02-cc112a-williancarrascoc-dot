#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

// EJERCICIO: Implementación propia de la función intercambio para punteros
void intercambiar(char* &a, char* &b) {
    char* temp = a;
    a = b;
    b = temp;
}

int separar_palabras(char* texto, char* palabras[]) {
    int i = 0;  
    char *p = texto; 
    while (*p != '\0') {
        if ((p == texto && *p != ' ') || (p > texto && *(p - 1) == ' ' && *p != ' ')) {
            palabras[i] = p;
            i++;
        }
        p++;
    }
    return i;
}

int longitud_palabra(const char* p) {
    int longitud = 0;
    while (*p != ' ' && *p != '\0') {
        longitud++;
        p++;
    }
    return longitud;
}

void clasificar(char* palabras[], int n, char* cortas[], int& nc, char* largas[], int& nl) {
    nc = 0; // Inicializamos contadores
    nl = 0;
    for (int i = 0; i < n; ++i) {
        int longitud = longitud_palabra(palabras[i]);
        if (longitud <= 3) {
            cortas[nc] = palabras[i];
            nc++;
        } else {
            largas[nl] = palabras[i];
            nl++;
        }
    }
}

int comparar_palabras(const char* a, const char* b) {
    int i = 0;
    while (a[i] != ' ' && a[i] != '\0' && b[i] != ' ' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return a[i] - b[i]; 
        }
        i++;
    }
    // Verificamos quién terminó primero para manejar longitudes distintas
    char charA = (a[i] == ' ') ? '\0' : a[i];
    char charB = (b[i] == ' ') ? '\0' : b[i];
    return charA - charB;
}

void ordenar(char* v[], int n) {
    for (int i = 0; i < n - 1; ++i) { 
        for (int j = 0; j < n - i - 1; ++j) { 
            if (comparar_palabras(v[j], v[j + 1]) > 0) {
                intercambiar(v[j], v[j + 1]); 
            }
        }
    }
}

void imprimir_grupo(const char* titulo, char* v[], int n) {
    cout << "--- Palabras " << titulo << " ---" << endl;
    for (int i = 0; i < n; ++i) {
        char* p = v[i];
        while (*p != ' ' && *p != '\0') {
            cout << *p; 
            p++;
        }
        cout << " "; // Espacio para legibilidad
    }
    cout << "\n" << endl;
}

int main() {
    char texto[300] = "Programar en C++ requiere logica C++ exige disciplina";
    char* palabras[60];
    char* cortas[60];
    char* largas[60];
    int nc = 0, nl = 0;

    // 1. Separar
    int n = separar_palabras(texto, palabras);
    imprimir_grupo("Originales", palabras, n);

    // 2. Clasificar
    clasificar(palabras, n, cortas, nc, largas, nl);

    // 3. Ordenar grupos
    ordenar(cortas, nc);
    ordenar(largas, nl);

    // 4. Imprimir resultados
    imprimir_grupo("Cortas (ordenadas)", cortas, nc);
    imprimir_grupo("Largas (ordenadas)", largas, nl);

    return 0;
}