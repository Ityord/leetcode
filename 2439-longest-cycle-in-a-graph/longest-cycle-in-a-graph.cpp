class Solution {
public:
    int ans = -1;
    int g = 0;
    void dfs(vector<int>& edges, vector<int>& vis, vector<int>& count, int node){
        vis[node] = g;
        int nghbr = edges[node];
        if (nghbr == -1) return;
        if (vis[nghbr] != -1){
            if (vis[nghbr] == g){
                int temp = count[node] - count[nghbr]+1;
                ans = max(ans,temp);
            }
        }
        count[nghbr] = count[node]+1;
        if (vis[nghbr] == -1){
            dfs(edges, vis, count, nghbr);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n,-1);
        vector<int> count(n,1);
        for(int i = 0; i < n; i++){
            if (vis[i] == -1){
                g++;
                dfs(edges,vis,count,i);
            }
        }
        for (int i = 0; i < n; i++){
            cout << count[i] << endl;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna