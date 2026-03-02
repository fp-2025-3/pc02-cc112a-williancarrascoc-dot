#include<iostream>
#include<fstream>
using namespace std;
void escribir(const string& archivo){
    int* m=new int[7];
    ofstream escribirarchivo;
    escribirarchivo.open(archivo,ios::out);
    cout<<"escribe las ventas de cada dia"<<endl;
    for(int i=0;i<7;i++){
        cin>>m[i];
    }
    for(int i=0;i<7;i++){
        escribirarchivo<<m[i]<<endl;
    }
    escribirarchivo.close();
    delete[] m;

}
void promedio(const string archivo){
    ifstream contararchivo;
    contararchivo.open(archivo,ios::in);


    int tot=0;
    int ventas;
    while(contararchivo>>ventas){
        tot+=ventas;
    }
    cout<<"el promedio es: "<<tot/7<<endl;
    contararchivo.close();

}
void mayor(const string archivo){
    ifstream mayornum;
    mayornum.open(archivo,ios::in);
    int venta;
    int mayor=0;
    while(mayornum>>venta){
        if(venta>mayor){
            mayor=venta;
        }
    }
    cout<<"mayor venta: "<<mayor<<endl;
    mayornum.close();
}
void menor(const string archivo){
    ifstream leerarchivo;
    leerarchivo.open(archivo,ios::in);
    int menor;
    int min=9999;
    while(leerarchivo>>menor){
        if(menor<min){
            min=menor;
        }
    }
    cout<<"menor venta: "<<min<<endl;
    leerarchivo.close();
}

int main(){
    string archivo("ventas.txt");
    escribir(archivo);
    promedio(archivo);
    mayor(archivo);
    menor(archivo);


    return 0;
}