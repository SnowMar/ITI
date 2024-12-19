public class Lab2 {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No input provided.");
        } else {
            System.out.println("Arguments provided:");
            for (int i = 0; i < args.length; i++) {
                System.out.println("Argument " + i + ": " + args[i]);
            }
        }
    }
}