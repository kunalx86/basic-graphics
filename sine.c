#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main() {

  double t = 0.0;
  int gd = DETECT, gm;
  float x = 0.0;
  initgraph(&gd, &gm, "");

  line(0, 240, getmaxx(), 240);
  for (int i = 0; i < 6400; ++i) {
    putpixel(x, (sin(t) * 120)+ 240, 15);
    putpixel(x, (cos(t) * 120)+ 240, 15);
    if (((tan(t) * 120) + 240) <= getmaxy() && ((tan(t) * 120) + 240) >= 0) {
      putpixel(x, (tan(t) * 120)+ 240, 15);
    }
    x += 0.1;
    t += 0.001;
    delay(2);
  }

  getch();
  closegraph();
  return 0;
}