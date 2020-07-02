#define ex03

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

    parquivo = fopen("contatos.txt","r");
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
        if((parquivo = fopen("contatos.txt","w"))==NULL)
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

                    for(i=0, verificador=0;i<51;i++)
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

    printf("\nDigite uma letra: "); getchar();
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

#include <stdio.h>

static struct controle
    {
        char nome[51];
        char codigo[6];
        char descricao[101];
        int quantidade;
    };

main()
{
    struct controle produto;

    //FILE *parquivo;
    char continuar;
    int menu;

    void cadastrar(struct controle *produto);
    void imprimir(struct controle *produto);
    void procurar(struct controle *produto);
    void retirada(struct controle *produto);
    void produtos_indisponiveis(struct controle *produto);

    (produto).nome[0] = '!';

    do{

    printf("Escolha uma opcao do menu: entrada de produtos(1), retirada de produtos(2), procurar por descricao(3), listar todos(4),\nprodutos nao disponiveis(5): ");
    scanf("%d",&menu);

    switch (menu)
    {
        case 1:
            cadastrar(&produto);
            break;
        case 4:
            imprimir(&produto);
            break;

        case 3:
            procurar(&produto);
            break;

        case 2:
            retirada(&produto);
            break;

        case 5:
            produtos_indisponiveis(&produto);
            break;

        default:
            printf("\nValor invalido. Podes tentar novamente.");
            getchar();
    }

    printf("\n\nDeseja continuar? Digite 's' para 'sim' ou qualquer outra tecla para 'nao': ");
    continuar = getchar(); printf("\n");

    }while(continuar == 's' || continuar == 'S');
}

void cadastrar(struct controle *produto)
{
    struct controle produto1;

    int i, verificador, contador_arquivo=0, deslocamento, cont;

    FILE *parquivo, *pcontador_arquivo;


                getchar();
                do{
                    verificador = 0;
                    printf("\nDigite o nome do produto: ");
                    gets((produto)->nome);  //fputs(produto->nome, parquivo);

                    for(i=0, verificador=0;i<51;i++)
                    {
                        if((produto)->nome[i] == '\0')
                        {
                            verificador = 1;
                            break;
                        }
                    }
                    if(verificador == 0)
                        printf("\nMaximo de 50 caracteres. Tente novamente.\n");

                }while(verificador == 0);

                do{
                    verificador = 0;    (produto)->codigo[5] = 'A';
                    printf("\nDigite o codigo do produto: ");
                    scanf("%s",(produto)->codigo);  //fputs(produto->codigo, parquivo);

                    if((produto)->codigo[5]=='\0')
                    {
                        verificador = 1;
                    }

                    if(verificador == 0)
                        printf("\nO codigo do produto deve conter exclusivamente 5 (cinco) caracteres. Tente novamente.\n");

                }while(verificador == 0);

                do{
                    getchar();
                    verificador = 0;
                    printf("\nDigite a descricao do produto: ");
                    gets(produto->descricao);   //fputs(produto->descricao, parquivo);

                    for(i=0;i<101;i++)
                    {
                        if(produto->descricao[i]=='\0')
                        {
                            verificador = 1;    //printf("\nDescricao aprovada.\n");
                            break;
                        }
                    }

                    if(verificador==0)
                        printf("\nMaximo de 100 caracteres. Tente novamente.\n");

                }while(verificador == 0);


                    do{
                        verificador=1;
                        printf("\nDigite uma quantidade (valor inteiro): ");
                        scanf("%d",&(produto)->quantidade); //fputs(&produto->quantidade, parquivo);

                        if(produto->quantidade<0)
                        {
                            printf("\nQuantidade nao pode ser negativa. Tente novamente.\n");
                            verificador = 0;
                        }
                    }while(verificador == 0);
        getchar();

        if((pcontador_arquivo = fopen("contador_arquivo.txt","r")) == NULL)
        {
            printf("\nErro na abertura do arquivo 'contador_arquivo'.\n");
            exit(0);
        }
        fscanf(pcontador_arquivo,"%d",&contador_arquivo);

        fclose(pcontador_arquivo);


        if((parquivo = fopen("mercadorias","r"))==NULL)
        {
            printf("\nErro na abertura do arquivo 'mercadorias'.\n");
            exit(0);
        }

        deslocamento = 0;
        for(cont=0,verificador=0; contador_arquivo>0; contador_arquivo--)
        {
            fseek(parquivo,deslocamento,0);
            fread(&produto1, sizeof(produto1),1,parquivo);


            for(i=0, verificador=1; i<50; i++)
            {
                if(produto->nome[i] != produto1.nome[i])
                {
                    verificador=0;
                    break;
                }
            }//este for serve para ver se os dois nomes sao iguais (o digitado agora pelo usuario e o já cadastrado no arquivo)

            if(verificador == 1)
            {   printf("\nProduto ja existente no estoque. Acrescentando quantidade...\n");
                fclose(parquivo);
                produto1.quantidade += produto->quantidade;
//printf("\nproduto1.quantidade += produto->quantidade : %d\n",produto1.quantidade);
                //fclose(parquivo);
                parquivo = fopen("mercadorias","r+");
                fseek(parquivo,deslocamento,0);
                fwrite(&produto1, sizeof(produto1),1,parquivo);
                fclose(parquivo);
                return;
            }
            deslocamento = (++cont) * sizeof(produto1);
        }
printf("\nCadastrando novo produto no estoque...\n");
        fclose(parquivo);

        if((parquivo = fopen("mercadorias","a"))==NULL)
        {
            printf("\nNao foi possivel abrir o arquivo de mercadorias.\n");
            exit(0);
        }


        fwrite(produto, sizeof(produto1),1,parquivo); // escreve no arquivo todos os dados que o usuário digitou na estrutura.

        fclose(parquivo);

        if((pcontador_arquivo = fopen("contador_arquivo.txt","r")) == NULL)
        {
            printf("\nErro na abertura do arquivo 'contador_arquivo'.\n");
            exit(0);
        }
        fscanf(pcontador_arquivo,"%d",&contador_arquivo);

        fclose(pcontador_arquivo);

        contador_arquivo++;

        pcontador_arquivo = fopen("contador_arquivo.txt","w");
        fprintf(pcontador_arquivo,"%d",contador_arquivo);
        fclose(pcontador_arquivo);

        /*if((pcontador_arquivo = fopen("contador_arquivo.txt","r")) == NULL)// <= teste para verificar o "novo contador" (Inicio).
        {
            printf("\nErro na abertura do arquivo 'contador_arquivo'.\n");
            exit(0);
        }
        fscanf(pcontador_arquivo,"%d",&contador_arquivo);
        printf("\nNovo contador_arquivo: %d\n",contador_arquivo);
        fclose(pcontador_arquivo);*/                                        //  <= teste para verificar o "novo contador" (Fim).
}

