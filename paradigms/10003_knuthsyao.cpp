#include <bits/stdc++.h>
using namespace std;

int memo[110][110];
int n, l;
int A[55];
int P[55][55]; // P[a][b] keeps the c such that cut(a, b) is minimum.
               // this way we can use Knuth's optimization and reduce O(n^3) to O(n^2)
               // This works due to "Quadrangle Inequality":
               // w(i, j) + w(i', j') <= w(i,j') + w(i',j), for all i <= i' <= j <= j'
               // and due to monotonicity:
               // w(i',j) <= w(i,j'), for all i <= i' <= j <= j'  

int cut(int left, int right){
    if(left + 1 == right) return 0;
    if(memo[left][right] != -1) return memo[left][right];
    int a = 1e9;

    int L = left + 1; // Knuth's trick
    int R = right - 1;
    if(P[left][right-1] != -1) L = P[left][right-1];
    if(P[left+1][right] != -1) R = P[left+1][right];
    
    for(int i = L; i <= R; i++){
        if(a > cut(left, i) + cut(i, right)){
            a = cut(left, i) + cut(i, right);
            P[left][right] = i;
        }
    }

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
        memset(P, -1, sizeof P);
        printf("The minimum cutting is %d.\n", cut(0, n + 1));
    }
}
