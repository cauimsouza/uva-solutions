#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int main(){
    int k = 1;
    int l, u, r;
    bool reached[10000];
    int num[15];
    while(scanf("%d %d %d", &l, &u, &r), (l || u || r)){
        memset(reached, 0, sizeof reached);
        reached[l] = 1;
        for(int i = 0; i < r; i++)
            scanf("%d", &num[i]);

        printf("Case %d: ", k++);
        bool found = false;
        queue<ii> q;
        q.push(ii(l, 0));
        while(!found && !q.empty()){
            ii front = q.front();
            q.pop();
            int number = front.first, dist = front.second;
            for(int i = 0; i < r; i++){
                int new_number = (number + num[i]) % 10000, new_dist = dist + 1;
                if(reached[new_number])
                    continue;
                if(new_number == u){
                    found = true;
                    printf("%d\n", new_dist);
                    break;
                }
                reached[new_number] = 1;
                q.push(ii(new_number, new_dist));
            }
        }

        if(!found)
            printf("Permanently Locked\n");
    } 
}