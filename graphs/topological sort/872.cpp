#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20 + 5;

char letra[MAXN];
bool AdjMatrix[MAXN][MAXN];
int n;
int ts[MAXN], k;
bool no;

void backtracking(int last, int mask){
    for(int i = 0; i < n; i++){
        if(i != last && (mask & (1 << i)) && AdjMatrix[last][i])
            return;
    }
    if(mask == (1 << n) - 1){
        printf("%c", letra[ts[0]]);
        for(int i = 1; i < n; i++)
            printf(" %c", letra[ts[i]]);
        printf("\n");
        no = false;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(!(mask & (1 << i))){
            ts[k++] = i;
            backtracking(i, mask | (1 << i));
            k--;
        }
    }
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        memset(AdjMatrix, false, sizeof AdjMatrix);

        char a, b;
        int id = 0;
        do{
            scanf(" %c", &a);
            letra[id++] = a;
        }while((a = getchar()) != '\n');
        n = id;

        do{
            scanf(" %c<%c", &a, &b);
            int id1, id2;
            for(id1 = 0; id1 < n; id1++)
                if(letra[id1] == a)
                    break;
            for(id2 = 0; id2 < n; id2++)
                if(letra[id2] == b)
                    break;
            AdjMatrix[id1][id2] = true;
            a = getchar();
        }while(a != '\n' && a != EOF);

        no = true;
        for(int i = 0; i < n; i++){
            k = 1;
            ts[0] = i;
            backtracking(i, 1 << i);
        }
        if(no)
            printf("NO\n");
        if(tc)
            printf("\n");
    }
}