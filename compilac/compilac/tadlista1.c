#include "tadlista1.h"
#include <stdlib.h>

Lista criaLista(){
    Lista lista = (tcabec *)malloc(sizeof(tcabec));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
    return lista;
}
int lenLista(Lista lst){
    return lst->tamanho;
}
tdado primLista(Lista lst){
    return lst->primeiro->dado;
}
tdado ultLista(Lista lst){
    return lst->ultimo->dado;
}
Lista appendLista(Lista lst, tdado dado){
    if(lst == NULL) return NULL;
    
    pnoh novoNo = (pnoh)malloc(sizeof(tnode));
    novoNo->proximo = NULL;
    novoNo->dado = dado;
    
    if (lst->tamanho == 0){
        lst->primeiro = novoNo;
        lst->ultimo = novoNo;
    }
    else{
        lst->ultimo->proximo = novoNo;
        lst->ultimo = novoNo;
    }
    
    lst->tamanho++;

    return lst;
}

tdado dadoLista(Lista lst, int pos){

    int contpulos;
    pnoh no_corrente;
    
    if((lst == NULL) || (pos < 0) || (pos >= lst->tamanho))
		return NULL;
		
	contpulos = 0;
	no_corrente = lst->primeiro;
		
	while(contpulos != pos){
        contpulos++;
        no_corrente = no_corrente->proximo;
	}
	
	return no_corrente->dado;
} 

int indexLista(Lista lst, tdado dado);
//Lista clearLista(Lista lst);
Lista insertLista(Lista lst, int pos, tdado dado);
Lista removeLista(Lista lst, int pos);
