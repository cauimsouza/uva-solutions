#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int teens, consts;
	while(scanf("%d%d", &teens, &consts), teens || consts){
		int *teenA = new int[consts+10];
		int *teenB = new int[consts+10];
		int *dist = new int[consts+10];
		int *position = new int[teens+10];

		for (int i = 0; i < consts; ++i)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			teenA[i] = a;
			teenB[i] = b;
			dist[i] = c;
		}

		
		for (int i = 0; i < teens; ++i)
		{
			position[i] = i;
		}

		int count = 0;
		do{
			count++;
			for (int i = 0; i < consts; ++i)
			{
				if(dist[i] > 0 && abs(position[teenA[i]] - position[teenB[i]]) > dist[i]){ count--; break;}
				if(dist[i] < 0 && abs(position[teenA[i]] - position[teenB[i]]) < -dist[i]){ count--; break;}
			}
		}while(next_permutation(position, position+teens));

		printf("%d\n", count);

		delete[]teenA;
		delete[]teenB;
		delete[]dist;
		delete[]position;
	}	

	return 0;
}
