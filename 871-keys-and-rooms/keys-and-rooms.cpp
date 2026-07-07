class Solution {
public:
    void dfs(int s, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[s] = true;
        for (int i = 0; i < rooms[s].size(); i++){
            if (!visited[rooms[s][i]])
            dfs(rooms[s][i], rooms, visited);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(0,rooms,visited);
        for (int i = 0; i < n; i++){
            if (visited[i] == false) return false;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna