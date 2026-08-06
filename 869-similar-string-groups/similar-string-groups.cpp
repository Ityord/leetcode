class Solution {
public:
    int g = 0;
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=g;
        for (int i = 0; i < adj[node].size(); i++){
            int nghbr = adj[node][i];
            if (vis[nghbr] == -1){
                dfs(nghbr, adj, vis);
            }
        }
    }
    bool isSimilar(string& s1, string& s2){
        int n = s1.length();
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < n; i++){
            if (s1[i] != s2[i]){
                diff++;
            }
        }
        return diff == 2 || diff == 0;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (isSimilar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,-1);
        for (int i = 0; i < n; i++){
            if (vis[i] == -1){
                g++;
                dfs(i, adj, vis);
            }
        }
        return g;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna