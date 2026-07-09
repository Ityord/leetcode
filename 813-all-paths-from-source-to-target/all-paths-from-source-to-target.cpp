class Solution {
public:
    void dfs(vector<vector<int>>& graph, int s, int t, vector<vector<int>>& result, vector<int>& temp){
        temp.push_back(s);
        if (s == t) {
            result.push_back(temp);
        }
        for (int i = 0;i < graph[s].size(); i++){
                int node = graph[s][i];
                dfs(graph, node, t, result, temp);
                temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = n-1;
        vector<vector<int>> result;
        vector<int> temp;
        dfs(graph, 0, target, result, temp);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna