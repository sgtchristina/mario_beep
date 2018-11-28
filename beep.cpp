#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#include "conio.h" 
enum COLORS
{
BLACK = 0,
BLUE = 1,
GREEN = 2,
CYAN = 3,
RED = 4,
MAGENTA = 5,
BROWN = 6,
LIGHTGRAY = 7,
DARKGRAY = 8,
LIGHTBLUE = 9,
LIGHTGREEN = 10,
LIGHTCYAN = 11,
LIGHTRED = 12,
LIGHTMAGENTA = 13,
YELLOW = 14,
WHITE = 15,
BLINK = 128
};
struct text_info
{
unsigned char winleft; 
unsigned char wintop;
unsigned char winright;
unsigned char winbottom;
unsigned char attribute;
unsigned char normattr; 
unsigned char currmode; 
unsigned char screenheight; 
unsigned char screenwidth; 
unsigned char curx; 
unsigned char cury; 
};
enum text_modes {
LASTMODE=-1,
BW40=0,
C40,
BW80,
C80,
MONO=7,
C4350=64
};

text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 25, 80, 1, 1}; //Utilizada para o funcionamento das funções textcolor e textbackground
void textcolor(int); /* Cor de primeiro plano [bLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE] */
void textbackground(int); //Cor de Fundo [Definida pelas mesmas constantes da textcolor, 
void musica(void); //Usa duas outras funções da biblioteca windows.h que serve para emitir alertas sonoros Beep(freq,temp); e Sleep(temp);
void gogumelo(void); //Cria um gogumelo em ascii colorido com as funções textcolor e textbackground
void redefine(void); //Define o tamanho da tela com chamada do sistema
/* Função Principal */
int main(void){
redefine();
gogumelo();
musica();
Sleep(1000); //Temporizador
return 0;
}
/* Fim da Função Principal */
//Função textcolor: Define a cor de primeiro plano dos textos
void textcolor(int newcolor)
{
CONSOLE_SCREEN_BUFFER_INFO csbi;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
(csbi.wAttributes & 0xf0) | newcolor);
vActual.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}
//Função textbackground: Define a cor de fundo das fontes.
void textbackground(int newcolor)
{
CONSOLE_SCREEN_BUFFER_INFO csbi;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
(csbi.wAttributes & 0x0f) | (newcolor << 4));
vActual.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}
void gogumelo(void){ //Imprime o gogumelo do Mario Bros (Gerada em ascii)
textcolor(WHITE);
textbackground(LIGHTGRAY); printf("_____________________________________________________\n");
textbackground(LIGHTGRAY); printf("_________________"); textbackground(BLACK); printf("¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶"); textbackground(LIGHTGRAY); printf("_______________\n");
textbackground(LIGHTGRAY); printf("_________________"); textbackground(LIGHTRED); printf("666666666666666666666"); textbackground(LIGHTGRAY); printf("_______________\n");
textbackground(LIGHTGRAY); printf("__________"); textbackground(BLACK); printf("¶¶¶¶¶¶¶"); textbackground(WHITE); printf("111111"); textbackground(LIGHTRED); printf("66666666"); textbackground(WHITE); printf("1111111"); textbackground(BLACK); printf("¶¶¶¶¶¶¶");textbackground(LIGHTGRAY); printf("________\n");
textbackground(LIGHTGRAY); printf("_______"); textbackground(BLACK); printf("¶¶¶"); textbackground(WHITE); printf("1111111111"); textbackground(LIGHTRED); printf("66666666666666"); textbackground(WHITE); printf("1111111111"); textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTGRAY); printf("______\n");
textbackground(LIGHTGRAY); printf("_______"); textbackground(BLACK); printf("¶¶¶"); textbackground(WHITE); printf("1111111111"); textbackground(LIGHTRED); printf("66666666666666"); textbackground(WHITE); printf("1111111111"); textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTGRAY); printf("______\n");
textbackground(LIGHTGRAY); printf("____"); textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTRED); printf("6666666666666"); textbackground(WHITE); printf("000TAINÁ0000"); textbackground(LIGHTRED); printf("6666666666666"); textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTGRAY); printf("___\n");
textbackground(LIGHTGRAY); printf("____"); textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTRED); printf("6666666666666"); textbackground(WHITE); printf("000CRISTINA000"); textbackground(LIGHTRED); printf("6666666666666"); textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTGRAY); printf("___\n");
textbackground(LIGHTGRAY); printf("____"); textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTRED); printf("6666666666"); textbackground(WHITE); printf("0000UNIS0MG000000000"); textbackground(LIGHTRED); printf("6666666666"); textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTGRAY); printf("___\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(WHITE); printf("111"); textbackground(LIGHTRED); printf("66666666"); textbackground(WHITE); printf("000000"); textbackground(WHITE); printf("11111111111111"); textbackground(WHITE); printf("000000"); textbackground(LIGHTRED); printf("6666666"); textbackground(WHITE); printf("111"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(WHITE); printf("111"); textbackground(LIGHTRED); printf("66666666"); textbackground(WHITE); printf("000000"); textbackground(WHITE); printf("11111111111111"); textbackground(WHITE); printf("000000"); textbackground(LIGHTRED); printf("6666666"); textbackground(WHITE); printf("111"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(WHITE); printf("1111111"); textbackground(LIGHTRED); printf("6666"); textbackground(WHITE); printf("000"); textbackground(WHITE); printf("11111111111111111111"); textbackground(WHITE); printf("000"); textbackground(LIGHTRED); printf("6666"); textbackground(WHITE); printf("111111"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(WHITE); printf("1111111"); textbackground(LIGHTRED); printf("6666"); textbackground(WHITE); printf("000"); textbackground(WHITE); printf("11111111111111111111"); textbackground(WHITE); printf("000"); textbackground(LIGHTRED); printf("6666"); textbackground(WHITE); printf("111111"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(WHITE); printf("1111111"); textbackground(LIGHTRED); printf("6666"); textbackground(WHITE); printf("000"); textbackground(WHITE); printf("11111111111111111111"); textbackground(WHITE); printf("000"); textbackground(LIGHTRED); printf("6666"); textbackground(WHITE); printf("111111"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(WHITE); printf("1111"); textbackground(LIGHTRED); printf("6666666666"); textbackground(WHITE); printf("11111111111111111111"); textbackground(LIGHTRED); printf("6666666666"); textbackground(WHITE); printf("111"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(WHITE); printf("1111"); textbackground(LIGHTRED); printf("6666666666"); textbackground(WHITE); printf("11111111111111111111"); textbackground(LIGHTRED); printf("6666666666"); textbackground(WHITE); printf("111"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTRED); printf("666666666666666666"); textbackground(WHITE); printf("111111111111"); textbackground(LIGHTRED); printf("66666666666666666"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTRED); printf("666666666666666666"); textbackground(WHITE); printf("111111111111"); textbackground(LIGHTRED); printf("66666666666666666"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(BLACK); printf("¶¶¶"); textbackground(LIGHTRED); printf("66666666666"); textbackground(BLACK); printf("¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶"); textbackground(LIGHTRED);printf("666666666"); textbackground(BLACK); printf("¶¶¶\n");
textbackground(LIGHTGRAY); printf("____"); textbackground(BLACK); printf("¶¶¶¶¶¶¶¶¶"); textbackground(YELLOW); printf("77777777"); textbackground(BLACK); printf("¶¶"); textbackground(YELLOW); printf("77777777"); textbackground(BLACK); printf("¶¶"); textbackground(YELLOW); printf("77777777"); textbackground(BLACK); printf("¶¶¶¶¶¶¶¶¶");textbackground(LIGHTGRAY); printf("___\n");
textbackground(LIGHTGRAY); printf("_______"); textbackground(BLACK); printf("¶¶"); textbackground(YELLOW); printf("7777"); textbackground(WHITE); printf("11111111"); textbackground(BLACK); printf("¶¶"); textbackground(WHITE); printf("11111111"); textbackground(BLACK); printf("¶¶"); textbackground(WHITE); printf("1111111"); textbackground(YELLOW); printf("7777"); textbackground(BLACK); printf("¶¶"); textbackground(LIGHTGRAY); printf("_______\n");
textbackground(LIGHTGRAY); printf("_______"); textbackground(BLACK); printf("¶¶"); textbackground(YELLOW); printf("7777"); textbackground(WHITE); printf("11111111"); textbackground(BLACK); printf("¶¶"); textbackground(WHITE); printf("11111111"); textbackground(BLACK); printf("¶¶"); textbackground(WHITE); printf("1111111"); textbackground(YELLOW); printf("7777"); textbackground(BLACK); printf("¶¶"); textbackground(LIGHTGRAY); printf("_______\n");
textbackground(LIGHTGRAY); printf("_______"); textbackground(BLACK); printf("¶¶"); textbackground(YELLOW); printf("7777"); textbackground(WHITE); printf("11111TAIN4CR15T1N4O11111"); textbackground(YELLOW); printf("7777"); textbackground(BLACK); printf("¶¶");textbackground(LIGHTGRAY); printf("_______\n");
textbackground(LIGHTGRAY); printf("_______"); textbackground(BLACK); printf("¶¶"); textbackground(YELLOW); printf("7777"); textbackground(WHITE); printf("11111MATHEUS11FLAUZINO11111"); textbackground(YELLOW); printf("7777"); textbackground(BLACK); printf("¶¶");textbackground(LIGHTGRAY); printf("_______\n");
textbackground(LIGHTGRAY); printf("___________"); textbackground(BLACK); printf("¶¶"); textbackground(YELLOW); printf("7777"); textbackground(WHITE); printf("11111111111111111111"); textbackground(YELLOW); printf("7777"); textbackground(BLACK); printf("¶¶"); textbackground(LIGHTGRAY); printf("__________\n");
textbackground(LIGHTGRAY); printf("_____________"); textbackground(YELLOW); printf("7777"); textbackground(WHITE); printf("11111111111111111111"); textbackground(YELLOW); printf("7777");textbackground(LIGHTGRAY); printf("____________\n");
textbackground(LIGHTGRAY); printf("_____________"); textbackground(BLACK); printf("¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶"); textbackground(LIGHTGRAY); printf("_____________ \n");
textbackground(LIGHTGRAY); printf("_____________________________________________________\n");
}
void musica(void){ 
Beep(660,100);Sleep(150); 
Beep(660,100);Sleep(300);
Beep(660,100);Sleep( 300);
Beep(510,100);Sleep( 100);
Beep(660,100);Sleep( 300);
Beep(770,100);Sleep( 550);
Beep(380,100);Sleep( 575);
Beep(510,100);Sleep( 450);
Beep(380,100);Sleep( 400);
Beep(320,100);Sleep( 500);
Beep(440,100);Sleep( 300);
Beep(480,80);Sleep( 330);
Beep(450,100);Sleep( 150);
Beep(430,100);Sleep( 300);
Beep(380,100);Sleep( 200);
Beep(660,80);Sleep( 200);
Beep(760,50);Sleep( 150);
Beep(860,100);Sleep( 300);
Beep(700,80);Sleep( 150);
Beep(760,50);Sleep( 350);
Beep(660,80);Sleep( 300);
Beep(520,80);Sleep( 150);
Beep(580,80);Sleep( 150);
Beep(480,80);Sleep( 500);
Beep(510,100);Sleep( 450);
Beep(380,100);Sleep( 400);
Beep(320,100);Sleep( 500);
Beep(440,100);Sleep( 300);
Beep(480,80);Sleep( 330);
Beep(450,100);Sleep( 150);
Beep(430,100);Sleep( 300);
Beep(380,100);Sleep( 200);
Beep(660,80);Sleep( 200);
Beep(760,50);Sleep( 150);
Beep(860,100);Sleep( 300);
Beep(700,80);Sleep( 150);
Beep(760,50);Sleep( 350);
Beep(660,80);Sleep( 300);
Beep(520,80);Sleep( 150);
Beep(580,80);Sleep( 150);
Beep(480,80);Sleep( 500);
Beep(500,100);Sleep( 300);
Beep(760,100);Sleep( 100);
Beep(720,100);Sleep( 150);
Beep(680,100);Sleep( 150);
Beep(620,150);Sleep( 300);
Beep(650,150);Sleep( 300);
Beep(380,100);Sleep( 150);
Beep(430,100);Sleep( 150);
Beep(500,100);Sleep( 300);
Beep(430,100);Sleep( 150);
Beep(500,100);Sleep( 100);
Beep(570,100);Sleep( 220);
Beep(500,100);Sleep( 300);
Beep(760,100);Sleep( 100);
Beep(720,100);Sleep( 150);
Beep(680,100);Sleep( 150);
Beep(620,150);Sleep( 300);
Beep(650,200);Sleep( 300);
Beep(1020,80);Sleep( 300);
Beep(1020,80);Sleep( 150);
Beep(1020,80);Sleep( 300);
Beep(380,100);Sleep( 300);
Beep(500,100);Sleep( 300);
Beep(760,100);Sleep( 100);
Beep(720,100);Sleep( 150);
Beep(680,100);Sleep( 150);
Beep(620,150);Sleep( 300);
Beep(650,150);Sleep( 300);
Beep(380,100);Sleep( 150);
Beep(430,100);Sleep(150);
Beep(500,100);Sleep(300);
Beep(430,100);Sleep(150);
Beep(500,100);Sleep( 100);
Beep(570,100);Sleep(420);
Beep(585,100);Sleep(450);
Beep(550,100);Sleep( 420);
Beep(500,100);Sleep(360);
Beep(380,100);Sleep(300);
Beep(500,100);Sleep(300);
Beep(500,100);Sleep( 150);
Beep(500,100);Sleep(300);
Beep(500,100);Sleep(300);
Beep(760,100);Sleep( 100);
Beep(720,100);Sleep( 150);
Beep(680,100);Sleep( 150);
Beep(620,150);Sleep( 300);
Beep(650,150);Sleep( 300);
Beep(380,100);Sleep( 150);
Beep(430,100);Sleep( 150);
Beep(500,100);Sleep( 300);
Beep(430,100);Sleep( 150);
Beep(500,100);Sleep( 100);
Beep(570,100);Sleep( 220);
Beep(500,100);Sleep( 300);
Beep(760,100);Sleep( 100);
Beep(720,100);Sleep( 150);
Beep(680,100);Sleep( 150);
Beep(620,150);Sleep( 300);
Beep(650,200);Sleep( 300);
Beep(1020,80);Sleep( 300);
Beep(1020,80);Sleep( 150);
Beep(1020,80);Sleep( 300);
Beep(380,100);Sleep( 300);
Beep(500,100);Sleep( 300);
Beep(760,100);Sleep( 100);
Beep(720,100);Sleep( 150);
Beep(680,100);Sleep( 150);
Beep(620,150);Sleep( 300);
Beep(650,150);Sleep( 300);
Beep(380,100);Sleep( 150);
Beep(430,100);Sleep( 150);
Beep(500,100);Sleep( 300);
Beep(430,100);Sleep( 150);
Beep(500,100);Sleep( 100);
Beep(570,100);Sleep( 420);
Beep(585,100);Sleep( 450);
Beep(550,100);Sleep( 420);
Beep(500,100);Sleep( 360);
Beep(380,100);Sleep( 300);
Beep(500,100);Sleep( 300);
Beep(500,100);Sleep( 150);
Beep(500,100);Sleep( 300);
Beep(500,60);Sleep( 150);
Beep(500,80);Sleep( 300);
Beep(500,60);Sleep( 350);
Beep(500,80);Sleep( 150);
Beep(580,80);Sleep( 350);
Beep(660,80);Sleep( 150);
Beep(500,80);Sleep( 300);
Beep(430,80);Sleep( 150);
Beep(380,80);Sleep( 600);
Beep(500,60);Sleep( 150);
Beep(500,80);Sleep( 300);
Beep(500,60);Sleep( 350);
Beep(500,80);Sleep( 150);
Beep(580,80);Sleep( 150);
Beep(660,80);Sleep( 550);
Beep(870,80);Sleep( 325);
Beep(760,80);Sleep( 600);
Beep(500,60);Sleep( 150);
Beep(500,80);Sleep( 300);
Beep(500,60);Sleep( 350);
Beep(500,80);Sleep( 150);
Beep(580,80);Sleep( 350);
Beep(660,80);Sleep( 150);
Beep(500,80);Sleep( 300);
Beep(430,80);Sleep( 150);
Beep(380,80);Sleep( 600);
Beep(660,100);Sleep( 150);
Beep(660,100);Sleep( 300);
Beep(660,100);Sleep( 300);
Beep(510,100);Sleep( 100);
Beep(660,100);Sleep( 300);
Beep(770,100);Sleep( 550);
Beep(380,100);Sleep( 575);
}
void redefine(void){
system("color f0"); 
system("MODE con cols=54 lines=29"); 
system("title Super Mário - by: Tainá Cristina - SGTChristina");
}
