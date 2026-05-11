class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp;
            int n = nums[i];
            while (n > 0) {
                int a = n%10;
                n = n/10;
                temp.push_back(a);
            }
            reverse(temp.begin(),temp.end());
            for (int i = 0; i < temp.size(); i++){
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};