class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n==0) return 0;
        string s = to_string(n);
        int l = s.length();
        string ans = "";
        long long sum = 0;
        for (int i = 0; i < l; i++){
            if (s[i] == '0') continue;
            ans += s[i];
            sum += (s[i] - '0');
        }
        long long res = stoi(ans);
        return res*sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna