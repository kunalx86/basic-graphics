#include <stdio.h>
// Uncomment the following line if working in DOS Box
// #include <conio.h>
#include <graphics.h>

// This wiil return the bit present at pth location in number
#define EXTRACTBIT(number, p) (1 & (number >> (p - 1)))

typedef struct {
	int x, y;
	int code;
} point;

typedef struct {
	int x1, y1;
	int x2, y2;
} box;

// The region code will be assigned in binary
void regionCode(point *p, box *b) {
	if (p->y < b->y1) p->code += 0b1000; // 0b simply means in binary
	if (p->y > b->y2) p->code += 0b100;
	if (p->x > b->x2) p->code += 0b10;
	if (p->x < b->x1) p->code += 0b1;
}

void sutherHelper(point* p1, point* p2, box* b) {
	// sleep(0.2);
	point res;
  res.code = 0;
  res.x = p1->x + (p2->x - p1->x) / 2, res.y =  p1->y + (p2->y - p1->y) / 2; 
  regionCode(&res, b);
  int and1 = p1->code & res.code;
  int and2 = p2->code & res.code;
	// The below is unstable implementation
  if (!res.code && !p1->code) {
    line(p1->x, p1->y, res.x, res.y);
		// return;
	}
  else {
		if (and1) return;
    sutherHelper(p1, &res, b);
		res.x++, res.y++;
  }
  if (!res.code && !p2->code) {
    line(res.x, res.y, p1->x, p1->y);
    // return;
  }
  else {
		if (and2) return;
		sutherHelper(&res, p2, b);
  }
	// Below is the textbook implementation
	// if ((p1->code == 0) && (p2->code == 0)) {
	// 	line(p1->x, p2->x, p1->y, p2->y);
	// 	return;
	// }
	// else {
	// 	if (p1->code & p2->code) return;
	// 	else {
	// 		sutherHelper(p1, &res, b);
	// 		sutherHelper(&res, p2, b);
	// 	}
	// }
}

void sutherHelperNonRecursive(point p1, point p2, box *b) {
	int t1 = 0, t2 = 0, f1 = 0, f2 = 0;
	point res;
	while (1) {
		res.x = ( p1.x + p2.x ) / 2; 
		res.y = ( p1.y + p2.y ) / 2;
		regionCode(&res, b);
		if (!res.code && !p1.code) {
	    line(p1.x, p1.y, res.x, res.y);
		} 
		else {
			if (! (res.code & p1.code) ) {
				t1 = 1;
			} else {
				break;
			}
		}
	}
	while (1) {
		res.x = ( p1.x + p2.x ) / 2; 
		res.y = ( p1.y + p2.y ) / 2;
		regionCode(&res, b);
		if (!res.code && !p2.code) {
	    line(p2.x, p2.y, res.x, res.y);
		} 
		else {
			if (! (res.code & p2.code) ) {
				t2 = 1;
			} 
			else {
				f2 = 1;
			}
		}
	}
}

void sutherCohan(point *p1, point *p2, box b, double slope) {
	int and_res;
	point pr_1, pr_2;
	if ((p1->code == 0) && (p2->code == 0)) {
		// Line is completely visisble
		line(p1->x, p1->y, p2->x, p2->y);
	}
	else {
		// Line might not be visible or partially visible
		and_res = p1->code & p2->code;
		printf("AND result: %d\n", and_res);
		if (and_res!=0) {
			// Line is not visible
			printf("Line not visible!");
		}
		else {
			// Line is partially visible
			sutherHelper(p1, p2, &b);
			// sutherHelperNonRecursive(*p1, *p2, b);
		}
	}
}

void main() {
	point p1, p2;
	int gd = DETECT, gm;
	double slope = 0.0;
	box b;
	p1.code = p2.code = 0;
	printf("Enter the line coordinates: \n");
	scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
	printf("Enter coords for box: \n");
	scanf("%d %d %d %d", &b.x1, &b.y1, &b.x2, &b.y2);
	slope = (p2.y - p1.y) / (double)(p2.x - p1.x);

	initgraph(&gd, &gm, "../BGI");

	printf("Line coordinates: (%d %d), (%d %d)\n", p1.x, p1.y, p2.x, p2.y);
	printf("Box coordinates: (%d %d), (%d %d)\n", b.x1, b.y1, b.x2, b.y2);

	regionCode(&p1, &b);
	regionCode(&p2, &b);

	printf("Region code for point 1: %d\n", p1.code);
	printf("Region code for point 2: %d\n", p2.code);

	rectangle(b.x1, b.y1, b.x2, b.y2);

	sutherCohan(&p1, &p2, b, slope);

	getch();
	closegraph();
}