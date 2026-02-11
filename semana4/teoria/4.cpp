//Liberacion de memoria: operador delete
/*
4.1 liberacion correcta
delete p;
p=nullptr;

4.2 Liberacion de arreglos
delete[] v;
v=nullptr;

4.3 errores críticos frecuentes
error 1: olvidar liberar
int* v=new int[100];
//no delete[]
-provoca memory leak

error 2:usar delete en lugar de delete[]
int* v=new int[100];
delete v;  //error -> es arreglo

error 3: doble liberacion:
int* p=new int;
delete p;
delete p; //error   --> detectado por Asan


*/