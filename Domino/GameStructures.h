#ifndef _structs
#define _structs

#include "Lista.h"
#include "Pilha.h"

typedef struct{
	tp_list_se* mao;
	char* nome;
}jogador;

typedef struct{
	tp_list_se* pecas;
	stack monte;
}mesa;

#endif
