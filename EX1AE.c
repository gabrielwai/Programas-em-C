#define ex04

#ifdef ex01
/*
    1 - Escreva um programa que receba um vetor e o decomponha em dois outros vetores,
    um contendo as componentes de ordem ímpar e o outro contendo as componentes
    de ordem par. Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7},
    o programa deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3}.
*/
#include <stdio.h>

main()
{
    int vet[9], i=0, pares[5] /*valores pares*/, impares[4] /*valores ímpares*/, cont=0;

    printf("Digite um numero inteiro para ir preenchendo o vetor: ");
    scanf("%d",&vet[i]);

    for(i=1; i < 9; i++)
    {
        printf("\nDigite outro numero: ");
        scanf("%d",&vet[i]);
    }

    for(i=0; i < 9; i++)
    {
        if(i % 2 == 0)
        {
            pares[cont] = vet[i];
            cont +=1;
        }
        else
        {
            impares[cont-1] = vet[i];
        }
    }
    printf("\nOs vetores criados com base nos Indices sao:\nPares: = ["); cont=0;
    for(i=0; cont < 4; i++)
    {
        printf("%d, ",pares[i]);
        cont+=1;
    }   printf("%d];",pares[4]);

    printf("\nImpares = ["); cont=0;
    for(i=0; cont < 3; i++)
    {
        printf("%d, ",impares[i]);
        cont+=1;
    }   printf("%d];\n",impares[3]);
}
#endif //ex01


#ifdef ex02
/*
    2 - Escreva um programa que decomponha um vetor de inteiros em dois outros vetores,
    um contendo as componentes de valor ímpar e o outro contendo as componentes de
    valor par. Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2}.
*/
#include <stdio.h>

main()
{
    int vet[9], i=0, cont=0, quantpar=0, quantimpar=0;

    printf("Digite um numero inteiro para ir preenchendo o vetor: ");
    scanf("%d",&vet[i]);

    for(i=1; i < 9; i++)
    {
        printf("\nDigite outro numero: ");
        scanf("%d",&vet[i]);
    }
// --------------------------------------------------->> Cria os vetores ímpares e pares já com o tamanho exato que irão precisar
    for(i=0; i<9; i++)
    {
        if(vet[i] % 2 == 0)
            quantpar ++;
        else
            quantimpar ++;
    }
    int impares[quantimpar];
    int pares[quantpar];
// --------------------------------------------------->> Fim da criação dos vetores
// ---------------------------------------------------------------------------------->> Início da análise e decomposição do vetor
    for(i=0, quantpar = 0, quantimpar = 0; i < 9; i++)
    {
        if(vet[i] % 2 == 0)
        {
            pares[quantpar] = vet[i];
            quantpar += 1;
        }
        else
        {
            impares[quantimpar] = vet[i];
            quantimpar += 1;
        }
    }
// ---------------------------------------------------------------------------------->> Fim da decomposição do vetor
    printf("\nOs vetores criados com base nos valores sao:\nPares = [");

    for(i=0,cont=0; quantpar > 1; i++)
    {
        printf("%d, ",pares[i]);
        quantpar-=1;
    }   printf("%d];",pares[i]);

    printf("\nImpares = ["); cont=0;
    for(i=0; quantimpar > 1; i++)
    {
        printf("%d, ",impares[i]);
        quantimpar-=1;
    }   printf("%d];\n",impares[i]);
}
#endif // ex02

#ifdef ex03
#include <stdio.h>
main()
{
    int i, j, cont;
    char input[4];
    char matriz[7][4] = {"seg", "ter", "qua", "qui", "sex", "sab", "dom"};

    /*for(i=0;i<7;i++)
        printf("\nDia da semana: %s\n",matriz[i]);*/

    do{
        printf("Digite as primeiras tres (3) letras de um dia da semana escolhido: ");
        input[3] = 'a';    scanf("%s",&input[0]);

        if(input[3] != '\0')
            printf("\nString suporta exclusivamente tres (3) caracteres. Tente novamente.\n\n");

    }while(input[3] != '\0');

    for(i=0,j=0,cont=0;(cont < 3) && (i < 7);j++)
    {
        if(input[j] != matriz[i][j])
            {i++; j=-1; cont=0;}
        else
            cont++;
    }

    switch(i)
    {
        case 0:
            printf("\nsegunda-feira\n");
            break;

        case 1:
            printf("\nterca-feira\n");
            break;

        case 2:
            printf("\nquarta-feira\n");
            break;

        case 3:
            printf("\nquinta-feira\n");
            break;

        case 4:
            printf("\nsexta-feira\n");
            break;

        case 5:
            printf("\nsabado\n");
            break;

        case 6:
            printf("\ndomingo\n");
            break;

        default:
            printf("\nDia da semana nao identificavel.\n");
    }

}

#endif //ex03

#ifdef ex03_hash_table
// ------------------------------------- Outra Opção para a Resolução do Exercício 3 --------------------------------------------
// ---------------------- Utilizando Tabela Hash (Open Adressing) com Linear Probing para solução de colisões ------------------------------------
#include <stdio.h>
main()
{
    int representante, i, count=0;
    char input[4];
    char dia_da_semana[7][14] = {{"Sexta-feira"},
                                 {"Quinta-feira"},
                                 {"Terca-feira"},
                                 {"Sabado"},
                                 {"Segunda-feira"},
                                 {"Quarta-feira"},
                                 {"Domingo"}};
    char matriz[7][3] = {{'s','e','x','\0'},
                         {'q','u','i','\0'},
                         {'t','e','r','\0'},
                         {'s','a','b','\0'},
                         {'s','e','g','\0'},
                         {'q','u','a','\0'},
                         {'d','o','m','\0'}};

    /*for(i=0;i<7;i++)
        printf("\nDia da semana: %s\n",dia_da_semana[i]);*/

    do{
        printf("Digite as primeiras tres (3) letras de um dia da semana escolhido: ");
        input[3] = 'a';    scanf("%s",&input[0]);

        if(input[3] != '\0')
            printf("\nString suporta exclusivamente tres (3) caracteres. Tente novamente.\n\n");

    }while(input[3] != '\0');

    representante = ((int)input[0] + (int)input[1] + (int)input[2])%7;  // Calcula qual seria o espaço ideal para se alocar o dado

    for(i=0;i<3;i++) // <<< Verifica se no espaço calculado realmente está o dado desejado (se não houve qualquer colisão)
    {
        if(matriz[representante][i] != input[i])
            break;
    }

    if(i==3) // <<< Caso não haja colisão
        printf("\nO dia da semana correspondente e': %s\n",dia_da_semana[representante]);
    else // <<< Caso haja colisão
       {
            for(count=0; representante<7; representante++) // Faz uma busca linear, começando pelo índice deduzido inicialmente
            {                                              // O índice do vetor é representado pela variável "representante"
                for(i=0;i<3;i++)
                {
                    if(matriz[representante][i] != input[i])
                        {count++; break;}

                }
                if(i==3) // <<< Caso o dado for encontrado, sai do ciclo e printa na tela (fora do ciclo)
                    break;
                else if(count==7) // << Caso o valor não tenha sido encontrado em nenhum lugar depois de ter varrido todo o vetor
                {
                    printf("\nDia da semana incompativel.\n");
                    return 0;
                }
                if(representante + 1 > 6) //<<Volta do início do vetor para continuar a busca caso já tenha chegado ao final dele
                    representante = -1;
            }

            printf("\nO dia da semana correspondente e': %s\n",dia_da_semana[representante]);
       }
}
#endif //ex03_hash_table

#ifdef ex04

#include <stdio.h>
#include <math.h>
main()
{
    int cont=0, c=0;
    double x, y;
    //unsigned int acumulador=0, c=0;
    double n, n_original;

    do{
        printf("Digite um numero para se calcular a soma dos algarismos de seu fatorial: ");
        scanf("%lf",&n); n_original = n;

        if(n<0)
            printf("\nDigite apenas valores positivos. Tente novamente.\n");
    }while(n<0);


    printf("\n%.lf! = ",n);

    for(cont=(n-1);cont > 0;cont--)
    {
        n *= (n_original - cont);
    }   printf("%.lf\n",n);

    n_original = n;
    cont=0;


    while(n_original/10 > 1)
    {
        n_original /= 10;
        cont += 1;
    }
    cont+=1;
// "n_original" passa a ser a partir de agora o acumulador dos algarismos que devem ser somados.
    for(n_original=0, c=0; cont > 0; cont --) //aplicação da fórmula: (n-[divisão_inteira_de(n/10^cont)*10^cont])/10^cont-1
    {                                         //repetidas vezes, diminuindo o valor de "cont" a cada repetição. A quantidade de
        x = n;                                //repetições é igual ao Nº de algarismos do fatorial do N° digitado.
        y = n;

        for(c=0;c<cont;c++)
        {
            x /= 10; printf("\tX / 10= %lf\n",x);
        }

        if(floor(x) == x + 1)
            x = floor(x) - 1;
        else
            x = floor(x);   printf("\n Divisao inteira de: (x // 1) = %lf\n",x);

        for(c=0;c<cont;c++)
        {
            x *= 10;  printf("\tx * 10= %.lf\n",x);
        }

        y -= x;  printf("\nN - [(N/10)*10] = %.lf\ty = y - x\n",y);

        for(c=0;c+1<cont;c++)
        {
            y /= 10;    printf("\n(N - (N/10)*10)/10 = %lf\ty / 10\n",y);
        }

        if(floor(y) == y + 1)
            {y = floor(y) - 1;}
        else
            y = floor(y);   printf("\n Divisao inteira de: (y // 1) = %lf\n",y);

        n_original += y;
    }

    printf("\nSoma dos algarismos de %.lf = %.lf\n",n, n_original);
}

#endif // ex04

#ifdef ex05

#include <stdio.h>
main()
{
    char soma1(char palavra[]);
    char palavra[51];
    int verificador = 0, cont;

    do{
        printf("Digite uma string de no maximo 50 caracteres: ");
        gets(palavra);

        for(cont=0;cont < 51;cont++)
        {
            if(palavra[cont] == '\0')
                {verificador = 1; break;}
        }

        if(verificador == 0)
            printf("\nMaximo de 50 caracteres. Tente novamente.\n");

    }while(verificador == 0);

    printf("\nString Inicial = %s\n",palavra);

    soma1(palavra);

    printf("\nString Resultante = %s\n",palavra);
}

char soma1(char palavra[])
{
    int i;

    for(i=0;palavra[i] != '\0';i++)
        palavra[i] ++;

    //return palavra[0];
}
#endif // ex05
