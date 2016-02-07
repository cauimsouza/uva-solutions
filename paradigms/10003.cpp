#include <bits/stdc++.h>
using namespace std;

int memo[110][110];
int n, l;
int A[55];

int cut(int left, int right){
    if(left + 1 == right) return 0;
    if(memo[left][right] != -1) return memo[left][right];
    int a = 1e9;
    for(int i = left + 1; i < right; i++)
        a = min(a , cut(left, i) + cut(i, right));
    a += A[right] - A[left];
    return memo[left][right] = a;
}


int main(){
    while(scanf("%d", &l), l){
        scanf("%d", &n);
        A[0] = 0;
        A[n + 1] = l;
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
        memset(memo, -1, sizeof memo);
        printf("The minimum cutting is %d.\n", cut(0, n + 1));
    }
}
