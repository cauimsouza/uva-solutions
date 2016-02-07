#include <bits/stdc++.h>
using namespace std;

const double inf = 1e9;
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

int n, k;
int x[10], y[10];
vector<int> sequence[10];
vector<int> ve;
double dist[10];

void tsp(int last, double sum){
    if(n == (int) ve.size()){
        if(sum < dist[k]){
            dist[k] = sum;
            sequence[k] = ve;
        }
        return;
    }
    for(int i = 0; i < n; i++){
        if(find(all(ve), i) != ve.end()) continue;
        ve.push_back(i);
        tsp(i, sum + hypot(x[i] - x[last], y[i] - y[last]));
        ve.pop_back(); 
    }
}

int main(){
    int cont = 1;
    while(scanf("%d", &n), n){
        printf("**********************************************************\n");
        printf("Network #%d\n", cont++);
        for(int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);

        for(k = 0; k < n; k++){
            dist[k] = inf;
            ve.assign(1, k);
            tsp(k, 0);
        }

        int id;
        double low = inf;
        for(int i = 0; i < n; i++){
            if(dist[i] < low){
                low = dist[i];
                id = i;
            }
        }

        for(int i = 0; i < n - 1; i++){
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
                x[sequence[id][i]], y[sequence[id][i]], x[sequence[id][i+1]], y[sequence[id][i+1]],
                16 + hypot(x[sequence[id][i]] - x[sequence[id][i+1]], y[sequence[id][i]] - y[sequence[id][i+1]]));
        }
        printf("Number of feet of cable required is %.2f.\n", low + 16 * (n-1));
    }
}
