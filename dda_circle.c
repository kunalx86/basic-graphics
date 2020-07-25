#include <graphics.h>
#include <math.h>
#include <unistd.h>
#include <X11/Xlib.h>

void wait_for_char() {
	int i = 0;
	
	while(i == 0) 
		i = getchar();
}

int main() {
	XInitThreads();
	int gd = DETECT, gm;
	float rad, eps, x, y, xi, yi, x1, y1;
	int i = 0;
	scanf("%f", &rad);
	while(pow(2, i) < rad) {
		i++;
	}	
	eps = (1 / pow(2, i));
	x = 0, y = rad;
	x1 = x, y1 = rad;
	initgraph(&gd, &gm, NULL);
	do {
		xi = x1 + y1 * eps;
		yi = y1 - eps * xi; 
		putpixel((getmaxx() / 2) + xi, (getmaxy() / 2) + yi, 15);
		// sleep(10);
		x1 = xi;
		y1 = yi;
	} while((y1 - y) < eps || (x - x1) > eps);
	// wait_for_char();
	closegraph();
	return 0;
}
