import java.util.Scanner;
import java.math.BigInteger;

class Main{
	static int [] ans;
	static{
		ans = new int[15];
		for(int i = 0; i < 15; i++)
			ans[i] = -1;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		boolean first = true;
		while(sc.hasNext()){
			int n = sc.nextInt();

			if(!first)
				System.out.println();
			System.out.println(solve(n));
			first = false;
		}
	}

	public static int solve(int n){
		if(n <= 1) return 1;
		if(ans[n] != -1)
			return ans[n];
		int ways = 0;
		for(int i = 0; i < n; i++)
			ways += solve(i) * solve(n - i - 1);
		return ans[n] = ways;
	}
}		