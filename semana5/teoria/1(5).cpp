/*

//estructuras:
#include<iostream>
using namespace std;

//--PARTE 1
//DEFINICION de una variable definida por el ususario:
struct estudiante{
    int codigo;
    float promedio;
    char sexo;
};    //---- COLOCAR ;

int main(){
//--PARTE 2
//DECLARACION de una estructura 
    //INICIALIZACION DIRECTA
    estudiante e1 = {2024,17.2,'M'};
    estudiante e2 = {2026,12.4,'F'};

    //INICIALIZACION MIEMBRO A MIEMBRO
    estudiante e3;
    e3.codigo=1234;
    e3.promedio=12.3;
    e3.sexo='M';

//--PARTE 3
    //ASIGNACION entre estructuras
    estudiante e4=e3;

    //LECTURA Y ESCRITURA 
    estudiante e5;
    cout<<"ingrese el codigo: "<<endl;
    cin>>e5.codigo;

    cout<<"ingrese el promedio: "<<endl;
    cin>>e5.promedio;

    cout<<"ingrese el nombre del operador:"<<endl;
    cin>>e5.sexo;

    //ARREGLO A ESTRUCTURAS
    estudiante A[3];

    //codigo para leer los miembrosde del arreglo
    for(int i=0;i<3;i++){
        cout<<"alumno "<<i+1<<endl;
        cout<<"codigo: ";cin>>A[i].codigo;
        cout<<"promedio: ";cin>>A[i].promedio;
        cout<<"sexo: ";cin>>A[i].sexo;
    }

//ESTRUCTURAS ANIDADAS 
struct fecha{
        int dia;
        int mes;
        int anio;
};

struct alumno{
        int codigo;
        fecha nacimineto;
};

    alumno a1;
    //inicializo codigo
    a1.codigo=123;
    
    //inicializo fecha
    a1.nacimineto.dia=10;
    a1.nacimineto.mes=19;
    a1.nacimineto.anio=2025;

    //puntero a estructuras
    estudiante e6;
    estudiante *ptr;
    ptr=&e6;

    //acceso mediante ptr a los miembros de las estructura
    //PRIMERA FORMA (usando el operador fecha ->)
    // -> solo funciona si ptr es un puntero
    cout<<ptr->codigo<<endl;
    cout<<ptr->promedio<<endl;
    cout<<ptr->sexo<<endl;


    //SEGUNDA FORMA
    cout<<(*ptr).codigo<<endl;

//PARTE 5
    //PASO DE ESTRUCTURA COMO PARAMETRO
    void mostrar(estudiante e1){
        cout<<e1.codigo;
    }
    //paso por referencia (util para programas eficietes y para modificar datos)
    void aumentarpromedio(estudiante &e1){
        e1.promedio+=1;
    }
    float calcularpromedio(estudiante e1[], int n){

    }
    return 0;
}

*/
