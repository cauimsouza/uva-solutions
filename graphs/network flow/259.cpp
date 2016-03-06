#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
using vi =  vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

const int MAXN = 40;

int res[MAXN][MAXN];
int mf, f, s, t;
vi p;

void augment(int v, int minEdge){
    if(v == s){
        f = minEdge;
        return;
    }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main(){
    s = 0;
    t = 37;
    while(1){
        memset(res, 0, sizeof res);
        for(int i = 27; i < t; i++)
            res[i][t] = 1;

        char c;
        int numTasks = 0;
        while(isalpha(c = getchar())){
            int app = c - 'A' + 1, num;
            
            scanf("%d%c", &num, &c);
            numTasks += num;
            res[0][app] = num;

            while((c = getchar()) != ';')
                res[app][c - '0' + 27] = INF;

            c = getchar();
        }

        if(numTasks == 0)
            break;

        mf = 0;
        bitset<MAXN> bs;
        while(1){
            p.assign(MAXN, -1);
            bs.reset();
            bs.set(s);
            queue<int> q;
            q.push(0);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u == t)
                    break;
                for(int i = 0; i <= 37; i++)
                    if(!bs.test(i) && res[u][i] > 0)
                        bs.set(i), p[i] = u, q.push(i);
            }
            f = 0;
            augment(t, INF);
            if(f == 0)
                break;
            mf += f;
        }
        
        if(mf == numTasks){
            for(int i = 27; i < t; i++){
                bool match = false;
                for(int j = 1; j < 27; j++)
                    if(res[i][j] == 1){
                        match = true;
                        printf("%c", 'A' + j - 1);
                        break;
                    }
                if(!match)
                    printf("_");
            }
            printf("\n");
        }
        else
            printf("!\n");

        if(c == EOF)
            break;
    }
}