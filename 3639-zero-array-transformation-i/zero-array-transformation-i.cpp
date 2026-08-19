class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr(n,0);
        for (int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = 1;
            arr[l] += val;
            if (r + 1 < n){
                arr[r+1] -= val;
            }
        }
        for (int i = 0; i < n; i++){
            if (i > 0) {
                arr[i] = arr[i] + arr[i-1];
            }
            if (arr[i] < nums[i]) return false;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna