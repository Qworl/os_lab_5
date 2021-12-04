#include <math.h>
#include <stdbool.h>

float Derivative(float a, float deltax){
	return (cos(a + deltax) - cos(a)) / deltax;
}

int PrimeCount(int a, int b){
	int cnt = 0;
	bool fnd_divider = false;
	if(a == 1) ++a;
	for(int i = a; i <= b; ++i){
		for(int j = i - 1; j > 1; --j){
			if(i % j == 0){
				fnd_divider = true;
				break;
			}
		}
		if(!fnd_divider){ 
			++cnt;
		}
		fnd_divider = false;
	}
	return cnt;
}
