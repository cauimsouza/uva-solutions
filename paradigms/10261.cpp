#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
const int inf = -(1e9);

int carLength[1005];
int prox[1000], best[1000];
map<pair<int,pair<int,int> >, int> mapa;
int n, higher;

int solve(int id, int remL, int remR){
    if(remL < 0 || remR < 0){
        if(id - 1 > higher){
            higher = id - 1;
            for(int i = 0; i < higher; i++)
                best[i] = prox[i];
        }
        return inf;
    }
    if(id == n){
        if(id > higher){
            higher = id;
            for(int i = 0; i < higher; i++)
                best[i] = prox[i];
        }
        return 0;
    }

    pair<int,pair<int,int> > iii = make_pair(id, make_pair(remL, remR));
    if(mapa.find(iii) != mapa.end())
        return mapa[iii];
    int &a = mapa[iii];
    a = 0;
    prox[id] = 0;
    a = max(a, 1 + solve(id + 1, remL - carLength[id], remR));
    prox[id] = 1;
    a = max(a, 1 + solve(id + 1, remL, remR - carLength[id]));
    return a;
}

int main(){
    int tc, k = 0;
    scanf("%d", &tc);
    while(tc--){
        mapa.clear();
        if(k++)
            printf("\n");

        int l;
        scanf("%d", &l);

        int x;
        n = 0;
        scanf("%d", &x);
        while(x){
            carLength[n++] = x;
            scanf("%d", &x);
        }

        higher = 0;

        printf("%d\n", solve(0, l*100, l*100));
        for(int i = 0; i < higher; i++)
            if(best[i] == 1)
                printf("starboard\n");
            else
                printf("port\n");
    }
}
