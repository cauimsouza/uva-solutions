#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        vector<string> wordList;       
        while(1){
            string word;
            cin >> word;
            if(word == "*")
                break;
            wordList.push_back(word);
        }

        vector<vi> AdjList(wordList.size());

        for(int i = 0; i < sz(wordList); i++){
            for(int j = i + 1; j < sz(wordList); j++){
                if(wordList[i].length() != wordList[j].length())
                    continue;
                int dif = 0;
                for(int k = 0; k < wordList[i].length(); k++)
                    if(wordList[i][k] != wordList[j][k])
                        dif++;
                if(dif > 1)
                    continue;
                AdjList[i].push_back(j);
                AdjList[j].push_back(i);
            }
        }

        getchar();
        while(1){
            string line;
            getline(cin, line);
            if(line.length() == 0)
                break;

            istringstream is(line);
            string origem, destino;
            is >> origem >> destino;
            int id_ini = find(all(wordList), origem) - wordList.begin(),
                id_fim = find(all(wordList), destino) - wordList.begin();

            queue<int> q;
            vi dist(sz(wordList), INF);
            dist[id_ini] = 0;
            q.push(id_ini);
            bool found = false;
            while(!q.empty() && !found){
                int u = q.front();
                q.pop();
                for(int i = 0; i < sz(AdjList[u]); i++){
                    int v = AdjList[u][i];
                    if(dist[v] == INF){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        if(v == id_fim){
                            found = true;
                            break;
                        }
                    }
                }
            }

            printf("%s %s %d\n", origem.c_str(), destino.c_str(), dist[id_fim]);
        }

        if(TC)
            printf("\n");
    }
}