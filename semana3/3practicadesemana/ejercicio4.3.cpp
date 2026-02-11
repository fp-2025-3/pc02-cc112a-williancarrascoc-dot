#include<iostream>
using namespace std;
void leer(const char* p){
    while(*p!='\0'){
        cout<<*p;
        p++;
    }
}
int main(){
    const char palabra[]="dinosario";
    leer(palabra);



    return 0;
}