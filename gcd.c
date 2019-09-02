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
	//TODO add extended euclidean algo

	int base = 10;
	if(argc == 4) {
		base = strtol(argv[3], &argv[3], 10);
	}
	int dividend = strtol(argv[1], &argv[1], base), divisor = strtol(argv[2], &argv[2], base), remainder;

	if(dividend < divisor) {	//dividend > divisor check
		remainder = dividend;
		dividend = divisor;
		divisor = remainder;
	}
	if(divisor == 0) {	//check for 0
		if(dividend == 0) {
			printf("UNDEFINED\n");
			return 1;
		}
		printf("%d\n", dividend);
		return 2;
	}
	remainder = dividend % divisor;
	while(remainder != 0) {
		remainder = dividend % divisor;
		dividend = divisor;
		divisor = remainder;
	}
	printf("%d\n", abs(dividend));
	return 0;
}
