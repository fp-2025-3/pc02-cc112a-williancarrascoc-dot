#include<iostream>
#include<fstream>  //para manipular archivos
#include<cstring>
using namespace std;
//parte 1: prototipos ---> archivos de encabezado

void escribirArchivo(const string& nombrearchivo,const string& nombre, int nota);
void leerArchivo(const string& nombreArchivo);

//------------------------------------------------------------
//archivos binarios
//para trabajar con archivos binarios, debemos usar char[] en lugar de string
struct estudiante{
    char nombre[50];
    int nota;
};
void escribirBinario(const string& nombrearchivo,const string& nombre, int nota);
void leerBinario(const string& nombrearchivo);
void modificarnotaBinario(const string& nombrearchivo,const string& nombre, int nuevanota);


//parte 3: aplicacion


//escritura en un archivo de texto

int main(){
    string nombreArchivo="notas.txt";
    //escritura en un archivo de texto
    escribirArchivo(nombreArchivo, "juan",17);
    escribirArchivo(nombreArchivo, "Pedro",11);
    escribirArchivo(nombreArchivo, "Maria",16);

    //leemos el archivo y lo mostramos en consola
    leerArchivo(nombreArchivo);

    //agregamos otros estudiantes
    escribirArchivo(nombreArchivo, "Pablo",12);
    escribirArchivo(nombreArchivo, "Mercedes",13);
    escribirArchivo(nombreArchivo, "Julio",14);


    cout<<"datos agregados correctamente"<<endl;

    //lectura completa
    leerArchivo(nombreArchivo);

    //-------------
    const string archivobinario= "notas.dat";
    //escritura en un archivo binario
    escribirBinario(archivobinario, "juan",17);
    escribirBinario(archivobinario, "Pedro",11);
    escribirBinario(archivobinario, "Maria",16);

    cout<<"\n contenido del archivo binario\n";
    leerBinario(archivobinario);

    return 0;
}

//parte 2: archivos .cpp ---> contienen la implementación
void escribirArchivo(const string& nombrearchivo,const string& nombre, int nota){
    //paso 1: instanciamos un objeto de la clase ofstream

    ofstream archivoescritura;

    //paso 2: conectamos con la fuente
    archivoescritura.open(nombrearchivo, ios::app);

    //comprobar si el archivo existe o si abrio correctamente
    if(!archivoescritura){
        cerr<<"error al abrir el archico para escritura"<<endl;
        return ;
    }

    //paso 3: procesar datos, escribir en notas.txt
    archivoescritura<<nombre<<" "<<nota<<endl;

    //paso 4:desconectamos la fuente
    archivoescritura.close();  //el destructor se encarga internamente de desconectar 

}
void leerArchivo(const string& nombreArchivo){
     //paso 1: instanciamos un objeto de la clase ifstream
    ifstream archivolectura;

    //paso 2: conectamos con la fuente;
    archivolectura.open(nombreArchivo);

    //comprobamos si el archivo exite
    if(!archivolectura){
        cerr<<"error, no existe el archivo"<<endl;
        return ;
    }

    //paso 3: procesar datos, leer desde notas.txt
    string nombre;
    int nota;
    while(archivolectura>>nombre>>nota){ //estados del stream
        cout<<nombre<<" -- "<<nota<<endl;  //mostramos en consola 
    }

    //paso 4: desconectar de la fuente
    archivolectura.close();

}

void escribirBinario(const string& nombrearchivo,const string& nombre, int nota){
    ofstream archivo(nombrearchivo,ios::binary | ios::app); //activar el modo binario y app
    if(!archivo){
        cerr<<"error al abrir el archivo";
        return;
    }

    estudiante e;
    e.nota=nota;
    strncpy(e.nombre,nombre.c_str(),sizeof(e.nombre));
    e.nombre[sizeof(e.nombre)-1]='\0'; 

    //escritura en el archivo binario

    archivo.write((char*)&e,sizeof(estudiante));

    archivo.close()
;}


void leerBinario(const string& nombrearchivo){
    ifstream archivo(nombrearchivo,ios::binary);
    if(!archivo){
        cerr<<"error al leer"<<endl;
        return;
    }

    estudiante e;


    while(archivo.read((char*)&e,sizeof(estudiante))){ //estados del stream
        cout<<e.nombre<<" -- "<<e.nota<<endl;  //mostramos en consola 
    }

    archivo.close();
}