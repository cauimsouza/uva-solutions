#include <bits/stdc++.h>
using namespace std;

bitset<1200> bs;
vector<int> primes;

void generate(){
    bs.set();
    for(int i = 2; i < 1200; i++){
        if(bs[i]){
            for(int j = i * i; j < 1200; j += i) bs[j] = 0;
            primes.push_back(i);
        }
    }
}

int n, k;
int memo[1200][1200][20]; // memo[sum][starting at prime idx][remaining primes]

int solve(int sum, int idx, int qnt){
    if(sum == 0) return qnt ? 0 : 1; 
    if(qnt == 0 || idx >= (int)primes.size()) return 0; // we cannot sum any other prime
    int &a = memo[sum][idx][qnt];
    if(a != -1) return a;
    if(sum < primes[idx]) return a = 0;
    return a = solve(sum, idx + 1, qnt) + solve(sum - primes[idx], idx + 1, qnt - 1);
}

int main(){
    generate();
    memset(memo, -1, sizeof memo);
    while(scanf("%d %d", &n, &k), n){
        printf("%d\n", solve(n, 0, k));
    }
}
