class Solution {
public:
    int g = 0;
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node){
        vis[node] = g;
        g++;
        for (int i = 0; i < adj[node].size(); i++){
            int nghbr = adj[node][i];
            if (vis[nghbr] == -1){
                dfs(adj, vis, nghbr);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, -1);
        long long ans = 0;
        int nn = n;
        for (int i = 0; i < n; i++){
            if (vis[i] == -1){
                dfs(adj, vis, i);
            }
            long long temp = nn-g;
            ans += (temp*g);
            g=0;
            nn = temp;
        }
        if (g==1) return 0;
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna