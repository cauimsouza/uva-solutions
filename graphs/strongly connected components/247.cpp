#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vector<string> nameList;
vi S;
vi visited;
vi dfs_low;
vi dfs_num;
int dfsCounter;

void tarjanSCC(int u){
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    visited[u] = 1;
    S.push_back(u);
    for(int i = 0; i < (int)AdjList[u].size(); i++){
        int v = AdjList[u][i];

        if(dfs_num[v] == 0)
            tarjanSCC(v);

        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_num[u] == dfs_low[u]){
        int nameid = S.back();
        S.pop_back();
        visited[nameid] = 0;
        cout << nameList[nameid];
        while(nameid != u){
            nameid = S.back();
            S.pop_back();
            visited[nameid] = 0;
            printf(", %s", nameList[nameid].c_str());
        }
        printf("\n");
    }
}

int main(){
    int v, e;
    int k = 1;
    while(scanf("%d %d", &v, &e), (v || e)){
        AdjList.assign(v, vi());
        visited.assign(v, 0);
        dfs_num.assign(v, 0);
        dfs_low.assign(v, 0);
        nameList.clear();

        while(e--){
            string name1, name2;
            cin >> name1 >> name2;
            int v1, v2;
            for(v1 = 0; v1 < (int)nameList.size(); v1++)
                if(nameList[v1] == name1)
                    break;
            if(v1 == (int)nameList.size())
                nameList.push_back(name1);


            for(v2 = 0; v2 < (int)nameList.size(); v2++)
                if(nameList[v2] == name2)
                    break;
            if(v2 == (int)nameList.size())
                nameList.push_back(name2);

            AdjList[v1].push_back(v2);
        }

        if(k > 1)
            printf("\n");
        printf("Calling circles for data set %d:\n", k++);
        dfsCounter = 0;
        for(int i = 0; i < v; i++)
            if(dfs_num[i] == 0)
                tarjanSCC(i);
    }
}