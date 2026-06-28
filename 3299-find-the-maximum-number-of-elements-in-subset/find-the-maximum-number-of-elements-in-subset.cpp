class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, long long> mp;
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int result;
        if (mp[1]%2) result = mp[1];
        else result = mp[1]-1;
        for (auto &[num,_] : mp){
            if (num == 1) continue;
            long long curr = num;
            int len = 0;
            while (mp.count(curr) && mp[curr] > 1){
                len += 2;
                curr = curr*curr;
            }
            if (mp.count(curr) == 1){
                len += 1;
            } else {
                len -= 1;
            }
             result = max(result,len);
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna