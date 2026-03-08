#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Proyecto {
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};
int total(fstream& f) {
    f.seekg(0, ios::end);
    return f.tellg() / sizeof(Proyecto);
}
void leerEn(fstream& f, Proyecto& p, int i) {
    f.seekg(i * sizeof(Proyecto), ios::beg);
    f.read(reinterpret_cast<char*>(&p), sizeof(Proyecto));
}
void escribirEn(fstream& f, Proyecto& p, int i) {
    f.seekp(i * sizeof(Proyecto), ios::beg);
    f.write(reinterpret_cast<char*>(&p), sizeof(Proyecto));
}
bool existeId(fstream& f, int id) {
    int n = total(f);
    Proyecto p;
    for (int i = 0; i < n; i++) {
        leerEn(f, p, i);
        if (p.id == id) return true;
    }
    return false;
}
void ordenar(fstream& f) {
    int n = total(f);
    if (n <= 1) return;
    Proyecto* arr = new Proyecto[n];
    for (int i = 0; i < n; i++) leerEn(f, arr[i], i);
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j].presupuesto < arr[j+1].presupuesto) {
                Proyecto tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp;
            }
    for (int i = 0; i < n; i++) escribirEn(f, arr[i], i);
    delete[] arr;
}
void insertar(fstream& f, Proyecto& nuevo) {
    if (existeId(f, nuevo.id)) {
        cout << "Error: ID " << nuevo.id << " ya existe." << endl;
        return;
    }
    int n = total(f);
    int pos = n;
    Proyecto p;
    for (int i = 0; i < n; i++) {
        leerEn(f, p, i);
        if (nuevo.presupuesto > p.presupuesto) { pos = i; break; }
    }
    for (int i = n-1; i >= pos; i--) {
        leerEn(f, p, i);
        escribirEn(f, p, i+1);
    }
    escribirEn(f, nuevo, pos);
    cout << "Insertado en posicion " << pos+1 << "." << endl;
}
void leerProyecto(Proyecto& p) {
    cout << "  ID             : "; cin >> p.id;
    cin.ignore();
    cout << "  Titulo         : "; cin.getline(p.titulo, 40);
    cout << "  Presupuesto    : "; cin >> p.presupuesto;
    cout << "  Duracion (mes) : "; cin >> p.duracionMeses;
    cin.ignore();
}
void mostrar(fstream& f) {
    int n = total(f);
    if (!n) { cout << "Archivo vacio." << endl; return; }
    cout << "\n--- PROYECTOS (mayor a menor presupuesto) ---" << endl;
    Proyecto p;
    for (int i = 0; i < n; i++) {
        leerEn(f, p, i);
        cout << "[" << i+1 << "] ID:" << p.id
             << " | " << p.titulo
             << " | S/ " << p.presupuesto
             << " | " << p.duracionMeses << " meses" << endl;
    }
}
int main() {
    fstream archivo("proyectos.dat", ios::in | ios::out | ios::binary);
    if (!archivo) {
        ofstream("proyectos.dat", ios::binary).close(); // crear archivo vacio
        archivo.open("proyectos.dat", ios::in | ios::out | ios::binary);
    }
    int n;
    cout << "Cuantos proyectos registrar: "; cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        Proyecto p;
        cout << "-- Proyecto " << i+1 << " --" << endl;
        leerProyecto(p);
        if (existeId(archivo, p.id))
            cout << "ID duplicado. Saltando." << endl;
        else
            escribirEn(archivo, p, total(archivo));
    }
    ordenar(archivo);
    cout << "Registros guardados y ordenados." << endl;
    char resp;
    cout << "Insertar nuevo proyecto? (s/n): "; cin >> resp; cin.ignore();
    if (resp == 's' || resp == 'S') {
        Proyecto nuevo;
        leerProyecto(nuevo);
        insertar(archivo, nuevo);
    }
    mostrar(archivo);
    archivo.close();
    return 0;
}