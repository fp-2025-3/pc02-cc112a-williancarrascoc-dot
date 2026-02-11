#include<iostream>
#include<cmath>
using namespace std;
struct punto{
    int x;
    int y;
    int z;
};

void leer(punto &a1, punto &a2){
    cout<<"escriba las coordenadas del primer punto "<<endl;
        cout<<"en el eje X: "; cin>>a1.x;
        cout<<"en el eje Y: "; cin>>a1.y;
        cout<<"en el eje Z: "; cin>>a1.z;
    cout<<"escriba las coordenadas del segundo punto "<<endl;
        cout<<"en el eje X: "; cin>>a2.x;
        cout<<"en el eje Y: "; cin>>a2.y;
        cout<<"en el eje Z: "; cin>>a2.z;
}

int distancia(punto a1, punto a2){
    int p=0;
    p=sqrt(pow((a1.x-a2.x),2)+pow((a1.y-a2.y),2)+pow((a1.z-a2.z),2));
    return p;
}

int main(){
    punto a1,a2;
    leer(a1,a2);
    cout<<"la distancia entre los dos puntos es: "<<distancia(a1,a2);


    return 0;
}