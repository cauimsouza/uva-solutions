import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(sc.hasNext()){
			int n = sc.nextInt();
			int k = sc.nextInt();
			
			BigInteger ans = fat(n);
			for(int i = 0; i < k; i++){
				int x = sc.nextInt();
				ans = ans.divide(fat(x));
			}
			System.out.println(ans);
		}
	}
	public static BigInteger fat(int k){
		if(k == 0)
			return BigInteger.ONE;
		BigInteger ans = BigInteger.valueOf(k);
		for(int i = k - 1; i > 1; i--)
			ans = ans.multiply(BigInteger.valueOf(i));
		return ans;
	}
}		