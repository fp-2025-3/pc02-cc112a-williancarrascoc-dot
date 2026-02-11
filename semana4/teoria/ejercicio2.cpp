/*
Utilizando una matriz dinámica de tamaño n x m, implementar funciones para
2.1 Reservar memoria dinámica para una matriz
2.2. Llenar con valores aleatorios
2.3. Detectar que filas NO SON VÁLIDAS (Una fila es válida si la suma de sus elementos es par) 
Detectar que columnas NO SON VALIDAD (Una columna es válida si el máximo elemento de la columna es positivo)
2.4. Construir una nueva matriz dinámica que elimine todas las filas y columnas inválidas
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    const int n=3;
    int** vec;
    vec=new int*[n];
    for(int i=0;i<n;i++){
        vec[i]=new int[n];
    }
    
    srand(time(0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vec[i][j]=rand();
        }
    }
    int fila=0;
    int fil=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fila=fila+vec[i][j];
        }
        if(fila%2==0){
            cout<<"fila "<<i<<" es valida"<<endl;
            fil++;
        }
    }
    int columna=0;
    int col=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            columna=columna+vec[j][i];            
        }
        if(columna%2==0){
            cout<<"la columna "<<i<<" es valida"<<endl;
            col++;
        }
    }


    //falta completar


    return 0;
}