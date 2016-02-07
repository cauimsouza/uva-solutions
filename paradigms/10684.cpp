#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n), n){
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            sum += x;
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        } 

        if(sum > 0)
            printf("The maximum winning streak is %d.\n", ans);
        else
            printf("Losing streak.\n");
    } 
}
