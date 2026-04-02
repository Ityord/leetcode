class Solution {
public:
    int dp[501][501][3];
    int m, n;
    int solve(vector<vector<int>>& coins, int i, int j, int neu){
        if (i >= m || j >= n) return INT_MIN;
        if (i == m-1 && j == n-1){
            if (coins[i][j] < 0 && neu > 0){
                return 0;
            }
            return coins[i][j];
        }
        if (dp[i][j][neu] != INT_MIN) return dp[i][j][neu];
        int take = coins[i][j] + max(solve(coins, i,j+1,neu), solve(coins,i+1,j,neu));
        int skip = INT_MIN;
        if (coins[i][j] < 0 && neu > 0){
            skip = max(solve(coins, i,j+1,neu-1), solve(coins,i+1,j,neu-1));
        }
        return dp[i][j][neu] = max(skip, take);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        for (int i = 0; i < 501; i++){
            for (int j = 0; j < 501; j++) {
                for (int k = 0; k < 3; k++){
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins,0,0,2);
    }
};