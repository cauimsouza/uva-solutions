import java.util.*;

class Main{

    static Scanner sc;
    static{
        sc = new Scanner(System.in);
    }
    public static void main(String[] args) {
        int testes;

        testes = sc.nextInt();
        while(testes-- > 0){
            task();
        }
    }

    static void task(){
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();

        UnionFind UF = new UnionFind(n);
        while(m-- > 0){
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            UF.unionSet(--a, --b);
        }

        System.out.println(UF.largest());
    }
}


class UnionFind{
    int [] p;
    int [] rank;
    int [] sz;
    int n;
    int numSets;

    public UnionFind(int n){
        p = new int[n];
        rank = new int[n];
        sz = new int[n];
        this.n = n;
        for(int i = 0; i < n; i++)
            p[i] = i;
        
        for(int i = 0; i < n; i++){
            sz[i] = 1;
            rank[i] = 0;
        }
    }
    int find(int i){
        if(i == p[i])
            return i;
        return p[i] = find(p[i]);
    }
    public boolean isSameSet(int i, int j){
        return find(i) == find(j);
    }
    public void unionSet(int i, int j){
        int x = find(i), y = find(j);
        if(x == y)
            return;
        numSets--;
        if(rank[x] > rank[y]){
            sz[x] += sz[y];
            p[y] = x;
            return;
        }
        else if(rank[x] == rank[y])
            rank[y]++;
        sz[y] += sz[x];
        p[x] = y;
    }
    public int numOfSets(){
        return numSets;
    }
    public int largest(){
        int maior = 0;
        for(int i = 0; i < n; i++)
            if(sz[i] > maior)
                maior = sz[i];
        return maior;
    }
}