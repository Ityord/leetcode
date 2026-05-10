class Solution {
public:
    int  solve (int i, vector<int>& nums, int target, vector<int>& t){
        int result = INT_MIN;
        if (i == nums.size()-1) return t[i] = 0;

        if (t[i] != INT_MIN) return t[i];
        for (int j = i+1; j < nums.size(); j++){
            if (abs(nums[i]-nums[j]) <= target){
                int temp = 1 + solve(j,nums, target, t);
                result = max(result,temp);
            }
        }
        return t[i] =  result;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> t(nums.size()+1, INT_MIN);
        int ans = solve(0,nums,target,t);
        if (ans < 0) return -1;
        else return ans;
    }
};