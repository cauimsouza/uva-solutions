#include<iostream>
#include<cstdio>
using namespace std;
 
int main(){
 
    int casos_teste, num_pedras, i = 1, dist_esq, dist_dir, cont_pedras, dist, max_dist, par, dist_margem;
    char tipo;
 
    cin >> casos_teste;
 
    while(i <= casos_teste){
        cin >> num_pedras >> dist_margem;
        dist_esq = dist_dir = max_dist = par = 0;
        cont_pedras = 1;
 
        while(cont_pedras <= num_pedras){
            cont_pedras++;
 
            scanf(" %c-%d", &tipo, &dist);
 
            if(tipo == 'S'){
 
                if(par%2 == 0){
                    if(dist - dist_dir > max_dist) max_dist = dist - dist_dir;
                    par++;
                    dist_dir = dist;
                }
 
                else{
                    if(dist - dist_esq > max_dist) max_dist = dist - dist_esq;
                    par++;
                    dist_esq = dist;
                }
            }
 
            else{
                if(dist - dist_dir > max_dist) max_dist = dist - dist_dir;
                if(dist - dist_esq > max_dist) max_dist = dist - dist_esq;
                dist_esq = dist;
                dist_dir = dist;
                par = 0;
            }
        }
 
        dist = dist_margem;
        if(dist - dist_dir > max_dist) max_dist = dist - dist_dir;
        if(dist - dist_esq > max_dist) max_dist = dist - dist_esq;
 
        cout << "Case " << i << ": " << max_dist << endl;
        i++;
    }
 
    return 0;
}