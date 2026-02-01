#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
bool esVocal(char c) {  //funcion para verifica si un carácter es vocal
    c = tolower(c);  //convertimos a minúscula 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');  //retornara si es vocal
}

//creamos una función que cuenta palabras que comienzan con vocal
int contarPalabrasConVocal(const char* texto) {
    int contador = 0;
    const char* p = texto;
    bool palabra = false;  // Indica si estamos dentro de una palabra
    
    while (*p != '\0') {  //recorer todo
        if (*p != ' ') {   //verifica si letra
            if (!palabra) {   //verifica si comienza una palabra
                palabra = true;   //estamos en una palabra
                if (esVocal(*p)) { //verifica si es vocal
                    contador++;
                }
            }
        } else {
            palabra = false;   //cambia para decir que finalizo la palabra
        }
        p++;  //avanzamos
    }
    return contador;
}

int main() {
    const char* texto = "  el gato vive en europa";
    cout << "Texto: " << texto << endl;   //imprimimos oracion original
    int resultado = contarPalabrasConVocal(texto);
    cout << "Número de palabras que comienzan con vocal: " << resultado << endl;

    return 0;
}