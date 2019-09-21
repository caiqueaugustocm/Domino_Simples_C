#ifndef MONTE_H
#define MONTE_H
#include<stdio.h>
#include<stdlib.h>

typedef struct noaux_pilha{
	int cod;
	struct noaux_pilha *prox;
}no_pilha;

typedef struct{
	no_pilha *topo;
}pilha;

pilha* ini_pilha() //Função inicializar a pilha
{
	pilha *monte = (pilha*)malloc(sizeof(pilha));
	monte->topo = NULL;
	return monte;
}

int pilha_empty(pilha *monte) //Função que identifica se a  pilha ta vazia
{
	if(monte->topo == NULL)
		return 1;
	return 0;
}

no_pilha *aloc_pilha()//Função que aloca dinamicamente da pilha
{
	no_pilha *newno;
	newno = (no_pilha*)malloc(sizeof(no_pilha));
	return newno;
}

int push(pilha *monte, int item_a_inserir)//Função que insere elementos
{
	no_pilha *newno = aloc_pilha();
	if(!newno)
		return 0;
	newno->cod = item_a_inserir;
	if(monte->topo == NULL){
		newno->prox = NULL;
		monte->topo = newno;
	}else{
		newno->prox = monte->topo;
		monte->topo = newno;
	}
	return 1;
}

int pop(pilha *monte, int *captura_item_retirado)//Função que retirar o último elemento inserido
{
	no_pilha *atu;
	if(pilha_empty(monte))
		return 0;
	*captura_item_retirado = monte->topo->cod;
	atu = monte->topo;
	monte->topo = monte->topo->prox;
	free(atu);
	return 1;
}

int busca_pilha(pilha *monte, int cod)//Função que "rastreia" e identifica o elemento desejado
{
	int e;
	while(!pilha_empty(monte)){
		pop(monte, &e);
		if(e == cod)
			return 1;
	}
	return 0;
}

void preenche_monte(pilha *monte)//Função que preenche o monte do dominó randomicamente
{
	int num1, num2, cod;
	for(int i = 0; i < 28; i++){
		num1 = rand()%6;
		num2 = rand()%6;
		cod = num1*10 + num2;
		if(!busca_pilha(monte, cod))
			push(monte, cod);
		else
			i--;
	}
}

#endif
