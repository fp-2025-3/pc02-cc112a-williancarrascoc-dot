#include<iostream>
using namespace std;
int main(){
    int filas;
    int columnas;
    int** matriz;
    cout<<"escribe la cantidad de filas: "<<endl;
    cin>>filas;
    cout<<"escribe la cantidad de columnas: "<<endl;
    cin>>columnas;
    matriz=new int*[filas];
    for(int i=0;i<filas;i++){
            matriz[i]=new int [columnas];
    }


    cout<<"ingrese los datos: "<<endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cin>>*(*(matriz+i)+j);
        }
    }

//suma de filas
for(int i=0;i<filas;i++){
int sumafilas=0;
    for(int j=0;j<columnas;j++){
        sumafilas=sumafilas+*(*(matriz+i)+j);
    }
    cout<<"fila "<<i<<": "<<sumafilas<<endl;
}
//suma de columnas
for(int j=0;j<columnas;j++){
    int sumacolumnas=0;
    for(int i=0;i<filas;i++){
        sumacolumnas=sumacolumnas+*(*(matriz+i)+j);
    }
    cout<<"columna "<<j<<": "<<sumacolumnas<<endl;
}
//liberacion de matriz
for(int i=0;i<filas;i++){
    delete[] matriz[i];
}
delete[] matriz;


    return 0;
}