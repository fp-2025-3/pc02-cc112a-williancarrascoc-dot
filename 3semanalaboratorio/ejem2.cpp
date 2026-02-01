#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int N = 9;

void intercambiar(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void perturbacion(int *fila){

    for(int i=0; i<N; i++){
        *(fila + i) = i + 1;       //Llenar una fila de 1,2,....,9
    }

    for(int i=N-1; i>0; i--){
        int j = rand() % (i+1);    //Generar la permutacion por el algoritmo de Fisher - Yates
        intercambiar((fila + i),(fila + j));
    }
}


void imprimir(int **Matriz){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<*(*(Matriz + i) + j) <<" ";
        }
        cout<<endl;
    }
}

int buscar(int** Matriz, int fil, int col){

    if(fil < 9 && col < 9){
        return *(*(Matriz + fil) + col);
    }
    return -1;
}

int buscarIndice(int* fila, int valor){
    for(int i=0; i<N; i++){
        if(*(fila + i) == valor){
            return i;
        }
    }
    return -1;
}

void rotar(int *fila, int valor, int colDestino){

    int colActual = buscarIndice(fila, valor);
    if(colActual == colDestino){
        return;
    }

    int dif = colActual - colDestino;
    int temp[9];

    for(int i=0; i<N; i++){
        int indOrigen = (i + dif + N) % N;
        *(temp + i) = *(fila + indOrigen);
    }

    for(int i=0; i<N; i++){
        *(fila + i) = *(temp + i);
    }
}

int main(){

    srand(time(NULL));
    int Datos[N][N];
    int *Matriz[N];  // Creamos un arreglo de punteros donde cada uno apunta al inicio de una fila de 'datos'

    for(int i=0; i<N; i++){
        *(Matriz + i) = *(Datos + i);
        perturbacion(*(Matriz + i));
    }

    cout<<"-------Arreglo Original--------"<<endl;
    imprimir(Matriz);
    cout<<endl;

    int fil, col;
    cout<<"Ingrese la fila inicial (0-9): ";
    cin>>fil;
    cout<<"Ingrese la columna inicial (0-9): ";
    cin>>col;

    int valor = buscar(Matriz, fil-1, col-1);

    if(valor != -1){
        cout<<"El valor seleccionado es: "<< valor <<endl;
    }else{
        cout<<"El valor no se encuentra en el rango "<<endl;
    }

    for(int i=0; i<N; i++){
        rotar(*(Matriz + i), valor, col);
    }
    cout<<"-------Arreglo Rotado--------"<<endl;
    imprimir(Matriz);

    return 0;
}