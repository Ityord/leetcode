class Solution {
public:
    bool dfs(vector<vector<int>>& mp, int s, int d, vector<bool>& visited){
        visited[s] = true;
        if (s == d) return true;
        for (int i = 0; i < mp[s].size(); i++){
            if (visited[mp[s][i]]) continue;
            bool temp = dfs(mp, mp[s][i], d, visited);
            if (temp) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> mp(n);
        for (int i = 0; i < edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        return dfs(mp, source, destination, visited);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna