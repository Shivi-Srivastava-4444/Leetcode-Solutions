class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            int cnt[26] = {};
            for (char c : s) cnt[c - 'a']++;

            string key;
            for (int x : cnt) {
                key += to_string(x) + '#';
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& [key, group] : mp)
            ans.push_back(move(group));

        return ans;
    }
};