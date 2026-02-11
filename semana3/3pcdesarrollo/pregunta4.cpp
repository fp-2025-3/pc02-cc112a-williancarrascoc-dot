#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
int guardarDirecciones(char* texto, char** almacen) {
    int n = 0;
    char* p = texto;
    bool palabra = false;
    while (*p != '\0') {  // Recorrer toda la oración
        if (*p != ' ') {  // Verifica que es el inicio una palabra
            if (!palabra) {  // Verifica que es el inicio de una nueva palabra
                *(almacen + n) = p;  // Copiamos posición del inicio de la palabra
                n++;
                palabra = true;
            }
        } else {
            palabra = false;
        }
        p++;  // Avanzamos al siguiente carácter
    }
    return n;
}

int comparar(const char* a, const char* b) {
    while (*a != '\0' && *a != ' ' && *b != '\0' && *b != ' ') {  //algunas condiciones
        char charA = tolower(*a); //convertimos a minusculas para comparar menos 
        char charB = tolower(*b); 
        if (charA < charB) {  //comparar alfabeticamente
            return -1;
        } else if (charA > charB) {
            return 1;
        }
        a++;
        b++;
    }
    //para verificar cual termina primero
    bool aTermina = (*a == '\0' || *a == ' ');
    bool bTermina = (*b == '\0' || *b == ' ');
    if (aTermina && !bTermina) {
        return -1;  // a es más corta
    } else if (!aTermina && bTermina) {
        return 1;   // b es más corta
    }
    return 0;  // Son iguales
}

void ordenarIndice(char** almacen, int n) {
    for (int i = 0; i < n - 1; i++) {  //recorrer 
        for (int j = 0; j < n - i - 1; j++) {
            if (comparar(*(almacen + j), *(almacen + j + 1)) > 0) { //verifica
                char* temp = *(almacen + j);  //intercambia lugares ordenandolos
                *(almacen + j) = *(almacen + j + 1);
                *(almacen + j + 1) = temp;
            }
        }
    }
}

//solamente para imprimir 
void imprimir(char* texto, char** almacen, int n) {
    for (int i = 0; i < n; i++) {
        char* palabraInicio = *(almacen + i);
        int posicion = palabraInicio - texto;        
        char* p = palabraInicio;
        while (*p != '\0' && *p != ' ') {
            cout << *p;
            p++;
        }
        cout << " (posicion " << posicion << ")" << endl;
    }
}

int main() {
    char texto[] = "los punteros no se copian se referencian y se ordenan"; 
    char* almacen[50];
    cout << "Texto original:" ; //imprimir original
    cout <<texto<<endl;
    cout << endl;
    int n = guardarDirecciones(texto, almacen);  //posiciones
    ordenarIndice(almacen, n); //ordenar
    imprimir(texto, almacen, n); //imprimir
    return 0;
}