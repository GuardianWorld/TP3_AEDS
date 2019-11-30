#include "TADTexto.h"
#include "TADPalavra.h"
void inicializaTexto(TTexto* texto, int TextoTamanho)
{
    texto->palavras = (TPalavra*)malloc(TextoTamanho * sizeof(TPalavra));
    int x;
    for(x = 0; x < TextoTamanho; x++)
    {
        inicializaPalavra(&texto->palavras[x]);
    }
    texto->numeroPalavras = 0;
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
}
void tamanhoTexto(TTexto* texto)
{
    printf("Tamanho: %d\n", texto->numeroPalavras);
}


void ordenaPalavra(TTexto* texto)
{

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
          }
        }

        temp = texto->palavras[min_idx];
        texto->palavras[min_idx] = texto->palavras[i];
        texto->palavras[i] = temp;
    }
}
