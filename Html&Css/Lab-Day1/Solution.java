import java.util.Arrays;
import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        String[] left = {"(", "{", "["};
        String[] right = {")", "}", "]"};
        if(s.length() % 2 != 0) return false;
        Stack<Character> stack = new Stack<>();
        for(int i =0; i < s.length(); i++){ {
            if(Arrays.asList(left).contains(String.valueOf(s.charAt(i))))
                stack.push(s.charAt(i));
            } 
            if (Arrays.asList(right).contains(String.valueOf(s.charAt(i)))) {
                if (stack.isEmpty()) return false;
                char top = stack.pop();
                if ((s.charAt(i) == ')' && top != '(') ||
                    (s.charAt(i) == '}' && top != '{') ||
                    (s.charAt(i) == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
 

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isValid("()"));
    }
}