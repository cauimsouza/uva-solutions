import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		BigInteger [] fib = new BigInteger[1010];
		fib[0] = BigInteger.valueOf(1);
		fib[1] = BigInteger.valueOf(2);
		for(int i = 2; i <= 1000; i++){
			fib[i] = fib[i-1];
			fib[i] = fib[i].add(fib[i-2]);
		}

		boolean first = true;
		while(sc.hasNext()){
			if(!first)
				System.out.println();
			first = false;
			String a = sc.next();
			String b = sc.next();

			BigInteger num1 = BigInteger.ZERO;
			for(int i = 0; i < a.length(); i++ ){
				if(a.charAt(i) == '1')
					num1 = num1.add(fib[a.length() - i - 1]);
			}
			BigInteger num2 = BigInteger.ZERO;
			for(int i = 0; i < b.length(); i++ ){
				if(b.charAt(i) == '1')
					num2 = num2.add(fib[b.length() - i - 1]);
			}

			BigInteger soma = num1.add(num2);

			if(soma.compareTo(BigInteger.ZERO) == 0)
				System.out.println("0");
			else{

			int i = 0;
			while(soma.compareTo(fib[i]) >= 0) i++;

			i--;
			while(i >= 0){
				if(soma.compareTo(fib[i]) >= 0){
					System.out.print('1');
					soma = soma.subtract(fib[i]);
				}
				else
					System.out.print('0');
				i--;
			}

			System.out.println();
			}
		}
	}
}


