#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
int shipX=30;
int shipY=10;
int enemy1X=173;
int enemy1Y=10;
int enemy2X=3;
int enemy2Y=2;
int enemy4X=20;
int enemy4Y=10;
int enemy3X=3;
int enemy3Y=30;

int bulletX[100];
int bulletY[100];
int bullet1X[100];
int bullet1Y[100];
int bullet2X[100];
int bullet2Y[100];
int bullet3X[100];
int bullet3Y[100];
int bullet4X[100];
int bullet4Y[100];
bool isBulletActive[100];
bool isBulletActive1[100];
bool isBulletActive2[100];
bool isBulletActive3[100];
bool isBulletActive4[100];

int bulletCount=0;
int bulletCount1=0;
int bulletCount2=0;
int bulletCount3=0;
int bulletCount4=0;
int health=9;
int score=0;
int lifeCount=3;
string enemyDirection1="Up";
string enemyDirection2="Right";
string enemyDirection3="Right";

void printMainScreen();
void printHeader();
string printMenu();
void printChoice2();
void printChoice3();
void printMaze1();
void printMaze2();
void printSpaceship();
void printEnemy1();
void printEnemy2();
void printEnemy3();
void printEnemy4();
void moveSpaceshipUp();
void moveSpaceshipDown();
void moveSpaceshipLeft();
void moveSpaceshipRight();
void eraseEnemy1();
void eraseEnemy2();
void eraseEnemy3();
void eraseEnemy4();
void moveEnemy1();
void moveEnemy2();
void moveEnemy3();
void moveEnemy4();
void moveBullet();
void moveBullet1();
void moveBullet2();
void moveBullet3();
void moveBullet4();

void printBullet(int x, int y);
void printBullet1(int x, int y);
void printBullet2(int x, int y);
void printBullet3(int x, int y);
void printBullet4(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int x);
void makeBulletInactive1(int x);
void makeBulletInactive2(int x);
void makeBulletInactive3(int x);
void makeBulletInactive4(int x);

void bulletCollisionWithEnemy();
void bulletCollisionWithShip1();
void bulletCollisionWithShip2();
void bulletCollisionWithShip4();
void addScore();
void printScore();
void generateBullet();
void generateBulletEnemy1();
void generateBulletEnemy2();
void generateBulletEnemy4();

void printHealth();
void printLife();

void eraseShip();
char getCharAtxy( short int x, short int y);
void gotoxy(int x, int y);


main(){
  string choice;
  bool end=true;
  int timer=0,timer2=0,timer3=0;;
  while(end){
    system("cls");
    printMainScreen();
    choice=printMenu();
    if(choice=="2"){
      printChoice2();

    }
    else if(choice=="3"){
      printChoice3();

    }
    else if(choice=="4"){
      end=false;

    }
    else if(choice=="1"){
      system("cls");
      printMaze1();
      printSpaceship();
      printEnemy1();
      printEnemy2();
      printEnemy4();
      while(true){
        printScore();
        if(score==200){
          //level 2
        }
        printHealth();
        if(health==0){
          lifeCount--;
          health=9;
        }
        printLife();
        if(lifeCount==0){
          system("cls");
          gotoxy(102,26);
          cout << "YOU LOSE";
          getch();
          lifeCount=3;
          end=false;
          break;
        }
        if(GetAsyncKeyState(VK_LEFT)){
          moveSpaceshipLeft();
        }
        if(GetAsyncKeyState(VK_RIGHT)){
          moveSpaceshipRight();
        }
        if(GetAsyncKeyState(VK_UP)){
          moveSpaceshipUp();
        }
        if(GetAsyncKeyState(VK_DOWN)){
          moveSpaceshipDown();
        }
        if(GetAsyncKeyState(VK_SPACE)){
          generateBullet();
        }
        if(timer3==20){
          generateBulletEnemy1();
          generateBulletEnemy4();
          generateBulletEnemy2();
          timer3=0;
        }
        if(timer2==7){
          moveEnemy4();
          timer2=0;
        }
        if(timer==3){
          moveEnemy1();
          moveEnemy2();
          
          timer=0;
        }
        moveBullet1();
        moveBullet2();
        moveBullet4();
        moveBullet();
        bulletCollisionWithEnemy();
        bulletCollisionWithShip1();
        bulletCollisionWithShip2();
        bulletCollisionWithShip4();
        timer++;
        timer2++;
        timer3++;
        Sleep(80);
      }
    }
   else{ 
      cout << "ERROR";
      getch();
      
    }
  }

}
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy( short int x, short int y){
  CHAR_INFO ci;
  COORD xy ={0,0};
  SMALL_RECT rect= {x,y,x,y};
  COORD coordBufSize;
  coordBufSize.X=1;
  coordBufSize.Y=1;
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void eraseEnemy1(){
  gotoxy(enemy1X, enemy1Y);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy1X, enemy1Y+1);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy1X, enemy1Y+2);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy1X, enemy1Y+3);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy1X, enemy1Y+4);
  for(int i=0; i<9; i++){
    cout << " ";
  }
}
void eraseEnemy2(){
  gotoxy(enemy2X, enemy2Y);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy2X, enemy2Y+1);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy2X, enemy2Y+2);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy2X, enemy2Y+3);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy2X, enemy2Y+4);
  for(int i=0; i<9; i++){
    cout << " ";
  }
}
void eraseEnemy3(){
  gotoxy(enemy3X, enemy3Y);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy3X, enemy3Y+1);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy3X, enemy3Y+2);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy3X, enemy3Y+3);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy3X, enemy3Y+4);
  for(int i=0; i<9; i++){
    cout << " ";
  }
}
void eraseEnemy4(){
  gotoxy(enemy4X, enemy4Y);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy4X, enemy4Y+1);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy4X, enemy4Y+2);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy4X, enemy4Y+3);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(enemy4X, enemy4Y+4);
  for(int i=0; i<9; i++){
    cout << " ";
  }
}
void eraseShip(){
  gotoxy(shipX, shipY);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(shipX, shipY+1);
  for(int i=0; i<9; i++){
    cout << " ";
  }
  gotoxy(shipX, shipY+2);
  for(int i=0; i<9; i++){
    cout << " ";
  }
}
void moveSpaceshipRight(){
  bool bomb=false;
  bool money=false;
  bool energy=false;
  bool bullet=false;
  bool empty=false;
  for(int i=0; i<3; i++){
    char next=getCharAtxy(shipX+9, shipY+i);
    if(next=='x'){
      bomb=true;
    }
    if(next=='['){
      energy=true;
    }
    if(next=='$'){
      money=true;
    }
    if(next=='-'|| next=='<'|| next=='*'){
      bullet=true;
    }
    if(next==' '){
      empty=true;
    }
  }
  if(bomb==true && empty==true){
    eraseShip();
    shipX=shipX+1;
    printSpaceship();
    lifeCount--;
  }
  else if(money==true && empty==true){
    eraseShip();
    shipX=shipX+1;
    printSpaceship();
    score=score+10;
  }
  else if(energy==true && empty==true){
    eraseShip();
    shipX=shipX+1;
    printSpaceship();
    health++;
  }
  else if(bullet==true && empty==true){
    eraseShip();
    shipX=shipX+1;
    printSpaceship();
  }
  else if(empty==true){
    eraseShip();
    shipX=shipX+1;
    printSpaceship();
  }
  
}
void moveSpaceshipLeft(){
  bool bomb=false;
  bool money=false;
  bool energy=false;
  bool bullet=false;
  bool empty=false;
  for(int i=0; i<3; i++){
    char next=getCharAtxy(shipX-1, shipY+i);
    if(next=='x'){
      bomb=true;
    }
    if(next=='['){
      energy=true;
    }
    if(next=='$'){
      money=true;
    }
    if(next=='-'|| next=='<' || next=='*'){
      bullet=true;
    }
    if(next==' '){
      empty=true;
    }
  }
  if(bomb==true && empty==true){
    eraseShip();
    shipX=shipX-1;
    printSpaceship();
    lifeCount--;
  }
  else if(money==true && empty==true){
    eraseShip();
    shipX=shipX-1;
    printSpaceship();
    score=score+10;
  }
  else if(energy==true && empty==true){
    eraseShip();
    shipX=shipX-1;
    printSpaceship();
    health++;
  }
  else if(bullet==true && empty==true){
    eraseShip();
    shipX=shipX-1;
    printSpaceship();
  }
  else if(empty==true){
    eraseShip();
    shipX=shipX-1;
    printSpaceship();
  }
  
}
void moveSpaceshipUp(){
  bool bomb=false;
  bool money=false;
  bool energy=false;
  bool bullet=false;
  bool empty=false;
  for(int i=0; i<9; i++){
    char next=getCharAtxy(shipX+i, shipY-1);
    if(next=='x'){
      bomb=true;
    }
    if(next=='['){
      energy=true;
    }
    if(next=='$'){
      money=true;
    }
    if(next=='-'|| next=='<' || next=='*'){
      bullet=true;
    }
    if(next==' '){
      empty=true;
    }
  }
  if(bomb==true && empty==true){
    eraseShip();
    shipY=shipY-1;
    printSpaceship();
    lifeCount--;
  }
  else if(money==true && empty==true){
    eraseShip();
    shipY=shipY-1;
    printSpaceship();
    score=score+10;
  }
  else if(energy==true && empty==true){
    eraseShip();
    shipY=shipY-1;
    printSpaceship();
    health++;
  }
  else if(bullet==true && empty==true){
    eraseShip();
    shipY=shipY-1;
    printSpaceship();
  
  }
  else if(empty==true){
    eraseShip();
    shipY=shipY-1;
    printSpaceship();
  }
  
}
void moveSpaceshipDown(){
  bool bomb=false;
  bool money=false;
  bool energy=false;
  bool bullet=false;
  bool empty=false;
  for(int i=0; i<9; i++){
    char next=getCharAtxy(shipX+i, shipY+3);
    if(next=='x'){
      bomb=true;
    }
    if(next=='['  ){
      energy=true;
    }
    if(next=='$'){
      money=true;
    }
    if(next=='-'|| next=='<' || next=='*'){
      bullet=true;
    }
    if(next==' '){
      empty=true;
    }
  }
  if(bomb==true && empty==true){
    eraseShip();
    shipY=shipY+1;
    printSpaceship();
    lifeCount--;
  }
  else if(money==true && empty==true){
    eraseShip();
    shipY=shipY+1;
    printSpaceship();
    score=score+10;
  }
  else if(energy==true && empty==true){
    eraseShip();
    shipY=shipY+1;
    printSpaceship();
    health++;
  }
  else if(bullet==true && empty==true){
    eraseShip();
    shipY=shipY+1;
    printSpaceship();
    
  }
  else if(empty==true){
    eraseShip();
    shipY=shipY+1;
    printSpaceship();
  }
  
}
void moveEnemy1(){
  if(enemyDirection1=="Up"){
    char next=getCharAtxy(enemy1X, enemy1Y-1);
    if(next==' '){
      eraseEnemy1();
      enemy1Y--;
      printEnemy1();
    }
    if(next =='#'){
      enemyDirection1="Down";
    }
  }
  if(enemyDirection1=="Down"){
    char next=getCharAtxy(enemy1X, enemy1Y+5);
    if(next==' '){
      eraseEnemy1();
      enemy1Y++;
      printEnemy1();
    }
      if(next =='#'){
      enemyDirection1="Up";
    }
  }
    
}
void moveEnemy2(){
 if(enemyDirection2=="Right"){
    char next=getCharAtxy(enemy2X+9, enemy2Y);
    if(next==' '){
      eraseEnemy2();
      enemy2X++;
      printEnemy2();
    }
    if(next =='#'){
      enemyDirection2="Left";
    }
  }
  if(enemyDirection2=="Left"){
    char next=getCharAtxy(enemy2X-1, enemy2Y);
    if(next==' '){
      eraseEnemy2();
      enemy2X--;
      printEnemy2();
    }
      if(next =='#'){
      enemyDirection2="Right";
    }
  }
}
void moveEnemy3(){
 if(enemyDirection3=="Right"){
    char next=getCharAtxy(enemy3X+9, enemy3Y);
    if(next==' '){
      eraseEnemy3();
      enemy3X++;
      printEnemy3();
    }
    if(next =='#'){
      enemyDirection3="Left";
    }
  }
  if(enemyDirection3=="Left"){
    char next=getCharAtxy(enemy3X-1, enemy3Y);
    if(next==' '){
      eraseEnemy3();
      enemy3X--;
      printEnemy3();
    }
      if(next =='#'){
      enemyDirection3="Right";
    }
  }
}
void moveEnemy4(){
  gotoxy(enemy4X, enemy4Y);
  eraseEnemy4();
  if(enemy4X+10<shipX){
    enemy4X++;
  }
  if(enemy4X+10>shipX){
    enemy4X--;
  }
  if(enemy4Y+1<shipY){
    enemy4Y++;
  }
  if(enemy4Y+1>shipY){
    enemy4Y--;
  } 
  gotoxy(enemy4X, enemy4Y);
  printEnemy4();
  
}
void generateBullet(){
  bulletX[bulletCount]=shipX+10;
  bulletY[bulletCount]=shipY+1;
  isBulletActive[bulletCount]=true;
  gotoxy(shipX+10, shipY+1);
  cout << ".";
  bulletCount++;
}
void generateBulletEnemy1(){
  bullet1X[bulletCount1]=enemy1X;
  bullet1Y[bulletCount1]=enemy1Y+3;
  isBulletActive1[bulletCount1]=true;
  gotoxy(enemy1X, enemy1Y+3);
  cout << "<";
  bulletCount1++;
}
void generateBulletEnemy2(){
  bullet2X[bulletCount2]=enemy2X+5;
  bullet2Y[bulletCount2]=enemy2Y+5;
  isBulletActive2[bulletCount2]=true;
  gotoxy(enemy2X+5, enemy2Y+5);
  cout << "*";
  bulletCount2++;
}
void generateBulletEnemy3(){
  bullet3X[bulletCount3]=enemy3X+5;
  bullet3Y[bulletCount3]=enemy3Y;
  isBulletActive3[bulletCount3]=true;
  gotoxy(enemy3X+5, enemy3Y);
  cout << "*";
  bulletCount3++;
}
void generateBulletEnemy4(){
  bullet4X[bulletCount4]=enemy4X+10;
  bullet4Y[bulletCount4]=enemy4Y+2;
  isBulletActive4[bulletCount4]=true;
  gotoxy(enemy4X+10, enemy4Y+2);
  cout << "-";
  bulletCount4++;
}
void moveBullet(){
  for(int i=0; i<bulletCount; i++){
    if(isBulletActive[i]==true){
      char next =getCharAtxy(bulletX[i]+1, bulletY[i]);
      if(next!=' '){
        eraseBullet(bulletX[i], bulletY[i]);
        makeBulletInactive(i);
      }
      else{
        eraseBullet(bulletX[i], bulletY[i]);
        bulletX[i]=bulletX[i]+1;
        printBullet(bulletX[i], bulletY[i]);
      }
    }
  }
}
void moveBullet1(){
  for(int i=0; i<bulletCount1; i++){
    if(isBulletActive1[i]==true){
      char next =getCharAtxy(bullet1X[i]-1, bullet1Y[i]);
      if(next!=' '){
        eraseBullet(bullet1X[i], bullet1Y[i]);
        makeBulletInactive1(i);
      }
      else{
        eraseBullet(bullet1X[i], bullet1Y[i]);
        bullet1X[i]=bullet1X[i]-1;
        printBullet1(bullet1X[i], bullet1Y[i]);
      }
    }
  }
}
void moveBullet2(){
  for(int i=0; i<bulletCount2; i++){
    if(isBulletActive2[i]==true){
      char next =getCharAtxy(bullet2X[i], bullet2Y[i]+1);
      if(next!=' '){
        eraseBullet(bullet2X[i], bullet2Y[i]);
        makeBulletInactive2(i);
      }
      else{
        eraseBullet(bullet2X[i], bullet2Y[i]);
        bullet2Y[i]=bullet2Y[i]+1;
        printBullet2(bullet2X[i], bullet2Y[i]);
      }
    }
  }
}
void moveBullet3(){
  for(int i=0; i<bulletCount3; i++){
    if(isBulletActive3[i]==true){
      char next =getCharAtxy(bullet3X[i], bullet3Y[i]-1);
      if(next!=' '){
        eraseBullet(bullet3X[i], bullet3Y[i]);
        makeBulletInactive3(i);
      }
      else{
        eraseBullet(bullet3X[i], bullet3Y[i]);
        bullet3Y[i]=bullet3Y[i]-1;
        printBullet2(bullet3X[i], bullet3Y[i]);
      }
    }
  }
}
void moveBullet4(){
  for(int i=0; i<bulletCount4; i++){
    if(isBulletActive4[i]==true){
      char next =getCharAtxy(bullet4X[i]+1, bullet4Y[i]);
      if(next!=' '){
        eraseBullet(bullet4X[i], bullet4Y[i]);
        makeBulletInactive4(i);
      }
      else{
        eraseBullet(bullet4X[i], bullet4Y[i]);
        bullet4X[i]=bullet4X[i]+1;
        printBullet4(bullet4X[i], bullet4Y[i]);
      }
    }
  }
}
void printBullet(int x, int y){
  gotoxy(x,y);
  cout << ".";
}
void printBullet1(int x, int y){
  gotoxy(x,y);
  cout << "<";
}
void printBullet2(int x, int y){
  gotoxy(x,y);
  cout << "*";
}
void printBullet4(int x, int y){
  gotoxy(x,y);
  cout << "-";
}
void eraseBullet(int x, int y){
  gotoxy(x,y);
  cout << " ";
}
void makeBulletInactive(int x){
  isBulletActive[x]=false;
}
void makeBulletInactive1(int x){
  isBulletActive1[x]=false;
}
void makeBulletInactive2(int x){
  isBulletActive2[x]=false;
}
void makeBulletInactive3(int x){
  isBulletActive3[x]=false;
}
void makeBulletInactive4(int x){
  isBulletActive4[x]=false;
}
void bulletCollisionWithEnemy(){
  for(int x=0; x<bulletCount; x++){
    if(isBulletActive[x]==true){
      if(bulletX[x]+1==enemy1X && (bulletY[x]==enemy1Y || bulletY[x]==enemy1Y+2 || bulletY[x]==enemy1Y+1 ||bulletY[x]==enemy1Y+3 || bulletY[x]==enemy1Y+4|| bulletY[x]==enemy1Y+5)){
        addScore();
      }
      if(bulletX[x]+1==enemy4X && (bulletY[x]==enemy4Y || bulletY[x]==enemy4Y+2 || bulletY[x]==enemy4Y+1 ||bulletY[x]==enemy4Y+3 || bulletY[x]==enemy4Y+4|| bulletY[x]==enemy4Y+5)){
        addScore();
      }
    }
  }
}
void bulletCollisionWithShip1(){
 for(int x=0; x<bulletCount1; x++){
    if(isBulletActive1[x]==true){
      if(bullet1X[x]-1==shipX+8 && (bullet1Y[x]==shipY || bullet1Y[x]==shipY+1 || bullet1Y[x]==shipY+2 || bullet1Y[x]==shipY+3|| bullet1Y[x]==shipY+4)){
        health= health-1;
      }
      
    }
  }

}
void bulletCollisionWithShip4(){
 for(int x=0; x<bulletCount4; x++){
    if(isBulletActive4[x]==true){
      if(bullet4X[x]+1==shipX && (bullet4Y[x]==shipY || bullet4Y[x]==shipY+1 || bullet4Y[x]==shipY+2)){
        health= health-1;
      }
      
    }
  }

}
void bulletCollisionWithShip2(){
 for(int x=0; x<bulletCount2; x++){
    if(isBulletActive2[x]==true){
      if(bullet2Y[x]+1==shipY && (bullet2X[x]==shipX || bullet2X[x]==shipX+1 || bullet2X[x]==shipX+2 || bullet2X[x]==shipX+3 ||bullet2X[x]==shipX+4 ||bullet2X[x]==shipX+5 ||bullet2X[x]==shipX+6 ||bullet2X[x]==shipX+7 ||bullet2X[x]==shipX+8 ||bullet2X[x]==shipX+9 )){
        health=health-1;
      }
      
    }
  }

}
void bulletCollisionWithShip3(){
 for(int x=0; x<bulletCount3; x++){
    if(isBulletActive3[x]==true){
      if(bullet3Y[x]-1==shipY && (bullet3X[x]==shipX || bullet3X[x]==shipX+1 || bullet3X[x]==shipX+2 || bullet3X[x]==shipX+3 ||bullet3X[x]==shipX+4 ||bullet3X[x]==shipX+5 ||bullet3X[x]==shipX+6 ||bullet3X[x]==shipX+7 ||bullet3X[x]==shipX+8 ||bullet3X[x]==shipX+9 )){
        health=health-1;
      }
      
    }
  }

}

void addScore(){
  score++;
}
void printScore(){
  gotoxy(195,5);
  cout << "Score: " << score;
}
void printHealth(){
  gotoxy(195,6);
  cout << "Health: "<<health;
}
void printLife(){
  gotoxy(195,7);
  cout << "Life Count: "<<lifeCount;
}
void printSpaceship(){
  gotoxy(shipX,shipY);
  cout << " /====\\ ";
  gotoxy(shipX,shipY+1);
  cout << "(((())))>";
  gotoxy(shipX,shipY+2);
  cout << " \\====/ ";
}
void printEnemy3(){
  gotoxy(enemy3X, enemy3Y);
  cout << "   /\\   "<<endl;
  gotoxy(enemy3X, enemy3Y-1);
  cout << "  (  )   "<<endl;
  gotoxy(enemy3X, enemy3Y-2);
  cout << "  (  )   "<<endl;
  gotoxy(enemy3X, enemy3Y-3);
  cout << " /|/\\|\\"<<endl;
  gotoxy(enemy3X, enemy3Y-4);
  cout << "/_||||_\\"<<endl;
}

void printEnemy2(){
  gotoxy(enemy2X, enemy2Y);
  cout << "\\-||||-/" <<endl;
  gotoxy(enemy2X, enemy2Y+1);
  cout << " \\|\\/|/" <<endl;
  gotoxy(enemy2X, enemy2Y+2);
  cout << "  (  )   " <<endl;
  gotoxy(enemy2X, enemy2Y+3);
  cout << "  (  )   " <<endl;
  gotoxy(enemy2X, enemy2Y+4);
  cout << "   \\/   " << endl;
    
}
void printEnemy1(){
  gotoxy(enemy1X,enemy1Y);
  cout << "  <====> ";
  gotoxy(enemy1X,enemy1Y+1);
  cout << "   / /   ";
  gotoxy(enemy1X,enemy1Y+2);
  cout << "<([][][])";
  gotoxy(enemy1X,enemy1Y+3);
  cout << "   \\ \\ ";
  gotoxy(enemy1X,enemy1Y+4);
  cout << "  <====> ";    
}
void printEnemy4(){
  gotoxy(enemy4X, enemy4Y);
  cout << " <====>  "<<endl;
  gotoxy(enemy4X, enemy4Y+1);
  cout << " \\ \\   "<<endl;
  gotoxy(enemy4X, enemy4Y+2);
  cout << "([][][])>"<<endl;
  gotoxy(enemy4X, enemy4Y+3);
  cout << "   / /   "<<endl;
  gotoxy(enemy4X, enemy4Y+4);
  cout << " <====>  "<<endl;
    
}
void printMainScreen(){
    
   
    cout << "        .                      +            .             +                                                                          .           .          +                              .                           "<< endl;
    cout << "                 .                                          .             +        .                   .                              +       .                                                           "<< endl;
    cout << "                                        +            .                                                            +                                                .                                          .     "<< endl;
    cout << "           +         +                                       .                             +                   .                                             +                                        +                      "<< endl;
    cout << "         .                          +                       +              +                                                     +            .                                                                   "<< endl;
    cout << "                                                     .                      .                              +            .                                                 .               .                  "<< endl;
    cout << "    +                                                      +            .                                       +                                                +             .                               +          +  "<< endl;
    cout << "           .              +            .                  +                                                         .         .                                                                              "<< endl;
    cout << "                                         +            .                                                       +                                                                                            "<< endl;
    cout << "                                                                     +            +                                      +                               .                     +       .                    "<< endl;
    cout << "         +   .       +          .                 +            .                                          +                          +           +                   +                            .          "<< endl;
    cout << "           .                                                      .                                  .                    .                                                                                  "<< endl;
    cout << "    .            .            .                                                            .                             .                                    +                                             "<< endl;
    cout << "            .                              +            .                +               .                                             +               .                              +                          +     "<< endl;
    cout << "                  +            .                                                    +                  +            +                                                                              .                   "<< endl;
    cout << "                 .                              +            .                   .                     .                        +             .                              +                            .   "<< endl;
    cout << "           .         +            .                              +                         .                                                                                                                ."<< endl;
    cout << "                                         +                                                                                 .          +                                                        .                   +"<<endl;
    cout << "           +           .       +                                      +             +               .          +        /$$         +       /$$             /$$                                                   ." << endl;
    cout << "      .           .                    +                        .                 .        +                           | $$                |__/            | $$                       +                                  +  "<< endl;
    cout << "  .                                                         +    /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$       | $$$$$$$   /$$$$$$ /$$  /$$$$$$$ /$$$$$$              !                    .                  " <<endl;
    cout << "  +           +                             +          .        /$$_____/ /$$__  $$ |____  $$ /$$_____/ /$$__  $$  +   | $$__  $$ /$$__  $$|$$ /$$_____/|_  $$_/       +      !                         .         "<<endl;
    cout << "                   .      .                         .           | $$$$$$ |  $$  \\$$  /$$$$$$$| $$      | $$$$$$$$      | $$  \\ $$| $$$$$$$$|$$|  $$$$$$  |  $$                ^                   +            "<< endl;
    cout << "        .                                .                +    \\____  $$|  $$  | $$ /$$__  $$| $$      | $$_____/      | $$  | $$| $$_____/|$$\\____  $$  |  $$ /$$           / \\           .                        .       "<< endl;
    cout << "                                 +                              /$$$$$$$/| $$$$$$$/| $$$$$$$|  $$$$$$$|  $$$$$$$    .  | $$  | $$|  $$$$$$$|$$ /$$$$$$$/  | $$$$/      .    /___\\                               +           "<<endl;
    cout << "              .                                          .     |_______/ | $$____/  \\_______/  \\_______/\\_______/      |__/  |__/\\_______/|__/|_______/   \\___/            |=   =|                                     +"<< endl;
    cout << "                                                 .                       | $$                                                                                              |     |                  .       .       "<<endl;  
    cout << "                                   .                                     | $$                      .                                                    .                  |     |           +                         +"<<endl;                          
    cout << "              +        .                                  +              |__/                                     .              +                                         |     |                                 ."<< endl;
    cout << "   +   .                .                 +                                          +                                                          +                   +      |     |                 +     "<< endl;
    cout << "                              .                                       .                           +                    +                                                   |     |                  .                    +  "<< endl;
    cout << "                         .               +                                                  .                                                                              |     |        .                  ."<< endl;
    cout << "  +           +                                          +                                                                          .           .          +               |     |  +                                  "<< endl;
    cout << "             .             .    +                      .                   .                              +       .                                                        |     |                    +                     ."<< endl;
    cout << "           .                                                                                +                                                                              |     |  .                 .            "<< endl;
    cout << "      .                  +          .                                                 +                   .                                                       .       /|##!##|\\       .                     ."<< endl;
    cout << "            .                                                                                                    +                  +            +                       / |##!##| \\                    ."<< endl;
    cout << "  +   .           +          .                 +                            .                              +            .                                   .           /  |##!##|  \\                     .       +        "<< endl;
    cout << "             .                                                           +                                                             .                               |  / ^ | ^ \\  |                           "<< endl;
    cout << "       .                 .                 +                       .                           .                             .                                         | /  ( | )  \\ |                        "<< endl;
    cout << "                                                                              +                                                                +                       |/   ( | )   \\|                  .       "<< endl;
    cout << "            .                 +                                 +                                      +                                                .                  ((   ))                     .    +              "<< endl;
    cout << "         .       +          .                     +                                                +                                     +                          .     ((  :  ))     +                    "<< endl;
    cout << "     .                +                   .                                   .                                  .         +                                              ((  :  ))                   +          "<< endl;
    cout << "                 .                 +                                                                  .                             .                                      ((   ))         .                       "<< endl;
    cout << "     .       +          .                                 +               .                                                                      +             +            (( ))                                 .           "<< endl;
    cout << "                    .                 +                                                          +                  +            +                                           ( )     .                    .         "<< endl;
    cout << "                  .                               .                                 +                                                                                         .                   +                          ."<< endl;
    cout << "   +   .       +          .        .                            +            .                              +                              .                +                 .            .                       ."<< endl;
    cout << "           +          .                 +                             .                         .                        .                       .                            .                             .              +"<< endl; 
    getch();
}
void printHeader(){
    cout << "        .                      +            .             +                                                                          .           .          +                                             "<< endl;
    cout << "                 .                                          .             +        .                   .                              +       .                                                        "<< endl;
    cout << "                                        +            .                                                            +                                                .                                 .     "<< endl;
    cout << "           +         +                                       .                             +                   .                                             +                     +                      "<< endl;
    cout << "         .                          +                       +              +                                                     +            .                                                          "<< endl;
    cout << "                                                     .                      .                              +            .                                                 .               .                  "<< endl;
    cout << "    +                                                      +            .                                       +                                                +             .                +          +  "<< endl;
    cout << "           .              +            .                  +                                                         .         .                                                                              "<< endl;
    cout << "                                         +            .                                                       +                                                                                           "<< endl;
    cout << "                                                                     +            +                                      +                               .                     +       .                    "<< endl;
    cout << "         +   .       +          .                 +            .                                          +                          +           +                   +                            .          "<< endl;
    cout << "           .                                                      .                                  .                    .                                                                                  "<< endl;
    cout << "    .            .            .                                                            .                             .                                    +                                             "<< endl;
    cout << "            .                              +            .                +               .                                             +               .                              +                +     "<< endl;
    cout << "                  +            .                                                    +                  +            +                                                                                     "<< endl;
    cout << "                 .                              +            .                   .                     .                        +             .                              +                 .           .   "<< endl;
    cout << "           .         +            .                              +                         .                                                                                                                ."<< endl;
    cout << "                                         +                                                                                 .          +                                                        .                   +"<<endl;
    cout << "           +             .       +                                      +             +               .          +        /$$         +       /$$             /$$                                       ." << endl;
    cout << "      .           .                      +                        .                 .        +                           | $$                |__/            | $$                       +                      "<< endl;
    cout << "  .                                                           +    /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$       | $$$$$$$   /$$$$$$ /$$  /$$$$$$$ /$$$$$$              .                    .               " <<endl;
    cout << "  +           +                               +          .        /$$_____/ /$$__  $$ |____  $$ /$$_____/ /$$__  $$  +   | $$__  $$ /$$__  $$|$$ /$$_____/|_  $$_/       +                               .         "<<endl;
    cout << "                   .        .                         .           | $$$$$$ |  $$  \\$$  /$$$$$$$| $$      | $$$$$$$$      | $$  \\ $$| $$$$$$$$|$$|  $$$$$$  |  $$                                      "<< endl;
    cout << "        .                                  .                +    \\____  $$|  $$  | $$ /$$__  $$| $$      | $$_____/      | $$  | $$| $$_____/|$$\\____  $$  |  $$ /$$                                   .       "<< endl;
    cout << "                                   +                              /$$$$$$$/| $$$$$$$/| $$$$$$$|  $$$$$$$|  $$$$$$$    .  | $$  | $$|  $$$$$$$|$$ /$$$$$$$/  | $$$$/      .         .                +          "<<endl;
    cout << "              .          .                                 .     |_______/ | $$____/  \\_______/  \\_______/\\_______/      |__/  |__/\\_______/|__/|_______/   \\___/                                         ."<< endl;
    cout << "                                                   .                       | $$                                                                                                                       .       .       "<<endl;  
    cout << "                                     .                                     | $$                      .                                                    .                                  .                         +"<<endl;                          
    cout << "              +          .                                  +              |__/                                     .              +                                          .                                       ."<< endl;
    cout << "   +   .                  .                 +                                          +                                                          +                   +                          +     "<< endl;
    cout << "                                .                                       .                           +                    +                                                              .                    +  "<< endl;
    cout << "                         .                 +                                                  .                                                                            .                  ."<< endl;
    
}

string printMenu(){
  system("cls");
  printHeader();
  string num;
   cout << " +*+*+*+*+*+*+*+*+*+*+*MENU+*+*+*+*+*+*+*+*+*+*+*+                                                                                     +           .          +                    "<< endl;
    cout << " -------------------------------------------------          .           +                   .          .               +                    .                                     "<< endl;
    cout << "  1-START                                                                      +                                                                                     .        "<< endl;
    cout << "  2-INSTRUCTIONS       +           +                   .                                                           +                                 +                           "<< endl;
    cout << "  3-KEYS              .                                                       .                        +                            +                                    +          " << endl;
    cout << "  4-EXIT            .                    .          +                                   +                               .                  "<< endl;
    cout << "                               +                           .                .                     .                                            +             .                  ."<< endl;
    cout << "  ENTER YOUR CHOICE : "; 
    cin >> num;
    return num;
}
void printChoice2(){
  system("cls");
  printHeader();
  cout << "               INSTRUCTIONS" <<endl;
  cout << "-------------------------------------------------" <<endl;
  cout << "THIS GAME HAS TWO LEVELS       " <<endl<<endl;
  
  cout << "The player has a total of 3 Lifes, if all the lifes are gone, YOU LOSE       " <<endl;
  cout << "If player touches the bomb (x), he loses a life      " <<endl;
  cout << "If the health decreases to 0, player loses a life      " <<endl;
  cout << "If an enemy bullet touches the player, health is decreases by 1       " <<endl;
  cout << "If the player touches an energy bottle [], health is increased by 1       " <<endl;
  cout << "A score of 10 is awarded on collecting  money $       " <<endl;
  cout << "Score is incremented by 1 on hitting a bullet to the enemy      " <<endl;
  cout << "When the score turns 200, the next level begins      " <<endl<<endl;
  cout << "Press any key to continue:      " <<endl;
  getch();



}
void printChoice3(){
  system("cls");
  printHeader();
  cout << "                      KEYS      " <<endl;
  cout << "-------------------------------------------------" <<endl;
  cout << "1-Up          Move Up      " <<endl;
  cout << "2-Down        Move Down       " <<endl;
  cout << "3-Left        Move Left       " <<endl;
  cout << "4-Right       Move Right       " <<endl;
  cout << "5-Space       Fire Bullets       " <<endl;
  cout << "press any key to continue:              " <<endl;
  getch();

}

void printMaze1(){
  system("cls");
   cout << "###############################################################################################################################################################################################"<<endl;
   cout << "###############################################################################################################################################################################################"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                                                                             (x)                                                                         ###"<<endl;
   cout << "###       $                                                                     (x)                                                                                                         ###"<<endl;
   cout << "###                                                                                                                                                      $                                  ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                              $                                                                                                                                          ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                  $                                                                                                   $                                                                  ###"<<endl;
   cout << "###                                                                                          $                                                                                              ###"<<endl;
   cout << "###                                                                                                                                        (x)                                              ###"<<endl;
   cout << "###                                                            []                                                                                                $                          ###"<<endl;
   cout << "###                                                                                                    $                                                                                    ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                      &                                                                                                                                                  ###"<<endl;
   cout << "###           $                                                                                                                                                                             ###"<<endl;
   cout << "###                                                                                                                                               $                                         ###"<<endl;
   cout << "###                                                                        $                                                                                                                ###"<<endl;
   cout << "###                                                                                                                  []                                                                     ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                                                          $                                                                                              ###"<<endl;
   cout << "###                                     (x)                                                                                                                           $                     ###"<<endl;
   cout << "###               $                                                                                                                   $                  $                                  ###"<<endl;
   cout << "###                                                                                                        $                                                                                ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                         $                         []                                                                                                    ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###               $                                                                                                                                                                         ###"<<endl;
   cout << "###                                           $                                 $                        (x)                    $                                                           ###"<<endl;
   cout << "###                                                                                                                                                        $                                ###"<<endl;
   cout << "###                           $                                                                   $                                                                                         ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                                     (x)                                                                  $                                              ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###                                                             $                                            $                 $                                                            ###"<<endl;
   cout << "###                     $                    []                                                                                                  (x)                                        ###"<<endl;
   cout << "###                                                                                                                                                                  (x)                    ###"<<endl;
   cout << "###                                                                                     (x)                                                                                                 ###"<<endl;
   cout << "###                                                                                                                                                                                         ###"<<endl;
   cout << "###############################################################################################################################################################################################"<<endl;
   cout << "###############################################################################################################################################################################################"<<endl;
   
}

