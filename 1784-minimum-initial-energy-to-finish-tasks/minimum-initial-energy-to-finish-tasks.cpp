class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks, int mid){
        for (auto &task : tasks){
            int act = task[0];
            int mini = task[1];
            if (mid < mini){
                return false;
            }
            mid -= act;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        auto lambda = [] (auto &task1, auto &task2){
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];
            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lambda);
        int l = 0;
        int r = 1e9;
        int result = INT_MAX;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (isPossible(tasks,mid)){
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna