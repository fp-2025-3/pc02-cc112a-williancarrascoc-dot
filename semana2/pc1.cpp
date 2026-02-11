/*
implemente el algoritmo de ordenacion burbuja empleando punteros
considere dentro de su codigo main() la siguiente linea:
int A[]={5,2,9,4,1,8,5,6,3,0,7};
Al ejecutar el programa, muestra el siguiente resultad:
Vector después de ser ordenado: 0 1 2 3 4 5 5 6 7 8 9

*/
#include<iostream>
using namespace std;
int main(){
    int A[]={5,2,9,4,1,8,5,6,3,0,7};
    int* p=A;
    int aux;
    int n=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(*(p+j)>*(p+j+1)){
                aux=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=aux;
            }
        }
    }
    cout<<"Vector después de ser ordenado: ";
    for(int i=0;i<n;i++){
        cout<<*(p+i)<<" ";
    }


    return 0;
}