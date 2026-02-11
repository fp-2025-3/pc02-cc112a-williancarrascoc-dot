#include<iostream>
#include<cstring>
using namespace std;
struct estudiante{
    string nombre;
    float promedio;
};

void leer(int &n,estudiante* &a){
    cout<<"escribe el numero de estudiantes: "; cin>>n;
    cin.ignore();
    a=new estudiante[n];
    for(int i=0;i<n;i++){
        cout<<"ingrese el nombre del estudiante "<<i+1<<": ";getline(cin,a[i].nombre);
        cout<<"ingrese la nota del estudiante "<<i+1<<": "; cin>>a[i].promedio;
        cin.ignore();
    }
}
void max(int n,estudiante* &a){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[i].promedio>a[i+1].promedio){
                swap(a[i].promedio,a[i+1].promedio);
                swap(a[i].nombre,a[i+1].nombre);
            }
        }
    }
    cout<<"la/las persona con mayor nota es: "<<endl;
    for(int i=0;i<n;i++){
        if(a[i].promedio==a[n-1].promedio){
            cout<<a[i].nombre<<" - "<<a[i].promedio<<endl;
        }
    }
}

int main(){
    int n;
    estudiante* a;
    leer(n,a);
    max(n,a);
    delete[] a;
    a=nullptr;
}