#include<stdio.h>
// #include<conio.h>
#include<graphics.h>
 
int main()
{
      int gd = DETECT, gm;
      int left = 100, right = 200, top = 100, bottom = 200;
      printf("\nLet's build a sample rectangle using Graphics in C\n");
      initgraph(&gd, &gm, NULL);
      rectangle(left, top, right, bottom);
      getch();
      closegraph();
      return 0;
}
