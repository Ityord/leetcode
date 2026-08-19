class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> arr(n,0);
        for (int i = 0; i < shifts.size(); i++){
            int l = shifts[i][0];
            int r = shifts[i][1];
            int dir = shifts[i][2];
            if (dir == 0){
                arr[l]--;
                if (r+1 < n){
                    arr[r+1]++;
                }
            }else {
                arr[l]++;
                if (r+1 < n){
                    arr[r+1]-=1;
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (i > 0){
                arr[i] = arr[i] + arr[i-1];
            }
        }
        for (int i = 0; i < n; i++){
            int net_shift = (arr[i] % 26 + 26) % 26;
             
            s[i] = 'a' + (s[i] - 'a' + net_shift) % 26;
        }
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna