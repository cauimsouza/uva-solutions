#include <cstdio>
using namespace std;

int main() {
    int testes;
    scanf("%d", &testes);
    for (int i = 0; i < testes; ++i)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: ", i + 1);
        for (int j = 0; j < n; ++j)
        {
            if(j == (n - 1) / 2){
                int x;
                scanf("%d", &x);
                printf("%d\n", x);
            }
            else
                scanf("%*s");
        }
    }
}
