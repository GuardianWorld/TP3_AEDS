#include "TADPalavra.h"
void inicializaPalavra(TPalavra* palavra)
{
    palavra->palavra = (char*)malloc(10 * sizeof(char));
    palavra->palavra[0] = '\0';
    palavra->tamanho = 0;
}
void insereLetra(TPalavra* palavra, char letra)
{
    palavra->palavra[palavra->tamanho] = letra;
    palavra->tamanho++;
}

void removeLetra(TPalavra* palavra, char letra)
{
    int x;
    int mover = 0;

    for(x = 0; x < palavra->tamanho; x++)
    {
       //ABCD / C -> ABD
       if(palavra->palavra[x] == letra)
       {
           mover = 1;
       }

       if(mover != 0)
       {
           if(x == palavra->tamanho -1)
           {
               palavra->palavra[x] = '\0';
           }
           else
           {
               palavra->palavra[x] = palavra->palavra[x+1];
           }
       }
    }
    palavra->tamanho--;
}

void removeLetraLoop(TPalavra* palavra)
{
    int y = palavra->tamanho;
    int z;
    for(z = 0; z < y; z++)
    {
        removeLetra(palavra, palavra->palavra[0]);
    }
}

void imprimePalavra(TPalavra palavra)
{
    printf("Palavra: %s\n", palavra.palavra);
}

void tamanhoPalavra(TPalavra* palavra)
{
    printf("Tamanho: %d\n", palavra->tamanho);
}
