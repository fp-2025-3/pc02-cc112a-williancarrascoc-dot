/*
escribir un programa que reciba la siguiente cadena
"123,45.67,-89,1001,23.45,6789,12.45"
y calcule la suma de todo los numeros enteros contenidos en ella
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int sumarenteros(char* p){
    int suma=0;
    char* token=strtok(p,",");

    while(token!=nullptr){
        double n=atof(token);
        if(floor(n)==n){
            suma+=n;
            cout<<n<<endl;
        }
        token=strtok(nullptr,",");
    }
    return suma;

}
int main(){
    char elgato[]="123,45.67,-89,1001,23.45,6789,12.45";
    char* p=elgato;
    cout<<sumarenteros(p);

    return 0;
}