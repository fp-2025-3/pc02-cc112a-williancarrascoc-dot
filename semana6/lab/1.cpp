#include<iostream>
#include<fstream>
using namespace std;
void agregar(const string& archivo){
    int n;
    cout<<"escribe la cantidad de notas: "<<endl;
    cin>>n;
    int* m=new int[n];
    cout<<"Escribe las notas: "<<endl;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }

    ofstream escribirarchivo;
    escribirarchivo.open(archivo,ios::binary|ios::out);
    if(!escribirarchivo){
        cerr<<"no se abrio correctamente el archivo";
        return ;
    }
    for(int i=0;i<n;i++){
        escribirarchivo.write(reinterpret_cast<const char*>(&m[i]),sizeof(int));
    }


    delete[] m;
}
void modificar(const string& archivo) {
    int indice,nuevovalor;
    ifstream contar(archivo,ios::binary|ios::ate);
    if(!contar){
        cerr<<"no se abrio correctamente el archivo"<<endl;
        return;
    }
    int total=contar.tellg()/sizeof(int);
    contar.close();
    cout<<"hay un total de "<<total<<" numeros"<<endl;
    cout<<"¿que notas quieres cambiar: ?"<<endl;
    cin>>indice;
    if(indice>=total||indice<0){
        cout<<"el valor esta fuera de parametro"<<endl;
        return ;
    }
    cout<<"nuevo valor: "<<endl;
    cin>>nuevovalor;


    fstream mod(archivo ,ios::binary|ios::in|ios::out);
    if(!mod){
        cerr<<"no se abrio correctamente"<<endl;
        return ;
    }

    mod.seekp(indice * sizeof(int));
    mod.write(reinterpret_cast<const char*>(&nuevovalor),sizeof(int));

}
void promedio(const string& archivo){
  ifstream mod(archivo,ios::binary|ios::ate);
  if(!mod){
    cerr<<"no se abrio correctamente"<<endl;
    return;
  }
  int total=mod.tellg()/sizeof(int);

  mod.seekg(0);
  int suma=0;
  for(int i=0;i<total;i++){
    int nota;
    mod.read(reinterpret_cast<char*>(&nota),sizeof(int));
    suma+=nota;
  }
  cout<<"el promedio es: "<<(float)suma/total<<endl;


}
//revisar esto
void mostrar(const string& archivo) {
    ifstream f(archivo, ios::binary | ios::ate);
    if (!f) { 
        cerr << "No se pudo abrir." << endl; 
        return;
    }

    int total = f.tellg() / sizeof(int);
    f.seekg(0);

    cout << "Notas: " << endl;
    for (int i = 0; i < total; i++) {
        int nota;
        f.read(reinterpret_cast<char*>(&nota), sizeof(int));
        cout << "  [" << i << "]: " << nota << endl;
    }
}


int main(){
    string archivo("hoja.bin");
    agregar(archivo);
    modificar(archivo);
    promedio(archivo);
    mostrar(archivo);


    return 0;
}