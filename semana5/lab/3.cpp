#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
struct seleccion{
    string nombre;
    int puntostot;
    int parjugados;
    int ganados;
    int empatados;
    int perdidos;
    float rendimiento;
};
void datos(int n, seleccion* &a){
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i].nombre="Pais_selccion "+to_string(i);
        a[i].parjugados=100;
    }

    for(int i=0;i<n;i++){
        a[i].ganados=0+rand()%100;
        a[i].empatados=0+rand()%(100-a[i].ganados);
        a[i].perdidos=(100-a[i].ganados-a[i].empatados);
    }
    for(int i=0;i<n;i++){
        a[i].puntostot=((a[i].ganados*3)+a[i].empatados*1);   
    }
    for(int i=0;i<n;i++){
        a[i].rendimiento=(a[i].puntostot/3.0);
    }

}

void mostrar(int n,seleccion* a){
    cout<<"SELECCION\t\t PG\tPP\tPE\tPUNTAJE\t\tRENDIMIENTO"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i].nombre<<"\t\t "<<a[i].ganados<<"\t "<<a[i].perdidos<<"\t "<<a[i].empatados<<"\t "<<a[i].puntostot<<" \t\t"<<a[i].rendimiento<<endl;
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(a[i].puntostot>max){
            max=a[i].puntostot;
        }
    }
    int pos=0;
    for(int i=0;i<n;i++){
        if(a[i].puntostot!=max){
            pos++;
            break;
        }
    }
    cout<<"la seleccion con mejor rendimiento es: "<<a[pos].nombre<<" con rendimiento "<<a[pos].rendimiento<<endl;

}

int main(){
    seleccion* a;
    const int n=5;
    a=new seleccion[n];
    datos(n,a);
    mostrar(n,a);
    delete[] a;
    a=nullptr;

    return 0;
}