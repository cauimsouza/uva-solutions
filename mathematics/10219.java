import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(sc.hasNext()){
			int n = sc.nextInt();
			int k = sc.nextInt();

			if(k < n - k)
				k = n - k;

			BigInteger ans = BigInteger.valueOf(n);
			for(int i = n - 1; i > k; i--){
				ans = ans.multiply(BigInteger.valueOf(i));
			}
			for(int i = 2; i <= n - k; i++)
				ans = ans.divide(BigInteger.valueOf(i));

			System.out.println(ans.toString().length());
		}
	}
}		