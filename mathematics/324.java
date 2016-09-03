import java.util.Scanner;
import java.math.BigInteger;

class Main{

	static BigInteger [] fat_vet = new BigInteger[1010];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(true){
			int n = sc.nextInt();
			if(n == 0)
				break;
			System.out.println(n + "! --");

			String str_fat = fat(n).toString();
			int [] dig_freq = new int[10];
			for(int i = 0; i < str_fat.length(); i++)
				dig_freq[str_fat.charAt(i) - '0']++;
			System.out.printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n", dig_freq[0], dig_freq[1], dig_freq[2],dig_freq[3],dig_freq[4]);			
			System.out.printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n", dig_freq[5], dig_freq[6], dig_freq[7],dig_freq[8],dig_freq[9]);
		}
	}

	public static BigInteger fat(int n){
		if(n < 2)
			return BigInteger.ONE;
		if(fat_vet[n] != null)
			return fat_vet[n];
		BigInteger ans = BigInteger.valueOf(n);
		while(--n > 0){
			ans = ans.multiply(BigInteger.valueOf(n));
		}
		return fat_vet[n] = ans;
	}
}		