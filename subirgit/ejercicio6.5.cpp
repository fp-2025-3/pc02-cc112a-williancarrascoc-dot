/*
dado una lista de nombre
char nombre[][20]={
"lesly",
"americo",
"xingbeck",
"willian",
"julio",
"darwin",
"kevin"
};

1. ordenar la lista en orden alfabetico ascendente 
2. no usar []
    -use aritmetica de punteros
    -puede usar las funciones que implemento


*/

#include<iostream>
#include<cstring>
using namespace std;
void ordenar(const char** nombre,int n){
    for(const char** i=nombre;i<nombre+n-1;++i){
        for(const char**j=i+1;j<nombre+n;++j){
            if(strcmp(*i,*j)>0){
            const char* aux=*i;
            *i=*j;
            *j=aux;
            }
        }
    }
}

void imprimir(const char **nombre,int n){
    for(const char **i=nombre;i<nombre+n;i++){
        cout<<*i<<endl;
    }

}

int main(){
    const char* nombre[]={"Lesly","Americo","Xngbeck","Willian","Julio","Darwin","Kevin"};
    ordenar(nombre,7);
    cout<<"arreglo ordenado :"<<endl;
    imprimir(nombre,7);


    return 0;
}


