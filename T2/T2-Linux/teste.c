#include <stdio.h>
#include <stdlib.h>
#include "BARALHO.h"
#include "LISTA.H"

int main()
{
	int retorno;
	BAR_tppBaralho *Baralho=(BAR_tppBaralho*)malloc(sizeof(BAR_tppBaralho));
	BAR_tppCarta *carta=(BAR_tppCarta*)malloc(sizeof(BAR_tppCarta));
	if(BAR_CriaCarta(carta,"A",10,"ouros")==BAR_CondRetOK)
	{
	printf("sucesso em criar uma carta!\n");
	}
	retorno=BAR_CriarBaralho(Baralho);
	return 0;
}
