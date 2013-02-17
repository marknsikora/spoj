import java.util.Scanner;

class SAMER08F {
    public static void main(String[] args) {
        int n, m;
        Scanner sc = new Scanner(System.in);
        
        while ((n = sc.nextInt()) != 0) {
            System.out.println(n*(n+1)*(2*n+1)/6);
        }
    }
}
