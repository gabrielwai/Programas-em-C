#define ex02

// feof() => função que checa o final do arquivo (EOF)
#ifdef ex01
#include <stdio.h>
main()
{
    char continuar='s';
    char ch;
    int cont, total_de_caracteres;
    FILE *p;


    while(continuar == 's' || continuar == 'S')
    {

        total_de_caracteres=0;

        if((p = fopen("arq","w"))==NULL)
        {
            printf("\nO Arquivo nao foi localizado.");
            exit(0);
        }
        ch = 'a';
        while(ch != '0')
        {
            printf("Digite um caractere (digite o numero zero para sair): ");
            ch = getchar(); //printf("\nAqui2: %c",ch);
            getchar();

            if(ch == '0')
                 break;

            total_de_caracteres++;

            putc(ch,p);

            printf("\n");
        }
        //putc('EOF',p);
        fclose(p);

        if((p = fopen("arq","r"))==NULL)
        {
            printf("\nO Arquivo nao foi localizado.");
            exit(0);
        }
        printf("\nExibicao: ");

        /*while(p != 'EOF')
        {
            putchar(getc(p));
        }*/

        for(cont=0; total_de_caracteres!=cont; cont++)
        {
            putchar(getc(p));
        }

        printf("\n\nDeseja continuar?\nDigite 's' para 'sim' ou qualquer outra tecla para 'nao': ");
        continuar = getchar(); getchar(); printf("\n");
    }
}
#endif //ex01

#ifdef ex02

#include <stdio.h>
static struct dados
    {
        char nome[51];
        char telefone[13]; // 9 dígitos para celulares ou 8 para telefones fixos + DDD
        int aniversario[2];
    };

main()
{
    FILE *parquivo;
    struct dados cadastro[4];
    char continuar = 'a';
    int menu,i,mes,limite_de_cadastros=0;

    int dia_limite_referente_ao_mes(int mes);
    void cadastrar(struct dados *cadastro, int limite_de_cadastros);
    void imprimir(struct dados *cadastro);
    void procurar(struct dados *cadastro);
    void excluir(struct dados *cadastro);
    void letra(struct dados *cadastro);
    void aniversariante(struct dados *cadastro);

    for(i=0;i<4;i++)
    {
        (cadastro+i)->nome[0] = '!';
        (cadastro+i)->telefone[11]='0';
        (cadastro+i)->telefone[12]='0';
    }

    parquivo = fopen("contatosWai.txt","r");
    if(parquivo == NULL)
    {
        printf("\nNao foi possivel abrir o arquivo para exibir os contatos.\n");
        exit(0);
    }
    for(i=0;i<4;i++)
    {
        fread(&cadastro[i],sizeof(cadastro),1,parquivo);
    }
    fclose(parquivo);

    do{

    printf("Escolha uma opcao do menu: cadastrar(1), remover contato(2), procurar contato(3), ver contatos(4),\npesquisar por letra(5), aniversariantes(6): ");
    scanf("%d",&menu);

    switch (menu)
    {
        case 1:
            cadastrar(&cadastro[0], limite_de_cadastros);
            limite_de_cadastros++;
            break;
        case 4:
            imprimir(&cadastro[0]);
            getchar();
            break;

        case 3:
            procurar(&cadastro[0]);
            break;

        case 2:
            excluir(&cadastro[0]);
            break;

        case 5:
            letra(&cadastro[0]);
            break;

        case 6:
            aniversariante(&cadastro[0]);
            break;

        default:
            printf("\nValor invalido. Podes tentar novamente.");
    }

    printf("\n\nDeseja continuar? Digite 's' para 'sim' ou qualquer outra tecla para 'nao': ");
    continuar = getchar(); printf("\n");

    if(continuar != 's' && continuar != 'S')
    {
        if((parquivo = fopen("contatosWai.txt","w"))==NULL)
        {
            printf("\nNao foi possivel abrir o arquivo para salvar os novos contatos.\n");
            exit(0);
        }

        for(i=0;i<4;i++)
        {
            //if((cadastro+i)->nome[0]!='!')
                fwrite(&cadastro[i],sizeof(cadastro),1,parquivo);
                //fprintf(parquivo,"%s %s %d %d",(cadastro+i)->nome, (cadastro+i)->telefone, (cadastro+i)->aniversario[0], (cadastro+i)->aniversario[1]);
        }
        fclose(parquivo);
    }

    }while(continuar == 's' || continuar == 'S');
}

void cadastrar(struct dados *cadastro, int limite_de_cadastros)
{
    int i,verificador,mes;

            if(limite_de_cadastros < 4)
            {
                getchar();
                do{
                    verificador = 0;
                    printf("\nDigite seu nome: ");
                    gets((cadastro+limite_de_cadastros)->nome);

                    for(i=0, verificador=0;i<50;i++)
                    {
                        if((cadastro+limite_de_cadastros)->nome[i] == '\0')
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
                    printf("\nDigite seu telefone (digite na frente o DDD neste mesmo formato): ");
                    scanf("%s",(cadastro+limite_de_cadastros)->telefone);

                    if((cadastro+limite_de_cadastros)->telefone[3]!='9')
                    {
                        if((cadastro+limite_de_cadastros)->telefone[11] == '\0')
                        {
                            verificador = 1;
                        }
                    }
                    else
                    {

                        if((cadastro+limite_de_cadastros)->telefone[12] == '\0')
                        {
                            verificador = 1;
                        }
                    }

                    if(verificador == 0)
                        printf("\nDigite 8 caracteres alfa numericos para telefones fixos e 9 para celulares (sem contar o DDD). Tente novamente.\n");

                }while(verificador == 0);

                do{
                    printf("\nDigite a data de seu aniversario.\n");
                    printf("\nDigite um dia do mes (valor inteiro): ");
                    scanf("%d",&(cadastro+limite_de_cadastros)->aniversario[0]);

                    if((cadastro+limite_de_cadastros)->aniversario[0] > 31 || (cadastro+limite_de_cadastros)->aniversario[0] < 1)
                        printf("\nValor fora do intervalo. Tente novamente.\n\n");

                }while((cadastro+limite_de_cadastros)->aniversario[0] > 31 || (cadastro+limite_de_cadastros)->aniversario[0] < 1);

                do{
                    do{
                        printf("\nDigite um mes (valor inteiro): ");
                        scanf("%d",&(cadastro+limite_de_cadastros)->aniversario[1]);

                        mes = (cadastro+limite_de_cadastros)->aniversario[1];

                        if((cadastro+limite_de_cadastros)->aniversario[1] > 12 || (cadastro+limite_de_cadastros)->aniversario[1] < 1)
                            printf("\nValor do mes fora do intervalo (1-12). Tente novamente.\n\n");

                        else if((cadastro+limite_de_cadastros)->aniversario[0] > dia_limite_referente_ao_mes(mes))
                             printf("\nVerifique o dia com o mes digitado, valor do mes fora do intervalo permitido para o dia dado.\n");

                    }while((cadastro+limite_de_cadastros)->aniversario[0] > dia_limite_referente_ao_mes(mes));
                }while((cadastro+limite_de_cadastros)->aniversario[1] > 12 || (cadastro+limite_de_cadastros)->aniversario[1] < 1);
            getchar();
            }
            else
            {
                printf("\nVoce ja fez o limite maximo de 4 (quatro) cadastros.");
                getchar();
            }
}

void imprimir(struct dados *cadastro)
{
    int i, cont;

    for(i=0,cont=0; i<4; i++)
    {
        if((cadastro+i)->nome[0]!='!')
        {
            if(cont==0)
                 printf("\nSegue abaixo o(s) cadastro(s) registrado(s):\n");

            printf("\nNome: %s",(cadastro+i)->nome);
            printf("\nTelefone: %s",(cadastro+i)->telefone);
            printf("\nAniversario: %d/%d\n",(cadastro+i)->aniversario[0], (cadastro+i)->aniversario[1]);
            cont=1;
        }
    }
    if(cont == 0)
        printf("\nNao foi localizado nenhum cadastro.\n");
}

void procurar(struct dados *cadastro)
{
    char nome[51];
    int i,atual,verificador;

    do{
        fflush(stdin);
        printf("\nQual e' o cadastro que voce quer visualizar especificamente?\nDigite o nome: ");
        gets(nome);
        for(i=0,verificador=0,atual=0; i<50 && atual<4; i++)
        {
            if(nome[i]!=(cadastro+atual)->nome[i])
            {
                atual++;
                i=-1;
            }
            else
            {
                if((cadastro+atual)->nome[i]=='\0')
                {
                    verificador = 1;
                    break;
                }
            }
        }
        if(verificador == 0)
        {
            printf("\nRegistro nao encontrado.\n");
            return;
        }
    }while(verificador == 0);

    printf("\nO cadastro foi localizado:\n");

    printf("\nNome: %s",(cadastro+atual)->nome);
    printf("\nTelefone: %s",(cadastro+atual)->telefone);
    printf("\nAniversario: %d/%d\n",(cadastro+atual)->aniversario[0], (cadastro+atual)->aniversario[1]);
}

int dia_limite_referente_ao_mes(int mes)
{
    int dia_limite;

    if(mes % 2 != 0)
    {
        if(mes > 7)
            dia_limite = 30;
        else
            dia_limite = 31;
    }
    else
    {
        if(mes > 7)
            dia_limite = 31;
        else
        {
            dia_limite = 30;

            if(mes == 2)
                dia_limite = 28;
        }
    }
        return dia_limite;
}

void excluir(struct dados *cadastro)
{
    char nome[51];
    int i,atual,verificador;


        fflush(stdin);
        printf("\nQual e' o cadastro que voce quer excluir especificamente?\nDigite o nome: ");
        gets(nome);

        for(i=0,verificador=0,atual=0; i<50 && atual<4; i++)
        {
            if(nome[i]!=(cadastro+atual)->nome[i])
            {
                atual++;
                i=0;
            }
            else
            {
                if((cadastro+atual)->nome[i]=='\0')
                {
                    verificador = 1;
                    break;
                }
            }
        }
        if(verificador == 0)
        {
            printf("\nRegistro nao encontrado.\n");
            return;
        }


    printf("\nO cadastro a seguir acaba de ser excluido.\n");

    printf("\nNome: %s",(cadastro+atual)->nome);
    printf("\nTelefone: %s",(cadastro+atual)->telefone);
    printf("\nAniversario: %d/%d",(cadastro+atual)->aniversario[0], (cadastro+atual)->aniversario[1]);

    (cadastro+atual)->nome[0] = '!';
}

void letra(struct dados *cadastro)
{
    char letra;
    int verificador=0, atual;

    printf("\nDigite uma letra: "); //getchar();
    letra = getchar(); getchar();

        for(atual=0;atual<4;atual++)
        {
            if(letra==(cadastro+atual)->nome[0])
            {
                if(verificador != 1)
                    printf("\nO(s) contato(s) que comeca(m) com '%c' e'(sao): \n",letra);

                printf("\nNome: %s",(cadastro+atual)->nome);
                printf("\nTelefone: %s",(cadastro+atual)->telefone);
                printf("\nAniversario: %d/%d\n",(cadastro+atual)->aniversario[0], (cadastro+atual)->aniversario[1]);

                verificador = 1;
            }
        }
        if(verificador != 1)
            printf("\nNao foi encontrado nenhum contato que comece com a letra '%c'.\n",letra);
}

void aniversariante(struct dados *cadastro)
{
    int mes, atual, verificador=0;

    printf("\nDigite o mes atual (valor inteiro): ");
    scanf("%d",&mes);

    for(atual=0;atual<4;atual++)
    {
        if(mes==(cadastro+atual)->aniversario[1])
        {
            if(verificador != 1)
                printf("\nO(s) aniversariante(s) do mes e'(sao): \n");

            printf("\nNome: %s",(cadastro+atual)->nome);
            printf("\nTelefone: %s",(cadastro+atual)->telefone);
            printf("\nAniversario: %d/%d\n",(cadastro+atual)->aniversario[0], (cadastro+atual)->aniversario[1]);

            verificador = 1;
        }
    }
    if(verificador != 1)
        printf("\nNao foi encontrado nenhum contato que faca aniversario este mes.\n");

    getchar();
}
#endif // ex02

#ifdef ex03



#endif // ex03
