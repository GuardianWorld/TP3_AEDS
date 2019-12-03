#include "TADPalavraEncadeada.h"

void inicializaPalavraEncadeada(TlistaPalavra* listaLetras)
{
    listaLetras->pPrimeiro = malloc(sizeof(TPalavraEncadeada));
    listaLetras->pUltimo = listaLetras->pPrimeiro;
    listaLetras->pUltimo->ProxLetra = NULL;
    listaLetras->tamanho = 0;
    return;
}

int inf = 0;

void insereLetraEncadeada(TlistaPalavra* listaLetras, char letra)
{
    //inf++;
    //printf("\n%c %d\n", letra,inf);
    listaLetras->pUltimo->ProxLetra = (apontadorLetra) malloc(sizeof(TPalavraEncadeada));
    listaLetras->pUltimo = listaLetras->pUltimo->ProxLetra;
    listaLetras->pUltimo->letra = letra;
    listaLetras->pUltimo->ProxLetra = NULL;
    listaLetras->tamanho++;
    return;
}

void removeLetraEncadeada(TlistaPalavra* listaLetras)
{
    apontadorLetra pAux;
    int x;
    if (listaLetras->tamanho == 0)
    {
        return;
    }
    pAux = listaLetras->pPrimeiro->ProxLetra;
    listaLetras->pPrimeiro->ProxLetra = listaLetras->pPrimeiro->ProxLetra->ProxLetra;
    //printf("%c\n", pAux->letra);
    free(pAux);
    listaLetras->tamanho--;
    if(listaLetras->tamanho == 0)
    {
        listaLetras->pUltimo = listaLetras->pPrimeiro;
        listaLetras->pPrimeiro->ProxLetra = NULL;
    }
    return;
}

void removeLetraLoopEncadeada(TlistaPalavra* listaLetras)
{
    int y = listaLetras->tamanho;
    int z;
    for(z = 0; z < y; z++)
    {
        removeLetraEncadeada(listaLetras);
    }
    return;
}

void imprimePalavraEncadeada(TlistaPalavra* lista)
{
    apontadorLetra pAux;
    if(lista->tamanho == 0)
    {
        return;
    }

    pAux = lista->pPrimeiro->ProxLetra;
    while (pAux != NULL)
    {
        //printf("%c", pAux->letra);
        pAux = pAux->ProxLetra; /* próxima célula */
    }
    //printf("\n");
    return;
}

void tamanhoPalavraEncadeada(TlistaPalavra* palavra)
{
    printf("Tamanho: %d\n", palavra->tamanho);
    return;
}
