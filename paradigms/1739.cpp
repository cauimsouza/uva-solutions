#include <bits/stdc++.h>
using namespace std;

const int MAXV = 5010;
const int inf = 1e9;
int type[6] = {5,10,20,50,100,200};
int quant[6];
int memo[100][10][MAXV];
int memo2[MAXV];

int solve(int qnt, int id, int value){
    if(value == 0) return 0;
    if(id >= 6 || value < 0) return inf;
    int &a = memo[qnt][id][value];
    if(a != -1) return a;
    if(qnt >= quant[id]) return a = solve(0, id + 1, value);
    return a = min(1 + solve(qnt + 1, id, value - type[id]), solve(0, id + 1, value));
}

int solve2(int value){
    if(value == 0) return 0;
    if(value < 0) return inf;
    int &a = memo2[value];
    if(a != -1) return a;
    a = inf;
    for(int i = 0; i < 6; i++) a = min(a, 1 + solve2(value - type[i]));
    return a;
}

int main(){
    memset(memo2, -1, sizeof memo2);
    while(true){
        int sum = 0;
        for(int i = 0; i < 6; i++){
            scanf("%d", &quant[i]);
            sum += quant[i] * type[i];
        }
        if(!sum) break;

        memset(memo, -1, sizeof memo);
        int a, b;
        scanf("%d.%d", &a, &b);
        int money = 100 * a + b;
        int result = inf, i = money;
        while(i <= sum){
            result = min(result, solve(0, 0, i) + solve2(i - money));
            i += 5;
        }

        printf("%3d\n", result);
    }
}
