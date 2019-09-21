#ifndef _pilha
#define _pilha

#include<stdio.h>

#define _SIZE_PILHA 28

typedef int element;

typedef struct{
	element elements[_SIZE_PILHA];
	int top;
}stack;

bool Creat(stack* s){
	s->top=-1;
	return true;
}

bool IsEmpty(stack* s){
	return s->top==-1;
}

bool IsFull(stack* s){
	return s->top==_SIZE_PILHA-1;
}

bool Push(stack* s,element e){
	if(IsFull(s)) return false;
		s->elements[++s->top] = e;
	return true;
}

bool Pop(stack* s,element* e){
	if(IsEmpty(s)) return false;
	if(e!=NULL)	*e=s->elements[s->top--];
	else s->top--;
	return true;
}

bool Top(stack* s,element* e){
	if(IsEmpty(s)) return false;
		*e=s->elements[s->top];
	return true;
}

int CountPilha(stack* s){
	return s->top + 1;
}

bool PrintStack(stack* s,char betwen){
	if(IsEmpty(s)) return false;
	register int t = s->top;
	while(t!=-1){
		printf("%d",s->elements[t]);
		printf("%c",betwen);
		t--;
	}
	return true;
}
bool ExistElement(stack* s,element e){
	if(IsEmpty(s)) return false;

	register int t = s->top;
	
	for (; t != -1;t--) {
		if(s->elements[t]==e){
			return true;
		}
	}
	return false;
}



#endif
