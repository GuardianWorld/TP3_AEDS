#ifndef TADTEXTO_H_INCLUDED
#define TADTEXTO_H_INCLUDED
#include "TADPalavra.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXTEXTO 50000

typedef struct TextoEncadeado* apontadorTexto;
typedef struct TextoEncadeado{
    apontadorTexto* ProxPalavra;
    TPalavraEncadeada palavra;
}TTextoEncadeada;

typedef struct{
    apontadorTexto* pPrimeiro;
    apontadorTexto* pUltimo;
    int numeroPalavras;
}TListaTexto;

void inicializaTextoEncadeado(TTextoEncadeada* texto, int TextoTamanho);
void inserePalavraEncadeado(TTextoEncadeada* texto, TPalavra* palavra);
void removePalavraEncadeado(TTextoEncadeada* texto, int pos);
void removePalavraLoopEncadeado(TTextoEncadeada* texto);
void imprimeTextoEncadeado(TTextoEncadeada* texto);
void tamanhoTextoEncadeado(TTextoEncadeada* texto);

void ordenaPalavraEncadeado(TTextoEncadeada* texto);

int particaoEncadeado (TPalavraEncadeada* arr, int low, int high);
void trocaEncadeado(TPalavraEncadeada* a, TPalavra* b);
void quickSortEncadeado (TPalavraEncadeada* arr, int low, int high);

#endif // TADTEXTO_H_INCLUDED
