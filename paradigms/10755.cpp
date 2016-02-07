#include <bits/stdc++.h>
using namespace std;

int main(){
    int TC;
    long long A[25][25][25];
    scanf("%d", &TC);
    while(TC--){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
                for(int k = 0; k < z; k++){
                    scanf("%lld", &A[i][j][k]);
                    if(i > 0) A[i][j][k] += A[i-1][j][k];
                    if(j > 0) A[i][j][k] += A[i][j-1][k];
                    if(k > 0) A[i][j][k] += A[i][j][k-1];
                    if(i > 0 && j > 0) A[i][j][k] -= A[i-1][j-1][k];
                    if(i > 0 && k > 0) A[i][j][k] -= A[i-1][j][k-1];
                    if(j > 0 && k > 0) A[i][j][k] -= A[i][j-1][k-1];
                    if(i > 0 && j > 0 && k > 0) A[i][j][k] += A[i-1][j-1][k-1]; 
                }

        long long ans = A[0][0][0];
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
                for(int k = 0; k < z; k++)
                    for(int a = i; a < x; a++)
                        for(int b = j; b < y; b++)
                            for(int c = k; c < z; c++){
                                long long subCub = A[a][b][c];
                                if(i > 0) subCub -= A[i-1][b][c];
                                if(j > 0) subCub -= A[a][j-1][c];
                                if(k > 0) subCub -= A[a][b][k-1];
                                if(i > 0 && j > 0) subCub += A[i-1][j-1][c];
                                if(i > 0 && k > 0) subCub += A[i-1][b][k-1];
                                if(j > 0 && k > 0) subCub += A[a][j-1][k-1];
                                if(i > 0 && j > 0 && k > 0) subCub -= A[i-1][j-1][k-1];
                                ans = max(ans, subCub);
                            }

        printf("%lld\n", ans);
        if(TC) printf("\n");
    }

}
