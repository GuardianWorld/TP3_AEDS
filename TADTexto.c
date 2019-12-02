#include "TADTexto.h"
#include "TADPalavra.h"
#include <time.h>
void inicializaTexto(TTexto* texto, int TextoTamanho)
{
    texto->palavras = (TPalavra*)malloc(TextoTamanho * sizeof(TPalavra));
    int x;
    for(x = 0; x < TextoTamanho; x++)
    {
        inicializaPalavra(&texto->palavras[x]);
    }
    texto->numeroPalavras = 0;
    return;
}

void inserePalavra(TTexto* texto, TPalavra* palavra)
{
    strcpy(texto->palavras[texto->numeroPalavras].letras , palavra->letras);
    texto->palavras[texto->numeroPalavras].tamanho = palavra->tamanho;
    texto->numeroPalavras++ ;
}

void removePalavra(TTexto* texto, int pos)
{
    int x;
    int mover = 0;
    for(x = 0; x < texto->numeroPalavras; x++)
    {
       //ABCD / C -> ABD
       if(x == pos)
       {
           mover = 1;
       }

       if(mover != 0)
       {
           if(x == texto->numeroPalavras-1)
           {
               strcpy(texto->palavras[x].letras, "\0");
               texto->palavras[x].tamanho = 0;
           }
           else
           {
               strcpy(texto->palavras[x].letras, texto->palavras[x+1].letras);
               texto->palavras[x].tamanho = texto->palavras[x+1].tamanho;
           }
       }
    }
    //system("pause");
    texto->numeroPalavras--;
    return;
}

void removePalavraLoop(TTexto* texto)
{
    int y = texto->numeroPalavras;
    int z;
    for(z = 0; z < y; z++)
    {
        //printf("Hi");
        removePalavra(texto, 0);
    }
    return;
}

void imprimeTexto(TTexto* texto)
{
    int y;
    printf("\n");
    for(y = 0; y < texto->numeroPalavras; y++)
    {


        printf("%s ",texto->palavras[y].letras);


    }
    printf("\n");
    return;
}
void tamanhoTexto(TTexto* texto)
{
    printf("Tamanho: %d\n", texto->numeroPalavras);
    return;
}


void ordenaPalavra(TTexto* texto)
{
    int comparacao = 0, movimentacao = 0; //Comparações e movimentação
    clock_t Ticks[2];
    Ticks[0] = clock();
    Ticks[1] = clock();
    int i, j, min_idx;
    TPalavra temp;
    int n = texto->numeroPalavras;
    //int ver1,ver2

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

void quickSort(TPalavra* palavra, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, palavra[p] is now
           at right place */
        int pi = particao(palavra, low, high);

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


