class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = t[0];
        for (char &c : s){
            ch = c^ch;
        }
        for (int i = 1; i < t.size(); i++){
            ch = ch^t[i];
        }
        return ch;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna