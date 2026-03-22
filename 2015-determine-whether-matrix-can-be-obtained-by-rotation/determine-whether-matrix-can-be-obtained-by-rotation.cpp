class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<vector<int>> grid = mat;
        while (true) {
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    swap(grid[i][j], grid[j][i]);
                }
            }
            for (int i = 0; i < n; i++) {
                reverse(grid[i].begin(), grid[i].end());
            }

            if (grid == target) return true;
            if (grid == mat) {
                return false;
            }
        }
        return 1;
    }
};