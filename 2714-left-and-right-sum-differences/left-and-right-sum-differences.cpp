class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int curr = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            int ls = curr;
            curr += nums[i];
            int rs = sum - curr;
            ans[i] = abs(ls-rs);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna