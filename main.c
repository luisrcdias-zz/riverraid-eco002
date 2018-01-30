#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
//<!--Defines sections-->//
#define VAZIO ' '
#define EX '#'
#define PONTEup '-'
#define PONTEdwn '_'
#define FUELup 280
#define FUELdwn 281
#define TIRO '|'
#define FUEL 'F'
#define JOGADOR 197
#define OBSTACULO 'H'
#define NAV 'N'
#define NAVIO 'N'
#define PAREDE 'Ã'
#define VAZIO ' '
#define GRAMA 178
#define ARV 5
//</!--Defines sections-->//
void inicio(){
     int dig;
//     //     system("color 04"); 04"); 04");
     while(dig!=13){
       printf("\n");
       printf("\n");
       printf(" _____  _                  _____       _     _ \n");
       printf("|  __ \\(_)                |  __ \\     (_)   | |\n");
       printf("| |__) |___   _____ _ __  | |__) |__ _ _  __| |\n");
       printf("|  _  /| \\ \\ / / _ \\ '__| |  _  // _` | |/ _` |\n");
       printf("| | \\ \\| |\\ V /  __/ |    | | \\ \\ (_| | | (_| |\n");
       printf("|_|  \\_\\_| \\_/ \\___|_|    |_|  \\_\\__,_|_|\\__,_|\n");
       printf("\n");
       printf("\n");
       printf("Bem vindo!\n");
       printf("\n");
       printf("Aperte enter para comecar o jogo.\n");
       printf("\n");
       printf("Caso necessário, aperte espaço para instrucoes sobre como jogar.\n");
       dig = getch();
      if(dig==32){
      system("cls");
      printf("\n");
      printf("\n");
      printf(" ___         _                           \n");
      printf("|_ _|_ _  __| |_ _ _ _  _ __ ___  ___ ___\n");
      printf(" | || ' \\(_-<  _| '_| || / _/ _ \\/ -_|_-<\n");
      printf("|___|_||_/__/\\__|_|  \\_,_\\__\\___/\\___/__/\n");
      printf("\n");
      printf("\n");
      printf("Utilize as setas do teclado \33 e \32 para movimentar o aviao.\n");
      printf("\n");
      printf("Desvie dos obstaculos(N e H) e abasteca(F) para nao cair.\n");
      printf("\n");
      printf("Aperte \30 para um boost de velocidade momentaneo.\n");
      printf("\n");
      printf("Boa sorte!\n");
      printf("\n");
      printf("\nPressione qualquer tecla para iniciar.");
      while (!kbhit()){}
      break;}
      if(dig!=13){
      system("cls");}}
system("cls");}
void inicializaMapa(char m[20][20]){
  int i,j;
  for (i=0;i<20;i++){
      for(j=0;j<20;j++){
          m[i][j]= VAZIO;               
         if(j==4){
            m[i][j]= PAREDE;    }
            if(j==16){
            m[i][j]= PAREDE; }}}}
void atualizaMapa(char m[20][20]){
int i,j,posCarro,posFuel,posNavio;
for (i=18;i>=0;i--){
    for(j=0;j<20;j++){
       m[i+1][j]=m[i][j]; }}          
    for(j=6;j<15;j++){
       m[0][j]=VAZIO;}
       m[0][5]=PAREDE;
       m[0][15]=PAREDE;
       m[0][16]=VAZIO;
       m[0][4]=VAZIO;                
       if ((rand()%100)<15) {
         posCarro = 6 + (rand()%9);
         m[0][posCarro] = OBSTACULO;}
       if ((rand()%100)<15) {
         posNavio = 6 + (rand()%9);
         m[0][posNavio] = NAVIO;  
         m[0][posNavio-1] = NAVIO;}
         posFuel = 6 + (rand()%9);
       if (((rand()%100)<5)&&(m[0][posFuel] != PONTEup)&&(m[0][posFuel] != PONTEdwn)&&(m[0][posFuel] != NAVIO)&&(m[0][posFuel] != OBSTACULO)){
         m[0][posFuel] = FUELup;
         m[1][posFuel] = FUEL;
         m[2][posFuel] = FUELdwn;         }      
       for (i=10;i<20;i++){
       for(j=17;j<20;j++){
       m[i][j]=VAZIO;         }}
       for (i=14;i<20;i++){
       for(j=0;j<4;j++){
       m[i][j]=VAZIO;       }}
       printf("-----------------------------------------");}
