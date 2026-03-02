#include<iostream>
#include<fstream>
using namespace std;
int calculartotal(ifstream& entrada){
    int nota,total=0;
    while(entrada>>nota){
        total++;
    }
    cout<<"hay "<<total<<" alumnos"<<endl;
entrada.clear();
entrada.seekg(0);
    return total;
}
float calcularpromedio(ifstream& entrada,int total){
    int a,suma=0;
    while(entrada>>a){
        suma+=a;
    }
    suma=suma/total;
    cout<<"el promedio es: "<<suma<<endl;

entrada.clear();
entrada.seekg(0);

    return suma;
}
int notabaja(ifstream& entrada){
    int a=99999,b;
    while(entrada>>b){
        if(b<a){
            a=b;
        }
    }
    cout<<"la nota mas baja es: "<<a<<endl;
entrada.clear();
entrada.seekg(0);

    return a;
}
int notaalta(ifstream& entrada){
    int a=0,b;
    while(entrada>>b){
        if(b>a){
            a=b;
        }
    }
    cout<<"la nota mas alta es: "<<a<<endl;
entrada.clear();
entrada.seekg(0);

    return a;
}
int aprovados(ifstream& entrada){
    int a,count=0;
    while(entrada>>a){
        if(a>=10){
            count++;
        }
    }
    cout<<"la cantidad de aprovados es: "<<count<<endl;
entrada.clear();
entrada.seekg(0);

    return count;
}
int jalados(ifstream& entrada){
    int a,count=0;
    while(entrada>>a){
        if(a<10){
            count++;
        }
    }
    cout<<"la cantidad de desaprovados es: "<<count<<endl;
entrada.clear();
entrada.seekg(0);

    return count;
}
void escribirreporte(ofstream& salida,int total, float promedio,int bajo, int alto,int aprov, int jala){
    salida<<total<<endl;
    salida<<promedio<<endl;
    salida<<bajo<<endl;
    salida<<alto<<endl;
    salida<<aprov<<endl;
    salida<<jala<<endl;
}

int main(){
    ifstream entrada;
    ofstream salida;
    
    entrada.open("notas.txt",ios::in);
    if(!entrada){
        cerr<<"no se abrio correctamente"<<endl;
        return 1;
    }

    salida.open("reporte.txt",ios::out);
    if(!salida){
        cerr<<"no se abrio correctamente"<<endl;
        return 1;
    }

    int total=calculartotal(entrada);
    float promedio=calcularpromedio(entrada,total);
    int bajo=notabaja(entrada);
    int alto=notaalta(entrada);
    int aprov= aprovados(entrada);
    int jala= jalados(entrada);

    escribirreporte(salida,total,promedio,bajo,alto,aprov,jala);
    
    entrada.close();
    salida.close();

    return 0;
}