class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        int mx = INT_MIN, l = 0, r = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }

        while (pq.size() == nums.size()) {
            auto [mn, i, j] = pq.top();
            pq.pop();

            if (mx - mn < r - l) {
                l = mn;
                r = mx;
            }

            if (j + 1 == nums[i].size()) break;

            int next = nums[i][j + 1];
            mx = max(mx, next);
            pq.push({next, i, j + 1});
        }

        return {l, r};
    }
};