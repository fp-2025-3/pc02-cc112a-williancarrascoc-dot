#include <iostream>
#include <cmath>
using namespace std;
struct Punto {
    double x;
    double y;
};
void leerPunto(Punto* p) {
    cout << "  x: "; cin >> p->x;
    cout << "  y: "; cin >> p->y;
}
double distanciaOrigen(const Punto* p) {
    return sqrt(p->x * p->x + p->y * p->y);
}
Punto* masLejano(Punto* p1, Punto* p2) {
    if (distanciaOrigen(p1) >= distanciaOrigen(p2))
        return p1;
    else
        return p2;
}
int main() {
    Punto p1, p2;
    cout << "Ingrese coordenadas del Punto 1:" << endl;
    leerPunto(&p1);
    cout << "Ingrese coordenadas del Punto 2:" << endl;
    leerPunto(&p2);
    double d1 = distanciaOrigen(&p1);
    double d2 = distanciaOrigen(&p2);
    Punto* lejano = masLejano(&p1, &p2);
    cout << "\n--- Punto mas lejano al origen ---" << endl;
    cout << "Coordenadas : (" << lejano->x << ", " << lejano->y << ")" << endl;
    cout << "Distancia   : " << distanciaOrigen(lejano) << endl;

    return 0;
}