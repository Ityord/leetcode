class Solution {
public:
    int M = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        // Using 1-indexed arrays to avoid l-1 out-of-bounds checks during queries
        vector<long long> prefix_sum(n + 1, 0);
        vector<long long> ds(n + 1, 0);
        vector<int> cnt(n + 1, 0); 
        
        // Precompute powers of 10 modulo M
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        // Build prefix states
        for (int i = 0; i < n; i++) {
            int num = s[i] - '0';
            prefix_sum[i + 1] = prefix_sum[i] + num;
            
            if (num == 0) {
                ds[i + 1] = ds[i];
                cnt[i + 1] = cnt[i];
            } else {
                ds[i + 1] = (ds[i] * 10 + num) % M;
                cnt[i + 1] = cnt[i] + 1;
            }
        }

        int m = queries.size();
        vector<int> ans(m);
        
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            long long ss = prefix_sum[r + 1] - prefix_sum[l];
            
            int len_diff = cnt[r + 1] - cnt[l];
            long long shift = pow10[len_diff];
            long long xx = (ds[r + 1] - (ds[l] * shift) % M + M) % M;
            
            ans[i] = (xx * ss) % M;
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna