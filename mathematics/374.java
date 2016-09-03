import java.util.Scanner;
import java.math.BigInteger;

class Main{

	static BigInteger [] fat_vet = new BigInteger[1010];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(sc.hasNext()){
			int b, p, m;
			b = sc.nextInt();
			p = sc.nextInt();
			m = sc.nextInt();
			System.out.println(BigInteger.valueOf(b).modPow(BigInteger.valueOf(p), BigInteger.valueOf(m)));
		}		
	}
}		