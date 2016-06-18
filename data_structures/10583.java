import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args) throws IOException{

        Reader.init( System.in );

        int n, m;
        int cont = 1;

        while(true){
            n = Reader.nextInt();
            m = Reader.nextInt();
            if(n == 0)
                break;
            UnionFind UF = new UnionFind(n);
            while(m-- > 0){
                int a, b;
                a = Reader.nextInt();
                b = Reader.nextInt();
                UF.unionSet(a - 1, b - 1);
            }

            System.out.printf("Case %d: %d\n", cont, UF.numOfSets());
            cont++;
        }
    }

    static class UnionFind{
        int n, numSets;
        int[] p;
        int[] rank;

        public UnionFind(int n){
            this.n = n;
            this.numSets = n;
            this.p = new int[n];
            this.rank = new int[n];

            for(int i = 0; i < n; i++){
                p[i] = i;
                rank[i] = 0;
            }
        }
        private int findSet(int i){
            if(i == p[i])
                return i;
            return p[i] = findSet(p[i]);
        }
        public void unionSet(int i, int j){
            int x = findSet(i), y = findSet(j);
            if(x == y)
                return;
            numSets--;
            if(rank[x] > rank[y]){
                p[y] = x;
                return;
            }
            p[x] = y;
            if(rank[x] == rank[y])
                rank[y]++;
        }
        public int numOfSets(){
            return numSets;
        }
    }
}

/** Class for buffered reading int and double values */
class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}