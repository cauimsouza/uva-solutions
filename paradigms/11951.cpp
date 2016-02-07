#include <bits/stdc++.h>
using namespace std;

int main(){
    int TC, cont = 1;
    scanf("%d", &TC);
    long long A[110][110];
    while(TC--){
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                scanf("%lld", &A[i][j]);
                if(i > 0) A[i][j] += A[i-1][j];
                if(j > 0) A[i][j] += A[i][j-1];
                if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
            }

        int maxArea = 0, minCost = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int a = i; a < n; a++)
                    for(int b = j; b < m; b++){
                        long long sum = A[a][b];
                        if(i > 0) sum -= A[i-1][b];
                        if(j > 0) sum -= A[a][j-1];
                        if(i > 0 && j > 0) sum += A[i-1][j-1];
                        if(sum <= k){
                            if((a-i+1)*(b-j+1) > maxArea){
                                maxArea = (a-i+1)*(b-j+1);
                                minCost = sum;
                            }
                            else if((a-i+1)*(b-j+1) == maxArea && sum < minCost)
                                minCost = sum;
                        } 
                    }

        printf("Case #%d: %d %d\n", cont++, maxArea, minCost);
    }
}
