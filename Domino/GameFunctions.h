#ifndef _functions
#define _functions

#include <iostream>
#include "GameStructures.h"
#include "Lista.h"
#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

	 int screenx=0,screeny=0;
	 int x_size = 128,y_size = 16;
	 int x_start=3,y_start=3,dist=4;
	 int pecaParaJogar=-1;

int seed=0;

void AtualizaTela();
int Novo_Monte(stack* s);
void IniciarMesa(mesa* Mesa);
void IniciaJogador(jogador* Player,mesa* Mesa,char* nome);
int PorNaMesa(int PecaCode,mesa* Mesa,jogador* Player,int dir);
int JogadaValida(int PecaCode,mesa* Mesa,int dir);
void PegarDoMonte();
void IniciarJogo(mesa* Mesa,jogador* Player1, jogador* Player2);
void gotoxy(int x, int y);
void PutCharOnPosition(int x,int y,char c);

int Jogador(jogador* Player,mesa* Mesa);

void IniciarMesa(mesa* Mesa){
	
	Mesa->pecas = Init();
	Creat(&Mesa->monte);
	
	Novo_Monte(&Mesa->monte);
	
	printf("Ordem do monte: ");
	PrintStack(&Mesa->monte,' ');
	printf("\n");
}

void IniciaJogador(jogador* Player,mesa* Mesa,char* nome){
	register int peca,i;
	
	Player->mao = Init();
	Player->nome = nome;
	for(i=0;i<7;i++){
		Pop(&Mesa->monte,&peca);
		Add(&Player->mao,peca);
	}
	
	PrintList(Player->mao,CountList(Player->mao));
}

int PorNaMesa(int PecaCode,mesa* Mesa,jogador* Player,int dir){

		if(dir==2){
		if(JogadaValida(PecaCode,Mesa,dir)!=-1){
				Add(&Mesa->pecas,PecaCode);	
		    Remove(&Player->mao,PecaCode);
		    return 1;
			}
		    
		}
		else
		{
		if(JogadaValida(PecaCode,Mesa,dir)!=-1){
			AddIni(&Mesa->pecas,PecaCode);
			Remove(&Player->mao,PecaCode);
			return 1;
		}
		}
	
	
return -1;
}

int JogadaValida(int PecaCode,mesa* Mesa,int dir){
	
//-1 jogada invalida
//-2 mesa vazia, jogada sempre válida
// caso contrario retorna a peca

	
	int peca;
	int pecaR;
	if(dir==2){
	    if(Get(Mesa->pecas,&peca)==-1) return -2;
	
	}else{
	    if(GetIni(Mesa->pecas,&peca)==-1)return -2;
	}
	
	pecaR=peca;
		
	if(peca%10 == PecaCode%10 || peca%10 == PecaCode/10 || peca/10 == PecaCode%10||peca/10 == PecaCode/10){
		
		
		
		if(dir==2 && (peca%10 != PecaCode/10)){
			
	        pecaR=((peca%10)*10) + PecaCode/10;
	    }else if(PecaCode%10 != peca/10){
	    	pecaR=((PecaCode%10)*10) + peca/10;
		}
			return pecaR;
	}
		
		return -1;
}

void PegarDoMonte(){
	
}

int Novo_Monte(stack* s) {
	register int v = -1;
	srand(time(NULL) + seed);
	seed += 10;
	while (IsFull(s)==0)
	{
		v = rand() % 67;
	
		if (((v >= 0 && v <= 6) || (v >= 11 && v <= 16) || (v >= 22 && v <= 26) || (v >= 33 && v <= 36) || (v >= 44 && v <= 46) || v== 55 || v == 56 || v == 66)) {
			
			if (!ExistElement(s, v)) {
				Push(s, v);
			}
		}
	}
	
	
	return v;
}

void AtualizaTela(mesa* Mesa){
	system("cls");

      screenx=0;
	  screeny=0;
	  x_size = 128;
	  y_size = 16;
	  x_start=3;
	  y_start=3;
	  dist=4;
	
	for(screenx=0;screenx<x_size;screenx++){
		for(screeny=0;screeny<y_size;screeny++){
			
			if(screenx==0 && screeny==0 ) PutCharOnPosition(screenx+x_start,screeny+y_start,201);
			else if(screenx==0 && screeny==y_size-1 ) PutCharOnPosition(screenx+x_start,screeny+y_start,200);
			else if(screenx == x_size-1 && screeny == y_size-1) PutCharOnPosition(screenx+x_start,screeny+y_start,188);
			else if(screenx == x_size-1 && screeny == 0) PutCharOnPosition(screenx+x_start,screeny+y_start,187);
			else if(screenx ==0 && screeny!=0) PutCharOnPosition(screenx+x_start,screeny+y_start,186);
			else if(screenx!=0 && screeny==0) PutCharOnPosition(screenx+x_start,screeny+y_start,205);
			else if(screenx == x_size-1 && screeny!=0) PutCharOnPosition(screenx+x_start,screeny+y_start,186);
			else if(screenx!=0 && screeny==y_size-1) PutCharOnPosition(screenx+x_start,screeny+y_start,205);
		}	
	}
	
	for(screenx=0;screenx<x_size;screenx++){
		for(screeny=0;screeny<y_size/2;screeny++){
			
			if(screenx==0 && screeny==0 ) PutCharOnPosition(screenx+x_start,screeny+dist+y_size,201);
			else if(screenx==0 && screeny==y_size/2 -1 ) PutCharOnPosition(screenx+x_start,screeny+dist+y_size,200);
			else if(screenx == x_size-1 && screeny == y_size/2 -1) PutCharOnPosition(screenx+x_start,screeny+dist+y_size,188);
			else if(screenx == x_size-1 && screeny == 0) PutCharOnPosition(screenx+x_start,screeny+dist+y_size,187);
			else if(screenx ==0 && screeny!=0) PutCharOnPosition(screenx+x_start,screeny+dist+y_size,186);
			else if(screenx!=0 && screeny==0) PutCharOnPosition(screenx+x_start,screeny+dist+y_size,205);
			else if(screenx == x_size-1 && screeny!=0) PutCharOnPosition(screenx+x_start,screeny+dist+y_size,186);
			else if(screenx!=0 && screeny==y_size/2 -1) PutCharOnPosition(screenx+x_start,screeny+dist+y_size,205);
		}	
	}
	
	gotoxy(x_start+2,(y_size/2)+ y_size/4);
	PrintFormatedToDomino(Mesa->pecas);
	
}

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void PutCharOnPosition(int x,int y,char c){
gotoxy(x,y);
printf("%c",c);	
}

void IniciarJogo(mesa* Mesa,jogador* Player1, jogador* Player2){
	cout<< "Comecando partida\n\n";
		char n[15];
		char n2[15];
		
		fflush(stdin);
		printf("%s","Nome do Player 1: ");
		gets(n);
		fflush(stdin);
		printf("%s","Nome do Player 2: ");
		gets(n2);
		fflush(stdin);
		
	cout<<"Gerando monte...\n";
	IniciarMesa(Mesa);
	cout<<"Monte gerado!\n\n";
	
	cout<<"Dando pecas aos jogadores...\n";
	cout<<"Mao do jogador1: ";

	IniciaJogador(Player1,Mesa,n);
	cout<<"Mao do jogador2: ";

	IniciaJogador(Player2,Mesa,n2);
	
	cout<<"Jogadores prontos!\n\n";
}

int Jogador(jogador* Player,mesa* Mesa){
	int dir=0;
	
	gotoxy(x_start+2,screeny+dist+2+y_size/2);
	
	cout<<"Sua mao: ";
 	PrintFormatedToDomino(Player->mao);
 
 	gotoxy(x_start+2,screeny+dist+3+y_size/2);
 	
	 if(pecaParaJogar==-1){
 		cout<<"Digite qual peca deseja jogar: ";
 		cin>>pecaParaJogar;
 		
		 if(Find(Player->mao,pecaParaJogar)==NULL){
 			pecaParaJogar=-1;
 			return -1;
		 }
		 
 		gotoxy(x_start+2,screeny+dist+4+y_size/2);
 	}
 	
	 
 	  cout<<"Digite em qual lado deseja jogar (1 = Esquerdo, 2 =Direito ): ";
 	  cin>>dir;	
	 if(dir!=1 && dir!=2) return -1;
	
	if(PorNaMesa(pecaParaJogar,Mesa,Player,dir)==-1) return -1;
	
 	pecaParaJogar=-1;
 	return 1;
}

	
int PodeJogar(jogador* Player,mesa* Mesa){
	int i,j,size;
	size=CountList(Player->mao);

	for(i=0;i<size;i++){
		
	}
}

#endif
