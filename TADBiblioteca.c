#include "TADTexto.h"
#include "TADPalavra.h"
#include "TADBiblioteca.h"
#include <time.h>
void inicializaBiblioteca(TBiblioteca* Biblioteca, int TamanhoTextos,int TamanhoBib)
{
    int x;
    Biblioteca->textos = malloc(TamanhoBib * sizeof(TTexto));
    for(x = 0; x < TamanhoBib; x++)
    {
        inicializaTexto(&Biblioteca->textos[x], TamanhoTextos);
    }
    Biblioteca->tamBiblioteca = 0;
}
void insereTexto(TBiblioteca* Biblioteca, TTexto* texto)
{
    int x;
    for (x = 0; x < texto->numeroPalavras; x++)
    {
        strcpy(Biblioteca->textos[Biblioteca->tamBiblioteca].palavras[x].letras, texto->palavras[x].letras);
        Biblioteca->textos[Biblioteca->tamBiblioteca].palavras[x].tamanho = texto->palavras[x].tamanho;
        Biblioteca->textos[Biblioteca->tamBiblioteca].numeroPalavras++;
    }
    Biblioteca->tamBiblioteca++;
    //system("Pause");
}

void removeTexto(TBiblioteca* Biblioteca, int pos)
{
    int x, y;
    int mover = 0;
    for(x = 0; x < Biblioteca->tamBiblioteca; x++)
    {
       //ABCD / C -> ABD
       if(x == pos)
       {
           mover = 1;
       }

       if(mover != 0)
       {
           if(x == Biblioteca->tamBiblioteca-1)
           {
               for(y = 0; y < Biblioteca->textos[x].numeroPalavras; y++)
               {
                   strcpy(Biblioteca->textos[x].palavras[y].letras, "\0");
               }
               Biblioteca->textos[x].palavras[y].tamanho = 0;
               Biblioteca->textos[x].numeroPalavras = 0;
           }
           else
           {
               Biblioteca->textos[x] = Biblioteca->textos[x+1];
               Biblioteca->textos[x].numeroPalavras = Biblioteca->textos[x+1].numeroPalavras;
           }
       }
    }
    //system("pause");
    Biblioteca->tamBiblioteca--;

}

void removeTextoLoop(TBiblioteca* Biblioteca)
{
    int x;
    int local = Biblioteca->tamBiblioteca;
    for(x = 0; x < local; x++)
    {
        removeTexto(Biblioteca, 0);
    }

}

void imprimeBiblioteca(TBiblioteca* Biblioteca)
{
    int y,z;

    int l = Biblioteca->tamBiblioteca;
    int k = 0;
    if(Biblioteca->tamBiblioteca > 150)
    {
        l = 150;
    }
    for(z = 0; z < l; z++){
        printf("\nImprimindo texto: %d\n\n",z+1);
        k = Biblioteca->textos[z].numeroPalavras;
        if(Biblioteca->textos[z].numeroPalavras > 200)
        {
            k = 200;
        }
        for(y = 0; y < k; y++)
        {
            printf("%s ",Biblioteca->textos[z].palavras[y].letras);
        }
        if(k = 200)
        {
            printf("...");
        }
    }
    printf("\n");
}
void tamanhoBiblioteca(TBiblioteca* Biblioteca)
{
    printf("Tamanho da Biblioteca: %d\n", Biblioteca->tamBiblioteca);
}


void ordenaTexto(TBiblioteca* Biblioteca){

    printf("Biblioteca original: \n");
    imprimeBiblioteca(Biblioteca);
    int comparacao = 0, movimentacao = 0; //Comparações e movimentação
    clock_t Ticks[2];
    Ticks[0] = clock();
    Ticks[1] = clock();

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
            comparacao++;
          }
        }

        temp = Biblioteca->textos[min_idx];
        Biblioteca->textos[min_idx] = Biblioteca->textos[i];
        Biblioteca->textos[i] = temp;
        movimentacao++;

    }
    Ticks[1] = clock();
    printf("Biblioteca ordenada: \n");
    imprimeBiblioteca(Biblioteca);
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo total da CPU para organizar via selecao: %g ms\n", Tempo);
    printf("Total de Comparacoes: %d, Total de Movimentacoes: %d\n", comparacao, movimentacao);
}

//Quicksort


void quickSortbib(TTexto* texto, int low, int high, int* comp, int* mov)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partitionbib(texto, low, high, comp, mov);

        // Separately sort elements before
        // partition and after partition
        quickSortbib(texto, low, pi - 1, comp, mov);
        quickSortbib(texto, pi + 1, high, comp, mov);
    }
}

int partitionbib (TTexto* texto, int low, int high, int* comp, int* mov)
{
    int pivot = texto[high].numeroPalavras;
    //printf("=%d=",texto[high].numeroPalavras);    // pivot
    int i = (low - 1);  // Index of smaller element
    for (int j = low; j <= high- 1; j++)
    {
        *comp += 1;
        // If current element is smaller than the pivot
        if (texto[j].numeroPalavras < pivot)
        {
            i++;    // increment index of smaller element
            swapbib(&texto[i], &texto[j], mov);
        }
    }
    swapbib(&texto[i + 1], &texto[high], mov);
    return (i + 1);
}


void swapbib(TTexto* a, TTexto* b, int* mov)
{
    TTexto t = *a;
    *a = *b;
    *b = t;
    *mov += 1;
}
