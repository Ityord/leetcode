class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> arr(2*limit+2, 0);

        for (int i = 0; i < n/2; i++){
            int a = nums[i];
            int b = nums[n-1-i];
            arr[2] += 2;
            arr[min(a,b)+1]--;
            arr[max(a,b)+1+limit]++;
            arr[a+b]--;
            arr[a+b+1]++;
        }
        int ans = n;
        int pref = 0;

        for (int i = 2; i <= limit*2; i++){
            pref += arr[i];
            ans = min(ans,pref);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna