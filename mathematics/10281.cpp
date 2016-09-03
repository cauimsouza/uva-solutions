#include <stdio.h>


int main(){
    int h0, m0, s0, h, m, s;
    h0 = m0 = s0 = 0;
    double dist = 0;
    int vel = 0;
    while(scanf("%d:%d:%d", &h, &m, &s) != EOF){
        char c;
        scanf("%c", &c);
        dist += ((h - h0) * 3600 + (m - m0) * 60 + (s - s0)) * vel / 3.6;
        if(c == ' ')// mudar vel.
            scanf("%d", &vel);
        else{// consulta
            printf("%02d:%02d:%02d %.2f km\n", h, m, s, dist / 1000);
        }
        h0 = h;
        m0 = m;
        s0 = s;
    } 

}
