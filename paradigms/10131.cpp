#include <bits/stdc++.h>
using namespace std;

struct elefante{
    int peso,
        qi,
        id;
    bool operator < (const elefante& B){
        if(peso != B.peso) return peso < B.peso;
        return false;
    }
};

int main(){
    int cont = 0;
    vector<elefante> A;

    int w, q;
    while(scanf("%d %d", &w, &q) != EOF){
        elefante aux;
        aux.peso = w;
        aux.qi = q;
        aux.id = cont++;
        A.push_back(aux);
    }
    sort(A.begin(), A.end());

    int idx, maior = 0;
    vector<int> LIS(cont);
    vector<int> pai(cont);
    for(int i = 0; i < cont; i++){
        LIS[i] = 1;
        pai[i] = -1;
        for(int j = 0; j < i; j++){
            if(A[j].peso != A[i].peso && A[j].qi > A[i].qi && LIS[j] >= LIS[i]){
                LIS[i] = LIS[j] + 1;
                pai[i] = j;
            }
        }
        if(LIS[i] > maior){
            maior = LIS[i];
            idx = i;
        }
    }

    printf("%d\n", maior);
    stack<int> pilha;
    while(idx >= 0){
        pilha.push(A[idx].id);
        idx = pai[idx];
    }
    while(!pilha.empty()){
        printf("%d\n", pilha.top()+1);
        pilha.pop();
    }
}
