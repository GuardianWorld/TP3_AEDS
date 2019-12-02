#include "TADTextoEncadeada.h"
#include "TADPalavraEncadeada.h"
void inicializaTextoEncadeado(TListaTexto* listaTextos)
{
    listaTextos->pPrimeiro = malloc(sizeof(TPalavraEncadeada));
    listaTextos->pUltimo = listaTextos->pPrimeiro;
    listaTextos->pPrimeiro->ProxPalavra = NULL;
    listaTextos->numeroPalavras = 0;
    return;
}

void inserePalavraEncadeado(TListaTexto* listaTextos, int tamanhoPalavra)
{
    int y;
    char inputLetra;
    listaTextos->pUltimo->ProxPalavra = (apontadorTexto) malloc(sizeof(TTextoEncadeada));
    listaTextos->pUltimo = listaTextos->pUltimo->ProxPalavra;
    listaTextos->pUltimo->ProxPalavra = NULL;
    inicializaPalavraEncadeada(&listaTextos->pUltimo->palavra);
    for(y = 0; y < tamanhoPalavra - rand() % tamanhoPalavra; y++)
    {
        inputLetra = (rand() % 26) + 65;
        insereLetraEncadeada(&listaTextos->pUltimo->palavra, inputLetra);
    }
    listaTextos->numeroPalavras++;
    return;
}

void removePalavraEncadeado(TListaTexto* listaTextos)
{
    apontadorTexto pAuxTexto;
    apontadorLetra pAuxLetra;
    int x;
    if (listaTextos->numeroPalavras == 0)
    {
         return;
    }
    pAuxTexto = listaTextos->pPrimeiro;
    listaTextos->pPrimeiro = listaTextos->pPrimeiro->ProxPalavra;
    removeLetraLoopEncadeada(&listaTextos->pPrimeiro->palavra);
    free(pAuxTexto);
    //printf("%d\n", listaTextos->numeroPalavras);
    listaTextos->numeroPalavras--;
    return;
}

void removePalavraLoopEncadeado(TListaTexto* listaTextos)
{
    int x = listaTextos->numeroPalavras;
    int y;
    for(y = 0; y < x; y++)
    {
        removePalavraEncadeado(listaTextos);
    }
    return;
}

void imprimeTextoEncadeado(TListaTexto* listaTextos)
{
    apontadorTexto pAux;
    apontadorLetra pAuxLetra;

    if(listaTextos->numeroPalavras == 0)
    {
        return;
    }

    pAux = listaTextos->pPrimeiro->ProxPalavra;
    pAuxLetra = pAux->palavra.ProxLetra;
    while(pAux != NULL)
    {
        if(pAux->palavra.ProxLetra->ProxLetra != NULL)
        {
            pAuxLetra = pAux->palavra.ProxLetra->ProxLetra;
        }
        while (pAuxLetra != NULL)
        {
            printf("%c", pAuxLetra->letra);
            pAuxLetra = pAuxLetra->ProxLetra;
        }
        printf(" ");
        pAux = pAux->ProxPalavra;
    }
    printf("\n");
    return;
}

void tamanhoTextoEncadeado(TListaTexto* listaTextos)
{
    printf("Tamanho: %d\n", listaTextos->numeroPalavras);
    return;
}


void ordenaPalavraEncadeada(TListaTexto* texto)
{
    //
    int comparacao = 0, movimentacao = 0; //Comparações e movimentação
    clock_t Ticks[2];
    Ticks[0] = clock();
    Ticks[1] = clock();
    //
    int i, j, min_idx;
    apontadorTexto temp;
    int n = texto->numeroPalavras;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++){
            //ver1 = arrj[j];
            //ver2 = arr[min_idx];
          if (texto->palavras[j].letras[0] < texto->palavras[min_idx].letras[0]){
            min_idx = j;
            comparacao++;
          }
        }
        temp = texto->palavras[min_idx];
        texto->palavras[min_idx] = texto->palavras[i];
        texto->palavras[i] = temp;
        movimentacao += 2;
    }
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo total da CPU para organizar via selecao: %g ms\n", Tempo);
    printf("Total de Comparacoes: %d, Total de Movimentacoes: %d\n", comparacao, movimentacao);
    return;
}

//Quicksort Texto
/*
void quickSort(TPalavra* palavra, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, palavra[p] is now
           at right place */
        /*int pi = particao(palavra, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(palavra, low, pi - 1);
        quickSort(palavra, pi + 1, high);
    }
}

int particao (TPalavra* palavra, int low, int high)
{
    int pivot = palavra[high].letras[0];    // pivot
    int i = (low - 1);  // Index of smaller element
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (palavra[j].letras[0] < pivot)
        {
            i++;    // increment index of smaller element
            troca(&palavra[i], &palavra[j]);
        }
    }
    troca(&palavra[i + 1], &palavra[high]);
    return (i + 1);
}


void troca(TPalavra* a, TPalavra* b)
{
    TPalavra t = *a;
    *a = *b;
    *b = t;
}
*/

