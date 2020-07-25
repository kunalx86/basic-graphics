#include <stdio.h>
#include <graphics.h>
// Uncomment the following line if working on DOSBOX
// #include <conio.h>

// Following are the MACROS for Height and Width of the bitmap respectively
#define h 18
#define w 12

void main() {
  // Following is the bitmap for letter 'K'
  int k_map[h][w] = { 
    { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    { 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    { 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    { 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    { 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    { 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    { 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    { 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    { 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    { 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    { 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    { 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    { 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    { 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    { 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  };
  int gd = DETECT, gm;

  initgraph(&gd, &gm, "../BGI");

  for (int x = 0; x < h; ++x) 
    for (int y = 0; y < w; ++y) 
      putpixel(y + 300, x + 220, 15 * k_map[x][y]);

  getch();
  closegraph();
}