#include <iostream>
#include <stdlib.h>

using namespace std;

void PegarDisco(int pdt, int t,int *torre1, int *torre2, int *torre3);
void SoltarDisco();



void PegarDisco(int pdt, int t,int *torre1, int *torre2, int *torre3)
{



}

void SoltarDisco()
{

}

void Jogando( int j,int t,int *torre1, int *torre2, int *torre3, char *nome)
{

    system("cls");

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

    cout<<"==========================="<<endl;
    cout<<" Jogador: "<<nome<<endl;
    cout<<" Quantidade de jogadas = "<<j<<endl;
    cout<<"==========================="<<endl;


// Verificar se eu estou escolhendo uma torre válida
    int pegaDiscoTorre=0;
    int VerificarT1=0, VerificarT2=0, VerificarT3=0;
    int disco, disco_i=0;
    int soltaDiscoTorre=0;
    int topoTorre=0;
    int disco_j=6;

    while(pegaDiscoTorre != 1 && pegaDiscoTorre != 2 &&pegaDiscoTorre != 3 )
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
                Jogando(j,t,torre1, torre2, torre3,nome);
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
                Jogando(j,t,torre1, torre2, torre3,nome);
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
                Jogando(j,t,torre1, torre2, torre3,nome);
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
                Jogando(j,t,torre1, torre2, torre3,nome);
            }
            else if(topoTorre==0)
            {

                torre1[disco_j] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }

                Jogando(j,t,torre1, torre2, torre3,nome);

            }
            else if(topoTorre!=0)
            {

                torre1[disco_j-1] = disco;

                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome);


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
                Jogando(j,t,torre1, torre2, torre3,nome);
            }
            else if(topoTorre==0)
            {
                torre2[disco_j] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome);

            }
            else if(topoTorre!=0)
            {

                torre2[disco_j-1] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome);

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
                Jogando(j,t,torre1, torre2, torre3,nome);
            }
            else if(topoTorre==0)
            {
                torre3[disco_j] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome);
            }
            else if(topoTorre!=0)
            {

                torre3[disco_j-1] = disco;
                if(pegaDiscoTorre !=soltaDiscoTorre)
                {
                    j++;
                }
                Jogando(j,t,torre1, torre2, torre3,nome);

            }


            break;
        default:

            cout<<"torre inválida";

            break;

        }


    }




}

void iniciarTorres(int Qd, char *nome)
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
    Jogando(j,tamTorre,torre1, torre2, torre3,nome);
}

void NumDiscos(int d, char *nome)
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
    default:
        //QtDiscos não recebeu nada
        QtDiscos=0;
        break;
    }

    if(QtDiscos>1)
    {
        iniciarTorres(QtDiscos,nome);
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
        NumDiscos(d,nome);

    }
//aqui podemos implementar para o programa chamar a função IniciarJogo(); novamente se o usuário desejar jogar denovo...

}

int main()
{


    cout<<"===================================="<<endl;
    cout<<"              WELCOME!              "<<endl;
    cout<<"===================================="<<endl;

    char nome[100];

    cout<<"insira seu nome para iniciar o jogo:"<<endl;
    cin.getline(nome,49);

    while(*nome == '\0'){

    cout<<"insira seu nome para iniciar o jogo:"<<endl;
    cout<<" ou informe 0 para sair do jogo...";
    cin.getline(nome,49);
    }
    if(*nome !='0'){
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
    cout<<" 0 - Sair do jogo:"<<endl;
    cout<<"=============================="<<endl;
    cin>>dificuldade;

    NumDiscos(dificuldade,nome);

    }else if(*nome =='0'){
    cout<<"encerrando o jogo...";

    }
}
