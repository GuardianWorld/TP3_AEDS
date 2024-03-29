#ifndef TADTEXTOE_H_INCLUDED
#define TADTEXTOE_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAXTEXTO 50000
#include "TADPalavraEncadeada.h"
typedef struct TextoEncadeado* apontadorTexto;
typedef struct TextoEncadeado{
    struct TextoEncadeado* ProxPalavra;
    struct TextoEncadeado* AntPalavra;
    TlistaPalavra palavra;
}TTextoEncadeada;

typedef struct listaTXT{
    struct TextoEncadeado* pPrimeiro;
    struct TextoEncadeado* pUltimo;
    int numeroPalavras;
}TListaTexto;

void inicializaTextoEncadeado(TListaTexto* listaTextos);
void inserePalavraEncadeado(TListaTexto* listaTextos, int tamanhoPalavra);
void removePalavraEncadeado(TListaTexto* listaTextos);
void removePalavraLoopEncadeado(TListaTexto* listaTextos);
void imprimeTextoEncadeado(TListaTexto* listaTextos);
void tamanhoTextoEncadeado(TListaTexto* listaTextos);

void ordenaPalavraEncadeada(TListaTexto texto);



#endif // TADTEXTOE_H_INCLUDED
