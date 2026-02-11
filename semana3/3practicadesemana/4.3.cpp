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
     int j=1;

    //union de vectores
    for(int i=0;i<n;i++){
            arr3[j]=arr1[i];
            j=j+2;
        }
        
    int y=0;
    for(int i=0;i<n;i++){
            arr3[y]=arr2[i];
         y=y+2; 
        }
    

//enseñando el vector
    cout<<"el vector es: "<<endl;
    for(int i=0;i<n2;i++){
        cout<<arr3[i]<<" ";
    }


//busqueda binaria
    int sup, inf, mitad, dato;
    bool band=false;
    cout<<endl; 
    cout<<"escribe el numero a buscar: "<<endl;
    cin>>dato;
    inf=0;
    sup=n2;
    while(inf<=sup){
        mitad=(sup+inf)/2;
        if(arr3[mitad]==dato){
            band=true;
            break;
        }
        if(arr3[mitad]<dato){
            inf=mitad+1;
        }if(arr3[mitad]>dato){
            sup=mitad-1;
        }
    }
    if(band==false){
        cout<<"no exite el numero";
    }if(band==true){
        cout<<"la posicion es: "<<mitad<<endl;
    }



    return 0;
}