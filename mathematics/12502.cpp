#include <stdio.h>
#include <cmath>

int main(){
    int testes;
    scanf("%d", &testes);
    while(testes--){
    	int x, y, z;
    	scanf("%d %d %d", &x, &y, &z);
    	double media = (x + y) / 3.0;
    	double qnt1 = x - media;
    	double qnt2 = y - media;
    	
    	int res = (int)round((z * qnt1)/(qnt1 + qnt2));
  
   		printf("%d\n", res);
    	
    }

}
