/**
 * Because this problem has no input. Generate the output in a separate file and submit it! This is O(1)
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define POT 1000000
int main()
{
	for(ll a = 0; a <= 2000; a++){

		for(ll b = a; b <= 2000; b++){

			if(a + b >= 2000) break;

			for(ll c = b; c <= 2000; c++){
				if(a + b + c >= 2000) break;

				ll den =  a*b*c - POT;

				if(den <= 0 || (POT*(a+b+c))%den) continue;

				ll d = (POT*(a+b+c))/den;

				if(d >= c && a+b+c+d <= 2000) printf("printf(\"%.2lf %.2lf %.2lf %.2lf\\n\");\n", a/100.0, b/100.0, c/100.0, d/100.0);
			}
		}
	}	

	return 0;
}