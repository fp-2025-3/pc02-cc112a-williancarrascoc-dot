#include<iostream>
using namespace std;
int main(){
    int** A;
    int n,m;
    int** B;
    cout<<"escribe la cantidad de filas: "<<endl;
    cin>>n;
    A=new int*[n];
    B=new int*[n];
    cout<<"escribe la cantidad de columnas: "<<endl;
    cin>>m;
    for(int i=0;i<n;i++){
        A[i]=new int[m];
        B[i]=new int[m];
    }
    cout<<"escribe los valores de la matriz: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>*(*(A+i)+j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            *(*(B+i)+j)=*(*(A+j)+i);
        }
    }
    //enseñando
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<*(*(B+i)+j)<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        delete[] A[i];
        delete[] B[i];
    }
    delete[] A;
    delete[] B;

    return 0;
}
