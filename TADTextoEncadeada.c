#include "TADTextoEncadeada.h"
#include "TADPalavraEncadeada.h"
void inicializaTextoEncadeado(TListaTexto* listaTextos)
{
    listaTextos->pPrimeiro = malloc(sizeof(TPalavraEncadeada));
    inicializaPalavraEncadeada(&listaTextos->pPrimeiro->palavra);
    listaTextos->pUltimo = listaTextos->pPrimeiro;
    listaTextos->pPrimeiro->ProxPalavra = NULL;
    listaTextos->pPrimeiro->AntPalavra = NULL;
    listaTextos->numeroPalavras = 0;
    return;
}

void inserePalavraEncadeado(TListaTexto* listaTextos, int tamanhoPalavra)
{
    int y;
    char inputLetra;
    listaTextos->pUltimo->ProxPalavra = (apontadorTexto) malloc(sizeof(TTextoEncadeada));
    listaTextos->pUltimo->ProxPalavra->AntPalavra = listaTextos->pUltimo;
    listaTextos->pUltimo = listaTextos->pUltimo->ProxPalavra;
    listaTextos->pUltimo->ProxPalavra = NULL;
    inicializaPalavraEncadeada(&(listaTextos->pUltimo->palavra));
    for(y = 0; y < tamanhoPalavra - rand() % tamanhoPalavra; y++)
    {
        inputLetra = (rand() % 26) + 65;
        //printf("%c ", inputLetra);
        insereLetraEncadeada(&listaTextos->pUltimo->palavra, inputLetra);
        //printf("\n");
    }
    listaTextos->pPrimeiro->AntPalavra = NULL;
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
    apontadorLetra pAuxL;

    if(listaTextos->numeroPalavras == 0)
    {
        return;
    }
    pAux = listaTextos->pPrimeiro->ProxPalavra;
    while(pAux != NULL)
    {
        //imprimePalavraEncadeada(&pAux->palavra);
        pAuxL = pAux->palavra.pPrimeiro->ProxLetra;
        while (pAuxL != NULL)
        {
            printf("%c", pAuxL->letra);
            pAuxL = pAuxL->ProxLetra; /* próxima célula */
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


void ordenaPalavraEncadeada(TListaTexto texto)
{
    printf("Texto Original: ");
    imprimeTextoEncadeado(&texto);
    int n = texto.numeroPalavras;
    if(n <= 1)
    {
        printf("Tempo total da CPU para organizar via selecao: 0 ms\n");
        printf("Total de Comparacoes: 0, Total de Movimentacoes: 0\n");
        return;
    }
    //
    int comparacao = 0, movimentacao = 0; //Comparações e movimentação
    clock_t Ticks[2];
    Ticks[0] = clock(); //Inicio
    apontadorTexto pAux, pAux2;
    apontadorTexto Mini = texto.pPrimeiro;
    TlistaPalavra palavra, palAux;
    int i,j;
    Ticks[0] = clock();
    for (i = 0; i < n - 1; i++) {
        Mini = Mini->ProxPalavra;
        palavra = Mini->palavra;
        pAux = Mini->ProxPalavra;
        pAux2 = Mini;
        for (j = i + 1; j < n; j++)
        {
            comparacao++;
            if (pAux->palavra.pPrimeiro->ProxLetra->letra < palavra.pPrimeiro->ProxLetra->letra)
            {
                palavra = pAux->palavra;
                pAux2 = pAux;
            }
            pAux = pAux->ProxPalavra;
        }
        movimentacao++;
        palAux = Mini->palavra;
        Mini->palavra = palavra;
        pAux2->palavra = palAux;
    }
    printf("Texto Ordenado: ");
    imprimeTextoEncadeado(&texto);

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

