#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// Definición de constantes para límites
const int MAX_PERSONAS = 100;
const int MAX_STR = 100;

int main() {
    int N;
    cout << "Ingrese cantidad de entradas (N): ";
    cin >> N;
    cin.ignore(); // Limpiar el buffer tras leer N

    // Arreglos independientes según lo solicitado
    char nombres[MAX_PERSONAS][MAX_STR];
    char direcciones[MAX_PERSONAS][MAX_STR];
    char celulares[MAX_PERSONAS][MAX_STR];
    int edades[MAX_PERSONAS];
    float tallas[MAX_PERSONAS];

    int validos = 0;

    for (int i = 0; i < N; i++) {
        char buffer[500];
        cout << "Ingrese entrada " << i + 1 << ": ";
        cin.getline(buffer, 500);

        // Contar comas para validar el formato (deben ser exactamente 4 para 5 campos)
        int comas = 0;
        for (int j = 0; buffer[j] != '\0'; j++) {
            if (buffer[j] == ',') comas++;
        }

        if (comas == 4) {
            // Extracción manual usando strtok (de <cstring>)
            char *ptr = strtok(buffer, ",");
            if (ptr) strcpy(nombres[validos], ptr);

            ptr = strtok(NULL, ",");
            if (ptr) strcpy(direcciones[validos], ptr);

            ptr = strtok(NULL, ",");
            if (ptr) strcpy(celulares[validos], ptr);

            ptr = strtok(NULL, ",");
            if (ptr) edades[validos] = atoi(ptr); // Transformación a entero

            ptr = strtok(NULL, ",");
            if (ptr) tallas[validos] = atof(ptr); // Transformación a decimal

            validos++;
        } else {
            cout << "[Error] Formato incorrecto. Entrada descartada." << endl;
        }
    }

    // Mostrar resultados en formato tabla
    cout << "\nLos datos guardados en el directorio son:" << endl;
    printf("%-20s %-30s %-15s %-5s %-5s\n", "Nombre", "Direccion", "Celular", "Edad", "Talla");
    
    for (int i = 0; i < validos; i++) {
        printf("%-20s %-30s %-15s %-5d %-5.2f\n", 
               nombres[i], direcciones[i], celulares[i], edades[i], tallas[i]);
    }

    return 0;
}