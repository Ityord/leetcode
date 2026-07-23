class Solution {
public:
    int solve(int n){
        int cnt = 0;
        while (n){
            n = n/2;
            cnt++;
        }
        int ans = 1;
        while (cnt){
            ans = ans*2;
            cnt--;
        }
        return ans;

    }
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;
        return solve(n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna