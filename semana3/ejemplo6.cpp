/*
dado una lista de nombres almacenados en un arreglo
de cadenas, utilice punteros a cadenas de caracteres y
1. escriba una funcion que determine si un nombre esta o no en el arreglo
2.escriba una funcion que permita concatenar 2 nombre elegidos
3.escriba una funcion que permita encontrar una subcadena
*/
#include<iostream>
#include<cstring>
using namespace std;
bool busqueda(const char* nombres[],int n,const char* nombre){
    for(int i=0;i<n;i++){
        if(strcmp(*(nombres+i),nombre)==0){
            return true;
        }
    }
    return false;
} 
void concatenar(const char* a,const char* b){
    char aux[20]="";
    strcat(aux,a);
    strcat(aux,b);
    cout<<aux;
    cout<<endl;
}
void buscar(const char** palabra,int n,const char* letra){
    bool band=false;
        for(int i=0;i<n;i++){
            if(strstr(palabra[i],letra)!=nullptr){
                cout<<"se encontro la palabra y esta en la posicion: "<<i<<endl;
                band=true;
        }
    }
        if(band==false){
            cout<<"no se encontro la palabra"<<endl;
        }
}
int main(){
    const char *palabra[6]={"Alejandra","Beti","Carmen","Doris","Estefani","Federica"};
    int n=6;
    const char* nombre={"Carmen"};
    const char* nombre2={"Beti"};
    char letra[20];
    cout<<"escribe la subcadena que quieres buscar: ";
    cin.getline(letra,20);

    if(busqueda(palabra,n,nombre)){
        cout<<"el nombre si esta en el arreglo"<<endl;
    }else{
        cout<<"el nombre no esta en el arreglo"<<endl;
    }
    concatenar(nombre,nombre2);
    buscar(palabra,n,letra);

    return 0;
}