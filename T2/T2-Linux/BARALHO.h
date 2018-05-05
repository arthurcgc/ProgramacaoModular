#include "LISTA.H"

typedef enum {

      BAR_CondRetOK ,
            /* Concluiu corretamente */

      BAR_CondRetListaVazia ,
            /* A lista n�o cont�m elementos */

      BAR_CondRetFimLista ,
            /* Foi atingido o fim de lista */

      BAR_CondRetNaoAchou ,
            /* N�o encontrou o valor procurado */

      BAR_CondRetFaltouMemoria
            /* Faltou mem�ria ao tentar criar um elemento de lista */

} BAR_tpCondRet ;


typedef struct BAR_tagCarta * BAR_tppCarta ;


BAR_tpCondRet BAR_CriaCarta(BAR_tppCarta *carta,char *nome, int peso,char *naipe);
