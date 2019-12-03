#include "TADBibliotecaEncadeada.h"

void inicializaBibliotecaEncadeada(TListaBiblioteca* listaBib)
{
    listaBib->pPrimeiro = (apontadorBib) malloc(sizeof(TBibliotecaEncadeada));
    listaBib->pPrimeiro->ProxTexto = NULL;
    listaBib->pPrimeiro->antTexto = NULL;
    listaBib->pUltimo = listaBib->pPrimeiro;
    listaBib->tamanhoBib = 0;
}
void insereTextoEncadeado(TListaBiblioteca* listaBib, int tamanhoTexto, int tamanhoPalavra)
{
    int y;
    int x;
    int trandom;
    char inputLetra;
    listaBib->pUltimo->ProxTexto = malloc(sizeof(TBibliotecaEncadeada));
    listaBib->pUltimo->ProxTexto->antTexto = listaBib->pUltimo;
    listaBib->pUltimo = listaBib->pUltimo->ProxTexto;
    listaBib->pUltimo->ProxTexto = NULL;
    inicializaTextoEncadeado(&(listaBib->pUltimo->Texto));
    //inicializaPalavraEncadeada(&listaBib->pUltimo->Texto.pUltimo->palavra);
    /*if(tamanhoTexto == 100000)
    {
        trandom = rand() % 50000;
    }
    else
    {
        trandom = rand() % tamanhoTexto;
    }*/

    for(x = 0; x < tamanhoTexto - rand() % tamanhoTexto; x++)
    {
        inserePalavraEncadeado(&listaBib->pUltimo->Texto, tamanhoPalavra);
        //imprimeTextoEncadeado(&(listaBib->pUltimo->Texto));
    }
    listaBib->tamanhoBib++;
    return;
}

void removeTextoEncadeado(TListaBiblioteca* listaBib)
{
    if(listaBib->tamanhoBib == 0)
    {
        return;
    }
    apontadorBib pAux;
    pAux = listaBib->pUltimo;
    listaBib->pUltimo = listaBib->pUltimo->antTexto;
    listaBib->pUltimo->ProxTexto = NULL;
    free(pAux);
    listaBib->tamanhoBib--;
}

void removeTextoLoopEncadeado(TListaBiblioteca* listaBib)
{
    int y = listaBib->tamanhoBib;
    if(y == 0)
    {
        return;
    }
    int x;
    for (x = 0; x < y; x++)
    {
        removeTextoEncadeado(listaBib);
    }
}

void imprimeBibliotecaEncadeado(TListaBiblioteca* listaBib)
{
    apontadorBib pAux = listaBib->pPrimeiro->ProxTexto;
    apontadorTexto pAuxT;
    apontadorLetra pAuxL;
    int y = 0;
    if(listaBib->tamanhoBib == 0)
    {
        return;
    }
    while (pAux != NULL)
    {
        y++;
        printf("Imprimindo texto %d\n", y);
        printf("\n");
        pAuxT = pAux->Texto.pPrimeiro->ProxPalavra;
        while(pAuxT != NULL)
        {
            pAuxL = pAuxT->palavra.pPrimeiro->ProxLetra;
            while (pAuxL != NULL)
            {
                printf("%c", pAuxL->letra);
                pAuxL = pAuxL->ProxLetra; /* próxima célula */
            }
            printf(" ");
            pAuxT = pAuxT->ProxPalavra;
        }
        printf("\n");
        pAux = pAux->ProxTexto;
    }
    return;
}

void tamanhoBibliotecaEncadeado(TListaBiblioteca* listaBib)
{
 printf("Tamanho da Biblioteca: %d\n", listaBib->tamanhoBib);
}

void ordenaTextoBib(TListaBiblioteca bib)
{
    int comparacao = 0, movimentacao = 0; //Comparações e movimentação
    clock_t Ticks[2];

    apontadorBib pAux, pAux2;
    apontadorBib Mini = bib.pPrimeiro;
    TListaTexto mainText, telAux;

    printf("Biblioteca Original: ");
    imprimeBibliotecaEncadeado(&bib);
    int n = bib.tamanhoBib;
    if(n <= 1)
    {
        printf("Tempo total da CPU para organizar via selecao: 0 ms\n");
        printf("Total de Comparacoes: 0, Total de Movimentacoes: 0\n");
        return;
    }
    //
    int x,y;
    Ticks[0] = clock();
    for (x = 0; x < n - 1; x++)
    {
        Mini = Mini->ProxTexto;
        mainText = Mini->Texto;
        pAux = Mini->ProxTexto;
        pAux2 = Mini;
        for (y = x + 1; y < n; y++)
        {
            comparacao++;
            if (pAux->Texto.numeroPalavras < mainText.numeroPalavras)
            {
                mainText = pAux->Texto;
                pAux2 = pAux;
            }
            pAux = pAux->ProxTexto;
        }
        movimentacao++;
        telAux = Mini->Texto;
        Mini->Texto = mainText;
        pAux2->Texto = telAux;
    }
    printf("Biblioteca Ordenada: ");
    imprimeBibliotecaEncadeado(&bib);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo total da CPU para organizar via selecao: %g ms\n", Tempo);
    printf("Total de Comparacoes: %d, Total de Movimentacoes: %d\n", comparacao, movimentacao);
    return;

}
/*
//Quicksort


void quickSortbib(TTexto* texto, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        /*int pi = partitionbib(texto, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSortbib(texto, low, pi - 1);
        quickSortbib(texto, pi + 1, high);
    }
}

int partitionbib (TTexto* texto, int low, int high)
{
    int pivot = texto[high].numeroPalavras;
    //printf("=%d=",texto[high].numeroPalavras);    // pivot
    int i = (low - 1);  // Index of smaller element
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (texto[j].numeroPalavras < pivot)
        {
            i++;    // increment index of smaller element
            swapbib(&texto[i], &texto[j]);
        }
    }
    swapbib(&texto[i + 1], &texto[high]);
    return (i + 1);
}


void swapbib(TTexto* a, TTexto* b)
{
    TTexto t = *a;
    *a = *b;
    *b = t;
}*/
