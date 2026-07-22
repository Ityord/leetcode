class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>& adj, vector<bool>& vis, int node, int& result){
        vis[node] = true;
        for (int i = 0; i < adj[node].size(); i++){
            int dist = adj[node][i].second;
            int nghbr = adj[node][i].first;
            result = min(result,dist);
            if (!vis[nghbr]){
                dfs(adj, vis, nghbr, result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int dist = roads[i][2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        vector<bool> vis(n+1, false);
        int result = INT_MAX;
        dfs(adj, vis, 1, result);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna