#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define LIMIT	640


void main() {
	int gd = DETECT;
	int gm = 0;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	/*int i, j;
	for(i = 0; i < LIMIT; i++) {
		for(j = 0; j < LIMIT; j++) {
			putpixel(i, j, WHITE);
		}
	}*/

	int x1, y1, x2, y2;
	float dx, dy;
	float step;
	float x, y;

	printf("Enter x1, y1, x2, y2");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	if( x1 == x2 && y1 == y2 ) {
		putpixel(x1, y1, GREEN);
		getch();
		return;
	}

	dx = x2-x1;
	dy = y2-y1;

	if( dx >= dy ) {
		step = dx;
	} else {
		step = dy;
	}

	dx /= step;
	dy /= step;

	x = x1 + 0.5*( int( dx/abs(dx) ) );
	y = y1 + 0.5*( int( dy/abs(dy) ) );

	putpixel(x, y, GREEN);

	int i = 1;
	int choice;

		printf("1. normal line\n2. dotted line\n3. dashed line\n4. thick");
		printf("Enter choice\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				while( i <= step ) {
					x = x + dx;
					y = y + dy;
					putpixel(x, y, GREEN);
					i++;
				}
				x = x*2;
				y = y*2;

			case 2:
				while( i <= step ) {
					x = x + dx;
					y = y + dy;
					if( i%6 == 0 )
						putpixel(x, y, GREEN);
					i++;
				}

			case 3:
				while( i <= step ) {
					x = x + dx;
					y = y + dy;

					if( i%6 != 0 )
						putpixel(x, y, GREEN);


					i++;
				}
			case 4:
				while( i <= step ) {
					x = x + dx;
					y = y + dy;
					putpixel(x, y, GREEN);
					putpixel(x+1, y, GREEN);
					putpixel(x-1, y, GREEN);
					i++;
				}
				
		}

	/*while( i <= step ) {
		x = x + dx;
		y = y + dy;

		if( i%6 == 0 )
			putpixel(x, y, GREEN);


		i++;
	} */


	getch();
}

