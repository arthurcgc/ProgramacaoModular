#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>
#include "BARALHO.h"
#include "LISTA.H"


#define	TRUCO 40

void DestruirValor(void * pValor)
	{
		free(pValor);
	}


typedef struct BAR_tagCarta
{
	char nome[20];
	int peso;
	char naipe[20];
}	BAR_tpCarta;


typedef struct BAR_tagBaralho
{
	LIS_tppLista Cartas;
}	BAR_tpBaralho;



BAR_tpCondRet BAR_CriaCarta(BAR_tppCarta *carta,char *nome, int peso,char *naipe)
{
	BAR_tpCarta *aux_carta;
	aux_carta=(BAR_tpCarta*)malloc(sizeof(BAR_tpCarta));
	if(aux_carta==NULL) return BAR_CondRetFaltouMemoria;
	strcpy(aux_carta->nome,nome);
	strcpy(aux_carta->naipe,naipe);
	aux_carta->peso=peso;
	*carta=aux_carta;
	return BAR_CondRetOK;
}


BAR_tpCondRet BAR_CriarBaralho(BAR_tppBaralho *pBar,void   ( * ExcluirValor ) ( void * pDado ))
{
	*pBar = (BAR_tpBaralho*)malloc(sizeof(BAR_tpBaralho));
	(*pBar)->Cartas = LIS_CriarLista(DestruirValor);
	for(int i=0;i<TRUCO;i++)
	{
			LIS_InserirElementoApos((*pBar)->Cartas, 1);
	}
	return BAR_CondRetOK;
}
