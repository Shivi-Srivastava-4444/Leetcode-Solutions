class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return new ArrayList<>();
        
        String[] map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        List<String> ans = new ArrayList<>();
        backtrack(digits, 0, new StringBuilder(), ans, map);
        return ans;
    }

    void backtrack(String d, int i, StringBuilder s, List<String> ans, String[] map) {
        if (i == d.length()) {
            ans.add(s.toString());
            return;
        }
        for (char c : map[d.charAt(i) - '0'].toCharArray()) {
            s.append(c);
            backtrack(d, i + 1, s, ans, map);
            s.deleteCharAt(s.length() - 1);
        }
    }
}