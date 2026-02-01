/*
#include<iostream>
#include<cstring>
using namespace std;
void contar(const char* cad[],int n){
    float promedio=0;
    for(int i=0;i<n;i++){
        promedio=promedio+strlen(*(cad+i));
    }
    promedio=promedio/n;
    for(int i=0;i<n;i++){
        if((strlen(*(cad+i)))>promedio){
            cout<<*(cad+i);
        }
        cout<<endl;
    }
}
int main(){
    const char* cad[]={"elgato", "vivaelvino", "lapazesvida","perro"};
    int n=sizeof(cad)/sizeof(cad[0]);   //4
    contar(cad,n);

    return 0;
}
    */


//
#include<iostream>
#include<cstring>
using namespace std;
void contar(const char** cad, int n){
    const char** fin=cad+n;
    float promedio=0;
    for(const char** p=cad;p<fin;p++){
        promedio+=strlen(*p);
    }
    promedio/=n;
    for(const char** p=cad;p<fin;p++){
        if(strlen(*p)>promedio){
            cout<<*p<<endl;
        }
    }
}
int main(){
    const char* cad[]={"elgato", "vivaelvino", "lapazesvida","perro"};
    int n=sizeof(cad)/sizeof(cad[0]);   //4
    contar(cad,n);

    return 0;
}


