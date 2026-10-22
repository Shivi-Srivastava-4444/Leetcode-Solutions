class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int n = s.size(), w = words[0].size(), k = words.size();
        unordered_map<string, int> need;

        for (auto& word : words) need[word]++;

        for (int i = 0; i < w; i++) {
            unordered_map<string, int> seen;
            int left = i, count = 0;

            for (int right = i; right + w <= n; right += w) {
                string word = s.substr(right, w);

                if (!need.count(word)) {
                    seen.clear();
                    count = 0;
                    left = right + w;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > need[word]) {
                    seen[s.substr(left, w)]--;
                    left += w;
                    count--;
                }

                if (count == k) {
                    ans.push_back(left);
                    seen[s.substr(left, w)]--;
                    left += w;
                    count--;
                }
            }
        }

        return ans;
    }
};