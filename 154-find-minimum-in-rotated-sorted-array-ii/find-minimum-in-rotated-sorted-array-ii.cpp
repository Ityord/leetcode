class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while (nums[l] == nums[r] && l < r){
            l++;
        }
        while (nums[r] == nums[l] && l < r){
            r--;
        }
        int res = 0;
        while (l <= r){
            int mid = l+(r-l)/2;
            if (nums[mid] < nums[res]){
                res = mid;
            }
            if (nums[mid] > nums[r]){
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }
        return nums[res];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna