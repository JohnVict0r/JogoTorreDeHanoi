#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <locale.h>

using namespace std;
int v=0, p1=0,p2=0;
char jogador1[100] ;
char jogador2[100];

void finalizando();
void menu();
void instrucoes();
void pegarNome(int tipo);
void modoDoJogo();
void singlePlayer();
void multiplayer();
void verificarGanhador(char *nome, int pontos);
void iniciarJogo(char *nome, int tipo);
void numDiscos();
int Jogando( int j,int t,int *torre1, int *torre2, int *torre3, char *nome, int tipo);
void PegarDisco(int j, int t,int *torre1, int *torre2, int *torre3, char *nome, int tipo);
void SoltarDisco(int pegaDiscoTorre, int disco,int disco_i,int j, int t,int *torre1, int *torre2, int *torre3, char *nome, int tipo);
int quantMinJogadas();
float pontuacao();

int main()
{
//inicializando o jogo;
   setlocale(LC_ALL, "Portuguese");

    menu();

return 0;
}


void pegarNome(int tipo){

char nome[100];

    nome[0]='\0';

    while(nome[0] == '\0'){

    system("cls");
    cout<<"insira seu nome para iniciar o jogo:"<<endl;
    cin.getline(nome,49);
    }

iniciarJogo(nome,tipo);
}

float pontuacao(float t,  float j, float r){

float pontos = (1000.0*t)*(r/j);

return pontos;

}

int quantMinJogadas(int t){
int jmin;

jmin= pow(2,t) -1;

return jmin;

}

void PegarDisco(int j, int t,int *torre1, int *torre2, int *torre3, char *nome, int tipo)
{

    int pegaDiscoTorre=0;
    int VerificarT1=0, VerificarT2=0, VerificarT3=0;
    int disco, disco_i=0;
    int soltaDiscoTorre=0;
    int topoTorre=0;
    int disco_j=6;

    while(pegaDiscoTorre != 1 && pegaDiscoTorre != 2 && pegaDiscoTorre != 3 )
    {
        cout<<" deseja movimentar o primeiro disco de qual torre?"<<endl;
        cin>>pegaDiscoTorre;

        switch(pegaDiscoTorre)
        {

        case 1:

            for(int i=7-t; i<7; i++)
            {
                if(torre1[i-1] == 0)
                {

                    disco=torre1[i];
                    disco_i=i;

                }
                if(torre1[i] == 0)
                {
                    VerificarT1++;
                }
            }
            if(VerificarT1 == t)
            {
                cout<<"Não pode selecionar a Torre 1!";
                Jogando(j,t,torre1, torre2, torre3,nome,tipo);
            }

            torre1[disco_i]=0;
            break;
        case 2:

            for(int i=7-t; i<7; i++)
            {
                if(torre2[i-1] == 0 )
                {

                    disco=torre2[i];
                    disco_i=i;

                }
                if(torre2[i] == 0)
                {
                    VerificarT2++;
                }
            }
            if(VerificarT2 == t)
            {
                cout<<"Não pode selecionar a Torre 2!";
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);
            }
            torre2[disco_i]=0;
            break;
        case 3:

            for(int i=7-t; i<7; i++)
            {
                if(torre3[i-1] ==0 )
                {

                    disco=torre3[i];
                    disco_i=i;

                }
                if(torre3[i] == 0)
                {
                    VerificarT3++;
                }
            }

            if(VerificarT3 == t)
            {
                cout<<"Não pode selecionar a Torre 3!";
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);
            }
            else
            {
                //cout<<"pode mexer a 3";
            }
            torre3[disco_i]=0;
            break;
        default:

            cout<<"torre inválida";

            break;

        }
    }

    SoltarDisco(pegaDiscoTorre, disco,disco_i, j, t, torre1,torre2, torre3, nome, tipo);

}

void SoltarDisco(int pegaDiscoTorre, int disco,int disco_i,int j, int t,int *torre1, int *torre2, int *torre3, char *nome, int tipo)
{

    int VerificarT1=0, VerificarT2=0, VerificarT3=0;

    int soltaDiscoTorre=0;
    int topoTorre=0;
    int disco_j=6;


    while(soltaDiscoTorre != 1 && soltaDiscoTorre != 2 &&soltaDiscoTorre != 3 )
    {


        cout<<" deseja movimentar o disco"<< disco <<" para qual torre?"<<endl;
        cin>>soltaDiscoTorre;

        switch(soltaDiscoTorre)
        {

        case 1:



            for(int i=6; i>6-t; i--)
            {
                if((torre1[i-1] == 0 && torre1[i] != 0))
                {

                    topoTorre=torre1[i];
                    disco_j=i;

                }
            }

            if(disco > topoTorre && topoTorre!=0 )
            {
                cout<<"disco "<<disco<<" não pode ficar em cima do disco "<<topoTorre<<"!"<<endl;

                switch(pegaDiscoTorre){

                    case 1:
                        torre1[disco_i]=disco;
                        break;
                    case 2:
                        torre2[disco_i]=disco;
                        break;
                    case 3:
                        torre3[disco_i]=disco;
                        break;


                }
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);
            }
            else if(topoTorre==0)
            {

                torre1[disco_j] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }

                Jogando(j,t,torre1, torre2, torre3,nome, tipo);

            }
            else if(topoTorre!=0)
            {

                torre1[disco_j-1] = disco;

                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);


            }

            break;
        case 2:



            for(int i=6; i>6-t; i--)
            {
                if((torre2[i-1] == 0 && torre2[i] != 0))
                {

                    topoTorre=torre2[i];
                    disco_j=i;

                }
            }
            if(disco > topoTorre && topoTorre!=0)
            {
                cout<<"disco "<<disco<<" não pode ficar em cima do disco"<<topoTorre<<"!"<<endl;
                switch(pegaDiscoTorre){

                    case 1:
                        torre1[disco_i]=disco;
                        break;
                    case 2:
                        torre2[disco_i]=disco;
                        break;
                    case 3:
                        torre3[disco_i]=disco;
                        break;


                }
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);
            }
            else if(topoTorre==0)
            {
                torre2[disco_j] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);

            }
            else if(topoTorre!=0)
            {

                torre2[disco_j-1] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);

            }
            break;
        case 3:


            for(int i=6; i>6-t; i--)
            {
                if((torre3[i-1] == 0 && torre3[i] != 0))
                {

                    topoTorre=torre3[i];
                    disco_j=i;

                }
            }
            if(disco > topoTorre && topoTorre!=0)
            {
                cout<<"disco "<<disco<<" não pode ficar em cima do disco"<<topoTorre<<"!"<<endl;
                switch(pegaDiscoTorre){

                    case 1:
                        torre1[disco_i]=disco;
                        break;
                    case 2:
                        torre2[disco_i]=disco;
                        break;
                    case 3:
                        torre3[disco_i]=disco;
                        break;


                }
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);
            }
            else if(topoTorre==0)
            {
                torre3[disco_j] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);
            }
            else if(topoTorre!=0)
            {

                torre3[disco_j-1] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome, tipo);

            }


            break;
        default:

            cout<<"torre inválida";

            break;

        }


    }
}

int Jogando( int j,int t,int *torre1, int *torre2, int *torre3, char *nome, int tipo)
{

    system("cls");

    int resultadoQuantMinJogadas = quantMinJogadas(t);

    cout<<"==========================="<<endl;
    cout<<"=   Jogo Torre De Hanoi   ="<<endl;
    cout<<"==========================="<<endl;


    for(int i=7-t; i<7; i++)
    {

        if(torre1[i] !=0)
        {
            cout<<"  ["<< torre1[i]<<"] ";
        }
        else
        {

            cout<<"  [ ] ";
        }
        if(torre2[i] !=0)
        {
            cout<<"     ["<< torre2[i]<<"]";
        }
        else
        {

            cout<<"     [ ]";
        }
        if(torre3[i] !=0)
        {
            cout<<"      ["<< torre3[i]<<"]";
        }
        else
        {

            cout<<"      [ ]";
        }
        cout<<endl;
        if(i==6)
        {
            cout<<"Torre 1  Torre 2  Torre 3"<<endl;
        }

    }

    char jogarNovamente;
    cout<<"==========================="<<endl;
    cout<<"quantidade mínima de jogadas: "<<resultadoQuantMinJogadas<<endl;
    cout<<"==========================="<<endl;
    cout<<" Jogador: "<<nome<<endl;
    cout<<" Quantidade de jogadas = "<<j<<endl;
    cout<<"==========================="<<endl;


// Verificar se eu estou escolhendo uma torre válida
int soma=0;

 for(int i=0; i<7; i++) //inicializando as torres como vetores preenchidos com 0...
    {

       soma+= torre1[i]+torre2[i];

    }
if(soma>0){
PegarDisco(j,t,torre1, torre2, torre3,nome, tipo);
}else{
float pontos = pontuacao(t,j,resultadoQuantMinJogadas);
cout<<"Você cumpriu o objetivo do jogo em "<<j<<" jogadas"<<endl;
cout<<"pontuação: "<<pontos<<" pts"<<endl<<endl;

if(tipo==0){
    cout<<"quer jogar novamente? (s/n)"<<endl;
    cin>>jogarNovamente;

    switch(jogarNovamente){

    case 's':
    iniciarJogo(nome, tipo);
    break;

    case 'n':
        cout<<"finalizando o jogo..."<<endl;
    break;

    default:
    cout<<"Erro no sistema..."<<endl;




    }

}else if(tipo==1){

    verificarGanhador(nome,pontos);
    if(v==2){
        finalizando();
    }

}


}


}

void iniciarTorres(int Qd, char *nome,int tipo)
{

    int j=0;//jogadas
    int torre1[7],torre2[7],torre3[7];

    for(int i=0; i<7; i++) //inicializando as torres como vetores preenchidos com 0...
    {

        torre1[i]=0;
        torre2[i]=0;
        torre3[i]=0;

    }
    int tamTorre = Qd;//clonar o valor de Qd para não perde-lo...

    for(int i=6; (i>=0) && (Qd >0); i--)
    {

        torre1[i]=Qd;
        Qd--;

    }
    Jogando(j,tamTorre,torre1, torre2, torre3,nome,tipo);
}

void numDiscos(int d, char *nome, int tipo)
{
    system("cls");

    int  QtDiscos;
    switch(d)
    {

    case 0:
        QtDiscos=1;
        //finalizar jogo
        break;
    case 1:
        QtDiscos=3;
        cout<<"iniciando jogo com 3 discos..."<<endl;
        break;
    case 2:
        QtDiscos=5;
        cout<<"iniciando jogo com 5 discos..."<<endl;
        break;
    case 3:
        QtDiscos=7;
        cout<<"iniciando jogo com 7 discos..."<<endl;
        break;
    case 4:
        menu();
        break;
    default:
        //QtDiscos não recebeu nada
        QtDiscos=0;
        break;
    }

    if(QtDiscos>1)
    {
        iniciarTorres(QtDiscos,nome,tipo);
    }
    else if (QtDiscos ==1)
    {
        cout<<"Finalizando o jogo..."<<endl;
    }
    else
    {

        cout<<"=============================="<<endl;
        cout<<"Jogador: "<<nome<<endl;
        cout<<"=============================="<<endl;
        cout<<"=informou uma opção inválida!="<<endl;
        cout<<"=============================="<<endl;
        cout<<"=============================="<<endl;
        cout<<"escolha a dificuldade do jogo:"<<endl;
        cout<<"=============================="<<endl;
        cout<<"Opções:"<<endl;
        cout<<" 1 - Fácil (3 Discos)"<<endl;
        cout<<" 2 - Médio (5 Discos)"<<endl;
        cout<<" 3 - Dificil (7 Discos)"<<endl;
        cout<<"=============================="<<endl;
        cout<<" 0 - Sair do jogo:"<<endl;
        cout<<"=============================="<<endl;
        cin>>d;
        numDiscos(d,nome,tipo);

    }
//aqui podemos implementar para o programa chamar a função IniciarJogo(); novamente se o usuário desejar jogar denovo...

}

void iniciarJogo(char *nome,int tipo){



    int dificuldade;

    system("cls");
    cout<<"=============================="<<endl;
    cout<<"Jogador: "<<nome<<endl;
    cout<<"escolha a dificuldade do jogo:"<<endl;
    cout<<"=============================="<<endl;
    cout<<"Opções:"<<endl;
    cout<<" 1 - Fácil (3 Discos)"<<endl;
    cout<<" 2 - Médio (5 Discos)"<<endl;
    cout<<" 3 - Dificil (7 Discos)"<<endl;
    cout<<"=============================="<<endl;
    cout<<" 4 - Voltar ao menu"<<endl;
    cout<<" 0 - Sair do jogo"<<endl;
    cout<<"=============================="<<endl;
    cin>>dificuldade;

    numDiscos(dificuldade, nome,tipo);



}

void modoDoJogo(){

    char modoJogo='0';
    int cont=0;
    while(modoJogo<'1' || modoJogo >'2' ){

    if(cont>0){

        cout<<"Você informou uma opção inválida..."<<endl;

    }

    cout<<"============================="<<endl;
    cout<<"Escolha o modo do jogo:"<<endl;
    cout<<"============================="<<endl;
    cout<<"1- Single Player"<<endl;
    cout<<"2- Multiplayer"<<endl;
    cin>>modoJogo;
    cont++;

    }

    switch(modoJogo){

    case '1':

        singlePlayer();
        break;

    case '2':
        multiplayer();
        break;

    default:
        cout<<"erro no sistema...";
        break;
    }
}

void singlePlayer(){
int tipo =0;
pegarNome(tipo);

}

void multiplayer(){
int tipo=1;
int p1=0;
//vez do jogador 1
cout<<"Jogador 01:"<<endl;
pegarNome(tipo);

cout<<"jogador 02:"<<endl;
pegarNome(tipo);

}

void verificarGanhador(char *nome, int pontos){
system("cls");
v++;
if(v==1){

    for(int i=0; i<30; i++){
        jogador1[i]= nome[i];
    }

 p1 = pontos;

}else if(v==2){

for(int i=0; i<30; i++){
        jogador2[i]= nome[i];
    }
 p2 = pontos;
}

if(v==2){

    if(p1>p2){

        cout<<"============================"<<endl;
        cout<<"         Vencedor!"<<endl;
        cout<<"============================"<<endl;
        cout<<"jogador 1: ";

        for(int i=0; i<30; i++){

        cout<<jogador1[i];
         //sair do for, considerando que o restante do nome sera vazio
        if(jogador1[i] ==' ' ){

            i=30;
        }
        }
        cout<<endl<<"pontos: "<<p1<<endl;
    cout<<"============================"<<endl;


    }else if (p2>p1){

        cout<<"============================"<<endl;
        cout<<"         Vencedor!"<<endl;
        cout<<"============================"<<endl;
        cout<<"jogador 2 ";

        for(int i=0; i<30; i++){

        cout<<jogador2[i];

         //sair do for, considerando que o restante do nome sera vazio
        if(jogador2[i] ==' ' ){

            i=30;
        }

        }

        cout<<endl<<"pontos: "<<p2<<endl;
        cout<<"============================"<<endl;
    }else{


        cout<<"============================"<<endl;
        cout<<"         Empataram!"<<endl;
        cout<<"============================"<<endl;

    cout<<"jogador 01: ";


        for(int i=0; i<30; i++){

        cout<<jogador1[i];

        //sair do for, considerando que o restante do nome sera vazio
        if(jogador1[i] ==' ' ){

            i=30;
        }

        }
    cout<<endl<<"pontos: "<<p1<<endl;
    cout<<"============================"<<endl;

    cout<<"jogador 02: ";

        for(int i=0; i<30; i++){

        cout<<jogador2[i];
        if(jogador2[i]==' ' ){

            i=30;

        }
        }

    cout<<endl<<"pontos: "<<p2<<endl;
    cout<<"============================"<<endl;


    }

}

}

void finalizando(){

cout<<endl<<"Finalizando o jogo..."<<endl;

}

void intrucoes(){

char voltar='0';

while(voltar=='0'){

    system("cls");
    cout<<"====================================================================="<<endl;
    cout<<"Objetivo:"<<endl;
    cout<<"1- Mover todos os discos da torre 1 para a torre 3."<<endl;
    cout<<"Regras:"<<endl;
    cout<<"1- mover um disco de cada vez"<<endl;
    cout<<"2- mover um disco maior para cima de um menor é um movimento inválido"<<endl;
    cout<<"====================================================================="<<endl;

    cout<<"digite qualquer coisa para voltar";
    cin>>voltar;

    voltar='1';

    menu();
}

}

void menu(){

int op=-1;

    while(op<0 || op >2){

    system("cls");

    cout<<"===================================="<<endl;
    cout<<"             Bem Vindo!             "<<endl;
    cout<<"        Jogo Torre De Hanoi         "<<endl;
    cout<<"===================================="<<endl;
    cout<<"Digite:                             "<<endl;
    cout<<"1 - Iniciar o jogo                  "<<endl;
    cout<<"2 - Instruções do jogo              "<<endl;
    cout<<"0 - Sair do jogo"<<endl;
    cout<<"===================================="<<endl;

    cin>>op;
    }
    switch(op){

    case 1:
        modoDoJogo();
        break;
    case 2:
        intrucoes();
        break;
    case 0:
        cout<<"Finalizando o jogo...";
        break;
    default:
        cout<<"erro no sistema...";
        cout<<"reinicie o jogo por favor...";
    }

}
