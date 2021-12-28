// bibliotecas Principais
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

// bibliotecas ara cores
#include <dos.h>
#include <dir.h>

//cores
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKPINK 5
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define GREEN 10
#define BLUE 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15

//Botão de setas
#define cima 72
#define baixo 80
#define BACKSPACE 8
#define tab 9
#define ENTER 13

FILE *arq;
FILE *arqu;

//Função que verifica se tem algo existente no arquivo
int get_size(const char* file_name){
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

//estrutura global para inclusao
struct cadastro{
        char documento[60], descricao[60], beneficiario[60];
        int dia, mes, ano;
        float valor;

};
//Estrutura para cadastro de usuario
 struct usuario{
        char nome[25];
        char user[25];
        char senha[25];
        char confirm_senha[25];
};


// função para fazer as cores
void SetColor(char ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
/* Função GOTOXY */
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});

     return;
}

/* Função Para criar espaçamentos */
void espacamneto(int tamanho, char codigo){
    int i;
    for(i = 0; i <= tamanho; i++)
        printf("%c", codigo);
    return;
}

/* Barrinhas laterais */
void barras(int tamanho, char codigo,int TT, int a,int a2,int z){
    int i, j;

    for(i = 0, j = z; i < tamanho; i++, j++){

        gotoxy(a,j);
        printf("%c", codigo);
        espacamneto(TT, ' ');
        gotoxy(a2,j);
        printf("%c\n", codigo);
    }
return;
}

// caixinha
void criar_caixinha(int canto1,int canto2,int canto3,int canto4,
                    int CODcima, int CODlado,int tamanho,int TT,
                    int x,int y, int y2,int a2, int z){
    z = y2 - tamanho;
    gotoxy(x,y);
    printf("%c", canto1); espacamneto(TT, CODcima); printf("%c\n", canto2);
    barras(tamanho,CODlado, TT,x,a2,z );
    gotoxy(x,y2);
    printf("%c",canto3); espacamneto(TT, CODcima); printf("%c\n", canto4);
}

// funcao para definir
void definir(int TAM_barras, int espacamento, int x_su, int  y_su, int y_infe, int xbarra_esquer){

    int z;
    int canto1 = 201;
    int canto2 = 187;
    int canto3 = 200;
    int canto4 = 188;

    int CODcima = 205;
    int CODlado = 186;
    // tamanho das barras
    int tamanho = TAM_barras;
    //espacamneto
    int TT = espacamento;
    // barras superior
    int x =  x_su ; int y =  y_su;

    // barra inferior
    int y2 = y_infe;

    // barras laterais esquerda
    int a2 = xbarra_esquer;
criar_caixinha(canto1, canto2, canto3, canto4,CODcima, CODlado, tamanho, TT,
                x,y,y2,a2,z);
}


 // interface
 void inter(){
      //borda
    SetColor(LIGHTBLUE);
    definir(33,70,3,1,35,75);
    //QUADRO
    SetColor(LIGHTBLUE);
    definir(17,45,15,5,23,62);
    //CARREGANDO
    SetColor(7);
    definir(0, 62,7, 28,31,71);
    // estilo
    definir(0,0,5,5,6,57);
    definir(0,0,7,9,10,57);
    definir(0,0,6,18,19,57);
    definir(0,0,60,2,3,57);
    definir(0,0,67,5,6,57);


// Ipay
    gotoxy(24,18);
    printf("%c", 219);

    gotoxy(25,18);
    printf("%c", 219);

    gotoxy(26,18);
    printf("%c", 219);

    gotoxy(21,18);
    printf("%c", 219);

    gotoxy(20,18);
    printf("%c", 219);

    gotoxy(19,18);
    printf("%c", 219);

    gotoxy(18,18);
    printf("%c", 219);

    gotoxy(18,19);
    printf("%c", 219);

    gotoxy(19,19);
    printf("%c", 219);

    gotoxy(20,19);
    printf("%c", 219);

    gotoxy(21,10);
    printf("%c", 219);

    gotoxy(20,10);
    printf("%c", 219);

    gotoxy(19,10);
    printf("%c", 219);

    gotoxy(18,10);
    printf("%c", 219);

    gotoxy(22,10);
    printf("%c", 219);

    gotoxy(24,10);
    printf("%c", 219);

    gotoxy(26,9);
    printf("%c", 219);

    gotoxy(25,10);
    printf("%c", 219);

    gotoxy(26,10);
    printf("%c", 219);

    gotoxy(22,11);
    printf("%c", 219);

    gotoxy(22,12);
    printf("%c", 219);

    gotoxy(22,13);
    printf("%c", 219);

    gotoxy(22,14);
    printf("%c", 219);

    gotoxy(22,15);
    printf("%c", 219);

    gotoxy(22,16);
    printf("%c", 219);

    gotoxy(22,17);
    printf("%c", 219);

    gotoxy(22,18);
    printf("%c", 219);

    gotoxy(20,9);
    printf("%c", 219);

    gotoxy(19,9);
    printf("%c", 219);

    gotoxy(18,9);
    printf("%c", 219);

    gotoxy(21,9);
    printf("%c", 219);

    gotoxy(22,9);
    printf("%c", 219);

    gotoxy(23,9);
    printf("%c", 219);

    gotoxy(24,9);
    printf("%c", 219);

    gotoxy(25,9);
    printf("%c", 219);

    gotoxy(23,10);
    printf("%c", 219);

    gotoxy(23,11);
    printf("%c", 219);

    gotoxy(23,12);
    printf("%c", 219);

    gotoxy(23,13);
    printf("%c", 219);

    gotoxy(23,14);
    printf("%c", 219);

    gotoxy(23,15);
    printf("%c", 219);

    gotoxy(23,16);
    printf("%c", 219);

    gotoxy(23,17);
    printf("%c", 219);

    gotoxy(23,18);
    printf("%c", 219);

    gotoxy(23,19);
    printf("%c", 219);

    gotoxy(22,19);
    printf("%c", 219);

    gotoxy(21,19);
    printf("%c", 219);

    int i;
    for(i = 22; i < 61; i++){
        gotoxy(i,19);
        printf("%c", 219);
    }
    int j;

    for(j = 18; j < 61; j++ ){
        gotoxy(j,19);
        printf("%c", 219);
    }
    // (p)

    gotoxy(28,9);
    printf("%c", 219);

    gotoxy(28,10);
    printf("%c", 219);

    gotoxy(28,11);
    printf("%c", 219);

    gotoxy(28,12);
    printf("%c", 219);

    gotoxy(28,13);
    printf("%c", 219);

    gotoxy(28,14);
    printf("%c", 219);

    gotoxy(28,15);
    printf("%c", 219);

    gotoxy(28,16);
    printf("%c", 219);

    gotoxy(28,17);
    printf("%c", 219);


    gotoxy(29,9);
    printf("%c", 219);

    gotoxy(30,9);
    printf("%c", 219);

    gotoxy(31,9);
    printf("%c", 219);

    gotoxy(32,9);
    printf("%c", 219);

    gotoxy(33,9);
    printf("%c", 219);


    gotoxy(34,9);
    printf("%c", 219);

    gotoxy(34,10);
    printf("%c", 219);

    gotoxy(34,11);
    printf("%c", 219);

    gotoxy(34,12);
    printf("%c", 219);

    gotoxy(34,13);
    printf("%c", 219);

    gotoxy(33,13);
    printf("%c", 219);

    gotoxy(32,13);
    printf("%c", 219);

    gotoxy(31,13);
    printf("%c", 219);

    gotoxy(30,13);
    printf("%c", 219);

    gotoxy(29,13);
    printf("%c", 219);


    // (A)


    gotoxy(37,9);
    printf("%c", 219);

    gotoxy(38,9);
    printf("%c", 219);

    gotoxy(39,9);
    printf("%c", 219);

    gotoxy(40,9);
    printf("%c", 219);

    gotoxy(41,9);
    printf("%c", 219);

    gotoxy(42,9);
    printf("%c", 219);

    gotoxy(42,10);
    printf("%c", 219);

    gotoxy(42,11);
    printf("%c", 219);

    gotoxy(42,12);
    printf("%c", 219);

    gotoxy(42,13);
    printf("%c", 219);

    gotoxy(42,14);
    printf("%c", 219);


    gotoxy(42,15);
    printf("%c", 219);

    gotoxy(42,16);
    printf("%c", 219);

    gotoxy(42,17);
    printf("%c", 219);

    gotoxy(42,17);
    printf("%c", 219);

    gotoxy(41,17);
    printf("%c", 219);

    gotoxy(40,17);
    printf("%c", 219);

    gotoxy(39,17);
    printf("%c", 219);

    gotoxy(38,17);
    printf("%c", 219);

    gotoxy(37,17);
    printf("%c", 219);

    gotoxy(37,16);
    printf("%c", 219);

    gotoxy(37,15);
    printf("%c", 219);

    gotoxy(37,14);
    printf("%c", 219);

    gotoxy(37,13);
    printf("%c", 219);

    gotoxy(38,13);
    printf("%c", 219);

    gotoxy(39,13);
    printf("%c", 219);

    gotoxy(40,13);
    printf("%c", 219);

    gotoxy(41,13);
    printf("%c", 219);

    gotoxy(43,17);
    printf("%c", 219);

    // (y)
    gotoxy(45,9);
    printf("%c", 219);

    gotoxy(46,9);
    printf("%c", 219);

    gotoxy(46,9);
    printf("%c", 219);

    gotoxy(46,10);
    printf("%c", 219);

    gotoxy(47,10);
    printf("%c", 219);

    gotoxy(47,11);
    printf("%c", 219);

    gotoxy(48,11);
    printf("%c", 219);

    gotoxy(48,12);
    printf("%c", 219);

    gotoxy(49,12);
    printf("%c", 219);

    gotoxy(49,13);
    printf("%c", 219);

    gotoxy(50,12);
    printf("%c", 219);

    gotoxy(50,12);
    printf("%c", 219);

    gotoxy(50,11);
    printf("%c", 219);

    gotoxy(51,11);
    printf("%c", 219);

    gotoxy(51,10);
    printf("%c", 219);

    gotoxy(52,10);
    printf("%c", 219);

    gotoxy(52,9);
    printf("%c", 219);

    gotoxy(53,9);
    printf("%c", 219);

    gotoxy(49,14);
    printf("%c", 219);

    gotoxy(49,15);
    printf("%c", 219);

    gotoxy(49,16);
    printf("%c", 219);

    gotoxy(49,17);
    printf("%c", 219);

    // CARREGANDO

    gotoxy(40,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(42,30);
    printf("%c", 178);

    gotoxy(38,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(8,29);
    printf("%c", 178);

    gotoxy(70,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(44,30);
    printf("%c", 178);

    gotoxy(36,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(10, 29);
    printf("%c", 178);

    gotoxy(68,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(46,30);
    printf("%c", 178);

    gotoxy(34,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(10, 29);
    printf("%c", 178);

    gotoxy(68,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(48,30);
    printf("%c", 178);

    gotoxy(32,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(12,29);
    printf("%c", 178);

    gotoxy(66,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(50,30);
    printf("%c", 178);

    gotoxy(30,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(14,29);
    printf("%c", 178);

    gotoxy(64,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(52,30);
    printf("%c", 178);

    gotoxy(28,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(16,29);
    printf("%c", 178);

    gotoxy(62,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(54,30);
    printf("%c", 178);

    gotoxy(26,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(18,29);
    printf("%c", 178);

    gotoxy(60,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(56,30);
    printf("%c", 178);

    gotoxy(24,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(20,29);
    printf("%c", 178);

    gotoxy(58,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(58,30);
    printf("%c", 178);

    gotoxy(22,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(22,29);
    printf("%c", 178);

    gotoxy(56,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(60,30);
    printf("%c", 178);

    gotoxy(20,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(24,29);
    printf("%c", 178);

    gotoxy(54,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(62,30);
    printf("%c", 178);

    gotoxy(18,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(26,29);
    printf("%c", 178);

    gotoxy(52,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(64,30);
    printf("%c", 178);

    gotoxy(16,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(28,29);
    printf("%c", 178);

    gotoxy(50,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(66,30);
    printf("%c", 178);

    gotoxy(14,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(30,29);
    printf("%c", 178);

    gotoxy(48,29);
    printf("%c",178);
    Sleep(20);

    gotoxy(68,30);
    printf("%c", 178);

    gotoxy(12,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(32,29);
    printf("%c", 178);

    gotoxy(46,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(70,30);
    printf("%c", 178);

    gotoxy(10,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(34,29);
    printf("%c", 178);

    gotoxy(44,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(8,30);
    printf("%c", 178);
    Sleep(20);

    gotoxy(36,29);
    printf("%c", 178);

    gotoxy(42,29);
    printf("%c", 178);
    Sleep(20);

    gotoxy(38,29);
    printf("%c", 178);

    gotoxy(40,29);
    printf("%c", 178);
    Sleep(20);

    definir(1,6,35,24,26,43);
    gotoxy(36, 25);
    printf("Iniciar");

    getchar();
    system("cls");

    arqu =fopen("Usuario.txt","rb");
    if(arqu == NULL){
        fclose(arqu);
        criar_usuario();
    }
    if(get_size("Usuario.txt") == 0){
        fclose(arqu);
        criar_usuario();
     }
     fclose(arqu);

    inter_Criar_entrar();
 }
 // entrar ou criar conta
void inter_Criar_entrar(){
    SetColor(LIGHTBLUE);
    //borda
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,55,10,11,30,75);

    // CAIXINHAS
    definir(3,45,15,13,17,62);

    SetColor(LIGHTBLUE);
    definir(3,10,32,3,7,44);


    definir(3,45,15,18,22,62);

    definir(1,11,61,32,34,74);

    definir(3,45,15,23,27,62);


    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");

    int i;

    // WELCOME

    gotoxy(37,5);
    printf("IpAY");

    gotoxy(19,10);
    printf("BEM VINDO (A), APROVEITE NOSSO SISTEMA IPAY!");

    // printf de criar usuario ou entrar

    gotoxy(27,15);
    printf("  ACESSAR MINHA CONTA");
    gotoxy(27,20);
    printf("ALETRAR USU%cRIO E SENHA",181);

    gotoxy(35,25);
    printf("DESLIGAR");

    int x = 25, y = 15;
    int de = 0;
    char opcao;

    while(opcao != 13) {
        gotoxy(x, y);
        printf("%c", 175);
        opcao = getch();
        if(opcao == 72) {
            if(y > 15) {
                gotoxy(x, y);
                printf(" ");
                y -= 5;
                gotoxy(x, y);
                printf("%c", 175);
                if(y == 15)
                    de = 1;
                else
                    if(y == 20)
                        de = 2;
                    else
                        if(y == 25)
                            de = 3;
                            else
                                de = 0;
            }
        }else
            if(opcao == 80) {
                if(y < 25) {
                    gotoxy(x, y);
                    printf(" ");
                    y += 5;
                    gotoxy(x, y);
                    printf("%c", 175);
                    if(y == 25)
                        de = 3;
                    else
                        if(y == 20)
                            de = 2;
                        else
                            if(y == 15)
                                de = 1;
                                else
                                    de = 0;
                }
            }else{
                if(y == 15)
                    de = 1;
            }
    }
    switch(de){
        case 1:
            entrar_com_usuario();
            break;
        case 2:
            confirmar_usuario();
            break;
        case 3:
            sair();
            break;

    }


}
void sair(){
    SetColor(WHITE);
            system("cls");
            SetColor(LIGHTBLUE);
            //borda
            definir(33,70,3,1,35,75);
            //QUADRO
            definir(0,55,10,7,28,75);
            int i;
            for(i = 1; i <= 15; i++){
            SetColor(i);
            definir(3,45,15,15,19,62);
            gotoxy(23,17);
            SetColor(WHITE);
            printf("OBRIGADO POR USAR NOSSOS SERVI%cOS",128);
            Sleep(10);
            }
            getchar();

            exit(0);
}

void criar_usuario(){
   struct usuario pop;
   char op;
   FILE *arqu;
    arqu = fopen("Usuario.txt","rb");//abre o arquivo para modo leitura
    if(arq == NULL){ //se ele nao existir executara os comandos

        arqu = fopen("Usuario.txt","wb");
    }
    fclose(arqu);

    fflush(stdin);

 arqu = fopen("Usuario.txt","ab");
    if(arqu == NULL){
        printf("Erro no arquivo\n");
        return;
    }

    SetColor(LIGHTBLUE);
    //borda
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,64,6,10,27,72);

    SetColor(WHITE);
    // caixinhas
    definir(1,40,8,11,13,18);
    definir(1,40,8,15,17,18);

    definir(1,40,8,19,21,18);
    definir(1,45,8,23,25,25);

    definir(0,30,25,7,9,57);

    //data
    SetColor(1);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");

    gotoxy(30,8);
    printf("PAINEL DE CRIAR CONTA");

    gotoxy(11,12);
    printf("NOME:");

    gotoxy(9,16);
    printf(" USU%cRIO:", 181);

    gotoxy(11,20);
    printf("SENHA:");

    gotoxy(9,24);
    printf("CONFIRMAR SENHA:");
    voltarnome:
    gotoxy(20,12);
    gets(pop.nome);
    if(pop.nome[0] <= '\0'){
        gotoxy(20,12);
        SetColor(RED);
        printf("PREENCHIMENTO OBRIGAT%cRIO",224);
        Sleep(900);
        SetColor(WHITE);
        gotoxy(20,12);
        printf("                              ");
        goto voltarnome;
    }
    fflush(stdin);

    voltaruser:
    gotoxy(20,16);
    gets(pop.user);
    if(pop.user[0]<='\0'){
        gotoxy(20,16);
        SetColor(RED);
        printf("PREENCHIMENTO OBRIGAT%cRIO",224);
        Sleep(900);
        SetColor(WHITE);
        gotoxy(20,16);
        printf("                              ");
        goto voltaruser;
    }
    fflush(stdin);

    SetColor(WHITE);
    p:
    gotoxy(20,20);
    printf("                                                ");

    gotoxy(20,20);
    char cc;
    int ii;
    obrigar:
    ii = 0;
       do{
            cc = getch();
            if(isprint(cc)) {    //Analisa se o valor da variável c é imprimivel
                pop.senha[ii] = cc;
                ii++;
                printf("*");
            }else
                if(cc == BACKSPACE && ii) {
                    pop.senha[ii] = '\0';
                    ii--;
                    printf("\b \b");
                }
        }while(cc != ENTER);
        pop.senha[ii] = '\0';
        if(pop.senha[0] <= '\0'){ //Condicao para que force o usuario a preencher a senha
            gotoxy(20,20);
            SetColor(RED);
            printf("PREENCHIMENTO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(20,20);
            printf("                              ");
            gotoxy(20,20);
            goto obrigar;
        }

        gotoxy(27,24);
        obrigar2:
        ii = 0;
        do{
            cc = getch();
            if(isprint(cc)) {    //Analisa se o valor da variável c é imprimivel
                pop.confirm_senha[ii] = cc;
                ii++;
                printf("*");
            }else
                if(cc == BACKSPACE && ii > 0) {
                    pop.confirm_senha[ii] = '\0';
                    ii--;
                    printf("\b \b");
                }
        }while(cc != ENTER);
        pop.confirm_senha[ii] = '\0';
        if(pop.confirm_senha[0]<= '\0'){ //Condicao para que force o usuario a preencher a senha
            gotoxy(27,24);
            SetColor(RED);
            printf("PREENCHIMENTO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(27,24);
            printf("                              ");
            gotoxy(27,24);
            goto obrigar2;
        }

        if(strcmp(pop.senha,pop.confirm_senha)==0){
                fwrite(&pop,sizeof(pop),1,arqu);
                fclose(arqu);
        }else{
            gotoxy(20,20);
            SetColor(RED);
            printf("Senhas Diferentes!");
            gotoxy(27,24);
            printf("Senhas Diferentes!");
            SetColor(WHITE);
            Sleep(900);
            gotoxy(27,24);
            printf("                                            ");
            goto p;
            fclose(arqu);
        }
        SetColor(WHITE);

    int k;

    definir(14,0,56,11,26,58);
     for(k = 12; k < 26; k ++){
        gotoxy(57,k);
        SetColor(RED);
        printf("%c", 219);
        Sleep(50);
     }

    SetColor(WHITE);
    definir(14,0,56,11,26,58);
    for(k = 12; k < 26; k ++){
        gotoxy(57,k);
        SetColor(YELLOW);
        printf("%c", 219);
        Sleep(50);
     }

    SetColor(WHITE);
    definir(14,0,56,11,26,58);
    for(k = 12; k < 26; k ++){
        gotoxy(57,k);
        SetColor(GREEN);
        printf("%c", 219);
        Sleep(50);
     }
    SetColor(WHITE);
    definir(0,30,25,28,30,57);
    gotoxy(30,29);
    printf("SEUS DADOS FORAM SALVOS");

    getchar();

    tela_inicial();



}


// Funcão de entrada de dados
void entrar_com_usuario(){

   struct usuario pop;
    int j;
    struct entrar{
        char user[60];
        char senha[60];

     } cade;
     char opc;
     // parcial
    SetColor(LIGHTBLUE);
    definir(33,70,3,1,35,75);
    definir(0,64,6,10,29,72);

    //CAIXINHA MENOR
    SetColor(WHITE);
    definir(3,35,25,15,19,35);

    //Caixinha de Menu do usuario
    SetColor(LIGHTBLUE);
    definir(1,27,28,7,9,57);
    SetColor(WHITE);
    // CAIXINHA SECUNDARIA MENOR
    definir(3,35,25,20,24,35);

    SetColor(LIGHTBLUE);
    //CAIXINHA DE CRIAR CONTA
    definir(1,9,34,25,27,45);

    definir(1,9,34,12,14,45);

    SetColor(LIGHTBLUE);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");

    SetColor(WHITE);
    gotoxy(38,13);
    printf("LOGIN");

    gotoxy(38,26);
    printf("ENTER");
    gotoxy(30,8);
    printf("MENU DE ENTRADA DO USU%cRIO",181);
    gotoxy(27,17);
    printf("USU%cRIO:", 181);

    gotoxy(28,22);
    printf("SENHA:");

    gotoxy(28,30);
    printf("PREENCHA OS CAMPOS COM <0> PARA ");
    gotoxy(28,31);
    printf("VOLTAR AO MENU ANTERIOR.");

    fflush(stdin);
    voltaruser:
    voltaragora:
    gotoxy(37,17);
    gets(cade.user);
    if(cade.user[0] <= '\0'){
            gotoxy(37,17);
            SetColor(RED);
            printf("CAMPO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(37,17);
            printf("                      ");
            gotoxy(37,17);
            goto voltaruser;
    }
    fflush(stdin);
                            //ARQUIVOS
    gotoxy(37,22);

    char cc;
    int ii;
    voltarsenha:
    ii = 0;
     do{
            cc = getch();
            if(isprint(cc)) {    //Analisa se o valor da variável c é imprimivel
                cade.senha[ii] = cc;
                ii++;
                printf("*");
            }else
                if(cc == BACKSPACE && ii) {
                    cade.senha[ii] = '\0';
                    ii--;
                    printf("\b \b");
                }
        }while(cc != ENTER);
         cade.senha[ii] = '\0';
         if(cade.senha[0]<='\0'){
            gotoxy(37,22);
            SetColor(RED);
            printf("CAMPO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(37,22);
            printf("                              ");
            gotoxy(37,22);
            goto voltarsenha;
         }
          if(cade.user[0] == '0'&& cade.senha[0]=='0'){
              SetColor(GREEN);
              gotoxy(37,17);
              printf("                             ");
              gotoxy(37,17);
              printf("0");
              gotoxy(37,22);
              printf("                              ");
              gotoxy(37,22);
              printf("0");
              Sleep(500);
              SetColor(WHITE);

              inter_Criar_entrar();
         }


     arqu =fopen("Usuario.txt","rb");
    if(arqu == NULL){
        printf("VOCE PRECISA CRIAR UM USUARIO ANTES");
        opc = getch();
        fclose(arqu);
    }


      while(fread(&pop,sizeof(struct usuario),1,arqu)==1){
            if(strcmp(cade.user,pop.user)==0 && strcmp(cade.senha,pop.senha)==0){
                    fclose(arqu);





    SetColor(WHITE);
    definir(1,39,20,30,32,61);
    for(j = 21; j < 61; j++){
    gotoxy(j,31);
    SetColor(RED);
    Sleep(10);
    printf("%c",219);
    }

    SetColor(WHITE);
    definir(1,39,20,30,32,61);
    for(j = 21; j < 61; j++){
    gotoxy(j,31);
    SetColor(YELLOW);
    Sleep(10);
    printf("%c",219);
    }

    SetColor(WHITE);
    definir(1,39,20,30,32,61);
    for(j = 21; j < 61; j++){
    gotoxy(j,31);
    SetColor(GREEN);
    Sleep(10);
    printf("%c",219);
    }
    SetColor(WHITE);
    definir(0,58,10,7,9,61);

    gotoxy(11,8);
    printf("%s BEM VINDO(A) NOVAMENTE AO GERENCIADOR DE CONTAS",cade.user);

    getchar();

    tela_inicial();
                    }else{ //Fim do comparação de usuario e senha
                       gotoxy(37,17);
                       SetColor(RED);
                       printf("USUARIO OU SENHA ERRADOS");
                       gotoxy(37,22);
                       printf("USUARIO OU SENHA ERRADOS");
                       SetColor(WHITE);
                       Sleep(900);
                       gotoxy(37,22);
                       printf("                          ");
                       gotoxy(37,17);
                       printf("                           ");
                       goto voltaragora;
                       fclose(arqu);
                    }
      }//fim do comando Whilw


}


// Protóticos do Menu Principal
void tela_inicial();
void cadastro_de_contas();
void baixa_de_contas();
void relatorios();

// Protóticos de cadastro de contas
void inclusao();
void alteracao();
void consulta();
void exclusao();
void retornar();
void creditos();

//Protóticos de Baixa de Contas

//função Principal
int main(){

    inter();
    return 0;
}

//Tela Inicial
void tela_inicial(){
    int opc  = 0;
    system("cls");

    SetColor(LIGHTBLUE);
    definir(33,70,3,1,35,75);
    definir(0,64,6,8,28,72);

    //data
    SetColor(1);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");

    //caixa

    SetColor(WHITE);
    definir(1,30,25,21,23,57);


    definir(1,30,25,18,20,57);

    definir(1,30,25,15,17,57);
    // caixa de menu
    SetColor(LIGHTBLUE);
    definir(1,13,33,5,7,48);
    gotoxy(34,6);
    SetColor(WHITE);
    printf("MENU-PRINCIPAL");


    gotoxy(37,22);
    printf("CR%cDITOS",144);

    gotoxy(34,19);
    printf("SAIR DA CONTA");

    gotoxy(32, 16);
    printf("CADASTRO DE CONTAS");

    definir(1,11,35,12,14,48);

    gotoxy(39,13);
    printf("OP%c%cES",128,229);

    int x = 29, y = 16;
    int escolha = 0;
    char opcao;

    while(opcao != 13) {
        gotoxy(x, y);
        printf("%c", 175);
        opcao = getch();
        if(opcao == 72) {
            if(y > 16) {
                gotoxy(x, y);
                printf(" ");
                y -= 3;
                gotoxy(x, y);
                printf("%c", 175);
                if(y == 16)
                    escolha = 1;
                else
                    if(y == 19)
                        escolha = 2;
                    else
                        if(y == 22)
                            escolha = 3;
                            else
                                escolha = 0;
            }
        }else
            if(opcao == 80) {
                if(y < 22) {
                    gotoxy(x, y);
                    printf(" ");
                    y += 3;
                    gotoxy(x, y);
                    printf("%c", 175);
                        if(y == 22)
                            escolha = 3;
                        else
                            if(y == 19)
                                escolha = 2;
                            else
                                if(y == 16)
                                    escolha = 1;
                                else
                                    escolha = 0;
                }
            }else{
                if(y == 16)
                    escolha = 1;
            }
    }
    do{
        switch (escolha){
            case 1:
                cadastro_de_contas();
                break;
            case 2:
                inter_Criar_entrar();
                break;
            case 3:
                creditos();
        }
    } while(opc != 0);

}

void creditos(){
    system("cls");

    SetColor(LIGHTBLUE);
    definir(33,70,3,1,35,75);
    definir(0,64,6,8,28,72);

    //data
    SetColor(1);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");

    gotoxy(29,10);
    printf("Paulo Victor Ribeiro");
    gotoxy(30,11);
    printf("Gabriel Pepes Moda");

    gotoxy(24,13);
    printf("- - - - - - - - - - - - - - - - ");

    gotoxy(31,15);
    printf("Ant%cnio Jackson",147);

    gotoxy(31,16);
    printf("Eduardo Nicolas");

    gotoxy(32,17);
    printf("Gadson Souza");

    gotoxy(35,18);
    printf("Junior");

    gotoxy(24,20);
    printf("- - - - - - - - - - - - - - - - ");

    gotoxy(30,22);
    printf("Emerson Santa Rita");

    getchar();

    int h;

    SetColor(YELLOW);
    for(h = 24; h < 56; h++){
        gotoxy(h,13);
        printf("- ");
        Sleep(10);
    }

    SetColor(YELLOW);

        for(h = 24; h < 56; h++){
        gotoxy(h,20);
        printf("- ");
        Sleep(10);
    }

    SetColor(GREEN);
        for(h = 24; h < 56; h++){
        gotoxy(h,13);
        printf("- ");
        Sleep(10);
    }
    SetColor(GREEN);
        for(h = 24; h < 56; h++){
        gotoxy(h,20);
        printf("- ");
        Sleep(10);
    }


    tela_inicial();
}


void confirmar_usuario(){
     struct usuario pop;
    int j;
    struct entrar{
        char user[60];
        char senha[60];

     } cade;
     char opc;
     // parcial
    SetColor(LIGHTBLUE);
    definir(33,70,3,1,35,75);
    definir(0,64,6,10,29,72);

    //CAIXINHA MENOR
    SetColor(WHITE);
    definir(3,35,25,15,19,35);

    //Caixinha de Menu do usuario
    SetColor(LIGHTBLUE);
    definir(1,27,28,7,9,57);
    SetColor(WHITE);
    // CAIXINHA SECUNDARIA MENOR
    definir(3,35,25,20,24,35);

    SetColor(LIGHTBLUE);
    //CAIXINHA DE CRIAR CONTA
    definir(1,9,34,25,27,45);

    SetColor(LIGHTBLUE);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");

    SetColor(WHITE);

    gotoxy(38,26);
    printf("ENTER");
    gotoxy(30,8);
    printf("CONFIRMA%c%cO PARA ALTERA%c%cO",128,199,128,199);
    gotoxy(27,17);
    printf("USU%cRIO:", 181);

    gotoxy(28,22);
    printf("SENHA:");

    gotoxy(28,30);
    printf("PREENCHA OS CAMPOS COM <0> PARA ");
    gotoxy(28,31);
    printf("VOLTAR AO MENU ANTERIOR.");

    fflush(stdin);
    voltaruser:
    voltaragora:
    gotoxy(37,17);
    gets(cade.user);
    if(cade.user[0] <= '\0'){
            gotoxy(37,17);
            SetColor(RED);
            printf("CAMPO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(37,17);
            printf("                      ");
            gotoxy(37,17);
            goto voltaruser;
    }
    fflush(stdin);
                            //ARQUIVOS
    gotoxy(37,22);

    char cc;
    int ii;
    voltarsenha:
    ii = 0;
     do{
            cc = getch();
            if(isprint(cc)) {    //Analisa se o valor da variável c é imprimivel
                cade.senha[ii] = cc;
                ii++;
                printf("*");
            }else
                if(cc == BACKSPACE && ii) {
                    cade.senha[ii] = '\0';
                    ii--;
                    printf("\b \b");
                }
        }while(cc != ENTER);
         cade.senha[ii] = '\0';
         if(cade.senha[0]<='\0'){
            gotoxy(37,22);
            SetColor(RED);
            printf("CAMPO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(37,22);
            printf("                              ");
            gotoxy(37,22);
            goto voltarsenha;
         }
          if(cade.user[0] == '0'&& cade.senha[0]=='0'){
              SetColor(GREEN);
              gotoxy(37,17);
              printf("                             ");
              gotoxy(37,17);
              printf("0");
              gotoxy(37,22);
              printf("                              ");
              gotoxy(37,22);
              printf("0");
              Sleep(500);
              SetColor(WHITE);

              inter_Criar_entrar();
         }


     arqu =fopen("Usuario.txt","rb");
    if(arqu == NULL){
        printf("VOCE PRECISA CRIAR UM USUARIO ANTES");
        opc = getch();
        fclose(arqu);
    }


      while(fread(&pop,sizeof(struct usuario),1,arqu)==1){
            if(strcmp(cade.user,pop.user)==0 && strcmp(cade.senha,pop.senha)==0){
                    fclose(arqu);





    SetColor(WHITE);
    definir(1,39,20,30,32,61);
    for(j = 21; j < 61; j++){
    gotoxy(j,31);
    SetColor(RED);
    Sleep(10);
    printf("%c",219);
    }

    SetColor(WHITE);
    definir(1,39,20,30,32,61);
    for(j = 21; j < 61; j++){
    gotoxy(j,31);
    SetColor(YELLOW);
    Sleep(10);
    printf("%c",219);
    }

    SetColor(WHITE);
    definir(1,39,20,30,32,61);
    for(j = 21; j < 61; j++){
    gotoxy(j,31);
    SetColor(GREEN);
    Sleep(10);
    printf("%c",219);
    }


    getchar();

    alterar_usuario();
                    }else{ //Fim do comparação de usuario e senha
                       gotoxy(37,17);
                       SetColor(RED);
                       printf("USUARIO OU SENHA ERRADOS");
                       gotoxy(37,22);
                       printf("USUARIO OU SENHA ERRADOS");
                       SetColor(WHITE);
                       Sleep(900);
                       gotoxy(37,22);
                       printf("                          ");
                       gotoxy(37,17);
                       printf("                           ");
                       goto voltaragora;
                       fclose(arqu);
                    }
      }//fim do comando Whilw


}

void alterar_usuario(){
     struct usuario pop;
   char op;
   FILE *arqu;
    arqu = fopen("Usuario.txt","rb");//abre o arquivo para modo leitura
    if(arq == NULL){ //se ele nao existir executara os comandos
        arqu = fopen("Usuario.txt","wb");
    }
    fclose(arqu);

    fflush(stdin);

 arqu = fopen("Usuario.txt","ab");
    if(arqu == NULL){
        printf("Erro no arquivo\n");
        return;
    }

    SetColor(LIGHTBLUE);
    //borda
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,64,6,10,27,72);

    SetColor(WHITE);
    // caixinhas
    definir(1,40,8,11,13,18);
    definir(1,40,8,15,17,18);

    definir(1,40,8,19,21,18);
    definir(1,45,8,23,25,25);

    definir(0,30,25,7,9,57);

    //data
    SetColor(1);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");

    gotoxy(30,8);
    printf("PAINEL DE ALTERACAO");

    gotoxy(11,12);
    printf("NOME:");

    gotoxy(9,16);
    printf(" USU%cRIO:", 181);

    gotoxy(11,20);
    printf("SENHA:");

    gotoxy(9,24);
    printf("CONFIRMAR SENHA:");
    voltarnome:
    gotoxy(20,12);
    gets(pop.nome);
    if(pop.nome[0] <= '\0'){
        gotoxy(20,12);
        SetColor(RED);
        printf("PREENCHIMENTO OBRIGAT%cRIO",224);
        Sleep(900);
        SetColor(WHITE);
        gotoxy(20,12);
        printf("                              ");
        goto voltarnome;
    }
    fflush(stdin);

    voltaruser:
    gotoxy(20,16);
    gets(pop.user);
    if(pop.user[0]<='\0'){
        gotoxy(20,16);
        SetColor(RED);
        printf("PREENCHIMENTO OBRIGAT%cRIO",224);
        Sleep(900);
        SetColor(WHITE);
        gotoxy(20,16);
        printf("                              ");
        goto voltaruser;
    }
    fflush(stdin);

    SetColor(WHITE);
    p:
    gotoxy(20,20);
    printf("                                                ");

    gotoxy(20,20);
    char cc;
    int ii;
    obrigar:
    ii = 0;
       do{
            cc = getch();
            if(isprint(cc)) {    //Analisa se o valor da variável c é imprimivel
                pop.senha[ii] = cc;
                ii++;
                printf("*");
            }else
                if(cc == BACKSPACE && ii) {
                    pop.senha[ii] = '\0';
                    ii--;
                    printf("\b \b");
                }
        }while(cc != ENTER);
        pop.senha[ii] = '\0';
        if(pop.senha[0] <= '\0'){ //Condicao para que force o usuario a preencher a senha
            gotoxy(20,20);
            SetColor(RED);
            printf("PREENCHIMENTO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(20,20);
            printf("                              ");
            gotoxy(20,20);
            goto obrigar;
        }

        gotoxy(27,24);
        obrigar2:
        ii = 0;
        do{
            cc = getch();
            if(isprint(cc)) {    //Analisa se o valor da variável c é imprimivel
                pop.confirm_senha[ii] = cc;
                ii++;
                printf("*");
            }else
                if(cc == BACKSPACE && ii > 0) {
                    pop.confirm_senha[ii] = '\0';
                    ii--;
                    printf("\b \b");
                }
        }while(cc != ENTER);
        pop.confirm_senha[ii] = '\0';
        if(pop.confirm_senha[0]<= '\0'){ //Condicao para que force o usuario a preencher a senha
            gotoxy(27,24);
            SetColor(RED);
            printf("PREENCHIMENTO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(27,24);
            printf("                              ");
            gotoxy(27,24);
            goto obrigar2;
        }

        if(strcmp(pop.senha,pop.confirm_senha)==0){
                fwrite(&pop,sizeof(pop),1,arqu);
                fclose(arqu);
        }else{
            gotoxy(20,20);
            SetColor(RED);
            printf("Senhas Diferentes!");
            gotoxy(27,24);
            printf("Senhas Diferentes!");
            SetColor(WHITE);
            Sleep(900);
            gotoxy(27,24);
            printf("                                            ");
            goto p;
            fclose(arqu);
        }
        SetColor(WHITE);

    int k;

    definir(14,0,56,11,26,58);
     for(k = 12; k < 26; k ++){
        gotoxy(57,k);
        SetColor(RED);
        printf("%c", 219);
        Sleep(50);
     }

    SetColor(WHITE);
    definir(14,0,56,11,26,58);
    for(k = 12; k < 26; k ++){
        gotoxy(57,k);
        SetColor(YELLOW);
        printf("%c", 219);
        Sleep(50);
     }

    SetColor(WHITE);
    definir(14,0,56,11,26,58);
    for(k = 12; k < 26; k ++){
        gotoxy(57,k);
        SetColor(GREEN);
        printf("%c", 219);
        Sleep(50);
     }
    SetColor(WHITE);
    definir(0,30,25,28,30,57);
    gotoxy(30,29);
    printf("SEUS DADOS FORAM SALVOS");

    getchar();

    tela_inicial();



}





void cadastro_de_contas(){
    int opc = 0;



    do{

    system("cls");
    SetColor(LIGHTBLUE);
    //borda
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,64,6,8,28,72);
    SetColor(WHITE);

    //data
    SetColor(1);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");
    //cadastro de contas
    SetColor(LIGHTBLUE);
    definir(1,17,30,5,7,49);
    gotoxy(31,6);
    SetColor(WHITE);
    printf("CADASTRO DE CONTAS");

    //caixa
    definir(1,30,25,13,15,57);

    definir(1,30,25,16,18,57);

    definir(1,30,25,19,21,57);

    definir(1,30,25,22,24,57);

    definir(1,30,25,25,27,57);

    // Caixa de opção
    definir(1,10,35,10,12,47);
    gotoxy(38,11);
    printf("OP%c%cES:",128,229);

    gotoxy(37,14);
    printf("INCLUS%cO",199);

    gotoxy(37,17);
    printf("ALTERA%c%cO",128,199);

    gotoxy(37,20);
    printf("CONSULTA");

    gotoxy(37,23);
    printf("EXCLUS%cO",199);

    gotoxy(39,26);
    printf("EXIT");

    int x = 32, y = 14;
    int escolha = 0;
    char opcao;

    while(opcao != 13) {
        gotoxy(x, y);
        printf("%c", 175);
        opcao = getch();
        if(opcao == 72) {
            if(y > 14) {
                gotoxy(x, y);
                printf(" ");
                y -= 3;
                gotoxy(x, y);
                printf("%c", 175);
                if(y == 14)
                    escolha = 1;
                else
                    if(y == 17)
                        escolha = 2;
                    else
                        if(y == 20)
                            escolha = 3;
                        else
                            if(y == 23)
                                escolha = 4;
                            else
                                if(y == 26)
                                    escolha =5;
                            else
                                escolha = 0;
            }
        }else
            if(opcao == 80) {
                if(y < 26) {
                    gotoxy(x, y);
                    printf(" ");
                    y += 3;
                    gotoxy(x, y);
                    printf("%c", 175);
                    if(y == 26)
                        escolha = 5;
                    else
                        if(y == 23)
                            escolha = 4;
                        else
                            if(y == 20)
                                escolha = 3;
                            else
                                if(y == 17)
                                    escolha = 2;
                                else
                                    if(y == 14)
                                        escolha = 1;
                                else
                                    escolha = 0;
                }
            }else{
                if(y == 14)
                    escolha = 1;
            }
    }


        switch (escolha){
        case 1:
           inclusao();
            break;
        case 2:
            alteracao();
            break;
        case 3:
           consulta();
            break;
        case 4:
            exclusao();
            break;
        case 5:
        tela_inicial();
            break;
        }


    }while(opc != 0);
}


// Função de Inclusão de conta
void inclusao(){
    struct cadastro c;
    char op;
    voltar:

    fflush(stdin);

    arq = fopen("Arquivo 1.txt","ab");
    if(arq == NULL){
        printf("Erro no arquivo\n");
        getch();
        exit(1);
    } fclose(arq);

    system("cls");
    SetColor(LIGHTBLUE);
    //borda
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,64,6,8,30,72);
    SetColor(WHITE);

    //data
    SetColor(LIGHTBLUE);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");
    //cadastro de contas
    SetColor(LIGHTBLUE);
    definir(1,17,30,5,7,49);
    gotoxy(36,6);
    SetColor(WHITE);
    printf("INCLUS%cO",199);

    //caixa documento
    definir(1,33,8,9,11,19);
    gotoxy(9,10);
    printf("DOCUMENTO:");

    //descição
    definir(1,33,8,12,14,19);
    gotoxy(9,13);
    printf("DESCRI%c%cO:",128,199);

    //beneficiário
    definir(1,33,8,15,17,22);
    gotoxy(9,16);
    printf("BENEFICI%cRIO:",181);

    // valor
    SetColor(RED);
    definir(1,15,45,15,17,52);
    SetColor(WHITE);
    gotoxy(46,16);
    printf("VALOR:");

    //VENCIMENTO
    definir(1,21,45,9,11,68);
    gotoxy(47,10);
    printf("DATA DE VENCIMENTO:");

    SetColor(RED);
    definir(1,10,45,12,14,57);
    SetColor(WHITE);
    gotoxy(49,13);
    printf("/  /");

        SetColor(YELLOW);

    gotoxy(9,19);
    printf(">PARA VOLTAR AO MENU-ANTERIOR PREENCHA AS LACUNAS COM (0).");
    Sleep(600);

        gotoxy(9,19);
    printf("                                                         ");
    Sleep(300);

        gotoxy(9,19);
    printf(">PARA VOLTAR AO MENU-ANTERIOR PREENCHA AS LACUNAS COM (0).");
    Sleep(600);

        gotoxy(9,19);
    printf("                                                           ");
    Sleep(300);

        gotoxy(9,19);
    printf(">PARA VOLTAR AO MENU-ANTERIOR PREENCHA AS LACUNAS COM (0).");
    Sleep(600);

        gotoxy(9,19);
    printf("                                                            ");
    Sleep(300);

        gotoxy(9,19);
    printf(">PARA VOLTAR AO MENU-ANTERIOR PREENCHA AS LACUNAS COM (0).");
    Sleep(600);

        gotoxy(9,19);
    printf("                                                           ");

    SetColor(WHITE);

    //LEITURA
    voltardoc:
    gotoxy(20,10);
    gets(c.documento);
    if(c.documento[0]<='\0'){
            gotoxy(20,10);
            SetColor(RED);
            printf("CAMPO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(20,10);
            printf("                       ");
            gotoxy(20,10);
     goto voltardoc;
    }

    fflush(stdin);
    voltardesc:
    gotoxy(20,13);
    gets(c.descricao);
    if(c.descricao[0]<='\0'){
        gotoxy(20,13);
        SetColor(RED);
        printf("CAMPO OBRIGAT%cRIO",224);
        Sleep(900);
        SetColor(WHITE);
        gotoxy(20,13);
        printf("                   ");
        gotoxy(20,13);
        goto voltardesc;
    }
    fflush(stdin);
    voltarbenefc:
    gotoxy(23,16);
    gets(c.beneficiario);
    if(c.beneficiario[0]<='\0'){
        gotoxy(23,16);
        SetColor(RED);
        printf("CAMPO OBRIGAT%cRIO",224);
        Sleep(900);
        SetColor(WHITE);
        gotoxy(23,16);
        printf("                    ");
        gotoxy(23,16);
        goto voltarbenefc;
    }

    fflush(stdin);
    voltardia:
    gotoxy(46,13);
    scanf("%d",&c.dia);


    gotoxy(50,13);
    scanf("%d",&c.mes);

    gotoxy(53,13);
    scanf("%d",&c.ano);

    gotoxy(53,16);
    scanf("%f",&c.valor);

            if(c.documento[0] == '0' || c.descricao == '0' || c.beneficiario == '0' || c.descricao == '0') {
                 gotoxy(20,10);
                 SetColor(GREEN);
                 printf("0");
                 gotoxy(20,13);
                 printf("0");
                 gotoxy(23,16);
                 printf("o");
                 gotoxy(46,13);
                 printf("0");
                 gotoxy(50,13);
                 printf("0");
                 gotoxy(53,13);
                 printf("0");
                 gotoxy(53,16);
                 printf("0");
                 Sleep(500);
                cadastro_de_contas();
            }else{
                arq = fopen("Arquivo 1.txt", "ab");
                fflush(stdin);
                fwrite(&c,sizeof(struct cadastro),1,arq);
                fclose(arq);

            }


            int h;
            SetColor(WHITE);
            definir(1,32,21,27,29,55);
            for(h = 22; h <55; h++){
                SetColor(RED);
                gotoxy(h,28);
                printf("%c",219);
                Sleep(10);
            }
            SetColor(WHITE);
            definir(1,32,21,27,29,55);
            for(h = 22; h <55; h++){
                SetColor(YELLOW);
                gotoxy(h,28);
                printf("%c",219);
                Sleep(10);
            }
            SetColor(WHITE);
            definir(1,32,21,27,29,55);
            for(h = 22; h <55; h++){
                SetColor(GREEN);
                gotoxy(h,28);
                printf("%c",219);
                Sleep(10);
            }


    //confirmar
    SetColor(LIGHTBLUE);
    definir(1,30,22,18,20,54);
    gotoxy(32,19);
    SetColor(WHITE);
    printf("NOVA INCLUS%cO ?",199);

    //sim
    SetColor(LIGHTBLUE);
    definir(1,10,34,21,23,46);
    SetColor(GREEN);
    gotoxy(39,22);
    printf("SIM");

    //NÃO
    SetColor(LIGHTBLUE);
    definir(1,10,34,24,26,46);
    gotoxy(39,25);
    SetColor(RED);
    printf("N%cO",199);

    int x = 33, y = 22;
    int escolha = 0;
    char opcao;
    SetColor(WHITE);
    while(opcao != 13) {
        gotoxy(x, y);
        printf("%c", 175);
        opcao = getch();
        if(opcao == 72) {
            if(y > 22) {
                gotoxy(x, y);
                printf(" ");
                y -= 3;
                gotoxy(x, y);
                printf("%c", 175);
                if(y == 22)
                    escolha = 1;
                else
                    if(y == 25)
                        escolha = 2;
                            else
                                escolha = 0;
            }
        }else
            if(opcao == 80) {
                if(y < 25) {
                    gotoxy(x, y);
                    printf(" ");
                    y += 3;
                    gotoxy(x, y);
                    printf("%c", 175);
                    if(y == 25)
                        escolha = 2;
                    else
                        if(y == 22)
                            escolha = 1;
                                else
                                    escolha = 0;
                }
            }else{
                if(y == 22)
                    escolha = 1;
            }
    }
    switch(escolha){

        case 1:
            setbuf(stdin,NULL);
            inclusao();
            break;
        case 2 :
            setbuf(stdin,NULL);
            cadastro_de_contas();
            break;

            }

    getchar();

}


//Função Para Consulta
void consulta(){
    struct cadastro c;
    char op;

    fflush(stdin);
    arq = fopen("Arquivo 1.txt","rb");
    if(arq == NULL){
    system("cls");
    //borda
    SetColor(LIGHTBLUE);
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,55,10,7,28,75);
    definir(3,45,15,15,19,62);


    definir(1,17,30,1,3,49);
    gotoxy(36,2);
    SetColor(WHITE);
    printf("CONSUlTA",199);

    SetColor(WHITE);
      gotoxy(18,17);
      printf("                                          ",199);
      Sleep(100);

      gotoxy(18,17);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(18,17);
      printf("                                          ",199);
      Sleep(100);

      gotoxy(18,17);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(18,17);
      printf("                                          ",199);
      Sleep(100);


      gotoxy(18,17);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(18,17);
      printf("                                          ",199);
      Sleep(100);


      gotoxy(18,17);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(18,17);
      printf("                                          ",199);
      Sleep(100);
        fclose(arq);

        cadastro_de_contas();
    }
    system("cls");
    SetColor(LIGHTBLUE);
    definir(1,17,30,1,3,49);
    gotoxy(36,2);
    SetColor(WHITE);
    printf("CONSUlTA",199);

    // quadradinhos

    int doc =5,um = 7;
    int des = 8,cri = 10;
    int be = 11,ne =13;
    int ven = 5,ci = 7;
    int va = 8,lor =10;
    int bar = 11,ra = 13;
    int qua = 4, dra = 14;
    int data = 12;

    //printfs
    int ydocu = 6, ydescri = 9, ybenefi = 12, yvalor = 9, yvencimento = 6 , ybarras =12 ;


    while(fread(&c,sizeof(struct cadastro),1,arq)){
    SetColor(LIGHTBLUE);

    //QUADRO
    definir(0,64,6,qua,dra,72);
    //caixa documento
    SetColor(WHITE);
    definir(1,33,8,doc,um,19);
    gotoxy(9,ydocu);
    printf("DOCUMENTO:");

    //descição
    definir(1,33,8,des,cri,19);
    gotoxy(9,ydescri);
    printf("DESCRI%c%cO:",128,199);

    //beneficiário
    definir(1,33,8,be,ne,22);
    gotoxy(9,ybenefi);
    printf("BENEFICI%cRIO:",181);

    // valor
    SetColor(RED);
    definir(1,15,45,va,lor,52);
    SetColor(WHITE);
    gotoxy(46, yvalor);
    printf("VALOR:");

    //VENCIMENTO
    definir(1,21,45,ven,ci,68);
    gotoxy(47, yvencimento);
    printf("DATA DE VENCIMENTO:");

    SetColor(RED);
    definir(1,10,45,bar,ra,57);
    SetColor(WHITE);
    gotoxy(49,ybarras);
    printf("/  /");

        // imprimindo
        gotoxy(20,ydocu);
        printf("%s",c.documento);

        gotoxy(20,ydescri);
        printf("%s",c.descricao);

        gotoxy(23,ybenefi);
        printf("%s",c.beneficiario);

        gotoxy(46,data);
        printf("%d",c.dia);

        gotoxy(50,data);
        printf("%d",c.mes);

        gotoxy(53,data);
        printf("%d",c.ano);

        gotoxy(53,yvalor);
        printf("%.2f",c.valor);

            doc+=12;um +=12;
    des += 12;cri += 12;
    be += 12;ne +=12;
    ven+= 12;ci+= 12;
    va += 12;lor +=12;
    bar += 12 ; ra += 12;
    qua += 12; dra += 12;
    //printfs
    ydocu += 12; ydescri += 12; ybenefi += 12; yvalor += 12; yvencimento += 12; ybarras += 12 ;
    data += 12;



    }
    arq = fclose(arq);
    getchar();
    cadastro_de_contas();
}


FILE *copy;

// confirmar se deseja salvar ou não
void alteracao() {

    struct cadastro c; //struct dos dados do usuario
    char documento[60];
    char resp;
    int op, n;

        system("cls");
    SetColor(LIGHTBLUE);
    //borda
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,55,10,8,24,75);

    //quadradinho
    definir(1,51,12,21,23,65);

       //Entre com o Nome do documento
    SetColor(YELLOW);
    gotoxy(12,20);
    printf("*DIGITE O NOME DO DOCUMENTO QUE SER%c ALTERADO*",181);

    SetColor(LIGHTBLUE);
    definir(1,17,30,5,7,49);
    gotoxy(36,6);
    SetColor(WHITE);
    printf("ALTERA%c%cO",128,199);

    SetColor(LIGHTBLUE);
    gotoxy(13,22);
    SetColor(YELLOW);
    printf("DOCUMENTO:");

    // avisp

    gotoxy(12, 10);
    SetColor( RED);
    printf("AVISO:\n");
    SetColor(WHITE);
    gotoxy(14,11);
    printf("AO CLICAR (SIM) NA OP%c%cO DE ALTERA%c%cO, INFORMAMOS QUE",128,199,128,199);
    gotoxy(14,12);
    printf("SEUS DADOS SALVOS SER%cO ALTERADOS E N%cO SER%c MAIS POS-",199,199,181);
    gotoxy(14,13);
    printf("S%cVEL RECUPERA-LOS E CONSULTA-LOS.",214);

    gotoxy(12,16);
    SetColor(GREEN);
    printf("VOLTAR:");

    gotoxy(14,17);
    SetColor(WHITE);
    printf("PARA  VOLTAR AO MENU-ANTERIOR, PREENCHA O CAMPO COM ZE-");
    gotoxy(14,18);
    printf("RO (0), EM SEGUIDA CLIQUE EM ENTER.");

    // caracter errado
    k:
    errado:
    vol:
    vem:

    gotoxy(23,22);
    printf("                                     ");

    SetColor(WHITE);
    gotoxy(23,22);
    fflush(stdin);
    gets(documento);

    if(documento[0] == '0'){
        gotoxy(23,22);
        printf("                        ");
        SetColor(GREEN);
        gotoxy(23,22);
        printf("0");
        Sleep(500);
        cadastro_de_contas();
    }

    arq = fopen("Arquivo 1.txt","rb");

    if(arq == NULL){
        while(documento != -1){
        if(documento[0] == '0'){
        cadastro_de_contas();
        }else
            if(documento != '0'){
      gotoxy(23,22);
      SetColor(RED);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);

      gotoxy(23,22);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);

      gotoxy(23,22);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);


      gotoxy(23,22);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);


      gotoxy(23,22);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);
      fclose(arq);
      goto k;

         }
    }


    }

    while(fread(&c,sizeof(struct cadastro),1,arq) == 1){
        if(strcmp(c.documento,documento) == 0){

            //Consultar o que você vai alterar

    //borda
    SetColor(LIGHTBLUE);
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,64,6,8,18,72);
    SetColor(WHITE);

    //data
    SetColor(LIGHTBLUE);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");
    //cadastro de contas
    SetColor(LIGHTBLUE);
    definir(1,17,30,5,7,49);
    gotoxy(36,6);
    SetColor(WHITE);
    printf("ALTERA%c%cO",128,199);

    //caixa documento
    definir(1,33,8,9,11,19);
    gotoxy(9,10);
    printf("DOCUMENTO:");

    //descição
    definir(1,33,8,12,14,19);
    gotoxy(9,13);
    printf("DESCRI%c%cO:",128,199);

    //beneficiário
    definir(1,33,8,15,17,22);
    gotoxy(9,16);
    printf("BENEFICI%cRIO:",181);

    // valor
    SetColor(RED);
    definir(1,15,45,15,17,52);
    SetColor(WHITE);
    gotoxy(46,16);
    printf("VALOR:");

    //VENCIMENTO
    definir(1,21,45,9,11,68);
    gotoxy(47,10);
    printf("DATA DE VENCIMENTO:");

    SetColor(RED);
    definir(1,10,45,12,14,57);
    SetColor(WHITE);
    gotoxy(49,13);
    printf("/  /");

    // imprimindo
        gotoxy(20,10);
        printf("%s",c.documento);

        gotoxy(20,13);
        printf("%s",c.descricao);

        gotoxy(23,16);
        printf("%s",c.beneficiario);

        gotoxy(46,13);
        printf("%d",c.dia);

        gotoxy(50,13);
        printf("%d",c.mes);

        gotoxy(53,13);
        printf("%d",c.ano);

        gotoxy(53,16);
        printf("%.2f",c.valor);

        //confirmar
    SetColor(LIGHTBLUE);
    definir(1,30,22,20,22,54);
    gotoxy(30,21);
    SetColor(WHITE);
    printf("DESEJA MESMO ALTERAR ?",199);

         //sim
    SetColor(LIGHTBLUE);
    definir(1,10,34,23,25,46);
    SetColor(GREEN);
    gotoxy(39,24);
    printf("SIM");

    //NÃO
    SetColor(LIGHTBLUE);
    definir(1,10,34,26,28,46);
    gotoxy(39,27);
    SetColor(RED);
    printf("N%cO",199);

    int x = 35, y = 24;
    int escolha = 0;
    char opcao;
    SetColor(WHITE);
    while(opcao != 13) {
        gotoxy(x, y);
        printf("%c", 175);
        opcao = getch();
        if(opcao == 72) {
            if(y > 24) {
                gotoxy(x, y);
                printf(" ");
                y -= 3;
                gotoxy(x, y);
                printf("%c", 175);
                if(y == 24)
                    escolha = 1;
                else
                    if(y == 27)
                        escolha = 2;
                            else
                                escolha = 0;
            }
        }else
            if(opcao == 80) {
                if(y < 27) {
                    gotoxy(x, y);
                    printf(" ");
                    y += 3;
                    gotoxy(x, y);
                    printf("%c", 175);
                    if(y == 27)
                        escolha = 2;
                    else
                        if(y == 24)
                            escolha = 1;
                                else
                                    escolha = 0;
                }
            }else{
                if(y == 24)
                    escolha = 1;
            }
    }
    switch(escolha){

        case 1:
            setbuf(stdin, NULL);
                    copy = fopen("copia.txt", "ab");
                    rewind(arq);
                    while(fread(&c, sizeof(struct cadastro), 1, arq) == 1) {
                        if(strcmp(documento, c.documento) != 0 ) {
                            fwrite(&c, sizeof(struct cadastro), 1, copy);
                        }
                    }
                    fclose(arq);
                    fclose(copy);
                    remove("Arquivo 1.txt");
                    rename("copia.txt","Arquivo 1.txt");
                    system("cls");

                     system("cls");
    SetColor(LIGHTBLUE);
    //borda
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,64,6,8,30,72);
    SetColor(WHITE);

    //data
    SetColor(LIGHTBLUE);
    definir(1,11,61,32,34,74);
    SetColor(WHITE);
    gotoxy(63,33);
    system("date/t");
    //cadastro de contas
    SetColor(LIGHTBLUE);
    definir(1,17,30,5,7,49);
    gotoxy(36,6);
    SetColor(WHITE);
    printf("INCLUS%cO",199);

    //caixa documento
    definir(1,33,8,9,11,19);
    gotoxy(9,10);
    printf("DOCUMENTO:");

    //descição
    definir(1,33,8,12,14,19);
    gotoxy(9,13);
    printf("DESCRI%c%cO:",128,199);

    //beneficiário
    definir(1,33,8,15,17,22);
    gotoxy(9,16);
    printf("BENEFICI%cRIO:",181);

    // valor
    SetColor(RED);
    definir(1,15,45,15,17,52);
    SetColor(WHITE);
    gotoxy(46,16);
    printf("VALOR:");

    //VENCIMENTO
    definir(1,21,45,9,11,68);
    gotoxy(47,10);
    printf("DATA DE VENCIMENTO:");

    SetColor(RED);
    definir(1,10,45,12,14,57);
    SetColor(WHITE);
    gotoxy(49,13);
    printf("/  /");

    voltardoc:
    gotoxy(20,10);
    gets(c.documento);
    if(c.documento[0]<='\0'){
            gotoxy(20,10);
            SetColor(RED);
            printf("CAMPO OBRIGAT%cRIO",224);
            Sleep(900);
            SetColor(WHITE);
            gotoxy(20,10);
            printf("                       ");
            gotoxy(20,10);
     goto voltardoc;
    }

    fflush(stdin);
    voltardesc:
    gotoxy(20,13);
    gets(c.descricao);
    if(c.descricao[0]<='\0'){
        gotoxy(20,13);
        SetColor(RED);
        printf("CAMPO OBRIGAT%cRIO",224);
        Sleep(900);
        SetColor(WHITE);
        gotoxy(20,13);
        printf("                   ");
        gotoxy(20,13);
        goto voltardesc;
    }
    fflush(stdin);
    voltarbenefc:
    gotoxy(23,16);
    gets(c.beneficiario);
    if(c.beneficiario[0]<='\0'){
        gotoxy(23,16);
        SetColor(RED);
        printf("CAMPO OBRIGAT%cRIO",224);
        Sleep(900);
        SetColor(WHITE);
        gotoxy(23,16);
        printf("                    ");
        gotoxy(23,16);
        goto voltarbenefc;
    }

    fflush(stdin);
    voltardia:
    gotoxy(46,13);
    scanf("%d",&c.dia);


    gotoxy(50,13);
    scanf("%d",&c.mes);

    gotoxy(53,13);
    scanf("%d",&c.ano);

    gotoxy(53,16);
    scanf("%f",&c.valor);

    int h;
            SetColor(WHITE);
            definir(1,32,21,27,29,55);
            for(h = 22; h <55; h++){
                SetColor(RED);
                gotoxy(h,28);
                printf("%c",219);
                Sleep(10);
            }
            SetColor(WHITE);
            definir(1,32,21,27,29,55);
            for(h = 22; h <55; h++){
                SetColor(YELLOW);
                gotoxy(h,28);
                printf("%c",219);
                Sleep(10);
            }
            SetColor(WHITE);
            definir(1,32,21,27,29,55);
            for(h = 22; h <55; h++){
                SetColor(GREEN);
                gotoxy(h,28);
                printf("%c",219);
                Sleep(10);
            }
                    arq = fopen("Arquivo 1.txt","ab");
                    fwrite(&c,sizeof(c),1,arq);
                    fclose(arq);
                    cadastro_de_contas();
            break;
        case 2 :
    //confirmar
       SetColor(LIGHTBLUE);
        definir(1,30,22,20,22,54);
    gotoxy(32,21);
    SetColor(WHITE);
    printf("NOVA ALTERA%c%cO ?",128,199);

         //sim
    SetColor(LIGHTBLUE);
    definir(1,10,34,23,25,46);
    SetColor(GREEN);
    gotoxy(39,24);
    printf("SIM");

    //NÃO
    SetColor(LIGHTBLUE);
    definir(1,10,34,26,28,46);
    gotoxy(39,27);
    SetColor(RED);
    printf("N%cO",199);

    int x = 35, y = 24;
    int escolha = 0;
    char opcao;
    SetColor(WHITE);
    while(opcao != 13) {
        gotoxy(x, y);
        printf("%c", 175);
        opcao = getch();
        if(opcao == 72) {
            if(y > 24) {
                gotoxy(x, y);
                printf(" ");
                y -= 3;
                gotoxy(x, y);
                printf("%c", 175);
                if(y == 24)
                    escolha = 1;
                else
                    if(y == 27)
                        escolha = 2;
                            else
                                escolha = 0;
            }
        }else
            if(opcao == 80) {
                if(y < 27) {
                    gotoxy(x, y);
                    printf(" ");
                    y += 3;
                    gotoxy(x, y);
                    printf("%c", 175);
                    if(y == 27)
                        escolha = 2;
                    else
                        if(y == 24)
                            escolha = 1;
                                else
                                    escolha = 0;
                }
            }else{
                if(y == 24)
                    escolha = 1;
            }
    }
    switch(escolha){

        case 1:
            fclose(arq);
            fflush(stdin);
            alteracao();
            break;
        case 2:
            fclose(arq);
            fflush(stdin);
            cadastro_de_contas();
            break;

            }

            }
    }
    gotoxy(23,22);
    SetColor(RED);
    printf("DOCUMENTO N%cO ENCONTRADO",199);
    Sleep(900);
    SetColor(WHITE);
    fclose(arq);
    goto errado;
        }
    }




//Função para Exclusão de Conta
void exclusao(){
    struct cadastro c;
    char documento[60],op;

    system("cls");
    SetColor(LIGHTBLUE);
    //borda
    definir(33,70,3,1,35,75);
    //QUADRO
    definir(0,55,10,8,24,75);

    //quadradinho
    definir(1,51,12,21,23,65);

       //Entre com o Nome do documento
    SetColor(YELLOW);
    gotoxy(12,20);
    printf("*DIGITE O NOME DO DOCUMENTO QUE SER%c EXCLUIDO*",181);

    SetColor(LIGHTBLUE);
    definir(1,17,30,5,7,49);
    gotoxy(36,6);
    SetColor(WHITE);
    printf("EXCLUS%cO",199);

    SetColor(LIGHTBLUE);
    gotoxy(13,22);
    SetColor(YELLOW);
    printf("DOCUMENTO:");

    // avisp

    gotoxy(12, 10);
    SetColor( RED);
    printf("AVISO:\n");
    SetColor(WHITE);
    gotoxy(14,11);
    printf("AO CLICAR (SIM) NA OP%c%cO DE EXCLUS%cO, INFORMAMOS QUE",128,199,199);
    gotoxy(14,12);
    printf("SEUS DADOS SALVOS SER%cO DELETADOS E N%cO SER%c MAIS POS-",199,199,181);
    gotoxy(14,13);
    printf("S%cVEL RECUPERA-LOS E CONSULTA-LOS.",214);

    gotoxy(12,16);
    SetColor(GREEN);
    printf("VOLTAR:");

    gotoxy(14,17);
    SetColor(WHITE);
    printf("PARA  VOLTAR AO MENU-ANTERIOR, PREENCHA O CAMPO COM ZE-");
    gotoxy(14,18);
    printf("RO (0), EM SEGUIDA CLIQUE EM ENTER.");

    // caracter errado
    k:
    errado:

    gotoxy(23,22);
    printf("                                     ");

    SetColor(WHITE);
    gotoxy(23,22);
    fflush(stdin);
    gets(documento);

    if(documento[0] == '0'){
        gotoxy(23,22);
        printf("                        ");
        SetColor(GREEN);
        gotoxy(23,22);
        printf("0");
        Sleep(500);
        cadastro_de_contas();
    }
    else{

    arq = fopen("Arquivo 1.txt","rb");
    if(arq == NULL){
              while(documento != -1){
        if(documento[0] == '0'){
        cadastro_de_contas();
        }else
            if(documento != '0'){
      gotoxy(23,22);
      SetColor(RED);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);

      gotoxy(23,22);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);

      gotoxy(23,22);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);


      gotoxy(23,22);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);


      gotoxy(23,22);
      printf("VOLTE AO MENU-ANTERIOR E CRIE UM DOCUMENTO",199);
      Sleep(500);

      gotoxy(23,22);
      printf("                                          ",199);
      Sleep(100);
      fclose(arq);
      goto k;

            }
        }
    }
    while(fread(&c,sizeof(struct cadastro),1,arq)==1){
        if(strcmp(documento,c.documento)==0){
                FILE *aux = fopen("auxiliarexclusao.txt","ab");
                rewind(arq);

                  SetColor(LIGHTBLUE);
    definir(1,30,22,25,27,54);
    gotoxy(29,26);
    SetColor(WHITE);
    printf("DESEJA MESMO EXCLUIR ?");

    //sim
    SetColor(LIGHTBLUE);
    definir(1,10,34,28,30,46);
    SetColor(GREEN);
    gotoxy(39,29);
    printf("SIM");

    //NÃO
    fflush(stdin);
    SetColor(LIGHTBLUE);
    definir(1,10,34,31,33,46);
    gotoxy(39,32);
    SetColor(RED);
    printf("N%cO",199);

    int a = 33, b = 29;
    int desejo = 0;
    char opc;
    SetColor(WHITE);
    while(opc != 13) {
        gotoxy(a, b);
        printf("%c", 175);
        opc = getch();
        if(opc == 72) {
            if(b > 29) {
                gotoxy(a, b);
                printf(" ");
                b -= 3;
                gotoxy(a, b);
                printf("%c", 175);
                if(b == 29)
                    desejo = 1;
                else
                    if(b == 32)
                        desejo = 2;
                            else
                                desejo = 0;
            }
        }else
            if(opc == 80) {
                if(b < 32) {
                    gotoxy(a, b);
                    printf(" ");
                    b += 3;
                    gotoxy(a, b);
                    printf("%c", 175);
                    if(b == 32)
                        desejo = 2;
                    else
                        if(b == 29)
                            desejo = 1;
                                else
                                    desejo = 0;
                }
            }else{
                if(b == 29)
                    desejo = 1;
            }
    }
        fflush(stdin);
        switch(desejo){
            case 1:
                while(fread(&c,sizeof(struct cadastro),1,arq) == 1){
                    if(strcmp(documento,c.documento)!= 0){
                        fwrite(&c,sizeof(struct cadastro),1,aux);
                    }
                }
                fclose(arq);
                fclose(aux);
                remove("Arquivo 1.txt");
                rename("auxiliarexclusao.txt","Arquivo 1.txt");
                cadastro_de_contas();

                break;
            case 2:
        // CASO NÃO QUEIRA SALVAR EM ARQUIVOS
                fclose(arq);
                exclusao();
                break;

//fimmm
        }
    }
}
    gotoxy(23,22);
    SetColor(RED);
    printf("DOCUMENTO N%cO ENCONTRADO",199);
    Sleep(900);
    SetColor(WHITE);
    fclose(arq);
    goto errado;
    }
}
