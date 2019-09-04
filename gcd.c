#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char* e;
	//correct # args
	if(argc > 4 || argc < 3) {
		printf("Usage: ./gcd int1 int2 <base>\n");
		return -1;
	}

	int base = 10;
	int i = 0;
	if(argc == 4) {
		while(*(argv[3] + i) != '\0') {
			if((int)*(argv[3] + i) < 48 || (int)*(argv[3] + i) > 57) {
				printf("Base argument must be a positive base-10 integer\nUsage: ./gcd int1 int2 <base>\n");
				return 3;
			}
			i++;
		}
		base = strtol(argv[3], &e, 10);
		if(base < 1 || base > 36) {
			printf("Invalid base. Use 0 < base < 37\n");
			return 4;
		}
	}

	int x = 1, y = 0, q, u, v, w;
	i = 0;
	while(*(argv[1] + i) != '\0') {
		if(base > 10) {
			if(((int)*(argv[1] + i) > 96) && ((int)*(argv[1] + i) < (87 + base))) {
				*(argv[1] + i) = *(argv[1] + i) - 32;
			} else if(((int)*(argv[1] + i) < 65 && ((int)*(argv[1] + i) > 57 || (int)*(argv[1] + i) < 48)) || (int)*(argv[1] + i) > (54 + base)) {
				printf("Invalid argument(s)\nUsage: ./gcd int1 int2 <base>\n");
				return 5;
			}
		}
		if((base < 11) && ((int)*(argv[1] + i) < 48 || (int)*(argv[1] + i) > (47 + base))) {
			printf("Invalid Argument(s)\nUsage: ./gcd int1 int2 <base>\n");
			return 3;
		}
		i++;
	}
	i = 0;
	while(*(argv[2] + i) != '\0') {
		if(base > 10) {
			if(((int)*(argv[2] + i) > 96) && ((int)*(argv[2] + i) < (87 + base))) {
				*(argv[2] + i) = *(argv[2] + i) - 32;
			} else if(((int)*(argv[2] + i) < 65 && ((int)*(argv[2] + i) > 57 || (int)*(argv[2] + i) < 48)) || (int)*(argv[2] + i) > (54 + base)) {
				printf("Invalid argument(s)\nUsage: ./gcd int1 int2 <base>\n");
				return 5;
			}
		}
		if((base < 11) && ((int)*(argv[2] + i) < 48 || (int)*(argv[2] + i) > (47 + base))) {
			printf("Invalid Argument(s)\nUsage: ./gcd int1 int2 <base>\n");
			return 3;
		}
		i++;
	}
	//FIXME accept (-) in argv[1] and argv[2]

	int a = strtol(argv[1], &e, base), b = strtol(argv[2], &e, base);
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
	printf("gcd(%d, %d): %d\n", (int)strtol(argv[1], &e, base), (int)strtol(argv[2], &e, base), g);
	printf("x: %d\ny: %d\n", x, y);
	printf("%d = %d(%d) + %d(%d)\n", g, a, x, b, y);
	return 0;
}
