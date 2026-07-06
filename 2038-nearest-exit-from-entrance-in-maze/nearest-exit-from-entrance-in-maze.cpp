class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q;
        int m = maze.size();
        int n = maze[0].size();
        int ans = 0;
        q.push(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        while (!q.empty()){
            int k = q.size();
            while (k--){
                vector<int> temp = q.front();
                int r = temp[0];
                int c = temp[1];
                q.pop();
                if (r == 0 || r == m-1 || c == 0 || c == n-1){
                    if (r != entrance[0] || c != entrance[1]) return ans;
                }
                    if (r >= 0 && r < m && c+1 >= 0 && c+1 < n){
                        if (maze[r][c+1] == '.'){
                            q.push({r,c+1});
                            maze[r][c+1] = '+';
                        }
                    }
                    if (r+1 >= 0 && r+1 < m && c >= 0 && c < n){
                        if (maze[r+1][c] == '.'){
                            q.push({r+1,c});
                            maze[r+1][c] = '+';
                        }
                    }   
                    if (r-1 >= 0 && r-1 < m && c >= 0 && c < n){
                        if (maze[r-1][c] == '.'){
                            q.push({r-1,c});
                            maze[r-1][c] = '+';
                        }
                    }
                    if (r >= 0 && r < m && c-1 >= 0 && c-1 < n){
                        if (maze[r][c-1] == '.'){
                            q.push({r,c-1});
                            maze[r][c-1] = '+';
                        }
                    }
            }
            ans++;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna