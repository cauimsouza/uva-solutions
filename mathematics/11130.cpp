#include <cstdio>
#include <cmath>
using namespace std;



int main(){
	int hor, vert, vel, angle, tempo;
	while(scanf("%d %d %d %d %d", &hor, &vert, &vel ,&angle, &tempo), hor || vert || vel || angle || tempo){
		double ac = (vel * 1.0) / tempo;
		double dist = (ac / 2.0) * tempo * tempo;
		double rad = angle * acos(-1) / 180.0;
		double hordist = dist * cos(rad);
		double verdist = dist * sin(rad);
		double horqnt = hordist / hor;
		double verqnt = verdist / vert;
		int resp1 = floor(horqnt);
		if(horqnt - resp1 >= 0.50) resp1++;
		int resp2 = floor(verqnt);
		if(verqnt - resp2 >= 0.50) resp2++;
		printf("%d %d\n", resp1, resp2);
	}
}