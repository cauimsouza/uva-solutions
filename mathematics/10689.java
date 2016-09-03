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

		
		int num_cases = sc.nextInt();
		while(num_cases-- > 0){
			int a = sc.nextInt();
			int b = sc.nextInt();
			int n = sc.nextInt();
			int m = sc.nextInt();
			if(m == 1) n %= 60;
			else if (m == 2) n %= 300;
			else if(m == 3) n %= 1500;
			else n %= 15000;


			BigInteger value;
			if(n == 0)
				value = BigInteger.valueOf(a);
			else if (n == 1)
				value = BigInteger.valueOf(b);
			else if (n == 2)
				value = BigInteger.valueOf(a + b);
			else{
				BigInteger value1 = fib[n - 3].multiply(BigInteger.valueOf(a));
				BigInteger value2 =  fib[n - 2].multiply(BigInteger.valueOf(b));
				String val1s = value1.toString();
				String val2s = value2.toString();
				val1s = val1s.substring( Math.max(0, val1s.length() - m) );
				val2s = val2s.substring( Math.max(0, val2s.length() - m) );
				value = new BigInteger (val1s);
				value = value.add(new BigInteger (val2s));
			}
			String decRepres = value.toString();
			String answer =  decRepres.substring( Math.max(0, decRepres.length() - m) );
			int i = 0;
			while(i < answer.length() && answer.charAt(i) == '0')
				i++;
			if(i >= answer.length())
				System.out.println("0");
			else
				System.out.println(answer.substring(i));
		}
	}
}


