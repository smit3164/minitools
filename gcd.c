#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//correct # args
	if(argc > 4 || argc < 3) {
		printf("Usage: ./gcd num1 num2 <base>\n");
		return -1;
	}
	//TODO handle a, 2
	//TODO handle incorrect base for inputs

	int base = 10;
	if(argc == 4) {
		base = strtol(argv[3], &argv[3], 10);
	}
	//extended euclidean algo
	int x = 1, y = 0, q, u, v, w;
	int a = strtol(argv[1], &argv[1], base), b = strtol(argv[2], &argv[2], base);
	int r = 0, s = 1;
	if(a < b) {	//dividend > divisor check
		r = a;
		a = b;
		b = r;
		r = 0;
	}
	int g = a, t = b;
	if(b == 0) {	//check for 0
		if(a == 0) {
			printf("UNDEFINED\n");
			return 1;
		}
		printf("%d\n", a);
		return 2;
	}
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
