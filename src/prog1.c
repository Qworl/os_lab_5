#include <stdio.h>
#include "functions.h"

int main(){
	printf("1 + float A + float deltaX - derivative of cos in dot A with deltaX as delta\n");
	printf("2 + int A + int B - number of prime numbers in [a,b]\n");
	int command;
	while(scanf("%d", &command) != EOF){
		switch(command){
			case 1:{
				float a, deltax;
				if(scanf("%f%f", &a, &deltax) != 2){
					printf("Wrong arguements!\n");
					continue;
				} 
				printf("%f\n", Derivative(a, deltax));
				break;
			}
			case 2:{
				int a, b;
				if(scanf("%d%d", &a, &b) != 2){
					printf("Wrong arguements!\n");
					continue;
				} 
				printf("%d\n", PrimeCount(a, b));
				break;
			}
			default:{
				printf("Wrong command!\n");
			}
		}
	}
}