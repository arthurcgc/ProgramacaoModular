#include <malloc.h>


typedef struct CAR_tagCarta
{
	char nome[20];
	int peso;
	char naipe[20];
}	CAR_tpCarta;

CAR_tpCarta CAR_CriaCarta(char *nome, int peso,char *naipe);

