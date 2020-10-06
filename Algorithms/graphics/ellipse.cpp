#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main(){
    initwindow(600,600);
     for (int i=1; i<=3; i++) 
    {  
        setcolor(i);  
        settextstyle(i,0,i+2); 
        outtextxy(100,20*i,"Text - 32 !");     
        delay(500); 
    }  
    int i=4;
        settextstyle(i,1,i);
        setcolor(i);
        outtextxy( 305, 45,"vertical");
    getch();
    return 0;
}

