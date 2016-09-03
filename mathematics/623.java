import java.util.Scanner;
import java.math.BigInteger;

class Main{

	static BigInteger [] fat_vet = new BigInteger[1010];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n;
		while(sc.hasNext()){
			n = sc.nextInt();
			System.out.println(n + "!");
			System.out.println(fat(n));
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