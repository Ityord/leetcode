class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash(26,0);
        for (char &c : s){
            hash[c-'a']++;
        }
        for (int i = 0; i < t.size(); i++){
            if (hash[t[i]-'a'] == 0) return t[i];
            hash[t[i]-'a']--;
        }
        return 'a';
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna