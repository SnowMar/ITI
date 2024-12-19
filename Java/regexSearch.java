import java.util.regex.*;

public class regexSearch {
    public static void main(String[] args) {
        String str = "ITI is where ITI And ITI is the best";
        String regex = "ITI";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(str);
        
        int count = 0;

        while (matcher.find()) {
            count++;
        }
        
        if (count > 0) {
            System.out.println("Found using Pattern and Matcher");
            System.out.println("Occurrences of 'ITI': " + count);
        } else {
            System.out.println("No matches found.");
        }
    }
}
