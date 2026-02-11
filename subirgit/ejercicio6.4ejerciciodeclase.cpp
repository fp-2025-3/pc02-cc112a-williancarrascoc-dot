#include<iostream>
using namespace std;
char* my_strcat(char* destination,const char* source){
    char* inicio=destination;
    while(*destination!=0){
        destination++;
    }
    while(*source!=0){
        *destination=*source;
        destination++;
        source++;
    }
    *destination='\0';
    return inicio;
}
int my_strcmp (const char * str1, const char * str2){
    
    while(*str1!='\0'){
    if(*str1!=*str2){
    return -1;
    }
    str1++;
    str2++;
    }
    return 1;
}


int main(){
    char a[100]="elgato";
    char b[100]="vivaelvino";
    char c[100]= "";
    const char d[10]="elgato2";
    const char e[10]="elgato2";
    my_strcat(c,a);
    my_strcat(c,b);
    cout<<my_strcat(a,b)<<endl;
    cout<<my_strcmp(d,e)<<endl;   //aca hay un fallo (revisar)

    return 0;
}
