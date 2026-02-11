//implemente una funcion que invierta una cadena 
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cctype>
using namespace std;
void invertir(char* p){
    for(size_t i=0;i<strlen(p)/2;i++){
        char aux;
        aux=*(p+i);
        *(p+i)=*(p+strlen(p)-1-i);
        *(p+strlen(p)-1-i)=aux;
    }
}
int main(){
    char palabra[100];
    char* p=palabra;
    cout<<"escribe una palabra: "<<endl;
    cin.getline(p,100);
    invertir(p);
    for(size_t i=0;i<strlen(p);i++){
        cout<<*(p+i)<<" ";
    }
    cout<<endl;
    
    return 0;
}