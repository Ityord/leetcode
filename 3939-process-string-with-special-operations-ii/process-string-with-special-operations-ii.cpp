class Solution {
public:
    char processStr(string s, long long k) {
        long long l = 0;
        int n = s.length();
        for (char &c : s){
            if (c == '*'){
                if (l > 0){
                    l--;
                }
            } else if (c == '%'){
                continue;
            } else if (c == '#'){
                l *= 2;
            } else {
                l++;
            }
        }
        if (k >= l) return '.';
        for (int i = n-1; i >= 0; i--){
            if (s[i] == '*'){
                l++;
            } else if (s[i] == '%'){
                k = l-k-1;
            } else if (s[i] == '#'){
                l = l/2;
                if (k >= l){
                    k = k-l;
                }
            } else {
                l--;
            }
            if (k == l){
                return s[i];
            }
        }
        return '.';
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna