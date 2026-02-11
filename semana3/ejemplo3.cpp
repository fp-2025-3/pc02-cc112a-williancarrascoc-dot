#include<iostream>
using namespace std;
void cambiar(char primero[],char segundo[]){
    int i=0;
    while(segundo[i]!='\0'){
        primero[i]=segundo[i];
        i++;
    }
    primero[i]='\0';
}
int main(){
    char primero[]="primero";
    char segundo[]="segundo";
    char auxiliar[20];
    cambiar(auxiliar,primero);
    cambiar(primero,segundo);
    cambiar(segundo,auxiliar);
    cout<<primero<<endl;
    cout<<segundo<<endl;

    return 0;
}




























/*
#include<iostream>
using namespace std;
void cambiar(char a[],char b[],int n){

    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}
int main(){
    char primero[]={"primero"};
    char segundo[]={"segundo"};
    const int n=sizeof(primero)/(sizeof(primero[0]));
    char auxiliar[n];
    //char auxiliar[100];
    cambiar(primero,auxiliar,n);
    cambiar(segundo,primero,n);
    cambiar(auxiliar,segundo,n);
    for(int i=0;i<n;i++){
        cout<<primero[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<segundo[i]<<" ";
    }
    return 0;
} 
*/


























/*
#include<iostream>
using namespace std;
int main(){
    char primero[]={"primero"};
    char segundo[]={"segundo"};
    const int n=sizeof(primero)/(sizeof(primero[0]));
    char auxiliar[n];
    swap(primero,auxiliar);
    swap(segundo,primero);
    swap(auxiliar,segundo);

    for(int i=0;i<n;i++){
        cout<<primero[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<segundo[i]<<" ";
    }
    return 0;
}
*/