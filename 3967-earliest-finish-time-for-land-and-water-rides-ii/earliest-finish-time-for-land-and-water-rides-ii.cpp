class Solution {
public:
    int solve (vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int finish1 = INT_MAX;
        int result = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++){
            finish1 = min(finish1,landStartTime[i]+landDuration[i]);
        }
        for(int i = 0; i < waterDuration.size(); i++){
            result = min(result, max(finish1, waterStartTime[i]) + waterDuration[i]);
        }
        return result;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int res2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(res1, res2);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna