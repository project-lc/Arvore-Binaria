#include <stdio.h>

typedef struct{
  
    double valorkwh;    //preço do kWh consumido;
    int numcon;         //numero do consumidor;
    double qntcon;      //quantidade de kWh consumidos durante o mes;
    int cod;            //codigo do tipo de consumidor (residencial, comercial, industrial).

}conta;


int main(){

    conta info;
    double high = -1, less = -1, total[3];
    int i;
    
    for(i = 0; i < 3; i++){
        total[i] = 0;
    }

    printf("Digite o valor do do preco do kWh consumido.\n");
    scanf("%lf", &info.valorkwh);

    printf("Digite o numero do consumidor.\nPara deixar claro:\n0 = Interromper o programa.\n1 = Residencial.\n2 = Comercial.\n3 = Industrial.\n");
    scanf("%d", &info.numcon); // Numero do consumidor

    while(info.numcon != 0){

        printf("Quantidade de kWh consumido nesse mes.\n");
        scanf("%lf", &info.qntcon);

        printf("Codigo do tipo de consumidor.\n");
        scanf("%lf", &info.cod);

        if(high < info.qntcon){
            high = info.qntcon;
        }

        if(less > info.qntcon){
            less = info.qntcon;
        }

        printf("Sua conta totalizou %lf ");

    }

    return 0;

}