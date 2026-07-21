class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++){
            sum += s[i]-'0';
        }
        vector<int> zero_count;
        int zero = 0;
        int j = 0;
        while (j < s.length()){
            if (s[j] == '0'){
                break;
            }
            j++;
        }
        int k = s.length()-1;
        while (k >= 0){
            if (s[k] == '0'){
                break;
            }
            k--;
        }
        if ( j == k) return sum;
        for (int i = j; i <= k; i++){
            if (s[i] == '1') continue;
            while (i <= k && s[i] == '0'){
                zero++;
                i++;
            }
            zero_count.push_back(zero);
            zero = 0;
        }
        if (zero > 0){
            zero_count.push_back(zero);
        }
        if (zero_count.size() <= 1) return sum;
        int ans = sum;
        for (int i = 1; i < zero_count.size(); i++){
            int tunuk = zero_count[i-1] + zero_count[i];
            ans = max(ans, sum + tunuk);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna