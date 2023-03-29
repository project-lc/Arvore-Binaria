#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char var[10000], st[10000];

    setbuf(stdin, 0);

    fgets(var, 10000, stdin);
    var[strlen(var)-1] = '\0';

    fgets(st, 10000, stdin);
    st[strlen(st)-1] = '\0';

    printf("A segunda letra da primeira string e %c.\nA segunda letra da segunda string e %c.\n", var[1], st[1]);

    system("pause");

    return 0;
}