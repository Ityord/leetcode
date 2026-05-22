class Solution {
public:
    int solve(vector<int>& nums, int n){
        int l = 0, r = n-1;
        while (l < r){
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[r]){
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    int binarySearch(int l, int r, vector<int>& nums, int target){
        int res = -1;
        while (l <= r){
            int mid = l+(r-l)/2;
            if (nums[mid] == target){
                return mid;
            }
            if (nums[mid]>target){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return res;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = solve(nums,n);
        int idx = binarySearch(0,pivot-1,nums,target);
        if (idx != -1){
            return idx;
        }
        idx = binarySearch(pivot,n-1,nums,target);
        return idx;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna