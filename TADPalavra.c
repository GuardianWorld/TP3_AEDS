#include "TADPalavra.h"
void inicializaPalavra(TPalavra* palavra)
{
    palavra->letras = (char*)malloc(100 * sizeof(char));
    int x;
    palavra->tamanho = 0;
}
void insereLetra(TPalavra* palavra, char letra)
{
    if(palavra->tamanho == MAXWORD - 1)
    {
        return;
    }
    palavra->letras[palavra->tamanho] = letra;
    palavra->letras[palavra->tamanho+1] = '\0';
    palavra->tamanho++;
    return;
}

void removeLetra(TPalavra* palavra, char letra)
{
    int x;
    int mover = 0;

    for(x = 0; x < palavra->tamanho; x++)
    {
       //ABCD / C -> ABD
       if(palavra->letras[x] == letra)
       {
           mover = 1;
       }

       if(mover != 0)
       {
           if(x == palavra->tamanho -1)
           {
               palavra->letras[x] = '\0';
           }
           else
           {
               palavra->letras[x] = palavra->letras[x+1];
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
        removeLetra(palavra, palavra->letras[0]);
    }
}

void imprimePalavra(TPalavra palavra)
{
    printf("Palavra: %s\n", palavra.letras);
}

void tamanhoPalavra(TPalavra* palavra)
{
    printf("Tamanho: %d\n", palavra->tamanho);
}
