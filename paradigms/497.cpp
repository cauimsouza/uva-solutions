#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    scanf("%d\n\n", &tc);
    while(tc--){
        string line;
        vector<int> A;

        getline(cin, line);
        int x;
        stringstream(line) >> x;
        A.push_back(x);
        getline(cin, line);
        while(line.length()){
            stringstream(line) >> x;
            A.push_back(x);
            getline(cin, line);
        }

        vector<int> lis(A.size());
        vector<int> pai(A.size());
        int resp = 0, idx = 0;
        for(int i = 0; i < (int)A.size(); i++){
            lis[i] = 1;
            pai[i] = -1;
            for(int j = 0 ; j < i; j++){
                if(A[j] < A[i] && lis[j] + 1 > lis[i]){
                    lis[i] = lis[j] + 1;
                    pai[i] = j;
                }
            }
            if(resp < lis[i]){
                idx = i;
                resp = lis[i];
            }
        }

        printf("Max hits: %d\n", resp);
        stack<int> p;
        while(idx >= 0){
            p.push(A[idx]);
            idx = pai[idx];
        }
        while(!p.empty()){
            printf("%d\n", p.top());
            p.pop();
        }
        if(tc) printf("\n");
    }
}
