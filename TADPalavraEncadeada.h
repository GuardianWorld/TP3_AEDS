#ifndef TADPALAVRAE_H_INCLUDED
#define TADPALAVRAE_H_INCLUDED
#include "string.h"
#include <stdlib.h>
#define MAXWORD 100
typedef struct PalavraEncadeada* apontadorLetra;
typedef struct PalavraEncadeada{
    struct PalavraEncadeada* ProxLetra;
    char letra;
}TPalavraEncadeada;

typedef struct{
    struct PalavraEncadeada* pPrimeiro;
    struct PalavraEncadeada* pUltimo;
    int tamanho;
}TlistaPalavra;

void inicializaPalavraEncadeada(TlistaPalavra* palavra);
void insereLetraEncadeada(TlistaPalavra* palavra, char letra);
void removeLetraEncadeada(TlistaPalavra* listaLetras);
void removeLetraLoopEncadeada(TlistaPalavra* palavra);
void imprimePalavraEncadeada(TlistaPalavra* palavra);
void tamanhoPalavraEncadeada(TlistaPalavra* palavra);

#endif // TADPALAVRA_H_INCLUDED
