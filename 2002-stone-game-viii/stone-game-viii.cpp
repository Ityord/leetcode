class Solution {
public:
    int solve (int i, vector<int>& prefix, vector<int>& dp){
        if (i == prefix.size()-1){
            return prefix[i];
        }
        if (dp[i] != -1) return dp[i];
        int take = prefix[i] - solve(i+1, prefix, dp);
        int skip = solve(i+1, prefix, dp);
        return dp[i] = max(take, skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum(n,0);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }
        vector<int> dp(n,-1);
        dp[n-1] = prefixSum[n-1];
        for (int i = n-2; i >= 1; i--){
            int take = prefixSum[i] - dp[i+1];
            int skip = dp[i+1];
            dp[i] = max(skip,take);
        }
        return dp[1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna