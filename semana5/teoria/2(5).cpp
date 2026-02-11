/*
Ejercicio 1
Se desea gestionar estudiantes, donde no se conoce de antemano cuántos habrá.
Cada estudiante tiene código y promedio
Escribir un programa que:
a) Solicitar al usuario la cantidad N de estudiantes
b) Reservar memoria dinámicamente para los N estudiantes
c) Leer los datos
d) Mostrar únicamente los aprobados (>= 10)
e) Liberar memoria correctamente
*/
#include<iostream>
using namespace std;
struct estudiate{
    int codigo;
    float promedio;
};

void leer(int &n, estudiate* &A){
    cout<<"escribe la cantidad de estudiantes: ";
    cin>>n;
    A=new estudiate[n];

    cout<<"rellenamos los datos: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"estudiante: "<<i<<endl;
        cout<<"el codigo: "; cin>>A[i].codigo;
        cout<<"el promedio: "; cin>>A[i].promedio;
        cout<<endl;
    }
}

void filtrar(int &n, estudiate* &A){
    int cont=0;
    for(int i=0;i<n;i++){
        if(A[i].promedio>=10){
            cont++;
        }
    }
    estudiate* e2=new estudiate[cont];
    for(int i=0;i<n;i++){
        if(A[i].promedio>=10){
        e2[i]=A[i];
        }
    }
    delete[] A;
    A=e2;
    n=cont;
}

void mostrar(int n, estudiate* A){
    for(int i=0;i<n;i++){
        cout<<"codigo: "<<A[i].codigo<<" -- promedio: "<<A[i].promedio;
        cout<<endl;
    }
}



int main(){
    int n;
    estudiate *A=nullptr;
    leer(n,A);
    filtrar(n,A);
    mostrar(n,A);
    delete[] A;
    A=nullptr;

}
