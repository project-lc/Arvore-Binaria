#include <stdio.h>

int main (){
    char string[100]; /* String, ate' 99 caracteres */
    int i, cont;

    printf("\n\nDigite uma frase: ");
    fgets(string, 100, stdin); /* Le a string */
    printf("\n\nFrase digitada:\n%s", string);
    cont = 0;
    
    for (i=0; string[i] != '\0'; i=i+1){
        
        if (string[i] == 'a' || string[i] == 'A'){
            
            cont = cont + 1; /* Incrementa o contador de caracteres */
            string[i] = 'b';
        }
    }
    
    printf("\nNumero de caracteres a = %d", cont);
    printf("\nNova frase: %s", string);
    
    return(0);
} 