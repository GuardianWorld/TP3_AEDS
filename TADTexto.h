#ifndef TADTEXTO_H_INCLUDED
#define TADTEXTO_H_INCLUDED
#include "TADPalavra.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXTEXTO 50000

typedef struct{
    int numeroPalavras;
    TPalavra* palavras;
}TTexto;

typedef struct{
    char* ProxPalavra;
    TPalavra palavra;
}TTextoEncadeada;

typedef struct{
    char* pPrimeiro;
    char* pUltimo;
    int numeroPalavras;
}TListaTexto;

void inicializaTexto(TTexto* texto, int TextoTamanho);
void inserePalavra(TTexto* texto, TPalavra* palavra);
void removePalavra(TTexto* texto, int pos);
void removePalavraLoop(TTexto* texto);
void imprimeTexto(TTexto* texto);
void tamanhoTexto(TTexto* texto);
void ordenaPalavra(TTexto* texto);

#endif // TADTEXTO_H_INCLUDED
