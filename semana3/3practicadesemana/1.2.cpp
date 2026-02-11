#include<iostream>
#include<cstring>
using namespace std;
void invertircadena(char vec[],int n){
    char* p=vec;
    char* final=p+n-1;
    for(int i=0;i<n-i-1;i++){
        swap(*(p+i),*(final-i));
    }
    cout<<"la forma invertida es: "<<endl;
    cout<<vec;
}
int main(){
    char vec[]="el gato tiene vida";
    int n=strlen(vec);
    invertircadena(vec,n);
    return 0;
}