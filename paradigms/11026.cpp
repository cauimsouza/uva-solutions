#include <bits/stdc++.h>
using namespace std;

int main(){
   long long fit[1010][1010]; // fit[last element to be considered][group size]
   long long n, m;
   vector<int> vi;
   while(scanf("%lld %lld", &n, &m), n){
        vi.resize(n+1);
        for(int i = 1; i <= n; i++){
            scanf("%d", &vi[i]);
            vi[i] %= m;
        }

        fit[1][1] = vi[1] % m; // base case
        for(int i = 2; i <= n; i++){
            fit[i][1] = (fit[i-1][1] + vi[i]) % m;
            for(int j = 2; j <= i; j++){
                fit[i][j] = (fit[i-1][j] + fit[i-1][j-1] * vi[i]) % m;
            }
        }
        long long maior = -1;
        for(int i = 1; i <= n; i++)
            maior = max(maior, fit[n][i]);

        cout << maior << endl; 
   }
}