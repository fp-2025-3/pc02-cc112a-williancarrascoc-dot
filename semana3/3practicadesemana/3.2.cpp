/*
#include<<cctype>
-comprueba si el caracter es alfanumerico   --- isalnum
-comprueba si el caracter es alfabetico  --- isalpha
-comprueba si el caracter es decimal  --- isdigit
-compruea si el caracter es minuscula   --- islower
-comprueba si el caracter es mayusucla  --- isupper
-convierte letra mayuscula en minuscula -- tolower
-convierte letra minuscula en mayuscula - toupper



#include<cstdlib>
-convierte cadena a entero  ---- atoi
-convierte cadena a doble --- atof
-genera un numero aleatorio  --- rand
-inicializa generador de numerso aleatorios    -srand

#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

    srand(time(NULL));
    // 2. Generar un número entre 0 y 99
    // El operador % (módulo) limita el rango
    int numero = rand() % 100; 
    std::cout << "Número aleatorio: " << numero << std::endl;
    // Fórmula para un rango [min, max]: 
    // rand() % (max - min + 1) + min


#include<cstring>
-retorna la longitud(numero de caracteres no nulos) -- strlen
-modifica s1 reemplazando sus caracteres por copias de los caracteres de s2 strcpy(s1,s2)
-modifica s1 concatenando s2 al final de s1 -- strcat(s1,s2)
-compara s1 y s2, retornando un entero negativo, 0 , o un entero positivo 
segun s1 es menor que, igual a, o mayor que s2  --- strcmp
*/
#include<iostream>
using namespace std;
int main(){
    return 0;
}