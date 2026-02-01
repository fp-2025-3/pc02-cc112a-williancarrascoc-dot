#include<iostream>
using namespace std;
int main(){
    int arr1[100],arr2[100],n,arr3[100],n2;
    cout<<"escribe la cantidad de elementos : "<<endl;
    cin>>n;
    cout<<"escribe los elementos de forma decreciente del primer arreglo (arreglo A): "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"escribe los elementos de forma decreciente del segundo arreglo (arreglo B): "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    n2=n*2;

    /*
    //union de vectores
    for(int i=0;i<n;i+){
       if(i%2==0){
            arr3[j]=arr1[i];
                    j++;
        }
        }
    
    for(int i=0;i<n;i++){
        if(i%2!=0){
            arr3[j]=arr2[i];
         j++; 
        }
    }
        */



//enseñando el vector
    cout<<"el vector es: "<<endl;
    for(int i=0;i<n2;i++){
        cout<<arr3[i]<<" ";
    }

    return 0;
}