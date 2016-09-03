import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int num_cases = sc.nextInt();
		while(num_cases-- > 0){
			int n = sc.nextInt();
			int k = sc.nextInt();
			int sum = 0;
			for(int i = 0; i < k; i++){
				int x = sc.nextInt();
				sum += x;
			}

			BigInteger ans = Coef(n - sum - 1, k - 1);
			ans = ans.multiply(BigInteger.valueOf(2));
			ans = ans.add(Coef(n - sum - 1, k - 2));
			ans = ans.add(Coef(n - sum - 1, k));

			System.out.println(ans);
		}
	}

	public static BigInteger Coef(int n, int k){
		if(k < 0 || k > n)
			return BigInteger.ZERO;
		BigInteger ans = BigInteger.valueOf(n);
		if(k > n - k)
			k = n - k;
		for(int i = n - 1; i > k; i--)
			ans = ans.multiply(BigInteger.valueOf(i));
		for(int i = 2; i <= n - k; i++)
			ans = ans.divide(BigInteger.valueOf(i));
		return ans;
	}
}		