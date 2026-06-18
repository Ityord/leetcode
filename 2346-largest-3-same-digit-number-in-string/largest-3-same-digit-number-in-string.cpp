class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "";
        int dig = -1;
        for (int i = 2; i < num.length(); i++){
            if (num[i] == num[i-1]){
                if (num[i-1] == num[i-2]){
                    int tt = num[i]-'0';
                    if (tt > dig){
                        dig = tt;
                    }
                }
            }
        }
        if (dig != -1){
        char c = dig + '0';
            s += c;
            s+= c;
            s+= c;
        }
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna