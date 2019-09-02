#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//error checking
	if(argc > 4 || argc < 3) {
		printf("Usage: ./gcd num1 num2 <base>\n");
		return -1;
	}
	//TODO check convert success

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
	remainder = dividend % divisor;
	while(remainder != 0) {
		remainder = dividend % divisor;
		dividend = divisor;
		divisor = remainder;
	}
	printf("%d\n", abs(dividend));
	return 0;
}
