#include <bits/stdc++.h>
using namespace std;

int main(){
    int TC;
    scanf("%d\n\n", &TC);
    int A[110][110];
    while(TC--){
        int n, b;
        scanf("%d%d", &n, &b);
        memset(A, 0, sizeof A);

        while(b--){
            int r1, c1, r2, c2;
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            for(int i = r1-1; i < r2; i++)
                for(int j = c1-1; j < c2; j++)
                    A[i][j] = 1;
        }

        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(i > 0) A[i][j] += A[i-1][j];
                if(j > 0) A[i][j] += A[i][j-1];
                if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
            }

        int result = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int a = i; a < n; a++)
                    for(int b = j; b < n; b++){
                        int sum = A[a][b];
                        if(i > 0) sum -= A[i-1][b];
                        if(j > 0) sum -= A[a][j-1];
                        if(i > 0 && j > 0) sum += A[i-1][j-1];
                        if(sum == 0 && (a-i+1)*(b-j+1) > result) result = (a-i+1)*(b-j+1); 
                    }

        printf("%d\n", result);
    }
}
