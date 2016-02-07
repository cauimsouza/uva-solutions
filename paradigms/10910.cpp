#include <bits/stdc++.h>
using namespace std;

int memo[80][80][80];

int cont(int subj, int marks, int minimum){
    if(subj == 1){
        return 1;
    }

    int &a = memo[subj][marks][minimum];
    if(a != -1)
        return a;
    a = 0;
    for(int i = minimum * (subj - 1); i <= marks - minimum; i++){
        a += cont(subj - 1, i, minimum);
    }
    return a;
}

int main(){
   memset(memo, -1, sizeof memo);
   int cases;
   scanf("%d", &cases);

   while(cases--){
        int n, t, p;
        scanf("%d %d %d", &n, &t, &p);
        printf("%d\n", cont(n, t, p));
   }
}