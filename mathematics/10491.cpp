#include <cstdio>

int main(){
	int ncows, ncars, nshows;
	while(scanf("%d %d %d", &ncows, &ncars, &nshows) != EOF){
		int doors = ncows + ncars;
		double prob = (double) ncars * (doors - 1) / (doors * (doors - 1 - nshows)); 
		printf("%.5f\n", prob);
	}

	return 0;
}