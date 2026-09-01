class Solution {
public:
    struct State {
        int r;
        int c;
        int energy;
        int mask;
    };
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int maxEnergy = energy;
        int litter[20][20];
        int lcount = 0;
        int startRow = 0;
        int startCol = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                litter[i][j] = -1;
                if (classroom[i][j] == 'S'){
                    startRow = i;
                    startCol = j;
                }
                if (classroom[i][j] == 'L'){
                    litter[i][j] = lcount;
                    lcount++;
                }
            }
        }
        int allCollect = (1 << lcount)-1;
        if (lcount == 0){
            return 0;
        }
        queue <State> q;
        q.push({startRow, startCol, maxEnergy, 0});
        bool vis[20][20][51][1024] = {false};
        vis[startRow][startCol][maxEnergy][0] = true;
        int moves = 0;
        while (!q.empty()){
            int currSize = q.size();
            while (currSize--){
                State curr = q.front();
                q.pop();
                if (curr.mask == allCollect) return moves;
                if (curr.energy == 0) continue;

                for (auto &dir : directions){
                    int nextRow = curr.r + dir[0];
                    int nextCol = curr.c + dir[1];
                    if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n){
                        continue;
                    }
                    int elevel = curr.energy;
                    int nextMask = curr.mask;
                    char cell = classroom[nextRow][nextCol];
                    elevel -= 1;
                    if (cell == 'X') continue;
                    if (cell == 'R'){
                        elevel = maxEnergy;
                    } else if (cell == 'L'){
                        nextMask |= (1<<litter[nextRow][nextCol]);
                    }

                    if (!vis[nextRow][nextCol][elevel][nextMask]){
                        vis[nextRow][nextCol][elevel][nextMask] = true;
                        q.push({nextRow, nextCol, elevel, nextMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna