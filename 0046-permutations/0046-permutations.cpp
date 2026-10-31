class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        auto dfs = [&](auto&& self, int start) -> void {
            if (start == nums.size()) {
                ans.push_back(nums);
                return;
            }

            for (int i = start; i < nums.size(); i++) {
                swap(nums[start], nums[i]);
                self(self, start + 1);
                swap(nums[start], nums[i]);
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};