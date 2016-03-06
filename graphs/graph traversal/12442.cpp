#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef pair<int,int> ii;
typedef vector<int> vi;

int n;
int ciclo, temp;
vi aresta;
vi dist;
vi dfs_num;

int dfs(int u){
    dfs_num[u] = ++temp;
    dist[u] = -1;
    int v = aresta[u];
    if(dfs_num[v] == 0){
        int x = dfs(v);
        if(x < 0){// ciclo
            dist[u] = dist[v];
            if(u == ciclo)
                return dist[u];
            else
                return -1;
        }
        return dist[u] = dist[v] + 1;
    }
    else if(dist[v] < 0){ 
        ciclo = v;
        dist[u] = dfs_num[u] - dfs_num[v] + 1;
        return -1;
    }
    else
        return dist[u] = 1 + dist[v];
}

int main(){
    int t, k = 1;
    cin >> t;
    while(t--){
        cin >> n;
        aresta.resize(n);
        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            aresta[a - 1] = b - 1;
        }

        dist.assign(n, 0);
        dfs_num.assign(n, 0);
        temp = 0;
        for(int i = 0; i < n; i++){
            if(dfs_num[i] == 0)
                dfs(i);
        }
        int id = 0, maior = -1;
        for(int i = 0; i < n; i++)
            if(dist[i] > maior){
                maior = dist[i];
                id = i;
            }
        printf("Case %d: %d\n", k++, id + 1);
    }
}