void level (char m[20][20], int km){
     int j, i;
     for(i=1;i>1; i++);
     if (km==250*i){
                 for (j=5; j<16; j++){
                     m[0][j]=VAZIO;
                     m[0][5]= PAREDE;
                     m[0][15]= PAREDE; 
                     m[1][j]=PONTEup;
                     m[2][j]=PONTEdwn;
                     m[3][j]=VAZIO;
                     m[3][5]= PAREDE;
                     m[3][15]= PAREDE; 
     }
     }
}
                
   
void desenhaMapa(char m[20][20], int colJogador){
  int i,j;
  for (i=0;i<20;i++){
     for(j=0;j<20;j++){
     if ((j==colJogador) && (i==19)){
     printf("%c ", JOGADOR);
     }else{
     printf("%c ", m[i][j]);
  }
  }
  printf("\n");
}
}   



void tiro(char m[20][20] , int colTiro ){
     int i,j;
     for(i=20 ; i>=0 ; i--){
     if(m[i][colTiro] == OBSTACULO){  
        m[i][colTiro] = EX;          
        break;
        }
     if(m[i][colTiro] == NAVIO){  
        m[i][colTiro] = EX;          
                m[i][colTiro+1] = EX;
                                m[i][colTiro-1] = EX;
        break;
        }
     if(m[i][colTiro] == FUEL){  
        m[i][colTiro] = EX;   
        m[i+1][colTiro] = EX;
        m[i-1][colTiro] = EX;       
        break;
        }
     if((m[i][colTiro] == PONTEup)||(m[i][colTiro] == PONTEdwn)){  
     for (j=5; j<16; j++){
       m[i][j] = VAZIO; 
       m[i-1][j] = VAZIO;
       }    
       m[i][5]= PAREDE;
       m[i][15]= PAREDE; 
       m[i-1][5]= PAREDE;
       m[i-1][15]= PAREDE;                 
       break;
       }
       }
}

int main (int argc, char*argv[]){
char dig,mapa[20][20],f[100];
int colJogador=10, score=0, i, j, fase=1, km=0, life=3, timing=1, v[300];
double fuel=100;
inicio();
//     //     system("color 04"); 04"); 09");
while (life>=1) {
inicializaMapa(mapa);
desenhaMapa(mapa, colJogador);
printf("-----------------------------------------");
printf("\n");
printf("         Score: 0\n");
printf("         Fuel:IIIIIIIIII"); 

printf("\nPressione qualquer tecla para inicar o jogo!");
while (!kbhit())
{
}

while((mapa[19][colJogador] != OBSTACULO)&&(mapa[19][colJogador]!= PAREDE) && (fuel>=1) && (mapa[19][colJogador]!= NAVIO) && (mapa[19][colJogador]!= PONTEdwn)&&(mapa[19][colJogador]!= PONTEup)){
      system("cls");  
      if (timing>=151) {
      fase = 2; }
      if (timing>=301) {
      fase = 3; }
      if (timing>=451) {
      fase = 4; }
      if(fuel>=91){
      for(i=0; i<10; i++){
      f[i]='I';
      }
      }
      if((fuel>=81)&&(fuel<91)){
      for(i=0; i<9; i++){
      f[i]='I';
      }
      for(i=9; i<10; i++){
      f[i]=VAZIO;
      }
      }
      if((fuel>=71)&&(fuel<81)){
      for(i=0; i<8; i++){
      f[i]='I';
      }
      for(i=8; i<10; i++){
      f[i]=VAZIO;
      }
      }
      if((fuel>=61)&&(fuel<71)){
      for(i=0; i<7; i++){
      f[i]='I';
      }
      for(i=7; i<10; i++){
      f[i]=VAZIO;
      }
      }
      if((fuel>=51)&&(fuel<61)){
      for(i=0; i<6; i++){
      f[i]='I';
      }
      for(i=6; i<10; i++){
      f[i]=VAZIO;
      }
      }
      if((fuel>=41)&&(fuel<51)){
      for(i=0; i<5; i++){
      f[i]='I';
      }
      for(i=5; i<10; i++){
      f[i]=VAZIO;
      }
      }
      if((fuel>=31)&&(fuel<41)){
      for(i=0; i<4; i++){
      f[i]='I';
      }
      for(i=4; i<10; i++){
      f[i]=VAZIO;
      }
      }
      if((fuel>=21)&&(fuel<31)){
      for(i=0; i<3; i++){
      f[i]='I';
      }
      for(i=3; i<10; i++){
      f[i]=VAZIO;
      }
      }
      if((fuel>=11)&&(fuel<21)){
      for(i=0; i<2; i++){
      f[i]='I';
      }
      for(i=2; i<10; i++){
      f[i]=VAZIO;
      }
      }
      if((fuel>=1)&&(fuel<11)){
      for(i=0; i<1; i++){
      f[i]='I';
      }
      for(i=1; i<10; i++){
      f[i]=VAZIO;
      }
      }
      if((fuel>=0)&&(fuel<2)){
      for(i=0; i<10; i++){
      f[i]=VAZIO;
      }
      }
       for (i=0; i<life; i++){
      v[i]=JOGADOR;
      }
    if (kbhit()){
      dig = getch();
    if((dig==75) && (colJogador>5)){
      colJogador--;}
    if((dig==77) && (colJogador<15)){
      colJogador++;
      }
    if(dig==32){
    tiro(mapa,colJogador);}  
          }       
      if((mapa[19][colJogador]==FUEL)){
      fuel=fuel+100;
      score=score+30;
      }
      if(fuel>=101){
      fuel=100;}   
      level(mapa, km);
      life=life+(score/1000);
      desenhaMapa(mapa, colJogador); 
      atualizaMapa(mapa); 

      if(dig==72){   
      sleep(40/fase);
      }else{
      sleep(60/fase);}
      


      score++;
      km++;
      timing++;
      fuel=fuel-0.5;
      printf("\n");
      printf("         Score: %d\n",score);
      printf("         Fuel:");   
      for(i=0;i<10;i++){
      printf("%c",f[i]);}
      printf("\n");
      printf("        Lifes:");
      for(i=0;i<life;i++){
      printf("%c",v[i]);}}
sleep(500);
system("cls");
//     //     system("color 04"); 04"); 4");
while(dig!=32){
printf("\n");
printf("\n");
printf("  ________    _____      _____  ___________\n");
printf(" /  _____/   /  _  \\    /     \\ \\_   _____/\n");
printf("/   \\  ___  /  /_\\  \\  /  \\ /  \\ |    __)_ \n");
printf("\\    \\_\\  \\/    |    \\/    Y    \\|        \\\n");
printf(" \\______  /\\____|__  /\\____|__  /_______  /\n");
printf("        \\/         \\/         \\/        \\/ \n");
printf("____________   _________________________ \n");
printf("\\_____  \\   \\ /   /\\_   _____/\\______   \\\n");
printf(" /   |   \\   Y   /  |    __)_  |       _/\n");
printf("/    |    \\     /   |        \\ |    |   \\\n");
printf("\\_______  /\\___/   /_______  / |____|_  /\n");
printf("        \\/                 \\/         \\/ \n");
printf("\n");
printf("\n");
if (fuel<=1){
  printf("Voce ficou sem combustivel!\n");
  }else{
  printf("Voce bateu!\n");  }
printf("\n");
printf("Seu Score foi: %d\n",score);
printf("\n");
printf("Voce andou %dKM\n", km);
printf("\n");
if (life<=1){
   printf("\nAtire para sair.");
   }else{
   printf("\nAtire para jogar novamente.");   }   
dig = getch();
if(dig!=32){
  system("cls");}}
//     //     system("color 04"); 04"); 09");
life--;
km=0;
colJogador=10;
fuel=100;
system("cls");
if (fase==1){
timing=0;
}else{
timing=150*fase;}
}
return 0;
} 
