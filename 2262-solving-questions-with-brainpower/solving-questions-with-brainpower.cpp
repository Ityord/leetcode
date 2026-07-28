class Solution {
public:
    long long solve(int s, int n, vector<vector<int>>& questions, vector<long long>& dp){
        if (s >= n) return 0;
        if (dp[s] != -1) return dp[s];
        int points = questions[s][0];
        int bp = questions[s][1];
        long long take = points + solve(s+bp+1,n,questions,dp);
        long long skip = solve(s+1, n, questions,dp);
        return dp[s] = max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return solve(0,n,questions,dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna