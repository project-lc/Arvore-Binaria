#include "tadlista1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lerstring(char nomearq[100]){

    setbuf(stdin, 0);
    fgets(nomearq, 100, stdin);
    nomearq[strlen(nomearq) - 1] = '\0';

    return nomearq;
}

Lista lerarqstr(FILE* arqin, Lista conteuarq){

    char* aux;

    aux = (char *)malloc(50*sizeof(char));
    
    while(!feof(arqin)){
        fgets(aux, 50, arqin);
        appendLista(conteuarq, aux);
        aux = NULL;
    }
    
    return conteuarq;
}

void imprimirarqstr(Lista lst){

    int i;
    FILE* arqout;

    arqout = fopen("saida.txt", "wt");

    for(i = 0; i < lenLista(lst); i++){
        printf("%s", dadoLista(lst, i));
        fprintf(arqout, "%s", dadoLista(lst, i));
    }

    fclose(arqout);

}

int main(){

    Lista nomes = criaLista(), alturas = criaLista(), cpfs = criaLista(), idades = criaLista();
    char /**nome, *cpf,*/ nomearq[100];
    float* altura;
    int* idade;
    FILE* arqin;

    printf("Digite o nome do arquivo a ser lido.\n");
    strcpy(lerstring(nomearq),nomearq);

    arqin = fopen(nomearq,"rt");
    
    lerarqstr(arqin, nomes);
    imprimirarqstr(nomes);

    fclose(arqin);

    return 0;
}