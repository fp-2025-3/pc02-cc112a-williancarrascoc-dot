//utilizando punteros, implementar su propia funcion
#include<iostream>
#include<cstring>
using namespace std;
int my_strlen(const char* str){
    int contador=0;
    while(*str!='\0'){
        str++;
        contador++;
    }
    return contador;
}
int main(){
    const char p[]={"Fundamentos de Programacion"};
    cout<<"la cantidad de elementos son: "<<my_strlen(p)<<endl;
    cout<<strlen(p);


    return 0;
}


//pregunta porque debemos usar char* p = str en la funcion si recorren lo mismo