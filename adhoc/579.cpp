#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int h, m;
	double angh, angm, resp;
	while(scanf("%d:%d", &h, &m), h || m){
		angm = 6 * m;
		angh = h*30;
		if(m)
			angh += 30 * (m/60.0);
		resp = min(abs(angh - angm), 360.0 - abs(angh - angm));
		printf("%.3f\n", resp);
	}

	return 0;
}
