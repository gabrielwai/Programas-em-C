#define ex01

#ifdef ex01
#include <stdio.h>

   /* struct dados
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

    */
main()
{
    char continuar = 'a', *pchar, _char;
    unsigned char *puchar, _uchar;
    int cont, rodadas, *pint, _int;
    long *plong, _long;
    unsigned int *puint, _uint;
    unsigned long *pulong, _ulong;
    float *pfloat, _float;
    double *pdouble, _double;

    pchar = &_char;
    puchar = &_uchar; pint = &_int; plong = &_long; puint = &_uint;
    pulong = &_ulong; pfloat = &_float; pdouble = &_double;

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
    scanf("%lf",&_double);  printf("%Double = %lf",_double);

    printf("\nDigite um valor unsigned char: ");
    scanf("%u",&_uchar);    printf("%Double = %lf",_double);

    printf("\nDigite um valor unsigned int: ");
    scanf("%u",&_uint); printf("%Double = %lf",_double);

    printf("\nDigite um valor unsigned long: ");
    scanf("%lu",&_ulong);   printf("%Double = %lf",_double);

    printf("\nDigite um valor character: ");
    getchar(); _char = getchar();   printf("%Double = %lf",_double);

    //printf("\n%c, %d, %ld, %f, %lf \n%c, %u, %lu,\n\n",_char, _int, _long, _float, _double, _uchar, _uint, _ulong);

    printf("  ");
    for(cont=10;cont<70;cont+=10)
    {
        printf("%10d",cont);
    }

    printf("\n\n  ");
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

    /*printf("%-20f",*pfloat);
    printf("%-20lf",*pdouble);*/
    printf("\n            "); printf("AQUIII..."); printf("%lf",*pdouble);

    printf("%-20lf",*pdouble);
    printf("%-20f",*pfloat);

    printf("\n\nDeseja continuar? Digite 's' para 'sim' ou qualquer outra tecla para 'nao': "); getchar();
    continuar = getchar(); /*putchar(continuar);*/

    }while(continuar == 's' || continuar == 'S');
}
#endif //ex01
