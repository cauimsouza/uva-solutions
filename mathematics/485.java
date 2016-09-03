import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		BigInteger [] pascal = new BigInteger[1010];
		for(int i = 1; i < 1010; i++)
			pascal[i] = BigInteger.ZERO;
		pascal[0] = BigInteger.ONE;

		boolean end = false;
		int row = 0;
		while(true){
			if(end)
				break;
			for(int i = row; i > 0; i--){
				pascal[i] = pascal[i].add(pascal[i-1]);
				if(pascal[i].toString().length() >= 61)
					end = true;
			}
			System.out.print("1");
			for(int i = 1; i <= row; i++)
				System.out.print(" " + pascal[i]);
			System.out.println();
			row++;
		}
	}
}		