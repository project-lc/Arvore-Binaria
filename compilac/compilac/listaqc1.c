#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

    Autor: Lucas Cunha de Souza
    Estrutura de dados - 2022/1
    Programa para copiar conteúdo de um arquivo para o outro.

*/

char* lerstring(char nomearq[300]){

    setbuf(stdin, 0);
    fgets(nomearq, 300, stdin);
    nomearq[strlen(nomearq) - 1] = '\0';

    return nomearq;
}

char* lerarqtodo(FILE* arqin, char* conteuarq){

    char auxiliar[40000];

    while(!feof(arqin)){
        fgets(auxiliar, 40000, arqin);
        strcat(conteuarq,auxiliar);
        /*strcat(conteuarq,"\n");*/
    }
    
    return conteuarq;
}

int main(){

    char conteuarq[40000], nomearq[300];
    FILE* arqin;
    FILE* arqout;

    printf("Ola. Por favor, digite o nome do arquivo que quer copiar.\n");
    strcpy(lerstring(nomearq),nomearq);

    arqin = fopen(nomearq,"rt");
    arqout = fopen("saida.txt","wt");

    /*fscanf(arqin, "%[^\n]s", conteuarq);*/

    lerarqtodo(arqin, conteuarq);

    /*printf("%s", conteuarq);*/

    fprintf(arqout, "%s", conteuarq);

    fclose(arqin);
    fclose(arqout);

    return 0;
}