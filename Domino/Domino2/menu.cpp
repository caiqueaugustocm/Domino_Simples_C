#include<stdio.h>
#include"lista_mesa.h"
#include"lista_mao.h"
#include"pilha_monte.h"
#include"dom.h"

void jogo();
int menu_jog(lista *mao_jog, int i);

lista *mao_jog1 = ini_lista(), *mao_jog2 = ini_lista(), *mesa = ini_lista();
pilha *monte = ini_pilha();

main()
{
	int key = 1, r;
	preenche_monte(monte);
	mao_jog1 = ini_lista();
	mao_jog2 = ini_lista();
	while(key){
		system("cls");
		titulo();
		printf("1 > Iniciar\n2 > Sair\n	:: ");
		fflush(stdin);
		scanf("%d", &r);
		switch(r){
			case 1:
				jogo();
				break;
			case 2:
			 sair();
				break;
			default:
				return 0;
		}
	}
}

void distribui_pecas(pilha *monte, lista *mao1, lista *mao2)//Distribui sete peças aos jogadores
{
	int cod, i;
	while((mao1->size < 7) && (mao2->size < 7)){
		pop(monte, &cod);
		inserir_ordenado(mao1, gera_peca(cod));
		pop(monte, &cod);
		inserir_ordenado(mao2, gera_peca(cod));
	}
}

void jogo()
{
	int key = 1;
//	system("cls");
	distribui_pecas(monte, mao_jog1, mao_jog2);
	while(key){
		key = menu_jog(mao_jog1, 1);
		key = menu_jog(mao_jog2, 2);
	}
}

int menu_jog(lista *mao_jog, int i)
{
	int key = 1, r;
	int cod;
	while(key){
//		system("cls")
		printf("Jogador(a) %d, eh a sua vez!\n\n", i);
		print_mao(mao_jog);
		printf("1 > Visualizar mesa\n2 > Cavar\n3 > Fazer jogada\n4 > Desistir\n	:: ");
		fflush(stdin);
		scanf("%d", &r);
		switch(r){
			case 1:
//				system("cls");
				print_mesa(mesa);
				printf("1 > Voltar");
				fflush(stdin);
				scanf("%d", &r);
				break;
			case 2:
				pop(monte, &cod);
				inserir_ordenado(mao_jog, gera_peca(cod));
				break;
			case 3:
				
				break;
		}
	}
}
