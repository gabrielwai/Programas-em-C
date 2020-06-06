#define ex03

#ifdef ex01
#include <stdio.h>

    struct dados
    {
        char _char;
        int _int;
        long int _long;
        float _float;
        double _double;
        unsigned char _uchar;
        unsigned int _uint;
        unsigned long _ulong;
    };

    struct dados estrutura;

main()
{
    char continuar = 'a';
    int cont, rodadas;

    do{

    getchar();

    printf("Digite um valor character: ");
    scanf("%c",&estrutura._char);

    printf("\nDigite um valor inteiro: ");
    scanf("%d",&estrutura._int);

    printf("\nDigite um valor do tipo long: ");
    scanf("%ld",&estrutura._long);

    printf("\nDigite um numero real: ");
    scanf("%f",&estrutura._float);

    printf("\nDigite um valor double: ");
    scanf("%lf",&estrutura._double);

    printf("\nDigite um valor unsigned char: ");
    scanf("%u",&estrutura._uchar);

    printf("\nDigite um valor unsigned int: ");
    scanf("%u",&estrutura._uint);

    printf("\nDigite um valor unsigned long: ");
    scanf("%lu",&estrutura._ulong);

    printf("\n%c, %d, %ld, %f, %lf \n%c, %u, %lu,\n\n",estrutura._char, estrutura._int, estrutura._long, estrutura._float, estrutura._double,
           estrutura._uchar, estrutura._uint, estrutura._ulong);

    printf("  ");
    for(cont=10;cont<=70;cont+=10)
    {
        printf("%10d",cont);
    }

    printf("\n  ");
    for(cont=1, rodadas=0;rodadas<7;cont++)
    {
        printf("%d",cont);
        if(cont==9)
        {
            cont=-1;
            rodadas++;
        }
    }printf("0\n      ");

    printf("%-20c",estrutura._char);
    printf("%-20d",estrutura._int);
    printf("%-20l",estrutura._long);
    printf("%-20f",estrutura._float);
    printf("%-20lf",estrutura._double);
    printf("\n            ");

    printf("%-20c",estrutura._uchar);
    printf("%-20u",estrutura._uint);
    printf("%-20lu",estrutura._ulong);

    printf("\n\nDeseja continuar? Digite 's' para 'sim' ou qualquer outra tecla para 'nao': "); getchar();
    continuar = getchar(); /*putchar(continuar);*/

    }while(continuar == 's' || continuar == 'S');
}
#endif //ex01

#ifdef ex02
static struct dados{
    char nome[51];
    char endereco[51];
    char cidade[26];
    char estado[3];
    char cep[9];
};

main()
{
    struct dados cadastro[4];
    char continuar = 'a';
    int menu,novo=0,i,verificador,limite_de_cadastros=0;

    for(i=0;i<3;i++)
    {
        cadastro[i].estado[2] = '\0';
    }

    do{

    printf("Escolha uma opcao do menu: cadastrar(1), ver cadastros(2), sair(3): ");
    scanf("%d",&menu);

    switch (menu) //cadastrar(1), ver cadastros(2), sair(3)
    {
        case 1:
            if(limite_de_cadastros < 4)
            {
                getchar();
                do{
                    verificador = 0;
                    printf("\nDigite seu nome: ");
                    gets(cadastro[novo].nome);

                    for(i=0, verificador=0;i<50;i++)
                    {
                        if(cadastro[novo].nome[i] == '\0')
                        {
                            verificador = 1;
                            break;
                        }
                    }
                    if(verificador == 0)
                        printf("\nMaximo de 50 caracteres. Tente novamente.\n");

                }while(verificador == 0);

                do{
                    verificador = 0;
                    printf("\nDigite seu endereco: ");
                    gets(cadastro[novo].endereco);

                    for(i=0, verificador=0;i<50;i++)
                    {
                        if(cadastro[novo].endereco[i] == '\0')
                        {
                            verificador = 1;
                            break;
                        }
                    }
                    if(verificador == 0)
                        printf("\nMaximo de 50 caracteres. Tente novamente.\n");

                }while(verificador == 0);

                do{
                    verificador = 0;
                    printf("\nDigite seu Estado (sigla) no formato XX: ");
                    gets(cadastro[novo].estado);

                    if(cadastro[novo].estado[2] == '\0')
                    {
                        verificador = 1;
                    }

                    if(verificador == 0)
                        printf("\nDigite apenas 2 caracteres para a sigla do Estado. Tente novamente.\n");

                }while(verificador == 0);

                do{
                    verificador = 0;
                    printf("\nDigite sua cidade: ");
                    gets(cadastro[novo].cidade);

                    for(i=0, verificador=0;i<25;i++)
                    {
                        if(cadastro[novo].cidade[i] == '\0')
                        {
                            verificador = 1;
                            break;
                        }
                    }
                    if(verificador == 0)
                        printf("\nMaximo de 25 caracteres. Tente novamente.\n");

                }while(verificador == 0);

                do{
                    verificador = 0;
                    printf("\nDigite seu cep: ");
                    gets(cadastro[novo].cep);


                    if(cadastro[novo].cep[8] == '\0')
                    {
                        verificador = 1;
                        break;
                    }

                    if(verificador == 0)
                        printf("\nMaximo de 9 caracteres. Tente novamente.\n");

                }while(verificador == 0);

                novo++;
                limite_de_cadastros ++;
            }
            else
                {
                    printf("\nVoce ja fez o limite maximo de 4 (quatro) cadastros.");
                    getchar();
                }
            break;


        case 2:
            printf("\nOs cadastros registrados foram:\n");
            for(i=1;i<5;i++)
            {
                printf("\nNome: %s",cadastro[novo-i].nome);
                printf("\nEndereco: %s",cadastro[novo-i].endereco);
                printf("\nCidade: %s",cadastro[novo-i].cidade);
                printf("\nEstado: %s",cadastro[novo-i].estado);
                printf("\nCep: %s\n",cadastro[novo-i].cep);
            }
            getchar();
            break;

        case 3:
            return 0;
        default:
            printf("\nValor invalido. Podes tentar novamente.");
    }

    printf("\n\nDeseja continuar? Digite 's' para 'sim' ou qualquer outra tecla para 'nao': ");
    continuar = getchar(); printf("\n");

    }while(continuar == 's' || continuar == 'S');
}
#endif // ex02

#ifdef ex03
#include <stdio.h>
main()
{


}
#include

#endif // ex03
