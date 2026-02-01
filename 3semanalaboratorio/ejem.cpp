#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip> // Para dar formato a la tabla sin printf

using namespace std;

const int N = 3;

void separar_palabra(char datos[N][100], char nombres[N][100], char direcciones[N][100], char celulares[N][20], char* edades, char* talla) {
    for (int i = 0; i < N; i++) {
        char* token;
        
        // 1. Nombre
        token = strtok(*(datos + i), ",");
        if (token != NULL) strcpy(*(nombres + i), token);

        // 2. Dirección
        token = strtok(NULL, ",");
        if (token != NULL) strcpy(*(direcciones + i), token);

        // 3. Celular
        token = strtok(NULL, ",");
        if (token != NULL) strcpy(*(celulares + i), token);

        // 4. Edad (Guardado como valor numérico en un char)
        token = strtok(NULL, ",");
        if (token != NULL) *(edades + i) = (char)atoi(token);

        // 5. Talla (Guardado como valor numérico en un char)
        // Nota: Si la talla es decimal (ej. 1.56), atoi la truncará a 1. 
        // Si necesitas decimales exactos, el tipo de dato debe ser float.
        token = strtok(NULL, ",");
        if (token != NULL) *(talla + i) = (char)atof(token); 
    }
}

int main() {
    char datos[N][100];
    char nombres[N][100];
    char direcciones[N][100];
    char celulares[N][20];
    char edades[N];
    char talla[N];

    for (int i = 0; i < N; i++) {
        cout << "Ingrese entrada " << i + 1 << ":" << endl;
        cin.getline(*(datos + i), 100);
    }

    separar_palabra(datos, nombres, direcciones, celulares, edades, talla);

    cout << "\nLos datos guardados en el directorio son:" << endl;

    // Configuración de la cabecera usando manipuladores de iomanip
    cout << left << setw(20) << "Nombre" 
         << setw(30) << "Direccion" 
         << setw(15) << "Celular" 
         << setw(10) << "Edad" 
         << setw(10) << "Talla" << endl;

    for (int i = 0; i < N; i++) {
        cout << left << setw(20) << *(nombres + i)
             << setw(30) << *(direcciones + i)
             << setw(15) << *(celulares + i)
             // Casteamos a (int) para que cout imprima el número y no el símbolo ASCII
             << setw(10) << (int)*(edades + i) 
             << setw(10) << (int)*(talla + i) << endl;
    }

    return 0;
}