#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N = 9;
// Función para imprimir la matriz usando punteros
void imprimirTablero(int m[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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
    srand(time(NULL));
    int matriz[N][N];
    // Inicializar matriz
    for (int i = 0; i < N; i++) {
        // Llenar con 1..9
        for (int j = 0; j < N; j++) {
            matriz[i][j] = j + 1;
        }

        // Permutación aleatoria
        for (int j = N - 1; j > 0; j--) {
            int k = rand() % (j + 1);
            int temp = matriz[i][j];
            matriz[i][j] = matriz[i][k];
            matriz[i][k] = temp;
        }
    }

    cout << "Tablero Inicial:\n";
    imprimirTablero(matriz, N);

    int filI, colJ;
    cout << "\nFila inicial (1-9): ";
    cin >> filI;
    cout << "Columna inicial (1-9): ";
    cin >> colJ;

    int fIdx = filI - 1;
    int cIdx = colJ - 1;
    int valorObjetivo = matriz[fIdx][cIdx];

    cout << "Valor seleccionado: " << valorObjetivo << endl;

    // Desplazamiento
    for (int i = 0; i < N; i++) {
        int posActual = -1;

        for (int j = 0; j < N; j++) {
            if (matriz[i][j] == valorObjetivo) {
                posActual = j;
                break;
            }
        }

        while (posActual != cIdx) {
            rotarFila(matriz[i], N);
            posActual = (posActual + 1) % N;
        }
    }

    cout << "\nTablero Final:\n";
    imprimirTablero(matriz, N);

    return 0;
}
