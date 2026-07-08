class Solution {
public:
    long long pahela = 0;
    vector<int> count;
    int N;
    int dfsroot(vector<vector<int>>& adj, int node, int prev, int depth){
        pahela += depth;
        int nodecount = 1;
        for (int i = 0; i < adj[node].size(); i++){
            if (adj[node][i] == prev) continue;
            nodecount += dfsroot(adj, adj[node][i], node, depth+1);
        }
        count[node] = nodecount;
        return nodecount;
    }
    void dfs(vector<vector<int>>& adj, int node, int prev, vector<int>& res){
        for (int i = 0; i < adj[node].size(); i++){
            if (adj[node][i] == prev) continue;
            res[adj[node][i]] = res[node] + (N-2*count[adj[node][i]]);
            dfs(adj, adj[node][i], node, res);
        }
        return;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        N=n;
        for (int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        count.resize(n);
        int aise = dfsroot(adj, 0, -1, 0);
        vector<int> res(n);
        res[0] = pahela;
        dfs(adj,0,-1,res);
        for (int i = 0; i < n; i++){
            cout << count[i] << endl;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna