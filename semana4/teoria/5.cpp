//Arreglos dinámicos unidimencionales con punteros
/*
5.1 paso de arreglos dinámicos a funciones
void llenar(int* v, int n){
    for(int i=0;i<n;i++){
        v[i]=i*i;
    }
}
--el arreglo no se copia, se pasa la direccion

5.2 error frecuente: perder la referencia
int* v=new int[10];
v=new int[20];  //fuga de memoria
correcion:
delete[] v;
v=new int[20];



*/