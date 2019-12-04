#include "TADBibliotecaEncadeada.h"

void inicializaBibliotecaEncadeada(TListaBiblioteca* listaBib)
{
    listaBib->pPrimeiro = malloc(sizeof(TBibliotecaEncadeada));
    listaBib->pUltimo = listaBib->pPrimeiro;
    listaBib->pPrimeiro->ProxTexto = NULL;
    listaBib->pPrimeiro->antTexto = NULL;
    listaBib->tamanhoBib = 0;
}
void insereTextoEncadeado(TListaBiblioteca* listaBib, int tamanhoTexto, int tamanhoPalavra)
{
    int y;
    int x;
    int trandom;
    char inputLetra;
    TListaTexto* Texto;
    listaBib->pUltimo->ProxTexto = malloc(sizeof(TBibliotecaEncadeada));
    listaBib->pUltimo->ProxTexto->antTexto = listaBib->pUltimo;
    listaBib->pUltimo = listaBib->pUltimo->ProxTexto;
    listaBib->pUltimo->ProxTexto = NULL;
    Texto = &(listaBib->pUltimo->Texto);
    inicializaTextoEncadeado(&(listaBib->pUltimo->Texto));
    //inicializaPalavraEncadeada(&listaBib->pUltimo->Texto.pUltimo->palavra);
    if(tamanhoTexto == 100000)
    {
        trandom = rand() % 50000;
    }
    else
    {
        trandom = rand() % tamanhoTexto;
    }

    for(x = 0; x < tamanhoTexto - trandom; x++)
    {
        inserePalavraEncadeado(&listaBib->pUltimo->Texto, tamanhoPalavra);
        //imprimeTextoEncadeado(&(listaBib->pUltimo->Texto));
    }
    //printf("\n=%c=\n",listaBib->pUltimo->Texto.pUltimo->palavra.pPrimeiro->ProxLetra->letra);
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
    /*for(y = 0;y < listaBib->tamanhoBib;y++){
        pAux = pAux->ProxTexto;
        //imprimeTextoEncadeado(&pAux->Texto);
        printf("\n=%c=",pAux->Texto.pPrimeiro->ProxPalavra->palavra.pPrimeiro->ProxLetra->letra);
    }*/
    int w = 0;
    if(listaBib->tamanhoBib == 0)
    {
        return;
    }
    int h = 0;
    while (pAux != NULL && y!= 150)
    {
        y++;
        printf("Imprimindo texto %d\n", y);
        printf("\n");
        pAuxT = pAux->Texto.pPrimeiro->ProxPalavra;
        w = 0;
        while(pAuxT != NULL && w != 1000)
        {
            pAuxL = pAuxT->palavra.pPrimeiro->ProxLetra;
            while (pAuxL != NULL)
            {
                printf("%c", pAuxL->letra);
                pAuxL = pAuxL->ProxLetra; /* próxima célula*/
            }
            printf(" ");
            pAuxT = pAuxT->ProxPalavra;
            w++;
        }
        if(w >= 1000)
        {
            printf("...\n");
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

//Quicksort


void Quicksort(int Inicio, int Fim, TListaBiblioteca* Bib, int* comp, int* mov)
{
    int x,y;
    ParticaoQSBib(Bib,Inicio, Fim, &x, &y, comp, mov);
    *comp += 2;
    if (Inicio < y)
    {
        Quicksort(Inicio, y, Bib, comp, mov);
    }
    if (x < Fim)
    {
        Quicksort(x, Fim, Bib, comp, mov);
    }
    return;
}

void ParticaoQSBib(TListaBiblioteca* bib, int Inicio, int Fim,int* x, int* y, int* comp, int* mov){
    int centro, h,j,k;
    apontadorBib pAux;
    pAux = bib->pPrimeiro;
    apontadorBib pAux2;
    pAux2 = pAux;
    apontadorBib pAux3;
    pAux3 = pAux;
    struct BibEncadeado auxTexto;
    *x = Inicio;
    *y = Fim;
    int xa;
    xa = *x;
    int ya;
    ya = *y;

    for (k = 0;k < (xa+ya)/2 ;k++)
    {
        pAux = pAux->ProxTexto;
    }
    centro = pAux->Texto.numeroPalavras;
    for(h = 0; h < xa; h++)
    {
        pAux2 = pAux2->ProxTexto;
    }

    for(j = 0;j < ya; j++)
    {
        pAux3 = pAux3->ProxTexto;
    }
    while (xa <= ya)
    {
        *comp += 4;
        while (centro > pAux2->Texto.numeroPalavras)
        {
            pAux2 = pAux2->ProxTexto;
            *x += 1;
        }

        while (centro < pAux3->Texto.numeroPalavras)
        {
            pAux3 = pAux3->ProxTexto;
            *y += 1;
        }
        xa = *x;
        ya = *y;
        if (xa <= ya)
        {
            auxTexto.Texto = pAux2->Texto;
            pAux2->Texto = pAux3->Texto;
            pAux3->Texto = auxTexto.Texto;

            *x += 1;
            *y -= 1;
            *mov += 1;
            xa = *x;
            ya = *y;
        }
    }
}
