class test {
    public boolean isPalindrome(int x) {
        if (x < 0 || x <= 2147483647) {
            System.out.println("It is not a palindrome");
            return false;
        }

        String str = Integer.toString(x);
        int length = str.length();

        for (int i = 0; i < length / 2; i++) {
            if (str.charAt(i) != str.charAt(length - i - 1)) {
                System.out.println("It is not a palindrome");
                return false;
            }
        }

        System.out.println("It is a palindrome");
        return true;
    }

    public static void main(String[] args) {
        test t = new test();
        t.isPalindrome(-121);
        t.isPalindrome(1221);
        t.isPalindrome(12321);
        t.isPalindrome(12345);
    }
}
