#ifndef TADBIBLIOTECA_H_INCLUDED
#define TADBIBLIOTECA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
typedef struct{
    TTexto* textos;
    int tamBiblioteca;
}TBiblioteca;

typedef struct{
    char* ProxPalavra;
    TPalavra palavra;
}TBibliotecaEncadeada;

typedef struct{
    char* pPrimeiro;
    char* pUltimo;
    int numeroPalavras;
}TListaBiblioteca;

void inicializaBiblioteca(TBiblioteca* Biblioteca, int TamanhoTextos,int TamanhoBib);
void insereTexto(TBiblioteca* Biblioteca, TTexto* texto);
void removeTexto(TBiblioteca* Biblioteca, int pos);
void removeTextoLoop(TBiblioteca* Biblioteca);
void imprimeBiblioteca(TBiblioteca* Biblioteca);
void tamanhoBiblioteca(TBiblioteca* Biblioteca);
void ordenaTexto(TBiblioteca* Biblioteca);

int partitionbib (TTexto* arr, int low, int high);
void swapbib(TTexto* a, TTexto* b);

void quickSortbib(TTexto* arr, int low, int high);

#endif // TTADBIBLIOTECA_H_INCLUDED
