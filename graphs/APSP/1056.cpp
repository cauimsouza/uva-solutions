#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;
const int MAXV = 50 + 5;

int main(){
    int v, e, k = 1;
    int AdjMat[MAXV][MAXV];
    map<string, int> name;
    while(scanf("%d %d", &v, &e), v){
        name.clear();
        
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++)
                AdjMat[i][j] = INF;
            AdjMat[i][i] = 0;
        }

        int cont = 0;
        while(e--){
            string personA, personB;
            cin >> personA >> personB;
            
            if(name.find(personA) == name.end())
                name[personA] = cont++;
            if(name.find(personB) == name.end())
                name[personB] = cont++;

            int id1, id2;
            id1 = name[personA];
            id2 = name[personB];
            AdjMat[id1][id2] = AdjMat[id2][id1] = 1;
        }

        for(int k = 0; k < v; k++)
            for(int i = 0; i < v; i++)
                for(int j = 0; j < v; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        int maxmini = 0;
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                maxmini = max(maxmini, AdjMat[i][j]);

        printf("Network %d: ", k++);
        if(maxmini == INF)
            printf("DISCONNECTED\n\n");
        else
            printf("%d\n\n", maxmini);
    }
}