void imprimir(struct controle *produto)
{
    struct controle produto1;

    int contador, cont, deslocamento, contador_arquivo=0;


    FILE *parquivo, *pcontador_arquivo;

    if((pcontador_arquivo = fopen("contador_arquivo.txt","r")) == NULL)
    {
        printf("\nErro na abertura do arquivo 'contador_arquivo'.\n");
        exit(0);
    }

    fscanf(pcontador_arquivo,"%d",&contador_arquivo);                     //printf("\ncontador_arquivo = %d\n",contador_arquivo);
    fclose(pcontador_arquivo);

    parquivo=fopen("mercadorias","r");

    if(parquivo==NULL)
    {
        printf("\nO arquivo nao pode ser aberto.\n");
        exit(0);
    }

    deslocamento = 0;

    for(contador=0,cont=0; contador_arquivo>0; contador_arquivo--)
    {
        fseek(parquivo, deslocamento, 0);
        fread(produto, sizeof(produto1), 1, parquivo);

        if((produto)->nome[0]!='!')
        {
            if(contador==0)
                 printf("\nSegue abaixo o(s) produto(s) registrado(s):\n");

            printf("\nNome: %s",(produto)->nome);
            printf("\ncodigo: %s",(produto)->codigo);
            printf("\ndescricao: %s",(produto)->descricao);
            printf("\nquantidade: %d\n",produto->quantidade);
            contador = 1;
        }
        deslocamento = (++cont) * (sizeof(produto1));
    }
    if(contador == 0)
        printf("\nNao foi localizado nenhuma produto.\n");

    fclose(parquivo);
    getchar();
}

void procurar(struct controle *produto)
{
    struct controle produto1;

    char descricao[100];
    int i,verificador,deslocamento,cont,contador_arquivo;

    FILE *parquivo, *pcontador_arquivo;

    pcontador_arquivo = fopen("contador_arquivo.txt","r");
    if(pcontador_arquivo == NULL)
    {
        printf("\nNao foi possivel abrir o arquivo das mercadorias.\n");
        exit(0);
    }

    fscanf(pcontador_arquivo,"%d",&contador_arquivo);                  //printf("\ncontador_arquivo = %d\n",contador_arquivo);
    fclose(pcontador_arquivo);

    parquivo = fopen("mercadorias","r");
    if(parquivo == NULL)
    {
        printf("\nNao foi possivel abrir o arquivo das mercadorias.\n");
        exit(0);
    }

    do{
        fflush(stdin);
        printf("\nQual e' a descricao do produto que voce quer encontrar?\nDigite a descricao: ");
        gets(descricao);

        deslocamento = 0;
        for(i=0,cont=0,verificador=0; i<100 && contador_arquivo>0; i++)
        {                                                                   //printf("\ncontador_arquivo = %d\n",contador_arquivo);
            fseek(parquivo, deslocamento, 0);
            fread(produto, sizeof(produto1), 1, parquivo);

            if(descricao[i]!=(produto)->descricao[i])
            {
                deslocamento = (++cont) * sizeof(produto1);
                contador_arquivo--;
                i=-1;
            }
            else
            {
                if((produto)->descricao[i]=='\0')
                {
                    verificador = 1;
                        break;
                }
            }
        }
        if(verificador == 0)
        {
            printf("\nRegistro nao encontrado.\n");
            fclose(parquivo);
            return;
        }
    }while(verificador == 0);

    printf("\nO produto foi localizado:\n");

    printf("\nNome: %s",(produto)->nome);
    printf("\ncodigo: %s",(produto)->codigo);
    printf("\ndescricao: %s",(produto)->descricao);
    printf("\nquantidade: %d\n",produto->quantidade);
    fclose(parquivo);
}

void retirada(struct controle *produto)
{
    struct controle produto1;

    char nome[51];
    int i, verificador, deslocamento, cont, contador_arquivo, quantidade;

    FILE *parquivo, *pcontador_arquivo;

    if((pcontador_arquivo=fopen("contador_arquivo.txt","r"))==NULL)
    {
        printf("\nNao foi possivel abrir o arquivo 'contador_arquivo.txt'.\n");
        exit(0);
    }

    fscanf(pcontador_arquivo,"%d",&contador_arquivo);                     //printf("\ncontador_arquivo: %d\n",contador_arquivo);
    fclose(pcontador_arquivo);

    parquivo = fopen("mercadorias","r");
    if(parquivo==NULL)
    {
        printf("\nNao foi possivel abrir o arquivo.\n");
        exit(0);
    }

        fflush(stdin);
        printf("\nQual produto que voce quer retirar especificamente?\nDigite o nome do produto: ");
        gets(nome);
        printf("\nDigite a quantiade a ser retirada: ");
        scanf("%d",&quantidade);

        deslocamento = 0;

        for(i=0,cont=0,verificador=0; i<50 && contador_arquivo>0 ; i++)
        {
            fseek(parquivo, deslocamento, 0);
            fread(produto, sizeof(produto1), 1, parquivo);

            if(nome[i]!=(produto)->nome[i])
            {
                deslocamento = (++cont) * sizeof(produto1);
                contador_arquivo--;
                i=-1;
            }
            else if((produto)->nome[i]=='\0')
            {
                 verificador = 1;
                    break;
            }
        }
        if(verificador == 0)
        {
            printf("\nProduto nao encontrado.\n");
            fclose(parquivo);   getchar();
            return;
        }

    printf("\nProduto localizado.\n");
    fclose(parquivo);

    while(produto->quantidade - quantidade < 0 || quantidade < 0)
    {
        if(produto->quantidade - quantidade < 0)
            printf("\nNao e' possivel retirar esta quantidade (so ha %d unidades do produto), escolha um valor menor.\n",produto->quantidade);

        else if(quantidade < 0)
            printf("\nQuantidade a ser retirada nao poode ser negativa. Tente novamente.\n");

        printf("\nDigite a quantiade a ser retirada: ");
        scanf("%d",&quantidade);
    }

    parquivo = fopen("mercadorias","r+");
    fseek(parquivo, deslocamento, 0);

    produto->quantidade -= quantidade;

    fwrite(produto,sizeof(produto1),1,parquivo);
    fclose(parquivo);

    printf("\nAcabou de se retirar %d unidades do produto escolhido.\nAgora ficando:\n",quantidade);

    printf("\nNome: %s",(produto)->nome);
    printf("\ncodigo: %s",(produto)->codigo);
    printf("\ndescricao: %s",(produto)->descricao);
    printf("\nquantidade: %d\n",(produto)->quantidade);

    getchar();
}

void produtos_indisponiveis(struct controle *produto)
{
    int contador_arquivo,cont,verificador;
    unsigned deslocamento;
    struct controle produto1;

    FILE *parquivo, *pcontador_arquivo;

    pcontador_arquivo = fopen("contador_arquivo.txt","r");
    if(pcontador_arquivo == NULL)
    {
        printf("\nErro na abertura do arquivo 'contador_arquivo'.\n");
        exit(0);
    }
    fscanf(pcontador_arquivo, "%d", &contador_arquivo);
    fclose(pcontador_arquivo);

    parquivo = fopen("mercadorias","r");
    if(parquivo == NULL)
    {
        printf("\nErro na abertura do arquivo 'mercadorias'.\n");
        exit(0);
    }

    deslocamento = 0;
    for(cont=0,verificador=0; contador_arquivo>0; contador_arquivo--, deslocamento = (++cont) * sizeof(produto1))
    {                                                                   //printf("\ncontador_arquivo = %d\n",contador_arquivo);
            fseek(parquivo, deslocamento, 0);
            fread(produto, sizeof(produto1), 1, parquivo);

            if(produto->quantidade == 0)
            {
                printf("\nNome: %s",(produto)->nome);
                printf("\ncodigo: %s",(produto)->codigo);
                printf("\ndescricao: %s",(produto)->descricao);
                printf("\nquantidade: %d\n",produto->quantidade);

                verificador = 1;
            }
    }
        if(verificador == 0)
        {
            printf("\nNao ha nenhuma mercadoria indisponivel.\n");
            fclose(parquivo);
            getchar();
            return;
        }
        fclose(parquivo);
        getchar();
}

#endif // ex03

#ifdef ex04



#endif // ex04
