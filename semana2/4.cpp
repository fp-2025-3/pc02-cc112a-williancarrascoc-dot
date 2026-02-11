#include <iostream> 
using namespace std;

int main() {
    int arr[5] = {1,2,3,4,5};
    int* p = arr; //Guarda la direccion del primer elemento

    for (int i = 0; i < 10; ++i) {
        cout << p[i] << " "; // *(p+i)==p[i]
    }
    cout<<endl;
}