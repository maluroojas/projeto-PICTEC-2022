#include <LiquidCrystal_I2C.h>
#define botao_a 8
#define botao_b 9
#define botao_c 10
#define led_verde 11
#define led_vermelho 12
#define buzzer_pin 13
int acertos = 0;
int resposta1;

18

int resposta2;
int resposta3;
int resposta4;
int resposta5;
#include "U8glib.h"
U8GLIB_ST7920_128X64_1X u8g(6, 5, 4 ,7); //Enable, RW, RS, RESET
int display = 1;

//variável do tipo de função
int tipo_de_funcao;
int tempo_pergunta;
int tempo_buzzer;
LiquidCrystal_I2C lcd(0x27,16,2);
int cont_mensg_reset=0;
void (*funcReset)() = 0;
void setup()
{
Serial.begin(9600);
pinMode (botao_a, INPUT);
pinMode (botao_b, INPUT);
pinMode (botao_c, INPUT);
pinMode (led_verde, OUTPUT);
pinMode (led_vermelho, OUTPUT);
pinMode (buzzer_pin, OUTPUT);
resposta1=-1;
resposta2=-1;
resposta3=-1;
resposta4=-1;
resposta5=-1;
tempo_pergunta=10000;
tempo_buzzer=200;
digitalWrite(led_verde,LOW);
digitalWrite(led_vermelho,LOW);
lcd.init();
lcd.backlight();
lcd.clear();
lcd.setCursor(2,0);
lcd.print("BEM-VINDO(A)");
lcd.setCursor(4,1);
lcd.print("EpiGame");
// assign default color value
if ( u8g.getMode() == U8G_MODE_R3G3B2 )
u8g.setColorIndex(255); // white

19

else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )
u8g.setColorIndex(1); // max intensity
else if ( u8g.getMode() == U8G_MODE_BW )
u8g.setColorIndex(1); // pixel on

u8g.firstPage();
do
{
draw_IF();
}
while( u8g.nextPage() );
}
void loop()
{
delay(5000);
while(resposta1<0)
{
pergunta1();
}
if(resposta1==3){
resp_certa();
acertos=acertos+1;
}else{
resp_errada();
}
delay(1000);
while(resposta2<0)
{
pergunta2();
}
if(resposta2==2){
resp_certa();
acertos=acertos+1;
}else{
resp_errada();
}
delay(1000);
while(resposta3<0)
{
pergunta3();
}
if(resposta3==1){
resp_certa();
acertos=acertos+1;
}else{

2
0

resp_errada()
;

}
delay
(1000
)
;
while
(resposta4<
0
)

{
pergunta4()
;

}
if
(resposta4==
1){
resp_certa()
;
acertos=acertos+
1
;

}else
{
resp_errada()
;

}
delay
(1000
)
;
while
(resposta5<
0
)

{
pergunta5()
;

}
if
(resposta5==
2){
resp_certa()
;
acertos=acertos+
1
;

}else
{
resp_errada()
;

}
delay
(1000
)
;

if
(acertos>=
4){
msg_final_boa()
;

}else
{
msg_final_ruim()
;

}
delay
(10000
)
;
funcReset()
;

}

void pergunta1() {
lcd
.clear()
;

lcd
.setCursor
(
4
,
0
)
;

lcd
.print
("EpiGame"
)
;

lcd
.setCursor
(
2
,
1
)
;

lcd
.print
("Pergunta 1:"
)
;

u8g
.firstPage()
;

do{
u8g_prepare()
;

u8g
.drawStr90
(125
,
0
, "Pergunta 1:"
)
;

u8g
.drawStr90
(115
,
0
, "Qual
o nome"
)
;

21

u8g.drawStr90(105, 0, "dado quando");
u8g.drawStr90(95, 0, "uma epide-");
u8g.drawStr90(85, 0, "mia atinge");
u8g.drawStr90(75, 0, "varios");
u8g.drawStr90(65, 0, "paises de");
u8g.drawStr90(55, 0, "diferentes");
u8g.drawStr90(45, 0, "continen-");
u8g.drawStr90(35, 0, "tes?");
}
while( u8g.nextPage() );
delay(tempo_pergunta);

u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Opcao A:");
u8g.drawStr90(115, 0, "Surto");
u8g.drawStr90(100, 0, "Opcao B:");
u8g.drawStr90(90, 0, "Endemia");
u8g.drawStr90(75, 0, "Opcao C:");
u8g.drawStr90(65, 0, "Pandemia");
}
while( u8g.nextPage() );
resposta1 = aguardarResposta();
}
//_________________________________________________________________________
void pergunta2()
{
lcd.clear();
lcd.setCursor(4,0);
lcd.print("EpiGame");
lcd.setCursor(2,1);
lcd.print("Pergunta 2:");
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Pergunta 2:");
u8g.drawStr90(115, 0, "Quais as");
u8g.drawStr90(105, 0, "epidemias");
u8g.drawStr90(95, 0, "com maior");
u8g.drawStr90(85, 0, "numero de");
u8g.drawStr90(75, 0, "casos na");
u8g.drawStr90(65, 0, "na cidade");

22

u8g.drawStr90(55, 0, "de Tres");
u8g.drawStr90(45, 0, "Lagoas-MS?");
}
while( u8g.nextPage() );
delay(tempo_pergunta);
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Opcao A:");
u8g.drawStr90(115, 0, "Poliomieli-");
u8g.drawStr90(105, 0, "te e ");
u8g.drawStr90(95, 0, "Variola");
u8g.drawStr90(80, 0, "Opcao B:");
u8g.drawStr90(70, 0, "Dengue e ");
u8g.drawStr90(60, 0, "Sarampo");
u8g.drawStr90(45, 0, "Opcao C:");
u8g.drawStr90(35, 0, "Febre"); //
u8g.drawStr90(25, 0, "amarela e");
u8g.drawStr90(15, 0, "Tuberculose");
}
while( u8g.nextPage() );
resposta2 = aguardarResposta();
}
//____________________________________________________________________________
_
void pergunta3()
{
lcd.clear();
lcd.setCursor(4,0);
lcd.print("EpiGame");
lcd.setCursor(2,1);
lcd.print("Pergunta 3:");
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Pergunta 3:");
u8g.drawStr90(115, 0, "Qual o");
u8g.drawStr90(105, 0, "melhor");
u8g.drawStr90(95, 0, "metodo de");
u8g.drawStr90(85, 0, "prevencao");
u8g.drawStr90(75, 0, "contra a");
u8g.drawStr90(65, 0, "dengue?");
}
while( u8g.nextPage() );

23

delay(tempo_pergunta);
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Opcao A:");
u8g.drawStr90(115, 0, "Eliminando");
u8g.drawStr90(105, 0, "agua");
u8g.drawStr90(95, 0, "parada");
u8g.drawStr90(80, 0, "Opcao B:");
u8g.drawStr90(70, 0, "Vacinacao");
u8g.drawStr90(55, 0, "Opcao C:");
u8g.drawStr90(45, 0, "Lavando"); //
u8g.drawStr90(35, 0, "as maos");
}
while( u8g.nextPage() );
delay(tempo_pergunta);
resposta3 = aguardarResposta();
}
//____________________________________________________________________________
_
void pergunta4()
{
lcd.clear();
lcd.setCursor(4,0);
lcd.print("EpiGame");
lcd.setCursor(2,1);
lcd.print("Pergunta 4:");
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Pergunta 4:");
u8g.drawStr90(115, 0, "Segundo");
u8g.drawStr90(105, 0, "levantamen-");
u8g.drawStr90(95, 0, "to da SMS");
u8g.drawStr90(85, 0, "de TL, em ");
u8g.drawStr90(75, 0, "2023,");
u8g.drawStr90(65, 0, "80,9% dos");
u8g.drawStr90(55, 0, "focos de:");
u8g.drawStr90(45, 0, "mosquitos");
u8g.drawStr90(35, 0, "Aedes");
u8g.drawStr90(25, 0, "aegypti");
u8g.drawStr90(15, 0, "estao em:");
}

24

while( u8g.nextPage() );
delay(tempo_pergunta);

u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Opcao A:");
u8g.drawStr90(115, 0, "Casas");
u8g.drawStr90(100, 0, "Opcao B:");
u8g.drawStr90(90, 0, "Terrenos");
u8g.drawStr90(80, 0, "baldios");
u8g.drawStr90(65, 0, "Opcao C:");
u8g.drawStr90(55, 0, "Comercios");
}
while( u8g.nextPage() );
resposta4 = aguardarResposta();
}
//____________________________________________________________________________
_
void pergunta5()
{
lcd.clear();
lcd.setCursor(4,0);
lcd.print("EpiGame");
lcd.setCursor(2,1);
lcd.print("Pergunta 5:");
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Pergunta 5:");
u8g.drawStr90(115, 0, "A dengue");
u8g.drawStr90(105, 0, "pode ser");
u8g.drawStr90(95, 0, "transmitida");
u8g.drawStr90(85, 0, "de pessoa");
u8g.drawStr90(75, 0, "para ");
u8g.drawStr90(65, 0, "pessoa?");
}
while( u8g.nextPage() );
delay(tempo_pergunta);

u8g.firstPage();
do
{

25

u8g_prepare();
u8g.drawStr90(125, 0, "Opcao A:");
u8g.drawStr90(115, 0, "Sim, pelo");
u8g.drawStr90(105, 0, "sangue.");
u8g.drawStr90(90, 0, "Opcao B:");
u8g.drawStr90(80, 0, "Nao, apenas");
u8g.drawStr90(70, 0, "pelo");
u8g.drawStr90(60, 0, "mosquito");
u8g.drawStr90(50, 0, "transmissor");
u8g.drawStr90(35, 0, "Opcao C:");
u8g.drawStr90(25, 0, "Sim, pela");
u8g.drawStr90(15, 0, "saliva.");
}
while( u8g.nextPage() );
resposta5 = aguardarResposta();
}
//_________________________________________________________________________

void u8g_prepare()
{
u8g.setFont(u8g_font_6x10);
u8g.setFontRefHeightExtendedText();
u8g.setDefaultForegroundColor();
u8g.setFontPosTop();
}

void draw_IF() //Rotina Desenho
{
u8g_prepare();
switch(display) //Carrega a tela correspondente
{
case 1:
u8g_Tela_IF();
}
}
void u8g_Tela_IF()
{
u8g.drawStr90(45, 8, "IFMS");
u8g.drawStr90(35, 8, "Campus");
u8g.drawStr90(25, 8, "Tres");
u8g.drawStr90(15, 8, "Lagoas");
u8g.drawPixel(23, 20);
u8g.drawPixel(24, 21);
u8g.drawPixel(25, 22);
u8g.drawPixel(24, 23);
u8g.drawPixel(23, 24);

2
6

u8g
.drawDisc
(107
, 15
,
7
)
;

for
(int x=100
; x<115
; x=x+
1){

for
(int y=25
; y<40
; y=y+
1){

u8g
.drawPixel
(x,
y
)
;

}
}
for
(int x=100
; x<115
; x=x+
1){

for
(int y=42
; y<57
; y=y+
1){

u8g
.drawPixel
(x,
y
)
;

}
}
for
(int x=83
; x<98
; x=x+
1){

for
(int y=
8
; y<23
; y=y+
1){

u8g
.drawPixel
(x,
y
)
;

}
}
for
(int x=83
; x<98
; x=x+
1){

for
(int y=25
; y<40
; y=y+
1){

u8g
.drawPixel
(x,
y
)
;

}
}
for
(int x=66
; x<81
; x=x+
1){

for
(int y=
8
; y<23
; y=y+
1){

u8g
.drawPixel
(x,
y
)
;

}
}
for
(int x=66
; x<81
; x=x+
1){

for
(int y=25
; y<40
; y=y+
1){

u8g
.drawPixel
(x,
y
)
;

}
}
for
(int x=66
; x<81
; x=x+
1){

for
(int y=42
; y<57
; y=y+
1){

u8g
.drawPixel
(x,
y
)
;

}
}
for
(int x=49
; x<64
; x=x+
1){

for
(int y=
8
; y<23
; y=y+
1){

u8g
.drawPixel
(x,
y
)
;

}
}
for
(int x=49
; x<64
; x=x+
1){

27

for(int y=25; y<40; y=y+1){
u8g.drawPixel(x, y);
}
}
}

int aguardarResposta() {
// Esperar o usuário pressionar um dos botões
while (true) {
if (digitalRead(botao_a) == HIGH) {
delay(50); // Debounce
if (digitalRead(botao_a) == HIGH) {
return 1;
}
}
if (digitalRead(botao_b) == HIGH) {
delay(50); // Debounce
if (digitalRead(botao_b) == HIGH) {
return 2;
}
}
if (digitalRead(botao_c) == HIGH) {
delay(50); // Debounce
if (digitalRead(botao_c) == HIGH) {
return 3;
}
}
}
}

void resp_certa()
{
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Parabens!");
u8g.drawStr90(115, 0, "Resposta");
u8g.drawStr90(105, 0, "certa.");
}
while( u8g.nextPage() );
digitalWrite(led_verde,HIGH);
tocarBuzzer(4000, tempo_buzzer);
delay(3000);
digitalWrite(led_verde,LOW);
}
void resp_errada()

28

{
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Que pena!");
u8g.drawStr90(115, 0, "Resposta");
u8g.drawStr90(105, 0, "errada.");
}
while( u8g.nextPage() );
digitalWrite(led_vermelho,HIGH);
tocarBuzzer(1000, tempo_buzzer);
delay(3000);
digitalWrite(led_vermelho,LOW);
}

void msg_final_boa()
{
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Parabens!");
u8g.drawStr90(115, 0, "Voce");
u8g.drawStr90(105, 0, "realmente");
u8g.drawStr90(95, 0, "conhece o");
u8g.drawStr90(85, 0, "assunto.");
}
while( u8g.nextPage() );
digitalWrite(led_verde,HIGH);
}

void msg_final_ruim()
{
u8g.firstPage();
do
{
u8g_prepare();
u8g.drawStr90(125, 0, "Nao desista!");
u8g.drawStr90(115, 0, "Continue");
u8g.drawStr90(105, 0, "estudando");
u8g.drawStr90(95, 0, "e jogue");
u8g.drawStr90(85, 0, "novamente!");
}
while( u8g.nextPage() );
digitalWrite(led_vermelho,HIGH);
}
void tocarBuzzer(unsigned int frequencia, unsigned long duracao) {
for(int cont_buzzer=1; cont_buzzer<=6; cont_buzzer++){
tone(buzzer_pin, frequencia);

29

delay(duracao);
noTone(buzzer_pin);
delay(duracao);
}
}