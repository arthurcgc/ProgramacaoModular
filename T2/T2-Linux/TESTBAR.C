
#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include "GENERICO.H"
#include "LERPARM.H"
#include "BARALHO.h"
#include "TST_ESPC.H"

/* Nomes dos comandos de teste espec�ficos */
#define CRIAR_BAR_CMD "=criarbaralho"
#define CRIAR_CAR_CMD "=criarcarta"
#define CRIA_VEC_CMD "=criavetor"
#define EMBARALHA_CMD "=embaralhar"
#define DESTRUIR_BAR_CMD "=destruirbaralho"
#define DESTROI_CAR_CMD "=destruircarta"



static	  BAR_tppCarta pCarta = NULL; // ponteiro para uma carta
static    BAR_tppBaralho pBaralho= NULL; //ponteiro para baralho
/*****************************************************************
******
*
* $FC Fun��o: Efetuar opera��es de teste espec�ficas para baralho
*
* $EP Par�metros
* $P ComandoTeste - String contendo o comando
*
******************************************************************
*****/
TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
    BAR_tpCondRet CondRetObtido;
    BAR_tpCondRet CondRetEsperada = BAR_CondRetOK;
    //BAR_tppCarta pCarta = NULL; // ponteiro para uma carta
	BAR_tppCarta *vec_cartas=NULL;	// vetor de cartas
	//BAR_tppBaralho pBaralho= NULL; //ponteiro para baralho
    char nome_carta;
    int peso_carta;
    char naipe_carta[20];
    int NumLidos   = -1 ,
        CondRetEsp = -1  ;
    TST_tpCondRet Ret ;

	/* Testar BAR Criar carta */

    if( strcmp( ComandoTeste , CRIAR_CAR_CMD ) == 0 )
    {

      NumLidos = LER_LerParametros("cisi",&nome_carta,&peso_carta,&naipe_carta,&CondRetEsperada);

		if ( NumLidos != 4 )
		{
			return TST_CondRetParm ;
		} /* if */

    CondRetObtido = BAR_CriaCarta(&pCarta,nome_carta,peso_carta,naipe_carta);

    return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                            "Retorno errado ao criar carta." );
	}/* fim ativa: Testar BAR Criar carta */


	/* Testar BAR Destruir carta 
	else if( strcmp( ComandoTeste , DESTROI_CAR_CMD ) == 0)
	{
		 NumLidos = LER_LerParametros("cisi",&nome_carta,&peso_carta,&naipe_carta,&CondRetEsperada);

		if ( NumLidos != 4 )
		{
			return TST_CondRetParm ;
		} /* if 

	CondRetObtido = DestruirCarta(pCarta);

	return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                            "Retorno errado ao destruir carta." );

	}/* fim ativa: Testar BAR Destruir carta 

	
	/* Testar BAR Cria vetor de cartas */

	else if( strcmp( ComandoTeste , CRIA_VEC_CMD ) == 0 )
	{
		NumLidos = LER_LerParametros("i",&CondRetEsperada);
		
		if ( NumLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = BAR_CriaVetorCartas(&vec_cartas);

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                            "Retorno errado ao construir vetor de cartas." );
	}/* fim ativa: Testar BAR Cria vetor cartas */


	/* Testar BAR Criar baralho */

	else if( strcmp( ComandoTeste , CRIAR_BAR_CMD ) == 0 )
	{
		NumLidos = LER_LerParametros("i",&CondRetEsperada);
		
		if ( NumLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = BAR_CriarBaralho(&pBaralho);

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                            "Retorno errado ao construir baralho." );
	}/* fim ativa: Testar BAR Criar baralho */


	/* Testar BAR Destruir baralho */
	else if( strcmp( ComandoTeste , DESTRUIR_BAR_CMD ) == 0 )
	{
		NumLidos = LER_LerParametros("i",&CondRetEsperada);

		if ( NumLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		//CondRetObtido = BAR_CriarBaralho(&pBaralho);

		CondRetObtido = BAR_DestruirBaralho(pBaralho);

		return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                            "Retorno errado ao destruir baralho." );

	}/* fim ativa: Testar BAR Destruir baralho */


	/* Testar BAR Embaralhar */

	else if( strcmp( ComandoTeste , EMBARALHA_CMD ) == 0 )
	{

	}

}


