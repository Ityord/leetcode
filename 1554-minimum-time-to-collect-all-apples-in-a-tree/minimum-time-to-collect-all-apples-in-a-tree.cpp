class Solution {
public:
    int dfs(vector<vector<int>>& adj, int curr, int prev, vector<bool>& hasApple){
        int time = 0;
        for (int i = 0; i < adj[curr].size(); i++){
            int child = adj[curr][i];
            if (child == prev) continue;
            int time_child = dfs(adj, child, curr, hasApple);
            if (time_child > 0 || hasApple[child]){
                time = time + time_child + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj, 0, -1, hasApple);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna