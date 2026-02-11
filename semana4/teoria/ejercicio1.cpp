/*
Implemente un programa para gestionar notas de un curso utilizando asignación dinámica. El programa debe:
1.1. Solicitar al usuario el número n de estudiantes.
1.2. Reservar memoria dinámica para almacenar las notas float notas[n]
1.3. Leer las notas desde el teclado
1.4. Calcular: Promedio del curso. Nota máxima y mínima
1.5. Redimensionar dinámicamente el arreglo para agregar k estudiantes.
1.6. Leer las nuevas notas
1.7. Recalcular los valores (1.4)
1.8. Liberar correctamente la memoria
*/
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;
int main(){
    int n;
    cout<<"escribe el numero es estudiantes: "<<endl;
    cin>>n;
    float* vec=new float[n]();
    float promedio=0;
    int min=20,max=0;
    cout<<"escribe las notas de los estudiantes: "<<endl;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(vec[i]<min){
            min=vec[i];
        }
        if(vec[i]>max){
            max=vec[i];
        }
        promedio+=vec[i];
    }
    promedio=promedio/n;
    cout<<"el promeido es: "<<promedio<<endl;
    cout<<"el max es: "<<max<<endl;
    cout<<"el min es: "<<min<<endl;

    cout<<"agregando 3 estudiantes mas "<<endl;

    float* vec2=new float[n+3];
    for(int i=0;i<n;i++){
        vec2[i]=vec[i];
    }
    delete[] vec;
    vec=nullptr;

    cout<<"escribe las notas de los 3 estudiantes agregados"<<endl;
    for(int i=n;i<n+3;i++){
        cin>>vec2[i];
        if(vec2[i]<min){
            min=vec2[i];
        }
        if(vec2[i]>max){
            max=vec2[i];
        }
    }
    float promedio2=0;
    for(int i=0;i<n+3;i++){
        promedio2+=vec2[i];
    }
    promedio2=promedio2/(n+3);
    cout<<"el nuevo promedio es: "<<promedio2<<endl;
    cout<<"el nuevo min es: "<<min<<endl;
    cout<<"el nuevo max es: "<<max<<endl;
    delete[] vec2;
    vec2=nullptr;

    return 0;
}

