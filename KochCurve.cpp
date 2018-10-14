//
//  main.cpp
//  koch_curve
//
//  Created by Kaiying Shan on 2018/7/29.
//  Copyright © 2018 Kaiying Shan. All rights reserved.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int w, h, x, y;
char* image;

void draw(int i, int j, char c) {
	char *d = image + j * w + i;
	if (*d == '_' || *d == ' ') {
		*d = c;
	}
}

void kochCurve(int n, int dir) {
	if (n == 0) {
		switch (dir % 6) {
		case 0:
			draw(x++, y, '_');
			draw(x++, y, '_');
			break;
		case 1:
			draw(x++, y--, '/');
			break;
		case 2:
			draw(--x, y--, '\\');
			break;
		case 3:
			draw(--x, y, '_');
			draw(--x, y, '_');
			break;
		case 4:
			draw(--x, ++y, '/');
			break;
		case 5:
			draw(x++, ++y, '\\');
			break;
		}
	}
	else {
		kochCurve(n - 1, dir);
		kochCurve(n - 1, dir + 1);
		kochCurve(n - 1, dir + 5);
		kochCurve(n - 1, dir);
	}
}

int main(int argc, const char * argv[]) {
	int num;
	while (scanf_s("%d", &num) == 1 && num != 0) {
		w = 6;
		h = 3;
		printf("\nn=%d\n", num);
		w *= (int) pow(3, num);
		h *= (int) num;
		x = 0;
		y = h - 1;
		image = (char*)malloc(w * h);
		memset(image, ' ', w * h);
		kochCurve(num, 0);
		for (int a = 0; a < h; a++) {
			for (int b = 0; b < w; b++) {
				putchar(image[a * w + b]);
			}
			putchar('\n');
		}
		free(image);
	}
	return 0;
}