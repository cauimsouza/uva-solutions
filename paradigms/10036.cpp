#include <bits/stdc++.h>
using namespace std;

int n, k;
int num[10010];
int memo[110][10010];

int divisible(int mod, int id){
    if(id == n) return mod == 0;
    while(mod < 0) mod += k;
    int &a = memo[mod][id];
    if(a != -1) return a;
    return a = divisible((mod+num[id])%k, id + 1) || divisible((mod-num[id])%k, id + 1);
}

int main(){
    int m;
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", &num[i]);

        memset(memo, -1, sizeof memo);
        if(divisible(num[0]%k, 1))
            printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
}
