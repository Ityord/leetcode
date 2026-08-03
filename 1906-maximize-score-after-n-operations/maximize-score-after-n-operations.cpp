class Solution {
public:
    int solve(vector<int>& nums, vector<bool>& visited, int op, unordered_map<vector<bool>, int>& mp){
        if (mp.find(visited) != mp.end()) return mp[visited];
        int maxScore = 0;
        for (int i = 0; i < nums.size()-1; i++){
            if (visited[i] == true) continue;
            for (int j = i+1; j < nums.size(); j++){
                if (visited[j] == true) continue;
                visited[i] = true;
                visited[j] = true;
                int s = op * gcd(nums[i],nums[j]);
                int remain = solve(nums, visited, op+1,mp);
                maxScore = max(s+remain, maxScore);
                visited[i] = false;
                visited[j] = false;
            }
        }
        return mp[visited] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);
        unordered_map<vector<bool>, int> mp;
        return solve(nums, visited, 1, mp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna