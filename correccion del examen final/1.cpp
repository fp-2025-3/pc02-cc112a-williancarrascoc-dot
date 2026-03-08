#include <iostream>
using namespace std;
int** crearMatriz(int n, int m) {
    int** M = new int*[n];
    for (int i = 0; i < n; i++)
        M[i] = new int[m];
    return M;
}
void llenarMatriz(int** M, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            M[i][j] = (i + 1) * (j + 1);
}
int* sumaFilas(int** M, int n, int m) {
    int* sumas = new int[n];
    for (int i = 0; i < n; i++) {
        sumas[i] = 0;
        for (int j = 0; j < m; j++)
            sumas[i] += M[i][j];
    }
    return sumas;
}
void liberarMatriz(int** M, int n) {
    for (int i = 0; i < n; i++)
        delete[] M[i];   
    delete[] M;          
}
int main() {
    int n, m;
    cout << "Ingrese numero de filas: "; cin >> n;
    cout << "Ingrese numero de columnas: "; cin >> m;
    int** M = crearMatriz(n, m);
    llenarMatriz(M, n, m);
    cout << "\nMatriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    int* sumas = sumaFilas(M, n, m);
    cout << "\nVector de suma de filas: " << endl;
    for (int i = 0; i < n; i++)
        cout << "Suma " << i + 1 << ": " << sumas[i] << endl;
    liberarMatriz(M, n);
    delete[] sumas;
    sumas = nullptr;
    return 0;
}