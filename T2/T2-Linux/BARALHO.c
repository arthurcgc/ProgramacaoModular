/***************************************************************************
*  $MCI M�dulo de implementa��o: BAR  BARALHO
*
*  Arquivo gerado:              BARALHO.c
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 / Truco
*  Gestor:  DI/PUC-Rio
*  Autores: Arthur Cavalcante Gomes Coelho(art)
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       art   30/04/2018 in�cio desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>
#include "BARALHO.h"
#include "LISTA.H"


#define BARALHO_OWN
	#include "BARALHO.h"
#undef BARALHO_OWN

#define	TRUCO 40


/***********************************************************************
*
*  $TC Tipo de dados: BAR Carta
*
*
***********************************************************************/

typedef struct BAR_tagCarta
{
	char nome;
	int peso;
	char naipe[20];
}	BAR_tpCarta;


/***********************************************************************
*
*  $TC Tipo de dados: BAR Baralho
*
*
***********************************************************************/

typedef struct BAR_tagBaralho
{
	LIS_tppLista Cartas;
}	BAR_tpBaralho;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/
BAR_tpCondRet DestruirValor(void * pValor);

/***********************************************************************
*
*  $FC Fun��o: BAR  -Destruir elemento
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados pelo ponteiro passado
*
***********************************************************************/
BAR_tpCondRet DestruirValor(void * pValor)
	{
		free(pValor);
		return BAR_CondRetOK;
	}
/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: BAR  &Criar carta
*  ****/
BAR_tpCondRet BAR_CriaCarta(BAR_tppCarta *pCarta,char nome, int peso,char *naipe)
{
	BAR_tpCarta *aux_carta;
	aux_carta=(BAR_tpCarta*)malloc(sizeof(BAR_tpCarta));
	if(aux_carta==NULL) 
	{
		return BAR_CondRetFaltouMemoria;
	}
	aux_carta->nome=nome;
	strcpy(aux_carta->naipe,naipe);
	aux_carta->peso=peso;
	*pCarta=aux_carta;
	if(*pCarta==NULL)
	{
		return  BAR_CondRetCartaNaoCriada;
	}
	return BAR_CondRetOK;
}/* Fim fun��o: BAR  &Criar carta */

/***************************************************************************
*
*  $FC Fun��o: BAR  &Criar Baralho
*  ****/
BAR_tpCondRet BAR_CriarBaralho(BAR_tppBaralho *pBaralho)
{
	int i;
	int *p=(int*)malloc(sizeof(int));
	BAR_tppCarta vetor_cartas[40];
	BAR_tpCondRet retorno;
	//ponteiro para baralho
	*pBaralho = (BAR_tpBaralho*)malloc(sizeof(BAR_tpBaralho));
	//cria as 40 cartas e armazena em um vetor
	retorno=BAR_CriaVetorCartas(vetor_cartas);
	if ( *pBaralho == NULL )
      {
         return  BAR_CondRetFaltouMemoria ;
      }
	(*pBaralho)->Cartas = LIS_CriarLista(DestruirValor);
	if((*pBaralho)->Cartas==NULL)
	{
		return BAR_CondRetFaltouMemoria;
	}
	for(i=0;i<TRUCO;i++)
	{
		*p=i;
		//insere a carta na lista
		LIS_InserirElementoApos((*pBaralho)->Cartas,vetor_cartas[i]);
	}
	return BAR_CondRetOK;
}/* Fim fun��o: BAR  &Criar baralho */


/***************************************************************************
*
*  $FC Fun��o: BAR  &Cria vetor cartas
*  ****/
BAR_tpCondRet BAR_CriaVetorCartas(BAR_tppCarta cartas[])
{
	BAR_tpCondRet retorno;
	char *naipe[10][4];
	BAR_tppCarta *carta=(BAR_tppCarta*)malloc(sizeof(BAR_tppCarta));
	int i,j,cont;
	naipe[0][0]="ouros";naipe[0][1]="copas";
	naipe[0][2]="paus";naipe[0][3]="espadas";

	if(*carta==NULL)
	{
		return BAR_CondRetFaltouMemoria;
	}
	cont=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<4;j++)
		{
			//cria cartas de 2 a 7
			if(i<6)
			{
				retorno=BAR_CriaCarta(carta,(50+i),0,naipe[0][j]);
			}
			//cria o J
			else if(cont>=24&&cont<28)
			{
				retorno=BAR_CriaCarta(carta,'J',0,naipe[0][j]);
			}
			//cria o Q
			else if(cont>=28&&cont<32)
			{
				retorno=BAR_CriaCarta(carta,'Q',0,naipe[0][j]);
			}
			//cria o K
			else if(cont>=32&&cont<36)
			{
				retorno=BAR_CriaCarta(carta,'K',0,naipe[0][j]);
			}
			//cria o A
			else if(cont>=36&&cont<40)
			{
				retorno=BAR_CriaCarta(carta,'A',0,naipe[0][j]);
			}
			//else retorno=BAR_CriaCarta(carta,'G',10,"generico");
			cartas[cont]=*carta;
			cont++;
		}
	}
	return retorno;
}/* Fim fun��o: BAR  &Cria vetor cartas */

/********** Fim do m�dulo de implementa��o: BAR  BARALHO **********/
