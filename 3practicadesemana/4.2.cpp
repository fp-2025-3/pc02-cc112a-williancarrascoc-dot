#include <iostream>
#include <cstring>
using namespace std;

//Separamos palabras reemplazando espacios por '\0'
int separar_palabras(char* texto, char* palabras[]) {
    int i = 0;
    char* p = texto;
    while (*p != '\0') {
        if (*p != ' ') {
            palabras[i++] = p;      // inicio de palabra
            while (*p != ' ' && *p != '\0') {
                p++;
            }
            if (*p == ' ') {
                *p = '\0';          // termina la palabra
            }
        }
        p++;
    }
    return i;
}

// Clasifica palabras en cortas (<=3) y largas (>3)
void clasificar(char* palabras[], int n,
                char* cortas[], int& nc,
                char* largas[], int& nl) {
    nc = 0;
    nl = 0;

    for (int i = 0; i < n; i++) {
        int longitud = strlen(palabras[i]);
        if (longitud <= 3) {
            cortas[nc++] = palabras[i];
        } else {
            largas[nl++] = palabras[i];
        }
    }
}

// Ordena alfabéticamente usando burbuja
void ordenar(char* v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(v[j], v[j + 1]) > 0) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

// Imprime grupo de palabras
void imprimir_grupo(char* v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

int main() {
    char texto[300] = "     Programar en C++ requiere logica C++ exige disciplina";
    char* palabras[60];
    char* cortas[60];
    char* largas[60];
    int nc = 0, nl = 0;

    cout << "La frase original es:\n";      //solo orden
    cout << texto << "\n\n";                //imprimimos la frase original
    int n = separar_palabras(texto, palabras);    //separamos la frase

    clasificar(palabras, n, cortas, nc, largas, nl);   //clasificamos

    ordenar(cortas, nc);   //ordenamos cortas
    ordenar(largas, nl);   //ordenamos largas

    cout << "Palabras cortas:\n";     //solo orden   
    imprimir_grupo(cortas, nc);       //imprimimos cortas

    cout << "Palabras largas:\n";     //solo orden
    imprimir_grupo(largas, nl);       //imprimimos largas

    return 0;
}