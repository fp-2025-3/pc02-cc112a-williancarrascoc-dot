#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;
int calcularProducto(int *A, int inicio, int fin) {
    int producto = 1;
    for(int i = inicio; i <= fin; i++) {
        producto *= *(A + i);
    }
    return producto;
}

int costoMaximoSegmentacion(int *A, int pos, int n) {
    if(pos >= n) {
        return 0;
    }
    int costoMaximo = 0;
    for(int fin = pos; fin < n; fin++) {
        int valorSegmento = calcularProducto(A, pos, fin);
        int costoResto = costoMaximoSegmentacion(A, fin + 1, n);
        int costoTotal = valorSegmento + costoResto;
        if(costoTotal > costoMaximo) {
            costoMaximo = costoTotal;
        }
    }
    return costoMaximo;
}

int main() {
    int A1[] = {2, 1, 3};
    int n1 = 3;
    
    cout << "Arreglo A = [2, 1, 3]\n";
    cout << "Costo maximo: " << costoMaximoSegmentacion(A1, 0, n1) << "\n\n";
    
    return 0;
}

/*
costoMaximoSegmentacion(A, pos=0, n=3)
│
├─ for(fin=0; fin<3; fin++)
│  │
│  ├─ fin=0: valorSegmento = calcularProducto(A,0,0) = 2
│  │         costoResto = costoMaximoSegmentacion(A, pos=1, n=3)
│  │         │
│  │         └─ for(fin=1; fin<3; fin++)
│  │            │
│  │            ├─ fin=1: valorSegmento = calcularProducto(A,1,1) = 1
│  │            │         costoResto = costoMaximoSegmentacion(A, pos=2, n=3)
│  │            │         │
│  │            │         └─ for(fin=2; fin<3; fin++)
│  │            │            │
│  │            │            └─ fin=2: valorSegmento = calcularProducto(A,2,2) = 3
│  │            │                      costoResto = costoMaximoSegmentacion(A, pos=3, n=3)
│  │            │                      │
│  │            │                      └─ pos>=n → RETORNA 0
│  │            │                      │
│  │            │                      costoTotal = 3 + 0 = 3
│  │            │                      costoMaximo = 3
│  │            │            │
│  │            │            RETORNA 3
│  │            │         │
│  │            │         costoTotal = 1 + 3 = 4
│  │            │         costoMaximo = 4
│  │            │
│  │            └─ fin=2: valorSegmento = calcularProducto(A,1,2) = 1*3 = 3
│  │                      costoResto = costoMaximoSegmentacion(A, pos=3, n=3)
│  │                      │
│  │                      └─ pos>=n → RETORNA 0
│  │                      │
│  │                      costoTotal = 3 + 0 = 3
│  │                      costoMaximo = max(4, 3) = 4
│  │            │
│  │            RETORNA 4
│  │         │
│  │         costoTotal = 2 + 4 = 6
│  │         costoMaximo = 6
│  │
│  ├─ fin=1: valorSegmento = calcularProducto(A,0,1) = 2*1 = 2
│  │         costoResto = costoMaximoSegmentacion(A, pos=2, n=3)
│  │         │
│  │         └─ for(fin=2; fin<3; fin++)
│  │            │
│  │            └─ fin=2: valorSegmento = calcularProducto(A,2,2) = 3
│  │                      costoResto = costoMaximoSegmentacion(A, pos=3, n=3)
│  │                      │
│  │                      └─ pos>=n → RETORNA 0
│  │                      │
│  │                      costoTotal = 3 + 0 = 3
│  │                      costoMaximo = 3
│  │            │
│  │            RETORNA 3
│  │         │
│  │         costoTotal = 2 + 3 = 5
│  │         costoMaximo = max(6, 5) = 6
│  │
│  └─ fin=2: valorSegmento = calcularProducto(A,0,2) = 2*1*3 = 6
│            costoResto = costoMaximoSegmentacion(A, pos=3, n=3)
│            │
│            └─ pos>=n → RETORNA 0
│            │
│            costoTotal = 6 + 0 = 6
│            costoMaximo = max(6, 6) = 6
│
RETORNA 6
*/