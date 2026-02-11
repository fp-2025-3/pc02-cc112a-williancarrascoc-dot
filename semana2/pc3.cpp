/*
Considere que los coeficientes de un polinomio de grado n<100, p(x)=a_0 +a_1x+a_2x²+....a_x^n se 
almacenan en un arreglo A=[a_0,a_1,a_2,....a_n]. Escriba un programa que pida el ingreso de los coeficientes 
de un polinomio de grado n, luego pida un entero k positivo y finalmente imprima la derivada de orden k
de p(x). Utilice punteros para acceder a los valores del arreglo A.
Ejemplo de entrada: p(x)=3+2x+x²-5x³+2x⁴+3x⁵, A=[3,2,1,-5,2,3] y k=3 
Ejemplo de salida: p⁽³⁾(x)=-30+48x+180x², A=[-30,48,180,0,0,0]

*/
#include<iostream>
using namespace std;
int main(){
    int n,k;
    double A[100];
    cout<<"ingrese el grado del polinomio";
    cin>>n;
    cout<<"ingrese los coeficientes a0 a an:\n";
    for(int i=0;i<=n;i++){
        cin>>A[i];
    }
    cout<<"ingrese el orden de la derivada k: ";
    cin>>k;

    double *p=A;

    //si k>n, todo se anula
    if(k>n){
        for(int i=0;i<=n;i++){
            *(p+i)=0;
        }
    }

    else{
        for(int i=0;i<=n;i++){
            if(i<k){
                *(p+i)=0;
            }else{
                double coef=*(p+i);
                for(int j=0;j<k;j++){
                    coef *=(i-j);
                }
                    *(p+i-k)=coef;
            }
        }
            
            //anular terminos sobrantes
            for(int i=n-k+1;i<=n;i++){
                *(p+i)=0;
            }
        }


            //mostrar los resultados
            cout<<"coeficientes de p^("<<k<<")(x):\nA=[";
            for(int i=0;i<=n;i++){
                cout<<A[i];
                if(i<n){
                    cout<<" , ";
                }
            }
cout<<"]"<<endl;

    return 0;
}
