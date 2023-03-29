#include <stdio.h>

typedef struct{
	
	float kwhpre; 	//preço do kWh consumido
	float kwhqtd;	//quantidade de kWh consumidos durante o mês
	int numcon;		//número do consumidor
	int codcon;		//código do tipo de consumidor (residencial, comercial, industrial)
	
}conta;

double higher(double maior, double consumo){
	
	if (maior > consumo){
		return maior;
	}
	
	else{
		return consumo;
	}
	
}

double smaller(double menor, double consumo){
	
	if (menor < consumo){
		return menor;
	}
	
	else{
		return consumo;
	}	
	
}

double* zeravetor(double *total){
	
	int i;
	
	for(i = 0; i < 3; i++)
		total[i] = 0;
	
	return total;
}

double* tipocon(conta consumidor, double *total){
	
	total[consumidor.codcon - 1] = total[consumidor.codcon - 1] + consumidor.kwhqtd;
	
	return total;
	
}

void ImprimirTotalTipo(double *total){
	int i;

	for(i = 0; i < 3; i++){

		printf("O total de consumo para o código 0%d foi %lf.\n", i, total[i]);

	}
}

void ImprimirMedia(double *total, int denominador){

	int i;
	double numerador;
	
	for(i = 0; i < 3; i++)
		numerador = numerador + total[i];
	
	printf("A media geral de consumo foi: %lf.\n", numerador/denominador);	

}

int main(){
	
	int cont = 0;	//Contando quantas vezes vai passar no while
	conta consumidor;
	double consumo = 0;
	double maior = -1, menor = 999999999, total[3];
	
	zeravetor(total);
	
	printf("Digite o codigo do tipo do consumidor. Lembrando que:\n0 - Interrompe o programa.\n1 - Residencial.\n2 - Comercial.\n3 - Industrial.\n");
	scanf("%d", &consumidor.codcon);
	while(consumidor.codcon != 0){
	
		printf("Entre com o numero do consumidor.\n");
		scanf("%d", &consumidor.numcon);
		printf("Entre com o preco do kWh consumido.\n");
		scanf("%f", &consumidor.kwhpre);
		printf("Entre com a quantidade de kWh consumido.\n");
		scanf("%f", &consumidor.kwhqtd);
		
		consumo = consumidor.kwhpre * consumidor.kwhqtd;
		
		higher(maior, consumidor.kwhqtd);
		smaller(menor, consumidor.kwhqtd);
		
		tipocon(consumidor, total);
		
		printf("O consumidor %d precisará pagar %f.\n", consumidor.numcon, consumo);
		
		cont++;
		
		printf("Digite o codigo do tipo do consumidor. Lembrando que:\n0 - Interrompe o programa.\n1 - Residencial.\n2 - Comercial.\n3 - Industrial.\n");
		scanf("%d", &consumidor.codcon);
		
	}
	
	printf("O maior consumo verificado: %lf.\nO menor consumo verificado: %lf.\n", maior, menor);
	
	ImprimirTotalTipo(total);
	
	ImprimirMedia(total, cont);

	return 0;
}
