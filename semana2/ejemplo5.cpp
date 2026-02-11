#include<iostream>
using namespace std;
int maximo(int* p,int n){
    int max=*p;
    for(int i=0;i<n-1;i++){
        if(*(p+i)<*(p+i)+1){
            max=*(p+i)+1;
        }
    }
    return max;
}
int minimo(int* p,int n){
    int min=*p;
    for(int i=0;i<n-1;i++){
        if(*(p+i)>*(p+i)+1){
            min=*(p+i)+1;
        }
    }
    return min;
}
int main(){
    int A[5]={1,2,3,4,5};
    int n=sizeof(A)/sizeof(A[0]);
    int* p=A;
    cout<<maximo(p,n)<<endl;
    cout<<minimo(p,n)<<endl;
    return 0;
}