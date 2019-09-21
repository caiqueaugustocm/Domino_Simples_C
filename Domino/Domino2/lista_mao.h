#ifndef MAO_H
#define MAO_H
#include<stdio.h>
#include<stdlib.h>
#include"dom.h"

/*28 peças:
cod = 00 > 0:0
    = 01 > 0:1
    = 02 > 0:2
    = 03 > 0:3
    = 04 > 0:4
    = 05 > 0:5
    = 06 > 0:6
    = 11 > 1:1
    = 12 > 1:2
    = 13 > 1:3
    = 14 > 1:4
    = 15 > 1:5
    = 16 > 1:6
    = 22 > 2:2
    = 23 > 2:3
    = 24 > 2:4
    = 25 > 2:5
    = 26 > 2:6
    = 33 > 3:3
    = 34 > 3:4
    = 35 > 3:5
    = 36 > 3:6
    = 44 > 4:4
    = 45 > 4:5
    = 46 > 4:6
    = 55 > 5:5
    = 56 > 5:6
    = 66 > 6:6*/

void print_mao(lista *mao)//Exibe a mão do jogador
{
	no_lista *atu;
	int i = 0;
	atu = mao->ini;
	while(atu != NULL){
		i++;
		printf("%d > %d:%d\n", i, atu->info.ladoE, atu->info.ladoD);
		atu = atu->prox;
	}
}

int remove_peca_mao(lista *mao, int local, int *cod)//Retira da mão a peça do local requerido e manda de volta seu codigo
{
	no_lista *atu;
	atu = mao->ini;
	int i = 1;
	while((atu != NULL) && (i < local)){//Procura a peça do local pedido
		atu = atu->prox;
		i++;
	}
	if(atu == NULL)
		return 0;
	*cod = atu->info.cod;
	if(mao->ini == mao->fim)//Se for o unico elemento da lista
		mao->ini = mao->fim = NULL;
	else{
		if(mao->ini == atu){//Se for o primeiro elemento da lista
			mao->ini = atu->prox;
			atu->prox->ant = NULL;
		}else{
			if(mao->fim == atu){//Se for o ultimo no da lista
				mao->fim = atu->ant;
				atu->ant->prox = NULL;
			}else{//No intermediario
				atu->prox->ant = atu->ant;
				atu->ant->prox = atu->prox;
			}
		}
	}
	mao->size--;
	free(atu);
	return 1;
}

int inserir_ordenado(lista *mao, peca e)//Insere um item oredenadamente (mão do jogador)
{
	no_lista *newno;
	newno = aloc_lista();
	if(!newno)
		return 0;
	newno->info = e;
	e.sum = e.ladoD + e.ladoE;
	if(lista_empty(mao)){//Se a lista estiver vazia
		newno->prox = NULL;
		newno->ant = NULL;
		mao->ini = mao->fim = newno;
		return 1;
	}else{
		no_lista *atu = mao->ini;
		while((atu != NULL) && (atu->info.sum < e.sum))//Procura a peça anterior da nova peça que será inserida 
 			atu = atu->prox;
		if(atu == mao->ini){//Início
			newno->ant = NULL;
			newno->prox = mao->ini;
			mao->ini->ant = newno;
			mao->ini = newno;
		}else{
			if(atu != NULL){//Meio
				newno->prox = atu;
				atu->ant->prox = newno;
				newno->ant = atu->ant->prox;
				atu->ant = newno;
			}else{//Final
				newno->ant = mao->fim;
				newno->prox = NULL;
				mao->fim = newno;
			}
		}
	}
	return 1;
}

#endif
