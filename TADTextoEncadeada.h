#ifndef TADTEXTOE_H_INCLUDED
#define TADTEXTOE_H_INCLUDED
#include "TADPalavra.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXTEXTO 50000
#include "TADPalavraEncadeada.h"
typedef struct TextoEncadeado* apontadorTexto;
typedef struct TextoEncadeado{
    struct TextoEncadeado* ProxPalavra;
    TPalavraEncadeada palavra;
}TTextoEncadeada;

typedef struct{
    struct TextoEncadeado* pPrimeiro;
    struct TextoEncadeado* pUltimo;
    int numeroPalavras;
}TListaTexto;

void inicializaTextoEncadeado(TListaTexto* listaTextos);
void inserePalavraEncadeado(TListaTexto* listaTextos, TlistaPalavra* palavra, int tamanhoPalavra);
void removePalavraEncadeado(TListaTexto* listaTextos);
void removePalavraLoopEncadeado(TListaTexto* listaTextos);
void imprimeTextoEncadeado(TListaTexto* listaTextos);
void tamanhoTextoEncadeado(TListaTexto* listaTextos);

//void ordenaPalavraEncadeado(TListaTexto* texto);

//int particaoEncadeado (TPalavraEncadeada* arr, int low, int high);
//void trocaEncadeado(TPalavraEncadeada* a, TPalavra* b);
//void quickSortEncadeado (TPalavraEncadeada* arr, int low, int high);

#endif // TADTEXTOE_H_INCLUDED
