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
void regionCode(point *p, box b) {
	if (p->y < b.y1) p->code = p->code + 0b1000; // 0b simply means in binary
	if (p->y > b.y2) p->code = p->code + 0b100;
	if (p->x > b.x2) p->code = p->code + 0b10;
	if (p->x < b.x1) p->code = p->code + 0b1;
}

// This function detetermines where the point p1 lies and will appropriately store the result coordinates in pr
void sutherHelper(point *pr, point *p1, box b, double slope) {
	if (p1->code == 0) {
		pr->x = p1->x;
		pr->y = p1->y;
	}
	else {
		// Check for x
		if (EXTRACTBIT(p1->code, 2) || EXTRACTBIT(p1->code, 1)) {
			if (EXTRACTBIT(p1->code, 1)) pr->x = b.x1;
			else pr->x = b.x2;
			pr->y = (slope * (pr->x - p1->x)) + p1->y;
			// Following conditions are for the exceptional diagonal case
			if (p1->y == b.y1) pr->y = b.y1;
			if (p1->y == b.y2) pr->y = b.y2;
		}
		// Check for y
		else /*(EXTRACTBIT(p1->code, 4) || EXTRACTBIT(p1->code, 3))*/ {
			if (EXTRACTBIT(p1->code, 4)) pr->y = b.y1;
			else pr->y = b.y2;
			pr->x = p1->x + ((1 / slope) * (pr->y - p1->y));
			// Following conditions are for the exceptional diagonal case
			if (p1->x == b.x1) pr->x = b.x1;
			if (p1->x == b.x2) pr->x = b.x2;
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
			sutherHelper(&pr_1, p1, b, slope);
			sutherHelper(&pr_2, p2, b, slope);
			printf("Result line coords: (%d %d), (%d %d)\n", pr_1.x, pr_1.y, pr_2.x, pr_2.y);
			line(pr_1.x, pr_1.y, pr_2.x, pr_2.y);
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

	regionCode(&p1, b);
	regionCode(&p2, b);

	printf("Region code for point 1: %d\n", p1.code);
	printf("Region code for point 2: %d\n", p2.code);

	rectangle(b.x1, b.y1, b.x2, b.y2);

	sutherCohan(&p1, &p2, b, slope);

	getch();
	closegraph();
}