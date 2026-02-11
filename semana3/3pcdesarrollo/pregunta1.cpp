#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
// Función para extraer números de la cadena y almacenarlos en un arreglo
int extraerNumeros(const char* texto, int* numeros) { 
    int i= 0;
    const char* p = texto;
    while (*p != '\0') {   //para que recorra todo el arreglo
        while (*p == ' ' || *p == ',') {      // para saltar espacios y comas
            p++;
        }
        // Si encontramos un dígito 
        if (isdigit(*p) ){
            numeros[i] = atoi(p);
            i++;
            while (isdigit(*p)) {
                p++;
            }
        } else if (*p != '\0') {
            p++;
        }
    }
    return i;
}

//encontramos si existe un par con suma k usando dos punteros
bool existeParConSuma(int* numeros, int n, int k) {
    int* izq = numeros;           // Puntero al inicio
    int* der = numeros + n - 1;   // Puntero al final
    while (izq < der) {
        int suma = *izq + *der;
        if (suma == k) {
            return true;
        } else if (suma < k) {
            izq++;  // Necesitamos una suma mayor
        } else {
            der--;  // Necesitamos una suma menor
        }
    }
    return false;
}

int main() {
    const char* texto = "1, 2, 4, 7, 11";
    int k = 15;
    int numeros[100];      // Arreglo para almacenar los números 
    cout << "Texto: " << texto <<endl;   //anunciamos texto original 
    int n = extraerNumeros(texto, numeros);      // Extraermos números de la cadena
    if(existeParConSuma(numeros, n, k)){
        cout<<"SI existen 2 números con suma "<<k;
    }else{
        cout<<"NO existe 2 números con suma "<<k;
    }
    cout << endl;

    return 0;
}