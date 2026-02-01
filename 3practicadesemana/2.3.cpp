#include<iostream>
using namespace std;
int recursivo(int arr,int i,int n);
    int j=0;
int main(){
    int n,arr[100];
    cout<<"escribe la cantidad de elementos: "<<endl;
    cin>>n;
    cout<<"escribe los elementos: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    //buscamos el mayor
    int mayor=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mayor){
            mayor=arr[i];
        }
    }
    
    
    //busqueda lineal
    int i=0;
    bool band=false;
    while((band==false)&&(i<n)){
        if(arr[i]==mayor){
            band=true;
        }
        i++;
    }
    cout<<"el mayor es: "<<mayor<<" y su ubicacion en el arreglo es: "<<i-1<<endl;
    cout<<"los elementos dominantes son: ";
    for(int j=i-1;j<n;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    cout<<"hay "<<n-i+1<<" elementos dominantes"<<endl;

/*
cout<<recursivo(arr,i,n);
*/
    return 0;
}
/*
int recursivo(int arr,int i,int n){
    if(i<=n){
    j++;
    return recursivo (arr,i,n);
    }
    return j;
}
    */


