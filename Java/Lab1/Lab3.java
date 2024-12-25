public class Lab3 {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No input provided.");
        } else {
            System.out.println("Arguments provided:");
			int switcher = Integer.parseInt(args[1]);
            for (int i = 0; i < switcher; i++) {
                if (isValidInteger(args[i])) {
                    System.out.println("Argument " + i + ": " + args[i]);
                } else {
                    System.out.println("Argument " + i + " is not a valid integer.");
                }
            }
        }
    }

    public static boolean isValidInteger(String str) {
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c < '0' || c > '9') {
                return false;
            }
        }
        return true;
    }
}
