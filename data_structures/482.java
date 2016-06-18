import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        MyScanner sc = new MyScanner();

        int casos = sc.nextInt();
        sc.nextLine();
        while(casos-- > 0){
            String sequencia = sc.nextLine();
            Vector<Integer> vet = new Vector<Integer>();
            Scanner s = new Scanner(sequencia);
            while(s.hasNextInt()){
                vet.add(s.nextInt());
            }
            sequencia = sc.nextLine();
            Vector<String> num = new Vector<String>();
            s = new Scanner(sequencia);
            while(s.hasNext()){
                num.add(s.next());
            }

            for(int k = 0; k < num.size(); k++){
                for(int i = 0; i < num.size(); i++){
                    if(vet.get(i) == k + 1)
                        System.out.println(num.get(i));
                }
            }

            if(casos > 0){
                System.out.println();
                sc.nextLine();
            }
        }
    }
      
   //-----------MyScanner class for faster input----------
   public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
      try {
         str = br.readLine();
      } catch (IOException e) {
         e.printStackTrace();
      }
      return str;
      }

   }
   //--------------------------------------------------------
}