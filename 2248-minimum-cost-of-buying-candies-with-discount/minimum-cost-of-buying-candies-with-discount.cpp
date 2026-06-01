class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int j = 0;
        int sum = 0;
        sort(cost.begin(),cost.end());
        for (int i = n-1; i >= 0; i--){
            sum += cost[i];
            j++;
            if (j == 2){
                j=0;
                i--;
            }
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna