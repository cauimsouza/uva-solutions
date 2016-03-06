#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

bool dfs_num[MAXN];
int ts[MAXN], id;
vector<vector<int> > AdjList;

void dfs(int u){
    dfs_num[u] = true;
    for(int i = 0; i < (int)AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(dfs_num[v] == false)
            dfs(v);
    }
    ts[id--] = u;
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m), n){
        AdjList.assign(n, vector<int> ());
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            AdjList[a-1].push_back(b-1);
        }
        memset(dfs_num, false, sizeof dfs_num);
        id = n - 1;
        for(int i = 0; i < n; i++)
            if(dfs_num[i] == false)
                dfs(i);
        printf("%d", ts[0] + 1);
        for(int i = 1; i < n; i++)
            printf(" %d", ts[i] + 1);
        printf("\n");
    }
}