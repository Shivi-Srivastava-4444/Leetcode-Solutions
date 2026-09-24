class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] last = new int[128];
        int left = 0, max = 0;
        for (int right = 0; right < s.length(); right++) {
            left = Math.max(left, last[s.charAt(right)]);
            max = Math.max(max, right - left + 1);
            last[s.charAt(right)] = right + 1;
        }
        return max;
    }
}