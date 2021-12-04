#include <math.h>

float Derivative(float a, float deltax){
	return (cos(a + deltax) - cos(a - deltax)) / (2 * deltax);
}

int PrimeCount(int a, int b){
	int cnt = 0;
	int sieve[b + 1];
	for(int i = 0; i < b + 1; ++i){
		sieve[i] = 0;
	}
	sieve[0] = 1;
	sieve[1] = 1;
	for(int i = 2; i <= b; ++i){
		if(sieve[i] != 0){
			continue;
		}
		for(int j = 2 * i; j <= b; j += i){
			sieve[j] = 1;
		}
		++cnt;
	}
	return cnt;
}