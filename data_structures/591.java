import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args) throws IOException{

        Reader.init( System.in );

        int n, cont = 1;
        while(true){
            n = Reader.nextInt();
            if(n == 0)
                break;
            Vector<Integer> vec = new Vector<Integer>();
            for(int i = 0; i < n; i++){
                vec.add(i, Reader.nextInt());
            }
            int avg = 0;
            for(int i = 0; i < n; i++){
                avg += vec.get(i);
            }
            avg /= n;
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(vec.get(i) > avg)
                    sum += vec.get(i) - avg;
            }

            System.out.printf("Set #%d\nThe minimum number of moves is %d.\n\n", cont++, sum);
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