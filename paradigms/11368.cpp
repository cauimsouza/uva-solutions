#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

bool ordena(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int n;
        scanf("%d", &n);
        vector<pair<int,int> > vii;
        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            vii.push_back(make_pair(a,b));
        }
        sort(vii.begin(), vii.end(), ordena);
        vector<int> vi(n);
        for(int i = 0; i < n; i++)
            vi[i] = vii[i].second;
        int L[n], lis = 0;
        for(int i = 0; i < n; i++){
            int pos = upper_bound(L, L + lis, vi[i]) - L;
            L[pos] = vi[i];
            lis = max(lis, pos + 1);
        }
        printf("%d\n", lis);
    }
}