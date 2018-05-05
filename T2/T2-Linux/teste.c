#include <stdio.h>
#include <stdlib.h>
#include "BARALHO.h"
#include "LISTA.H"

int main()
{
	BAR_tppCarta *carta=(BAR_tppCarta*)malloc(sizeof(BAR_tppCarta));
  if(BAR_CriaCarta(carta,"A",10,"ouros")==BAR_CondRetOK)
	{
	printf("sucesso!\n");
	}
	return 0;
}
