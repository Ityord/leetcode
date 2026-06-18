class Solution {
public:
    int reverseDigits(int num) {
        int reversed_num = 0;
    
        while (num != 0) {
            int last_digit = num % 10;
            reversed_num = (reversed_num * 10) + last_digit;
            num /= 10; 
        }
    
        return reversed_num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int res = INT_MAX;
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++){
            if (mp.find(nums[i]) == mp.end()){
                mp[reverseDigits(nums[i])] = i;
            } else {
                int j = mp[nums[i]];
                int ans = abs(j-i);
                res = min(res,ans);
                mp[reverseDigits(nums[i])] = i;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna