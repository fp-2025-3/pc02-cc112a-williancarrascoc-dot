#include<iostream>
#include<cctype>
#include<cstdlib>
#include<cstring>
using namespace std;
const int n = 9;

void generarPermutacion(int fila[]) {
    for(int i = 0; i < n; i++) { //le damos un valor a cada fila[i] del 1 al 9
        fila[i] = i + 1;
    }
    for(int i = n - 1; i > 0; i--) { //algoritmo fisher
        int j = rand() % (i + 1);  //num aleatorio
        int temp = fila[i];        //intercambiamos fila[i] y fila[j]
        fila[i] = fila[j];
        fila[j] = temp;
    }
}

// Función para rotar una fila hacia la izquierda
void rotarFila(int fila[], int pasos) {
    int temp[n];
    for(int i = 0; i < n; i++) {
        temp[i] = fila[(i + pasos) % n]; //mueve y limitar a 9
    }
    for(int i = 0; i < n; i++) {
        fila[i] = temp[i]; //se copia matriz cambiada
    }
}

void imprimirMatriz(int vec[][n]) { //imprimiendo matriz 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {
    int fila, columna;
    int vec[n][n];
    srand(time(NULL));

    for(int i = 0; i < n; i++) {     // Generar matriz con permutaciones aleatorias
        generarPermutacion(vec[i]);
    }
    imprimirMatriz(vec);     //imprimiendo matriz original
    cout << endl;
    cout << "Ingrese fila (1-9): ";
    cin >> fila;
    cout << "Ingrese columna (1-9): ";
    cin >> columna;
    int valorSeleccionado = vec[fila-1][columna-1];
    cout<<endl;
    cout << "Valor seleccionado " << valorSeleccionado << endl;
    for(int i = 0; i < n; i++) { //recorre filas para saber donde esta el numero
        int posActual = -1; //solo es indicador si se encontro el numero o no
        for(int j = 0; j < n; j++) { //buscar la columna donde esta el numero
            if(vec[i][j] == valorSeleccionado) {
                posActual = j;
                break;
            }
        }
        // Calcular cuántas posiciones rotar
        if(posActual != -1 && posActual != columna - 1) {
            int desplazamiento = (posActual - (columna - 1) + n) % n;
            rotarFila(vec[i], desplazamiento);
        }
    }
    cout <<endl;
    imprimirMatriz(vec);
    return 0;
}