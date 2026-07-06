class Solution {
public:
    bool check(vector<int>& ye, vector<vector<int>>& intervals, int j){
        for (int i = 0; i < j; i++){
            if (ye[0] >= intervals[i][0] && ye[1] <= intervals[i][1]){
                return true;
            }
        }
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] == intervals[i-1][0]){
                if (intervals[i][1] > intervals[i-1][1]){
                    int temp = intervals[i][1];
                    intervals[i][1] = intervals[i-1][1];
                    intervals[i-1][1] = temp;
                }
            }
        }
        int n = intervals.size();
        for (int i = 1; i < intervals.size(); i++){
            if (check(intervals[i], intervals, i)){
                n--;
            }
        }
        return n;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna