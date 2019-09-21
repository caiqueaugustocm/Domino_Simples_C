#ifndef _LIST_SE
#define _LIST_SE

#include<stdio.h>
#include<stdlib.h>

typedef int tp_item;

typedef struct no{
	tp_item item;
	struct no *prox;
}tp_list_se;

tp_list_se* Init();
int CountList(tp_list_se* l);


 tp_list_se* Init(){
	return NULL;
}

tp_list_se* Alloc(){
	tp_list_se* t = (tp_list_se*)malloc(sizeof(tp_list_se));
	return t;
}

tp_list_se* Find(tp_list_se* l, tp_item e){
	tp_list_se* atu = l;
	int i=1;
	while(atu!=NULL && i=<e){
		atu=atu->prox;
	}
	return atu;
}

bool IsEmpty(tp_list_se* l){
	if(l==NULL) return true;
	return false;
}
 
bool Add(tp_list_se** l,tp_item e){
	
	tp_list_se* atu;
	tp_list_se* novo_no=Alloc();
	
	if(novo_no == NULL) return false;
	
	novo_no->item = e;
	novo_no->prox = NULL;
	
	if(IsEmpty(*l)){
		*l=novo_no;
	}else{
		
		atu=*l;
		while(atu->prox!= NULL){
			atu=atu->prox;
		}
		atu->prox = novo_no;
	}
	return true;
}
bool AddIni(tp_list_se** l,tp_item e){
	
	tp_list_se* atu;
	tp_list_se* novo_no=Alloc();
	
	if(novo_no == NULL) return false;
	
	novo_no->item = e;
	novo_no->prox = NULL;
	
	if(IsEmpty(*l)){
		*l=novo_no;
	}else{
		
	atu=*l;
	novo_no->prox = atu;
	*l=novo_no;
	}
	return true;
}
bool OrderedAdd(tp_list_se** l,tp_item e){
	tp_list_se *novo_no,*atu,*ant;
	novo_no =Alloc();
	
	if(novo_no==NULL) return 0;
	novo_no->item= e;
	atu=*l;
	ant=NULL;	
	
	while((atu!=NULL) && atu->item<e){
	ant=atu;
	atu=atu->prox;
	}
	if(ant==NULL){
	
		*l=novo_no;
	}
	else{
		ant->prox = novo_no;
	}
	novo_no->prox=atu;
	return true;
}

void Concat(tp_list_se* a,tp_list_se* b){
	tp_list_se* atu;
	atu=a;
		while(atu->prox!= NULL){
			atu=atu->prox;
		}
		atu->prox = b;
		atu=b;
		while(atu->prox!= NULL){
			atu=atu->prox;
		}
		atu->prox=a;
		b=a;
}

tp_list_se* Divide(tp_list_se list,tp_item e){
		tp_list_se* atu = &list;
		tp_list_se* newList;
		while(atu->prox!= NULL && atu->item!=e){
			atu=atu->prox;
		}
		if(atu==NULL) return NULL;
		newList=atu->prox;
		atu->prox=NULL;
		return newList;
}

bool Remove(tp_list_se** l,tp_item e){
	tp_list_se* ant;
	tp_list_se* atu;
	
	atu=*l;
	ant=NULL;
	
	while((atu!=NULL) && (atu->item!=e)){
		ant = atu;
		atu = atu->prox;
	}
	
	if(ant== NULL){
		*l= atu->prox;
		free(atu);
		return true;
	}
	if(atu==NULL){
		return false;
	}
	ant->prox = atu->prox;
	free(atu);
	return true;
}

void PrintList(tp_list_se* l,int Length){
	tp_list_se* atu;
	atu=l;
	register int t=0;
	for(;t<Length;t++){
	printf("%d ",atu->item);
		atu=atu->prox;	
	}
}

void PrintFormatedToDomino(tp_list_se* l){
	tp_list_se* atu;
	atu=l;
	int size = CountList(l);
	register int t=0;
	for(;t<size;t++){
	printf("[%d|%d] ",atu->item/10,atu->item%10);
		atu=atu->prox;	
	}
}

void Clear(tp_list_se** l){
	tp_list_se* atu;
	atu=*l;
	
	while(atu!=NULL){
		*l=atu->prox;
		free(atu);
		atu=*l;
	}
		
	*l=NULL;
}

int CountList(tp_list_se* l){

	tp_list_se* atu = l; 
	register int i=0;
	
	while(atu!=NULL ){
		atu=atu->prox;
		i++;
	}
	return i;
}

int Get(tp_list_se* l,tp_item* e){
	if(IsEmpty(l)) return -1;
	tp_list_se* atu = l;
	while(atu->prox!=NULL){
		atu=atu->prox;
	}
	*e=atu->item;
	return true;
}
int GetIni(tp_list_se* l,tp_item* e){
	if(IsEmpty(l)) return -1;
	*e=l->item;
	return true;
}
#endif
