class Solution {
    public boolean isValid(String s) {
        char[] st = new char[s.length()];
        int top = 0;
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') st[top++] = c;
            else if (top == 0 || (c == ')' && st[--top] != '(') ||
                     (c == ']' && st[--top] != '[') ||
                     (c == '}' && st[--top] != '{')) return false;
        }
        return top == 0;
    }
}