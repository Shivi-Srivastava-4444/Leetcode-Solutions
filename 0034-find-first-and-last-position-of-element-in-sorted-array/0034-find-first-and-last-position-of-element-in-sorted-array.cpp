
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (first == nums.size() || nums[first] != target)
            return {-1, -1};

        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        return {first, last};
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna