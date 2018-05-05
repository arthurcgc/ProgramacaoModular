#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BARALHO.h"
#include "LISTA.H"


#define	TRUCO 40

/*void DestruirValor(void * pValor)
	{
		free(pValor);
	}
*/
LIS_tppLista   baralho;

typedef struct BAR_tagCarta
{
	char nome[20];
	int peso;
	char naipe[20];
}	BAR_tpCarta;



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


/*LIS_tppLista BAR_CriarBaralho()
{
	int pDado=1;
	int aux;
	baralho=LIS_CriarLista(DestruirValor);
	for(int i=0;i<TRUCO;i++)
	{
			aux=LIS_InserirElementoApos(baralho,pDado);
	}
*/

 //Fim função: BAR -Destruir baralho
/*
static void BAR_CriaCartas2a7(LIS_tppLista *baralho)
{
	CAR_tpCarta *carta;
			for(int j=2;j<8;j++)
		{
			for(k=0;k<4;k++)		//cria cartas de 2 a 7
			{
				carta=CAR_CriaCarta(2_a_7,2,naipe);
				LIS_InserirElementoApos(baralho,carta);
				if(k==1) naipe="paus";
				if(k==2) naipe="espadas";
				if(k==3) naipe="copas";
			}
			2_a_7++;
		}
}
*/
