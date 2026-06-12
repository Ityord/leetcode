class TreeAncestor {
public:
    int rows, cols;
   vector<vector<int>> ancestor;
    TreeAncestor(int n, vector<int>& parent) {
        rows = n;
        cols = log2(n)+1;
        ancestor.assign(rows, vector<int>(cols, -1));
        for (int i = 0; i < parent.size(); i++){
            ancestor[i][0] = parent[i];
        }
        for (int j =1; j < cols; j++){
            for (int node = 0; node <rows; node++){
                if (ancestor[node][j-1] != -1)
                    ancestor[node][j] = ancestor[ancestor[node][j-1]][j-1];
            }
        }
        return;
    }
    
    int getKthAncestor(int node, int k) {
        int ans = node;
        for (int j = 0; j < cols; j++){
            if (k&(1<<j)){
                ans = ancestor[ans][j];
                if (ans == -1){
                    return -1;
                }
            }
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna