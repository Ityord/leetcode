class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int i = x;
        int j = x+k-1;

        while (i < j){
            for (int v = y; v < y+k; v++){
                swap(grid[i][v], grid[j][v]);
            }
            i++;
            j--;
        }
        return grid;
    }
};