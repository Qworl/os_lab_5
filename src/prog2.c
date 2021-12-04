#include <stdio.h>
#include <dlfcn.h>

int main(){
	int version = 0;
	int command;
	float (*Derivative)(float, float) = NULL;
	int (*PrimeCount)(int, int) = NULL;
	void *lib1_handler = dlopen("./lib1.so",RTLD_LAZY);
	if (!lib1_handler){
	    fprintf(stderr,"dlopen() error: %s\n", dlerror());
	    return -1;
	}
	void *lib2_handler = dlopen("./lib2.so",RTLD_LAZY);
	if (!lib2_handler){
	    fprintf(stderr,"dlopen() error: %s\n", dlerror());
	    return -1;
	}
	Derivative = dlsym(lib1_handler,"Derivative");
	PrimeCount = dlsym(lib1_handler,"PrimeCount");
	printf("0 - to switch realizations\n");
	printf("1 + float A + float deltaX - derivative of cos in dot A with deltaX as delta\n");
	printf("2 + int A + int B - number of prime numbers in [a,b]\n");
	while(scanf("%d", &command) != EOF){
		switch(command){
			case 0:{
				version ^= 1;
				if(!version){
					Derivative = dlsym(lib1_handler,"Derivative");
					PrimeCount = dlsym(lib1_handler,"PrimeCount");
				} else{
					Derivative = dlsym(lib2_handler,"Derivative");
					PrimeCount = dlsym(lib2_handler,"PrimeCount");
				}
				printf("Switched to realization %d\n", version + 1);
				break;
			}
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
	dlclose(lib1_handler);
	dlclose(lib2_handler);
}