class Solution {
public:
    bool solve(vector<int>& nums, vector<vector<int>>& queries, int k){
        int n = nums.size();
        vector<int> arr(n,0);
        for (int i = 0; i < k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0; 
        int r = queries.size();
        int k = -1;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (solve(nums, queries, mid)){
                r = mid-1;
                k = mid;
            } else {
                l = mid + 1;
            }
        }
        return k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna