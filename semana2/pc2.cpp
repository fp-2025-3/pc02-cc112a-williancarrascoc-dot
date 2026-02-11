/*
Escribe una funcion rev() que tome un argumento de cadena de estilo C(C-string) e invierta los caracteres 
que contiene. Es decir, después de rev(p) el último carácter de p será el primero, etc.
ejemplo de entrada: 
    Abejita
ejemplo de salida: 
    atijebA
*/

#include<iostream>
#include<cstring>
using namespace std;
void rev(char* p){
    int n=strlen(p);
    for(int i=0;i<n/2;i++){
        char aux=p[i];
        p[i]=p[n-1-i];
        p[n-1-i]=aux;
    }
}

int main(){
    char palabra[]="dinosaurio";
    rev(palabra);
    cout<<palabra<<endl;

    return 0;
}