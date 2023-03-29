#include <stdio.h>
#include <stdlib.h>

/*
 * prova2.c
 *
 *  Created on: 13 de mai. de 2022
 *      Author: cunha.lucas
 */

void ordena(int* input){

    int* p;
    int aux;
    
    p = &aux;

    if(input[0] > input[1]){
        aux = input[1];
        input[1] = input[0];
        input[0] = *p;
        if(input[1] > input[2]){
            aux = input[2];
            input[2] = input[1];
            input[1] = *p;
            if(input[0] > input[1]){
                aux = input[1];
                input[1] = input[0];
                input[0] = *p;
            }
        }
    }
    else{
        if(input[1] > input[2]){
            aux = input[2];
            input[2] = input[1];
            input[1] = *p;
        }
    }

}

int main(){

    int input[3], i;

    input[0] = 5;
    input[1] = 1;
    input[2] = 2;
    

    ordena(input);

    for(i = 0; i < 3; i++){
        printf("%d\n", input[i]);
    }

    return 0;
}