package go;

public class ExceptionThrower {
    public void methodOne(int number) throws MyCustomException {
        if (number < 0) {
            throw new MyCustomException("Negative number exception: " + number);
        }
        System.out.println("MethodOne executed successfully.");
    }

    public void methodTwo(int fileSize) throws MyCustomException {
        int maxSize = 500;
        if (fileSize > maxSize) {
            throw new MyCustomException("File size exceeds limit! Maximum allowed is " + maxSize + "MB.");
        }
        System.out.println("File size is within the allowed limit: " + fileSize + "MB.");
    }

    public void methodThree(String input) throws MyCustomException {
        if (input == null || input.isEmpty()) {
            throw new MyCustomException("Invalid input: String is null or empty.");
        }
        System.out.println("Input is valid: " + input);
    }
}
