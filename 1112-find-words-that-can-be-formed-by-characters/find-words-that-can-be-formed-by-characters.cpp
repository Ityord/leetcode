class Solution {
public:
    vector<int> solve(string s){
        vector<int> hash(26,0);
        for (char &c : s){
            hash[c-'a']++;
        }
        return hash;
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int> asli = solve(chars);
        int sum = 0;
        for (int i = 0; i < words.size(); i++){
            vector<int> mera = solve(words[i]);
            bool flag = true;
            for (int j =0; j < 26; j++){
                if (asli[j] < mera[j]){
                    flag = false;
                }
            }
            if (flag){
                sum += words[i].length();
            }
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna