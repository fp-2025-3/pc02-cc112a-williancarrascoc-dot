/*
Ejercicio 2
Implementar una agenda de contactos.
Cada contacto tiene nombre y fecha de nacimiento (estructura Fecha)
La cantidad de contactos es desconocida:
a) Reservar memoria dinámica para N contactos
b) Leer datos
c) y mostrar los nacidos en un año específico
*/
#include<iostream>
#include<cstring>
using namespace std;
struct fecha{
    int dia;
    int mes;
    int anio;
};

struct contacto{
    string nombre;
    fecha nacimiento;
};

void leer(int &n, contacto* &e1){
    cout<<"escribe la cantidad de persona en los contactos: "; cin>>n;
    cin.ignore();
    e1=new contacto[n];
    cout<<"rellenando datos: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"nombre: "; getline(cin,e1[i].nombre);
        cout<<"dia de nacimiento: ";cin>>e1[i].nacimiento.dia;
        cout<<"mes de nacimiento: ";cin>>e1[i].nacimiento.mes;
        cout<<"anio de nacimiento: ";cin>>e1[i].nacimiento.anio;
        cin.ignore();
    }
}

void enseñar(int n,contacto* e1){
    int x;
    int a=0;
    cout<<"escribe el año de nacimiento que quieres buscar: "; cin>>x;
    for(int i=0;i<n;i++){
        if(e1[i].nacimiento.anio==x){
        cout<<"el nombre es: "<<e1[i].nombre;
        cout<<"su dia de nacimiento es: "<<e1[i].nacimiento.dia<<endl;
        cout<<"su mes de nacimiento es; "<<e1[i].nacimiento.mes<<endl;
        cout<<"su anio de nacimiento es: "<<e1[i].nacimiento.anio<<endl;
        a++;
    }
}
    if(a==0){
        cout<<"no existe una persona en ese fecha"<<endl;
    }

}

int main(){
    int n;
    contacto* e1;
    leer(n,e1);
    enseñar(n,e1);
    delete[] e1;
    return 0;
}