#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    cout<<"creando un numero aleatorio"<<endl;
    srand(time(0));
    int num=1+rand()%100;
    cout<<"el numero es: "<<endl;
    cout<<num;
    return 0;
}