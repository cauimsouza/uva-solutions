import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		BigInteger [] fib = new BigInteger[1010];
		fib[0] = BigInteger.valueOf(1);
		fib[1] = BigInteger.valueOf(2);
		for(int i = 2; i <= 1000; i++){
			fib[i] = fib[i-1];
			fib[i] = fib[i].add(fib[i-2]);
		}
		
		while(sc.hasNext()){
			int n = sc.nextInt();
			System.out.println(fib[n]);
		}
	}
}


