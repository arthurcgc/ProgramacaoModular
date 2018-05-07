/***************************************************************************
*  $MCI Módulo de implementação: TLIS Teste lista de símbolos
*
*  Arquivo gerado:              TestLIS.c
*  Letras identificadoras:      TLIS
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1		  bla   05/05/2018
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.H"
#include    "BARALHO.h"

static const char RESET_BARALHO_CMD         [ ] = "=resetteste"     ;
static const char CRIAR_BARALHO_CMD         [ ] = "=criarbaralho"   ;
static const char CRIAR_CARTA_CMD           [ ] = "=criarcarta"     ;
static const char CRIAR_VETORCARTA_CMD      [ ] = "=criarvetcarta"  ;
static const char EMBARALHAR_CMD            [ ] = "=embaralha"      ;
static const char DESTRUIR_CARTA_CMD        [ ] = "=destroicarta"   ;
static const char DESTRUIR_BARALHO_CMD      [ ] = "=destroibar"     ;


#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_CARTA   10
#define DIM_VT_BARALHO 10	
#define DIM_VALOR     100

BAR_tppCarta   vtCartas  [ DIM_VT_CARTA] ;
BAR_tppBaralho vtBaralho [ DIM_VT_BARALHO];

/***** Protótipos das funções encapuladas no módulo *****/

   static void DestruirValor( void * pValor ) ;
   static int ValidarInxBaralho( int inxBaralho , int Modo ) ;
   static int ValidarInxcarta( int inxCarta , int Modo ) ;

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TBAR &Testar Baralho
*
*  $ED Descrição da função
*     Criar 1 baralho embaralhado
*
*     Comandos disponíveis:
*
*     =resetteste
*           - anula o vetor de Baralho. Provoca vazamento de memória
*     =criarbaralho                 inxBaralho	CondRetEsp
*     =criarcarta                   inxCarta    nome	peso	naipe	CondRetEsp
*	  =destroicarta                 inxCarta    CondRetEsp
*	  =criarvetcarta                inxCarta    CondRetEsp
*     =embaralha                    inxBaralho  CondRetEsp
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int inxBaralho = -1 ,
		  inxCarta   = -1 , 
          numLidos   = -1 ,
          CondRetEsp = -1 ;

      TST_tpCondRet CondRet ;

      char   StringDado[  DIM_VALOR ] ;
      char * pDado ;

      int ValEsp = -1 ;

      int i ;

      int numElem = -1 ;

      StringDado[ 0 ] = 0 ;

      /* Efetuar reset de teste de Baralho */

         if ( strcmp( ComandoTeste , RESET_BARALHO_CMD ) == 0 )
         {

            for( i = 0 ; i < DIM_VT_BARALHO ; i++ )
            {
               vtbaralho[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de Baralho */

      /* Testar CriarLista */

         else if ( strcmp( ComandoTeste , CRIAR_BARALHO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                       &inxBaralho, &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxBaralho( inxBaralho , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet = BAR_CriarBaralho(&vtBaralho[ inxBaralho ]) ;

            return TST_CompararInt( CondRetEsp , CondRet ,
               "Erro ao criar baralho."  ) ;

         } /* fim ativa: Testar CriarBaralho */

      /* Testar Criar Carta */

         else if ( strcmp( ComandoTeste , CRIAR_CARTA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iiii" , &inxCarta, &nome, &peso, &naipe, &CondRetEsp ) ;

            if ( ( numLidos != 4 )
              || ( ! ValidarInxCarta( inxCarta , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

           CondRet= BAR_CriaCarta(&vtCartas[ inxCarta ],nome, peso, naipe);

		   return TST_CompararInt( CondRetEsp , CondRet ,
                     "Erro ao criar carta." );

         } /* fim ativa: Testar CriarVetCarta */
		 
		 /* Testar Destroi Carta */

		 else if ( strcmp( ComandoTeste , DESTRUIR_CARTA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" , &inxCarta, &CondRetEsp ) ;

            if ( ( numLidos != 1 )
              || ( ! ValidarInxCarta( inxCarta , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            DestruirValor(&vtCartas[ inxCarta ]) ;
            vtCartas[ inxCarta ] = NULL ;

            return  TST_CompararInt( CondRetEsp , CondRet ,
                     "Erro ao destruir carta." );

         } /* fim ativa: Testar Destruir carta */

		 /* Testar Destroi Baralho */

		 else if ( strcmp( ComandoTeste , DESTRUIR_BARALHO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" , &inxBaralho, &CondRetEsp ) ;

            if ( ( numLidos != 1 )
              || ( ! ValidarInxBaralho( inxBaralho , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            BAR_DestruirBaralho(&vtBaralho[ inxBaralho ]) ;
            vtBaralho[ inxBaralho ] = NULL ;

            return  TST_CompararInt( CondRetEsp , CondRet ,
                     "Erro ao destruir baralho." );

         } /* fim ativa: Testar Destruir baralho */

		else if ( strcmp( ComandoTeste , CRIAR_VETCARTA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                       &inxCarta, &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxBaralho( inxCarta , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet = BAR_CriaVetorCartas(&vtCartas[ inxCarta ]) ;

            return TST_CompararInt( CondRetEsp , CondRet ,
               "Erro ao criar vetor de carta."  ) ;

         } /* fim ativa: Testar Embaralhamento */

		 else if ( strcmp( ComandoTeste , EMBARALHAR_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                       &inxBaralho, &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxBaralho( inxCarta , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet = BAR_Embaralhar( &vtBaralho[ inxBaralho ] )

            return TST_CompararInt( CondRetEsp , CondRet ,
               "Erro ao embaralhar."  ) ;

         } /* fim ativa: Testar Embaralhamento */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TLIS -Destruir valor
*
***********************************************************************/

   void DestruirValor( void * pValor )
   {

      free( pValor ) ;

   } /* Fim função: TLIS -Destruir valor */



/***********************************************************************
*
*  $FC Função: TBAR -Validar indice do baralho
*
***********************************************************************/

   int ValidarInxBaralho( int inxBaralho , int Modo )
   {

      if ( ( inxBaralho <  0 )
        || ( inxBaralho >= DIM_VT_BARALHO ))
      {
         return FALSE ;
      } /* if */
      
      if ( Modo == VAZIO )
      {
         if ( vtBaralhos[ inxBaralho ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtBaralhos[ inxBaralho ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim função: TEMB -Validar indice do baralho */

/***********************************************************************
*
*  $FC Função: TCAR -Validar indice da carta
*
***********************************************************************/

   int ValidarInxCarta( int inxCarta , int Modo )
   {

      if ( ( inxCarta <  0 )
        || ( inxCarta >= DIM_VT_CARTA ))
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vtCartas[ inxCarta ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtCartas[ inxCarta ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim Função: TCAR -Validar indice de carta */



/********** Fim do módulo de implementação: TLIS Teste lista de símbolos **********/

