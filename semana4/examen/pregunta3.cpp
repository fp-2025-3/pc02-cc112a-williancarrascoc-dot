#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;
int esFilaDominanteEstricta(int (*M)[4], int f) {
    int existeEstricto = 0;

    for(int j = 0; j < 4; j++) {
        int esMayorIgual = 1;
        int esMayorEstricto = 1;

        for(int i = 0; i < 4; i++) {
            if(i != f) {
                if(*(*(M + f) + j) < *(*(M + i) + j)) {
                    esMayorIgual = 0;
                    esMayorEstricto = 0;
                    break;
                }
                if(*(*(M + f) + j) == *(*(M + i) + j)) {
                    esMayorEstricto = 0;
                }
            }
        }
        if(!esMayorIgual) {
            return 0;
        }
        if(esMayorEstricto) {
            existeEstricto = 1;
        }
    }
    return existeEstricto;
}

int esFilaFuertementeDominante(int (*M)[4], int f) {
    if(!esFilaDominanteEstricta(M, f)) {
        return 0;
    }

    int sumaF = 0;
    for(int j = 0; j < 4; j++) {
        sumaF += *(*(M + f) + j);
    }

    for(int i = 0; i < 4; i++) {
        if(i != f) {
            int sumaI = 0;
            for(int j = 0; j < 4; j++) {
                sumaI += *(*(M + i) + j);
            }

            if(sumaF <= sumaI) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int M[4][4] = {
        {2, 3, 1, 4},
        {1, 2, 3, 2},
        {5, 6, 7, 8},
        {0, 1, 2, 1}
    };
    cout << "Fila\tDominante Estricta\tFuertemente Dominante\n";
    cout << "----\t------------------\t---------------------\n";
    
    for(int f = 0; f < 4; f++) {
        int domEstricta = esFilaDominanteEstricta(M, f);
        int domFuerte = esFilaFuertementeDominante(M, f);
        cout << f << "\t" << (domEstricta ? "SI" : "NO") << "\t\t\t" << (domFuerte ? "SI" : "NO") << "\n";
    }
    
    return 0;
}
