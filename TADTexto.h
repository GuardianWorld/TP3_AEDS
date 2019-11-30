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

void mainTexto(TPalavra* palavra, TTexto* texto);
void inicializaTexto(TTexto* texto, int TextoTamanho);
void inserePalavra(TTexto* texto, TPalavra* palavra);
void removePalavra(TTexto* texto, int pos);
void removePalavraLoop(TTexto* texto);
void imprimeTexto(TTexto* texto);
void tamanhoTexto(TTexto* texto);

void ordenaPalavra(TTexto* texto);

int particao (TPalavra* arr, int low, int high);
void troca(TPalavra* a, TPalavra* b);
void quickSort(TPalavra* arr, int low, int high);

#endif // TADTEXTO_H_INCLUDED
