class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> never;
        vector<int> once;
        unordered_map<int,int> mp;
        for (int i = 0; i < matches.size(); i++){
            mp[matches[i][1]]++;
        }
        for (int i = 0; i < matches.size(); i++){
            int winner = matches[i][0];
            int loser = matches[i][1];
            if (mp.find(winner) == mp.end()){
                never.push_back(winner);
                mp[winner] = 2;
            }
            if (mp[loser] == 1){
                once.push_back(loser);
            }
        }
        sort(never.begin(),never.end());
        sort(once.begin(),once.end());
        return {never,once};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna