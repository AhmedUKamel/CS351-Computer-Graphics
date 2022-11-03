#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C://TURBOC3/BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   left   = getmaxx() / 2 - 100;
   top    = getmaxy() / 2 -  50;
   right  = getmaxx() / 2 + 100;
   bottom = getmaxy() / 2 +  50;
   
   /* color  rectangle 1*/
   setfillstyle(SOLID_FILL, 100);
   floodfill(getmaxx() / 2, getmaxx() / 2, getmaxcolor());

   /* draw a rectangle 1*/
   rectangle(left,top,right,bottom);

   left   = getmaxx() / 2 - 150;
   top    = getmaxy() / 2 - 100;
   right  = getmaxx() / 2 + 150;
   bottom = getmaxy() / 2 + 100;

   /* color  rectangle 2*/
   setfillstyle(SOLID_FILL, 150);
   floodfill(getmaxx() / 2, (getmaxx() / 2) - 100, getmaxcolor());

   /* draw a rectangle 2*/
   rectangle(left,top,right,bottom);

   left   = getmaxx() / 2 - 200;
   top    = getmaxy() / 2 - 150;
   right  = getmaxx() / 2 + 200;
   bottom = getmaxy() / 2 + 150;

   /* color  rectangle 3*/
   setfillstyle(SOLID_FILL, 200);
   floodfill(getmaxx() / 2, (getmaxx() / 2) - 150, getmaxcolor());

   /* draw a rectangle 3*/
   rectangle(left,top,right,bottom);

   /* color  rectangle 4*/
   setfillstyle(SOLID_FILL, 250);
   floodfill(0, 0, getmaxcolor());

   /* clean up */
   getch();
   closegraph();
   return 0;
}