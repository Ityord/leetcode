class Solution {
public:
    int M = 1e9+7;
    int power(int n, int d){
        int res = 1;
        while (d){
            res = (res*n)%M;
            d--;
        }
        return res;
    }
    int max_depth(unordered_map<int,vector<int>> &adj, int node, int prnt){
        int max_dep = 0;
        for (auto nbr : adj[node]){
            if (nbr == prnt) continue;
            max_dep = max(max_dep, max_depth(adj,nbr,node)+1);
        }
        return max_dep;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for (int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int depth = max_depth(adj, 1, -1);
        return power(2,depth-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna