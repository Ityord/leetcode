class Solution {
public:
    void dfs(vector<vector<int>>& stones,vector<bool>& visited, vector<int> waha, int i){
        visited[i] = true;
        for(int j = 0; j < stones.size(); j++){
            int r = waha[0];
            int c = waha[1];
            if (!visited[j]){
                if (r == stones[j][0] || c == stones[j][1]){
                    dfs(stones, visited, stones[j], j);
                }
            }
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int g = 0;
        vector<bool> visited(n,false);
        for (int i = 0; i < n; i++){
            if (visited[i]) continue;
            dfs(stones, visited, stones[i], i);
            g++;
        }
        return n-g;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna