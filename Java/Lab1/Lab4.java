import java.util.Random;

public class Lab4 {
    public static void main(String[] args) {
        int[] arr = new int[1000];
        Random random = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = random.nextInt(1000);
        }

        long startTime = System.nanoTime();

        int max = arr[0];
        int min = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        long duration = System.nanoTime() - startTime;

        System.out.println("Maximum number in the array: " + max);
        System.out.println("Minimum number in the array: " + min);
        System.out.println("Time taken to find the maximum and minimum: " + duration + "ms");
    }
}
