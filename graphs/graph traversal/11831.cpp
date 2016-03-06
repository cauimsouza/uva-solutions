#include <bits/stdc++.h>
using namespace std;

int main(){
    char mapa[110][110];
    int n, m, s;
    while(scanf("%d %d %d", &n, &m, &s), n){
        for(int i = 0; i < n; i++)
            scanf("%s", mapa[i]);

        int posx, posy;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mapa[i][j] != '.' && mapa[i][j] != '#' && mapa[i][j] != '*'){
                    posx = j;
                    posy = i;
                }

        int cont = 0;
        char ori = mapa[posy][posx];
        while(s--){
            char c;
            scanf(" %c", &c);
            if(c == 'F'){
                if(ori == 'N'){
                    if(posy > 0 && mapa[posy-1][posx] != '#')
                        posy--;
                }
                else if(ori == 'L'){
                    if(posx < m - 1 && mapa[posy][posx + 1] != '#')
                        posx++;
                }
                else if(ori == 'O'){
                    if(posx > 0 && mapa[posy][posx-1] != '#')
                        posx--;
                }
                else{
                    if(posy < n - 1 && mapa[posy+1][posx] != '#')
                        posy++;
                }
            }
            else if(c == 'E'){
                if(ori == 'N')
                    ori = 'O';
                else if(ori == 'L')
                    ori = 'N';
                else if(ori == 'O')
                    ori = 'S';
                else
                    ori = 'L';
            }
            else{
                if(ori == 'N')
                    ori = 'L';
                else if(ori == 'L')
                    ori = 'S';
                else if(ori == 'O')
                    ori = 'N';
                else
                    ori = 'O';
            }
            if(mapa[posy][posx] == '*'){
                cont++;
                mapa[posy][posx] = '.';
            }
        }

        printf("%d\n", cont);
    }
}