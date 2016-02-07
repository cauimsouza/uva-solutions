#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, cont = 0;
    int A[1010][1010];
    while(scanf("%d%d", &n, &m) != EOF){
        if(cont++) putchar('\n');
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                scanf("%d", &A[i][j]);
                if(i > 0) A[i][j] += A[i-1][j];
                if(j > 0) A[i][j] += A[i][j-1];
                if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
            }

        long long totalSum = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                int a = i + m - 1, b = j + m - 1;
                if(a >= n || b >= n) break;
                long long sum = A[a][b];
                if(i > 0) sum -= A[i-1][b];
                if(j > 0) sum -= A[a][j-1];
                if(i > 0 && j > 0) sum += A[i-1][j-1];
                totalSum += sum;
                printf("%lld\n", sum);
            }

        printf("%lld\n", totalSum);
    }
}
