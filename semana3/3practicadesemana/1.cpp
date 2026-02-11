#include<iostream>
using namespace std;

void tablaASCCI(){
    for(int i=0;i<128;i++){
        cout<<i<<"le corresponde: "<<(char)i<<endl;
    }
}
    
int main(){
    char c1 = 'A';
    char c2 = 'a';
    char c3 = '0';

    cout << (int)c1 << endl;
    cout << (int)c2 << endl;
    cout << (int)c3 << endl;

    cout<<endl;
    tablaASCCI();
/*
    char a='a';
    char b='b';
    char c='c';
    char* c1=&a;
    char* c2=&b;
    char* c3=&c;
    cout<<*c1<<endl;
    cout<<*c2<<endl;
    cout<<*c3<<endl;
*/
    return 0;
}