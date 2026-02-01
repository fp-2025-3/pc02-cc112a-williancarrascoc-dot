#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para imprimir la matriz usando punteros
void imprimirTablero(int** m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Usando aritmética de punteros para demostrar el uso de doble puntero
            cout << *(*(m + i) + j) << " ";
        }
        cout << endl;
    }
}

// Función para rotar una fila hacia la derecha (circular)
void rotarFila(int* fila, int n) {
    int ultimo = *(fila + n - 1);
    for (int i = n - 1; i > 0; i--) {
        *(fila + i) = *(fila + i - 1);
    }
    *fila = ultimo;
}

int main() {
    // Inicializar semilla aleatoria
    srand(time(NULL));
    
    int n = 9;
    
    // 1. Crear matriz con doble puntero
    int** matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
        
        // Llenar fila con 1, 2, ..., 9
        for (int j = 0; j < n; j++) {
            matriz[i][j] = j + 1;
        }
        
        // Generar permutación aleatoria (Fisher-Yates shuffle manual)
        for (int j = n - 1; j > 0; j--) {
            int k = rand() % (j + 1);
            int temp = matriz[i][j];
            matriz[i][j] = matriz[i][k];
            matriz[i][k] = temp;
        }
    }

    cout << "Tablero Inicial:" << endl;
    imprimirTablero(matriz, n);

    // 2. Entrada de usuario
    int filI, colJ;
    cout << "\nFila inicial (1-9): "; cin >> filI;
    cout << "Columna inicial (1-9): "; cin >> colJ;

    // Ajuste a índices de matriz (0-8)
    int fIdx = filI - 1;
    int cIdx = colJ - 1;
    int valorObjetivo = matriz[fIdx][cIdx];

    cout << "Valor seleccionado: " << valorObjetivo << endl;

    // 3. Lógica de desplazamiento
    // Para cada fila de la matriz...
    for (int i = 0; i < n; i++) {
        int posActual = -1;
        
        // Buscar dónde está el valor seleccionado en la fila 'i'
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == valorObjetivo) {
                posActual = j;
                break;
            }
        }

        // Rotar la fila hasta que el valor esté en la columna cIdx
        while (posActual != cIdx) {
            rotarFila(matriz[i], n);
            posActual = (posActual + 1) % n;
        }
    }

    // 4. Mostrar resultado final
    cout << "\nTablero Final:" << endl;
    imprimirTablero(matriz, n);

    // 5. Liberación de memoria dinámica
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}