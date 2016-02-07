#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    int A[200][200];
    scanf("%d", &tc);
    while(tc--){
        int n;
        scanf("%d", &n);
        for(int i =0; i < n; i++)
            for(int j = 0; j < n; j++){
                scanf("%d", &A[i][j]);
                if(i > 0) A[i][j] += A[i-1][j];
                if(j > 0) A[i][j] += A[i][j-1];
                if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
            }
        for(int i = 0; i < n; i++)
            for(int j = n; j < 2 * n; j++){
                A[i][j] = A[i][j-n] + A[i][n-1];
            }
        for(int i = n; i < 2 * n; i++)
            for(int j = 0; j < n; j++)
                A[i][j] = A[i-n][j] + A[n-1][j];
        for(int i = n; i < 2*n; i++)
            for(int j = n; j < 2*n; j++){
                A[i][j] = A[n-1][j] + A[i][n-1] + A[i-n][j-n] - A[n-1][n-1];
            }

        int maior = -1e9;
        for(int i = 0; i < 2*n; i++)
            for(int j = 0; j < 2*n; j++)
                for(int a = i; a < 2*n && a < i + n; a++)
                    for(int b = j; b < 2*n && b < j +n; b++){
                        int soma = A[a][b];
                        if(i > 0) soma -= A[i-1][b];
                        if(j > 0) soma -= A[a][j-1];
                        if(i > 0 && j > 0) soma += A[i-1][j-1];
                        if(soma > maior) maior = soma;
                    }

        printf("%d\n", maior);
    }
}
