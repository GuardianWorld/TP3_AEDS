#ifndef TADBIBLIOTECAE_H_INCLUDED
#define TADBIBLIOTECAE_H_INCLUDED
#include "TADTextoEncadeada.h"
#include "TADPalavraEncadeada.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct BibEncadeado* apontadorBib;
typedef struct BibEncadeado{
    struct BibEncadeado* ProxTexto;
    struct BibEncadeado* antTexto;
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

void ordenaTextoBib(TListaBiblioteca bib);

void Quicksort(int Inicio, int Fim, TListaBiblioteca* Bib, int* comp, int* mov);
void ParticaoQSBib(TListaBiblioteca* bib, int Inicio, int Fim,int* x, int* y, int* comp, int* mov);

#endif // TTADBIBLIOTECAE_H_INCLUDED
