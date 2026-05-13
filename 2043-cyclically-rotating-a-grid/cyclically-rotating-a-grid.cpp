class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m,n)/2;

        for (int i = 0; i < layers; i++){
            vector<int> arr;
            int top = i;
            int bottom = m-1-i;
            int left = i;
            int right = n-i-1;
            for (int j = left; j <= right; j++){
                arr.push_back(grid[top][j]);
            }
            for (int j = top+1; j <= bottom-1; j++){
                arr.push_back(grid[j][right]);
            }
            for (int j = right; j >= left; j--){
                arr.push_back(grid[bottom][j]);
            }
            for (int j = bottom-1; j >= top+1; j--){
                arr.push_back(grid[j][left]);
            }
            int len = arr.size();
            int kt = k%len;
            rotate(begin(arr), begin(arr)+kt, end(arr));
            int idx = 0;
            for (int j = left; j <= right; j++){
                grid[top][j] = arr[idx++];
            }
            for (int j = top+1; j <= bottom-1; j++){
                grid[j][right] = arr[idx++];
            }
            for (int j = right; j >= left; j--){
                grid[bottom][j] = arr[idx++];
            }
            for (int j = bottom-1; j >= top+1; j--){
                grid[j][left] = arr[idx++];
            }
        }
        return grid;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna