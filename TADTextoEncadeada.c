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
    for(y = 0; y < tamanhoPalavra; y++)
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
        //return;
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

void QSTextoEncadeado(TListaTexto* texto, int inicio, int fim, int* comparacao, int* movimentacao)
{
    if(texto->numeroPalavras == 0)
    {
        return;
    }
    int x,y;
    particaoTextoEncadeado(texto,inicio, fim, &x, &y, comparacao, movimentacao);
    *comparacao += 2;
    if (inicio < y)
    {
        QSTextoEncadeado(fim, y, texto,comparacao,movimentacao);
    }
    if (x < fim)
    {
        QSTextoEncadeado(x, fim, texto, comparacao, movimentacao);
    }
}

void particaoTextoEncadeado(TListaTexto* texto, int inicio, int fim,int *x, int *y, int* Comp, int* Mov)
{
    char pivot;
    apontadorTexto pAux = texto->pPrimeiro;
    apontadorTexto pAux2= pAux;
    apontadorTexto pAux3= pAux;
    TlistaPalavra auxP;
    *x = inicio; *y = fim;
    int xa, ya;
    xa = *x;
    ya = *y;
    int h,j,k;
    for(h = 0; h < xa;h++)
    {
        pAux2 = pAux2->ProxPalavra;
    }
    for(j = 0; j < ya; j++)
    {
        pAux3 = pAux3->ProxPalavra;
    }
    for (k = 0; k < (xa + ya)/2;k++)
    {
        pAux=pAux->ProxPalavra;
    }
        pivot = pAux->palavra.pPrimeiro->ProxLetra->letra;
    while (*x <= *y)
    {
        while (pivot > pAux2->palavra.pPrimeiro->letra)
        {
            pAux2=pAux2->ProxPalavra;
            *x += 1;
        }
        while (pivot < pAux3->palavra.pPrimeiro->letra)
        {
            pAux3=pAux3->AntPalavra;
            *y += 1;
        }
        *Comp += 1;
        if (*x <= *y)
        {
            auxP = pAux2->palavra;
            pAux2->palavra = pAux3->palavra;
            pAux3->palavra = auxP;
            Mov += 1;
            *x += 1;
            *y += 1;
        }
    }
}
