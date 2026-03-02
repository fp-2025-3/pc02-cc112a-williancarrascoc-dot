#include<iostream>
#include<fstream>
using namespace std;
void escribirFibonacciBinario(){
    cout << "Funcion escribirFibonacciBinario:" << endl;
    ofstream archivo("fibonacci.bin", ios::binary);
    if(!archivo){
        cerr << "no se pudo crear el archivo" << endl;
        return;
    }
    int fib[20];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < 20; i++)
        fib[i] = fib[i-1] + fib[i-2];
    archivo.write(reinterpret_cast<char*>(fib), sizeof(fib));
    archivo.close();
    cout << "Terminos de Fibonacci escritos en el archivo correctamente." << endl;
}
void leerFibonacciBinario(){
    cout << "\nFuncion leerFibonacciBinario:" << endl;
    ifstream archivo("fibonacci.bin", ios::binary);
    if(!archivo){
        cerr << "no se pudo abrir el archivo" << endl;
        return;
    }
    int fib[20];
    archivo.read(reinterpret_cast<char*>(fib), sizeof(fib));
    archivo.close();
    for(int i = 0; i < 20; i++)
        cout << "Termino " << i+1 << ": " << fib[i] << endl;
    cout << "----------------------------------------" << endl;
}
int main(){
    escribirFibonacciBinario();
    leerFibonacciBinario();
    return 0;
}