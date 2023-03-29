#include <stdio.h>
#include <math.h>

long double potencia(int expoente, double base){

    int i;
    long double resultado = 1;

    for(i = 0; i < expoente; i++){
        resultado = resultado * base;
    }

    return resultado;
}

long int fatorial(int fat){

    int cont1, result = 1;

    for(cont1 = fat; cont1 >= 1; cont1--){
        result = result * cont1;
    }

    return result;
}

double rad(int ang){

    double pi = 3.1415, radiano;

    radiano = (ang * pi)/180;

    return radiano;
}

long double termo(double angulo, int tamanho){

    int cont, i = 0;
    long double res = 0;

    for(cont = 1; cont <= tamanho; cont = cont + 2){
        res = res + (potencia(i, -1) * (potencia(cont, angulo)/ fatorial(cont)));
        i++;
    }

    return res;
}

int main(){

    int tamanho = 10, i;
    double a;

    for(i = 0; i <= 360; i = i +2){
        
        a = rad(i);        
        printf("Angulo: %3d     Seno sistema: %f     Seno funcao: %Lf     Diferenca entre ambos: %Lf\n", i, sin(a), termo(a, tamanho), sin(a)-termo(a, tamanho));
    }

    return 0;
}