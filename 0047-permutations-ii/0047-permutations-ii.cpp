class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size(), false);

        auto dfs = [&](auto&& self) -> void {
            if (cur.size() == nums.size()) {
                ans.push_back(cur);
                return;
            }

            for (int i = 0; i < nums.size(); i++) {
                if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
                    continue;

                used[i] = true;
                cur.push_back(nums[i]);

                self(self);

                cur.pop_back();
                used[i] = false;
            }
        };

        dfs(dfs);
        return ans;
    }
};