#include<iostream>
#include<cstring>
using namespace std;
char *my_strcpy(char* destination,const char* source){
    char* inicio=destination;
    while(*source !='\0'){
        *destination=*source;
        destination++;
        source++;
    }
    *destination='\0';
    return inicio;
}
int main(){
    const char a[5]="vaca";
     char b[5]=" ";
    const char c[5]="lola";
    char d[100];
    strcpy(d,a);
  //  strcpy(d,b);
  //  strcpy(d,c);
    cout<<d<<endl;
    cout<<my_strcpy(b,c);
    return 0;
}