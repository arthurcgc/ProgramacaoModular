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
	char nome;
	int peso;
	char naipe[20];
}	BAR_tpCarta;


typedef struct BAR_tagBaralho
{
	LIS_tppLista Cartas;
}	BAR_tpBaralho;



BAR_tpCondRet BAR_CriaCarta(BAR_tppCarta *carta,char nome, int peso,char *naipe)
{
	BAR_tpCarta *aux_carta;
	aux_carta=(BAR_tpCarta*)malloc(sizeof(BAR_tpCarta));
	if(aux_carta==NULL) return BAR_CondRetFaltouMemoria;
	aux_carta->nome=nome;
	strcpy(aux_carta->naipe,naipe);
	aux_carta->peso=peso;
	*carta=aux_carta;
	return BAR_CondRetOK;
}


BAR_tpCondRet BAR_CriarBaralho(BAR_tppBaralho *pBar)
{
	int i;
	int *p=(int*)malloc(sizeof(int));
	BAR_tppCarta vetor_cartas[40];
	BAR_tpCondRet retorno;
	//ponteiro para baralho
	*pBar = (BAR_tpBaralho*)malloc(sizeof(BAR_tpBaralho));
	//cria as 40 cartas e armazena em um vetor
	retorno=BAR_CriaVetorCartas(vetor_cartas);
	if ( *pBar == NULL )
      {
         return  BAR_CondRetFaltouMemoria ;
      }
	(*pBar)->Cartas = LIS_CriarLista(DestruirValor);
	for(i=0;i<TRUCO;i++)
	{
		*p=i;
		//insere a carta na lista
		LIS_InserirElementoApos((*pBar)->Cartas,vetor_cartas[i]);
	}
	return BAR_CondRetOK;
}


//cria vetor de cartas todas com o mesmo peso
BAR_tpCondRet BAR_CriaVetorCartas(BAR_tppCarta cartas[])
{
	BAR_tpCondRet retorno;
	char *naipe[10][4];
	BAR_tppCarta *carta=(BAR_tppCarta*)malloc(sizeof(BAR_tppCarta));
	int i,j,cont,alt;
	naipe[0][0]="ouros";naipe[0][1]="copas";
	naipe[0][2]="paus";naipe[0][3]="espadas";
	cont=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<4;j++)
		{
			//cria cartas de 2 a 7
			if(i<6)
			{
				retorno=BAR_CriaCarta(carta,(50+i),10,naipe[0][j]);
			}
			//cria o J
			else if(cont>=24&&cont<28)
			{
				retorno=BAR_CriaCarta(carta,'J',10,naipe[0][j]);
			}
			//cria o Q
			else if(cont>=28&&cont<32)
			{
				retorno=BAR_CriaCarta(carta,'Q',10,naipe[0][j]);
			}
			//cria o K
			else if(cont>=32&&cont<36)
			{
				retorno=BAR_CriaCarta(carta,'K',10,naipe[0][j]);
			}
			//cria o A
			else if(cont>=36&&cont<40)
			{
				retorno=BAR_CriaCarta(carta,'A',10,naipe[0][j]);
			}
			//else retorno=BAR_CriaCarta(carta,'G',10,"generico");
			cartas[cont]=*carta;
			cont++;
		}
	}
	return retorno;
}
