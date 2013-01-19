#include <stdio.h>
#include <windows.h>


typedef struct 
{
	int num_livro;
	char tema[60];	
    char nome[60];
    char autor[60];
    char editora[60];			
	int disponibilidade;	
    int estado;	
} livro;
typedef struct 
{
	int num_req;
	int num_livro;
	int num_uti;
	char data_req;
	char data_ent;
	int ativo;		
} requisicao;
typedef struct 
{
	int num_uti;
	char email[100];
	char pass[21];
	char nome[50];
    int ativo;		
} utilizador;


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



//administrador
 void menu_loginadmin (requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls"); 
     char op;
     int calen[12][31]; 
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |_________Nome___________|_|                       |");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |________Password________|_|                       |");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |_______Confirmar________|_|______Pressione_1______|");
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
     gotoxy(1,20); printf ("     |________________________|_|_______________________|");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
     fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
            case '1': menu_admin(requi, user, liv); break;
            case '0': menu_principal(calen, requi, user, liv); break;
            //default: menu_principal(calen, requi, user, liv); break; 
     }
     
     
     getch();
     
}    
     
     
//administrador
int menu_admin (requisicao *requi, utilizador *user, livro *liv)
{
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
     gotoxy(1,18); printf ("     |                        |_|                       |");
     gotoxy(1,19); printf ("     |                        |_|                       |");
     gotoxy(1,20); printf ("     |________________________|_|_______________________|");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
     fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
            case '1': menu_novasreq(requi); break;
            case '2': menu_inserirlivro(liv); break;
            case '3': menu_apagarlivro(liv); break;
            case '4': menu_atualizarlivros(liv); break;
            case '5': menu_entregalivros(liv, requi); break;
            case '6': menu_gestaouti(user); break;
            case '0': menu_loginadmin(requi, user, liv); break;
     }
     
     
     getch();
     
}

//administrador
int menu_novasreq(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen[12][31];  
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
     gotoxy(1,21); printf ("      |            |       |               |          |            |");
     gotoxy(1,22); printf ("      |____________|_______|_______________|__________|____________|");
     fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
     
            case '0': menu_admin(requi, user, liv); break;
     }
     
     
     getch();
     
     
}
//admin
int menu_inserirlivro(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen[12][31]; 
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
     gotoxy(1,13); printf ("     |____Ano_de_Publicacao___|_|                       |");
     gotoxy(1,14); printf ("     |                        |_|                       |");
     gotoxy(1,15); printf ("     |_______Confirmar________|_|______Pressione_1______|");
     gotoxy(1,16); printf ("     |                        |_|                       |");
     gotoxy(1,17); printf ("     |_________Voltar_________|_|______Pressione_0______|");
     gotoxy(1,18); printf ("     |                        |_|                       |");
     gotoxy(1,19); printf ("     |                        |_|                       |");
     gotoxy(1,20); printf ("     |________________________|_|_______________________|");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
     fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
     
            case '0': menu_admin(requi, user, liv); break;
     }
     
     
     getch();
} 
//admin
int menu_apagarlivro(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen[12][31];  
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |______APAGAR_LIVRO:_____|_|                       |");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |______Nome_do_Livro_____|_|                       |");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |_____Numero_doLivro_____|_|                       |");
     gotoxy(1,8); printf ("     |                        |_|                       |");
     gotoxy(1,9); printf ("     |_______Confirmar_________|_|______Pressione_1______|");
     gotoxy(1,10); printf ("     |                        |_|                       |");
     gotoxy(1,11); printf ("     |________Voltar__________|_|______Pressione_0______|");
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
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
     
            case '0': menu_admin(requi, user, liv); break;
     }
     
     
     getch();
}  
//admin
int menu_atualizarlivros(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen[12][31];  
     gotoxy(1,1); printf ("       _____________________________________________________________________");
     gotoxy(1,2); printf ("      |    ATUALIZAR LIVROS - Confirmar: Pressione 1, Voltar: Pressione 0   |");
     gotoxy(1,3); printf ("      |_____________________________________________________________________|");
     gotoxy(1,4); printf ("      |  Nome Livro  | NoLivro |     Autor     |  Editora |Ano Public  |Disp|");
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
     gotoxy(1,20); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,21); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,22); printf ("      |______________|_________|_______________|__________|____________|____|");
     fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
     
            case '0': menu_admin(requi, user, liv); break;
     }
     
     
     getch();
}  

//admin
int menu_entregalivros(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen[12][31];  
     gotoxy(1,1); printf ("       ______________________________________________________________________");
     gotoxy(1,2); printf ("      |      ENTREGA LIVROS - Confirmar: Pressione 1, Voltar: Pressione 0    |");
     gotoxy(1,3); printf ("      |______________________________________________________________________|");
     gotoxy(1,4); printf ("      |  Nome Livro  | NoLivro |     Autor    |  Editora | Ano Public |Estado|");
     gotoxy(1,5); printf ("      |--------------|---------|--------------|----------|------------|------| ");
     gotoxy(1,6); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,7); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,8); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,9); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,10); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,11); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,12); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,13); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,14); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,15); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,16); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,17); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,18); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,19); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,20); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,21); printf ("      |              |         |              |          |            |      |");
     gotoxy(1,22); printf ("      |______________|_________|______________|__________|____________|______|");
     fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
     
            case '0': menu_admin(requi, user, liv); break;
     }
     
     
     getch();
     
}    
//admin
int menu_gestaouti(requisicao *requi, utilizador *user, livro *liv)
{

     system ("cls");
     char op;
     int calen[12][31];  
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |_GESTAO_DE_UTILIZADORES:|_|                       |");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |___Nome_de_Utilizador___|_|                       |");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |__Numero_de_Utilizaodr__|_|                       |");
     gotoxy(1,8); printf ("     |                        |_|                       |");
     gotoxy(1,9); printf ("     |________Eliminar________|_|______Pressione_1______|");
     gotoxy(1,10); printf ("     |                        |_|                       |");
     gotoxy(1,11); printf ("     |_________Voltar_________|_|______Pressione_0______|");
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
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
     
            case '0': menu_admin(requi, user, liv); break;
     }
     
     
     getch();
     
     

     
}    


//user
int menu_utilizador(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen [12] [31];  
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |_________Entrar_________|_|______Pressione_1______|");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |________Registar________|_|______Pressione_2______|");
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
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
            case '1': menu_entrar(requi, user, liv); break;
            case '2': menu_registar(requi, user, liv); break;
            case '0': menu_principal(calen, requi, user, liv); break;
            //default: menu_principal(calen, requi, user, liv); break; 
     }
     
     
     getch();
     
}   

//user
int menu_entrar(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen [12] [31];   
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |_________Nome___________|_|                       |");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |________Password________|_|                       |");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |_______Confirmar________|_|______Pressione_1______|");
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
     fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
     switch (op)
     {
            case '1': menu_entraropc(requi, user, liv); break;
            case '0': menu_utilizador(requi, user, liv); break;
            //default: menu_principal(calen, requi, user, liv); break; 
     }
     
     
     getch();
    
}    
//user
int menu_registar(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
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
     gotoxy(1,16); printf ("     |                        |_|                          |");
     gotoxy(1,17); printf ("     |                        |_|                          |");
     gotoxy(1,18); printf ("     |                        |_|                          |");
     gotoxy(1,19); printf ("     |                        |_|                          |");
     gotoxy(1,20); printf ("     |________________________|_|__________________________|");
     gotoxy(1,21); printf ("     |________________________/ \\__________________________|");
     fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
      switch (op)
     {
            case '1': menu_entrar(requi, user, liv); break;
            case '0': menu_utilizador(requi, user, liv); break;
            //default: menu_principal(calen, requi, user, liv); break; 
     }
     
     
     getch();
     }

//user
int menu_entraropc(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen [12] [31];  
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
     gotoxy(20,10); scanf("%c", &op);
      switch (op)
     {
            case '1': menu_reqlivros(requi, user, liv); break;
            case '2': menu_livrosreq(requi, user, liv); break;
            case '0': menu_entrar(requi, user, liv); break;
            //default: menu_principal(calen, requi, user, liv); break; 
     }
     
     
     getch();
     
     
}   
//user
int menu_reqlivros(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen [12] [31];  
     gotoxy(1,1); printf ("      ________________________   _______________________");
     gotoxy(1,2); printf ("     |                        \\_/                       |");
     gotoxy(1,3); printf ("     |____REQUISITAR_LIVROS___|_|                       |");
     gotoxy(1,4); printf ("     |                        |_|                       |");
     gotoxy(1,5); printf ("     |_____Pesquisar_por:_____|_|                       |");
     gotoxy(1,6); printf ("     |                        |_|                       |");
     gotoxy(1,7); printf ("     |__________Tema__________|_|______Pressione_1______|");
     gotoxy(1,8); printf ("     |                        |_|                       |");
     gotoxy(1,9); printf ("     |__________Nome__________|_|______Pressione_2______|");
     gotoxy(1,10); printf ("     |                        |_|                       |");
     gotoxy(1,11); printf ("     |_________Autor__________|_|______Pressione_3______|");
     gotoxy(1,12); printf ("     |                        |_|                       |");
     gotoxy(1,13); printf ("     |_________Editora________|_|______Pressione_4______|");
     gotoxy(1,14); printf ("     |                        |_|                       |");
     gotoxy(1,15); printf ("     |_________Voltar_________|_|______Pressione_0______|");
     gotoxy(1,16); printf ("     |                        |_|                       |");
     gotoxy(1,17); printf ("     |                        |_|                       |");
     gotoxy(1,18); printf ("     |                        |_|                       |");
     gotoxy(1,19); printf ("     |                        |_|                       |");
     gotoxy(1,20); printf ("     |________________________|_|_______________________|");
     gotoxy(1,21); printf ("     |________________________/ \\_______________________|");
     fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
      switch (op)
     {
            
            
            case '0': menu_entraropc(requi, user, liv); break;
            //default: menu_principal(calen, requi, user, liv); break; 
     }
     
     
     getch();
}    

//user
int menu_livrosreq(requisicao *requi, utilizador *user, livro *liv)
{
     system ("cls");
     char op;
     int calen [12] [31];  
     gotoxy(1,1); printf ("       _____________________________________________________________________");
     gotoxy(1,2); printf ("      |             LIVROS REQUISITADOS - Voltar: Pressione 0               |");
     gotoxy(1,3); printf ("      |_____________________________________________________________________|");
     gotoxy(1,4); printf ("      |  Nome Livro  |  Tema   |     Autor     |  Editora |Ano Public  |Dias|");
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
     gotoxy(1,20); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,21); printf ("      |              |         |               |          |            |    |");
     gotoxy(1,22); printf ("      |______________|_________|_______________|__________|____________|____|");
    fflush(stdin);
     gotoxy(20,10); scanf("%c", &op);
      switch (op)
     {
            
            
            case '0': menu_entraropc(requi, user, liv); break;
            //default: menu_principal(calen, requi, user, liv); break; 
     }
     
     
     getch();
}    

//dois
int menu_principal(int calen[12][31], requisicao *requi, utilizador *user, livro *liv)
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
        gotoxy(30,11); scanf ("%c", &op);
        switch (op)
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
     int i, calen[12][31];
     requisicao requi[1000];
     utilizador user[100];
     livro liv[100];
     system ("cls");
     menu_principal (calen, requi, user, liv);  
     getch();
         
}
