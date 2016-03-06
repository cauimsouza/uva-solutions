#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;
const int MAXV = 200 + 5;

int main(){
    bool AdjMat[MAXV][MAXV];
    map<string, int> taskId;
    vector<string> taskName;
    int comp, caso = 1;

    while(scanf("%d", &comp), comp){
        taskId.clear();
        taskName.clear();
        int v = 0;
        for(int i = 0; i < MAXV; i++){
            for(int j = 0; j < MAXV; j++)
                AdjMat[i][j] = 0;
            AdjMat[i][i] = 1;
        }

        while(comp--){
            int n;
            scanf("%d", &n);
            if(n == 0)
                continue;
            string taskA, taskB;
            int idA, idB;
            cin >> taskA;
            if(taskId.find(taskA) == taskId.end()){
                taskId[taskA] = idA = v++;
                taskName.push_back(taskA);
            }
            else
                idA = taskId[taskA];
            n--;
            while(n--){
                cin >> taskB;
                if(taskId.find(taskB) == taskId.end()){
                    taskId[taskB] = idB = v++;
                    taskName.push_back(taskB);
                }
                else
                    idB = taskId[taskB];
                AdjMat[idA][idB] = 1;
                idA = idB;
            }
        }

        int msg;
        scanf("%d", &msg);
        while(msg--){
            string taskA, taskB;
            int idA, idB;
            cin >> taskA >> taskB;
            idA = taskId[taskA];
            idB = taskId[taskB];
            AdjMat[idA][idB] = 1;
        }

        for(int k = 0; k < v; k++)
            for(int i = 0; i < v; i++)
                for(int j = 0; j < v; j++)
                    AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);

        printf("Case %d, ", caso++);
        int ans = 0;
        for(int i = 0; i < v; i++)
            for(int j = i; j < v; j++)
                if(AdjMat[i][j] == 0 && AdjMat[j][i] == 0)
                    ans++;
        if(ans){
            printf("%d concurrent events:\n", ans);
            int k = 0;
            for(int i = 0; i < v && k < 2; i++)
                for(int j = i; j < v && k < 2; j++)
                    if(AdjMat[i][j] == 0 && AdjMat[j][i] == 0){
                        printf("(%s,%s) ", taskName[i].c_str(), taskName[j].c_str());
                        k++;
                    }
            printf("\n");
        }
        else
            printf("no concurrent events.\n");
    }
}
