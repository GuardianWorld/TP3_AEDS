#include "TADTexto.h"
#include "TADPalavra.h"
#include "TADBiblioteca.h"
/*void inicializaBiblioteca(TBiblioteca* Biblioteca, int TamanhoTextos,int TamanhoBib)
{
    int x;
    //Biblioteca->textos = malloc(TamanhoBib * sizeof(TTexto));
    /*for(x = 0; x < TamanhoTextos; x++)
    {

    }*/
    /*inicializaTexto(&Biblioteca->textos[0].texto, TamanhoTextos);
    inicializaTexto(&Biblioteca->textos[1].texto, TamanhoTextos);
    inicializaTexto(&Biblioteca->textos[2].texto, TamanhoTextos);
    inicializaTexto(&Biblioteca->textos[3].texto, TamanhoTextos);
    inicializaTexto(&Biblioteca->textos[4].texto, TamanhoTextos);
    inicializaTexto(&Biblioteca->textos[5].texto, TamanhoTextos);
    inicializaTexto(&Biblioteca->textos[6].texto, TamanhoTextos);
    inicializaTexto(&Biblioteca->textos[7].texto, TamanhoTextos);
    inicializaTexto(&Biblioteca->textos[8].texto, TamanhoTextos);
    inicializaTexto(&Biblioteca->textos[9].texto, TamanhoTextos);

    Biblioteca->tamBiblioteca = 0;
}
void insereTexto(TBiblioteca* Biblioteca, TTexto* texto)
{
    int x;
    for (x = 0; x < texto->numeroPalavras; x++)
    {
        strcpy(Biblioteca->textos[Biblioteca->tamBiblioteca].texto[x].palavra, texto->texto[x].palavra);
        Biblioteca->textos[Biblioteca->tamBiblioteca].texto[x].tamanho = texto->texto[x].tamanho;
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
                   strcpy(Biblioteca->textos[x].texto[y].palavra, "\0");
               }
               Biblioteca->textos[x].texto[y].tamanho = 0;
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


    for(z = 0; z < Biblioteca->tamBiblioteca; z++){
        printf("\nImprimindo texto: %d\n\n",z+1);
        for(y = 0; y < Biblioteca->textos[z].numeroPalavras; y++)
        {
            printf("%s ",Biblioteca->textos[z].texto[y].palavra);
        }
    }
    printf("\n");
}
void tamanhoBiblioteca(TBiblioteca* Biblioteca)
{
    printf("Tamanho da Biblioteca: %d\n", Biblioteca->tamBiblioteca);
}


void ordenaTexto(TBiblioteca* Biblioteca)
{

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
          }
        }

        temp = Biblioteca->textos[min_idx];
        Biblioteca->textos[min_idx] = Biblioteca->textos[i];
        Biblioteca->textos[i] = temp;
    }
}
*/
