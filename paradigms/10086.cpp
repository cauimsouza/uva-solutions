#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int T1, T2, n;
int C1[35][25], C2[35][25];
int samples[35];
int memo[35][305][305], bestChoice[35][305][305];

int solve(int site, int t1, int t2){
    if(t1 < 0 || t2 < 0)
        return inf;
    if(site == n)
        return 0;
    int &a = memo[site][t1][t2];
    if(a != -1)
        return a;
    a = inf;
    for(int i = 0; i <= samples[site]; i++){
        int aux = C1[site][i] + C2[site][samples[site] - i] + solve(site + 1, t1 - i, t2 + i - samples[site]);
        if(a > aux){
            a = aux;
            bestChoice[site][t1][t2] = i;
        }
    }
    return a;
}

int main(){
     while(scanf("%d %d", &T1, &T2), (T1 || T2)){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &samples[i]);
            C1[i][0] = C2[i][0] = 0;
            for(int j = 1; j <= samples[i]; j++){
                scanf("%d", &C1[i][j]);
            }
            for(int j = 1; j <= samples[i]; j++){
                scanf("%d", &C2[i][j]);
            }
        }

        memset(memo, -1, sizeof memo);
        printf("%d\n", solve(0, T1, T2));
        int j = bestChoice[0][T1][T2], t1 = T1, t2 = T2;
        printf("%d", j);
        for(int i = 1; i < n; i++){
            t1 = t1 - j;
            t2 = t2 + j - samples[i-1];
            j = bestChoice[i][t1][t2];
            printf(" %d", j);
        }
        printf("\n\n");
     }
}