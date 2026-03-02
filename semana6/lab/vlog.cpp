#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Producto {
    int id;
    char nombre[30];
    double precio;
    int stock;
    bool activo;
};

// ─────────────────────────────────────────
void registrarProducto(const char* nombreArchivo){
    Producto p;

    cout << "ID: "; cin >> p.id;

    // verificar ID repetido
    fstream archivo(nombreArchivo, ios::in | ios::binary);
    if(archivo.is_open()){
        Producto temp;
        while(archivo.read(reinterpret_cast<char*>(&temp), sizeof(Producto))){
            if(temp.id == p.id && temp.activo){
                cout << "error: ID ya existe" << endl;
                archivo.close();
                return;
            }
        }
        archivo.close();
    }

    cout << "Nombre: "; cin >> p.nombre;

    do {
        cout << "Precio: "; cin >> p.precio;
        if(p.precio <= 0) cout << "error: precio debe ser mayor a 0" << endl;
    } while(p.precio <= 0);

    do {
        cout << "Stock: "; cin >> p.stock;
        if(p.stock < 0) cout << "error: stock no puede ser negativo" << endl;
    } while(p.stock < 0);

    p.activo = true;

    ofstream salida(nombreArchivo, ios::app | ios::binary);
    salida.write(reinterpret_cast<char*>(&p), sizeof(Producto));
    salida.close();

    cout << "producto registrado correctamente" << endl;
}

// ─────────────────────────────────────────
void mostrarProductos(const char* nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){ cout << "no se pudo abrir el archivo" << endl; return; }

    Producto p;
    int posicion = 0;
    bool hayProductos = false;

    cout << "\n--- PRODUCTOS ACTIVOS ---" << endl;
    while(archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))){
        if(p.activo){
            cout << "Posicion: " << posicion << endl;
            cout << "  ID: "     << p.id << endl;
            cout << "  Nombre: " << p.nombre << endl;
            cout << "  Precio: " << p.precio << endl;
            cout << "  Stock: "  << p.stock << endl;
            cout << "------------------------" << endl;
            hayProductos = true;
        }
        posicion++;
    }
    if(!hayProductos) cout << "no hay productos activos" << endl;
    archivo.close();
}

// ─────────────────────────────────────────
int buscarProductoPorID(const char* nombreArchivo, int idBuscado){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo) return -1;

    Producto p;
    int posicion = 0;

    while(archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))){
        if(p.id == idBuscado && p.activo){
            archivo.close();
            return posicion;
        }
        posicion++;
    }
    archivo.close();
    return -1;
}

// ─────────────────────────────────────────
void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio){
    if(nuevoPrecio <= 0){ cout << "error: precio invalido" << endl; return; }

    int posicion = buscarProductoPorID(nombreArchivo, id);
    if(posicion == -1){ cout << "producto no encontrado" << endl; return; }

    fstream archivo(nombreArchivo, ios::in | ios::out | ios::binary);
    if(!archivo){ cout << "no se pudo abrir el archivo" << endl; return; }

    // saltar hasta el registro exacto y luego hasta el campo precio
    long offset = posicion * sizeof(Producto) + offsetof(Producto, precio);
    archivo.seekp(offset);
    archivo.write(reinterpret_cast<char*>(&nuevoPrecio), sizeof(double));
    archivo.close();

    cout << "precio actualizado correctamente" << endl;
}

// ─────────────────────────────────────────
void eliminarProducto(const char* nombreArchivo, int id){
    int posicion = buscarProductoPorID(nombreArchivo, id);
    if(posicion == -1){ cout << "producto no encontrado" << endl; return; }

    fstream archivo(nombreArchivo, ios::in | ios::out | ios::binary);
    if(!archivo){ cout << "no se pudo abrir el archivo" << endl; return; }

    // posicionarse exactamente sobre el campo activo
    long offset = posicion * sizeof(Producto) + offsetof(Producto, activo);
    archivo.seekp(offset);
    bool inactivo = false;
    archivo.write(reinterpret_cast<char*>(&inactivo), sizeof(bool));
    archivo.close();

    cout << "producto eliminado logicamente" << endl;
}

// ─────────────────────────────────────────
double calcularValorInventario(const char* nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){ cout << "no se pudo abrir el archivo" << endl; return 0; }

    Producto p;
    double total = 0;

    while(archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))){
        if(p.activo) total += p.precio * p.stock;
    }
    archivo.close();
    return total;
}

// ─────────────────────────────────────────
int main(){
    const char* archivo = "inventario.dat";
    int opcion;

    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Registrar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Modificar precio" << endl;
        cout << "5. Eliminar producto" << endl;
        cout << "6. Calcular valor total" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: "; cin >> opcion;

        switch(opcion){
            case 1:
                registrarProducto(archivo);
                break;
            case 2:
                mostrarProductos(archivo);
                break;
            case 3: {
                int id;
                cout << "ID a buscar: "; cin >> id;
                int pos = buscarProductoPorID(archivo, id);
                if(pos == -1) cout << "producto no encontrado" << endl;
                else cout << "producto encontrado en posicion: " << pos << endl;
                break;
            }
            case 4: {
                int id; double precio;
                cout << "ID: "; cin >> id;
                cout << "Nuevo precio: "; cin >> precio;
                modificarPrecio(archivo, id, precio);
                break;
            }
            case 5: {
                int id;
                cout << "ID a eliminar: "; cin >> id;
                eliminarProducto(archivo, id);
                break;
            }
            case 6:
                cout << "Valor total del inventario: " << calcularValorInventario(archivo) << endl;
                break;
            case 7:
                cout << "saliendo..." << endl;
                break;
            default:
                cout << "opcion invalida" << endl;
        }
    } while(opcion != 7);

    return 0;
}