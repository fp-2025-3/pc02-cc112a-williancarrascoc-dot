//dada la siguiente cadena "--Aqui tenemos, un ejemplo de cadena.", escribir una funcion 
//que elimine los caracteres -,y .
//la salida debe ser: "Aqui tenemos un ejemplo de cadena"
#include<iostream>
#include<cstring>
using namespace std;
void eliminaCaracteres(char* cadena){
    char* reCadena=cadena;
    char* resultado=cadena;
    while(*resultado!='\0'){
        if(*reCadena!='-'&& *reCadena != '.' && *reCadena != ','){
            *resultado = *reCadena;
            resultado++;
        }
        reCadena++;
    }
    *resultado='\0';
}
int main(){
    char elgato[50]= "--Aqui tenemos, un ejemplo de cadena.";
    char* p=elgato;
    eliminaCaracteres(p);
    cout<<elgato<<endl;

    return 0;
}