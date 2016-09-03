import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(true){
			int n = sc.nextInt();
			int k = sc.nextInt();
			if(n == 0) break;
			if(k == 0 || k == n) System.out.println("1");
			else{
				BigInteger ans = BigInteger.valueOf(n);
				if(k < n - k) k = n - k;
				for(int i = n - 1; i > k; i--) ans = ans.multiply(BigInteger.valueOf(i));
				for(int i = 2; i <= n - k; i++) ans = ans.divide(BigInteger.valueOf(i));
				System.out.println(ans);
			}
		}
	}
}		