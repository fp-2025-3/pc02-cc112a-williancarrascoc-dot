#include<iostream>
using namespace std;

//ESTRUCTURA AUTOREFERENCIADA 
struct producto{
    int codigo;
    float precio;
    producto *sig;
};

int main(){
    producto* cabeza = nullptr;

    //insertar producto al inicio

    for(int i=0;i<2;i++){
        producto* nuevo=new producto;
        cout<<"ingrese codigo: ";cin>>nuevo->codigo;
        cout<<"ingrese precio: ";cin>>nuevo->precio;
        nuevo->sig = cabeza;
        cabeza= nuevo;
    }

    return 0;
}