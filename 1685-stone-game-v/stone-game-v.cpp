class Solution {
public:
    int t[501][501];
    int solve(int l, int r, vector<int>& prefixSum){
        if (l >= r) return 0;
        if (t[l][r] != -1) return t[l][r];
        int score = 0;
        for (int mid = l; mid <= r-1; mid++){
            int leftSum = prefixSum[mid] - (l-1>=0 ? prefixSum[l-1] : 0);
            int rightSum = prefixSum[r] - prefixSum[mid];
            if (leftSum < rightSum){
                score = max(score, leftSum + solve(l, mid, prefixSum));
            } else if (rightSum < leftSum){
                score = max(score, rightSum + solve(mid+1, r, prefixSum));
            }else {
                score = max({score, leftSum + solve(l, mid, prefixSum), rightSum + solve(mid+1, r, prefixSum)});
            }
        }
        return t[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(t,-1,sizeof(t));
        vector<int> prefixSum(n,0);
        prefixSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1]+stoneValue[i];
        }
        return solve(0, n-1, prefixSum);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna