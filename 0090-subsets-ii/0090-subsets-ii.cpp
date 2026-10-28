class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;

        auto dfs = [&](auto&& self, int start) -> void {
            ans.push_back(cur);

            for (int i = start; i < nums.size(); i++) {
                if (i > start && nums[i] == nums[i - 1]) continue;

                cur.push_back(nums[i]);
                self(self, i + 1);
                cur.pop_back();
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};