#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <windows.h>

#define waitkey; rlutil::anykey("\n                             Pressione qualquer tecla...\n")
#define TAM 100
#include "rlutil.h"
using namespace std;

//---------------------- TAMANHO DO CONSOLE

struct console
  {
  console( unsigned width, unsigned height )
    {
    SMALL_RECT r;
    COORD      c;
    hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (!GetConsoleScreenBufferInfo( hConOut, &csbi ))
      throw runtime_error( "You must be attached to a human." );

    r.Left   =
    r.Top    = 0;
    r.Right  = width -1;
    r.Bottom = height -1;
    SetConsoleWindowInfo( hConOut, TRUE, &r );

    c.X = width;
    c.Y = height;
    SetConsoleScreenBufferSize( hConOut, c );
    }

  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  };

console con( 85, 35 );

//------------

int vidaTotal=30, amizadeTotal=0, dia=1, pergunta, morte=0, falaPocky, a;

char matriz[TAM][TAM], matrizVida[20][5];

string resposta, nomeJogador, objetivoJogador, rival="Aluisio";

void PrintNormal();
void PrintSorriso();
void PrintMegaSorriso();
void PrintQuaseMorto();
void PrintPassandoMal();
void PrintMorto();
void BarraDeVida();
void BarraAmizade();
void identificadorDeHumor();
void PrintApresentacao();
void instructions();
void pockyPergunta01();
void pockyPergunta02();
void pockyPergunta03();
void pockyPergunta04();
void pockyPergunta05();
void pockyPergunta06();
void pockyPergunta07();
void pockyPergunta08();
void pockyPergunta09();
void pockyPergunta10();
void pockyPergunta11();
void pockyPergunta12();
void pockyPergunta13();
void pockyPergunta14();
void pockyPergunta15();
void pockyPergunta16();
void pockyPergunta17();
void pockyPergunta18();
void pockyPergunta19();
void pockyPergunta20();
void pockyPergunta21();
void pockyPergunta22();
void pockyPergunta23();
void pockyPergunta24();
void pockyPergunta25();
void pockyPergunta26();
void pockyPergunta27();
void pockyPergunta28();
void pockyPergunta29();
void pockyPergunta30();
void pockyPergunta31();
void pockyPergunta32();

int main(){

rlutil::setConsoleTitle("Pocky - O Seu bixinho virtual");

PrintApresentacao();

while(dia<30 && morte==0){

    srand(time(0));

    pergunta = (rand() % 27) + 1;

    switch(pergunta){

    case 1:
    pockyPergunta01();
    break;

    case 2:
    pockyPergunta02();
    break;

    case 3:
    pockyPergunta03();
    break;

    case 4:
    pockyPergunta04();
    break;

    case 5:
    pockyPergunta05();
    break;

    case 6:
    pockyPergunta06();
    break;

    case 7:
    pockyPergunta07();
    break;

    case 8:
    pockyPergunta08();
    break;

    case 9:
    pockyPergunta09();
    break;

    case 10:
    pockyPergunta10();
    break;

    case 11:
    pockyPergunta11();
    break;

    case 12:
    pockyPergunta12();
    break;

    case 13:
    pockyPergunta13();
    break;

    case 14:
    pockyPergunta14();
    break;

    case 15:
    pockyPergunta15();
    break;

    case 16:
    pockyPergunta16();
    break;

    case 17:
    pockyPergunta17();
    break;

    case 18:
    pockyPergunta18();
    break;

    case 19:
    pockyPergunta19();
    break;

    case 20:
    pockyPergunta20();
    break;

    case 21:
    pockyPergunta21();
    break;

    case 22:
    pockyPergunta22();
    break;

    case 23:
    pockyPergunta23();
    break;

    case 24:
    pockyPergunta24();
    break;

    case 25:
    pockyPergunta25();
    break;

    case 26:
    pockyPergunta26();
    break;

    case 27:
    pockyPergunta27();
    break;

    case 28:
    pockyPergunta28();
    break;

    case 29:
    pockyPergunta29();
    break;

    case 30:
    pockyPergunta30();
    break;

    case 31:
    pockyPergunta31();
    break;

    case 32:
    pockyPergunta32();
    break;

    }

    if(vidaTotal==0){
        morte=1;
    }
}

    if(morte==1){

        rlutil::cls();
        cout<<"\n\n\n\n"<<endl;
        identificadorDeHumor();

        cout<<"\n                     Pocky esta morto. E e tudo culpa sua. ;-;\n\n"<<endl;
    } else {

        rlutil::cls();
        cout<<"\n\n\n\n"<<endl;
        PrintMegaSorriso();
        cout<<"\n\n"<<endl;

        if(pergunta>=1 && pergunta<=5){
            cout<<"\n                                  MEU HEROI!!\n";
        } else {
            cout<<"\n                                  EU TE AMO!!\n";
        }

        cout<<"\n                          Parabens voce ganhou!!!\n\n"<<endl;
        }

    cin>>resposta;
}

void PrintApresentacao(){

int i;

rlutil::setColor(15);

cout<<"\n";
cout<<"     Por Angelo Leite [2017]"<<endl;

cout<< "\n                                   POCKY - O SLIME \n"<<endl;

PrintSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                             - Oi, sou Pocky. TUDO BOM?\n\n"<<endl;

cout<<">";
getline(cin, resposta);

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintMegaSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                             - Hehe... "<<resposta<<" pra voce tambem!! \n                                   Qual o seu NOME?\n\n\n"<<endl;

cout<<">";
getline(cin, nomeJogador);

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintNormal();

cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                               - "<<nomeJogador<<"? Serio mesmo? \n\n"<<endl;

cout<<">";
getline(cin, resposta);

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n          - Bem.. enfim: deseja ouvir as instrucoes? Pressione 'E'"<<endl;
cout<<"\n          - Se nao, pressione ESPACO para continuar"<<endl;

while (true) {
    if (kbhit()) {
        char k = getch();

        if (k == 'e') instructions();
        else if (k == ' ') break;

    }
}

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintMegaSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                   - "<<resposta<<"?? Voce me parece bem animado! PRONTO??\n"<<endl;

cout<<"\n"<<endl;

waitkey;
}

void identificadorDeHumor(){

    falaPocky = rand()%3 + 1;

    if(vidaTotal==30){
        PrintMegaSorriso();
        if(falaPocky==1)
            cout<<"\n                         - DoobieDoo! Nunca me senti tao bem!\n"<<endl;
        if(falaPocky==2)
            cout<<"\n                                 - Estou tao feliz!\n"<<endl;
        if(falaPocky==3)
            cout<<"\n                            - Slimes adoram matematica!\n"<<endl;
    } else {
        if(vidaTotal<30 && vidaTotal>=20){
            PrintSorriso();
            if(falaPocky==1)
                cout<<"\n                           - Estou me sentindo saudavel!\n"<<endl;
            if(falaPocky==2)
                cout<<"\n                           - Voce nao adora dias de chuva?\n"<<endl;
            if(falaPocky==3)
                cout<<"\n                               - Slimes nao tem Deus.\n"<<endl;
        } else {
            if(vidaTotal<20 && vidaTotal>=12){
                PrintNormal();
                if(falaPocky==1)
                    cout<<"\n                         - Ja tive dias melhores. Mas estou OK.\n"<<endl;
                if(falaPocky==2)
                    cout<<"\n                         - Queria estar escutando Titas agora.\n"<<endl;
                if(falaPocky==3)
                    cout<<"\n                         - Meu corpinho de Slime nao aguenta CALOR!\n"<<endl;

            } else {
                if(vidaTotal<12 && vidaTotal>=7){
                    PrintPassandoMal();
                    if(falaPocky==1){
                        cout<<"\n                         - Nao... me sinto muito bem\n"<<endl;
                    } else {
                        cout<<"\n                         - Por que voce nao gosta de mim?\n"<<endl;
                    }
                } else {
                    if(vidaTotal<7 && vidaTotal>0){
                        PrintQuaseMorto();
                        cout<<"\n                         - ..."<<endl;
                    } else {
                        if(vidaTotal==0){
                            PrintMorto();
                            if(falaPocky==1){
                                    cout<<"\n\n"<<endl;
                                    cout<<"\n                          LAPIDE: MORTO POR MAUS TRATOS\n"<<endl;
                                } else {
                                    cout<<"\n\n"<<endl;
                                    cout<<"\n              LAPIDE: 'APENAS OS FORTES VIVEM PARA SUPORTAR O SOFRIMENTO'\n"<<endl;
                            }
                        }
                    }
                }
            }
        }
    }

}

void instructions() {

rlutil::setColor(15);

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n           - O jogo eh o seguinte: voce deve cuidar de mim durante 30 dias, e eu so\n                      vou comer se voce voce for legal comigo!!\n\n"<<endl;

waitkey;


rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintNormal();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                       - A barra VERMELHA abaixo eh a minha VIDA.\n                       Quando ela se esvazia por completo eu...\n\n"<<endl;

waitkey;

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                        - Na verdade eu nao sei o que acontece!\n\n"<<endl;

waitkey;

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintMegaSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

amizadeTotal = 15;

BarraDeVida();
BarraAmizade();

cout<<"\n                 - A barra VERDE eh a barra de AMIZADE.. quando voce acerta\n                                 uma pergunta ela sobe!\n\n"<<endl;

waitkey;

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                - E quando enche por completo eu recupero um pouco de VIDA!\n\n"<<endl;

waitkey;

amizadeTotal = 0;
rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                      - Presta atencao a tudo que eu disser...\n\n"<<endl;

waitkey;

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintMegaSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                  - Eh essencial para voce nao responder errado!\n\n"<<endl;

waitkey;

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintNormal();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n                  - Ah, e mais uma coisa: Slimes tem ouvidos internos, \n              entao se voce puder responder em CAIXA ALTA suas chances\n                      de nos entendermos sao beeeem maiores!\n\n"<<endl;

waitkey;

rlutil::cls();
cout<<"\n\n\n\n"<<endl;

PrintSorriso();

cout<< "\n                                      - DIA "<<dia<<" -\n                                         "<<endl;

BarraDeVida();
BarraAmizade();

cout<<"\n            - Bem, acho que eh so isso! Pressione ESPACO para prosseguirmos!\n\n"<<endl;

}

void pockyPergunta01(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n         - Voce e a favor dos direitos a bolsas nas universidades para Slimes?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="sim" ||resposta=="SIM" ||resposta=="claro" ||resposta=="CLARO" ||resposta=="Sim" ||resposta=="Claro" || resposta=="sou" || resposta=="Sou" || resposta=="SOU"){

         amizadeTotal += 10;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
            }

    dia++;

    cout<<"\n"<<endl;
}


void pockyPergunta02(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n          - Voce ajudaria um Slime muito muito idoso a achar o caminho de casa?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="sim" ||resposta=="SIM" ||resposta=="claro" ||resposta=="CLARO" ||resposta=="Sim" ||resposta=="Claro"){

         amizadeTotal += 10;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta03(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n            - Voce acredita no Deus Slime que faz chover pudim? SIM ou NAO?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="nao" ||resposta=="NAO" ||resposta=="não" ||resposta=="NÃO"){

         amizadeTotal += 10;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"\n                                   - Ora, bobagem sua.\n"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta04(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Oque voce prefere? FRIO ou CALOR?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="FRIO" || resposta=="frio"){

        amizadeTotal += 10;
        cout<<"\n                       - Frio eh demais!! :D\n"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"\n                       - Não gosto MESMO de "<<resposta<<" :P\n"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta05(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Me ajude com o dever de matematica:"<<endl;
    cout<<"\n               Quanto e 12 dividido por 4 vezes 11 mais 3, tudo isso menos 10?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="26"){

        amizadeTotal += 10;
        cout<<"\n                       - Acerto mizeravi\n"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"\n                    - Acho que... nao e " <<resposta<<" nao...\n"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta06(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                  - Existe diferenca entre a Alpaca e a Lhama? SIM ou NAO?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="sim" ||resposta=="SIM"){

        amizadeTotal += 10;
        cout<<"\n                       - Mas qual sera o som da Lhama? hmmmm...\n"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"\n                   - Tem certeza que "<<resposta<<" e a resposta mesmo??"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta07(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                  - O Slime plofta, a vaca muge e o gato...?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="MIA" || resposta=="mia"){

        amizadeTotal += 10;
        cout<<"\n                       - Miau! Quer dizer... PLOFf-t..!\n"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"\n                   - Um dia um gatinho chegou pra mim e disse: \n                    - "<<resposta<<"! "<<resposta<<"! "<<resposta<<"! \n                     e eu disse: - Voce nao e um gato nao!"<<endl;
                waitkey;
            }
    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta08(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Me ajude com o dever de matemática:"<<endl;
    cout<<"\n               Quanto e 7 vezes 6 mais 5 mais 3, tudo isso dividido por 10?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="5"){

        amizadeTotal += 10;
        cout<<"\n                       - Acerto mizeravi\n"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"\n                    - Acho que... nao e " <<resposta<<" nao...\n"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;

}

void pockyPergunta09(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Voce gosta de musica?"<<endl;

    cout<<">";
    getline (cin, resposta);

    cout<<"\n          - Que bom!! Complete essa musica do Titas entao: 'E preciso saber (...)'\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="viver" || resposta=="VIVER"){

        amizadeTotal += 10;
        cout<<"\n             - E preciso saber VIVER, e preciso saber VIVER! Yeah!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"\n            - E preciso saber "<<resposta<<", e preciso saber "<<resposta<<"... espera aí, isso parece errado\n"<<endl
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta10(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n               - Quem sera o rei dos piratas? e gosta muito de carne?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="LUFFY" || resposta=="luffy" || resposta=="Luffy" || resposta=="Monkey D. Luffy" || resposta=="MONKEY D LUFFY" || resposta=="MONKEY D. LUFFY"){

        amizadeTotal += 10;
        cout<<"\n                       - Arittakeno yume o kakiatsumeeee"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"\n                                     - "<<resposta<<"? Ata.\n"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;

}

void pockyPergunta11(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                - Quem fala errado na Turma da Slonica: CEBOLIME ou a SLONICA?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="CEBOLIME" || resposta=="meu cu" || resposta=="cebolime" || resposta=="Cebolime"){

        amizadeTotal += 10;
        cout<<"\n                       - Issooooo!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"\n                                     - "<<resposta<<"? Ata.\n"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;

}

void pockyPergunta12(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                            - Quem e seu Slime favorito?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="POCKY" || resposta=="pocky" || resposta=="Pocky"){

        amizadeTotal += 10;
        cout<<"                  - Isso mesmo..."<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                rival = resposta;
                vidaTotal -= 3;
                cout<<"                -"<<rival<<"?? Quem e esse ai?? Ja sei! "<<rival<<" e o nome do meu rival!! Nao esquecerei!"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;

}

void pockyPergunta13(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                - Qual a marca mais famosa do mundo?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="GOOGLE" || resposta=="google" || resposta=="Google"){

        amizadeTotal += 10;
        cout<<"                  - Isso mesmo!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - Nunca ouvi falar dessa tal de "<<resposta<<", sempre achei que fosse ou a GOOGLE\n                        ou as 'Tortas da tia Betty Slime'...!"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta14(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                                 - Quem me criou?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="ANGELIME" || resposta=="Angelime"){

        amizadeTotal += 10;
        cout<<"                  - Aquele lindo!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - "<<resposta<<"? Naaaaaaooo, meu criador se chama ANGELIME."<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta15(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                            - Qual o meu anime favorito?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="One Piece" || resposta=="ONE PIECE" || resposta=="one piece" || resposta=="One piece"){

        amizadeTotal += 10;
        cout<<"                  - Sagashi mono sagashi ni yuku no saaa.. "<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"                 - Nao gostei de "<<resposta<<", tem muitos fillers."<<endl;
                waitkey;
            }
    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta16(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                - Qual o meu filme favorito? Uma dica: tem um barco beeeemm grande...\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="Titanic" || resposta=="TITANIC"){

        amizadeTotal += 10;
        cout<<"                  - Acertouuuu!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - Que horror, eu dormi assistindo "<<resposta<<"."<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta17(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;
    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                - Qual a minha comida favorita? Uma dica: eu nao gosto de comer...\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="Nada" || resposta=="NADA"){

        amizadeTotal += 10;
        cout<<"                  - Isso mesmo! O gosto de comida e horrivel..."<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"                         - "<<resposta<<" tem gosto de coco de slime! Eu nao gosto de NADA!!"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta18(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Qual e o dia que se comemora o Natal?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="26"){

        amizadeTotal += 10;
        cout<<"                  - De dezembro! Isso mesmo."<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - Ah, entao foi por isso que voce nao me troxe meu presente..."<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta19(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                - Slimes tem genero?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="NAO" || resposta=="Nao"){

        amizadeTotal += 10;
        cout<<"                  - Eu amo todo mundoooooo"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - Qual eh a sua, "<<nomeJogador<<"?"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta20(){
    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                - Que pais inventou a cerveja?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="Slimelandia" || resposta=="SLIMELANDIA"){

        amizadeTotal += 10;
        cout<<"                  - Tambem inventamos o incenso e o papel higienico!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - "<<resposta<<"? Naaaaooo, foi a SLIMELANDIA!"<<endl;
                waitkey;
            }
    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta21(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Quem derrotou o Majinboo?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="GOKU" || resposta=="Goku" || resposta=="goku"){

        amizadeTotal += 10;
        cout<<"                  - Pocket no coin, soreto you wanna be my friend? (6)'"<<endl;
        waitkey;
        cout<<"\n                 - Perai";
        Sleep(1000);
        cout<<" .";
        Sleep(1000);
        cout<<" .";
        Sleep(1000);
        cout<<" .";
        cout<<" o Goku nao eh do OnePiece!\n"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"                           - Quem eh esse "<<resposta<<"? Ele e amigo do GOKU?"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta22(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Qual minha cor favorita?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="VERDE" || resposta=="Verde" || resposta=="verde"){

        amizadeTotal += 10;
        cout<<"                  - Duuuuhhh hahahaha!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - Pense melhor "<<nomeJogador<<"... qual eh a minha cor???"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta23(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - O que eu gosto de fazer nas horas vagas?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="SLIMAR" || resposta=="Slimar" || resposta=="slimar"){

        amizadeTotal += 10;
        cout<<"                  - Smuf... SLIMAR!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - Eu nao gosto de "<<resposta<<", gosto mesmo eh de SLIMAR!"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta24(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Qual o verdadeiro sentido do Natal?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="Comida" || resposta=="COMIDA" || resposta=="comida"){

        amizadeTotal += 10;
        cout<<"                  - E por comida, eu quero dizer ferias."<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - Que "<<resposta<<" o que... o real sentido eh COMIDA."<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta25(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                - Como se pronuncia eh o nome do simbolo matematico que representa\n                              o numero 2,14 + 1?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="PI" || resposta=="pi" || resposta=="Pi"){

        amizadeTotal += 10;
        cout<<"                  - Temos um genio entre nos!!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - Tenho certeza que nao eh isso."<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta26(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Slimes VOAM, NADAM, ou PULAM?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="PULAM" || resposta=="Pulam" || resposta=="pulam"){

        amizadeTotal += 10;
        cout<<"                  - Temos um genio entre nos!!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - Obviamente nos PULAMOS, eu nem sei o que eh "<<resposta<<"..."<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta27(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Vamos jogar PEDRA, PAPEL E TESOURA!\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="PEDRA" || resposta=="PAPEL" || resposta=="TESOURA" || resposta=="Pedra" || resposta=="Papel" || resposta=="Tesoura" || resposta=="pedra" || resposta=="papel" || resposta=="tesoura"){

        amizadeTotal += 10;
        cout<<"                     - Arrrgh.. voce ganhou denovo!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"                  - "<<resposta<<"... essa jogada e permitida?"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta28(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Qual o nome daquele planeta vermelho que todo mundo fala?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="MARTE" || resposta=="Marte" || resposta=="marte"){

        amizadeTotal += 10;
        cout<<"                     - O nome marte eh inspirado no nome de um deus grego da guerra..."<<endl;
        waitkey;
        cout<<"                     - Li isso na caixa de cereal hoje de manha"<<endl;
        waitkey;
        cout<<"                     - Nao, eu nao comi o cereal, so li a caixa mesmo. ¯\_(:])_/¯"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - "<<resposta<<"? Não sabia que isso era o nome de um planeta. "<<resposta<<" fica no nosso sistema solar?"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta29(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Você gosta do filme Slime-Aranha?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    cout<<"\n           - Que bom!! Entao complete essa frase do tio Ben: 'Com grandes poderes, vem grandes (...)'\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="RESPONSABILIDADES" || resposta=="Responsabilidades" || resposta=="responsabilidades"){

        amizadeTotal += 10;
        cout<<"      - 'Com grandes poderes vem grandes "<<resposta<<"!' Acertou "<<nomeJogador<<"!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - 'Com grandes poderes vem grandes "<<resposta<<"...' Acho que tem alguma coisa errada "<<nomeJogador<<"..."<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta30(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n     - Você gostaria de ter todo o queijo do mundo, mas todo queijo falaria com voce e imploraria para nao ser comido? SIM ou NAO?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="SIM" || resposta=="Sim" || resposta=="NAO" || resposta=="Nao"){

        amizadeTotal += 10;
        cout<<"           - Hehe "<<nomeJogador<<"... Queijo nao tem alma afinal.."<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - "<<resposta<<"? Isso e uma resposta valida por acaso?"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta31(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n                       - Qual seu objetivo de vida?\n\n"<<endl;

    cout<<">";
    getline(cin, objetivoJogador);

    cout<<"\n                       - "<<resposta<<"? Tem certeza mesmo?\n\n"<<endl;
    cout<<"\n           - Voce aceitaria R$1000000 para desistir desse objetivo? SIM ou NAO??\n\n"<<endl;

     if(resposta=="SIM" || resposta=="Sim" || resposta=="NAO" || resposta=="Nao"){

        amizadeTotal += 10;
        cout<<"            - Sera que muita gente que faz "<<resposta<<" no mundo?"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - O que "<<resposta<<" significa??"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void pockyPergunta32(){

    rlutil::cls();
    cout<<"\n\n\n\n"<<endl;

    identificadorDeHumor();

    cout<< "\n                                      - DIA "<<dia<<" -\n\n                                         VIDA "<<endl;

    BarraDeVida();
    BarraAmizade();

    cout<<"\n          - Voce gostaria de ter todos os poderes do Super-Slime, mas so poderia usa-los quando ninguem estivesse vendo? SIM ou NAO?\n\n"<<endl;

    cout<<">";
    getline(cin, resposta);

    if(resposta=="SIM" || resposta=="Sim" || resposta=="NAO" || resposta=="Nao"){

        amizadeTotal += 10;
        cout<<"           - Eu gostaria! Nao tem literalmente nenhum maleficio!"<<endl;
        waitkey;

         if (amizadeTotal == 30){
                vidaTotal += 3;
                amizadeTotal = 0;
            }

         if (vidaTotal>=30){
                vidaTotal = 30;
            }

            } else {
                vidaTotal -= 3;
                cout<<"          - "<<resposta<<"? Ahn?"<<endl;
                waitkey;
            }

    dia++;

    cout<<"\n"<<endl;
}

void BarraAmizade(){

int i;
char v1[15], v2[15], v3[15];

    cout<<"                           ";
    for(i=0; i<amizadeTotal; i++){
        rlutil::setBackgroundColor(3);
        rlutil::setColor(10);
        v2[i]=char(254);
        cout<<v2[i];
        rlutil::setColor(15);
        rlutil::setBackgroundColor(0);
        }

        cout<<endl;

    cout<<"                           ";
    for(i=0; i<30; i++){
        v3[i]=char(205);
        cout<<v3[i];
        }

        cout<<endl;

}

void BarraDeVida(){

int i;
char v1[15], v2[15], v3[15];

    cout<<"                           ";
    for(i=0; i<30; i++){
        v3[i]=char(205);
        cout<<v3[i];
        }

        cout<<endl;

    cout<<"                           ";
    for(i=0; i<vidaTotal; i++){
        rlutil::setBackgroundColor(4);
        rlutil::setColor(12);
        v2[i]=char(254);
        cout<<v2[i];
        rlutil::setColor(15);
        rlutil::setBackgroundColor(0);
        }

        cout<<endl;

    cout<<"                           ";
    for(i=0; i<30; i++){
        v3[i]=char(205);
        cout<<v3[i];
        }

        cout<<endl;

    }

void PrintNormal(){
    int i, j;
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            if(i==3 && j==2 ||
               i==3 && j==3 ||
               i==3 && j==4 ||
               i==4 && j==2 ||
               i==4 && j==3 ||
               i==4 && j==4 ||
               i==5 && j==2 ||
               i==5 && j==3 ||
               i==5 && j==4 ||
               i==3 && j==10 ||
               i==3 && j==11 ||
               i==3 && j==12 ||
               i==4 && j==10 ||
               i==4 && j==11 ||
               i==4 && j==12 ||
               i==5 && j==10 ||
               i==5 && j==11 ||
               i==5 && j==12 ||
               i==9 && j==2 ||
               i==9 && j==3 ||
               i==9 && j==4 ||
               i==9 && j==5 ||
               i==9 && j==6 ||
               i==9 && j==7 ||
               i==9 && j==8 ||
               i==9 && j==9 ||
               i==9 && j==10 ||
               i==9 && j==11 ||
               i==8 && j==11 ||
               i==10 && j==11

               ){
                matriz[i][j]=' ';
            }else{
            matriz[i][j]=char(254);
            }
        }
    }


        for(i=0; i<15; i++){
            cout<<"                           ";        //movimento para meio da tela
            for(j=0; j<15; j++){
                rlutil::setColor(10);
            rlutil::setBackgroundColor(2);
            cout<<" "<<matriz[i][j];

        }
        rlutil::setColor(15);
        rlutil::setBackgroundColor(0);
        cout<<endl;
        }
    }


void PrintSorriso(){
    int i, j;
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            if(i==3 && j==2 ||
               i==3 && j==3 ||
               i==3 && j==4 ||
               i==4 && j==2 ||
               i==4 && j==3 ||
               i==4 && j==4 ||
               i==5 && j==2 ||
               i==5 && j==3 ||
               i==5 && j==4 ||
               i==3 && j==10 ||
               i==3 && j==11 ||
               i==3 && j==12 ||
               i==4 && j==10 ||
               i==4 && j==11 ||
               i==4 && j==12 ||
               i==5 && j==10 ||
               i==5 && j==11 ||
               i==5 && j==12 ||
               i==9 && j==2 ||
               i==9 && j==3 ||
               i==9 && j==4 ||
               i==9 && j==5 ||
               i==9 && j==6 ||
               i==9 && j==7 ||
               i==9 && j==8 ||
               i==9 && j==9 ||
               i==9 && j==10 ||
               i==9 && j==11 ||
               i==8 && j==11 ||
               i==10 && j==11 ||
               i==11 && j==11 ||
               i==10 && j==3 ||
               i==11 && j==4 ||
               i==11 && j==5 ||
               i==11 && j==6 ||
               i==11 && j==7 ||
               i==11 && j==8 ||
               i==11 && j==9 ||
               i==11 && j==10 ||
               i==10 && j==4 ||
               i==10 && j==5 ||
               i==10 && j==6 ||
               i==10 && j==7 ||
               i==10 && j==8 ||
               i==10 && j==9 ||
               i==10 && j==10 ||
               i==10 && j==11
               ){

                matriz[i][j]=' ';
            }else{

            matriz[i][j]=char(254);
            }
        }
    }


    for(i=0; i<15; i++){
        cout<<"                           ";        //movimento para meio da tela
        for(j=0; j<15; j++){
            rlutil::setColor(10);
            rlutil::setBackgroundColor(2);
            cout<<" "<<matriz[i][j];

        }
        rlutil::setColor(15);
        rlutil::setBackgroundColor(0);
        cout<<endl;
    }

}

void PrintMegaSorriso(){

    int i, j;
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            if(i==4 && j==2 ||
               i==4 && j==3 ||
               i==4 && j==4 ||
               i==4 && j==10 ||
               i==4 && j==11 ||
               i==4 && j==12 ||
               i==8 && j==2 ||
               i==8 && j==3 ||
               i==8 && j==4 ||
               i==8 && j==10 ||
               i==9 && j==3 ||
               i==9 && j==4 ||
               i==9 && j==5 ||
               i==9 && j==6 ||
               i==9 && j==7 ||
               i==9 && j==8 ||
               i==9 && j==9 ||
               i==9 && j==10 ||
               i==9 && j==11 ||
               i==8 && j==5 ||
               i==8 && j==6 ||
               i==8 && j==7 ||
               i==8 && j==8 ||
               i==8 && j==9 ||
               i==8 && j==11 ||
               i==10 && j==11 ||
               i==10 && j==3 ||
               i==10 && j==4 ||
               i==10 && j==5 ||
               i==10 && j==6 ||
               i==10 && j==7 ||
               i==10 && j==8 ||
               i==10 && j==9 ||
               i==10 && j==10 ||
               i==10 && j==11 ||
               i==11 && j==4 ||
               i==11 && j==5 ||
               i==11 && j==6 ||
               i==11 && j==7 ||
               i==11 && j==8 ||
               i==11 && j==9 ||
               i==11 && j==10 )
               {
                matriz[i][j]=' ';
            }else{
            matriz[i][j]=char(254);
            }
        }
    }


    for(i=0; i<15; i++){
        cout<<"                           ";        //movimento para meio da tela
        for(j=0; j<15; j++){
            rlutil::setColor(10);
            rlutil::setBackgroundColor(2);
            cout<<" "<<matriz[i][j];

        }
        rlutil::setColor(15);
        rlutil::setBackgroundColor(0);
        cout<<endl;
    }
}

void PrintPassandoMal(){
    int i, j;
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            if(i==3 && j==2 ||
               i==3 && j==3 ||
               i==3 && j==4 ||
               i==4 && j==2 ||
               i==4 && j==3 ||
               i==4 && j==4 ||
               i==3 && j==10 ||
               i==3 && j==11 ||
               i==3 && j==12 ||
               i==4 && j==10 ||
               i==4 && j==11 ||
               i==4 && j==12 ||
               i==5 && j==10 ||
               i==5 && j==11 ||
               i==5 && j==12 ||
               i==9 && j==2 ||
               i==9 && j==3 ||
               i==9 && j==4 ||
               i==9 && j==5 ||
               i==9 && j==6 ||
               i==9 && j==7 ||
               i==9 && j==8 ||
               i==9 && j==9 ||
               i==9 && j==10 ||
               i==10 && j==11 ||
               i==11 && j==11 ||
               i==10 && j==3 ||
               i==11 && j==4 ||
               i==11 && j==5 ||
               i==11 && j==6 ||
               i==11 && j==7 ||
               i==11 && j==8 ||
               i==11 && j==9 ||
               i==11 && j==10 ||
               i==10 && j==4 ||
               i==10 && j==5 ||
               i==10 && j==6 ||
               i==10 && j==7 ||
               i==10 && j==8 ||
               i==10 && j==9 ||
               i==10 && j==10 ||
               i==10 && j==11)
               {
                matriz[i][j]=' ';
            }else{
            matriz[i][j]=char(254);
            }
        }
    }
    for(i=0; i<15; i++){
        cout<<"                           ";        //movimento para meio da tela
        for(j=0; j<15; j++){
            rlutil::setColor(10);
            rlutil::setBackgroundColor(2);
            cout<<" "<<matriz[i][j];

        }
        rlutil::setColor(15);
        rlutil::setBackgroundColor(0);
        cout<<endl;
    }

}


void PrintQuaseMorto(){
    int i, j;
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            if(i==3 && j==2 ||
               i==3 && j==3 ||
               i==3 && j==4 ||
               i==4 && j==2 ||
               i==4 && j==4 ||
               i==5 && j==2 ||
               i==5 && j==3 ||
               i==5 && j==4 ||
               i==3 && j==10 ||
               i==3 && j==11 ||
               i==3 && j==12 ||
               i==4 && j==10 ||
               i==4 && j==12 ||
               i==5 && j==10 ||
               i==5 && j==11 ||
               i==5 && j==12 ||
               i==9 && j==2 ||
               i==9 && j==3 ||
               i==9 && j==4 ||
               i==9 && j==5 ||
               i==9 && j==6 ||
               i==9 && j==7 ||
               i==9 && j==8 ||
               i==9 && j==9 ||
               i==9 && j==10 ||
               i==9 && j==11 ||
               i==9 && j==12 ||
               i==10 && j==11 ||
               i==11 && j==11
               ){
                matriz[i][j]=' ';
            }else{
            matriz[i][j]=char(254);
            }
        }
    }


        for(i=0; i<15; i++){
            cout<<"                           ";        //movimento para meio da tela
            for(j=0; j<15; j++){
                rlutil::setColor(10);
            rlutil::setBackgroundColor(2);
            cout<<" "<<matriz[i][j];

        }
        rlutil::setColor(15);
        rlutil::setBackgroundColor(0);
        cout<<endl;
        }

}


void PrintMorto(){
    int i, j;
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            if(i==3 && j==2 ||
               i==3 && j==4 ||
               i==4 && j==3 ||
               i==5 && j==2 ||
               i==5 && j==4 ||
               i==3 && j==10 ||
               i==3 && j==12 ||
               i==4 && j==11 ||
               i==5 && j==10 ||
               i==5 && j==12
               ){
                matriz[i][j]=' ';
            }else{
            matriz[i][j]=char(254);
            }
        }
    }
        for(i=0; i<15; i++){
            cout<<"                           ";        //movimento para meio da tela
            for(j=0; j<15; j++){
               rlutil::setColor(10);
            rlutil::setBackgroundColor(2);
            cout<<" "<<matriz[i][j];

        }
        rlutil::setColor(15);
        rlutil::setBackgroundColor(0);
        cout<<endl;
        }
}
