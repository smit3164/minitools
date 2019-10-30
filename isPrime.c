//Determine if a number is prime
#include <stdio.h>

int main(int argc, char * argv[]) {
	if(argc != 2) {
		printf("Usage: ./isPrime num\n");
		return -1;
	}
	int n;
	if(sscanf(argv[1], "%d", &n) == 0) {
		printf("Invalid argument \'%s\'\n", argv[1]);
		return -2;
	}
	if((argv[1][0] != '-') && (n < 0)) {
		printf("Invalid argument \'%s\' (> 2147483647)\n", argv[1]);
		return -3;
	}
	if((argv[1][0] == '-') && (n > 0)) {
		printf("Invalid argument \'%s\' (< -2147483648)\n", argv[1]);
		return -3;
	}
	if(n < 0) {
		printf("\'%s\' is NOT prime (Note: negative numbers are not prime)\n", argv[1]);
		return 2;
	}
	if((n == 0) || (n == 1)) {
		printf("\'%s\' is NEITHER prime NOR composite\n", argv[1]);
		return 3;
	}
	if(!(n == 2) && !(n == 3) && !(n % 6 == 5) && !(n % 6 == 1)) {
		printf("\'%s\' is COMPOSITE\n", argv[1]);
		return 1;
	}
	printf("\'%s\' is PRIME\n", argv[1]);
	return 0;
}
