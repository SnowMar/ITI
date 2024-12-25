import java.util.*;

public class Solution {
    public static void main(String argv[]) {
        TreeMap<String, List<String>> map = new TreeMap<>();

        String[] fruits = {
            "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", 
            "imbe", "jackfruit", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", 
            "quince", "raspberry", "strawberry", "tangerine", "ugli", "vanilla", "watermelon", 
            "ximenia", "yuzu", "zuchinni", "another", "butter", "candy", "dandy", "elephant"
        };

        for (String fruit : fruits) {
            String key = String.valueOf(fruit.charAt(0));
            map.putIfAbsent(key, new ArrayList<>());
            map.get(key).add(fruit);
        }

        displayAll(map);

        System.out.println("\nEntries starting with 'a':");
        displayOneOnly(map, 'a');
    }

    public static void displayAll(TreeMap<String, List<String>> map) {
        for (Map.Entry<String, List<String>> entry : map.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }

    public static void displayOneOnly(TreeMap<String, List<String>> map, char c) {
        String key = String.valueOf(c);
        if (map.containsKey(key)) {
            System.out.println(key + ": " + map.get(key));
        } else {
            System.out.println("No entries found for letter: " + c);
        }
    }
}
