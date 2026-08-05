class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, int k, vector<bool>& corrupt, bool isc, vector<int>& indegree, vector<int>& vis){
        vis[node] = 1;
        if (node == k || isc == true){
            corrupt[node] = true;
            isc = true;
        }
        for (int i = 0; i < adj[node].size(); i++){
            int nghbr = adj[node][i];
            if (corrupt[node] == true || node == k){
                indegree[nghbr]--;
            }
            if (vis[nghbr] != -1){
                if (corrupt[nghbr] == false && corrupt[node] == true){
                    dfs(nghbr, adj, k, corrupt, isc, indegree, vis);
                }
            }
            else {
                dfs(nghbr, adj, k, corrupt, isc, indegree, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> corrupt(n,false);
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<int> vis(n,-1);
        for (int i = 0; i < invocations.size(); i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for (int i = 0; i < n; i++){
            if (vis[i] == -1){
                dfs(i, adj, k, corrupt, false, indegree, vis);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (corrupt[i] && indegree[i] > 0){
                for (int i = 0; i < n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for (int i = 0; i < n; i++){
            if (corrupt[i] == false){
                ans.push_back(i);
            }
        }
        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna