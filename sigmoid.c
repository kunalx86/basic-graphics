#include <stdio.h>
#include <graphics.h>
#include <math.h>

float sigmoid(double x) {
  return (exp(x) / (float)(exp(x) + 1));
}

// sigmoid(x) = exp(x) / exp(x) + 1
int main() {

  double t = 0.0;
  int gd = DETECT, gm;
  float x = 0.0;
  initgraph(&gd, &gm, "");

  line(0, 240, getmaxx(), 240);
  for (int i = 0; i < 8000; ++i) {
    putpixel(x, (sigmoid(t)), 15);
    x += 0.08;
    t += 0.001;
    delay(2);
  }

  getch();
  closegraph();
  return 0;
}