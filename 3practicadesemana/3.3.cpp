#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
    int alumnos,promedio=0;
    int arr1[100];
    cout<<"escribe la cantidad de alumnos: "<<endl;
    cin>>alumnos;

    cout<<"escribe las notas del alumno "<<endl;
    for(int i=0;i<5;i++){
        cin>>arr1[i];
    }


    for(int i=0;i<5;i++){
        promedio=promedio+arr1[i];
    }
    promedio=promedio/5;
    cout<<"promedio general: "<<promedio<<endl;
    if(promedio>=10){
        cout<<"A"<<endl;
    }else if(promedio<10){
        cout<<"D"<<endl;
    }


return 0;
}