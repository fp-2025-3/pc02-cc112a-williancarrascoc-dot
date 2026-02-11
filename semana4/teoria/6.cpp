//Arreglos multidimensionales dinámicos
/*
6.1 matriz como puntero a punteros
int filas=3, columnas= 4;
int** M=new int*[filas];
for(int i=0;i<filas;i++){
    M[i]=new int[columas];
}

//liberacion correcta (con orden critico);
for(int i=0;i<filas;i++){
    delete[]   M[i];
}
delete[] M;

error frecuente: 
solo liberar M

6.3 error frecuente: índices fuera de rango
M[3][0]=10; //fuera de limites
detectado por Asan




*/