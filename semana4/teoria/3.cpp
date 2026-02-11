//Asignacion dinamica: operador new
/*
//1. asignacion simple
int* p=new int;
*p=42;


-error frecuente 1: usar sin inicializar:
int* p=new int;
cout<<*p;

-correccion:
int* p=new int(0);



//2. Asignacion de arreglos:
int n;
cin>>n;
int* v=new int[n];

-error frecuente: asumir que el arreglo se inicializa
for(int i=0},i<n;i++){
    cout<<v[i];
}

correcion: 
int* v=new int[n]();

*/