class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp1;
        for (int i = 0; i < arr.size(); i++){
            mp1[arr[i]]++;
        }
        unordered_map<int,int> mp2;
        for (auto &c : mp1){
            mp2[c.second]++;
        }
        for (auto &c : mp2){
            if (c.second >= 2) {
                return false;
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna