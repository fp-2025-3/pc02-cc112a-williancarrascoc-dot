//estudiarlo

#include <iostream>
#include <fstream> // para manejar archivos
using namespace std;


struct Producto {
    int id;                  // Identificador único
    char nombre[30];         // Nombre del producto
    double precio;           // Precio unitario
    int stock;               // Cantidad disponible
    bool activo;             // true = activo, false = eliminado lógicamente
};

// [P1][P2][P3].....[Pn][P_n+1]

void registrarProducto(const char* nombreArchivo); //ok
void mostrarProductos(const char* nombreArchivo); 
int buscarProductoPorID(const char* nombreArchivo, int idBuscado); //ok
void eliminarProducto(const char* nombreArchivo, int id);
void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio); //ok
double calcularValorInventario(const char* nombreArchivo);

int main(){

    return 0;
}

int buscarProductoID(const char* nombreArchivo, int Idbuscar) {
    // Como vamos a buscar un producto en un archivo binario instanciamos la clase ifstream
    ifstream archivo(nombreArchivo, ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo" <<endl;
        return -1; 
    }

    Producto p;

    int posicion = 0;


    while(archivo.read((char*)&p,sizeof(Producto))) {
        if (p.id == Idbuscar) {
            archivo.close();
            return  posicion;
        }
        posicion++;
    }

    archivo.close();
    return -1;
}


// a) funcion para registrar un producto
void registrarProducto(const char* nombreArchivo) {
    Producto p; // en C struct Producto p;

    cout << "Ingrese ID: ";
    cin >> p.id;

    // No debe permitir IDs repetidos.
    if (buscarProductoID(nombreArchivo,p.id) != -1) {
        cerr << "ERROR, el ID ya existe"<<endl;
        return;
    }

    cin.ignore(); // limpiamos el buffer
    cout << "Ingrese el nombre: ";
    cin.getline(p.nombre,30);

    cout << "Ingrese el precio: ";
    cin >> p.precio;

    if(p.precio <= 0) {
        cout << "Precio invalido" <<endl;
        return;
    }

    cout << "Ingrese stock: ";
    cin >> p.stock;

    if(p.stock < 0) {
        cout << "Stock invalido" <<endl;
        return;
    }

    p.activo = true;

    // USAMOS ARCHIVOS ARCHIVOS

    // Paso 1: instanciar un objeto de la clase ofstream y activar el modo binario
    ofstream archivo(nombreArchivo, ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo" <<endl;
        return;
    }

    // Paso 2: Escribir en el archivo binario
    archivo.write((char*)&p,sizeof(Producto)); // archivo.write(reinterpret_cast<char*>(&p),sizeof(Producto))

    archivo.close();


    cout << "Producto registrado correctamente" <<endl;

}




void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio) {

    // Ejericio: Validar nuevoPrecio

    // Paso 1: Creamos un objeto fstream (para lectura y ecritura)
    fstream archivo(nombreArchivo,ios::binary | ios::in | ios::out); 

    if (!archivo) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    int  posicion = buscarProductoID(nombreArchivo,id);

    if (posicion == -1) {
        cout << "Producto no encontrado\n";
        archivo.close();
        return;
    }

    // PARTE DE ACCESO ALEATORIO   (leemos, modicamos algun dato, escribimos)
    
    // Mover el ptr de lectura: seekg();

    Producto p;

    archivo.seekg(posicion*sizeof(Producto),ios::beg); 

    //leemos el producto en posicion
    archivo.read((char*)&p,sizeof(Producto));

    // Ejercicio: Comprobar primero si este producto ha sido eliminado

    // Actualizamos el precio
    p.precio = nuevoPrecio;

    // Mover el ptr de escritura seekp();
    archivo.seekp(posicion*sizeof(Producto),ios::beg);

    archivo.write( (char*)&p,sizeof(Producto));

    archivo.close();

    cout << "Se modificó el precio correctamente\n";
}