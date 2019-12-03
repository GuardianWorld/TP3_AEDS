#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TADPalavra.h"
#include "TADTexto.h"
#include "TADBiblioteca.h"
#include "TADBibliotecaEncadeada.h"
#include "TADPalavraEncadeada.h"
#include "TADTextoEncadeada.h"

int main()
{
    int comparacao = 0, movimentacao = 0; //Comparações e movimentação
    clock_t Ticks[2];
    int input, input2,input3 ,x,y,z;
    int inicializado = 0;
    int ordenaMenu = 0;
    int random = 0;
    char inputLetra;
    input = -2;
    //Vetores:
    TPalavra word;
    TPalavra word2;
    TTexto text;
    TTexto text2;
    TBiblioteca bib;
    TBiblioteca bib2;
    //Encadeada
    TlistaPalavra eword;
    TlistaPalavra eword2;
    TListaTexto etext;
    TListaTexto etext2;
    TListaBiblioteca ebib;
    TListaBiblioteca ebib2;
    srand((unsigned int)time(NULL));

    printf(" |========================|\n");
    printf(" |     Selecao de modo    |\n");
    printf(" | 0) Modo Vetor          |\n");
    printf(" | 1) Modo Lista Enc.     |\n");
    printf(" |========================|\n\n");

    scanf("%d", &input);
    printf("\n");

    if(input == 0)
    {
    while(input != 99)
    {
        /*#if WIN32
        system("cls");
        #endif // WIN32*/

        if(ordenaMenu == 0)
        {
        printf(" |===========================|\n");
        printf(" |        Menu funcao        |\n");
        printf(" | 0) Inicializar funcoes    |\n");
        printf(" | 1) Criar Palavra          |\n");
        printf(" | 2) Criar Texto            |\n");
        printf(" | 3) Criar Biblioteca       |\n");
        printf(" | 4) Remover Palavra        |\n");
        printf(" | 5) Remover Texto          |\n");
        printf(" | 6) Remover Biblioteca     |\n");
        printf(" | 7) Imprimir Palavra       |\n");
        printf(" | 8) Imprimir Texto         |\n");
        printf(" | 9) Imprimir Biblioteca    |\n");
        printf(" | 10) Menu Ordenacao        |\n");
        printf(" | 11) Sair do programa      |\n");
        printf(" |===========================|\n\n");
        scanf("%d", &input);
        if(input == 0)
        {
            if(inicializado == 1)
            {
                removeLetraLoop(&word);
                removePalavraLoop(&text);
                removeTextoLoop(&bib);
                removeLetraLoop(&word2);
                removePalavraLoop(&text2);
                removeTextoLoop(&bib2);
            }
            else
            {
                printf("Digite o tamanho maximo de cada texto: ");
                scanf("%d", &input2);
                printf("Digite o tamanho maximo de cada Biblioteca: ");
                scanf("%d", &input3);
                inicializaPalavra(&word);
                inicializaTexto(&text,input2);
                inicializaBiblioteca(&bib,input2, input3);
                inicializaPalavra(&word2);
                inicializaTexto(&text2,input2);
                inicializaBiblioteca(&bib2,input2, input3);
                inicializado = 1;
            }
        }
        else if(input == 1)
        {
            printf("==Insira o numero de letras da palavra: ");
            scanf("%d", &input);
            removeLetraLoop(&word);
            removeLetraLoop(&word2);
            for(x = 0; x < input; x++)
            {
                inputLetra = (rand() % 26) + 65;
                insereLetra(&word, inputLetra);
                insereLetra(&word2, inputLetra);
            }
            input = -1;
        }
        else if(input == 2)
        {
            printf("Insira o numero de palavras do texto: ");
            scanf("%d", &input);
            printf("Insira o numero de letras da palavra: ");
            scanf("%d", &input2);
            removePalavraLoop(&text);
            removePalavraLoop(&text2);

            for(x = 0; x < input; x++)
            {
                removeLetraLoop(&word);
                 // Randomiza o tamnanho da palavra
                for(y = 0; y < input2 - rand() % input2; y++)
                {
                    inputLetra = (rand() % 26) + 65;
                    insereLetra(&word, inputLetra);
                    insereLetra(&word2, inputLetra);
                }
                //printf("%s", word.palavra);
                inserePalavra(&text, &word);
                inserePalavra(&text2, &word);
            }
            input = -1;
        }
        else if(input == 3)
        {
            printf("Insira o numero de textos da biblioteca: ");
            scanf("%d", &input);
            printf("Insira o numero de palavras do texto: ");
            scanf("%d", &input2);
            printf("Insira o numero de letras da palavra: ");
            scanf("%d", &input3);
            removeTextoLoop(&bib);
            removeTextoLoop(&bib2);
            for(x = 0; x < input; x++) //Biblioteca
            {
                removePalavraLoop(&text);
                removePalavraLoop(&text2);
                if(input2 == 100000)
                {
                    random = input2 - rand() % 50001;
                }
                else
                {
                    random = input2 - rand() % input2;
                }
                for(y = 0; y < random ; y++) //Texto
                {
                    removeLetraLoop(&word);
                    removeLetraLoop(&word2);
                    for(z = 0; z < input3 - rand() % input3; z++) //Palavra
                    {
                        inputLetra = (rand() % 26) + 65;
                        insereLetra(&word, inputLetra);
                        insereLetra(&word2, inputLetra);
                    }
                    inserePalavra(&text, &word);
                    inserePalavra(&text2, &word);
                }
                insereTexto(&bib, &text);
                insereTexto(&bib2, &text);
            }
            input = -1;

        }
        else if(input == 4)
        {
            removeLetraLoop(&word);
            removeLetraLoop(&word2);
        }
        else if(input == 5)
        {
            removePalavraLoop(&text);
            removePalavraLoop(&text2);
        }
        else if(input == 6)
        {
            removeTextoLoop(&bib);
            removeTextoLoop(&bib2);
        }
        else if(input == 7)
        {
            printf("Imprimindo Palavra\n");
            imprimePalavra(word);
            tamanhoPalavra(&word);
            system("pause");
        }
        else if(input == 8)
        {
            printf("Imprimindo Texto\n");
            imprimeTexto(&text);
            tamanhoTexto(&text);
            system("pause");

        }
        else if(input == 9)
        {
            printf("Imprimindo Biblioteca\n");
            imprimeBiblioteca(&bib);
            tamanhoBiblioteca(&bib);
            system("pause");


        }
        else if(input == 10)
        {
            ordenaMenu = 1;
        }
        else if(input == 11)
        {
            return 0;
        }
        input = -1;
        }
        else
        {
        printf("|===========================|\n");
        printf("|       Menu Ordenacao      |\n");
        printf("| 0) Ordenar T1. (Selecao)  |\n");
        printf("| 1) Ordenar B1. (Selecao)  |\n");
        printf("| 2) Ordenar T2. (Selecao)  |\n");
        printf("| 3) Ordenar B2. (Selecao)  |\n");
        printf("| 4) Ordenar T1. (QuickSort)|\n");
        printf("| 5) Ordenar B1. (QuickSort)|\n");
        printf("| 6) Ordenar T2. (QuickSort)|\n");
        printf("| 7) Ordenar B2. (QuickSort)|\n");
        printf("| 10) Menu funcao           |\n");
        printf("| 11) Sair do programa      |\n");
        printf("|===========================|\n\n");
        scanf("%d", &input);

        if(input == 0)
        {
            ordenaPalavra(&text);
        }
        else if(input == 1)
        {
            ordenaTexto(&bib);
        }
        else if(input == 2)
        {
            ordenaPalavra(&text2);
        }
        else if(input == 3)
        {
            ordenaTexto(&bib2);
        }
        else if(input == 4)
        {
            printf("Texto Original: \n");
            imprimeTexto(&text);
            int n = text.numeroPalavras;
            Ticks[0] = clock();
            x = 0;
            y = 0;
            quickSort(text.palavras, 0 , n-1, &x, &y);
            Ticks[1] = clock();
            printf("Texto Ordenado: \n");
            imprimeTexto(&text);
            double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
            printf("Tempo total da CPU para organizar via selecao: %g ms\n", Tempo);
            printf("Total de Comparacoes: %d, Total de Movimentacoes: %d\n", x, y);
        }
        else if(input == 5)
        {
            printf("Bib Original: \n");
            imprimeBiblioteca(&bib);
            int n = bib.tamBiblioteca;
            Ticks[0] = clock();
            x = 0;
            y = 0;
            quickSortbib(bib.textos, 0 , n-1, &x, &y);
            Ticks[1] = clock();
            printf("Bib Ordenada: \n");
            imprimeBiblioteca(&bib);
            double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
            printf("Tempo total da CPU para organizar via selecao: %g ms\n", Tempo);
            printf("Total de Comparacoes: %d, Total de Movimentacoes: %d\n", x, y);
        }
        else if(input == 6)
        {
            printf("Texto Original: \n");
            imprimeTexto(&text);
            int n = text2.numeroPalavras;
            Ticks[0] = clock();
            x = 0;
            y = 0;
            quickSort(text2.palavras, 0 , n-1, &x, &y);
            Ticks[1] = clock();
            printf("Texto Ordenado: \n");
            imprimeTexto(&text);
            double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
            printf("Tempo total da CPU para organizar via selecao: %g ms\n", Tempo);
            printf("Total de Comparacoes: %d, Total de Movimentacoes: %d\n", x, y);
        }
        else if(input == 7)
        {
            printf("Bib Ordenada: \n");
            imprimeBiblioteca(&bib2);
            int n = bib2.tamBiblioteca;
            Ticks[0] = clock();
            x = 0;
            y = 0;
            quickSortbib(bib2.textos, 0 , n-1, &x, &y);
            Ticks[1] = clock();
            printf("Bib Ordenada: \n");
            imprimeBiblioteca(&bib2);
            double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
            printf("Tempo total da CPU para organizar via selecao: %g ms\n", Tempo);
            printf("Total de Comparacoes: %d, Total de Movimentacoes: %d\n", x, y);
        }
        else if(input == 10)
        {
            ordenaMenu = 0;
        }
        else if(input == 11)
        {
            return 0;
        }


        }
    }
    }
    else if(input == 1)
    {
       while(input != 99)
       {
           /*#if WIN32
        system("cls");
        #endif // WIN32*/

        if(ordenaMenu == 0)
        {
        printf(" |===========================|\n");
        printf(" |        Menu funcao        |\n");
        printf(" | 0) Inicializar funcoes    |\n");
        printf(" | 1) Criar Palavra          |\n");
        printf(" | 2) Criar Texto            |\n");
        printf(" | 3) Criar Biblioteca       |\n");
        printf(" | 4) Remover Palavra        |\n");
        printf(" | 5) Remover Texto          |\n");
        printf(" | 6) Remover Biblioteca     |\n");
        printf(" | 7) Imprimir Palavra       |\n");
        printf(" | 8) Imprimir Texto         |\n");
        printf(" | 9) Imprimir Biblioteca    |\n");
        printf(" | 10) Menu Ordenacao        |\n");
        printf(" | 11) Sair do programa      |\n");
        printf(" |===========================|\n\n");

        scanf("%d", &input);
        if(input == 0)
        {
            if(inicializado == 1)
            {
                removeLetraLoopEncadeada(&eword);
                removePalavraLoopEncadeado(&etext);
                removeTextoLoopEncadeado(&ebib);
            }
            else
            {
                inicializaPalavraEncadeada(&eword);
                inicializaTextoEncadeado(&etext);
                inicializaBibliotecaEncadeada(&ebib);
                inicializado = 1;
            }
        }
        else if(input == 1)
        {
            printf("==Insira o numero de letras da palavra: ");
            scanf("%d", &input);
            removeLetraLoopEncadeada(&eword);
            for(x = 0; x < input; x++)
            {
                inputLetra = (rand() % 26) + 65;
                insereLetraEncadeada(&eword, inputLetra);
            }
        }
        else if(input == 2)
        {
            printf("Insira o numero de palavras do texto: ");
            scanf("%d", &input);
            printf("Insira o numero de letras da palavra: ");
            scanf("%d", &input2);
            removePalavraLoopEncadeado(&etext);
            for(x = 0; x < input; x++)
            {
                inserePalavraEncadeado(&etext, input2);
            }
            input = -1;
        }
        else if(input == 3)
        {
            removeTextoLoopEncadeado(&ebib);
            printf("Insira o numero de textos da biblioteca: ");
            scanf("%d", &input);
            printf("Insira o numero de palavras do texto: ");
            scanf("%d", &input2);
            printf("Insira o numero de letras da palavra: ");
            scanf("%d", &input3);
            for(x = 0; x < input; x++)
            {
                insereTextoEncadeado(&ebib, input2, input3);
            }
            input = -1;
        }
        else if(input == 4)
        {
            //removeLetraEncadeada(&eword);
            removeLetraLoopEncadeada(&eword);
        }
        else if(input == 5)
        {
            removePalavraLoopEncadeado(&etext);
        }
        else if(input == 6)
        {
            removeTextoLoopEncadeado(&ebib);
        }
        else if(input == 7)
        {
            printf("Imprimindo Palavra\n");
            imprimePalavraEncadeada(&eword);
            if(eword.tamanho != 0)
            {
                printf("\n");
            }
            tamanhoPalavraEncadeada(&eword);
            system("pause");
        }
        else if(input == 8)
        {
            printf("Imprimindo Texto\n");
            imprimeTextoEncadeado(&etext);
            tamanhoTextoEncadeado(&etext);
            system("pause");

        }
        else if(input == 9)
        {
            printf("Imprimindo Biblioteca\n");
            imprimeBibliotecaEncadeado(&ebib);
            tamanhoBibliotecaEncadeado(&ebib);
            system("pause");

        }
        else if(input == 10)
        {
            ordenaMenu = 1;
        }
        else if(input == 11)
        {
            return 0;
        }
        input = -1;
        }
        else
        {
        printf("|===========================|\n");
        printf("|       Menu Ordenacao      |\n");
        printf("| 0) Ordenar T. (Selecao)   |\n");
        printf("| 1) Ordenar B. (Selecao)   |\n");
        printf("| 2) Ordenar T. (QuickSort) |\n");
        printf("| 3) Ordenar B. (QuickSort) |\n");
        printf("| 4) Imprimir Texto         |\n");
        printf("| 5) Imprimir Biblioteca    |\n");
        printf("| 10) Menu funcao           |\n");
        printf("| 11) Sair do programa      |\n");
        printf("|===========================|\n\n");

        scanf("%d", &input);

        if(input == 0)
        {
            ordenaPalavraEncadeada(etext);
        }
        else if(input == 1)
        {
            ordenaTextoBib(ebib);
        }
        else if(input == 2)
        {
            printf("Texto original: \n");
            imprimeTextoEncadeado(&etext);
            int n = text.numeroPalavras;
            Ticks[0] = clock();
            x = 0;
            y = 0;
            z = etext.numeroPalavras;
            QSTextoEncadeado(&etext, 0, z-1, &x, &y);
            Ticks[1] = clock();
            printf("Texto encadeado: \n");
            imprimeTextoEncadeado(&etext);
            double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
            printf("Tempo total da CPU para organizar via selecao: %g ms\n", Tempo);
            printf("Total de Comparacoes: %d, Total de Movimentacoes: %d\n", x, y);
        }
        else if(input == 4)
        {
            printf("Imprimindo Texto\n");
            imprimeTextoEncadeado(&etext);
            tamanhoTextoEncadeado(&etext);
            system("pause");
        }
        else if(input == 5)
        {
            printf("Imprimindo Biblioteca\n");
            imprimeBibliotecaEncadeado(&ebib);
            tamanhoBibliotecaEncadeado(&ebib);
            system("pause");
        }
        if(input == 10)
        {
            ordenaMenu = 0;
        }
        else if(input == 11)
        {
            return 0;
        }

        }
       }
    }

    return 0;
}
