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
    inicializaPalavraEncadeada(&listaTextos->pUltimo->palavra);
    for(y = 0; y < tamanhoPalavra - rand() % tamanhoPalavra; y++)
    {
        inputLetra = (rand() % 26) + 65;
        insereLetraEncadeada(&listaTextos->pUltimo->palavra, inputLetra);
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
    apontadorTexto pAux2;

    if(listaTextos->numeroPalavras == 0)
    {
        return;
    }

    pAux = listaTextos->pPrimeiro->ProxPalavra;
    pAux2 = listaTextos->pUltimo;
    while(pAux != NULL)
    {
        imprimePalavraEncadeada(&pAux->palavra);
        printf(" ");
        pAux = pAux->ProxPalavra;
    }
        /*while(pAux2 != NULL)
    {
        imprimePalavraEncadeada(&pAux2->palavra);
        printf(" ");
        pAux2 = pAux2->AntPalavra;
    }*/
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

  /*void selectionSortTextoLe(TListaPLe texto, int flag){
    for (int i = 0; i < texto.tam - 1; i++) {
        min = min->pProx;
        palavra = min->palavra;
        aux = min->pProx;
        aux2 = min;
        for (int j = i + 1; j < texto.tam; j++) {
            comp++;
            if (palavra.primeiraletra > aux->palavra.primeiraletra) {
                palavra = aux->palavra;
                aux2 = aux;
            }
            aux = aux->pProx;
        }
        palavraaux = min->palavra;
        min->palavra = palavra;
        aux2->palavra = palavraaux;
        mov++;
    }






    /*int n = texto->numeroPalavras;
    if(n <= 1)
    {
        printf("Tempo total da CPU para organizar via selecao: 0 ms\n");
        printf("Total de Comparacoes: 0, Total de Movimentacoes: 0\n");
        return;
    }
    //
    int comparacao = 0, movimentacao = 0; //Comparações e movimentação
    clock_t Ticks[2];
    Ticks[0] = clock();
    Ticks[1] = clock();
    //

    apontadorTexto pAux = texto->pPrimeiro->ProxPalavra; //1
    apontadorTexto pAux2 = pAux->ProxPalavra; //2
    TlistaPalavra checar;
    //printf("%c\n",texto->pPrimeiro->ProxPalavra->palavra.pPrimeiro->ProxLetra->letra);
    //
    int i,j,h, Min;
    for(i = 0; i < n-1; i++)
    {

        //aux = v[Min];
        //v[Min] = v[i];
        //v[i] = aux;

        //pAux2 = pAux2->ProxPalavra;
        pAux = pAux->ProxPalavra;
        pAux2 = pAux->ProxPalavra;
    }

    //
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo total da CPU para organizar via selecao: %g ms\n", Tempo);
    printf("Total de Comparacoes: %d, Total de Movimentacoes: %d\n", comparacao, movimentacao);
    return;*/
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

