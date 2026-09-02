class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool isodd = true;
        bool iseven = true;
        for (int i = 0; i < nums1.size(); i++){
            if (nums1[i] % 2 == 0){
                isodd = false;
            } else {
                iseven = false;
            }
        }
        if (isodd || iseven) return true;
        sort(nums1.begin(), nums1.end());
        if (nums1[0] % 2) return true;
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna