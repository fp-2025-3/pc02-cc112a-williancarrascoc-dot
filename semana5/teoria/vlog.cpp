//estructuras;
#include<iostream>
using namespace std;
struct elgato{
    char nombre[20];
    int edad;
}elgato[100];
int main(){
    int n;
    cout<<"Escribe cuantos gatos vas a tener: "<<endl;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"nombre: ";
        cin.getline(elgato[i].nombre,20);
        cout<<"edad: ";
        cin>>elgato[i].edad;
        cin.ignore();
    }
    cout<<"enseñando todo: "<<endl;
    for(int i=0;i<n;i++){
        cout<<elgato[i].nombre;
        cout<<elgato[i].edad;
        cout<<endl;
    }

    return 0;
}