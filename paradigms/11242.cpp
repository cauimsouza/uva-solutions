#include <bits/stdc++.h>
using namespace std;

int main()
{
	int front, rear;
	while(scanf("%d", &front), front){
		scanf("%d", &rear);
		int *frontCluster = new int[front+10];
		int *rearCluster = new int[rear+10];
		double *ratio = new double[front*rear+10];

		for (int i = 0; i < front; ++i)
		{
			scanf("%d", &frontCluster[i]);
		}
		for (int i = 0; i < rear; ++i)
		{
			scanf("%d", &rearCluster[i]);
		}

		int count = 0;
		for (int i = 0; i < rear; ++i)
		{
			for (int j = 0; j < front; ++j)
			{
				ratio[count++] = (1.0 * rearCluster[i]) / frontCluster[j];
			}
		}
		sort(ratio, ratio + count);
		double maxQuot = 0;
		for(int i = 1; i < count; i++){
			if(ratio[i]/ratio[i-1] > maxQuot) maxQuot = ratio[i]/ratio[i-1];
		}

		printf("%.2f\n", maxQuot);

		delete[]frontCluster;
		delete[]rearCluster;
	}

	return 0;
}