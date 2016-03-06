#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;
map<string, int> idx;
vector<string> name;
vector<vi> AdjList;
vi incoming;

int main(){
    int k = 1;
    while(scanf("%d", &n) != EOF){
        idx.clear();
        name.resize(n);
        incoming.assign(n, 0);
        AdjList.assign(n, vi());

        for(int i = 0; i < n; i++){
            string beverage;
            cin >> beverage;
            idx[beverage] = i;
            name[i] = beverage; 
        }

        int m;
        scanf("%d", &m);
        while(m--){
            string less, more;
            cin >> less >> more;
            int u = idx[less], v = idx[more];
            AdjList[u].push_back(v);
            incoming[v]++;
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", k++);

        priority_queue<int> pq;
        for(int i = 0; i < n; i++)
            if(incoming[i] == 0)
                pq.push(-i);
        while(!pq.empty()){
            int v = -pq.top();
            pq.pop();

            printf(" %s", name[v].c_str());
            for(int i = 0; i < (int)AdjList[v].size(); i++){
                int u = AdjList[v][i];
                incoming[u]--;
                if(incoming[u] == 0)
                    pq.push(-u);
            }
        }
        printf(".\n\n");
    }
}