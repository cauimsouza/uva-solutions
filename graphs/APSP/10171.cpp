#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;
const int MAXN = 26 + 5;

int main(){
    int AdjMatYoung[MAXN][MAXN], AdjMatOld[MAXN][MAXN];
    int id[MAXN];
    int n;
    while(1){
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < MAXN; i++){
            for(int j = 0 ; j < MAXN; j++)
                AdjMatOld[i][j] = AdjMatYoung[i][j] = INF;
            AdjMatYoung[i][i] = AdjMatOld[i][i] = 0;
        }

        for(int i = 0; i < MAXN; i++)
            id[i] = -1;
        int v = 0;
        while(n--){
            char a, b, c, d;
            int w, id1, id2;
            scanf(" %c %c %c %c %d", &a, &b, &c, &d, &w);
            if(id[c - 'A'] < 0)
                id[c - 'A'] = id1 = v++;
            else
                id1 = id[c - 'A'];
            if(id[d - 'A'] < 0)
                id[d - 'A'] = id2 = v++;
            else
                id2 = id[d - 'A'];

            if(a == 'M'){
                AdjMatOld[id1][id2] = min(w, AdjMatOld[id1][id2]);
                if(b == 'B')
                    AdjMatOld[id2][id1] = min(w, AdjMatOld[id2][id1]);
            }
            else{
                AdjMatYoung[id1][id2] = min(w, AdjMatYoung[id1][id2]);
                if(b == 'B')
                    AdjMatYoung[id2][id1] = min(w, AdjMatYoung[id2][id1]);
            }
        }

        for(int k = 0; k < v; k++)
            for(int i = 0; i < v; i++)
                for(int j = 0; j < v; j++){
                    AdjMatOld[i][j] = min(AdjMatOld[i][j], AdjMatOld[i][k] + AdjMatOld[k][j]);
                    AdjMatYoung[i][j] = min(AdjMatYoung[i][j], AdjMatYoung[i][k] + AdjMatYoung[k][j]);
                }

        char origem, dest;
        scanf(" %c %c", &origem, &dest);
        int id1 = id[origem - 'A'], id2 = id[dest - 'A'];
        int ans = INF;
        vi sol;
        if(id1 >= 0 && id2 >= 0)
            for(int i = 0; i < v; i++)
                if(ans > AdjMatYoung[id1][i] + AdjMatOld[id2][i]){
                    ans = AdjMatYoung[id1][i] + AdjMatOld[id2][i];
                    sol.assign(1, i);
                }
                else if(ans == AdjMatYoung[id1][i] + AdjMatOld[id2][i]){
                    sol.push_back(i);
                }
        if(origem == dest)
            ans = 0;
        if(ans < INF){
            printf("%d ", ans);
            if(origem == dest && sz(sol) == 0)
                printf("%c\n", origem);
            else{
                vector<char> print;
                for(int j = 0; j < sz(sol); j++)
                    for(int i = 0; i < MAXN; i++)
                        if(id[i] == sol[j])
                            print.push_back(i + 'A');
                sort(print.begin(), print.end());
                printf("%c", print[0]);
                for(int i = 1; i < sz(print); i++)
                    printf(" %c", print[i]);
                printf("\n");
            }
        }
        else
            printf("You will never meet.\n");
    }
}
