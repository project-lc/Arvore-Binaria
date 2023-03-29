#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * prova.c
 *
 *  Created on: 13 de mai. de 2022
 *      Author: cunha.lucas
 */


typedef struct{

	char placa[20];
	char modelo[20];
	char marca[20];
	char km[20];

}tveiculo;

void filtro(tveiculo* veiculos, char* saidat, int tam, char* marcap){

	FILE* asaida = fopen(saidat, "wt");
	int i;

	for(i = 0; i < tam; i++){
		if(veiculos[i].marca == marcap){
			fprintf(asaida, "%s", veiculos[i].placa);
			fprintf(asaida, "%s", veiculos[i].modelo);
			fprintf(asaida, "%s", veiculos[i].marca);
			fprintf(asaida, "%s", veiculos[i].km);
		}
	}

	fclose(asaida);
}

int main(){

	FILE* inputv;
	tveiculo veiculos[150];
	int cont = 0, posv = 0;
	char saidafiat[14] = "saidafiat.txt", saidatoy[13] = "saidatoy.txt", saidaf[14] = "saidaford.txt", saidar[12] = "saidare.txt";
	char m1[5] = "FIAT", m2[7] = "TOYOTA", m3[5] = "FORD", m4[8] = "RENAULT";

	inputv = fopen("bdveiculos.txt", "rt");

	while(!feof(inputv)){

		if((cont + 1) % 4 == 0){
			fscanf(inputv,"%s",veiculos[posv].placa);
			printf("%s", veiculos[posv].placa);
		}
		else{
			if((cont + 1) % 4 == 1){
				fscanf(inputv,"%s",veiculos[posv].modelo);
				printf("%s", veiculos[posv].modelo);
			}
			else{
				if((cont + 1) % 4 == 2){
					fscanf(inputv,"%s",veiculos[posv].marca);
					printf("%s", veiculos[posv].marca);
				}
				else{
					if((cont + 1) % 4 == 3){
						fscanf(inputv,"%s", veiculos[posv].km);
						posv++;
						printf("%s", veiculos[posv].km);
					}
				}
			}
		}

		cont++;
	}

	filtro(veiculos, saidafiat, 150, m1);
	filtro(veiculos, saidatoy, 150, m2);
	filtro(veiculos, saidaf, 150, m3);
	filtro(veiculos, saidar, 150, m4);

	fclose(inputv);

	return 0;
}
