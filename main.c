#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TADPalavra.h"
#include "TADTexto.h"
#include "TADBiblioteca.h"

int main()
{
    int input, input2,input3 ,x,y,z;
    int inicializado = 0;
    int ordenaMenu = 0;
    char inputLetra;
    input = -2;
    TPalavra word;
    //TPalavra* mallocWordMaster;
    TTexto text;
    TBiblioteca bib;
    //inicializaPalavra(&word);
    srand((unsigned int)time(NULL));

    printf("|========================|\n");
    printf("|     Selecao de modo    |\n");
    printf("| 0) Modo Automatico     |\n");
    printf("| 1) Modo Manual         |\n");
    printf("|========================|\n\n");

    scanf("%d", &input);
    printf("\n");

    if(input == 0)
    {
    while(input != 99)
    {
        /*#if WIN32
        system("cls");
        #endif // WIN32

        #if __linux__
        system("clear");
        #endif // __linux__*/
        if(ordenaMenu == 0)
        {
        printf("|===========================|\n");
        printf("|        Menu funcao        |\n");
        printf("| 0) Inicializar funcoes    |\n");
        printf("| 1) Criar Palavra          |\n");
        printf("| 2) Criar Texto            |\n");
        printf("| 3) Criar Biblioteca       |\n");
        printf("| 4) Remover Palavra        |\n");
        printf("| 5) Remover Texto          |\n");
        printf("| 6) Remover Biblioteca     |\n");
        printf("| 7) Imprimir Palavra       |\n");
        printf("| 8) Imprimir Texto         |\n");
        printf("| 9) Imprimir Biblioteca    |\n");
        printf("| 10) Menu Ordenacao        |\n");
        printf("| 11) Sair do programa      |\n");
        printf("|===========================|\n\n");

        scanf("%d", &input);
        if(input == 0)
        {
            if(inicializado == 1)
            {
                removeLetraLoop(&word);
                removePalavraLoop(&text);
                //removeTextoLoop(&bib);
            }
            else
            {
                printf("Digite o tamanho maximo de cada texto: ");
                scanf("%d", &input2);
                printf("Digite o tamanho maximo de cada Biblioteca: ");
                scanf("%d", &input3);
                inicializaPalavra(&word);
                inicializaTexto(&text,input2);
                //inicializaBiblioteca(&bib,input2, input3);
                inicializado = 1;
            }
        }
        else if(input == 1)
        {
            printf("==Insira o numero de letras da palavra: ");
            //getchar();
            scanf("%d", &input);
            removeLetraLoop(&word);
            for(x = 0; x < input; x++)
            {
                inputLetra = (rand() % 26) + 65;
                insereLetra(&word, inputLetra);
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
            for(x = 0; x < input; x++)
            {
                removeLetraLoop(&word);
                for(y = 0; y < input2; y++)
                {
                    inputLetra = (rand() % 26) + 65;
                    insereLetra(&word, inputLetra);
                }
                //printf("%s", word.palavra);
                inserePalavra(&text, &word);
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
            //removeTextoLoop(&bib);
            for(x = 0; x < input; x++) //Biblioteca
            {
                removePalavraLoop(&text);
                for(y = 0; y < input2; y++) //Texto
                {
                    removeLetraLoop(&word);
                    for(z = 0; z < input3; z++) //Palavra
                    {
                        inputLetra = (rand() % 26) + 65;
                        insereLetra(&word, inputLetra);
                    }
                    inserePalavra(&text, &word);
                }
                //insereTexto(&bib, &text);
            }
            input = -1;

        }
        else if(input == 4)
        {
            removeLetraLoop(&word);
        }
        else if(input == 5)
        {
            removePalavraLoop(&text);
        }
        else if(input == 6)
        {
            //removeTextoLoop(&bib);
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
            //imprimeBiblioteca(&bib);
            //tamanhoBiblioteca(&bib);
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
            ordenaPalavra(&text);
        }
        else if(input == 1)
        {
            //ordenaTexto(&bib);
        }
        else if(input == 2)
        {

        }
        else if(input == 3)
        {


        }
        else if(input == 4)
        {
            printf("Imprimindo Texto\n");
            imprimeTexto(&text);
            tamanhoTexto(&text);
            system("pause");
        }
        else if(input == 5)
        {
            printf("Imprimindo Biblioteca\n");
            //imprimeBiblioteca(&bib);
            //tamanhoBiblioteca(&bib);
            system("pause");
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

    /*if(input == 1)
    {
           while(input != -1)
    {





        scanf("%d", &input);
        if(input == 0)
        {
            inicializaPalavra(&word);
            inicializaTexto(&text);
            inicializaBiblioteca(&bib);
        }
        if(input == 1)
        {
            inputLetra = (rand() % 25) + 65;
            insereLetra(&word, inputLetra);
            //insereTexto(&bib);
        }
        if(input == 2)
        {
            getchar();
            scanf("%c", &inputLetra);
            removeLetra(&word, inputLetra);
        }
        if(input == 3)
        {
            imprimePalavra(word);
            //imprimeBiblioteca(&bib);
        }
        if(input == 4)
        {
            //tamanhoPalavra(&word);
            tamanhoBiblioteca(&bib);
        }
            //Remove texto
            printf("Digite a posicao da palavra no texto a ser removida: ");
            scanf("%d", &input);
            removePalavra(&text, input);
            input = -1;

            //Remove biblioteca
            printf("Digite a posicao do texto na biblioteca a ser removido: ");
            scanf("%d", &input);
            removeTexto(&bib, input);
            input = -1;
    }
    }*/

    return 0;
}
