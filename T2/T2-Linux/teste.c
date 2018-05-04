#include <stdio.h>
#include "CARTA.h"

int main()
{
	CAR_tpCarta *carta=(CAR_tpCarta*)malloc(sizeof(CAR_tpCarta));
	*carta=CAR_CriaCarta("A",10,"ouros");
	printf("nome da carta: %s\npeso: %d\nnaipe: %s\n",carta->nome,carta->peso,carta->naipe);
	return 0;
}
