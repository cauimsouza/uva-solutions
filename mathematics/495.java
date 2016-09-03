import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		BigInteger [] fib = new BigInteger[5010];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;
		for(int i = 2; i <= 5000; i++)
			fib[i] = fib[i-1].add(fib[i-2]);

		while(sc.hasNext()){
			int n = sc.nextInt();

			System.out.println("The Fibonacci number for " + n + " is " + fib[n]);
		}
	}
}		