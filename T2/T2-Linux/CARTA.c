#include <stdio.h>
#include "CARTA.h"
#include <string.h>

CAR_tpCarta CAR_CriaCarta(char *nome, int peso,char *naipe)
{
	CAR_tpCarta *carta=(CAR_tpCarta*)malloc(sizeof(CAR_tpCarta));
	strcpy(carta->nome,nome);
	carta->peso=peso;
	strcpy(carta->naipe,naipe);
	return *carta;
}
