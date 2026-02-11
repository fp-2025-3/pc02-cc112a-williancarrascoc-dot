#include <iostream>
using namespace std;

int main() {
    int matriz[2][3] = {{1,2,3},{4,5,6}};
    int (*p)[2][3] = &matriz;    //Siempre recordar declarar la columna por jerarquia 

    for(int j=0;j<2;++j){
        for(int i=0;i<3;++i){
            cout << (*p)[j][i] << " ";
        }
        cout<<endl;
    }
        
}
