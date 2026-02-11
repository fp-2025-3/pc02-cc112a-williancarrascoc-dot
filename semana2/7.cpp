#include <iostream>
using namespace std;

void incrementar(int* p) {
    p++;
    *p += 1;
}

int main() {
    int y[] = {10,11};
    int* x = y;
    incrementar(x);
    cout << *x << endl;
    cout << x << endl;
}