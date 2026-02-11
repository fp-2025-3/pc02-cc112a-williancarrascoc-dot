#include<iostream>
using namespace std;
int main(){
    int A[5]={-2,-1,0,1,2};
    int n=sizeof(A)/sizeof(A[0]);
    int* p=A;
    int j=0,k=0,l=0;
    int B[100],C[100],D[100];
    for(int i=0;i<n;i++){
        if(*(p+i)<0){
            B[j]=*(p+i);
            j++;
        }
        if(*(p+i)>0){
            C[k]=*(p+i);
            k++;
        }
        if(*(p+i)==0){
            D[l]=*(p+i);
            l++;
        }
    }
    for(int i=0;i<j;i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
        for(int i=0;i<k;i++){
        cout<<C[i]<<" ";
    }
    cout<<endl;
        for(int i=0;i<l;i++){
        cout<<D[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}