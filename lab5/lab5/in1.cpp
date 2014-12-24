#include <iostream>
#include <conio.h>

int main(){
int x,x1; //x1 - Футы;
int m,f,y;
std::cin>>x1; std::cout<<std::endl;
x=x1;
m=x/(6000.0);
y=(x-m*6000.0)/3;
f=(x-m*6000.0)/2000;
std::cout<<m<<" mile, "<<y<<" Yds "<<f<< " Fts " <<std::endl;
getch();
return 0;
}