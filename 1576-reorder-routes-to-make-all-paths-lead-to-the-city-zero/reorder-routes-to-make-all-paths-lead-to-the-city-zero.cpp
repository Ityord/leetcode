class Solution {
public:
    int res = 0;
    void dfs(vector<vector<pair<int,bool>>>& adj, int node, vector<bool>& vis){
        vis[node] = true;
        for (int i = 0; i < adj[node].size(); i++){
            int nghbr = adj[node][i].first;
            int dir = adj[node][i].second;
            if (!vis[nghbr]){
                if (dir) res++;
                dfs(adj,nghbr,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>> adj(n);
        for (int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back({v,true});
            adj[v].push_back({u,false});
        }
        vector<bool> vis(n,false);
        dfs(adj,0, vis);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna