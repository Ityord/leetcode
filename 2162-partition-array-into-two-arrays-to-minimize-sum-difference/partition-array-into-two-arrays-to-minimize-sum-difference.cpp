class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int S = 0;
        int N = nums.size();
        int n = N/2;
        int n1 = n;
        int n2 = n;

        for (int i = 0 ; i < N; i++){
            S += nums[i];
        }

        unordered_map<int, vector<int>> sumLeft;
        for (int mask = 0; mask < (1<<n1); mask++){
            int count = 0;
            int sum = 0;
            for (int i = 0; i < n; i++){
                if (mask & (1<<i)){
                    sum += nums[i];
                    count++;
                }
            }
            sumLeft[count].push_back(sum);
        }

        unordered_map<int, vector<int>> sumRight;
        for (int mask = 0; mask < (1<<n1); mask++){
            int count = 0;
            int sum = 0;
            for (int i = 0; i < n; i++){
                if (mask & (1<<i)){
                    sum += nums[n+i];
                    count++;
                }
            }
            sumRight[count].push_back(sum);
        }

        for (int count = 0; count <= n2; count++){
            sort(sumRight[count].begin(), sumRight[count].end());
        }
        int minValue = INT_MAX;
        for (int k = 0; k <= n1; k++){
            int m = n1-k;
            for (int leftS : sumLeft[k]){
                int need = (S - 2*leftS)/2;
                int low = lower_bound(begin(sumRight[m]), end(sumRight[m]), need) - begin(sumRight[m]);
                if (low < sumRight[m].size()){
                    int rightS = sumRight[m][low];
                    minValue = min(minValue, abs(2*(leftS + rightS)-S));
                }
                if (low -1 >= 0){
                    int rightS = sumRight[m][low-1];
                    minValue = min(minValue, abs(2*(leftS + rightS)-S));
                }
            }
        }
        return minValue;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna