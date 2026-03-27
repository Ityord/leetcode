class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k%n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (i % 2 == 0) {
                    int t = (j + k)%n;
                    if (mat[i][j] != mat[i][t]) return false;
                } else {
                    int t = (j-k+n)%n;
                    if (mat[i][j] != mat[i][t]) return false;
                }
            }
        }
        return true;
    }
};