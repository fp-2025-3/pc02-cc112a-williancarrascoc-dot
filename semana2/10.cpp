#include <iostream>
using namespace std;

int main() {
    int arr[3] = {1,2,3};
    int* p = arr;

    cout << *p +2 << endl;
    cout << *(p +2) << endl;
}