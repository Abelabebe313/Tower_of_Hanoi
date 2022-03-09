#include <iostream>
#include<windows.h>
#include <math.h>
#define Max 10
using namespace std;
int choice;
int diskNum;
int countr=0;
int arrA[Max];
int arrB[Max];
int arrC[Max];
int TopA=-1;
int TopB=-1;
int TopC=-1;
int Size=0;
void welcome(){
    int ch;
    system("cls");
 c: cout<<"\t\tMENU"<<endl;
    cout<<"Press 1 to start the Game"<<endl;
    cin>>ch;
    if(ch==1){
        system("cls");
        cout<<"Enter the Number of Disk"<<endl;
         cin>>diskNum;
       }
    else{
        cout<<"wrong input"<<endl;
        goto c;
    }
}
void gotoPos(short x, short y){
    COORD cord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cord);
}
void pushA(int data){
        ++TopA;
        ++Size;
        arrA[TopA]=data;
}
void pushB(int data){
        ++TopB;
        ++Size;
        arrB[TopB]=data;
}
void pushC(int data){
        ++TopC;
        ++Size;
        arrC[TopC]=data;
}
int popA(){
    int value;
    value = arrA[TopA];
    arrA[TopA] = NULL;
    --TopA;
    --Size;
  return value;
}
int popB(){
    int value;
    value = arrB[TopB];
    arrB[TopB] = NULL;
    --TopB;
    --Size;
  return value;
}
int popC(){
    int value;
    value = arrC[TopC];
    arrC[TopC] = NULL;
    --TopC;
    --Size;
  return value;
}
void counter(){
    ++countr;
}
void Move(){
    gotoPos(50,5);
   cout<<"Move"<<endl;
   gotoPos(40,6);
   cout<<"1 To Move From A to B"<<endl;
   gotoPos(40,7);
   cout<<"2 To Move From A to C"<<endl;
   gotoPos(40,8);
   cout<<"3 To Move From B to A"<<endl;
   gotoPos(40,9);
   cout<<"4 To Move From B to C"<<endl;
   gotoPos(40,10);
   cout<<"5 To Move From C to A"<<endl;
   gotoPos(40,11);
   cout<<"6 To Move From C to B"<<endl;
   gotoPos(40,12);
   cout<<"7 To exit"<<endl;
}
void display(){
    system("cls");
    cout<<"  ____________________________________________________________________"<<endl;
    cout<<"                                                                      "<<endl;
    cout<<"  \t\t\t-------**TOWER OF HANOI**------\n";
    cout<<"                                                            counter:-"<<countr<<endl;
    cout<<"  ____________________________________________________________________"<<endl;
    cout<<endl;
    //gotoPos(25,10);
  for(int i=diskNum-1; i>=0; i--){
      if(arrA[i]==0){
         cout<<"\t|   |";
        }
      else
         cout<<"\t| "<<arrA[i]<<" |";

      if(arrB[i]==0){
         cout<<"\t|   |";
        }
      else
         cout<<"\t| "<<arrB[i]<<" |";

      if(arrC[i]==0){
         cout<<"\t|   |";
        }
      else
         cout<<"\t| "<<arrC[i]<<" |";
      cout<<endl;
    }
    //gotoPos(25,13);
    cout<<"\t_____\t_____\t_____\n";
    //gotoPos(25,14);
    cout<<"\t  A  \t  B  \t  C\n";
    Move();
 cout<<"  ____________________________________________________________________"<<endl;
}
void Winner(){
   cout<<"\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
   cout<<"\t\t\tCongratulations"<<endl;
   cout<<"\t\t\t   You Win!!!"<<endl;
   cout<<"\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
}
void Losser(){
   cout<<"\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
   cout<<"\t\t\t   Try Again"<<endl;
   cout<<"\t\t\t   You lose!!!"<<endl;
   cout<<"\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
}
int main(){
 d:   welcome();
   for(int i=diskNum; i>0; i--){  //initially the disks will pushed to the first stack disknum of times to start the game
      pushA(i);
   }
a:  display();
while(!(TopA == -1 && TopB == -1 || TopA == -1 && TopC == -1)){
b:  cin>>choice;
   int num;
    switch(choice){
        case 1:
            counter();
              if((arrA[TopA]==0) && (arrB[TopB]==0)){
                cout<<"Nothing to move"<<endl;
                goto b;
              }
              else if(TopB==-1){
                 num=popA();
                 pushB(num);
                 display();
              }
             else if(arrA[TopA] > arrB[TopB]){
                cout<<"\tyou Can't put large number on small number"<<endl;
                cout<<"\tTry another move"<<endl;
                display();
             }
             else if(arrB[TopB] >= arrA[TopA]){
                 num=popA();
                 pushB(num);
                 display();
              }
             goto a;
             break;
        case 2:
            counter();
             if((arrA[TopA]==0)&& (arrC[TopC]==0)){
                cout<<"Noting to move"<<endl;
                goto b;
              }
            else if(TopC==-1){
                    num = popA();
                 pushC(num);
                 display();
              }
            else if(arrA[TopA] > arrC[TopC]){
                cout<<"\t you Can't put large number on small Number"<<endl;
                cout<<"\tTry another move"<<endl;
                goto b;
                //display();
              }
              else if(arrC[TopC] >= arrA[TopA]){
                  num = popA();
                 pushC(num);
                 display();
              }
             goto a;
             break;
        case 3:
            counter();
             if((arrA[TopA]==0) && (arrB[TopB]==0)){
                cout<<"Nothing to move"<<endl;
                goto b;
              }
             else if(TopA==-1){
                num = popB();
                pushA(num);
                display();
             }
             else if(arrB[TopB] > arrA[TopA]){
                cout<<"\t you Can't put large number on small"<<endl;
                cout<<"\tTry another move"<<endl;
                goto b;
             }
             else if(arrA[TopA] >= arrB[TopB]){
                num = popB();
                pushA(num);
                display();
             }
             goto a;
             break;
        case 4:
              counter();
             if((arrC[TopC]==0) && (arrB[TopB]==0)){
                cout<<"Nothing to move"<<endl;
                goto b;
              }
             else if(TopC==-1){
                 num = popB();
                pushC(num);
                display();
             }
             else if(arrB[TopB] > arrC[TopC]){
                cout<<"\t you Can't put large number on small"<<endl;
                cout<<"\tTry another move"<<endl;
                goto b;
             }
             else if(arrC[TopC]>= arrB[TopB]){
                 num = popB();
                pushC(num);
                display();
             }
             goto a;
             break;
        case 5:
            counter();
            if((arrA[TopA]==0) && (arrC[TopC]==0)){
                cout<<"Nothing to move"<<endl;
                goto b;
              }
             else if(TopA==-1){
                num = popC();
                pushA(num);
                display();
             }
             else if(arrC[TopC] > arrA[TopA]){
                cout<<"\t you Can't put large number on small"<<endl;
                cout<<"\tTry another move"<<endl;
                goto b;
             }
             else if(arrA[TopA] >= arrC[TopC]){
                num = popC();
                pushA(num);
                display();
             }
             goto a;
             break;
        case 6:
             counter();
             if((arrC[TopC]==0) && (arrB[TopB]==0)){
                cout<<"Nothing to move"<<endl;
                goto b;
              }
              else if(TopB==-1){
                 num=popC();
                 pushB(num);
                 display();
              }
             else if(arrC[TopC] > arrB[TopB]){
                cout<<"\tyou Can't put large number on smal number"<<endl;
                cout<<"\tTry another move"<<endl;
                goto b;
                //display();
             }
             else if(arrB[TopB] >= arrC[TopC]){
                 num=popC();
                 pushB(num);
                 display();
              }
             goto a;
             break;
        case 7:
            goto d;
      }
     }
     system("cls");
     if(countr = ((pow(2,diskNum)) + 2)){
        Winner();
     }
     else {
        Losser();
        cout<<"press 1 to retry the game "<<endl;
     }
     system("pause");
}
