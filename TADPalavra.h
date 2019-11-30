#ifndef TADPALAVRA_H_INCLUDED
#define TADPALAVRA_H_INCLUDED
#include "string.h"
#define MAXWORD 100

typedef struct{
    char* palavra;
    int tamanho;
}TPalavra;

typedef struct{
    char* ProxLetra;
    char letra;
}TPalavraEncadeada;

typedef struct{
    char* pPrimeiro;
    char* pUltimo;
    int tamanho;
}TlistaPalavra;

void inicializaPalavra(TPalavra* palavra);
void insereLetra(TPalavra* palavra, char letra);
void removeLetra(TPalavra* palavra, char letra);
void removeLetraLoop(TPalavra* palavra);
void imprimePalavra(TPalavra palavra);
void tamanhoPalavra(TPalavra* palavra);

#endif // TADPALAVRA_H_INCLUDED
