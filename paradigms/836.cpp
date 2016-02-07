#include <bits/stdc++.h>
using namespace std;

int main(){
    int TC;
    scanf("%d\n\n", &TC);
    int A[30][30];
    while(TC--){
        scanf("\n"); // there is a blank line between two consecutive test cases

        int linhas, colunas;
        int i = -1, j;
        char c;
        while((c = getchar()) != '\n' && c != EOF){
            i++;
            j = 0;
            A[i][j] = (c == '1' ? 0 : 1);
            if(i > 0) A[i][j] += A[i-1][j];
            j++;
            while((c = getchar()) != '\n' && c != EOF){
                A[i][j] = (c == '1' ? 0 : 1);
                if(i > 0) A[i][j] += A[i-1][j];
                if(j > 0) A[i][j] += A[i][j-1];
                if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
                j++;
            }
            colunas = j;
            if(c == EOF) break;
        }
        linhas = i + 1;

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
        if(TC) printf("\n");
    }
}
