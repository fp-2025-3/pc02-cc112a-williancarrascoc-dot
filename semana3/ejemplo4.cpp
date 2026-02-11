#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cctype>
using namespace std;
int main(){
    char palabra[100];
    int m=0;
    const char* buscar="UNI";
    cout<<"escribe una contraseña"<<endl;
    cin.getline(palabra,100);
    size_t n=strlen(palabra);
    bool band=true;
    bool band2=false;
    char* encontrar=strstr(palabra,buscar);

    for(size_t i=0;i<n;i++){
        if(!isalnum(palabra[i])){
            cout<<"caracter no valido en la posicion "<<i<<endl;
            band=false;
    }
        if(isdigit(palabra[i])){
            m=m+(palabra[i]-'0');

        }
}
        if(encontrar!=NULL){
            band2=true;
        }
    if(band==false){
        cout<<"la contraseña no cumple con los requisitos "<<endl;
    }else{
        cout<<"la contraseña cumplio con los requisitos "<<endl;
    }
    cout<<"la suma de numeros total es: "<<m<<endl;
    if(band2==true){
        cout<<"se encontro la palabra UNI y esta en la posicion: "<<(encontrar-palabra)<<endl;
    }else{
        cout<<"no se encontro la palabra"<<endl;
    }
    return 0;
}