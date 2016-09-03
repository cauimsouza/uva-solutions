import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int num_cases = sc.nextInt();
		for(int case_no = 1; case_no <= num_cases; case_no++){
			String word = sc.next();

			int [] freq = new int[30];
			for(int i = 0; i < word.length(); i++)
				freq[word.charAt(i) - 'A']++;
			BigInteger ans = fat(word.length());
			for(int i = 0; i < 30; i++)
				ans = ans.divide(fat(freq[i]));

			System.out.println("Data set " + case_no + ": " + ans);
		}
	}

	public static BigInteger fat(int n){
		if(n < 2)
			return BigInteger.ONE;
		BigInteger ans = BigInteger.valueOf(n);
		while(--n > 0){
			ans = ans.multiply(BigInteger.valueOf(n));
		}
		return ans;
	}
}		