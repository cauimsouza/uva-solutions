#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

vector<vector<string> > cell;
vector<vector<int> > value;
vector<vector<bool> > defined;
int rows, columns;

int val(int i, int j){
    if(isdigit(cell[i][j][0]) || cell[i][j][0] == '-'){
        defined[i][j] = 1;
        return value[i][j] = stoi(cell[i][j]);
    }
    if(defined[i][j]){
        return value[i][j];
    }
    value[i][j] = 0;
    int k = 1;
    int len = (int)cell[i][j].size();
    while(k < len){
        int idr = 0, idc = 0;
        while(k < len && isalpha(cell[i][j][k])){
            idc *= 26;
            idc += cell[i][j][k] - 'A' + 1;
            k++;
        }
        idr = cell[i][j][k] - '0';
        k++;
        while(k < len && isdigit(cell[i][j][k])){
            idr *= 10;
            idr += cell[i][j][k] - '0';
            k++;
        }
        
        value[i][j] += val(idr-1,idc-1);
        k++; 
    }
    defined[i][j] = 1;
    return value[i][j];
}

int main(){
    int tc;
    scanf("%d", &tc);
     while(tc--){
        scanf("%d %d", &columns, &rows);
        defined.assign(rows, vector<bool> (columns, 0));
        cell.assign(rows, vector<string> (columns));
        value.assign(rows, vector<int> (columns));

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < columns; j++)
                cin >> cell[i][j];
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(j)
                    printf(" ");
                printf("%d", val(i,j));
            }
            printf("\n");
        }
     }
}