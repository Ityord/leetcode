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
        long long runningSum = 0;
        runningSum = stones[0];
        for (int i = 1; i < n; i++){
            runningSum += stones[i];
        }
        int ans = runningSum;
        for (int i = n-2; i >= 1; i--){
           runningSum -= stones[i+1];
           ans = max((long long)ans, runningSum - ans);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna