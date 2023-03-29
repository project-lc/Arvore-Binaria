#include <stdio.h>

int soma(int x, int y){
    return x+y;
}

int main(){
    int x, y;

    printf("Digite um inteiro.\n");
    scanf("%d", &x);
    printf("Digite um inteiro.\n");
    scanf("%d", &y);

    printf("O resultado da soma eh %d.", soma(x,y));
    
    return 0;
}