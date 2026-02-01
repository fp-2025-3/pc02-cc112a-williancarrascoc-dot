#include<iostream>
using namespace std;
int sumar(char vec[],int n);
int sum;
int main(){
    char vec[100];
    int n;
    cout<<"escribe la cantidad de digitos: "<<endl;
    cin>>n;
    cin.ignore();
    cout<<"escribe un numero: "<<endl;
    cin.getline(vec,100);
    cout<<"mostrando"<<endl;
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";   
    }
    cout<<endl;
        cout<<sumar(vec,n);
    return 0;
}
int sumar(char vec[],int n){
    if(n>0){
        sum=0;
        for(int i=0;i<n;i++){
            sum=sum+vec[i];
        }
        return sum;
    }else{
        return sum;
    }
}
    