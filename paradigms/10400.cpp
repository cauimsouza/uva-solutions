#include <bits/stdc++.h>
using namespace std;

const int LIM = 32000;

typedef pair<int,int> ii;

int n, target;
int num[105];
char sequence[105];
set<ii> dp;

bool can(int val, int id){
    if(id == n)
        return val == target;

    ii par = ii(val, id);
    if(dp.find(par) != dp.end())
        return 0;
    dp.insert(par);

    if(val + num[id] < LIM){
        sequence[id] = '+';
        if(can(val + num[id], id + 1))
            return 1;
    }
    if(val - num[id] > -LIM){
        sequence[id] = '-';
        if(can(val - num[id], id + 1))
            return 1;
    }
    if(abs(val * num[id]) < LIM){
        sequence[id] = '*';
        if(can(val * num[id], id + 1))
            return 1;
    }
    if(val%num[id] == 0){
        sequence[id] = '/';
        if(can(val / num[id], id + 1))
            return 1;
    }
    return 0;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        scanf("%d", &target);
        dp.clear();
        if(can(num[0], 1)){
            printf("%d", num[0]);
            for(int i = 1; i < n; i++)
                printf("%c%d", sequence[i], num[i]);
            printf("=%d\n", target);
        }
        else
            printf("NO EXPRESSION\n");
    }
}