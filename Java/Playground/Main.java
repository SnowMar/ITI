import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int i = 0, sd = 0, avg = 0, n = 0, a = 0, b = 0;
        int x[] = new int[n];
        Scanner sc = new Scanner(System.in);
        System.err.println("Enter N Value: \n");
        n = sc.nextInt();
        
        for(i = 0; i < n; i++) {
            System.err.println("Enter the value of x[" + i + "]: \n");
            x[i] = sc.nextInt();
            avg += x[i];
        } 
        avg = avg / n;
        System.err.println("Average: " + avg + "\n");
        sc.close();
    }
}
