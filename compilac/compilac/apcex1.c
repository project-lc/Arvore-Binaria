#include <stdio.h>

int main(){
    char var;

    printf("Digite um caracter.\n");
    scanf("%c", &var);

    printf("O caracter digitado foi %c e tem codigo na tabela ASCII como %d.\n", var, var);
    
    return 0;
}