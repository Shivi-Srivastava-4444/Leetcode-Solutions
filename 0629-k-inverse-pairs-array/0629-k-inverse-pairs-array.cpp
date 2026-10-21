class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> dp(k + 1), ndp(k + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j <= k; j++) {
                sum = (sum + dp[j]) % MOD;
                if (j >= i) sum = (sum - dp[j - i] + MOD) % MOD;
                ndp[j] = sum;
            }
            dp.swap(ndp);
        }

        return dp[k];
    }
};