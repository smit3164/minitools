// Chinese Remainder Theorem calculator

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	char * usage = "Usage: ./crt a b m n\n";
	int input[argc+2];
	int valid = 0;

	if(argc != 5) {
		printf("%s", usage);
		return -1;
	}

	for(int i = 1; i < argc; i++) {
		valid = sscanf(argv[i], "%d", &input[i-1]);
		if(valid == 0) {
			printf("Invalid argument \'%s\'\n", argv[i]);
			printf("%s", usage);
			return -2;
		}
	}
	//input[0] - input[3] are a, b, m, and n respectively

	//check that gcd(m, n) = 1
	int num = abs(input[2]);
	int denom = abs(input[3]);
	if(denom > num) {
		num = abs(input[3]);
		denom = abs(input[2]);
	}
	int rem = num % denom;
	int g = num, t = denom;	//for use in next section
	while(rem != 0) {
		num = denom;
		denom = rem;
		rem = num % denom;
	}
	
	if(denom != 1) {
		printf("GCD of \'%d\' and \'%d\' is %d, not 1 (required)\n", input[2], input[3], denom);
		return -3;
	}

	//use Extended Euclidean algorithm to find c and d (input[4] and input[5])
	int q, r = 0, s = 1, u, v, w;
	input[5] = 1;
	input[4] = 0;
	while(t > 0) {
		q = g/t;
		u = input[5] - (q*r);
		v = input[4] - (q*s);
		w = g - (q*t);
		input[5] = r;
		input[4] = s;
		g = t;
		r = u;
		s = v;
		t = w;
	}

	if(input[2] < 0) { input[4] *= -1; }
	if(input[3] < 0) { input[5] *= -1; }

	printf("c (m^-1): %d\nd (n^-1): %d\n", input[4], input[5]);

	//calculate mcb + nda (mod mn)
	//remember to account for negative numbers
	int result = ((input[2] * input[4] * input[1]) + (input[3] * input[5] * input[0])) % (input[2] *
	input[3]);

	if(result < 0) { result += (input[2] * input[3]); }

	//output result and return
	printf("Solution: %d (mod %d)\n", result, (input[2] * input[3]));
	return 0;
}
