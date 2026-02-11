#include<iostream>
using namespace std;
int main(){
    char vaca[100];
    int edad;
    cout<<"escribe tu edad "<<endl;
    cin>>edad;
    cin.ignore();
    cout<<"escribe una palabra ";
    cin.getline(vaca,100);
    cout<<edad<<endl;
    cout<<vaca;


    return 0;
}