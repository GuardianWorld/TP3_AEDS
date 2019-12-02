#ifndef TADBIBLIOTECAE_H_INCLUDED
#define TADBIBLIOTECAE_H_INCLUDED
#include "TADTextoEncadeada.h"
#include "TADPalavraEncadeada.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct BibEncadeado* apontadorBib;
typedef struct BibEncadeado{
    struct BibEncadeado* ProxTexto;
    TListaTexto Texto;
}TBibliotecaEncadeada;

typedef struct{
    struct BibEncadeado* pPrimeiro;
    struct BibEncadeado* pUltimo;
    int tamanhoBib;
}TListaBiblioteca;

void inicializaBibliotecaEncadeada(TListaBiblioteca* listaBib);
void insereTextoEncadeado(TListaBiblioteca* listaBib, int tamanhoTexto, int tamanhoPalavra);
void removeTextoEncadeado(TListaBiblioteca* listaBib);
void removeTextoLoopEncadeado(TListaBiblioteca* listaBib);
void imprimeBibliotecaEncadeado(TListaBiblioteca* listaBib);
void tamanhoBibliotecaEncadeado(TListaBiblioteca* listaBib);
/*void ordenaTexto(TBiblioteca* Biblioteca);

int partitionbib (TTexto* arr, int low, int high);
void swapbib(TTexto* a, TTexto* b);

void quickSortbib(TTexto* arr, int low, int high);
*/
#endif // TTADBIBLIOTECAE_H_INCLUDED
