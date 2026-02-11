/*
escriba una funcion que convierta una cadena de caracteres de modo que las minusculas 
se conviertan en mayusculas y viceversa, mientras que los no alfabeticos se mantinen 
sin cambios
Ejemplo:   
estrada: "Veamos Su funCionamiento #@ 123!"
salida: "vEAMOS sU FUNcIONAMINETO #@ 123!"
*/
#include<iostream>
#include<cctype>
using namespace std;
void convertir(char* p){
    while(*p!='\0'){
        if(isalpha(*(p))){
            if(islower(*p)){
                *p=toupper(*p);
            }
            else if(isupper(*p)){
                *p=tolower(*p);
            }
        }
        p++;
    }
}
int main(){
    char elgato[]="Veamos Su funCionamiento #@ 123!";
    char* p=elgato;
    convertir(p);
    cout<<elgato<<endl;
    return 0;
}
