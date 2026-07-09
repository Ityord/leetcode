class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int group = 1;
        vector<int> component(n);
        component[0] = group;
        for (int i = 1; i < nums.size(); i++){
            int temp = nums[i] - nums[i-1];
            if (temp <= maxDiff){
                component[i] = group;
            } else {
                group++;
                component[i] = group;
            }
        }
        int m = queries.size();
        vector<bool> ans(m);
        for (int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if (component[l] == component[r]){
                ans[i] = true;
            }
            else {
                ans[i] = false;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna