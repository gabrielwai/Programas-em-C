#define ex02

#ifdef ex01
#include <stdio.h>
main()
{
    char continuar = 'a', *pchar, _char;
    unsigned char *puchar, _uchar;
    int cont, rodadas, *pint, _int;
    long *plong, _long;
    unsigned int *puint, _uint;
    unsigned long *pulong, _ulong;
    float _float, *pfloat;
    double _double, *ponteiro_double;

    ponteiro_double = &_double;
    pfloat = &_float;
    pchar = &_char;
    puchar = &_uchar;
    pint = &_int; plong = &_long; puint = &_uint;
    pulong = &_ulong;

    do{

    if(continuar == 's' || continuar == 'S')
        getchar();

    printf("Digite um valor inteiro: ");
    scanf("%d",&_int);

    printf("\nDigite um valor do tipo long: ");
    scanf("%ld",&_long);

    printf("\nDigite um numero real: ");
    scanf("%f",&_float);

    printf("\nDigite um valor double: ");
    scanf("%lf",&_double);

    printf("\nDigite um valor unsigned char: ");
    scanf("%u",&_uchar);

    printf("\nDigite um valor unsigned int: ");
    scanf("%u",&_uint);

    printf("\nDigite um valor unsigned long: ");
    scanf("%lu",&_ulong);

    printf("\nDigite um valor character: ");
    getchar(); _char = getchar();

    printf("\n");
    for(cont=10;cont<70;cont+=10)
    {
        printf("%10d",cont);
    }

    printf("\n  ");
    for(cont=1, rodadas=0;rodadas<6;cont++)
    {
        printf("%d",cont);
        if(cont==9)
        {
            cont=-1;
            rodadas++;
        }
    }printf("0\n      ");

    printf("%-20d",*pint);
    printf("%-20ld",*plong);
    printf("%-20u",*puint);

    printf("\n\t\t");

    printf("%-20.2lf",*pfloat);
    printf("%.2f",*ponteiro_double);

    printf("\n\t   %-20lu",*plong);
    printf("%c",*puchar);

    printf("\n\nDeseja continuar? Digite 's' para 'sim' ou qualquer outra tecla para 'nao': "); getchar();
    continuar = getchar(); /*putchar(continuar);*/

    }while(continuar == 's' || continuar == 'S');
}
#endif //ex01

#ifdef ex02

#include <stdio.h>
main()
{
    struct dados
    {
        char nome[50], endereco[50], cidade[25], cep[9], estado[3];
    };
    struct dados cadastro[4];

    int i=0, cont, verificador;

    for(cont=0;cont<4;cont++)
    {
        cadastro[cont].cep[8] = 'A';
        cadastro[cont].estado[2] = 'A';
    }

    do{
        verificador = 0;
        printf("Digite seu nome: ");
        gets(cadastro[i].nome);

        for(cont=0;cont<50;cont++)
        {
            if(cadastro[i].nome[cont] == '\0')
            {
                verificador = 1;
                break;
            }
        }
        if(verificador == 0)
            printf("\nMaximo de 49 caracteres. Tente novamente.\n");

    }while(verificador == 0);

    do{
        verificador = 0;
        printf("\nDigite seu endereco: ");
        gets(cadastro[i].endereco);

        for(cont=0;cont<50;cont++)
        {
            if(cadastro[i].endereco[cont] == '\0')
            {
                verificador = 1;
                break;
            }
        }

        if(verificador == 0)
            printf("\nMaximo de 49 caracteres. Tente novamente.\n");

    }while(verificador == 0);

    do{
        verificador = 0;
        printf("\nDigite sua cidade: ");
        gets(cadastro[i].cidade);

        for(cont=0;cont<25;cont++)
        {
            if(cadastro[i].cidade[cont] == '\0')
            {
                verificador = 1;
                cont = 25;
            }
        }

        if(verificador == 0)
            printf("\nMaximo de 24 caracteres. Tente novamente.\n");

    }while(verificador == 0);

    do{
        verificador = 0;
        printf("\nDigite seu cep: ");
        scanf("%s",&cadastro[i].cep);

        if(cadastro[i].cep[8] == '\0')
        {
            verificador = 1;
        }

        if(verificador == 0)
            printf("\nDigite apenas 8 caracteres. Tente novamente.\n");

    }while(verificador == 0);


    do{
        verificador = 0;
        printf("\nDigite seu estado (no formato XX): ");
        scanf("%s",&cadastro[i].estado);

        if(cadastro[i].estado[2] == '\0')
        {
            verificador = 1;
        }

        if(verificador == 0)
            printf("\nMaximo de 2 caracteres. Tente novamente.\n");

    }while(verificador == 0);

    for(i=0;i<4;i++){
    printf("\nCadastro foi: %s\n",cadastro[i].nome);
    printf("\nCadastro foi: %s\n",cadastro[i].endereco);
    printf("\nCadastro foi: %s\n",cadastro[i].cidade);
    printf("\nCadastro foi: %s\n",cadastro[i].cep);
    printf("\nCadastro foi: %s\n\n",cadastro[i].estado);

    }




}

#endif // ex02
