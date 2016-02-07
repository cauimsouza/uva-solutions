#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int b;
int x[15], y[15];
int memo[15][1300];

inline bool isSet(int mask, int i){
    return mask & (1 << i); 
}

int tsp(int last, int mask){
    if(mask == (1 << b) - 1) return abs(x[0] - x[last]) + abs(y[0] - y[last]);
    int &a = memo[last][mask];
    if(a != -1) return a;
    
    int mask2 = (1 << b) - 1; // set to 1 all b first digits of mask2 
    mask2 ^= mask; // now mask2 is mask "complement"
    mask2 |= 1; // set to 1 first digit

    a = inf;
    for(int i = 1; i < b; i++)
        if((isSet(mask2, i)) && memo[i][mask2] == -1) // here I use symmetry to avoid recalculation
        	a = min(a, abs(x[i] - x[last]) + abs(y[i] - y[last]) + tsp(i, mask | (1 << i)));
       
    return a;
}

int main(){
    int tc;
    scanf("%d", &tc);

    while(tc--){
        scanf("%*s %*s");
        scanf("%d %d", &x[0], &y[0]);
        scanf("%d", &b);
        b++;
        for(int i = 1; i < b; i++) scanf("%d %d", &x[i], &y[i]);
        
        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", tsp(0, 1));
    }
}
