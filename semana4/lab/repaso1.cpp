#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
void leerDatos(int codigo[], float nota[], int faltas[], int n) { //fun para leer datos
    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << (i + 1) << ":" << endl;
        cout << "  Código: ";
        cin >>codigo[i];
        cout << "  Nota (0-20): ";
        cin >>nota[i];       
        cout << "  Faltas: ";
        cin >>faltas[i];
    }
}

//Ordenar estudiantes por nota -Si tienen misma nota, el que tiene menos faltas va primero
void ordenarPorNota(float nota[], int codigo[], int faltas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool intercambiar = false;
            // Criterio 1: Mayor nota primero
            if (*(nota + j) < *(nota + j + 1)) {
                intercambiar = true;
            }
            // Criterio 2: Si tienen misma nota, menos faltas primero
            else if (*(nota + j) == *(nota + j + 1)) {
                if (*(faltas + j) > *(faltas + j + 1)) {
                    intercambiar = true;
                }
            }
            
            if (intercambiar) {
                // Intercambiar nota
                float tempNota = *(nota + j);
                *(nota + j) = *(nota + j + 1);
                *(nota + j + 1) = tempNota;
                
                // Intercambiar código
                int tempCodigo = *(codigo + j);
                *(codigo + j) = *(codigo + j + 1);
                *(codigo + j + 1) = tempCodigo;
                
                // Intercambiar faltas
                int tempFaltas = *(faltas + j);
                *(faltas + j) = *(faltas + j + 1);
                *(faltas + j + 1) = tempFaltas;
            }
        }
    }
}

// 3.3. Mostrar ranking académico
void mostrarRanking(int codigo[], float nota[], int faltas[], int n) {
    cout << "\n=== RANKING ACADÉMICO ===" << endl;
    int top = (n < 5) ? n : 5;
    for (int i = 0; i < top; i++) {
        cout << (i + 1) << ". Código: " <<codigo[i] 
             << " | Nota: " <<nota[i] 
             << " | Faltas: " <<faltas[i]<< endl;
    }
    
    // Calcular promedio del curso
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += *(nota + i);
    }
    float promedio = suma / n;
    cout << "\n--- PROMEDIO DEL CURSO: " << promedio << " ---" << endl;
    
    // Contar desaprobados (nota < 10)
    int desaprobados = 0;
    for (int i = 0; i < n; i++) {
        if (*(nota + i) < 10) {
            desaprobados++;
        }
    }
    cout << "--- DESAPROBADOS (nota < 10): " << desaprobados << " ---" << endl;
}

// 3.4. Búsqueda secuencial por código
void busquedaSecuencial(int codigo[], float nota[], int faltas[], int n, int clave) {
    cout << "\n=== BÚSQUEDA SECUENCIAL ===" << endl;
    cout << "Buscando código: " << clave << endl;
    
    for (int i = 0; i < n; i++) {
        if (*(codigo + i) == clave) {
            cout << "\n¡Estudiante encontrado!" << endl;
            cout << "  Código: " << *(codigo + i) << endl;
            cout << "  Nota: " << *(nota + i) << endl;
            cout << "  Faltas: " << *(faltas + i) << endl;
            cout << "  Posición en el ranking: " << (i + 1) << endl;
            return;
        }
    }
    
    cout << "Estudiante no encontrado." << endl;
}

// 3.5. Ordenar por código ascendente usando Selection Sort
void ordenarPorCodigo(int codigo[], float nota[], int faltas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        
        // Buscar el mínimo en el resto del arreglo
        for (int j = i + 1; j < n; j++) {
            if (*(codigo + j) < *(codigo + minIdx)) {
                minIdx = j;
            }
        }
        
        // Intercambiar código
        int tempCodigo = *(codigo + i);
        *(codigo + i) = *(codigo + minIdx);
        *(codigo + minIdx) = tempCodigo;
        
        // Intercambiar nota
        float tempNota = *(nota + i);
        *(nota + i) = *(nota + minIdx);
        *(nota + minIdx) = tempNota;
        
        // Intercambiar faltas
        int tempFaltas = *(faltas + i);
        *(faltas + i) = *(faltas + minIdx);
        *(faltas + minIdx) = tempFaltas;
    }
}

// 3.6. Búsqueda binaria (requiere arreglo ordenado por código)
int busquedaBinaria(int codigo[], int n, int clave) {
    int izq = 0;
    int der = n - 1;
    
    while (izq <= der) {
        int medio = (izq + der) / 2;
        
        if (*(codigo + medio) == clave) {
            return medio; // Encontrado
        }
        else if (*(codigo + medio) < clave) {
            izq = medio + 1;
        }
        else {
            der = medio - 1;
        }
    }
    
    return -1; // No encontrado
}

void mostrarBusquedaBinaria(int codigo[], float nota[], int faltas[], int n, int clave) {
    cout << "\n=== BÚSQUEDA BINARIA ===" << endl;
    cout << "Buscando código: " << clave << endl;
    
    int pos = busquedaBinaria(codigo, n, clave);
    
    if (pos != -1) {
        cout << "\n¡Estudiante encontrado!" << endl;
        cout << "  Código: " << *(codigo + pos) << endl;
        cout << "  Nota: " << *(nota + pos) << endl;
        cout << "  Faltas: " << *(faltas + pos) << endl;
        cout << "  Posición en arreglo ordenado por código: " << (pos + 1) << endl;
    }
    else {
        cout << "Estudiante no encontrado." << endl;
    }
}

// Función auxiliar para mostrar todos los datos
void mostrarTodos(int codigo[], float nota[], int faltas[], int n, const char* titulo) {
    cout << "Pos | Código | Nota  | Faltas" << endl;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << "   | " <<codigo[i]<< "     | " 
             <<nota[i]<< "   | " <<faltas[i]<< endl;
    }
}

int main() {
    int n;
    cout <<"Ingrese el número de estudiantes: ";
    cin >> n;
    int codigo[100];     // Declarar arreglos paralelos
    float nota[100];
    int faltas[100];
    leerDatos(codigo, nota, faltas, n);   //leer datos    
    // 3.2. Ordenar por nota (mayor a menor)
    ordenarPorNota(nota, codigo, faltas, n);
    // 3.3. Mostrar ranking
    mostrarRanking(codigo, nota, faltas, n);
    
    
    // 3.4. Búsqueda secuencial
    int codigoBuscar;
    cout << "\n\nIngrese código a buscar (búsqueda secuencial): ";
    cin >> codigoBuscar;
    busquedaSecuencial(codigo, nota, faltas, n, codigoBuscar);
    
    // 3.5. Ordenar por código ascendente
    ordenarPorCodigo(codigo, nota, faltas, n);
    mostrarTodos(codigo, nota, faltas, n, "DATOS ORDENADOS POR CÓDIGO (ASCENDENTE)");
    
    // 3.6. Búsqueda binaria
    cout << "\nIngrese código a buscar (búsqueda binaria): ";
    cin >> codigoBuscar;
    mostrarBusquedaBinaria(codigo, nota, faltas, n, codigoBuscar);
    
    return 0;
}