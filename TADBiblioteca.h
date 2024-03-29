#ifndef TADBIBLIOTECA_H_INCLUDED
#define TADBIBLIOTECA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
typedef struct{
    TTexto* textos;
    int tamBiblioteca;
}TBiblioteca;

void inicializaBiblioteca(TBiblioteca* Biblioteca, int TamanhoTextos,int TamanhoBib);
void insereTexto(TBiblioteca* Biblioteca, TTexto* texto);
void removeTexto(TBiblioteca* Biblioteca, int pos);
void removeTextoLoop(TBiblioteca* Biblioteca);
void imprimeBiblioteca(TBiblioteca* Biblioteca);
void tamanhoBiblioteca(TBiblioteca* Biblioteca);
void ordenaTexto(TBiblioteca* Biblioteca);

int partitionbib (TTexto* texto, int low, int high, int* comp, int* mov);
void swapbib(TTexto* a, TTexto* b, int* mov);

void quickSortbib(TTexto* texto, int low, int high, int* comp, int* mov);

#endif // TTADBIBLIOTECA_H_INCLUDED
