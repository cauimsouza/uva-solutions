import java.util.Scanner;

public class Main
{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        while(sc.hasNext()){
            int n = sc.nextInt();
            int k = (int)((-1 + Math.sqrt(1 + 8 * n)) / 2);
            while((k * (k + 1)) / 2 < n)
                k++;
            int N = (k * (k - 1)) / 2;
            if(k % 2 == 0){ // decrescente
                int num = n - N;
                int den = k + 1 - num;

                System.out.println("TERM " + n + " IS " + num + "/" + den);
            }
            else{
                int den = n - N;
                int num = k + 1 - den;

                System.out.println("TERM " + n + " IS " + num + "/" + den);
            }
        }
    }
}

