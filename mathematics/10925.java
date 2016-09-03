import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int items, friends;
		int case_no = 1;
		while(true){
			items = sc.nextInt();
			friends = sc.nextInt();
			if(items == 0 && friends == 0) break;

			BigInteger sum = BigInteger.ZERO;
			for(int i = 0; i < items; i++){
				BigInteger V = sc.nextBigInteger();
				sum = sum.add(V);
			}

			System.out.println("Bill #" + case_no++ + " costs " + sum
				+": each friend should pay " + sum.divide(BigInteger.valueOf(friends)) + "\n");
		}
	}
}


