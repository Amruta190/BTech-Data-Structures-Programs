// #include<stdio.h>
// #include "windows.h"
// void gotoxy(int x, int y) 
// { 
//     COORD coord;
//     coord.X = x; 
//     coord.Y = y;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//     printf("%d %d",coord.X,coord.Y);
// }
// void main()
// {
//     gotoxy(10,20);
// }
#include<iostream>
using namespace std;
#include<conio.h>
void gotoxy(int i,int j)
 { int o=0,p=0;
    for(;p<=j;p++)
      { cout<<"\n";
      } 
    for(;o<=i;o++)
      {cout<<" ";
      }

  }