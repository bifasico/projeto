#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


typedef struct
{
	int dia;
	int mes;
    int ano;
} data;

typedef struct
{
	int num_livro;
	char nome[60];
    char tema[60];
    char autor[60];
    char editora[60];
	int disponibilidade; //1-Disponivel 0-indisponivel
    int estado; // 1-ocupado 0- livre(pode ser preenchido
} livro;
typedef struct
{
	int num_req;
	int num_livro;
	char nome_uti[100];
	data data_req;
	data data_ent;
	char nome[100];
	int ativo; //1-nova requi 2=livro fora 0=eliminado
	int estado; // 1-ocupado 0- livre(pode ser preenchido
} requisicao;
typedef struct
{
	int num_uti;
	char pass[21];
	char nome[50];
    int ativo; //0-eliminado 1- ativo
    long int contacto;
    char morada[40];
    int estado;// 1-ocupado 0- livre(pode ser preenchido
} utilizador;


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}






int ficheiro (requisicao *requi, utilizador *user, livro *liv)
{
    int m, n, q, a;
    printf("A verificar ficheiros...\n\n"); //sleep(800);
    FILE *fc, *fr, *fu, *fl, *fa;

    //verifica se existe o ficheiro destinado para as requisicoes
    if(!(fr=fopen("requisicoes.txt","r")))
    {
        printf("Erro ao abrir o ficheiro requisicoes.txt! <Enter> para criar o ficheiro");getch();
        //cria o ficheiro das requisicoes
        fr=fopen("requisicoes.txt","w");
        printf("\nFoi criado o ficheiro requisicoes.txt com sucesso");
    }
    //le o ficheiro das requisicao
    for (n=0;n<1000;n++)
    {
      requi[n].ativo=0;
    }
    fr=fopen("requisicoes.txt","r");
    for(n=0;n<1000;n++)
        fscanf(fr,"%d\n%d\n%s\n%d\n%d\n%s\n%d\n%d\n\n", &requi[n].num_req, &requi[n].num_livro, &requi[n].nome_uti, &requi[n].data_req, &requi[n].data_ent, &requi[n].nome, &requi[n].ativo, &requi[n].estado);
    fclose(fr);
    printf("\nO ficheiro requisicoes.txt foi carregado com sucesso.\n");


    //igual para o ficheiro utilizador
    if (!(fu= fopen ("user.txt", "r")))
    {
        printf("\nErro ao abrir o ficheiro user.txt! <Enter> para criar o ficheiro");getch();
        fu=fopen("user.txt","w");
        printf("\nFoi criado o ficheiro user.txt com sucesso");
    }
    fu=fopen("user.txt","r");
    for (n=0;n<100;n++)
    {
      user[n].ativo=0;
    }
    for(q=0;q<100;q++)
         fscanf(fu,"%d\n%s\n%s\n%d\n%ld\n%s\n%d\n\n", &user[q].num_uti, &user[q].pass, &user[q].nome, &user[q].ativo, &user[q].contacto, &user[q].morada, &user[q].estado);
    fclose(fu);
    printf("\nO ficheiro user.txt foi carregado com sucesso.\n");

     //verifica se existe o ficheiro destinado para os livros
    if(!(fl=fopen("livros.txt","r")))
    {
        printf("Erro ao abrir o ficheiro livros.txt! <Enter> para criar o ficheiro");getch();
        //cria o ficheiro dos livros
        fl=fopen("livros.txt","w");
        printf("\nFoi criado o ficheiro livros.txt com sucesso");
    }
    //le o ficheiro dos livros
    fl=fopen("livros.txt","r");
    for (n=0;n<100;n++)
    {
      liv[n].estado=0;
    }

    for(m=0;m<100;m++)
        fscanf(fl,"%d\n%s\n%s\n%s\n%s\n%d\n%d\n\n", &liv[m].num_livro, liv[m].nome, &liv[m].tema, liv[m].autor, liv[m].editora, &liv[m].disponibilidade, &liv[m].estado);         //%[^\n] para ler espacos
    fclose(fl);
    printf("\nO ficheiro livros.txt foi carregado com sucesso.\n");
    getch();


}

/// FALTA ALTERAR OS TIPOS DE FICHERIRO
int gravar(requisicao *requi, utilizador *user, livro *liv)
{
    int m, n, q;
    //printf("A gravar ficheiros...\n\n"); //sleep(800);
    FILE *fr, *fu, *fl;

    //verifica se existe o ficheiro destinado para as requisicoes


    fr=fopen("requisicoes.txt","w");
    for(n=0;n<1000;n++)
        if (requi[n].ativo==0);
        {
            /// FALTA ALTERAR OS TIPOS DE FICHEIRO DE ACORDO COM
                 fprintf(fr,"%d\n%d\n%s\n%d\n%d\n%s\n%d\n%d\n\n", requi[n].num_req, requi[n].num_livro, requi[n].nome_uti, requi[n].data_req, requi[n].data_ent, requi[n].nome, requi[n].ativo, requi[n].estado);
        }

    fclose(fr);
   // printf("\nO ficheiro requisicoes.txt foi gravado com sucesso.\n");

    fu=fopen("user.txt","w");

    for(q=0;q<100;q++)
         if (user[q].ativo==1){
             fprintf(fu,"%d\n%s\n%s\n%d\n%ld\n%s\n%d\n\n", user[q].num_uti, user[q].pass, user[q].nome, user[q].ativo, user[q].contacto, user[q].morada, user[q].estado);
         }

    fclose(fu);
    //printf("\nO ficheiro user.txt foi carregado com sucesso.\n");

     //verifica se existe o ficheiro destinado para os livros

    //le o ficheiro dos livros
    fl=fopen("livros.txt","w");


    for(m=0;m<100;m++)
    {
        if (liv[m].estado==1)
        //{
             fprintf(fl,"%d\n%s\n%s\n%s\n%s\n%d\n%d\n\n", liv[m].num_livro, liv[m].nome, liv[m].tema, liv[m].autor, liv[m].editora, liv[m].disponibilidade, liv[m].estado);

        //}
    }
    fclose(fl);
    //printf("\nO ficheiro livros.txt foi carregado com sucesso.\n");

}

//user
int data_entrega (requisicao *requi, livro *liv, utilizador *user,int num , char op, char *nome1, char *nomeliv)
{
    SYSTEMTIME dataa;

    int time, dias, i, n;

    if (op=='1')
     {
                 for(i=0; i<1000; i++)
                 {
                          if(requi[i].estado!=1)
                          {
                              requi[i].num_req= rand() %9999;
                              requi[i].num_livro= num;
                              strcpy(requi[i].nome_uti,nome1);
                              requi[i].data_req.dia= dataa.wDay;
                              requi[i].data_req.mes= dataa.wMonth;
                              requi[i].data_req.ano= dataa.wYear;
                              strcpy(requi[i].nome,nomeliv);
                              requi[i].ativo=1;
                              requi[i].estado=1;
                          }
                 }
     }
     else
        menu_entraropc(requi, liv, nome1, num, nomeliv, op);
    //do{
        if (time!=dataa.wSecond){

        GetSystemTime(&dataa);

                          //printf("%d-%d-%d  \n",dataa.wDay,dataa.wMonth,dataa.wYear);

      dias=dataa.wDay+8;

    if ((dias > 31) && (dataa.wMonth>= 1 && dataa.wMonth <= 12) && (dataa.wYear >= 1900 && dataa.wYear <= 2100)) //verifica se os numeros sao validos
        {
            if ((dias > 29 && dataa.wMonth == 2) && ((dataa.wYear % 4) == 0)) //verifica se o ano e bissexto
            {
                for (n=22; n<30; n++)
                {
                           requi[i].data_ent.dia=n+8;
                           requi[i].data_ent.mes=3;
                           requi[i].data_ent.ano=dataa.wYear;
                           gravar(requi, user, liv);
                }
            }
            if (dias > 28 && dataa.wMonth == 2) //verifica o mes de feveireiro
            {
                for (n=21; n<30; n++)
                {
                           requi[i].data_ent.dia=n+8;
                           requi[i].data_ent.mes=3;
                           requi[i].data_ent.ano=dataa.wYear;
                           gravar(requi, user, liv);
                }
            }
            if ((dias > 30) && (dataa.wMonth == 4 || dataa.wMonth == 6 || dataa.wMonth == 9 || dataa.wMonth == 11)) //verifica os meses de 30 dias
            {
                for (n=23; n<30; n++)
                {
                           requi[i].data_ent.dia=n+8;
                           requi[i].data_ent.mes=dataa.wMonth+1;
                           requi[i].data_ent.ano=dataa.wYear;
                           gravar(requi, user, liv);
                }
            }
            if ((dataa.wDay > 31) && (dataa.wMonth == 1 || dataa.wMonth == 3 || dataa.wMonth == 5 || dataa.wMonth == 7 || dataa.wMonth ==8 || dataa.wMonth == 10 || dataa.wMonth == 12)) //verifica os meses de 31 dias
            {
                for (n=24; n<30; n++)
                {
                           requi[i].data_ent.dia=n+8;
                           requi[i].data_ent.mes=dataa.wMonth+1;
                           if(requi[i].data_ent.mes=13)
                              requi[i].data_ent.ano=dataa.wYear+1;
                           gravar(requi, user, liv);
                }
            }

      }
       else
           {
                requi[i].data_ent.dia=dias;
                requi[i].data_ent.mes=dataa.wMonth;
                requi[i].data_ent.ano=dataa.wYear;
                gravar(requi, user, liv);
           }
           time=dataa.wSecond;
        }
        GetSystemTime(&dataa);

    //gravar(requi, user, liv);

}



//administrador
 void menu_loginadmin (requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op, *pass="123", palavra[50];
     int num=1, nr;
     do{
        gotoxy(1,1); printf ("      ________________________   _______________________");
        gotoxy(1,2); printf ("     |                        \\_/                       |");
        gotoxy(1,3); printf ("     |_________Num____________|_|                       |");
        gotoxy(1,4); printf ("     |                        |_|                       |");
        gotoxy(1,5); printf ("     |________Password________|_|                       |");
        gotoxy(1,6); printf ("     |                        |_|                       |");
        gotoxy(1,7); printf ("     |_______Confirmar________|_|______Pressione_1______|");
        gotoxy(1,8); printf ("     |                        |_|                       |");
        gotoxy(1,9); printf ("     |_________Voltar_________|_|______Pressione_0______|");
        gotoxy(1,10); printf ("     |                        |_|                       |");
        gotoxy(1,11); printf ("     |                        |_|                       |");
        gotoxy(1,12); printf ("     |   Opcao:               |_|                       |");
        gotoxy(1,13); printf ("     |                        |_|                       |");
        gotoxy(1,14); printf ("     |                        |_|                       |");
        gotoxy(1,15); printf ("     |                        |_|                       |");
        gotoxy(1,16); printf ("     |                        |_|                       |");
        gotoxy(1,17); printf ("     |                        |_|                       |");
        gotoxy(1,18); printf ("     |                        |_|                       |");
        gotoxy(1,19); printf ("     |                        |_|                       |");
        gotoxy(1,20); printf ("     |________________________|_|_______________________|");
        gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
        gotoxy(35,3); scanf("%d", &nr); fflush(stdin);
        gotoxy(35,5); gets(palavra);
        gotoxy(17,12); op=getch();
                                  
        if (op=='1')              //Compara as stings, se o nome e a palavra pass forem iguais aos estabelecidos entao entra para o menu do admin, se nao fecha 
        {
             if (nr==num && (strcmp(palavra, pass)==0))
             {
                    //gotoxy(20,12); printf("Password e numero certo!");
                    menu_admin(requi, user, liv);
             }
             else
             {
                 gotoxy(20,12); printf("Password ou numero errado!");
             }
        }
     }while (op==0);
}


//administrador
int menu_admin (requisicao *requi, utilizador *user, livro *liv)
{
    do{
     system ("cls");
     char op;
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |____Novas_Requisicoes___|_|_______Pressione_1_____|");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |______Inserir_Livro_____|_|_______Pressione_2_____|");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |______Apagar_Livro______|_|_______Pressione_3_____|");
     gotoxy(1,8); printf ("     |                        |_|                       |");
     gotoxy(1,9); printf ("     |____Atualizar_Livros____|_|_______Pressione_4_____|");
     gotoxy(1,10); printf ("     |                        |_|                       |");
     gotoxy(1,11); printf ("     |___Entrega_de_Livros____|_|_______Pressione_5_____|");
     gotoxy(1,12); printf ("     |                        |_|                       |");
     gotoxy(1,13); printf ("     |_Gestao_de_Utilizadores_|_|_______Pressione_6_____|");
     gotoxy(1,14); printf ("     |                        |_|                       |");
     gotoxy(1,15); printf ("     |_________Sair___________|_|_______Pressione_0_____|");
     gotoxy(1,16); printf ("     |                        |_|                       |");
     gotoxy(1,17); printf ("     |                        |_|                       |");
     gotoxy(1,18); printf ("     |     Opcao:             |_|                       |");
     gotoxy(1,19); printf ("     |                        |_|                       |");
     gotoxy(1,20); printf ("     |________________________|_|_______________________|");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");

     fflush(stdin);
     gotoxy(18,18); op=getch();
     switch (op)    //Opções de entrada, ao clicar no determinado numero, vai para um determinado menu
     {
            case '1': menu_novasreq(requi, user, liv); break;
            case '2': menu_inserirlivro(liv, requi, user); break;
            case '3': menu_apagarlivro(liv, requi, user); break;
            case '4': menu_atualizarlivros(liv, requi, user); break;
            case '5': menu_entregalivros(liv, requi, user); break;
            case '6': menu_gestaouti(liv, requi, user); break;
            case '0': return; break;
     }

    }while(1);
}
//administrador
int menu_novasreq(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int i, n, k;
     gotoxy(1,1); printf ("       ____________________________________________________________");
     gotoxy(1,2); printf ("      |         NOVAS  REQUISICOES - Voltar: Pressione 0           |");
     gotoxy(1,3); printf ("      |____________________________________________________________|");
     gotoxy(1,4); printf ("      |NoRequisicao|NoLivro|Data Requisicao|Nome Livro|Utilizador  |");
     gotoxy(1,5); printf ("      |------------|-------|---------------|----------|------------|");
     gotoxy(1,6); printf ("      |            |       |               |          |            |");
     gotoxy(1,7); printf ("      |            |       |               |          |            |");
     gotoxy(1,8); printf ("      |            |       |               |          |            |");
     gotoxy(1,9); printf ("      |            |       |               |          |            |");
     gotoxy(1,10); printf ("      |            |       |               |          |            |");
     gotoxy(1,11); printf ("      |            |       |               |          |            |");
     gotoxy(1,12); printf ("      |            |       |               |          |            |");
     gotoxy(1,13); printf ("      |            |       |               |          |            |");
     gotoxy(1,14); printf ("      |            |       |               |          |            |");
     gotoxy(1,15); printf ("      |            |       |               |          |            |");
     gotoxy(1,16); printf ("      |            |       |               |          |            |");
     gotoxy(1,17); printf ("      |            |       |               |          |            |");
     gotoxy(1,18); printf ("      |            |       |               |          |            |");
     gotoxy(1,19); printf ("      |            |       |               |          |            |");
     gotoxy(1,20); printf ("      |            |       |               |          |            |");
     gotoxy(1,21); printf ("      |____________|_______|_______________|__________|____________|");
     gotoxy(1,22); printf ("      |                INSIRA O Nr DA REQUISICAO:                  |");
     gotoxy(1,23); printf ("      |                Digite a opcao:                             |");
     gotoxy(1,24); printf ("      |__________________Confirmar:Pressione_1_____________________|");
     for (i=0; i<1000; i++)
     {
         if (requi[i].ativo == 1) //Menu carrega as novas requisiçoes, quando o utilizador reqesita um livro, todos os dados referentes ao livro e o utilizador sao carregados
         {
                k++;
                gotoxy(10,6+k); printf("%d", requi[i].num_req);
                gotoxy(20,6+k); printf("%d", requi[i].num_livro);
                gotoxy(30,6+k); printf("%ld", requi[i].data_req);
                gotoxy(40,6+k); printf("%s", requi[i].nome);
                gotoxy(50,6+k); printf("%s", requi[i].nome_uti);
          }
     }
     gotoxy(50,22); scanf("%d", &n);
     fflush(stdin);
     gotoxy(40,23); op=getch();
     if (op=='0')
        menu_admin(requi, user, liv);
     else
     {
         for (i=0; i<100; i++)
             if (n==requi[i].num_req && requi[i].ativo == 1)
                requi[i].ativo=2;
                liv[i].disponibilidade=0;
                gravar(requi, user, liv);
      }
}
//admin
int menu_inserirlivro(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     int i, k, m;
     FILE *fl;
     char op;
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |_____INSERIR_LIVRO:_____|_|                       |");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |__________Nome__________|_|                       |");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |__________Tema__________|_|                       |");
     gotoxy(1,8); printf ("     |                        |_|                       |");
     gotoxy(1,9); printf ("     |__________Autor_________|_|                       |");
     gotoxy(1,10); printf ("     |                        |_|                       |");
     gotoxy(1,11); printf ("     |________Editora_________|_|                       |");
     gotoxy(1,12); printf ("     |                        |_|                       |");
     gotoxy(1,13); printf ("     |                        |_|                       |");
     gotoxy(1,14); printf ("     |                        |_|                       |");
     gotoxy(1,15); printf ("     |_________Confirmar______|_|______Precisone_1______|");
     gotoxy(1,16); printf ("     |                        |_|                       |");
     gotoxy(1,17); printf ("     |_________Voltar_________|_|______Pressione_0______|");
     gotoxy(1,18); printf ("     |                        |_|                       |");
     gotoxy(1,19); printf ("     |    Opcao:              |_|                       |");
     gotoxy(1,20); printf ("     |________________________|_|_______________________|");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
     fflush(stdin);
     for (i=0; i<=100; i++)
     {
         //Insere os livros no sistema
         if (liv[i].estado==0)
         {
            liv[i].num_livro= rand() % 9999;
            gotoxy(35,5); gets(liv[i].nome); fflush(stdin);
            gotoxy(35,7); gets(liv[i].tema); fflush(stdin);
            gotoxy(35,9); gets(liv[i].autor); fflush(stdin);
            gotoxy(35,11); gets(liv[i].editora); fflush(stdin);
            liv[i].disponibilidade=1; //fflush(stdin);
            liv[i].estado=1; //fflush(stdin);
            //gravar(requi, user, liv);
            i=101;
         }
     }    //Grava os livros no sistema se o user clicar 1 para confirmar, e nao grava se este clicar 0
     gotoxy(20,19); op=getch();
      switch (op)
     {
            case '1': {
                gravar(requi, user, liv); return; break;
            }
            case '0':{
                return; break;
            }
     }
}
//admin
int menu_apagarlivro(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     int i, n, k;
     char op;
     gotoxy(1,1); printf ("       ____________________________________________________________");
     gotoxy(1,2); printf ("      |              APAGAR LIVRO - Voltar: Pressione 0            |");
     gotoxy(1,3); printf ("      |____________________________________________________________|");
     gotoxy(1,4); printf ("      |No Livro|      Nome     |    Tema       |       Autor       |");
     gotoxy(1,5); printf ("      |--------|---------------|---------------|-------------------|");
     gotoxy(1,6); printf ("      |        |               |               |                   |");
     gotoxy(1,7); printf ("      |        |               |               |                   |");
     gotoxy(1,8); printf ("      |        |               |               |                   |");
     gotoxy(1,9); printf ("      |        |               |               |                   |");
     gotoxy(1,10); printf ("      |        |               |               |                   |");
     gotoxy(1,11); printf ("      |        |               |               |                   |");
     gotoxy(1,12); printf ("      |        |               |               |                   |");
     gotoxy(1,13); printf ("      |        |               |               |                   |");
     gotoxy(1,14); printf ("      |        |               |               |                   |");
     gotoxy(1,15); printf ("      |        |               |               |                   |");
     gotoxy(1,16); printf ("      |        |               |               |                   |");
     gotoxy(1,17); printf ("      |        |               |               |                   |");
     gotoxy(1,18); printf ("      |        |               |               |                   |");
     gotoxy(1,19); printf ("      |        |               |               |                   |");
     gotoxy(1,20); printf ("      |________|_______________|_______________|___________________|");
     gotoxy(1,21); printf ("      |   Insira o numero do livro que deseja apagar:              |");
     gotoxy(1,22); printf ("      |                     Opcao:                                 |");
     gotoxy(1,23); printf ("      |_________________Confirmar:Pressione_1______________________|");
     for (i=0; i<100; i++)
     {
         if (liv[i].estado == 1)        
         {
                k++; // Vais buscar os livros que estao no sistema, e mete no ecra
                gotoxy(10,6+i); printf("%d", liv[i].num_livro);
                gotoxy(22,6+i); printf("%s", liv[i].nome);
                gotoxy(34,6+i); printf("%s", liv[i].tema);
                gotoxy(50,6+i); printf("%s", liv[i].autor);
          }
     }    //O user escolhe o livro que quer apagar, se tiver no sistema, e o utilizador confirmar passa para o menu "Desejar Apagar", se nao volta para o menu antetior
     gotoxy(55,21); scanf("%d", &n);
     fflush(stdin);
     gotoxy(35,22); op=getch();
     if (op=='0')
        return;
     else
     {
         confirmacaoapagar(n, liv, requi, user);


    }
}
int confirmacaoapagar (int x, livro *liv, requisicao *requi, utilizador *user)
{
     system ("cls");
     char op;
     int i;
     gotoxy(1,1); printf ("       ____________________________________________________________");
     gotoxy(1,2); printf ("      |              DESEJA APAGAR O LIVRO SELECIONADO?            |");
     gotoxy(1,3); printf ("      |____________________________________________________________|");
     gotoxy(1,4); printf ("      |   SIM:Pressione 1                 NAO:Pressoine 2          |");
     gotoxy(1,5); printf ("      |                                                            |");
     gotoxy(1,6); printf ("      |                   VOLTAR:Pressione 0                       |");
     gotoxy(1,7); printf ("      |____________________________________________________________|");
     fflush(stdin);
     gotoxy(46,6); op=getch();
     if (op=='1')
     {
         for (i=0; i<100; i++)
         {
            if(liv[i].num_livro== x)
            {
                liv[i].estado=0;
                gravar(requi, user, liv);
                return 1;
            }
         }
     }
     else
           return 0;
}

//admin
int menu_atualizarlivros(requisicao *requi, utilizador *user, livro *liv)
{

    int i, k=0, n;
    char op;
    system ("cls");
     gotoxy(1,1); printf ("       _____________________________________________________________________");
     gotoxy(1,2); printf ("      |    ATUALIZAR LIVROS - Confirmar: Pressione 1, Voltar: Pressione 0   |");
     gotoxy(1,3); printf ("      |_____________________________________________________________________|");
     gotoxy(1,4); printf ("      |  Nome Livro  | NoLivro |     Autor     |  Editora |    Tema    |Disp|");                
     gotoxy(1,5); printf ("      |--------------|---------|---------------|----------|------------|----| ");
     gotoxy(1,6); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,7); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,8); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,9); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,10); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,11); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,12); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,13); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,14); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,15); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,16); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,17); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,18); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,19); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,20); printf ("      |______________|_________|_______________|__________|____________|____|");
     gotoxy(1,21); printf ("      |         Insira o numero do livro que deseja atualizar:              |");
     gotoxy(1,22); printf ("      |                             Opcao:                                  |");
     gotoxy(1,23); printf ("      |_____________________________________________________________________|");
     for (k=0;liv[k].estado == 1; k++)
     {//Imprime no ecra os livros que estao no sistema
                
                gotoxy(9,6+k); printf("%s", liv[k].nome);
                gotoxy(24,6+k); printf("%d", liv[k].num_livro);
                gotoxy(34,6+k); printf("%s", liv[k].autor);
                gotoxy(50,6+k); printf("%s", liv[k].editora);
                gotoxy(61,6+k); printf("%s", liv[k].tema);
                
                

                // O administrador selecciona o livro que quer para actualizar, e passa para o menu actualizar livro
     }
     gotoxy(63,21); scanf("%d", &n);
     fflush(stdin);
     gotoxy(43,22); op=getch();
     if (op=='0')
       return;
     else
     {
         menu_atulivro(requi,user,liv,n);
      }


}
//admin
int menu_atulivro(requisicao *requi, utilizador *user, livro *liv, int n)
{
     system ("cls");
     char nome1[60], tema1[60], autor1[60], editora1[60];
     int i, m;
     char op;
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |_____Atualizar_LIVRO:___|_|                       |");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |__________Nome__________|_|                       |");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |__________Tema__________|_|                       |");
     gotoxy(1,8); printf ("     |                        |_|                       |");
     gotoxy(1,9); printf ("     |__________Autor_________|_|                       |");
     gotoxy(1,10); printf ("     |                        |_|                       |");
     gotoxy(1,11); printf ("     |________Editora_________|_|                       |");
     gotoxy(1,12); printf ("     |                        |_|                       |");
     gotoxy(1,13); printf ("     |                        |_|                       |");
     gotoxy(1,14); printf ("     |                        |_|                       |");
     gotoxy(1,15); printf ("     |_______Confirmar________|_|______Pressione_1______|");
     gotoxy(1,16); printf ("     |                        |_|                       |");
     gotoxy(1,17); printf ("     |_________Voltar_________|_|______Pressione_0______|");
     gotoxy(1,18); printf ("     |                        |_|                       |");
     gotoxy(1,19); printf ("     |        Opcao:          |_|                       |");
     gotoxy(1,20); printf ("     |________________________|_|_______________________|");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
     gotoxy(35,5); gets(nome1);
     gotoxy(35,7); gets(tema1);
     gotoxy(35,9); gets(autor1);
     gotoxy(35,11); gets(editora1);
     gotoxy(21,19); op=getch();
     printf("%s", nome1);
     if (op=='1')
     {
     for (m=0; m<100; m++)     //Copia a string nova para a string que deseja actualizar, removendo a antiga, confirmando clicando 1
     {
         i=m;
         if(liv[i].num_livro == n)
         {
             strcpy(liv[i].nome,nome1);
             strcpy(liv[i].tema,tema1);
             strcpy(liv[i].autor,autor1);
             strcpy(liv[i].editora,editora1);
             gravar(requi, user, liv);
         m=101;
         }
     }
     }
     else
        return;

}

//admin
int menu_entregalivros(requisicao *requi, utilizador *user, livro *liv)
{
 system ("cls");
     char op;
     int i, k, num, n;
     gotoxy(1,1); printf ("       ______________________________________________________________________");
     gotoxy(1,2); printf ("      |      ENTREGA LIVROS - Confirmar: Pressione 1, Voltar: Pressione 0    |");
     gotoxy(1,3); printf ("      |______________________________________________________________________|");
     gotoxy(1,4); printf ("      |  Nome Livro      | NoLivro |     Nome utilizador  |  data requisicao |");
     gotoxy(1,5); printf ("      |------------------|---------|----------------------|------------------| ");
     gotoxy(1,6); printf ("      |                  |         |                      |                  |");
     gotoxy(1,7); printf ("      |                  |         |                      |                  |");
     gotoxy(1,8); printf ("      |                  |         |                      |                  |");
     gotoxy(1,9); printf ("      |                  |         |                      |                  |");
     gotoxy(1,10); printf ("      |                  |         |                      |                  |");
     gotoxy(1,11); printf ("      |                  |         |                      |                  |");
     gotoxy(1,12); printf ("      |                  |         |                      |                  |");
     gotoxy(1,13); printf ("      |                  |         |                      |                  |");
     gotoxy(1,14); printf ("      |                  |         |                      |                  |");
     gotoxy(1,15); printf ("      |                  |         |                      |                  |");
     gotoxy(1,16); printf ("      |                  |         |                      |                  |");
     gotoxy(1,17); printf ("      |                  |         |                      |                  |");
     gotoxy(1,18); printf ("      |                  |         |                      |                  |");
     gotoxy(1,19); printf ("      |                  |         |                      |                  |");
     gotoxy(1,20); printf ("      |__________________|_________|______________________|__________________|");
     gotoxy(1,21); printf ("      |         Insira o numero do livro que deseja entregar:                |");
     gotoxy(1,22); printf ("      |                   Opcao:                                             |");
     gotoxy(1,23); printf ("      |______________________________________________________________________|");
     for (i=0; i<100; i++)
     {
         if (requi[i].ativo == 1)
         {  //Imprime os livros no ecra
                k++;
                gotoxy(10,6+k); printf("%d", requi[i].nome);
                gotoxy(20,6+k); printf("%d", requi[i].num_livro);
                gotoxy(30,6+k); printf("%d", requi[i].nome_uti);
                gotoxy(40,6+k); printf("%d", requi[i].data_req);
          }
     }    //o admin escolhe o livro que deseja dar o ok para entregar
     gotoxy(62,21); scanf("%d", &num);
     gotoxy(33,22); op=getch();
     if (op=='1')
     {
                 for(i=0; i<1000; i++)
                 {        //Se o livro constar no sistema, e for seleccionada a opção 1 de confirmar a entrega, o livro é apagado de area de requisições da area de entrega, ficando disponivel outra vez para ser requisitado
                          if(requi[i].num_livro==num)
                          {
                              requi[i].ativo=0;
                              for (n=0; n<1000; n++)
                              {   if(liv[i].num_livro==num)
                                     liv[i].disponibilidade=1;
                                     gravar(requi, user, liv);

                              }

                          }
                 }
      return;
     }
     else
        return;
     //gravar(requi, user, liv);


}
//admin
int menu_gestaouti(requisicao *requi, utilizador *user, livro *liv)
{

     system ("cls");
     char op;
     int i, k, num;
      gotoxy(1,1); printf ("       ______________________________________________________________________");
     gotoxy(1,2); printf ("      | Gestao Utilizadores - Confirmar: Pressione 1, Voltar: Pressione 0    |");
     gotoxy(1,3); printf ("      |______________________________________________________________________|");
     gotoxy(1,4); printf ("      |       Nome de utilizador      |         Numero de Utilizador         |");
     gotoxy(1,5); printf ("      |-------------------------------|--------------------------------------| ");
     gotoxy(1,6); printf ("      |                               |                                      |");
     gotoxy(1,7); printf ("      |                               |                                      |");
     gotoxy(1,8); printf ("      |                               |                                      |");
     gotoxy(1,9); printf ("      |                               |                                      |");
     gotoxy(1,10); printf ("      |                               |                                      |");
     gotoxy(1,11); printf ("      |                               |                                      |");
     gotoxy(1,12); printf ("      |                               |                                      |");
     gotoxy(1,13); printf ("      |                               |                                      |");
     gotoxy(1,14); printf ("      |                               |                                      |");
     gotoxy(1,15); printf ("      |                               |                                      |");
     gotoxy(1,16); printf ("      |                               |                                      |");
     gotoxy(1,17); printf ("      |                               |                                      |");
     gotoxy(1,18); printf ("      |                               |                                      |");
     gotoxy(1,19); printf ("      |                               |                                      |");
     gotoxy(1,20); printf ("      |_______________________________|______________________________________|");
     gotoxy(1,21); printf ("      |         Insira o numero de utilizador que deseja apagar:             |");
     gotoxy(1,22); printf ("      |                           Opcao:                                     |");
     gotoxy(1,23); printf ("      |______________________________________________________________________|");
     for(i=1; i<100; i++)
     {
              if(user[i].ativo==1)
              {                   //Imprime no ecra todos os utilizadores do sistema
                  k++;
                  gotoxy(10,6); printf("%s", user[i].nome);
                  gotoxy(50,6); printf("%d", user[i].num_uti);
              }
     }        //Administrador escolhe o numero do utilizador que deseja apagar e é passado para o menu apagar utilizador
     gotoxy(65,21); scanf("%d", num);
     gotoxy(41,22); op=getch();
     if (op!='0')
        apaga_user(user, num, liv, requi);
     else
         return;
}
//admin
int apaga_user (requisicao *requi, utilizador *user, livro *liv, int num)
{
     char op;
     int i;
     system ("cls");
     gotoxy(1,1); printf ("       ____________________________________________________________");
     gotoxy(1,2); printf ("      |              DESEJA APAGAR O UTILIZADOR SELECIONADO?       |");
     gotoxy(1,3); printf ("      |____________________________________________________________|");
     gotoxy(1,4); printf ("      |   SIM:Pressione 1                 NAO:Pressoine 2          |");
     gotoxy(1,5); printf ("      |                                                            |");
     gotoxy(1,6); printf ("      |                   VOLTAR:Pressione 0                       |");
     gotoxy(1,7); printf ("      |____________________________________________________________|");
     fflush(stdin);
     gotoxy(46,6); op=getch();
     if (op=='1')  //Se o utilizador constar no sistema, este é apagado com um simples clique no botao 1, isto se o Administrador quiser, pois pode precionar 2 para nao, ou 0 para voltar para tras
     {
         for (i=0; i<100; i++)
         {
            if(user[i].num_uti== num)          
            {
                user[i].ativo=0;
                gravar(requi, user, liv);
                return 1;
            }
         }
     }
     else
           return 0;
}




   

//UTILIZADOR!!!!!!!!
int menu_utilizador(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen [12] [31],i;
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |_________Entrar_________|_|______Pressione_1______|");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |________Registar________|_|______Pressione_2______|");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |_________Voltar_________|_|______Pressione_0______|");
     gotoxy(1,8); printf ("     |                        |_|                       |");
     gotoxy(1,9); printf ("     |                        |_|                       |");
     gotoxy(1,10); printf ("     |        Opcao:          |_|                       |");
     gotoxy(1,11); printf ("     |                        |_|                       |");
     gotoxy(1,12); printf ("     |                        |_|                       |");
     gotoxy(1,13); printf ("     |                        |_|                       |");
     gotoxy(1,14); printf ("     |                        |_|                       |");
     gotoxy(1,15); printf ("     |                        |_|                       |");
     gotoxy(1,16); printf ("     |                        |_|                       |");
     gotoxy(1,17); printf ("     |                        |_|                       |");
     gotoxy(1,18); printf ("     |                        |_|                       |");
     gotoxy(1,19); printf ("     |                        |_|                       |");
     gotoxy(1,20); printf ("     |________________________|_|_______________________|");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
     fflush(stdin);
     gotoxy(22,10); op=getch();  //apanha o char, sem precisar carregar no ENTER
     switch (op)
     {
            case '1': menu_entrar(requi, user, liv); break;    //Passa para o menu entrar se clicar 1
            case '2': menu_registar(requi, user, liv); break;  //Passa para o menu registar se clicar 2
            case '0': menu_principal(calen, requi, user, liv); break;  //Passa para o menu principal se clicar 0, ou seja, volta para tras
     }

}

//UTILIZADOR!!!!!!!!
int menu_entrar(requisicao *requi, utilizador *user, livro *liv)

{
     system ("cls");
     char nome1[50], pass1[21], op;
     int t;
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |_________Nome___________|_|                       |");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |________Password________|_|                       |");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |_______Confirmar________|_|_________ENTER_________|");
     gotoxy(1,8); printf ("     |                        |_|                       |");
     gotoxy(1,9); printf ("     |_________Voltar_________|_|______Pressione_0______|");
     gotoxy(1,10); printf ("     |                        |_|                       |");
     gotoxy(1,11); printf ("     |                        |_|                       |");
     gotoxy(1,12); printf ("     |                        |_|                       |");
     gotoxy(1,13); printf ("     |                        |_|                       |");
     gotoxy(1,14); printf ("     |                        |_|                       |");
     gotoxy(1,15); printf ("     |                        |_|                       |");
     gotoxy(1,16); printf ("     |                        |_|                       |");
     gotoxy(1,17); printf ("     |                        |_|                       |");
     gotoxy(1,18); printf ("     |                        |_|                       |");
     gotoxy(1,19); printf ("     |                        |_|                       |");
     gotoxy(1,20); printf ("     |                        |_|                       |");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
     fflush(stdin); //Limpa buffer do teclado
     gotoxy(35,3); gets(nome1);
     fflush(stdin);
     gotoxy(35,5); gets(pass1);
     for(t=0;t<=100;t++)
     {
        if((strcmp(nome1,user[t].nome)==0)&& (strcmp(pass1,user[t].pass)==0)&& strlen(nome1)!=0) //Compara as 2 strings, se estas forem iguais, entao passa para o proximo menu, se nao da erro e volta para o menu do utilizador
         {
            t=101;
            menu_entraropc(requi, user, liv, nome1);
         }

         else //if (t=100 || strlen(nome1)==0)

         {
            gotoxy(1,23); printf("Password ou Usermane Inexistente!");
            getch();
            menu_utilizador(requi, user, liv);
         }
     }
}
//UTILIZADOR!!!!!!!!
int menu_registar(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int i,k;
     int calen [12] [31];
     gotoxy(1,1); printf ("      ________________________   __________________________");
     gotoxy(1,2); printf ("     |                        \\_/                          |");
     gotoxy(1,3); printf ("     |_________Nome___________|_|                          |");
     gotoxy(1,4); printf ("     |                        |_|                          |");
     gotoxy(1,5); printf ("     |________Password________|_|                          |");
     gotoxy(1,6); printf ("     |                        |_|                          |");
     gotoxy(1,7); printf ("     |_________Morada_________|_|                          |");
     gotoxy(1,8); printf ("     |                        |_|                          |");
     gotoxy(1,9); printf ("     |________Contacto________|_|                          |");
     gotoxy(1,10); printf ("     |                        |_|                          |");
     gotoxy(1,11); printf ("     |_______Confirmar________|_|_______Pressione_1________|");
     gotoxy(1,12); printf ("     |                        |_|                          |");
     gotoxy(1,13); printf ("     |_________Voltar_________|_|_______Pressione_0________|");
     gotoxy(1,14); printf ("     |                        |_|                          |");
     gotoxy(1,15); printf ("     |                        |_|                          |");
     gotoxy(1,16); printf ("     |      Opcao:            |_|                          |");
     gotoxy(1,17); printf ("     |                        |_|                          |");
     gotoxy(1,18); printf ("     |                        |_|                          |");
     gotoxy(1,19); printf ("     |                        |_|                          |");
     gotoxy(1,20); printf ("     |________________________|_|__________________________|");
     gotoxy(1,21); printf ("     |________________________/ \\__________________________|");
     fflush(stdin);
     for(k=0;k<=100;k++)         //Guarda na array o nome, a pass, a morada, e o contacto do utilizador
     {
            i=k;
            if (user[i].ativo!=1)
            {
                 gotoxy(35,3);gets(user[i].nome);
                 fflush(stdin);
                 gotoxy(35,5); gets(user[i].pass); fflush(stdin);
                 gotoxy(35,7); gets(user[i].morada); fflush(stdin);
                 gotoxy(35,9); scanf("%ld",&user[i].contacto); fflush(stdin);
                 user[i].ativo=1;
                 gravar(requi, user, liv);
                 k=101;
            }
    }

     gotoxy(20,16); op=getch(); //se clicar 1, salta para o menu entrar já guardando os dados do registo, se clicar 0 bolta para o menu anterior
      switch (op)
     {
            case '1': menu_entrar(requi, user, liv); break;
            case '0':return ; break;

            default: return; break;
     }
}

//UTILIZADOR!!!!!!!!
int menu_entraropc(requisicao *requi, utilizador *user, livro *liv, char *nome1)
{

     system ("cls");
     char op;
     int calen [12] [31],i;
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |____Requisitar_Livros___|_|______Pressione_1______|");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |___Livros_Requisitados__|_|______Pressione_2______|");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |_________Voltar_________|_|______Pressione_0______|");
     gotoxy(1,8); printf ("     |                        |_|                       |");
     gotoxy(1,9); printf ("     |                        |_|                       |");
     gotoxy(1,10); printf ("     |                        |_|                       |");
     gotoxy(1,11); printf ("     |                        |_|                       |");
     gotoxy(1,12); printf ("     |                        |_|                       |");
     gotoxy(1,13); printf ("     |                        |_|                       |");
     gotoxy(1,14); printf ("     |                        |_|                       |");
     gotoxy(1,15); printf ("     |                        |_|                       |");
     gotoxy(1,16); printf ("     |                        |_|                       |");
     gotoxy(1,17); printf ("     |                        |_|                       |");
     gotoxy(1,18); printf ("     |                        |_|                       |");
     gotoxy(1,19); printf ("     |                        |_|                       |");
     gotoxy(1,20); printf ("     |________________________|_|_______________________|");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
     fflush(stdin);
     gotoxy(35,3); op=getch();
      switch (op)  //Se clicar 1, salta para o menu requisitar livros, se clicar 2 salta para o menu livros requisitados, se clicar 0, volta para o menu anterior
     {
            case '1': menu_reqlivros(requi, user, liv, nome1); break;
            case '2': menu_livrosreq(requi, user, liv, nome1); break;
            case '0': menu_principal(requi, user, liv); break;
            
     }
}
//UTILIZADOR!!!!!!!!
int menu_reqlivros(requisicao *requi, utilizador *user, livro *liv, char *nome1)
{
     system ("cls");
     char op;
     int i, n, l, k, dias, num, b;
     char nomeliv[30];
     int calen [12] [31];
     gotoxy(1,1); printf ("       _____________________________________________________________________");
     gotoxy(1,2); printf ("      |   LISTA DE LIVROS - Voltar: Pressione 0 - Confirmar: pressione 1    |");
     gotoxy(1,3); printf ("      |_____________________________________________________________________|");
     gotoxy(1,4); printf ("      | Nr livro | Nome Livro    |  Tema       |   Autor     |  Editora     |");
     gotoxy(1,5); printf ("      |----------|---------------|-------------|-------------|--------------| ");
     gotoxy(1,6); printf ("      |          |               |             |             |              |");
     gotoxy(1,7); printf ("      |          |               |             |             |              |");
     gotoxy(1,8); printf ("      |          |               |             |             |              |");
     gotoxy(1,9); printf ("      |          |               |             |             |              |");
     gotoxy(1,10); printf ("      |          |               |             |             |              |");
     gotoxy(1,11); printf ("      |          |               |             |             |              |");
     gotoxy(1,12); printf ("      |          |               |             |             |              |");
     gotoxy(1,13); printf ("      |          |               |             |             |              |");
     gotoxy(1,14); printf ("      |          |               |             |             |              |");
     gotoxy(1,15); printf ("      |          |               |             |             |              |");
     gotoxy(1,16); printf ("      |          |               |             |             |              |");
     gotoxy(1,17); printf ("      |          |               |             |             |              |");
     gotoxy(1,18); printf ("      |          |               |             |             |              |");
     gotoxy(1,19); printf ("      |          |               |             |             |              |");
     gotoxy(1,20); printf ("      |          |               |             |             |              |");
     gotoxy(1,21); printf ("      |          |               |             |             |              |");
     gotoxy(1,22); printf ("      |__________|_______________|_____________|_____________|______________|");
     gotoxy(1,23); printf ("      |      Insira o numero de utilizador que quer requisitar:             |");
     gotoxy(1,24); printf ("      |                           Opcao:                                    |");
     gotoxy(1,25); printf ("      |_____________________________________________________________________|");
     fflush(stdin);
     
     for(n=0; n<100; n++)
     {
              if(liv[n].disponibilidade==0 && liv[n].estado==1)
              {
                   k++;
                   gotoxy(10, 6+k); printf("%d", liv[i].num_livro);
                   gotoxy(20, 6+k); printf("%s", liv[n].nome);
                   gotoxy(30, 6+k); printf("%s", liv[l].tema);
                   gotoxy(40, 6+k); printf("%s", liv[l].autor);
                   gotoxy(50, 6+k); printf("%s", liv[l].editora);
              }
     }
     gotoxy(65,23); scanf("%d", num); fflush(stdin);
     for (b=0; b<100; b++)
     {
         if(liv[b].num_livro==num)
         {    strcpy(nomeliv, liv[b].nome);}
     }
     gotoxy(20,24);
     data_entrega(requi, liv, user, num, op, nome1, nomeliv);
    /* if (op=='1')
     {
                 for(i=0; i<1000; i++)
                 {
                          if(requi[i].estado!=1)
                          {
                              requi[i].num_req= rand() %9999;
                              requi[i].num_livro= num;
                              strcpy(requi[i].nome_uti,nome1);
                              strcpy(requi[i].nome,nomeliv);
                              requi[i].ativo=1;
                              requi[i].estado=1;
                          }
                 }
     }
     else
        menu_entraropc(requi, user, liv, nome1);
      */


     }




//UTILIZADOR!!!!!!!!
int menu_livrosreq(requisicao *requi, utilizador *user, livro *liv, char *nome1)
{
     system ("cls");
     char op;
     int i, n, l, k, dias,num;
     int calen [12] [31];
     gotoxy(1,1); printf ("       _____________________________________________________________________");
     gotoxy(1,2); printf ("      |             LIVROS REQUISITADOS - Voltar: Pressione 0               |");
     gotoxy(1,3); printf ("      |_____________________________________________________________________|");
     gotoxy(1,4); printf ("      |  Nome Livro  |  Tema       |     Autor     |  Editora     |   Dias  |");
     gotoxy(1,5); printf ("      |--------------|-------------|---------------|--------------|---------| ");
     gotoxy(1,6); printf ("      |              |             |               |              |         |");
     gotoxy(1,7); printf ("      |              |             |               |              |         |");
     gotoxy(1,8); printf ("      |              |             |               |              |         |");
     gotoxy(1,9); printf ("      |              |             |               |              |         |");
     gotoxy(1,10); printf ("      |              |             |               |              |         |");
     gotoxy(1,11); printf ("      |              |             |               |              |         |");
     gotoxy(1,12); printf ("      |              |             |               |              |         |");
     gotoxy(1,13); printf ("      |              |             |               |              |         |");
     gotoxy(1,14); printf ("      |              |             |               |              |         |");
     gotoxy(1,15); printf ("      |              |             |               |              |         |");
     gotoxy(1,16); printf ("      |              |             |               |              |         |");
     gotoxy(1,17); printf ("      |              |             |               |              |         |");
     gotoxy(1,18); printf ("      |              |             |               |              |         |");
     gotoxy(1,19); printf ("      |              |             |               |              |         |");
     gotoxy(1,20); printf ("      |              |             |               |              |         |");
     gotoxy(1,21); printf ("      |              |             |               |              |         |");
     gotoxy(1,22); printf ("      |______________|_____________|_______________|______________|_________|");
    fflush(stdin);
    for(i=0; i<100; i++)
     {
              if(strcmp(user[i].nome,nome1)==0) //Compara as duas stings, se forem iguais, entao o livro é seleccionado, se nao da erro
              {
                  for(n=0; n<1000; n++)
                  {
                           if(strcmp(requi[n].nome_uti,nome1)==0)
                           {
                               num=requi[n].num_livro;
                               for(l=0; l<100; l++)
                               {
                                        if(liv[l].num_livro==num) //Carrega os livros todos no ecra com o seu respectivo nome, tema, autor e editora
                                        {
                                           k++;
                                           gotoxy(10,6+k); printf("%s", requi[n].nome);
                                           gotoxy(20, 6+k); printf("%s", liv[l].tema);
                                           gotoxy(30, 6+k); printf("%s", liv[l].autor);
                                           gotoxy(40, 6+k); printf("%s", liv[l].editora);
                                           gotoxy(50, 6+k); printf("%s", liv[l].tema);
                                           gotoxy(60, 6+k); printf("%d", dias);
                                        }
                               }
                           }
                  }
              }
     }
     gotoxy(20,10); op=getch();
      switch (op)
     {


            case '0': menu_entraropc(requi, user, liv, nome1); break;
            //default: menu_principal(calen, requi, user, liv); break;
     }



}
//dois
int menu_principal(requisicao *requi, utilizador *user, livro *liv)
{
     char op;
     do{

        system ("cls");
        gotoxy(1,1); printf ("      ___________________________________");
        gotoxy(1,3); printf ("     |         -_-_BEM-VINDO_-_-         |");
        gotoxy(1,2); printf ("     |                                   |");
        gotoxy(1,5); printf ("     |  Login Administrador: Pressione 1 |");
        gotoxy(1,4); printf ("     |                                   |");
        gotoxy(1,7); printf ("     |  Login Utilizador: Pressione 2    |");
        gotoxy(1,6); printf ("     |                                   |");
        gotoxy(1,9); printf ("     |          Sair: Pressione 0        |");
        gotoxy(1,8); printf ("     |                                   |");
        gotoxy(1,11); printf ("     |          Qual a opcao:__          |");
        gotoxy(1,10); printf ("     |                                   |");
        gotoxy(1,12); printf ("     |                                   |");
        gotoxy(1,13); printf ("     |                                   |");
        gotoxy(1,14); printf ("     |                                   |");
        gotoxy(1,15); printf ("     |                                   |");
        gotoxy(1,16); printf ("     |                                   |");
        gotoxy(1,17); printf ("     |                                   |");
        gotoxy(1,18); printf ("     |                                   |");
        gotoxy(1,19); printf ("     |                                   |");
        gotoxy(1,20); printf ("     |___________________________________|");
        gotoxy(1,21); printf ("     (___________________________________|");
        gotoxy(30,11); op=getch();
        switch (op) //Clicando 1 passa para o menu login do administrador, se clicar 2 passa para o menu do utilizador, se clicar zero, o programa fecha
        {
            case '1': menu_loginadmin(requi, user, liv); break;
            case '2': menu_utilizador(requi, user, liv); break;
            case '0': exit(0);
        }
     }while(op!=0);
     system("pause");
     getch();
}


main ()
{
    srand(time(NULL));
     system("color 1f"); //muda a cor do backgraound do programa, neste caso alterou a cor para azul
     requisicao requi[1000]; //Carrega a array requisição
     utilizador user[100]; //Carrega a array utilizador
     livro liv[100];       //Carrega a array livro
     srand(time(NULL));
     ficheiro(requi, user, liv);
     system ("cls");
     menu_principal (requi, user, liv);

}
