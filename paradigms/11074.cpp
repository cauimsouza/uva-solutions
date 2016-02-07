#include <bits/stdc++.h>
using namespace std;

int main(){
    int linhas, colunas;
    int A[110][110];
    while(scanf("%d%d", &linhas, &colunas), linhas){
        for(int i = 0; i < linhas; i++)
            for(int j = 0; j < colunas; j++){
                scanf("%d", &A[i][j]);
                if(i > 0) A[i][j] += A[i-1][j];
                if(j > 0) A[i][j] += A[i][j-1];
                if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
            }

        int ans = 0;
        for(int i = 0; i < linhas; i++)
            for(int j = 0; j < colunas; j++)
                for(int a = i; a < linhas; a++)
                    for(int b = j; b < colunas; b++){
                        int sum = A[a][b];
                        if(i > 0) sum -= A[i-1][b];
                        if(j > 0) sum -= A[a][j-1];
                        if(i > 0 && j > 0) sum += A[i-1][j-1];
                        if(sum == 0 && (a-i+1)*(b-j+1) > ans) ans = (a-i+1)*(b-j+1);
                    }

        printf("%d\n", ans);
    }
}
