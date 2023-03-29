#include <stdio.h>
#include <math.h>

long double termo(double angulo, int tamanho){

    int cont;
    long double res = 0;

    for(cont = 1; cont <= tamanho; cont++){
        res = res + ((-1) * (cont + angulo)/ cont);
    }

    printf("%Lf\n", res);

    return res;
}

int main(){

    int tamanho = 5, i;
    double a;

    for(i = 0; i <= 360; i = i +2){
                
        printf("Angulo: %3d     Seno sistema: %f     Seno funcao: %Lf     Diferenca entre ambos: %Lf\n", i, sin(i), termo(i, tamanho), sin(a)-termo(a, tamanho));
    }

    return 0;
}