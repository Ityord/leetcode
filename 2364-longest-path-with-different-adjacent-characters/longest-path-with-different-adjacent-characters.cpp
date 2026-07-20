class Solution {
public:
    int ans = 0;
    int solve(vector<vector<int>>& adj,int node, int parent, string &s){
        int longest = 0;
        int second_longest = 0;
        for (int i = 0; i < adj[node].size(); i++){
            int curr = adj[node][i];
            if (curr == parent) continue;
            int child_longest = solve(adj, curr, node, s);
            if (s[curr] == s[node]) continue;
            if (child_longest > second_longest){
                second_longest = child_longest;
            }
            if (second_longest > longest){
                swap(second_longest, longest);
            }
        }
        int koi_ek_achha = max(longest,second_longest)+1;
        int only_root_achha = 1;
        int niche = 1 + longest + second_longest;
        ans = max({ans,koi_ek_achha, only_root_achha, niche});
        return max(koi_ek_achha, only_root_achha);
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int temp = solve(adj,0, -1, s);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna