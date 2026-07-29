class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n);
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            prefixSum[i] = sum;
        }
        int i = 0;
        int j = firstLen + secondLen -1;
        int bestL = INT_MIN;
        int ans = INT_MIN;
        while (j < n){
            int ls = i;
            int le = ls + firstLen -1;
            int ms = le+1;
            int me = j;
            int lsum;
            if (ls == 0){
                lsum = prefixSum[le];
            } else {
                lsum = prefixSum[le] - prefixSum[ls-1];
            }
            bestL = max(bestL, lsum);
            int mSum = prefixSum[me] - prefixSum[ms-1];
            ans = max(ans, mSum + bestL);
            j++;
            i++;
        }
        j = firstLen + secondLen -1;
        i = 0;
        int bestM = INT_MIN;
        while (j < n){
            int ls = i;
            int le = ls + secondLen -1;
            int ms = le+1;
            int me = j;
            int lsum;
            if (ls == 0){
                lsum = prefixSum[le];
            } else {
                lsum = prefixSum[le] - prefixSum[ls-1];
            }
            bestM = max(bestM, lsum);
            int mSum = prefixSum[me] - prefixSum[ms-1];
            ans = max(ans, mSum + bestM);
            j++;
            i++;
        }
        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna