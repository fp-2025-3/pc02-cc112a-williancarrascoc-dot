#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

const int N = 5;

// Función auxiliar para leer la matriz
void leerMatriz(int (*M)[N]) {
    cout << "Ingrese los elementos de la matriz " << N << "x" << N << ":" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Fila " << (i + 1) << ": ";
        for (int j = 0; j < N; j++) {
            cin >> *(*(M + i) + j);
        }
    }
}

// Función auxiliar para mostrar la matriz
void mostrarMatriz(int (*M)[N]) {
    cout << "\nMatriz:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(M + i) + j) << "\t";
        }
        cout << endl;
    }
}

// 1. Verificar si una fila es dominante
// Una fila es dominante si cada elemento es estrictamente mayor
// que el elemento correspondiente de TODAS las demás filas
bool esFilaDominante(int (*M)[N], int fila) {
    // Para cada columna j
    for (int j = 0; j < N; j++) {
        int elementoFila = *(*(M + fila) + j);
        
        // Comparar con todas las demás filas
        for (int i = 0; i < N; i++) {
            if (i == fila) continue; // Saltar la misma fila
            
            int elementoOtraFila = *(*(M + i) + j);
            
            // Si no es estrictamente mayor, no es dominante
            if (elementoFila <= elementoOtraFila) {
                return false;
            }
        }
    }
    
    return true;
}

// 2. Contar columnas críticas
// Una columna es crítica si su suma es mayor que la suma de CUALQUIER fila
int contarColumnasCriticas(int (*M)[N]) {
    int columnasCriticas = 0;
    
    // Primero calculamos las sumas de todas las filas
    int sumaFilas[N];
    for (int i = 0; i < N; i++) {
        int suma = 0;
        for (int j = 0; j < N; j++) {
            suma += *(*(M + i) + j);
        }
        *(sumaFilas + i) = suma;
    }
    
    // Encontrar la suma máxima de las filas
    int maxSumaFila = *(sumaFilas + 0);
    for (int i = 1; i < N; i++) {
        if (*(sumaFilas + i) > maxSumaFila) {
            maxSumaFila = *(sumaFilas + i);
        }
    }
    
    // Ahora verificamos cada columna
    for (int j = 0; j < N; j++) {
        int sumaColumna = 0;
        
        // Calcular suma de la columna j
        for (int i = 0; i < N; i++) {
            sumaColumna += *(*(M + i) + j);
        }
        
        // Verificar si es mayor que TODAS las filas
        // Es decir, mayor que la máxima suma de fila
        if (sumaColumna > maxSumaFila) {
            columnasCriticas++;
        }
    }
    
    return columnasCriticas;
}

// 3. Verificar si la matriz es escalonada
// Una matriz es escalonada si el primer elemento no nulo de cada fila
// aparece en una columna mayor que el de la fila anterior
bool esMatrizEscalonada(int (*M)[N]) {
    int columnaAnterior = -1; // Columna del primer no nulo de la fila anterior
    
    for (int i = 0; i < N; i++) {
        int columnaPrimerNoNulo = -1;
        
        // Buscar el primer elemento no nulo en la fila i
        for (int j = 0; j < N; j++) {
            if (*(*(M + i) + j) != 0) {
                columnaPrimerNoNulo = j;
                break;
            }
        }
        
        // Si la fila es toda ceros, continuar
        if (columnaPrimerNoNulo == -1) {
            continue;
        }
        
        // Verificar que esté en columna estrictamente mayor
        if (columnaPrimerNoNulo <= columnaAnterior) {
            return false;
        }
        
        columnaAnterior = columnaPrimerNoNulo;
    }
    
    return true;
}

// 4. Encontrar el valor del núcleo de la matriz
// El núcleo es un elemento que es:
// - Máximo de su fila
// - Mínimo de su columna
int valorNucleo(int (*M)[N]) {
    // Revisar cada elemento de la matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int elemento = *(*(M + i) + j);
            bool esMaximoFila = true;
            bool esMinimoColumna = true;
            
            // Verificar si es máximo de su fila
            for (int k = 0; k < N; k++) {
                if (*(*(M + i) + k) > elemento) {
                    esMaximoFila = false;
                    break;
                }
            }
            
            // Verificar si es mínimo de su columna
            for (int k = 0; k < N; k++) {
                if (*(*(M + k) + j) < elemento) {
                    esMinimoColumna = false;
                    break;
                }
            }
            
            // Si cumple ambas condiciones, es el núcleo
            if (esMaximoFila && esMinimoColumna) {
                return elemento;
            }
        }
    }
    
    return -1; // No existe núcleo
}

int main() {
    int M[N][N];
    
    cout << "=== ANÁLISIS DE MATRIZ ===" << endl;
    
    // Leer matriz
    leerMatriz(M);
    mostrarMatriz(M);
    
    // 1. Verificar filas dominantes
    cout << "\n=== 1. FILAS DOMINANTES ===" << endl;
    bool hayDominante = false;
    for (int i = 0; i < N; i++) {
        if (esFilaDominante(M, i)) {
            cout << "La fila " << i << " es DOMINANTE" << endl;
            hayDominante = true;
        }
    }
    if (!hayDominante) {
        cout << "No hay filas dominantes." << endl;
    }
    
    // 2. Contar columnas críticas
    cout << "\n=== 2. COLUMNAS CRÍTICAS ===" << endl;
    int criticas = contarColumnasCriticas(M);
    cout << "Número de columnas críticas: " << criticas << endl;
    
    // 3. Verificar si es matriz escalonada
    cout << "\n=== 3. MATRIZ ESCALONADA ===" << endl;
    if (esMatrizEscalonada(M)) {
        cout << "La matriz ES escalonada" << endl;
    } else {
        cout << "La matriz NO es escalonada" << endl;
    }
    
    // 4. Encontrar valor del núcleo
    cout << "\n=== 4. VALOR DEL NÚCLEO ===" << endl;
    int nucleo = valorNucleo(M);
    if (nucleo != -1) {
        cout << "Valor del núcleo: " << nucleo << endl;
    } else {
        cout << "No existe núcleo en la matriz" << endl;
    }
    
    return 0;
}