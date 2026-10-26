class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(128, 0);
        for (char c : t) cnt[c]++;

        int left = 0, need = t.size(), start = 0, len = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (cnt[s[right]]-- > 0) need--;

            while (need == 0) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    start = left;
                }

                if (++cnt[s[left++]] > 0) need++;
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};