public class Stringsearch {
    public static void main(String[] args) {
        int occurences = 0;
        String pattern = "ITI";
        String test = "ITI is where ITI And ITI is the best";

        for (int i = 0; i < test.length(); i++) {
            if (test.charAt(i) == 'I' && test.charAt(i + 1) == 'T' && test.charAt(i + 2) == 'I' && test.charAt(i + 3) == ' ') {
                occurences++;
            }
        }
        System.out.println(occurences);
       
    
       String[] parts = test.split(" ");
       int count = 0;
       
       for (String part : parts) {
           if (part.equals(pattern)) {
               count++;
           }
        }
        System.out.println(count);
    }
}

