#include "TADBibliotecaEncadeada.h"
void inicializaBibliotecaEncadeada(TListaBiblioteca* listaBib)
{
    listaBib->pPrimeiro = malloc(sizeof(TBibliotecaEncadeada));
    listaBib->pUltimo = listaBib->pPrimeiro;
    listaBib->pPrimeiro->ProxTexto = NULL;
    listaBib->tamanhoBib = 0;
    return;
}

void insereTextoEncadeado(TListaBiblioteca* listaBib, int tamanhoTexto, int tamanhoPalavra)
{
    int y;
    int x;
    int trandom;
    char inputLetra;
    listaBib->pUltimo->ProxTexto = (apontadorBib) malloc(sizeof(TBibliotecaEncadeada));
    listaBib->pUltimo = listaBib->pUltimo->ProxTexto;
    listaBib->pUltimo->ProxTexto = NULL;
    inicializaTextoEncadeado(&listaBib->pUltimo->Texto);
    //inicializaPalavraEncadeada(&listaBib->pUltimo->Texto.pUltimo->palavra);
    if(tamanhoTexto == 100000)
    {
        trandom = tamanhoTexto - rand() % 50001;
    }
    else
    {
        trandom = tamanhoTexto - rand() % tamanhoTexto;
    }

    for(x = 0; x < trandom; x++)
    {
        inserePalavraEncadeado(&listaBib->pUltimo->Texto, tamanhoPalavra);
    }
    listaBib->tamanhoBib++;
    return;
}

void removeTextoEncadeado(TListaBiblioteca* listaBib)
{
    apontadorBib pAux;
    struct listaTXT* pAuxTexto;
    int x;
    if (listaBib->tamanhoBib == 0)
    {
         return;
    }
    pAux = listaBib->pPrimeiro;
    listaBib->pPrimeiro = listaBib->pPrimeiro->ProxTexto;
    removePalavraLoopEncadeado(&listaBib->pPrimeiro->Texto);
    free(pAux);
    //printf("%d\n", listaTextos->numeroPalavras);
    listaBib->tamanhoBib--;
    return;

}

void removeTextoLoopEncadeado(TListaBiblioteca* listaBib)
{
    int x = listaBib->tamanhoBib;
    int y;
    for(y = 0; y < x; y++)
    {
        removeTextoEncadeado(listaBib);
    }
    return;
}

void imprimeBibliotecaEncadeado(TListaBiblioteca* listaBib)
{
    apontadorBib pAuxBib;
    struct listaTXT* pAuxTexto;

    int y = 1;
    if(listaBib->tamanhoBib == 0)
    {
        return;
    }

    pAuxBib = listaBib->pPrimeiro->ProxTexto;
    pAuxTexto = &pAuxBib->Texto;
    while(pAuxBib != NULL)
    {
        printf("Imprimindo texto %d\n", y);
        imprimeTextoEncadeado(pAuxTexto);
        pAuxBib = pAuxBib->ProxTexto;
        pAuxTexto = &pAuxBib->Texto;
        y++;
        printf("\n");
        /*if(pAux->palavra.ProxLetra->ProxLetra != NULL)
        {
            pAuxLetra = pAux->palavra.ProxLetra->ProxLetra;
        }
        while (pAuxLetra != NULL)
        {
            printf("%c", pAuxLetra->letra);
            pAuxLetra = pAuxLetra->ProxLetra;
        }
        printf(" ");
        pAux = pAux->ProxPalavra;*/
    }
    printf("\n");
    return;
}

void tamanhoBibliotecaEncadeado(TListaBiblioteca* listaBib)
{
    printf("Tamanho da Biblioteca: %d\n", listaBib->tamanhoBib);
}

/*
void ordenaTexto(TBiblioteca* Biblioteca){

    int i, j, min_idx;
    TTexto temp;
    int n = Biblioteca->tamBiblioteca;
    //int ver1,ver2

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++){
            //ver1 = arrj[j];
            //ver2 = arr[min_idx];
          if (Biblioteca->textos[j].numeroPalavras < Biblioteca->textos[min_idx].numeroPalavras){
            min_idx = j;
          }
        }

        temp = Biblioteca->textos[min_idx];
        Biblioteca->textos[min_idx] = Biblioteca->textos[i];
        Biblioteca->textos[i] = temp;
    }
}

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
