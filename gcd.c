#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//correct # args
	if(argc > 4 || argc < 3) {
		printf("Usage: ./gcd int1 int2 <base>\n");
		return -1;
	}

	int base = 10;
	if(argc == 4) {
		base = strtol(argv[3], &argv[3], 10);
	}

	int x = 1, y = 0, q, u, v, w;
	int i = 0;
	while(*(argv[1] + i) != '\0') {
		if((int)*(argv[1] + i) < 48 || (int)*(argv[1] + i) > (47 + base)) {
			printf("Invalid Argument(s)\nUsage: ./gcd int1 int2 <base>\n");
			return 3;
		}
		i++;
	}
	i = 0;
	while(*(argv[2] + i) != '\0') {
		if((int)*(argv[2] + i) < 48 || (int)*(argv[2] + i) > (47 + base)) {
			printf("Invalid Argument(s)\nUsage: ./gcd int1 int2 <base>\n");
			return 3;
		}
		i++;
	}
	//FIXME this only works for base 1 - 10. add support for base 11+ using ascii vals.

	int a = strtol(argv[1], &argv[1], base), b = strtol(argv[2], &argv[2], base);
	int r = 0, s = 1;
	if(a < b) {	//a >= b check
		r = a;
		a = b;
		b = r;
		r = 0;
	}
	int g = a, t = b;
	if(b == 0) {	//when arg(s) == 0
		if(a == 0) {
			printf("UNDEFINED\n");
			return 1;
		}
		printf("%d\n", a);
		return 2;
	}

	//extended euclidean algo
	while(t > 0) {
		q = g/t;
		u = x - (q*r);
		v = y - (q*s);
		w = g - (q*t);
		x = r;
		y = s;
		g = t;
		r = u;
		s = v;
		t = w;
	}
	printf("gcd(%d, %d): %d\n", a, b, g);
	printf("x: %d\ny: %d\n", x, y);
	printf("%d = %d(%d) + %d(%d)\n", g, a, x, b, y);
	return 0;
}
