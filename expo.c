#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main() {

  double t = 0.0;
  int gd = DETECT, gm;
  float x = 0.0;
  initgraph(&gd, &gm, "");

  line(0, 240, getmaxx(), 240);
  for (int i = 0; i < 8000; ++i) {
    putpixel(x, ((int)(-exp(t)) + 470) % getmaxy(), 15);
    x += 0.08;
    t += 0.001;
    delay(5);
  }

  getch();
  closegraph();
  return 0;
}