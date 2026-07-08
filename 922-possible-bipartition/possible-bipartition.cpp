class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if (dislikes.size() == 0) return true;
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<int> q;
        vector<int> color(n+1,-1);
        q.push(dislikes[0][0]);
        color[dislikes[0][0]] = 1;
        for (int j = 1; j <= n; j++){
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (int i = 0;  i < adj[node].size(); i++){
                int ngbr = adj[node][i];
                if (color[ngbr] == -1){
                    if (color[node] == 0){
                        color[ngbr] = 1;
                    } else {
                        color[ngbr] = 0;
                    }
                    q.push(ngbr);
                } else {
                    if (color[node] == color[ngbr]) return false;
                }
            }
        }
        if (color[j] == -1){
            q.push(j);
        }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna