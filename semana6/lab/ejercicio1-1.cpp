//desarrolle un programa en c++ que mezcle las listas ordenadas en los archivos archio1 
//archivo2, creando el archivo nombreM con la mezcla
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream entrada1;
    ifstream entrada2;
    ofstream salida;
        entrada1.open("archivo1.txt",ios::in);
    if(!entrada1){
        cerr<<"no se abrio correctamente"<<endl;
        return 1;
    }

        entrada2.open("archivo2.txt",ios::in);
    if(!entrada2){
        cerr<<"no se abrio correctamente"<<endl;
        return 1;
    }

        salida.open("mezcla.txt",ios::out);
    if(!salida){
        cerr<<"no se abrio correctamente"<<endl;
        return 1;
    }

    int a,i=0,j=0;
    int vec[100];
    int vec2[100];
    while(entrada1>>a){
        vec[i]=a;
        i++;
    }
    while(entrada2>>a){
        vec2[j]=a;
        j++;
    }
    for(int k=0;k<i;k++){
        salida<<vec[k]<<endl;
    }
    for(int k=0;k<j;k++){
        salida<<vec2[k]<<endl;
    }

    entrada1.close();
    entrada2.close();
    salida.close();

    return 0;
}