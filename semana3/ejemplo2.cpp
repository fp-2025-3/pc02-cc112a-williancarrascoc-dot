#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand(0);
    char let[20];
    cout<<"generando caracteres:  "<<endl;
    for(int i=0;i<20;i++){
        let[i]='a'+rand()%26;
        cout<<let[i]<<" ";
    }
    cout<<endl;

    //contamos recurrencia
    bool revisado[20]={false};
    for(int i=0;i<20;i++){
        if(revisado[i]==true){
            continue;
        }
        int contador=1;
        for(int j=i+1;j<20;j++){
            if(let[i]==let[j]){
                contador++;
                revisado[j]=true;
            }
        }
        cout<<"el caracter "<<let[i]<<" aparece "<<contador<<endl;
    }
    return 0;
}