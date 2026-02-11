#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // char destino[5];
    char origen[] = "Programacion";
    char real[100];
    //strcpy(destino, origen);   //copia mas de lo que tiene
    //cout<<destino<<endl; //desbordamiento
    cout<<strcpy(real,origen)<<endl; 
}